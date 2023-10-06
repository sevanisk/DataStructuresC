//#pragma once
#include "array_list.h"
#include <stdexcept>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename Object>
class Queue {
private:
    ArrayList<Object>* q;

public:
    Queue(): q(nullptr){
        q = new ArrayList<Object>{};
    }

    ~Queue(){
        if(q!=nullptr){
            delete q;
            q = nullptr;
        }
    }

    Queue(const Queue& other): q(nullptr){
        q = new ArrayList<Object>{};
        for(size_t i = 0; i < other.q->size(); i++){
            q->insert(i, other.q->get(i));
        }
    }

    Queue& operator=(const Queue& other){
         if(this != &other){
            delete q;
            q = new ArrayList<Object>{};
            for(size_t i = 0; i < other.q->size(); i++){
               q->insert(i, other.q->get(i));
            }
         }
        return *this;
    }

    void enqueue(const Object& obj){
        q->insert(q->size(), obj);
    }

    Object dequeue(){
        if(q->size() == 0){
            throw out_of_range("no");
        }
        Object holder = q->get(0);
        q->remove(0);
        return holder;
    }

    Object& front(){
        if(q->size() == 0){
            throw out_of_range("no");
         }
        return q->get(0);
    }
    
    // TODO(student): implement Queue
};
