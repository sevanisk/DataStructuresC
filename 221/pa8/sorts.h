#pragma once
#include <vector>
#include <iostream>
#include<functional>
#include <utility>

using namespace std;
// Pretty printing for vectors of Printable objects (have ostream operator<< defined)
// Be careful: modifications risk failing tests
template <class Printable>
std::ostream& operator<<(std::ostream& os, const std::vector<Printable>& container) {
    os << "[";
    bool first = false;
    for (const Printable& t : container) {
        if (first) {
            os << ", ";
        }
        if (typeid(t) == typeid(std::string)) {
            os << "\"" << t << "\"";
        } else {
            os << t;
        }
        first = true;
    }
    os << "]";
    return os;
}

template <class Comparable>
void swap(vector<Comparable>& c, size_t a, size_t b){
    Comparable t = c[a];
    c[a] = c[b];
    c[b] = t;
}


template <class Comparable>
size_t find_pivot(vector<Comparable>& c, size_t first, size_t last){
    Comparable f = c[first];
    Comparable l = c[last];
    Comparable mid = c[last/2];
    size_t partition_index = 0;
    if((f > l && f < mid) || (f < l && f > mid)){
        partition_index = first;
    }else if((l > f && l < mid) || (l < f && l > mid)){
        partition_index = last;
    }
    else{
        partition_index = last/2;
    }
    return partition_index;
}

template <class Comparable>
size_t rearrange(vector<Comparable>& c, size_t pivotpt, size_t first, size_t last)
{
    size_t i = last;
    Comparable pivot = c[pivotpt];
    swap(c, last, pivotpt); 
    last--;
    while(true){
        while(c[first] < pivot){
            first++;
        }
        while(c[last] > pivot){
            last--;
        }
        if(first < last){
            swap(c, first, last);
        }
        else{
            break;
    }
  }
  swap(c, last+1, i);  // swap pivot with element at indexOfPivot
  return last+1;
}



// Selection sort (example of implementation expectations)
template <class Comparable>
void selection_sort(std::vector<Comparable>& container) {
    // print the initial container
    cout << container << endl;

    if (container.empty()) {
        return;
    }

    for (size_t index = 0; index < container.size()-1; index++) {
        // do 1 pass of selection sort: find the min and swap it to the front
        size_t index_min = index;
        for (size_t i = index+1; i < container.size(); i++) {
            if (container[i] < container[index_min]) {
                index_min = i;
            }
        }
        Comparable t = container[index];
        container[index] = container[index_min];
        container[index_min] = t;

        // print the container after each pass
        std::cout << container << std::endl;
    }
}

template <class Comparable>
void insertion_sort(vector<Comparable>& container){
    cout << container << endl;
    for(size_t i = 1; i < container.size(); i++){
        size_t index = i;
        while(index > 0 && container[index-1] > container[index]){
            swap(container, index, index-1);
            //decrement
            index--;
        }
        cout << container << endl;
    }

}

size_t find_hibbards(size_t sz){
    size_t curr = 1;
    while((curr*2 + 1) < sz){
        curr = curr*2 + 1;
    }
    if (sz == 0){
        return 0;
    }
    return curr;
}


template <class Comparable>
void shell_sort(vector<Comparable>& container){
    size_t increment = find_hibbards(container.size());
    size_t n = container.size();
    while(increment >= 1){
        cout << container << endl;
        for(size_t i = increment; i < n; i++){
            Comparable temp = container[i];
            size_t j = i;
            while(j >= increment && container[j-increment] > temp){
                container[j] = container[j-increment];
                j-= increment;
            }
            container[j] = temp;
        }
        increment = (increment / 2);
    }
    cout << container << endl;
}

template <class Comparable>
void heap_sort(vector<Comparable>& container){
    if(container.size() == 0){
        cout << container << endl;
        return;
    }
}


template <class Comparable>
void merge(vector<Comparable>& c, size_t& start, size_t& end){
    vector<Comparable> m;
    size_t mid = (start+end)/2;
    size_t s_l = start;
    size_t s_r = (mid) + 1;
    while(s_l <= mid && s_r<= end){
        if(c[s_l] <= c[s_r]){ 
            m.push_back(c[s_l]);
            s_l++;
        }
        else{
            m.push_back(c[s_r]);
            s_r++;
        }
    }

    while(s_l <= mid){
        m.push_back(c[s_l]);
        s_l++;
    }

    while(s_r <= end){
        m.push_back(c[s_r]);
        s_r++;
    }

    for(size_t a = start; a <= end; a++){
        c[a] = m[a-start];
    }
}


template <class Comparable>
void merge_sort(vector<Comparable>& container, size_t start, size_t end){
    if(start < end){
        size_t median = (start + end) / 2;
        merge_sort(container, start, median);
        merge_sort(container, median+1, end);
        merge(container, start, end);
        cout << container << endl;
    }
}

template <class Comparable>
void merge_sort(vector<Comparable>& container){
    cout << container << endl;
    if(container.size() < 2){
        return;
    }
    merge_sort(container, 0, container.size()-1);
}


template<class Comparable>
bool is_sorted(vector<Comparable>& c){
    for(size_t i = 0; i < c.size()-1; i++){
        if(c[i] > c[i+1]){
            return false;
        }
    }
    return true;
}

template <class Comparable>
void insertion_sort_2(vector<Comparable>& container){
    for(size_t i = 1; i < container.size(); i++){
        size_t index = i;
        while(index > 0 && container[index-1] > container[index]){
            swap(container, index, index-1);
            //decrement
            index--;
        }
        cout << container << endl;
    }

}


template <class Comparable>
void helper(vector<Comparable>& container, size_t first, size_t last){
    if(first + 10 < last){
        // find pivot
        size_t pivotpt = find_pivot(container, first, last);
        pivotpt = rearrange(container, pivotpt, first, last);
        // sort left side
        cout << container << endl;
        helper(container, first, pivotpt-1); 
        // sort right side
        helper(container, pivotpt+1, last);
    }
    else if(!is_sorted(container)){
        cout <<  container << endl;
        insertion_sort_2(container);
    }

}

template <class Comparable>
void quick_sort(vector<Comparable>& container){
    cout << container << endl;
    if(container.size() < 2){
        return;
    }
    helper(container, 0, container.size()-1);
}



void bucket_sort(std::vector<unsigned int>& container){
    cout << container << endl;
    size_t mx = container[0];
    for(size_t i = 0; i < container.size(); i++){
        if(container[i] > mx){
            mx = container[i];
        }
    }
    mx = mx+1;

    vector<size_t> ct(mx, 0);
    for(auto i : container){
        ct[i]++;
    }
    cout << ct << endl;

    container.clear();
    for(size_t n = 0; n < mx; n++){
        for(size_t apps = 0; apps < ct[n]; apps++){
            container.push_back(n);
        }

        if(ct[n] > 0){
            cout << container << endl;
        }
    }



}

template <class Comparable>
void radix_sort(vector<Comparable>& container){
    if(container.size() == 0){
        cout << container << endl;
        return;
    }
    /*Comparable b = container[0];
    for(size_t i = 1; i < container.size(); i++){
        if(container[i] > b){
            b = container[]
        }
    }
    vector<list<Comparable>> buckets(b);*/

}
