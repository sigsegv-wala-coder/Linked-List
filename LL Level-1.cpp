*********************************************************************************************************************************************************

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
**********************************************************************************************************************************************************
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
************************************************************************************************************************************************************
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
************************************************************************************************************************************************************




