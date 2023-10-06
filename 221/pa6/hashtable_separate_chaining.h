
#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include<functional>
#include <list>
#include<stdexcept>

using namespace std;
template <class Key, class Hash=std::hash<Key>>
class HashTable {
private:
    float max_load;
    size_t hsize;
    vector<list<Key>> htable;
public:
    HashTable(): max_load(1), hsize(0), htable(11){
        max_load = 1;
    }
    explicit HashTable(size_t sz): max_load(1), hsize(0), htable(sz){

    }
    bool is_empty() const{
        if(hsize==0){
            return true;
        }
        return false;
    }

    size_t size() const{
        return hsize;
    }

    void make_empty(){
        for(size_t i = 0; i < htable.size(); i++){
            for(size_t j = 0; j < htable[i].size(); j++){
                htable[i].pop_back();
            }
        }
        hsize = 0;
    }

    bool insert(const Key& value){
        size_t index = bucket(value);

        if(contains(value)){
            return false;
        }

        htable[index].push_back(value);
        hsize++;

        if(load_factor() > max_load_factor()){
            rehash(bucket_count());
        }

        return true;
    }

    size_t remove(const Key& value){
        size_t index = bucket(value);
        if(!contains(value)){
            return 0;
        }
        htable[index].remove(value);
        hsize--;
        return 1;
    }

    bool contains(const Key& value) const{
        size_t index = bucket(value);
        for (Key v : htable[index]){
            if(v == value){
                return true;
            }
        }
        return false;
    }


    bool is_prime(size_t num) const{
        for(size_t i = 2; i < num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    size_t bucket_count() const{
        size_t b = htable.size();
        if(load_factor() > max_load){
            b *= 2;
            while(!is_prime(b)){
                b++;
            }
        }
        return b;
    }

    size_t bucket_size(size_t index) const{
        if(index > htable.size()-1){
            throw out_of_range("no");
        }
        return htable[index].size();
    }


    size_t bucket(const Key& value) const{
        return Hash{}(value) % bucket_count();
    }

    float load_factor() const{
        float value = ((float)hsize / (float)htable.size());
        return value;

    }

    float max_load_factor() const{
        return max_load;
    }

    void max_load_factor(float val){
        if(val <= 0){
            throw invalid_argument("no");
        }

        max_load = val;
        if(load_factor() >= max_load){
            rehash(bucket_count());
        }
    }

    void rehash(size_t newsize){
        //cout << "REHASH" << endl;
        vector<list<Key>> htable2(newsize);
        for(size_t i = 0; i < htable.size(); i++){
            for(Key v : htable[i]){
                size_t index = Hash{}(v)%newsize;
                htable2[index].push_back(v);
            }
        }

        htable = htable2;
    }

    void print_table(std::ostream& os = std::cout) const{
        if(hsize == 0){
            os << "<empty>\n";
        }
        else {
            for(size_t i = 0; i < htable.size(); i++){
                if(htable[i].size() != 0){
                    os << i << ": ";
                    for (Key v : htable[i]){
                        os << v << " ; ";
                    }
                    os << endl;
                }
            }
        }

    }
};
