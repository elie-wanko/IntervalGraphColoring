//
// Created by Skovzki on 17/03/2021.
//

#ifndef HEURISTICINTERVALCOLORING_NODESORDERING_H
#define HEURISTICINTERVALCOLORING_NODESORDERING_H

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


inline vector<vector<int>> indexGreedy(vector<vector<int>> &weightVector) {
    sort(weightVector.begin(), weightVector.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });

    return weightVector;
}

inline vector<vector<int>> weightGreedy(vector<vector<int>> &weightVector) {
    sort(weightVector.begin(), weightVector.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    });

    return weightVector;
}


inline vector<vector<int>> degreeGreedy(vector<vector<int>> &adjacencyMatrix, vector<vector<int>> &weightVector){
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        weightVector[i].push_back(accumulate(adjacencyMatrix[i].begin(), adjacencyMatrix[i].end(), 0));
    }

    sort(weightVector.begin(), weightVector.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    });

    return weightVector;
}

inline vector<vector<int>> neighborGreedy(vector<vector<int>> &adjacencyMatrix, vector<vector<int>> &weightVector) {
    vector<int> weights, tempVector;

    for (auto & i : weightVector){
        weights.push_back(i[1]);
    }

    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        adjacencyMatrix[i][i] = 1;
        tempVector = weights;
        transform(adjacencyMatrix[i].begin(), adjacencyMatrix[i].end(),
                  tempVector.begin(), tempVector.begin(),
                  multiplies<int>());

        weightVector[i].push_back(accumulate(tempVector.begin(), tempVector.end(), 0));
    }

    sort(weightVector.begin(), weightVector.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[2] > b[2];
    });

    return weightVector;
}

#endif //HEURISTICINTERVALCOLORING_NODESORDERING_H
