#include <iostream>
#include <cstdlib>
#include <vector>

#include "utils/AdjacencyMatrix.h"
#include "utils/WeightVector.h"
#include "utils/NodesOrdering.h"
#include "utils/IntervalColoring.h"
#include "helpers/Helpers.h"


using namespace std;
vector<char> nodeLabel = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};


int main() {
    std::cout << "\n***  Heuristic Interval Coloring!  ***\n" << std::endl;

    int size, max_edges, edge_start, edge_end, weight;
    bool validMatrix, validVector = false;

    do {
        cout << "Enter size 'n' of Adjacency Matrix : ";
        cin >> size;

        if (cin.good() && size > 1){
            validMatrix = true;
            break;
        } else{
            cin.clear();  //something went wrong, we reset the buffer's state to good
            cin.ignore(numeric_limits<streamsize>::max(),'\n');  //and empty it
            cout << "Invalid input! Please make sure the input is an integer and it is greater than or equal to 2." << endl;
        }
    } while (!validMatrix);

    /*
     *1 Creating the adjacency matrix.
     */
    AdjacencyMatrix adjacencyMatrix = AdjacencyMatrix (size);
    max_edges = size * (size - 1);  // max number of edges in an undirected graph
    cout << "Awesome! You have opted to create an 'Adjacency Matrix' of size " << size << "*" << size <<
         ".\nThe maximum number of edges is " << max_edges << ".\n" << endl;

    for (int i = 0; i < max_edges; i++) {
        cout << "Enter edge (-1 -1 to exit): ";
        cin >> edge_start >> edge_end;
        if ((edge_start == -1) && (edge_end == -1))
            break;
        adjacencyMatrix.addEdge(edge_start, edge_end);
    }
    adjacencyMatrix.displayMatrix();

    /*
     * Creating the weight vector
     */
    cout << "\nNow, let's create the weight vector, w." << endl;
    vector<vector<int>> weightVector(0);
    do{
        for (int i = 0; i<size;) {
            cout << "Enter weight of node " << nodeLabel[i] << " : ";
            cin >> weight;
            if (cin.good() && weight > 0) {
                weightVector.push_back({i+1, weight});
                i++;
            } else {
                cin.clear();  //something went wrong, we reset the buffer's state to good
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  //and empty it
                cout << "Invalid input! Please make sure the weight is an integer greater than or equal to one."
                     << endl;
            }
        }
        validVector = true;
    } while (!validVector);


    printIntGrid(weightVector);
    vector<vector<int>> weightVector1, weightVector2, weightVector3, weightVector4;
    weightVector1 = indexGreedy(weightVector);
    weightVector2 = weightGreedy(weightVector);
    weightVector3 = degreeGreedy(adjacencyMatrix.getAdjacencyMatrix(), weightVector);
    weightVector4 = neighborGreedy(adjacencyMatrix.getAdjacencyMatrix(), weightVector);

    cout << "\nIndex Greedy : " << endl;
    printIntGrid(weightVector1);
    for (int i = 0; i < size; ++i) {
        vector<int> s_k = intervalColoring(i, adjacencyMatrix.getAdjacencyMatrix(), indexGreedy(weightVector1));
        weightVector1[i].insert(end(weightVector1[i]), begin(s_k), end(s_k));
    }
    printIntGrid(weightVector1);

    cout << "\nWeight Greedy : " << endl;
    printIntGrid(weightVector2);
    for (int i = 0; i < size; ++i) {
        vector<int> s_k = intervalColoring(i, adjacencyMatrix.getAdjacencyMatrix(), weightGreedy(weightVector2));
        weightVector2[i].insert(end(weightVector2[i]), begin(s_k), end(s_k));
    }
    printIntGrid(weightVector2);

    cout << "\nDegree Greedy : " << endl;
    printIntGrid(weightVector3);
    for (int i = 0; i < size; ++i) {
        vector<int> s_k = intervalColoring(i, adjacencyMatrix.getAdjacencyMatrix(), degreeGreedy(adjacencyMatrix.getAdjacencyMatrix(), weightVector3));
        weightVector3[i].insert(end(weightVector3[i]), begin(s_k), end(s_k));
    }
    printIntGrid(weightVector3);

    cout << "\nNeighbor Greedy : " << endl;
    printIntGrid(weightVector4);
    for (int i = 0; i < size; ++i) {
        vector<int> s_k = intervalColoring(i, adjacencyMatrix.getAdjacencyMatrix(), neighborGreedy(adjacencyMatrix.getAdjacencyMatrix(), weightVector4));
        weightVector4[i].insert(end(weightVector4[i]), begin(s_k), end(s_k));
    }
    printIntGrid(weightVector4);

    cout << "\n***  DONE!  ***\n" << endl;
    return 0;
}
