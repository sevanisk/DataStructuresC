#include <vector>
#include <iostream>
#include <sstream>
#include<functional>
#include <list>
#include<stdexcept>
#include "hashtable_separate_chaining.h"
using namespace std;

int main() {
    // TODO(student): write at least 1000 lines of test
    HashTable<string> table(11);
    cout << "hi" << endl;
    //cout << table.is_empty() << endl;
    //cout << table.bucket_count() << endl;
    table.insert("And them who hold High Places");
    table.insert("Must be the ones to start");
    table.insert("To mold a new Reality");
    table.insert("Closer to the Heart");
    table.insert("The Blacksmith and the Artist");
    table.insert("Reflect it in their Art");
    table.insert("Forge their Creativity");
    table.insert("Closer to the Heart");
    table.insert("Philosophers and Plowmen");
    table.insert("Each must know their Part");
    table.insert("To sow a new Mentality");
    table.insert("Closer to the Heart");
    table.insert("You can be the Captain");
    table.insert("I will draw the Chart");
    table.insert("Sailing into Destiny");
    table.insert("Closer to the Heart");

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    std::cout << "print the table" << std::endl;
    std::stringstream ss;
    table.print_table(ss);
    std::cout << ss.str() << std::endl;

    table.remove("Philosophers and Plowmen");
    table.remove("Each must know their Part");

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    cout << table.bucket_count() << endl;
    
    return 0;
}
