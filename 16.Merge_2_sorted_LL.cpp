#include<iostream>
#include<string>
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

node *mergeTwoSortedLinkedLists(node *head1, node *head2)
{
    node *head=NULL;
    node *temp1=head1;
    node *temp2=head2;
    node *tail=NULL;

    while(temp1!=NULL && temp2!=NULL)
    {
            if(temp1->data  >= temp2->data)
            {
                node *n= new node(temp2->data);
                if(head==NULL)
                {head=n;}
                else
                {
                tail->next=n;
                }
                temp2=temp2->next;
                tail=n;
            }
            else
            {
                node *n= new node(temp1->data);
                if(head==NULL)
                {head=n;}
                else
                {tail->next=n;}
                temp1=temp1->next;
                tail=n;
            }
    }
      while(temp1!=NULL)
        {   
             node *n= new node(temp1->data);
                if(head==NULL)
                {head=n;}
                else
                {tail->next=n;}
                temp1=temp1->next;
                tail=n;
        }
        while(temp2!=NULL)
        {
             node *n= new node(temp2->data);
                if(head==NULL)
                {head=n;}
                else
                {
                tail->next=n;
                }
                temp2=temp2->next;
                tail=n;
        }
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
    node *head2=input();
    node *headnew=mergeTwoSortedLinkedLists(head, head2);
    print(headnew);
    
    return 0;
}