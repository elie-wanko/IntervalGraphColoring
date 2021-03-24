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


    /*
     * RUNS
     */
    vector<vector<int>> weightVector1, weightVector2, weightVector3, weightVector4, matrix;
    matrix = adjacencyMatrix.getAdjacencyMatrix();


    cout << "\n***  SOLUTIONS  ***\n" << endl;

    cout << "\nIndex Greedy : " << endl;
    weightVector1 = indexGreedy(weightVector);
    printIntGrid(weightVector1);
    printIntGrid(intervalColoring(matrix, weightVector1));

    cout << "\nWeight Greedy : " << endl;
    weightVector2 = weightGreedy(weightVector);
    printIntGrid(weightVector2);
    printIntGrid(intervalColoring(matrix, weightVector2));

    cout << "\nDegree Greedy : " << endl;
    weightVector3 = degreeGreedy(matrix, weightVector);
    printIntGrid(weightVector3);
    printIntGrid(intervalColoring(matrix, weightVector3));

    cout << "\nNeighbor Greedy : " << endl;
    weightVector4 = neighborGreedy(matrix, weightVector);
    printIntGrid(weightVector4);
    printIntGrid(intervalColoring(matrix, weightVector3));


    cout << "\n***  DONE!  ***\n" << endl;
    return 0;
}
