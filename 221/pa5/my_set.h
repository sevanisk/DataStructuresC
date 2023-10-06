#pragma once
#include binarysearchtree.h
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cstddef>

using namespace std;

// forward declarations
template <class T> class Set;
template <class T> class Set_const_iterator;
template <class T> class Set_iterator;

// TODO(student): implement this
template <class Comparable>
class Set_Node {
    friend class Set<Comparable>;
    friend class Set_const_iterator<Comparable>;
    friend class Set_iterator<Comparable>;

    // TODO(student): implement this
};

// TODO(student): implement this
template <class Comparable>
class Set_const_iterator {
    friend class Set<Comparable>;
    typedef Set_Node<Comparable> Node;

 public:
    virtual std::string to_string() const {
        // make a string that represents the state of the iterator
        //   e.g. "<Set::const_iterator -> [value]>"
        return "Set::const_iterator";
    }
};

// TODO(student): implement this
template <class Comparable>
class Set_iterator : public Set_const_iterator<Comparable> {
    friend class Set<Comparable>;
    typedef Set_Node<Comparable> Node;
    typedef Set_const_iterator<Comparable> const_iterator;

 public:
    std::string to_string() const override {
        // make a string that represents the state of the iterator
        //   e.g. "<Set::iterator -> [value]>"
        return "Set::iterator";
    }
};

// TODO(student): implement this
template <class Comparable>
class Set {
    typedef Set_Node<Comparable> node;
 public:
    typedef Set_const_iterator<Comparable> const_iterator;
    typedef Set_iterator<Comparable> iterator;
    Set(){

    }

    Set(const Set& obj){

    }

    ~Set(const Set& obj){

    }

    Set& operator=(const Set& obj){

    }

    iterator begin(){

    }

    const_iterator begin() const{

    }

    const iterator end() const{

    }

    bool is_empty() const{

    }

    size_t size() const{

    }

    void make_empty(){

    }

    std::pair<iterator,bool> insert(const Comparable&){

    }

    iterator insert(const_iterator, const Comparable&){

    }

    size_t remove(const Comparable&){

    }

    iterator remove(const_iterator){

    }

    bool contains(const Comparable&) const{

    }

    iterator find(const Comparable& key){

    }

    const_iterator find(const Comparable&) const{

    }

    void print_set(std::ostream&=std::cout) const{
        
    }
};

template <class Comparable>
std::ostream& operator<<(std::ostream& os, const Set_const_iterator<Comparable>& iter) {
    return os << iter.to_string();
}
