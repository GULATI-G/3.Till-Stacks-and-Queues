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

node *deleteNodeRec (node *head, int pos)
{
    if(head==NULL){return head;}
    if(pos==0)
    {
        node *p=head->next;
        delete head;
        return p;
    }
    node *x=deleteNodeRec(head->next,pos-1);
    head->next=x;
    return head;
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
    int pos;
    cout<<"enter index you want to delete ";
    cin>>pos;
    head=deleteNodeRec(head,pos);
    print(head);
    return 0;
}