#include <bits/stdc++.h>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node
{
    public:

        Node(bool, int, char, Node*);
        void increase_wight();
        char get_char();
        int get_idx();
        int get_weight();
        bool is_nyt();
        bool is_external();
        Node* get_r();
        Node* get_l();
        Node* get_parent();
        void swap_childs();
        void make_internal(char, Node*);

    private:
        bool isnyt;
        int idx , weight;
        char ch;
        Node *r , *l , *parent;
};

#endif // NODE_H
