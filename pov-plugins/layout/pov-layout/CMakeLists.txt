# Copyright (c) 2014 Juan David Cruz Gómez and Telecom - Bretagne
#
# juan.cruzgomez@telecom-bretagne.eu 
# juandavidcruz@gmail.com
#
# Licensed under the EUPL, Version 1.2 or – as soon theywill be approved 
# by the European Commission - subsequent versions of the 
# EUPL (the "Licence");
#
# You may not use this work except in compliance with the Licence.
# You may obtain a copy of the Licence at:
#
#    https://joinup.ec.europa.eu/software/page/eupl5
#  
# Unless required by applicable law or agreed to inwriting, software 
# distributed under the Licence isdistributed on an *"AS IS"* basis,
# *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND*, either express or implied.
# See the Licence for the specific language governing permissions and limitations 
# under the Licence.
#cmake -DCMAKE_MODULE_PATH=~/tulip3dev/share/tulip -DATLAS_LIB=/home/juancrug/lib/ -DATLAS_INCLUDE=~/include/ -DTULIP_DIR=/home/juancrug/tulip3dev/ ..
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(PoVPlugins)

SET( PLUGIN_NAME PoVCommunityLayoutPluginV2 )

SET( CPP_FILES ${CPP_FILES} 
  CLayoutSpace.cpp
	ExecutionLog.cpp
	PoVLayoutTulipPlugin.cpp)

ADD_LIBRARY(${PLUGIN_NAME}-${TULIP_PLUGIN_VERSION} SHARED ${CPP_FILES} )

TARGET_LINK_LIBRARIES(${PLUGIN_NAME}-${TULIP_PLUGIN_VERSION} ${TULIP_LIBRARY} ${CORE_LIBS} ${SMACOF})

INSTALL( TARGETS ${PLUGIN_NAME}-${TULIP_PLUGIN_VERSION} LIBRARY DESTINATION ${TULIP_PLUGINS_PATH} )
