#pragma once
#include <cassert>
#include <cmath>
#include <cstddef>
#include <vector>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include "edge.h"
using namespace std;

class Vertex{
public:
    size_t id;
    list<Edge> adjacencies;
    Vertex(size_t i): id(i){
        adjacencies = new list<Edge>();
    }
};