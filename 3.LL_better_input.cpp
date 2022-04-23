#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        next = NULL;
    }
};

node* input()
{
    // we will be returning only the head of the LL
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data != -1)
    {
        // node n(data);
        // we can't make the nodes statically as the scope of node n will be only within while loop brackets. Once we move out of the
        // loop, our node will be lost. We know that if we create anything dynamically, it is there until we ourselves delete it.
        node *n= new node(data);
        if(head==NULL)
        {head=n;}
        else
        {
            tail->next=n;
            // to avoid time complexity of n^2 let's see another method
            // node *temp=head;
            // while(temp->next!=NULL)
            //     {temp=temp->next;}
            // temp->next=n;
        }
        tail=n;
        cin >> data;
    }
    //complexity is O(n)
    return head;
}

void print(node *p)
{
    
    cout<<p->data<<endl;
    if(p->next == NULL){return;}
    print(p->next);   
}

int main()
{
    node *head=input();
    print(head);

    return 0;
}