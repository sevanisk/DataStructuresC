//#pragma 

#include <stdexcept>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename Object> 
class Collection {
    private:
        Object* ptr;
        size_t ptr_size;
        size_t ptr_capacity;
    public:

        Collection():ptr(nullptr), ptr_size(0), ptr_capacity(0){
            ptr = new Object[0]{};
        };

        Collection(const Collection& other):ptr(nullptr), ptr_size(other.ptr_size), ptr_capacity(other.ptr_capacity){
            ptr = new Object[ptr_capacity]{};
            for(size_t i = 0; i < other.size(); i++){
                ptr[i] = other.ptr[i];
            }
        };

        ~Collection(){
            if(ptr!=nullptr){
                delete[] ptr;
                ptr = nullptr;
            }
            ptr_size = 0;
            ptr_capacity = 0;
        };

        Collection& operator=(const Collection& other){
            if(this != &other){
                delete[] ptr;
                ptr_size = other.ptr_size;
                ptr_capacity = other.ptr_capacity;

                ptr = new Object[ptr_capacity]{};
                for(size_t i = 0; i < other.size(); i++){
                    ptr[i] = other.ptr[i];
                }
            }

            return *this;
        };

        size_t size() const{ return this->ptr_size; }; // done


        bool is_empty() const {
            if(size() == 0 || ptr == nullptr){
                return true;
            }
            return false;
        }; // done


        void make_empty(){
            ptr_size = 0;
            ptr_capacity = 0;
            delete[] ptr;
            ptr = new Object[0]{};
        }; // done


        void insert(const Object& obj){
            cout << endl;
            cout << "INSERT " << obj << endl;

            ptr_size += 1;
            if(ptr_capacity == 0 || ptr == nullptr){
                cout << "BEEN HERE" << endl;
                ptr_capacity = 1;
                Object* new_ptr = new Object[ptr_capacity]{};
                new_ptr[ptr_capacity-1] = obj;

                delete[] ptr;
                ptr = nullptr;
                ptr = new_ptr;
                
            
            }

            else if(ptr_size > ptr_capacity){
                cout << "AND HERE" << endl;
                ptr_capacity *= 2;
                Object* new_ptr = new Object[ptr_capacity]{};
                for(size_t i = 0; i < size()-1; i++){
                    new_ptr[i] = ptr[i];
                }
                new_ptr[size()-1] = obj;

                delete[] ptr;
                ptr = nullptr;
                ptr = new_ptr;
            
            }
            else{
                ptr[size()-1] = obj;
            }

        };


        void remove(const Object& obj){
            size_t i = 0;
            size_t actual_i = 0;
            cout << endl;
            cout << "TO REMOVE " << obj << endl;

            size_t orig_size = size();
            Object* new_ptr = new Object[ptr_capacity]{};
            while(i < orig_size){
                if(ptr[i] == obj && actual_i >= i){
                    ptr_size -= 1;
                }
                else{
                    new_ptr[actual_i] = ptr[i];
                    actual_i++;
                }
                i++;

            }

            
            delete[] ptr;
            ptr = new_ptr;
        };


        bool contains(const Object& obj) const{
            cout << endl;
            cout << "CONTAINS " << obj << endl;
            if(ptr==nullptr || ptr_capacity == 0 || ptr_size == 0){
                return false;
            }
            for(size_t i = 0; i < ptr_size; i++){
                cout << ptr[i] << endl;
                if(ptr[i] == obj){
                    cout << "TRUE" << endl;
                    return true;
                }
            }
            return false;

        };

};


/*template <typename Object> size_t Collection<Object>::size() const{
     return this->ptr_size;
}


template <typename Object> void Collection<Object>::remove(const Object& obj){
    size_t remove_index = size() + 1;
    cout << "TO REMOVE " << obj << endl;
    for(size_t i = 0; i < size(); i++){
        cout << "PTR " << ptr[i] << " OBJ " << obj << endl;
        if(ptr[i] == obj){
            remove_index = i;
            ptr_size -= 1;
            break;
        }
    }

    Object* new_ptr = new Object[size()]{};
    size_t index = 0;
    while(index < size()){
        if(index != remove_index){
            new_ptr[index] = ptr[index];
        }
        index++;
    }

    ptr = new_ptr;
    delete[] new_ptr;

}
*/
