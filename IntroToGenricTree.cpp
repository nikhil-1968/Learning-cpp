#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    vector<node*> children;
    node(int val)
    {
        data=val;
    }
};
void printTree(node* root)
{
    cout<< root->data<<": ";
    for(int i=0 ;i < root->children.size(); i++)
    {
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i=0 ;i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
node* takeInput(){
    cout<<"Enter data";
    int data;cin>>data;
    node* root=new node(data);
    cout<<"Enter Number of children";
    int num;cin>>num;
    for(int i=0;i<num;i++)
    {
        node* child=takeInput();
        root->children.push_back(child);
    }
    return root;
};
int main(){
    
   node* root= takeInput();
    printTree(root);
    
return 0;
}