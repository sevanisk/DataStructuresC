#pragma once
#include <cassert>
#include <cmath>
#include <cstddef>
#include <vector>
#include <iostream>
#include <list>
#include <sstream>
#include <unordered_map>

using namespace std;

class Graph {
    public:
        // vertex id, map of <adjacent vertex, weight to that vertex>
        unordered_map<size_t, unordered_map<size_t, double>> g;
        size_t v_num;
        size_t e_num;
        Graph(): g({}), v_num(0), e_num(0){ }

        Graph(const Graph& obj): g(obj.g), v_num(obj.v_num), e_num(obj.e_num){ }

        Graph& operator=(const Graph& obj){
            g = obj.g;
            v_num = obj.v_num;
            e_num = obj.e_num;
            return *this;
        }

        ~Graph(){
            v_num = 0;
            e_num = 0;
            g.clear();
        }

        size_t vertex_count() const{
            return v_num;
        }

        size_t edge_count() const{
            return e_num;
        }

        bool contains_vertex(size_t id) const{
            if(g.find(id) != g.end()){
                return true;
            }
            return false;
        }

        bool contains_edge(size_t u, size_t v) const{
            if(contains_vertex(u) && contains_vertex(v)){
                if(g.at(u).find(v) != g.at(u).end()){
                    return true;
                }
            }
            return false;
        }

        double cost(size_t u, size_t v) const{
            if(!contains_edge(u, v)){
                return INFINITY;
            }
            return g.at(u).at(v);
        }

        bool add_vertex(size_t id){
            if(contains_vertex(id)){
                return false;
            }
            v_num++;
            g.insert({id,{}});
            return true;
        }

        bool add_edge(size_t u, size_t v, double weight=1){
            if(!contains_vertex(u) || !contains_vertex(v) || contains_edge(u, v)){
                return false;
            }
            e_num++;
            g[u].insert({v, weight});
            return true;
        }

        bool remove_edge(size_t u, size_t v){
            if(!contains_edge(u , v)){
                return false;
            }
            g[u].erase(v);
            e_num--;
            return true;
        }

        bool remove_vertex(size_t id){
            if(!contains_vertex(id)){
                return false;
            }
            g.erase(id);

            unordered_map<size_t, unordered_map<size_t, double>>::iterator it;
            for(it = g.begin(); it != g.end(); it++){
                if(contains_edge(it->first, id)){
                    remove_edge(it->first, id);
                }
            }
            v_num--;
            return true;
        }

        void dijkstra(size_t source_id){
            if(!contains_vertex(source_id)){
                return;
            }
            
            cout << "hi2" << source_id << endl;
        }

        double distance(size_t id) const{
            if(!contains_vertex(id)){
                return INFINITY;
            }
            cout << "hi" << id << endl;
            return 0.0;
        }

        void print_shortest_path(size_t dest_id, std::ostream& os=std::cout) const{
            if(!contains_vertex(dest_id)){
                os << "<no path>\n";
            }
            else{
                os << "hi" << dest_id;
            }
        }

};
