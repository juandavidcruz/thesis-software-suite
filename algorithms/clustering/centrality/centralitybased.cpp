/**
 Copyright (c) 2014 Juan David Cruz Gómez and Telecom - Bretagne

 juan.cruzgomez@telecom-bretagne.eu 
 juandavidcruz@gmail.com

 Licensed under the EUPL, Version 1.2 or – as soon theywill be approved 
 by the European Commission - subsequent versions of the 
 EUPL (the "Licence");

 You may not use this work except in compliance with the Licence.
 You may obtain a copy of the Licence at:

    https://joinup.ec.europa.eu/software/page/eupl5
  
 Unless required by applicable law or agreed to inwriting, software 
 distributed under the Licence isdistributed on an *"AS IS"* basis,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND*, either express or implied.
 See the Licence for the specific language governing permissions and limitations 
 under the Licence.
*/
#include "centralitybased.h"

CentralityBased::CentralityBased( Graph* pgraph, int iterations, float min_delta, string partition_name_prefix, int measure_type, int target_k )
  : ClusteringBase(pgraph, iterations, min_delta, partition_name_prefix ), measure_type(measure_type), target_k(target_k)
{
  assert( (unsigned int)target_k <= pgraph->numberOfNodes() );
}

CentralityBased::~CentralityBased()
{}
  
void CentralityBased::execute_algorithm()
{
  string property;
  switch( measure_type )
  {
    case(PAGERANK):
      property = use_pagerank( pgraph );
    break;
    case(HITSRANK):
      use_hits();
    break;
    case(CLOSENESS):
      use_closeness();
    break;
    default:
      //Raise a bloody error mate
    break;
  }
  //vector<node> best_k = extract_best_k( pgraph, property, target_k );
  // Execute a k means like algorithm for detecting communities. Using the 
  // similarity as distance measure
  if( target_k > 1 )
  {
    k_means_like( property );
  }else{
    pgraph->addCloneSubGraph("cent_group_0");
  }
}

void CentralityBased::k_means_like( string property )
{
  DoubleVectorProperty* patterns = pgraph->getProperty<DoubleVectorProperty>("data_vector");
  //Select the initial centroids
  vector<node> centroids = extract_best_k( pgraph, property, this->target_k );
  int i = 0;
  bool stable = false;
  map<node, Graph*> groups;
  while( i < iterations && !stable )
  {
    map<node, Graph*>::iterator map_it;
    for( map_it = groups.begin(); map_it != groups.end(); ++map_it )
    {
      pgraph->delSubGraph( map_it->second );
    }
    groups.clear();
    for( int j = 0; j < this->target_k; j++ )
    {
      groups[centroids[j]] = pgraph->addSubGraph("hola");
    }
    //Assign the nodes...
    Iterator<node>* node_iter = pgraph->getNodes();
    node winner_node;
    double best_dist = 1E25;
    double dist = best_dist;
    while( node_iter->hasNext() )
    {
      node n = node_iter->next();
      //Test all the centroids
      for( int j = 0; j < this->target_k; j++ )
      {
        dist = euclidean_distance( patterns->getNodeValue( centroids[j] ), patterns->getNodeValue( n ) );
        if( dist < best_dist )
        {
          best_dist = dist;
          winner_node = centroids[j];
        }
      }
      groups[winner_node]->addNode( n );
      best_dist = 1E25;
      dist = best_dist;
    }
    delete node_iter;
    int matches = 0;
    for( int j = 0; j < this->target_k; j++ )
    {
      //Add the edges
      Iterator<edge>* edge_iter = pgraph->getEdges();
      while( edge_iter->hasNext() )
      {
        edge e = edge_iter->next();
        node source = pgraph->source( e );
        node target = pgraph->target( e );
        if( groups[centroids[j]]->isElement( source ) && groups[centroids[j]]->isElement( target ) )
        {
          groups[centroids[j]]->addEdge( e );
        }
      }
      delete edge_iter;
      //Select new centroids
      vector<node> centr = extract_best_k( groups[centroids[j]], property, 1 );
      if( centr.size() > 0 )
      {
	node new_centroid = centr[0];
	if( new_centroid.id == centroids[j].id )
	{
	  matches++;
	}else{
	  centroids.at( j ) = new_centroid;
	}
      }else{
	stable = true;
      }
      
    }
    stable = stable || matches == this->target_k;
    i++;
  }
}

double CentralityBased::euclidean_distance( vector<double> vec_a, vector<double> vec_b )
{
  double result = 0;
  for( unsigned int i = 0; i < vec_a.size(); i++ )
  {
    result += ( vec_a[i] - vec_b[i] ) * ( vec_a[i] - vec_b[i] );
  }
  return sqrt(result);
}

vector<node> CentralityBased::extract_best_k( Graph* graph, string property, int target_k )
{
  vector<node> result;
  map<double, vector<node> > measures_map;
  vector<double> sorted_measures;
  DoubleProperty* measure = graph->getProperty<DoubleProperty>( property );
  Iterator<node>* node_iter = graph->getNodes();
  // First: group the nodes according to their measures.
  while( node_iter->hasNext() )
  {
    node n = node_iter->next();
    double actual_measure = measure->getNodeValue( n );
    if( find( sorted_measures.begin(), sorted_measures.end(), actual_measure ) == sorted_measures.end() )
    {
      sorted_measures.push_back( actual_measure );
    }
    measures_map[actual_measure].push_back( n );
  }
  delete node_iter;
  // Second: sort the measures (Note that the vector is sorted in ascending order)
  sort( sorted_measures.begin(), sorted_measures.end() );
  // Third: select the k with the highest measure.
  int size = sorted_measures.size();
  int i = size-1;
  int k_count = 0;
  vector<node> nodes;
  while( i >= 0 && k_count < target_k )
  {
    nodes = measures_map[sorted_measures[i]];
    unsigned int j = 0;
    while( j < nodes.size() && k_count < target_k )
    {
      result.push_back( nodes[j] );
      k_count++;
      j++;
    }
    i--;
  }
  return result;
}

string CentralityBased::use_pagerank( Graph* graph )
{
  double damping_factor=0.85;
  int max_iterations=100;
  double min_delta=1E-5;
  PageRank pr( graph, damping_factor, max_iterations, min_delta );
  pr.calculate_pagerank();
  return pr.getPropertyName();
}
  
string CentralityBased::use_hits()
{
  return "";
}
  
string CentralityBased::use_closeness()
{
  return "";
}
