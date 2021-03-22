//
// Created by Skovzki on 17/03/2021.
//

#ifndef HEURISTICINTERVALCOLORING_WEIGHTVECTOR_H
#define HEURISTICINTERVALCOLORING_WEIGHTVECTOR_H


class WeightVector {
    private:
        int sizeVector;
        int  **weightVector;

    public:
        WeightVector(int n) : sizeVector(n){
            this->sizeVector = n;
//            weightVector = new int *
        }

        void addWeight(int n);
        void displayVector();
};


#endif //HEURISTICINTERVALCOLORING_WEIGHTVECTOR_H
