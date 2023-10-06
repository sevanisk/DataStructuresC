//#pragma once

#include <stdexcept>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename Object>
class ArrayList {
    private:
        Object* alist;
        size_t asize;
        size_t acapacity;

    public:
        // TODO(student): implement ArrayList
        ArrayList(): alist(nullptr), asize(0), acapacity(0) {
            alist = new Object[0]{};
        }

        explicit ArrayList(size_t newsize): alist(nullptr), asize(0), acapacity(newsize){
            alist = new Object[acapacity]{};
        }


        ~ArrayList(){
            if(alist!=nullptr){
                delete[] alist;
                alist = nullptr;
            }
            asize = 0;
            acapacity = 0;
        }

        ArrayList(const ArrayList& other){ // use & for the reference to call by object
            acapacity = other.acapacity;
            asize = other.asize;
            alist = new Object[acapacity];
            for(size_t i = 0; i < asize; i++){
                alist[i] = other.alist[i];
            }

        }

        ArrayList& operator=(const ArrayList& other){
            if(this!= &other){
                delete[] alist;
                asize = other.asize;
                acapacity = other.acapacity;

                alist = new Object[acapacity];
                for(size_t i = 0; i < asize; i++){
                    alist[i] = other.alist[i];
                }
            }

            return *this;
        }

        size_t size() const {
            return this->asize;
        }

        Object& operator[](size_t index) {
            if(index >= asize){
                throw out_of_range("too big");
            }
            return alist[index];
        }

        void insert(size_t index, const Object& other) {
            // exceptions
            if(index > asize){
                throw out_of_range("too big also");
            }


            // other special cases
            if(asize == acapacity){
                acapacity *= 2;
            }

            if(asize == 0 || acapacity == 0){
                acapacity = 1;
            }



            asize++;
            size_t actual_index = 0;
            Object* newlist = new Object[acapacity];
            for(size_t i = 0; i < asize; i++){
                if(i == index){
                    newlist[i] = other;
                }
                else{
                    newlist[i] = alist[actual_index];
                    actual_index++;
                }
            }

            delete[] alist;
            alist = nullptr;
            alist = newlist;
        }

        void remove(size_t index){
            if(index >= asize){
                throw out_of_range("too big");
            }
            size_t actual_index = 0;
            Object* newlist = new Object[acapacity]{};
            for(size_t i = 0; i < asize; i++){
                if(i != index){
                    newlist[actual_index] = alist[i];
                    actual_index++;
                }
            }

            asize--;
            delete[] alist;
            alist = nullptr;
            alist = newlist;
        }

        Object& get(size_t index){
            return alist[index];
        }
};

//#endif  // ARRAY_LIST_H