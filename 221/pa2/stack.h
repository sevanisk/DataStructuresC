//#pragma once
#include "array_list.h"
#include <stdexcept>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename Object>
class Stack {
   private:
      ArrayList<Object>* s;
      size_t sz;

   public:
      //constructor
      Stack(): s(nullptr), sz(0){
         s = new ArrayList<Object>{};
      }

      ~Stack(){
         delete s;
         sz = 0;
      }

      //copy constructor
      Stack(const Stack& other): s(nullptr), sz(other.sz){
         this->s = new ArrayList<Object>{};
         for(size_t i = 0; i < other.sz; i++){
            s->insert(i, other.s->get(i));
         }
      }

      //copy assignment operator
      Stack& operator=(const Stack& other){
         if(this != &other){
            sz = other.sz;
            for(size_t i = 0; i < other.sz; i++){
               s->insert(i, other.s->get(i));
            }
         }
         return *this;
      }

      void push(const Object& other){
         s->insert(0, other);
         sz++;
      }

      void pop(){
         if(sz == 0){
            throw out_of_range("no");
         }
         s->remove(0);
         sz--;
      }

      Object& top(){
         if(sz == 0){
            throw out_of_range("no");
         }
         return s->get(0);
      }


   // TODO(student): implement Stack
};
