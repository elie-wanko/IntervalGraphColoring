//
// Created by Elie Wanko on 05/02/2021.
//

#include "bits/stdc++.h"

using namespace std;

void print(vector<float> a) {
    std::cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';

    cout << endl;
}

int main(int argc, char ** argv){
    int num_intervals;
    cout << "Enter the number of intervals : " << endl;
    cin >> num_intervals;

    vector <float> interval_starting;
    vector <float> interval_ending;
    float temp1, temp2;

    cout << "\nTo enter an interval, type in the start and end separated by a space."
            "\n Hint: For time enter in 24 hr format, e.g. 9 16, 11 15, ..." << endl;
    for (int i = 0; i < num_intervals ; i++){
        cin >> temp1 >> temp2;
        interval_starting.push_back(temp1);
        interval_ending.push_back(temp2);
    }

    sort(interval_starting.begin(), interval_starting.end());
    sort(interval_ending.begin(), interval_ending.end());

    int num_colors = 0, total = 1;
    int i = 0, j = 0;

    while (i < num_intervals && j < num_intervals){
        if (interval_starting[i] < interval_ending[j]){
            num_colors++;
            i++;
            if (num_colors > total) total = num_colors;
        }else{
            num_colors--;
            j++;
        }
    }
    cout << "For the given graph with " << num_intervals << " intervals";
    cout << " Total number of colors used is " << total << "." << endl;

    print(interval_starting);
    print(interval_ending);

    return 0;
}