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


inline void overlaps(vector<int> &n_k, int &r_k, int &l_k, int &l, vector<vector<int>> &weightVector){
    for (int k = 0; k < n_k.size(); ++k) {
        r_k = l_k + weightVector[n_k[0]][1] - 1;
        if (r_k < l) {
            pop_front(n_k);
        }
        if (max(l, l_k) - min(l + weightVector[n_k[0]][1] - 1, r_k) <= 0) {
            l = r_k + 1;
            pop_front(n_k);
        }
    }
}


inline vector<int> intervalColoring(int &index, vector<vector<int>> &adjacencyMatrix, vector<vector<int>> &weightVector) {
    // Initialization
    int l = 1, l_k = 1, r_k = 0;
    vector<int> n_k = (getNeighbors(index, adjacencyMatrix, weightVector));

    // Overlaps
    overlaps(n_k, r_k, l_k, l, weightVector);
    
    // Termination
    vector<int> s_k(weightVector[index][1]);
    if(l_k == l or n_k.empty()){
        iota (begin(s_k), end(s_k), l);
    }else{
        l_k = l;
        overlaps(n_k, r_k, l_k, l, weightVector);
        iota (begin(s_k), end(s_k), l);
    }
    return s_k;
}


#endif //HEURISTICINTERVALCOLORING_INTERVALCOLORING_H
