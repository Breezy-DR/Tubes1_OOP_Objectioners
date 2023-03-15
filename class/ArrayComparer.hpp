
#ifndef ARRAYCOMPARER_HPP
#define ARRAYCOMPARER_HPP
#define CAPACITY 13

template <class T>
class ArrayComparer {
    private:
        T *elements;
        int nEff;
    public:
        ArrayComparer() {
            this->elements = new T[CAPACITY];
            this->nEff = 0;
        }
        ~Queue() {}
        void enqueue(const T q){
            if(this->nEff == CAPACITY){
                throw "Array is full";
            }
            else{
                this->elements[this->nEff] = q;
                this->nEff++;
            }
        }
        T dequeue(){
            if(this->nEff == 0){
                throw "Array is empty";
            }
            else{
                T ans = this->elements[0];
                for(int i = 0; i < this->nEff; i++){
                    this->elements[i] = this->nEff[i+1];
                }
                this->nEff--;
                return ans;
            }
        }
        T max() {
            int max = this->elements[0];
            for (int i=1; i<this->nEff; i++) {
                if (this->elements[i] > max) {
                    max = this->elements[i]
                }
            }
            return T;
        }

};



#endif