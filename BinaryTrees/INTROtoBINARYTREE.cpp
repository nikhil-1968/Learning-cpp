//TREE
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>		vi;
class node{
    public:
    node *left;
    node *right;
    int data;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
    ~node()
    {
        delete left;
        delete right;
    }
}; 
void printTree(node* root)
{
    if(root==NULL) 
    return;
    cout<<root->data<<": ";
    if(root->left!=NULL){cout<<"L"<<root->left->data<<" ";}
    if(root->right!=NULL){cout<<"R"<<root->right->data<<" ";}
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}
node* takeInput()
{
    int data;
    cout<<"Enter Data";
    cin>>data;
    if(data== -1)
    {
        return NULL;
    }
    node* root=new node(data);
    root->left=takeInput();
    root->right=takeInput();

    return root;
    
}
void preorder(node* root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node* takeInputLevelWise()
{
    int data;
    cout<<"\nEnter Root Data ";
    cin>>data;
    if(data== -1)
    {
        return NULL;
    }
    node* root=new node(data);
    queue<node*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0)
    {
        node* front = pendingNode.front();
        pendingNode.pop();
//FOR LEFT NODE
        cout<<"\nEnter Left data of "<<front->data;
        int leftchild;
        cin>>leftchild;
        if(leftchild != -1)
        {
            front->left=new node(leftchild);
            pendingNode.push(front->left);
        }
        
//SAME FOR RIGHT Cright
        cout<<"\nEnter right data of "<<front->data;
        int rightchild;
        cin>>rightchild;
        if(rightchild != -1)
        {
            front->right=new node(rightchild);
            pendingNode.push(front->right);
        }
    }
//Returning Root;
    return root;
}
void printTreeLevelWise(node* root){
    if(root==NULL) 
    return;
    queue<node*> pendingNode;
    pendingNode.push(root);
     while(pendingNode.size()!=0)
    {
        node* front = pendingNode.front();
        pendingNode.pop();
        cout<<endl<<front->data<<" : ";
        if(front->left!=NULL)
        {
            cout<<"L"<<front->left->data<<" ";
            pendingNode.push(front->left);
        }
        if(front->right!=NULL)
        {
            cout<<"R"<<front->right->data<<" ";
            pendingNode.push(front->right);
        }
    }  

}
int countNodes(node* root)
{
    if(root==NULL)  {return 0;}
    return 1+countNodes(root->left)+countNodes(root->right);
}
int search(int in[],int st ,int end,int curr){
    while(st<=end)
    {
        if(in[st]==curr)
        {return st;}
        st++;
    }
    return -1;//CASE will not come
}
node* buildtreeformPreAndInorder(int pre[],int in[],int st,int end)
{
    static int idx=0;
    if(st> end){return NULL;}//Base case-1
    int curr=pre[idx];
    idx++;
    node* root=new node(curr);
    if(st==end){return root;}//Base case-1
    int pos=search(in,st,end,curr);
    root->left = buildtreeformPreAndInorder(pre,in,st,pos-1);
    root->right=buildtreeformPreAndInorder(pre,in,pos+1,end);
    return root;

}
int heightOfTree(node* root)
{
    if(root==NULL){return 0;}
    return 1+max(heightOfTree(root->left),heightOfTree(root->right));
}
int main(){
int preorder[]={1, 2, 4, 5, 3, 6, 7};
int inorder[]={4,2,5,1,6,3,7};
node* root = buildtreeformPreAndInorder(preorder,inorder,0,6);
printTreeLevelWise(root);
cout<<"\nheightOfTree "<<heightOfTree(root)<<endl;
return 0;
}  