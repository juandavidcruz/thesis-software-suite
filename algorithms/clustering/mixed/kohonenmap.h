/* 
 * File:   KohonenMap.h
 * Author: juandavidcruz
 *
 * Created on February 3, 2012, 10:25 PM
 * 
 * This class implements a Kohonen map 
 */

#ifndef KOHONENMAP_H
#define	KOHONENMAP_H

#include <map>
#include <vector>
#include <iostream>
#include <assert.h>
#include <string.h>

#include "somnode.h"

#define MAX_FLOAT 1E37

using namespace std;

class KohonenMap {
public:
    /**
     * Default constructor
     */
    KohonenMap();
    /**
     * The constructor
     * @param _rows
     * @param _cols
     * @param _lerning_rate
     */
    KohonenMap(int _rows, int _cols, float _learning_rate, int _pattern_size );
    /**
     * Destructor
     */
    virtual ~KohonenMap();
    /**
     * Instanciates the map.
     */
    void initialize();
    /**
     * Initializes the map using random samples from the pattern set
     */
    void initialize( vector<vector<double> > patterns );
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     * Calculates the distance between two patterns.
     * @param neuron_index the index of the neuron
     * @param pattern the pattern to be measured
     * @return the Euclidean distance between the neuron and pattern
     */
    float distance( int neuron_index, vector<double>& pattern );
    //Getters and setters
    /**
     * Gets a pointer to an specific neuron
     */
    SOM_Node* getNeutonAt( int _index );    
    /**
     * Gets the number of rows of the neuron map
     */
    int getNRows() const;
    /**
     * Gets the number of columns of the neuron map
     */
    int getNCols() const;
    /**
     * Sets the number of rows for the neuron map
     */    
    void setRows( int _rows );
    /**
     * Sets the number of columns for the neuron map
     */
    void setCols( int _cols );
    /**
     * Gets the number of features of the patterns
     */
    int getNFeatures() const;
    /**
     * Sets the number of features for the patterns
     */
    void setNFeatures( int _psize );
    /**
     * Gets the number of neurons
     */
    int getNNeurons() const;
    /**
     * Gets the value of the learning rate
     */
    float getlearningRate() const;
    /**
     * Sets the learning rate for the algorithm
     */
    void setLearning_rate(float _learning_rate);
    /**
     * Ask if the map is ready or not to train
     */
    bool isReady();
    
    int select_random_pattern( int* selected, int size );
 
private:
    /**
     * Rows of the map
     */
    int rows;
    /**
     * Columns of the map
     */
    int cols;
    /**
     * Learning rate
     */
    float learning_rate;
    /**
     * The size of each vector to be presented to the network.
     */
    int number_of_features;
    /**
     * The map in row major order!
     */
    map<int, SOM_Node*> theMap;
    /**
     * The assignation map. The index the is the pattern and the value is the neuron index.
     */
    map<int,int> assignation;
    
    int pattern_count;
    /**
     * Indicates whether the map is ready or not to do the training
     */
    bool ready;

};

#endif	/* KOHONENMAP_H */

