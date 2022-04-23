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

// bool isPalindrome (node *head)
// {
//     if(head==NULL){return true;}
//     string s="";
//     node *temp=head;
//     while(temp!=NULL)
//     {
//         s=s+to_string(temp->data);
//         temp=temp->next;
//     }
//     string t=s;
//     reverse (s.begin(),s.end());
//     if(s==t){return true;}
//     return false;
// }

int length(node *head)
{
    if(head == NULL){return 0;}
    if(head->next==NULL){return 1;}
    int ans=length(head->next);
    return (ans+1);
}

string reverse (string s,int len)
{
    string n="";
    int count=len-1;
    while(count!=-1)
    {
        n+=s[count];
        count--;
    }
    return n;
}

bool isPalindrome (node *head)
{
    int len=length(head);
    if(head==NULL){return true;}
    string s="";
    node *temp=head;
    while(temp!=NULL)
    {
        s=s+to_string(temp->data);
        temp=temp->next;
    }
    string d=reverse (s,len);
    if(s==d){return true;}
    return false;
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
    cout<<isPalindrome(head);

    return 0;
}