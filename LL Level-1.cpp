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

