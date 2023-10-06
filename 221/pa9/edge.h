#pragma once
#include <cassert>
#include <cmath>
#include <cstddef>
#include <vector>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include "vertex.h"
using namespace std;


class Edge{
public:
    Vertex target;
    double weight;
    Edge(Vertex t, double w): target(t), weight(w){

    }

};
