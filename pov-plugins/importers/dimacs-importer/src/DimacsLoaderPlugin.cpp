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
#include "DimacsLoaderPlugin.h"


DimacsLoaderPlugin::DimacsLoaderPlugin(tlp::AlgorithmContext context) : tlp::ImportModule(context){
	addParameter<std::string>("file::name",paramHelp[0]);
	loader = NULL;
}

DimacsLoaderPlugin::~DimacsLoaderPlugin(){
	if( loader != NULL ){
		delete loader;
	}
	loader = NULL;
}

bool DimacsLoaderPlugin::import(const std::string &name){
	std::string filename;
	if (!dataSet->get("file::name", filename)){
		return false;
	}
	loader = new CDimacsLoader( graph );
	loader->loadGraph(filename);
	return true;
}
