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

#ifndef SOMCLUSTERINGPLUGIN_H
#define SOMCLUSTERINGPLUGIN_H

#include <map>
#include <vector>

#include <tulip/TulipPlugin.h>
#include "somclusteringspace.h"

using namespace std;
using namespace tlp;

/** \addtogroup clustering*/
/*@{*/

class SOMClusteringPlugin : public tlp::Algorithm{
public:
  /**
   * Constructor
   * @param context : the algorithm context
   */
  SOMClusteringPlugin( tlp::AlgorithmContext context );
  /**
   * Destructor
   */
  ~SOMClusteringPlugin();
  /**
   * Executes the algorithm
   */
  bool run();
  /**
   * Check if all the data is available to execute the algorithm
   */
  bool check(string& error);
  /**
   * Reset the algorithm
   */
  void reset();
  
  void assignEdgesToGroups();
  
private:
  SOMClusteringSpace* space;
  
};

/*@}*/

#endif // SOMCLUSTERINGPLUGIN_H
