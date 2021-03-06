// MidPoint of Linked List.......

/* The brute force approach is to first calculate the length of linked list
   Then find (length-1)/2 . This will give the middle position of LL. Note that
   in case of even number of elements, the first middle is considered.
   Now, print the middle position node according to the approach to find ith node.
   
   Another better approach is to create two nodes. The first one will point to the head
   and the second one points to head->next . Now point the first node to next node and the second one to 
   next->next means two positions at a time.
   
   As a result when the second one will finish traversing, the first one will be at middle.
   And we'll return the first node */

#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

Node *midPoint(Node *head)
{
    if(head==NULL){
        return head;
    }
    Node* single_jump=head;     //shift one position at a time
    Node* double_jump=head->next;         //shift two position at a time
    while(double_jump!=NULL && double_jump->next!=NULL){
        single_jump=single_jump->next;
        double_jump=double_jump->next->next;
    }
    return single_jump;
}

int main()
{
	int t;
	cin >> t;     //Multiple test case handler
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}
//****************************************************************************************************************************************************
