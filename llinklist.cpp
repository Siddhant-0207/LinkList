#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    int data;
    Node* next;

    Node(int data1 )
    {
        data = data1;
        next = nullptr;

    }
    Node(int data1 , Node* next1)
    {
        data = data1;
        next= next1;
    }
   
};
 Node* convertArr2LL(vector<int> &arr)
    {
        Node* head =new Node(arr[0]);
        Node* mover = head;
        for( int i = 1;i<arr.size();i++)
        {
            Node* temp = new Node(arr[i]);
            mover->next=temp;
            mover=temp;
        }
        return head;
    }
// delete the head node 
Node* deletehead(Node* head)
{
    if(head==NULL) return head;
    Node* temp= head;
    head=head->next;
    delete temp;
    return head;

}
//delete the tail of the linklist 
Node* deleteTail(Node* head)
{
    if ( head==NULL|| head->next == NULL) return NULL;
    Node* temp=head;
    while (  temp->next->next != NULL)
    {
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
return head;
}
void print(Node* head)
{
    Node* temp = head;
    while( temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//deleteing the k element in the linklist
Node* deleteK(Node* head ,int k )
{
    if ( head == NULL) return head ;
    if ( k==1)                     // if the 1 element is our kth element 
    {
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    // if it is somewhere between the linklist
    Node* temp=head;
    int cnt=0;
    Node* prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if(cnt==k)
        {
            prev->next = prev->next->next;     
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
    
}
//Deleting the value in the linklist 
Node* deleteVal(Node* head ,int val )
{
    if ( head == NULL) return head ;
    if ( head->data==val)                     // if the 1 element is our  element 
    {
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    // if it is somewhere between the linklist
    Node* temp=head;
    Node* prev = NULL;
    while (temp != NULL)
    {
        
        if(temp->data==val)
        {
            prev->next = prev->next->next;     
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
    
}
Node* InsertHead(Node* head , int val)
{
    Node* temp = new Node(val,head);
    return temp;
}

//insert tail 
Node* insertTail(Node* head , int val)
{
    if ( head==NULL)
    return new Node(val);
    Node* temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
    
}

// insert at kth position 
Node* insertK(Node* head, int el, int k)
{
    if(head==NULL)
    {
        if(k==1) return new Node(el);
    }
    if ( k==1)
    {
        Node* temp = new Node(el,head);
        return temp;
    }
    int cnt= 0 ;
    Node* temp = head;
    while( temp != NULL)
    {
        cnt++;
        if ( cnt==k-1)
        {
            Node* x = new Node(el,temp->next);
            temp->next=x;
            break;
        }
        
        temp=temp->next;

    }
    return head;
}

//insert before the value 
Node* insertBeforeVal(Node* head, int el, int val)
{
    if(head==NULL)
    {
        return NULL;
    }
    if ( head->data==val)
    {
        Node* temp = new Node(el,head);
        return temp;
    }
    Node* temp = head;
    Node* prev = NULL;
    while( temp != NULL)
    {
        if ( temp->data == val )
        {
            Node* x = new Node(el,prev->next);
            prev->next=x;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main()
{   
    vector<int> arr = {12,4,5,8};
    Node* head = convertArr2LL(arr);
    head = insertBeforeVal(head,30,5);
    print(head);
    return 0 ;
}