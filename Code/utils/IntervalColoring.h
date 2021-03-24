//
// Created by Skovzki on 21/03/2021.
//

#ifndef HEURISTICINTERVALCOLORING_INTERVALCOLORING_H
#define HEURISTICINTERVALCOLORING_INTERVALCOLORING_H

#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#include <tuple>


using namespace std;


/*
 * Gets Neighbors of 'node' k based on 'ordering'.
 */
inline vector<int> getNeighbors(int &index, vector<vector<int>> &adjacencyMatrix, vector<vector<int>> &weightVector){
    vector<int> n_k, ordering;

    for (auto & i : weightVector){
        ordering.push_back(i[0]);
    }

    int k = ordering[index];
    for(int i=0; i<ordering.size(); i++){
        if (ordering[i] == k){
            break;
        } else if (adjacencyMatrix[k-1][ordering[i]-1] == 1){
            n_k.push_back(i);
        }
    }
    return n_k;
}


/*
 * Removes first element of vector
 */
inline void pop_front(vector<int> &v) {
    if (!v.empty()) {
        v.erase(v.begin());
    }
}


/*
 * Gets index of node from weightVector
 */
inline int getIndex(vector<vector<int>> weightVector, int node) {
    vector<int> ordering;
    int index;
    for (auto & i : weightVector) {
        ordering.push_back(i[0]);
    }

    auto it = find(ordering.begin(), ordering.end(), node);
    index = it - ordering.begin();  // calculating the index of K

    return index;
}

/*
 *
 */
inline void overlaps(int &index, int &r_j, int &l_j, int &l, vector<int> &n_k, vector<vector<int>> &weightVector, vector<vector<int>> &s_g){
    for (int j = 0; j < n_k.size(); ++j) {
        l_j = s_g[getIndex(weightVector, weightVector[n_k[0]][1])][0];
        r_j = l_j + weightVector[n_k[0]][1] - 1;

        if (r_j < l) {
            pop_front(n_k);
        }
        if (max(l, l_j) - min(l + weightVector[index][1] - 1, r_j) <= 0) {
            l = r_j + 1;
            pop_front(n_k);
        }
    }
}

/*
 *
 */
inline vector<vector<int>> intervalColoring(vector<vector<int>> &adjacencyMatrix, vector<vector<int>> &weightVector) {
    vector<vector<int>> s_g(0);

    for (int index = 0; index < weightVector.size(); ++index) {
        // Initialization
        int l = 1, l_k = 1, l_j, r_j;
        vector<int> n_k = getNeighbors(index, adjacencyMatrix, weightVector);

        // Overlaps
        overlaps(index, r_j, l_j, l, n_k, weightVector, s_g);

        // Termination
        vector<int> s_k(weightVector[index][1]);
        if (l_k == l or n_k.empty()) {
            iota(begin(s_k), end(s_k), l);
            s_g.push_back(s_k);
        } else {
            l_k = l;
            overlaps(index, r_j, l_j, l, n_k, weightVector, s_g);
            iota (begin(s_k), end(s_k), l);
            s_g.push_back(s_k);
        }
    }
    return s_g;
}


#endif //HEURISTICINTERVALCOLORING_INTERVALCOLORING_H
