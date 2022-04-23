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

node *delete_node(node *head,int pos)
{
    if (pos==0)
    {
        node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    node *temp=head;
    for(int i=1;i<pos;i++)
    {
        if(temp->next==NULL){return head;}
        temp=temp->next;
    }
    if(temp->next==NULL){return head;}
    node *node_we_want_to_delete=temp->next;
    temp->next=node_we_want_to_delete->next;
    delete node_we_want_to_delete;
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
    // int data;
    // cout<<"Enter data "; 
    // cin>>data;
    // int pos;
    // cout<<"Enter pos ";
    // cin>>pos;
    // insert_node(head,data,pos);
    // print(head);

    int posn;
    cout<<"enter node you want to delete "<<endl;
    cin>>posn;
    delete_node(head,posn);
    print(head);


    return 0;
}