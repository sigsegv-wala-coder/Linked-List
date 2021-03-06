//*********************************************************************************************************************************************************

/* Create a Linked list
Take Input function
Print function*/

#include<iostream>
using namespace std;
class Node{

    public : 

    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};
Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp->next;
            }
            temp -> next = newNode;
        }
        cin>>data;
    }
    return head;
}
void print( Node *head){
    while(head!=NULL){
        cout<< head ->data << " ";
        head = head ->next ;
    }
}
int main(){
//statically
    // Node n1(10);
    // Node *head=&n1;

    // Node n2(20);
    // n1.next=&n2;

    // Node n3(30);
    // Node n4(40);
    // Node n5(50);

    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;
    Node *head = takeInput();
    print(head);

/*Dynamically

    Node *n3 = new Node(30);
    Node *head = n3;
    Node *n4 = new Node(40);

    n3 -> next = n4;*/
}

/* A better approach to reduce the complexity of take input function. Initially it was O(n^2). */

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;      // Tail node is created which will store the address of the last node.
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail=tail->next; 
            // OR tail = newNode;
        }
        cin>>data;
    }
    return head;
}
//**********************************************************************************************************************************************************
// Find iteratively length of a linked list
// The basic skeleton to Node class and takeInput is same as above. So just mentioning the length function.
int length(Node *head)
{
    Node* temp =head;         // It's always a good practice to create a temporary variable while iterating through linked list as
    int count=0;              // if we iterate through head then we can't use head other time as head = NULL after final iteration.
    while(temp!=NULL){        // Since we have head means the address of first Node, we'll search if it's NULL. If yes then return whatever
        count++;              // is the count. If not then point the head to the next Node.
        temp=temp->next;
    }
    return count;
}

// Recursively

int length(Node *head) {
    if(head==NULL){
        return 0;
    }
    return 1+length(head->next);
}

//************************************************************************************************************************************************************
/* For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position. */

void printIthNode(Node *head, int i)
{
    Node *temp=head;
    
    int count=0;
    
    while(temp!=NULL){                    // It's important to check for NULL. Consider the case where linked list is 20 -1 and the position is 3
        if(count==i){                     // then we have to check only till head equals NULL. 
            cout<<temp->data<<endl;
            return;
        }
        else{
            count++;
            temp=temp->next;
        }
    }  
}
//************************************************************************************************************************************************************
/* Insert a node at ith position */

Node* insertNode(Node* head , int i, int data){
    
    /* First thing to do is to create a new node that consists of the given data
    Now we have to connect the (i-1)th position node to new Node and new Node to ith position node 
    Dry run to understand better */

    Node *newNode =new Node(data);
    int count=0;
    Node* temp = head;

    if(i==0){                        // When have to make a separate case if want to insert at position zero.
        newNode->next = head;        //   and that will ultimately change the head also. That's why we have to update the head
        head = newNode;              //   and return the new head. That's why change the return type to Node* .
        return head;
    }

    while(temp!=NULL && count < i-1){       // We also have to add constraint temp!=NULL. Consider inserting a data at ith position
        count++;                            // where i exceeds the length of Linkedlist. Then it will give seisegv error. That's why we
        temp=temp->next;                    // have to keep a check over temp!=NULL or not. 
    }
    if(temp!=NULL){
        newNode -> next = temp->next;      // Connect ith node to the new node
        temp->next = newNode;              // Connect (i-1)th node to the new node.
    }
    /*OR
    Node* a=temp->next;
    temp->next = newNode;
    newNode->next = a; */
    return head;
}

// Recursively

Node* insertNode(Node *head, int i, int data) {
	
    if(head==NULL){
        return head;
    }
    if(i==0){
        Node* newNode =new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node* a=insertNode(head->next , i-1 , data);
    head->next = a;
    return head;
}

//**************************************************************************************************************************************************
/* You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'pos'. */

Node *deleteNode(Node *head, int pos)
{
    if(pos==0){
        return head->next;
    }
    
    int count=0;
    Node* temp = head;
    while(temp!=NULL && count<pos-1){
        count++;
        temp=temp->next;
    }
    if(temp!=NULL && temp->next!=NULL ){     //Since we are using pointer to point to temp->next->next , we have to check whether temp->next = NULL or not
        Node* a=temp->next;
        Node* b=a->next;
        temp->next = b;
        delete a;
    }
    return head;
}

// Recursively

Node *deleteNodeRec(Node *head, int pos) {
	if(head==NULL){
        return head;
    }
    if(pos==0){
        Node *a=head;
        head=head->next;
        delete a;
        return head;
    }
    Node* b=deleteNodeRec(head->next , pos-1);
    head->next=b;
    return head;
}
//****************************************************************************************************************************************************
