//
// Created by Skovzki on 17/03/2021.
//

#ifndef HEURISTICINTERVALCOLORING_ADJACENCYMATRIX_H
#define HEURISTICINTERVALCOLORING_ADJACENCYMATRIX_H

#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>

using namespace std;

class AdjacencyMatrix {
    private:
        int size;
        int **adjMatrix;

    public:
        explicit AdjacencyMatrix(int n) : size(n){
            this->size = n;
            adjMatrix = new int* [n];
            for (int i = 0; i < n; i++) {
                adjMatrix[i] = new int [n];
                for(int j = 0; j < n; j++) {
                    adjMatrix[i][j] = 0;
                }
            }
        }

        void addEdge(int edge_start, int edge_end);
        void removeEdge(int edge_start, int edge_end);
        int isConnected(int i, int j);
        void displayMatrix();
        vector<vector<int>> getAdjacencyMatrix();

};

#endif //HEURISTICINTERVALCOLORING_ADJACENCYMATRIX_H
