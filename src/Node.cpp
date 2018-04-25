#include <bits/stdc++.h>
#include <node.h>
#include <tree.h>

using namespace std;

Node::Node(bool ny, int id, char cha, Node* par)
{
    isnyt = ny;
    idx = id;
    weight = !ny;
    ch = cha;
    r = l = nullptr;
    parent = par;
}

void Node::increase_wight(){
    weight++;
}

char Node::get_char(){
    return ch;
}

int Node::get_idx(){
    return idx;
}

int Node::get_weight(){
    return weight;
}

bool Node::is_nyt(){
    return isnyt;
}

bool Node::is_external(){
    return (this->l == nullptr);
}

Node* Node::get_r(){
    return r;
}

Node* Node::get_l(){
    return l;
}

Node* Node::get_parent(){
    return parent;
}

void Node::swap_childs(){
    Node *ll = l , *rr = r;
    r = ll;
    l = rr;
}

void Node::make_internal(char cha , Node *cur){
    isnyt = 0;
    l = new Node(1, get_idx() - 2, '-', cur);
    r = new Node(0, get_idx() - 1, cha, cur);
}
