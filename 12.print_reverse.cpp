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
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data != -1)
    {
        node *n= new node(data);
        if(head==NULL)
        {head=n;}
        else
        {tail->next=n;}
        tail=n;
        cin >> data;
    }
    return head;
}

void printReverse (node *head)
{
    if(head==NULL){return;}
    if(head->next==NULL)
    {
        cout<<head->data<<" ";
        return;
    }
    printReverse(head->next);
    cout<<head->data<<" ";
    return;
}

void print(node *p)
{
    if(p==NULL){return;}
    cout<<p->data<<endl;
    if(p->next == NULL){return;}
    print(p->next);
}

int main()
{
    node *head=input();
    print(head);
    printReverse(head);

    return 0;
}