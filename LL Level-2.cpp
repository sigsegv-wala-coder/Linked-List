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
/* REVERSE a Linked list Recursively */

/* The base case is if the linked list contain 0 or 1 element, then simply return
   Now call the recursive function and assume it will reverse the remaining list
   We'll save the head of the remaining linked list in smallans Node. Now find the
   last Node of the smallans linked list and connect that node to our head. Also, 
   head->next = NULL . Because initially our head ka next is the next element of original 
   linked list. 1 2 3 4 5 is Linked list, then after calling the recursive step, it will
   return 1 5 4 3 2 . So, we have to connect the last element i.e. 2 to our head i.e. 1 and
   head->next = NULL. */

Node *reverseLinkedListRec(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* smallans=reverseLinkedListRec(head->next);
    Node* temp=smallans;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return smallans;
}

/* The complexity of the above code is O(n^2). 
   Here is another recursive approach */

// Here we will create a pair class which consists of both head and tail such that
// we can't traverse the whole linked list to find the tail and then attach head to its next.

class inter {
  public : 
    
    Node* head;
    Node* tail;
    
};

inter reverseLL(Node* head){
    if(head==NULL || head->next==NULL){
        inter ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    inter smallAns=reverseLL(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    inter ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}

Node *reverseLinkedListRec(Node *head)
{
    return reverseLL(head).head;
}
