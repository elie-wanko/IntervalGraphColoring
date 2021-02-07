// A C++ program to demonstrate STL sort() using our own comparator

#include "bits/stdc++.h"

using namespace std;

// An interval has a start time and end time
struct Interval {
    int start, end;
};

// Compares two intervals according to staring times.
bool compareInterval(Interval i1, Interval i2) {
    return (i1.start < i2.start);
}

int main()
{
    Interval arr[]
            = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 }, {1, 3} };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "n = " << n << endl;
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
    cout << sizeof(arr[1]) << endl;
    cout << arr << endl;

    int num_intervals = 2
    int interval_start = 0;
    int interval_end = 0;

    for (i = 0; i < num_intervals; i++) {
        cout <<"Interval no. " << i+1 << ": ";
        cin >> interval_start >> interval_end;
        start_arr[i] = interval_start;
        end_arr[i] = interval_end;
    }

    // sort the intervals in increasing order of start time
    sort(arr, arr + n, compareInterval);

    cout << "Intervals sorted by start time : \n";
    for (int i = 0; i < n; i++)
        cout << "[" << arr[i].start << "," << arr[i].end
             << "] ";
    cout << endl;

    return 0;
}
