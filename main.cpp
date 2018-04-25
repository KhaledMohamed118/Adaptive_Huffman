#include <bits/stdc++.h>
#include <node.h>
#include <tree.h>

using namespace std;

map <char , int> k;
map <int , char> k2;
map <char , bool> seen;
vector <string> input , output;
string choice , s;
int n = 0 , m , e , r;
ifstream inFile;

string toBinary(int num , int bits){//convert decimal value to binary value of specified number of bits
    string str = "";
    while(bits--){
            str = (num&1 ? "1" : "0") + str;
            num/=2;
    }
    return str;
}


void encode(Tree &tre){
    for(int i = 0 ; i < (int)input.size() ; i++){
        for(int j = 0 ; j < (int)input[i].size() ; j++){
            if(input[i][j] == ' ')
                output.push_back(" ");
            else if(seen[input[i][j]])//if appeared before
                output.push_back(tre.added_before(input[i][j]));
            else{//if it is the first time to appear
                seen[input[i][j]] = 1;
                if(k[input[i][j]] <= 2*r)
                    output.push_back(tre.new_add(input[i][j]) + toBinary(k[input[i][j]] - 1, e+1));
                else
                    output.push_back(tre.new_add(input[i][j]) + toBinary(k[input[i][j]] - r - 1, e));
            }
        }
        output.push_back("\n");
    }
}

void decode(Tree &tre){
    Node *nod;
    int val;
    for(int i = 0 ; i < (int)input.size() ; i++){
        val = 0;
        nod = tre.getroot();
        for(int j = 0 ; j < (int)input[i].size() ; j++){
            if(!i && !j){   //if it is the first character
                for(int k = 0 ; k < e ; k++){// read e bits
                    val <<= 1;
                    val += input[i][j++] - '0';
                }

                if(val < r){    //read another bit (e+1) and add 1 to the value
                    val <<= 1;
                    val += input[i][j++] - '0';
                    val++;
                }

                else{   //still e bits and add (r+1) to the value
                    val += r + 1;
                }

                //getting the character of that index and adding it to the output and tree
                s = "";
                s += k2[val];
                output.push_back(s);
                tre.new_add(k2[val]);
                nod = tre.getroot();
                j--;
            }

            else if(input[i][j] == ' '){
                output.push_back(" ");
            }

            else{//tracing the tree  according to the input file
                if(input[i][j] == '1')
                    nod = nod->get_r();
                else
                    nod = nod->get_l();

                if(nod->is_nyt()){//the first time that character appear
                    val = 0;
                    for(int k = 0 ; k < e ; k++){   // read e bits
                        val <<= 1;
                        val += input[i][++j] - '0';
                    }

                    if(val < r){    //read another bit (e+1) and add 1 to the value
                        val <<= 1;
                        val += input[i][++j] - '0';
                        val++;
                    }

                    else{   //still e bits and add (r+1) to the value
                        val += r + 1;
                    }

                    //getting the character of that index and adding it to the output and the tree
                    s = "";
                    s += k2[val];
                    output.push_back(s);
                    tre.new_add(k2[val]);
                    nod = tre.getroot();
                }

                else if(nod->is_external()){    //that character appeared before
                    //getting the character of that node and adding it to the output and increment it in the tree
                    s = "";
                    s += nod->get_char();
                    output.push_back(s);
                    tre.added_before(nod->get_char());
                    nod = tre.getroot();
                }
            }
        }
        output.push_back("\n");
    }
}


int main()
{
    //determine the choice of user
    cout<<"What do you want ?\n\t1-Encode\n\t2-decode\n";
    cin>>choice;
    while(choice != "1" && choice != "2"){
        cout<<"Invalid Choice\n";
        cout<<"What do you want ?\n\t1-Encode\n\t2-decode\n";
        cin>>choice;
    }

    //reading the set
    inFile.open("set.txt");
    while(getline(inFile , s)){
        for(int i = 0 ; i < (int)s.size() ; i++){
            if(k[s[i]])
                continue;
            k[s[i]] = ++n;
            k2[n]  = s[i];
        }
    }
    inFile.close();


    //k[' '] = ++n;

    //for(auto it : k)
    //    cout<<it.ff<<" "<<it.ss<<ndl;


    //reading the input
    inFile.open("input.txt");
    while(getline(inFile , s))
        input.push_back(s);
    inFile.close();

    //foor(i,0,sz(input[0]))
    //    cout<<i+1<<" "<<input[0][i]<<ndl;

    //for(auto it : input)
    //    cout<<it<<ndl;

    //calculate m,e,r
    m = 2*n - 1;
    while((1<<(e+1)) <= n)
          e++;
    r = n - (1<<e);

    Tree MyTree(m);

    freopen("output.txt", "w", stdout);

    if(choice == "1"){
        encode(MyTree);
        for(int i = 0 ; i < (int)output.size() ; i++)
            cout<<output[i];
    }
    else{
        decode(MyTree);
        for(int i = 0 ; i < (int)output.size() ; i++)
            cout<<output[i];
    }

    return 0;
}
