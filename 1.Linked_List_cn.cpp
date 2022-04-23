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

void print(node *p)
{
    
    cout<<p->data<<endl;
    if(p->next == NULL){return;}
    print(p->next);   

    //or
    // so that we don't loose the head in this function we introduce temp variable
    // IMP if we use p instead of p in the loop, the head will be lost in the function not in the main code as the function creates
    // a copy of the head.
    // node *temp = p;
    // while(temp!=NULL)
    // {
    //     cout<< temp -> data <<endl;
    //     temp=temp->next;
    // }
}

int main()
{
    // in arrays we have to already define the siz of the array which creates a problem.
    // In array memory is allocated side by side which creates a problem of creating more space as memory adjacent may not be 
    // available for us. This is solved by linked list as in linked list the elements are not added side by side. 
    // each block holds the address for the next block and we store the address of only first element. Thus it is a list that is
    // linked to each other. Thus a linked list.

    
    node n1(1);
    node *head=&n1;
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;

    print(head);
    // first node of the linked list is called head
    // last node is called tail of the linked list

    // dynamically

    /*
    node *o1=new node(3);
    node *head1 = o1;
    node *o2=new node(4);
    cout<<o1->data<<" "<<o2->data<<endl;
    o1->next=o2;
    */

    return 0;
}