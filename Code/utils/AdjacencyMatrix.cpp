//
// Created by Skovzki on 17/03/2021.
//
#include "AdjacencyMatrix.h"

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
vector<char> nodeLabels = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};


/*
* Adds Edge to Graph
*/
void AdjacencyMatrix::addEdge(int edge_start, int edge_end) {
    if (edge_start > size || edge_end > size || edge_start <= 0 || edge_end <= 0) {
        cout << "Invalid edge! Inputs must be in the range 1 ... " << size << " inclusive.\n";
    } else {
        adjMatrix[edge_start - 1][edge_end - 1] = 1;
        adjMatrix[edge_end - 1][edge_start - 1] = 1;
    }
}

/*
* Removes Edge from Graph
*/
void AdjacencyMatrix::removeEdge(int edge_start, int edge_end) {
    if (edge_start > size || edge_end > size || edge_start <= 0 || edge_end <= 0) {
        cout << "Invalid edge! Inputs must be in the range 1 ... " << size << " inclusive.\n";
    } else {
        adjMatrix[edge_start - 1][edge_end - 1] = 0;
        adjMatrix[edge_end - 1][edge_start - 1] = 0;
    }
}

/*
 * Displays Adjacency Matrix
 */
void AdjacencyMatrix::displayMatrix() {
    cout << "\nHere is your graph ...\n     ";
    for (int i = 1; i <= size; i++) cout << i << "  ";
    cout << endl;
    for (int i = 1; i <= size + 3; i++) cout << "---";
    cout << endl;
    int i, j;
    for (i = 0; i < size; i++) {
        cout << nodeLabels[i] << "  | ";
        for (j = 0; j < size; j++)
            cout << adjMatrix[i][j] << "  ";
        cout << endl;
    }
}

/*
 * Transforms Matrix to a vector<vector<int>> type
 */
vector<vector<int>> AdjacencyMatrix::getAdjacencyMatrix() {
    vector<vector<int>> grid;
    for (int i = 0; i < size; i++) {
        vector<int> row;
        row.reserve(size);
        for (int j = 0; j < size; j++) {
            row.push_back(adjMatrix[i][j]);
        }
        grid.push_back(row);
    }
    return grid;
}

/*
 * Checks if two nodes are connected by an edge
 */
int AdjacencyMatrix::isConnected(int i, int j) {
    if (adjMatrix[i][j] == 1)
        return true;
    else
        return false;

}