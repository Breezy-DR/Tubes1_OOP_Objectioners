
#ifndef ARRAYCOMPARER_HPP
#define ARRAYCOMPARER_HPP
//#define CAPACITY 13
#include <vector>
using namespace std;
#pragma once

template <class T>
class ArrayComparer {
    private:
        vector<T> elements;
//        int nEff;
    public:
//        ArrayComparer() {
//            this->elements = new T[CAPACITY];
//            this->nEff = 0;
//        }
        ArrayComparer(vector<T> elements){
        this->elements=elements;
        }
        ~ArrayComparer() {}
        void enqueue(const T q){
//            if(this->nEff == CAPACITY){
//                throw "Array is full";
//            }
//            else{
//                this->elements[this->nEff] = q;
//                this->nEff++;
//            }
            this->elements.push_back(q);
        }
//        T dequeue(){
//            if(this->nEff == 0){
//                throw "Array is empty";
//            }
//            else{
//                T ans = this->elements[0];
//                for(int i = 0; i < this->nEff; i++){
//                    this->elements[i] = this->nEff[i+1];
//                }
//                this->nEff--;
//                return ans;
//            }
//        }
        T max() {
            int max = this->elements.at(0);
            for (int i=1; i<this->nEff; i++) {
                if (this->elements.at(i) > max) {
                    max = this->elements.at(i);
                }
            }
            return max;
        }

        vector<T> sort(){
            for (int i = 0; i < this->elements.size(); ++i) {
                for (int j = 0; j < this->elements.size() - i; ++j) {
                    if (this->elements.at(j)> this->elements.at(j+1)){
                        T temp= this->elements.at(j);
                        this->elements.at(j)= this->elements.at(j+1);
                        this->elements.at(j+1)=temp;
                    }
                }
            }
            return this->elements;
        }

};



#endif