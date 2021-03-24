//
// Created by Elie Wanko on 08/03/2021.
//
#include "utils/AdjacencyMatrix.h"
#include "utils/NodesOrdering.h"
#include "utils/IntervalColoring.h"
#include "helpers/Helpers.h"

#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <string>

using namespace std;
//using std::begin;
//using std::end;
//vector<string> nodeLabel = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n"};




int main () {

//    int n = 10;
//    vector<string> ca(2, " ");
//
//    vector<int> v(n) ; // vector with n ints.
//    iota (begin(v), end(v), 1); // Fill with 0, 1, ...
//    printIntVector(v);
//
//    for( int i : v) ca.push_back( to_string(i));
//    printStringVector(ca);


    vector<vector<int>> grid1, grid2, ordering1i, ordering1w, ordering1n, ordering2i, ordering2w, ordering2d, ordering2n;
    vector<int> neighbors_index, test;

    /*
     * EXAMPLES
     */
    grid1 = {{0, 1, 0, 1, 0},
             {1, 0, 0, 1, 0},
             {0, 0, 0, 1, 0},
             {1, 1, 1, 0, 0},
             {0, 0, 0, 0, 0}};

    ordering1i = {{1, 1}, {2, 2}, {3, 2}, {4, 1}, {5, 3}};
    ordering1w = {{5, 3}, {2, 2}, {3, 2}, {1, 1}, {4, 1}};
    ordering1n = {{4, 1}, {1, 1}, {2, 2}, {3, 2}, {5, 3}};


    grid2 ={{0, 1, 0, 1, 1, 0, 1},
            {1, 0, 1, 1, 0, 0, 1},
            {0, 1, 0, 1, 0, 1, 0},
            {1, 1, 1, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1, 0, 1},
            {1, 1, 0, 0, 0, 1, 0}};

    ordering2i = {{1, 1}, {2, 2}, {3, 2}, {4, 3}, {5, 2}, {6, 3}, {7, 3}};

    ordering2w = {{4, 3}, {6, 3}, {7, 3}, {2, 2}, {3, 2}, {5, 2}, {1, 1}};
    ordering2d = {{1, 1}, {2, 2}, {4, 3}, {3, 2}, {5, 2}, {6, 3}, {7, 3}};
    ordering2n = {{1, 1}, {2, 2}, {3, 2}, {4, 3}, {6, 3}, {5, 2}, {7, 3}};

    /*
     * TESTING
     */
    int l = 1, l_k = 1, r_k;
    vector<int> n_i = {0, 1, 2, 3, 4};

    cout << "\nBy Weight ..." << endl;
    printIntGrid(intervalColoring(grid1, ordering1w));


//
//    int n =7;
//    cout << getIndex(ordering2w, n) << endl;






//    cout << "\n1 by Weight ..." << endl;
//    for (int i = 0; i < n_i.size(); ++i) {
//        printIntVector(intervalColoring(n_i[i], grid1, ordering1w));
//    }
//
//    cout << "\n1 by Neighbour ..." << endl;
//    for (int i = 0; i < n_i.size(); ++i) {
//        printIntVector(intervalColoring(n_i[i], grid1, ordering1n));
//    }
//
//    cout << "\n2 by Index ..." << endl;
//    for (int i = 0; i < n_i.size(); ++i) {
//        printIntVector(intervalColoring(n_i[i], grid2, ordering2i));
//    }
//
//    cout << "\n2 by Weight ..." << endl;
//    for (int i = 0; i < n_i.size(); ++i) {
//        printIntVector(intervalColoring(n_i[i], grid2, ordering2w));
//    }
//
//    cout << "\n2 by Degree ..." << endl;
//    for (int i = 0; i < n_i.size(); ++i) {
//        printIntVector(intervalColoring(n_i[i], grid2, ordering2d));
//    }
//
//    cout << "\n2 by Neighbour ..." << endl;
//    for (int i = 0; i < n_i.size(); ++i) {
//        printIntVector(intervalColoring(n_i[i], grid2, ordering2n));
//    }

}
