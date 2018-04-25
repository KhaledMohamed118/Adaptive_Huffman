#include <bits/stdc++.h>
#include <node.h>
#include <tree.h>

using namespace std;

Tree::Tree(int mm)
{
    root = new Node(1, mm, '-', nullptr);
}

Node* Tree::getroot(){
    return root;
}

string Tree::added_before(char cha){//BFS
    queue <pair<Node* , string>> q;
    q.push({root , ""});
    pair<Node* , string> t;

    while(!q.empty()){
        t = q.front();
        q.pop();

        if(t.first->get_l()){//if it is internal node
            q.push({t.first->get_l() , t.second + '0'});
            q.push({t.first->get_r() , t.second + '1'});
        }

        else if(t.first->get_char() == cha){//if it is external node and it is the desired node
                t.first->increase_wight();//increase rhe node itself

                Node *tt = t.first->get_parent();

                while(tt){
                    if(tt->get_l()->get_weight() > tt->get_r()->get_weight())//swap if needed
                        tt->swap_childs();
                    tt->increase_wight();//increase parent
                    tt = tt->get_parent();
                }

                return t.second;//return the path to the desired node before updating
        }

    }
    return "";
}

string Tree::new_add(char cha){//BFS
    queue <pair<Node* , string>> q;
    q.push({root , ""});
    pair<Node* , string> t;

    while(!q.empty()){
        t = q.front();
        q.pop();

        if(t.first->get_l()){//if it is internal node
            q.push({t.first->get_l() , t.second + '0'});
            q.push({t.first->get_r() , t.second + '1'});
        }

        else if(t.first->is_nyt()){//if it is external node and it is the NYT node
                t.first->make_internal(cha , t.first);//add the new node and the new NYT node

                Node *tt = t.first;

                while(tt){
                    if(tt->get_l()->get_weight() > tt->get_r()->get_weight())//swap if needed
                        tt->swap_childs();
                    tt->increase_wight();//increase parent
                    tt = tt->get_parent();
                }

                return t.second;//return the path to the NYT node before updating
        }

    }
    return "";
}
