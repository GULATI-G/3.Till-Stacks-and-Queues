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

node *removeDuplicates (node *head)
{
if(head==NULL){return head;}
    node *temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==((temp->next)->data))
        {
            node *temp1=temp->next;
            while((temp->data)==(temp1->data) )
            {
                node *t=temp1;
                temp1=temp1->next;
                if(temp1==NULL){break;}
                delete t;
            }
            temp->next=temp1;
        }
        if(temp->next==NULL){break;}
        else{temp=temp->next;}
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
    // print(head);
    head=removeDuplicates(head);
    print(head);

    return 0;
}