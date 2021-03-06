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
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(BasicMatrixLib)

SET( LIBRARY_NAME bmatrix )

################################################################################
#C++ flags
#No warnings please!
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

#Setup the type of building
#SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g") #Debug
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3" ) #Full optimization
################################################################################
SET( INSTALL_BASE_PATH ${PREFIX} )
SET( INSTALL_LIB_PATH ${INSTALL_BASE_PATH}/lib )
SET( INSTALL_INCLUDE_PATH ${INSTALL_BASE_PATH}/include )
################################################################################
#Atlas libraries
SET( ATLAS_LIB_PATH ${ATLAS_PREFIX}/lib )
SET( ATLAS_INC_PATH ${ATLAS_PREFIX}/include )
SET( CMAKE_LIBARY_PATH ${CMAKE_LIBARY_PATH} ${ATLAS_LIB_PATH} )

FIND_LIBRARY(PTBLAS NAMES ptcblas PATHS ${CMAKE_LIBARY_PATH} NO_DEFAULT_PATH )
FIND_LIBRARY(ATLAS NAMES atlas PATHS ${CMAKE_LIBARY_PATH} NO_DEFAULT_PATH )
################################################################################
# Where to find all the headers
SET( HEADERS ${ATLAS_INC_PATH}
              src )

INCLUDE_DIRECTORIES(${HEADERS})
################################################################################
# Set the libraries to be used
SET( CORE_LIBS pthread
  dl        
  ${PTBLAS}
	${ATLAS} )
################################################################################
ADD_SUBDIRECTORY( src )
################################################################################

ADD_EXECUTABLE( ${LIBRARY_NAME}_test mat_test.cpp )

TARGET_LINK_LIBRARIES(${LIBRARY_NAME}_test ${CORE_LIBS} ${LIBRARY_NAME} )
################################################################################
