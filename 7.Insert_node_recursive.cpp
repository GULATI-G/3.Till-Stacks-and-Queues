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

node* insert_node_recursively(node *head, int data, int pos)
{
    if(head==NULL){return;}
    if(pos==0)
    {
        node *p= new node(data);
        p->next=head;
        head=p;
        return head;
    }
    // if(head->next==NULL){return head;}  IMP FEATURE DUE TO PLACEMENT OF LINE AT 44 OR 51
    if(pos==1)
    {
        node *p= new node(data);
        p->next=head->next;
        head->next=p;
    }
    if(head->next==NULL){return head;}
    insert_node_recursively(head->next,data,pos-1);
    return head;
}

//  ANOTHER METHOD BY CN
// node* insert_node_recursively(node *head, int data, int pos)
// {
//     if(head==NULL){return head;}
//     if(pos == 0)
//     {
//         node *p= new node(data);
//         p->next=head;
//         head = p;
//         return head;
//     }
//     node *x=insert_node_recursively(head->next, data, pos-1);
//     head->next=x;
//     return head;
// }

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
    int data;
    cout<<"enter data you want to insert ";
    cin>>data;
    int pos;
    cout<<"enter the position ";
    cin>>pos;
    head=insert_node_recursively(head,data,pos);
    print(head);
    return 0;
}