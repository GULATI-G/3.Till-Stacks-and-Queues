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

node *reverseLinkedListRec(node *head)
{
    if(head==NULL){return head;}
    if(head->next==NULL){return head;}
    node *pr=NULL;
    node *cr=head;
    while(cr!=NULL)
    {
        node *temp=cr->next;
        cr->next=pr;
        pr=cr;
        cr=temp;
    }
    return pr;
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
    node *headnew=reverseLinkedListRec(head);
    print(headnew);
    
    return 0;
}
