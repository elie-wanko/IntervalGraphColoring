//
// Created by Elie on 18/01/2021.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <string>


using namespace std;

// An interval has a start time and end time
struct Interval {
    int start, end;
};

// Compares two intervals according to staring times.
bool compareInterval(Interval i1, Interval i2) {
    return (i1.start < i2.start);
}

void GreedyColoring() {
    int num_intervals;
    cout << "How many intervals do you want to consider ? \n";
    cin >>  num_intervals;

    // Creating array to store intervals
    int arr_size = num_intervals;
    int *start_arr = (int *)malloc(arr_size * sizeof(int));
    int *end_arr = (int *)malloc(arr_size * sizeof(int));

    // intervals from user to array's
    int i = 0;
    int interval_start = 0;
    int interval_end = 0;

    cout << "\nTo enter an interval, type in the start and end separated by a space, e.g. 2 5.\n";
    for (i = 0; i < num_intervals; i++) {
        cout <<"Interval no. " << i+1 << ": ";
        cin >> interval_start >> interval_end;
        start_arr[i] = interval_start;
        end_arr[i] = interval_end;
    }


    //cout graph intervals
    cout <<"\nIntervals : {" ;
    for (i = 0; i < num_intervals; i++) {
        cout << "(" << start_arr[i] << "," << end_arr[i] << "), ";
    }
    cout <<"}";

    // Sorting intervals arrays by starters only
    int temp, j;
    for (j = 0; j < num_intervals; j++) {
        for (i = 1; i < num_intervals; i++) {
            if (start_arr[i - 1] > start_arr[i]) {

                //swaping the start_array
                temp = start_arr[i - 1];
                start_arr[i - 1] = start_arr[i];
                start_arr[i] = temp;

                //swaping the end_array
                temp = end_arr[i - 1];
                end_arr[i - 1] = end_arr[i];
                end_arr[i] = temp;
            }
        }
    }

    // Chromatic color
    int count_arr_size = 0;
    int chromatic_number = 0;

    for (i = 0; i < num_intervals; i++) {
        if (count_arr_size < end_arr[i])
            count_arr_size = end_arr[i];
    }
    count_arr_size++; // cause we most include the specific 'end' value
    // creating a count_array & set 0's ...
    int *count_arr = (int *)malloc(count_arr_size * sizeof(int));
    for (i = 0; i < count_arr_size; i++)
        count_arr[i] = 0;

    //"installing & suming" the intervals langh to array
    for (i = 0; i < num_intervals; i++) { // running all the intervals
        for (j = start_arr[i]; j <= end_arr[i]; j++) // running about any interval range
            (count_arr[j])++;
    }

    //set chromatic number of g to the max value of count_array
    for (i = 0; i < count_arr_size; i++) {
        if (chromatic_number < count_arr[i])
            chromatic_number = count_arr[i];
    }
    cout <<"\n * Chromatic Number of G = " << chromatic_number;


    // Optimal coloring (greedy coloring algorithm
    int *intervalColors_arr = (int *)malloc(num_intervals * sizeof(int));
    int *usedColors_arr = (int *)malloc(num_intervals * sizeof(int));

    for (i = 0; i < num_intervals; i++) // set zero's as the default color for all intervals
        intervalColors_arr[i] = 0;

    for (i = 0; i < num_intervals; i++) {
        for (j = 0; j < num_intervals; j++) // clearing the used colors list
            usedColors_arr[j] = 0;
        for (j = 0; j < num_intervals; j++) {
            if ((i != j) && !((end_arr[i] < start_arr[j]) || (start_arr[i] > end_arr[j])))
                usedColors_arr[intervalColors_arr[j]]++;
        }
        j = 0;
        while (usedColors_arr[j] != 0) // finding the smallest color that not in use.
            j++;
        intervalColors_arr[i] = j;
    }

    // cout intervals colorings
    cout <<("\n\nOptimal Coloring \n");
    cout << setw(3) << "No." << setw(10) << "  Intervals" << setw(7) << "  Color" << endl;
    for (i = 0; i < num_intervals; i++) {
        cout << setw(3) << i + 1 << setw(10) << to_string(start_arr[i]) + ", " + to_string(end_arr[i]) << setw(7) << intervalColors_arr[i] + 1 << endl;
    }
}


int main() {
    GreedyColoring();
    cout << "\n*** End ***\n" << endl;
}
