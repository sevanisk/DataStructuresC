
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
    struct Node{
        bool active;
        Key v;
        Node(): active(false), v(Key()){
        }

        Node(const Key val): active(true), v(val){
        }
    };
private:
    float max_load;
    size_t hsize;
    vector<Node> htable;
public:
    HashTable(): max_load(0.5), hsize(0), htable(11){
        max_load = 0.5;
    }
    explicit HashTable(size_t sz): max_load(0.5), hsize(0), htable(sz){
        max_load = 0.5;

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

    size_t table_size() const{
        return htable.size();
    }

    void make_empty(){
        for(size_t i = 0; i < htable.size(); i++){
            htable[i].active = false;
        }
        hsize = 0;
    }

    bool insert(const Key& value){
        if(contains(value)){
            return false;
        }

        size_t index = position(value);

        htable[index].v = value;
        htable[index].active = true;
        hsize++;

        if(load_factor() >= max_load_factor()){
            rehash(bucket_count());
        }
        return true;
    }

    size_t remove(const Key& value){
        if(!contains(value)){
            return 0;
        }
        size_t index = position(value);
        htable[index].active = false;
        hsize--;
        return 1;
    }

    bool contains(const Key& value) const{
        for (Node v2 : htable){
            if(v2.active && v2.v == value){
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

    size_t position(const Key& value) const{
        size_t val = Hash{}(value) % htable.size();
        size_t i = 0;
        while((htable[val].active || htable[val].v != Key()) && htable[val].v != value){
            i++;
            val = ((Hash{}(value)) + i) % htable.size();
        }
        return val;
    }

    size_t rehash_position(const Key& value, size_t newsize) const{
        size_t val = Hash{}(value) % newsize;
        size_t i = 0;
        while(htable[i].active){
            val = (Hash{}(value) + i) % newsize;
            i++;
        }
        return val;
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
            rehash(hsize/max_load + 1);
        }
    }

    void rehash(size_t newsize){
        vector<Node> htable2(newsize);
        for(size_t i = 0; i < htable.size(); i++){
            if(htable[i].active){
                size_t index = rehash_position(htable[i].v, newsize);
                htable2[index].v = htable[i].v;
                htable2[index].active = true;
            }
        }

        htable = htable2;
    }

    void print_table(std::ostream& os = std::cout) const{
        if(hsize == 0){
            os << "<empty>\n";
        }
        for(size_t i = 0; i < htable.size(); i++){
            if(htable[i].active){
                os << i << ": ";
                os << htable[i].v << endl;
            }
        }
    }
};
