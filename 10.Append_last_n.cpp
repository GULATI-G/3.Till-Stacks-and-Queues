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

int length(node *head)
{
    if(head == NULL){return 0;}
    if(head->next==NULL){return 1;}
    int ans=length(head->next);
    return (ans+1);
}

node *appendlastNToFirst (node *head, int n)
{
    if(head==NULL){return head;}
    int len=length(head);
    node *temp=head;
    node *temp1=head;

    for(int i=1;i<len;i++)
    {
        temp1=temp1->next;
    }
    temp1->next=head;

    for(int i=1;i<(len-n);i++)
    {
        temp=temp->next;
    }
    head=temp->next;
    temp->next=NULL;
    
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
    int last_n;
    cout<<"enter number by ";
    cin>>last_n;
    head=appendlastNToFirst(head,last_n);
    print(head);

    return 0;
}