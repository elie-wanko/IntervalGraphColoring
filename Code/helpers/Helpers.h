//
// Created by Skovzki on 19/03/2021.
//

#ifndef HEURISTICINTERVALCOLORING_HELPERS_H
#define HEURISTICINTERVALCOLORING_HELPERS_H

#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

/*
 * Prints grid of type <vector<int>>
 */
inline void printIntGrid(vector<vector <int>> const &grid) {
    for (vector<vector<int>>::size_type i = 0; i < grid.size(); i++ ) {
        for (vector<int>::size_type j = 0; j < grid[i].size(); j++ ) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

/*
 * Prints grid of type <vector<string>>
 */
inline void printStringGrid(vector<vector <string>> const &grid) {
    for (vector<vector<string>>::size_type i = 0; i < grid.size(); i++ ) {
        for (vector<string>::size_type j = 0; j < grid[i].size(); j++ ) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

/*
 * Prints grid of type <vector<int>>
 */
inline void printIntVector(vector <int> const &v) {
    for (vector<int>::size_type i = 0; i < v.size(); i++ ) {
        cout << v[i]<< ' ';
    }
    cout << endl;
}

/*
 * Prints grid of type <vector<string>>
 */
inline void printStringVector(vector <string> const &v) {
    for (vector<string>::size_type i = 0; i < v.size(); i++ ) {
        cout << v[i]<< ' ';
    }
    cout << endl;
}


#endif //HEURISTICINTERVALCOLORING_HELPERS_H
