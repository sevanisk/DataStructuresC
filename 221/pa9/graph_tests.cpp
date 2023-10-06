#include "graph.h"
#include <cassert>
#include <cmath>
#include <cstddef>
#include <vector>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
//#include "vertex.h"
//#include "edge.h" 
using namespace std;

int main() {
    Graph g;
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(4);
    g.add_vertex(1);
    std::cout << g.vertex_count() << std::endl;
    std::cout << g.contains_vertex(1) << std::endl;
    g.add_edge(1, 2, 3.3);
    g.add_edge(1, 2, 4.0);
    std::cout << g.contains_edge(1, 2);
    std::cout << g.cost(1, 2);
    std::cout << g.cost(2, 3);
    std::cout << g.edge_count() << std::endl;
    g.remove_edge(1, 4);
    g.remove_vertex(4);
    Graph h = g;
    h.add_vertex(3);
    g = h;
    // TODO(student): write many organized and effective tests
    
    return 0;
}
