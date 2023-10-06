#pragma once
#include <iostream>
#include <stdexcept>
#include <cstddef>

using std::cout, std::endl, std::invalid_argument;

template <typename Comparable> 
class RedBlackTree{
public: 
    enum Color {RED, BLACK};

    class Node{
    public:
        enum Color {RED, BLACK};
        Comparable value;
        Node* left;
        Node* right;
        int color;

        Node(): left(nullptr), right(nullptr){
        }

        Node(Comparable val): value(val), left(nullptr), right(nullptr), color(1){

        }

    };
    private:
        Node* root;

    public:
      RedBlackTree(): root(nullptr){
      }

     ~RedBlackTree(){
         while(root!= nullptr){
             remove(root->value);
         }
     }

     RedBlackTree(const RedBlackTree& other): root(nullptr){
         root = nullptr;
         //copy(other.root);
     }

     void copy(Node* n2){
         if(n2){
             insert(n2->value);
             copy(n2->left);
             copy(n2->right);
         }

     }

     RedBlackTree& operator=(const RedBlackTree& other){
         if(this != &other){
             root = nullptr;
             copy(other.root);
         }
         return *this;
     }

     bool contains(const Comparable& other) const{
         return contains(other, root);
     }

     bool contains(const Comparable& other, Node* rot) const{
         if(rot == nullptr){
             return false;
         }

         else if(rot->value == other){
             return true;
         }

         else if(other < rot->value){
             return contains(other, rot->left);
         }
         else{
             return contains(other, rot->right);
         }

     }

    void remove(const Comparable& other){
        if(root == nullptr || !contains(other)){
            return;
        }
        else if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else{
            remove(other, root, nullptr);      
        }   
    }

    Node* find_smallest(Node* rot2){
        if(rot2->left != nullptr){
            return find_smallest(rot2->left);
        }
        return rot2;

    }


    void remove(const Comparable& other, Node* rot, Node* old){
        if(rot == nullptr){
            return;
        }
        else if(other < rot->value){
            remove(other, rot->left, rot);
        }
        else if(other > rot->value){
            remove(other, rot->right, rot);
        }
        // 2 children
        else if(rot->right != nullptr && rot->left != nullptr){
            rot->value = find_smallest(rot->right)->value;
            remove(rot->value, rot->right, rot);
        }
        // no children
        else if(rot->right == nullptr && rot->left == nullptr){
            if(old != nullptr){
                if(old->left == rot){
                    old->left = nullptr;
                }
                else if(old->right == rot){
                    old->right = nullptr;
                }
            }
            delete rot;
        }
        // 1 child
        else{
            if(old == nullptr){
                if(rot->left == nullptr){
                    root = rot->right;
                }
                else{
                    root = rot->left;
                }

            }
            else if(old->right == rot){
                if(rot->left != nullptr){
                    old->right = rot->left;
                }
                else{
                    old->right = rot->right;
                }
            }

            else if(old->left == rot){
                if(rot->left != nullptr){
                    old->left = rot->left;
                }
                else{
                    old->left = rot->right;
                }
            }
            delete rot;
            
        }
    }

        void insert(const Comparable& other){
            if(root == nullptr){
                root = new Node(other);
            }
            else{
                insert(other, root);      
            }   
        }

        void insert(const Comparable& other, Node* rot){
            if(other > rot->value){
                if(rot->right == nullptr){
                    rot->right = new Node(other);
                }
                else{
                    insert(other, rot->right);
                }
            }
            else if(other < rot->value){
                if(rot->left == nullptr){
                    rot->left = new Node(other);
                }
                else{
                    insert(other, rot->left);
                }
            }   
        }

        const Comparable& find_min() const{
            if(root == nullptr){
                throw invalid_argument("empty");
            }
            return find_min(root);
        }

        const Comparable& find_min(Node* rot) const{
            if(rot->left == nullptr){
                return rot->value;
            }
            return find_min(rot->left);
        }


        const Comparable& find_max() const{
            if(root == nullptr){
                throw invalid_argument("empty");
            }
            return find_max(root);
        }

        const Comparable& find_max(Node* rot) const{
            if(rot->right == nullptr){
                return rot->value;
            }

            return find_max(rot->right);
        }
        void print_tree(std::ostream& os=cout) const{
            if(root == nullptr){
                os << "<empty>\n";
            }
            else{
                print_tree(os, 0, root);
            }   
        }

        void print_tree(std::ostream& os, int depth, Node* rot) const{
            if(rot->right != nullptr) {
                print_tree(os, depth + 1, rot->right);
            }
            for(int i = 0; i < depth; i++){
                os << "  ";
            }
            os << rot->value << endl;
            if(rot->left != nullptr){
                print_tree(os, depth + 1, rot->left);
            }
        }

        const Node* get_root() const{
            return root;
        }

        int color(const Node* node) const{
            if(node == nullptr){
                return BLACK;
            }
            return node->color;
        }
   };
