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

#include "PoVViewPlugin.h"
#include <tulip/LayoutProperty.h>


// VIEWPLUGIN(ClassName, "ViewName", "Authors", "date", "Long view plugin name", "plugin_release");
VIEWPLUGIN(PoVViewPlugin, "PoVViewPlugin", "Juan David Cruz Gomez", "07/02/2012", "PoV View Plugin", "1.0");

PoVViewPlugin::PoVViewPlugin(){
	addDependency<Algorithm>("Community Detection Louvain", "1.0");
	addDependency<LayoutAlgorithm>("Boundary layout", "1.0");
	addDependency<Algorithm>("PoV clustering algorithm", "1.0");
}

/**
 * Construct the view
 */
QWidget* PoVViewPlugin::construct( QWidget* parent ){
	view_widget = new QWidget(parent);
	theView = new MainWidgetView(view_widget);
	view_widget->setMinimumSize(theView->minimumSize());
	view_widget->resize(theView->minimumSize());
	theModel = new Model();
	theController = new Controller( theView, theModel, this );
	theModel->setController(theController);
	theView->setController(theController);
	//observer.setController(theController);
	return view_widget;
}
/**
 * Sets the data to the view
 */
void PoVViewPlugin::setData( tlp::Graph* graph, tlp::DataSet dataSet ){
	this->graph = graph;
	//this->graph->addGraphObserver(&this->observer);
	data = &dataSet;
	theModel->setData(this->graph, *data);
	theView->updateGraphInformation(graph->numberOfNodes(),graph->numberOfEdges());
	if( !theModel->validGraphLoaded() ){
	  theView->turnOffPoVButtons();
	}
	theController->drawDegreeGraph();
	draw();
}
/**
 * Gets the data from the view
 */
void PoVViewPlugin::getData( tlp::Graph** graph, tlp::DataSet* dataSet ){
	*graph = this->graph;
	dataSet = data;
}
/**
 * Returns the graph
 */
Graph* PoVViewPlugin::getGraph(){
	return graph;
}

QWidget* PoVViewPlugin::getWidget() {
    return view_widget;
}

void PoVViewPlugin::setInteractors(const std::list<tlp::Interactor *> &interactors) {
}

std::list<tlp::Interactor *> PoVViewPlugin::getInteractors(){
	return std::list<tlp::Interactor *>();
}

void PoVViewPlugin::setActiveInteractor(tlp::Interactor *interactor) {
}

tlp::Interactor *PoVViewPlugin::getActiveInteractor() {
	return NULL;
}

void PoVViewPlugin::createPicture(const std::string &pictureName,int width, int height) {
}

bool PoVViewPlugin::addPointOfView( string name ){
	return false;
}

string PoVViewPlugin::generateDefaultPovName(){
	return string("");
}

void PoVViewPlugin::activatePoVProperties(){}

void PoVViewPlugin::updateLayout(){
  Observable::holdObservers();
  LayoutProperty* layout = graph->getLocalProperty<LayoutProperty>("PoV_NULL_viewLayout");
  *layout = *graph->getLocalProperty<LayoutProperty>("viewLayout");
  Observable::unholdObservers();
}
