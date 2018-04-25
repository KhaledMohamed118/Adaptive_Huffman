#include <bits/stdc++.h>

using namespace std;

#ifndef TREE_H
#define TREE_H

class Tree
{
    public:
        Tree(int);
        Node* getroot();
        string added_before(char);
        string new_add(char);

    private:
        Node *root;
};

#endif // TREE_H
