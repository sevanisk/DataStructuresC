//#pragma once
#include <stdexcept>
#include <cstddef>
#include <iostream>

using namespace std;


template <typename Object>
class DoublyLinkedList{
    struct Node{
        Object o;
        Node* next;
        Node* prev;

        Node(const Object& other): o(other), next(nullptr), prev(nullptr){
        }
    };
    private:
        size_t lsize;
        Node* head;
        Node* tail;

    public:
        DoublyLinkedList(): lsize(0), head(nullptr), tail(nullptr){
        }

        ~DoublyLinkedList(){
            Node* curr = nullptr;
            while(head != nullptr){
                curr = head;
                head = head->next;
                curr->next = nullptr;
                curr->prev = nullptr;
                delete curr;
            }
            head = nullptr;
            tail = nullptr;
            curr = nullptr;
            lsize = 0;
        }

        DoublyLinkedList(const DoublyLinkedList& other): lsize(other.lsize), head(nullptr), tail(nullptr){
            if(other.head == nullptr){
                head = nullptr;
                tail = nullptr;
            }
            else{
                Node* curr = other.head;
                Node* n = other.head;
                head = curr;
                while(n != nullptr){
                    curr = n;
                    curr->prev = n->prev;
                    n = n->next;
                    curr->next = n;
                }
                tail = curr;
            }
        }

        DoublyLinkedList& operator=(const DoublyLinkedList& other){
            if (this != &other){
                Node* curr = other.head;
                Node* n = other.head->next;
                head = curr;
                while(n != nullptr){
                    curr->next = n;
                    curr = curr->next;
                    n = n->next;
                }
                this->tail = curr;
            }
            lsize = other.lsize;
            return *this;
        }

        size_t size() const{
            return lsize;
        }

        void insert(size_t index, const Object obj){
            if(index > lsize){
                throw out_of_range("no");
            }

            Node* n = new Node(obj);
            // in the beginning
            if(index == 0){
                if(head == nullptr){
                    head = n;
                    tail = n;
                    head->next = nullptr;
                    tail->prev = nullptr;
                }
                else{
                    n->next = head;
                    head->prev = n;
                    head = n;
                }
            }
            // in the end
            else if(index == lsize){
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
            else{
                // in the middle
                size_t curr_index = 0;
                Node* temp = head;
                while(curr_index != index){
                    temp = temp->next;
                    curr_index++;
                }
                n->prev = temp->prev;
                n->next = temp;
                temp->prev->next = n;
                temp->prev = n;
            }
            lsize++;
        }

    void remove(size_t index){
        Node* curr = head;
        size_t curr_index=0;
        if(index > size() || head == nullptr){
            throw out_of_range("nope");
        }

        if(index == 0){
            head = head->next;
            head->prev = nullptr;
            curr->next = nullptr;
            if(size() == 2){
                tail->prev = nullptr;
            }
            delete curr;
        }
        else if(index == size()){
            tail = tail->prev;
            tail->next = nullptr;
            curr->prev = nullptr;
            if(size() == 2){
                head->next = nullptr;
            }
            delete curr;
        }
        else{
            while(curr_index != index){
                curr=curr->next;
                curr_index++;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->prev = nullptr;
            curr->next = nullptr;
            delete curr;
        }
        lsize--;
    }

    Object& operator[](size_t index){
        if(index >= size()){
            throw out_of_range("no");
        }

        Node* n = head;
        size_t curr_index = 0;
        while(curr_index != index){
            n = n->next;
            curr_index++;
        } 
        return n->o;

    }
};


