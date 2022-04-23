Node *midPoint(Node *head)
{
    if(head==NULL){return head;}
    Node *slow=head;
    Node *fast=head->next;

    while( fast!=NULL )
    {
        if(fast->next==NULL){return slow;}
        slow=slow->next;
        fast=(fast->next)->next;
    }
    return slow;
}