#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
    
};

int search(node* &head,int x)
{
    int pos=0;
    node* current=head;
    while(current!=NULL)
    {
        if(current->data==x)
        {
            return pos;
        }
        pos++;
        current=current->next;
    }
    return -1;
}

void addhead(node* &head,int data)
{
    node* n=new node(data);
    n->next=head;
    head=n;
}

void pushback(node* &head,int data)
{
    node* n=new node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* current=head;
    
    while(current->next != NULL)
    {
        current=current->next;
    }
    current->next=n;
}


void display(node* &head)
{
    node* current=head;
    while(current!=NULL)
    {
        cout<<current->data<<"\t";;
        current=current->next;
    }
    cout<<endl;
}


int main()
{

    node *LL1=NULL;
    addhead(LL1,0);
    pushback(LL1,10);
    pushback(LL1,20);
    pushback(LL1,50);
    pushback(LL1,90);
    
    display(LL1);
    cout<<search(LL1, 50)<<endl;
    
    
    
return 0;
}
