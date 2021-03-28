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
 * Given "adjacencyMatrix" it gets Neighbors of node 'k' based on 'ordering' from "weightVector".
 */
inline vector<int> getNeighbors(int &index, vector<vector<int>> &adjacencyMatrix, vector<vector<int>> &weightVector){
    vector<int> n_k, ordering;

    for (auto &i : weightVector){
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
 * Removes first element of vector, "vec".
 */
inline void pop_front(vector<int> &vec) {
    if (!vec.empty()) {
        vec.erase(vec  .begin());
    }
}


/*
 * Test for Overlaps
 *   k - node
 *   n_k - set of nodes k' s.t. there exists an edge k'k, k' < k
 *   weightVector - ordering of nodes in some way, see NodesOrdering.h
 *   s_g - stores the interval coloring of nodes.
 */
inline void overlaps(int &k, int &l, int &l_j, vector<int> &n_k, vector<vector<int>> &weightVector, vector<vector<int>> &s_g){
    for (int j = 0; j < n_k.size(); ++j) {
        l_j = s_g[n_k[0]][0];
        int r_j = l_j + weightVector[n_k[0]][1] - 1;

        if (r_j < l) {
            pop_front(n_k);
        }
        if (max(l, l_j) - min(l + weightVector[n_k[0]][1] - 1, r_j) <= 0) {
            l = r_j + 1;
            pop_front(n_k);
        }
    }
}

/*
 * Interval Coloring depends on the order of nodes, 'weightVector' chosen from Step 1, NodesOrdering.h
 *   weightVector - ordering of nodes in some way, see NodesOrdering.h
 *   s_g - stores the interval coloring of nodes.
 */
inline vector<vector<int>> intervalColoring(vector<vector<int>> &adjacencyMatrix, vector<vector<int>> &weightVector) {
    vector<vector<int>> s_g(0);

    for (int k = 0; k < weightVector.size(); ++k) {
        // Initialization
        int l = 1, l_j = 1;
        vector<int> n_k = getNeighbors(k, adjacencyMatrix, weightVector);

        // Overlaps
        overlaps(k, l, l_j, n_k, weightVector, s_g);

        // Termination
        vector<int> s_k(weightVector[k][1]);
        if (l_j == l or n_k.empty()) {
            iota(begin(s_k), end(s_k), l);
            s_g.push_back(s_k);
        } else {
            l_j = l;
            overlaps(k, l, l_j, n_k, weightVector, s_g);
            iota(begin(s_k), end(s_k), l);
            s_g.push_back(s_k);
        }
    }

    return s_g;
}


#endif //HEURISTICINTERVALCOLORING_INTERVALCOLORING_H
