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
#ifndef CLUSTERINGBASE_H
#define CLUSTERINGBASE_H


#include <string>

#include <tulip/Graph.h>

using namespace tlp;
using namespace std;

class ClusteringBase{
public:
  /**
   * Constructor
   * @param pgraph a pointer to the target graph
   * @param iterations the maximum number of iterations for the algorithm
   * @param min_delta the minimum error to stop the algorithm
   * @param partition_name_prefix the prefix for naming the groups
   */
  ClusteringBase( Graph* pgraph, int iterations, float min_delta, string partition_name_prefix );
  /**
   * Destructor
   */
  virtual ~ClusteringBase();
  /**
   * Call the actual algorithm
   */
  virtual void execute_algorithm() =0;
  
protected:
  /**
   * This function takes each group in the partition and add the inner edges from
   * the root graph
   */
  void assignEdgesToGroups();

protected:
  /**
   * A pointer to the target (original) graph
   */
  Graph* pgraph;
  /**
   * The maximum number of iterations for the algorithm
   */
  int iterations;
  /**
   * Minimum error for stopping the algorithm
   */
  float min_delta;
  /**
   * The prefix for naming the groups in the partition
   */
  string partition_name_prefix;

};

#endif
