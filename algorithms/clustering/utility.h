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
#ifndef UTILITY_H
#define UTILITY_H

#include <tulip/Graph.h>
#include <tulip/ColorProperty.h>

#include <vector>

#include "colorwheel.h"

using namespace tlp;
using namespace std;

/**
 * Takes a parititon and set a color for each group in it
 * @param thegraph the graph object containing the partition
 */
void color_partitions( Graph* theGraph );
/**
 * Remove all the groups of size 0 from the partition
 * @param thegraph the graph object containing the partition
 */
void clean_partition( Graph* theGraph );

#endif
