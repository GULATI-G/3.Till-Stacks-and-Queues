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

int findNode (node *head, int data_you_want_to_search) 
{
    node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(data_you_want_to_search==temp->data)
        {
            return count;
        }
        count++;
        temp=temp->next;
    }
    return -1;
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
    int data;
    cout<<"enter data you want to search ";
    cin>>data;
    int index=findNode (head, data);
    if(index==-1){cout<<"not present ";}
    else {cout<<"the data is present at index "<<index<<endl; }
    return 0;
}