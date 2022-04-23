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
    //Write your code here
    if(head1==NULL && head2==NULL) return head1;
    if(head1==NULL) return head2;
    if(head2==NULL)  return head1;
    
    node* fh = NULL;
    node* ft = NULL;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(fh == NULL && ft == NULL)
        {
            if(head1->data < head2->data)
            {
                fh = head1;
                ft = head1;
                head1= head1->next;
            }
            else 
            {
                fh = head2;
                ft = head2;
                head2 = head2->next;
            }
        }
        if(head1->data < head2->data)
        {
            ft->next = head1;
            ft = ft->next;
            head1 = head1->next;
        }
        else 
        {
            ft->next = head2;
            ft = ft->next;
            head2 = head2->next;
        }
    }
    if(head1!=NULL)
    {
        ft->next = head1;
    }
    if(head2!=NULL)
    {
        ft->next = head2;
    }
   return fh; 
    
}

// node *mergeTwoSortedLinkedLists(node *head1, node *head2)
// {
//     node *head=NULL;
//     node *temp1=head1;
//     node *temp2=head2;
//     node *tail=NULL;

//     while(temp1!=NULL && temp2!=NULL)
//     {
//             if(temp1->data  >= temp2->data)
//             {
//                 node *n= new node(temp2->data);
//                 if(head==NULL)
//                 {head=n;}
//                 else
//                 {
//                 tail->next=n;
//                 }
//                 temp2=temp2->next;
//                 tail=n;
//             }
//             else
//             {
//                 node *n= new node(temp1->data);
//                 if(head==NULL)
//                 {head=n;}
//                 else
//                 {tail->next=n;}
//                 temp1=temp1->next;
//                 tail=n;
//             }
//     }
//       while(temp1!=NULL)
//         {   
//              node *n= new node(temp1->data);
//                 if(head==NULL)
//                 {head=n;}
//                 else
//                 {tail->next=n;}
//                 temp1=temp1->next;
//                 tail=n;
//         }
//         while(temp2!=NULL)
//         {
//              node *n= new node(temp2->data);
//                 if(head==NULL)
//                 {head=n;}
//                 else
//                 {
//                 tail->next=n;
//                 }
//                 temp2=temp2->next;
//                 tail=n;
//         }
//     return head;
// }
// int length(node *head)
// {
//     if(head == NULL){return 0;}
//     if(head->next==NULL){return 1;}
//     int ans=length(head->next);
//     return (ans+1);
// }

// node *mergeSort(node *head)
// {
//     if(head==NULL)
//     {return head;}
//     if(head->next==NULL){return head;}

//     int len=length(head);
//     node *head2=head;
//     for(int i=0;i<(len/2)-1;i++)
//     {head2=head2->next;}
//     node *t=head2->next;
//     head2->next=NULL;
//     node* temp1=mergeSort(t);
//     node* temp=mergeSort(head);
//     node *ans=mergeTwoSortedLinkedLists(temp1,temp);
//     return ans;
// }






// node *mergeSort(node *head)
// {
//     if(head==NULL){return head;}
//     if(head->next==NULL){return head;}

//     node *head2=head->next;
//     head->next=NULL;
//     node* temp=mergeSort(head2);
//     node *ans=mergeTwoSortedLinkedLists(head,temp);
//     return ans;
// }

// node *Sort(node *head)
// {
//     if(head->next==NULL){return head;}
//     node *n = Sort(head->next);
//     if(head->data > n->data)
//     {
//         node *temp=n;
//         while(temp->data < head->data)
//         {
//             if(temp->next==NULL)
//             {
//                 temp->next=head;
//                 break;
//             }
//             else if((temp->next)->data > head->data)
//             {
//                 head->next=temp->next;
//                 temp->next=head;
//                 break;
//             }
//             temp=temp->next;
//             if(temp==NULL){break;}
//         }
//         head=n;
//     }
//     else
//     {head->next=n;}
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
    node *headnew=mergeTwoSortedLinkedLists(head);
    print(headnew);
    
    return 0;
}