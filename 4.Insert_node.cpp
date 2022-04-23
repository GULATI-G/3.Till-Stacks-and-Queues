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

void insert_node(node *&head, int data, int pos) // passed head by refernce for the 0 position case. else return head
{
    node *p=new node(data);
    node *temp=head;
    if (pos==0)
    {
        p->next=head;
        head=p;
        return;
    }

    for(int i=1;i<pos;i++)
    {
        if(temp==NULL){break;}
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        p->next=temp->next;
        temp->next=p;
    }
    return;
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
    int data;
    cout<<"Enter data "; 
    cin>>data;
    int pos;
    cout<<"Enter pos ";
    cin>>pos;
    insert_node(head,data,pos);
    print(head);
    return 0;
}