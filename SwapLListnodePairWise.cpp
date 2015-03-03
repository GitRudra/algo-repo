/**
 * Program to swap the node of a linklist pair wise.
 * Ex: I/P : 1->2->3->4->5->6
 * 	   O/P : 2->1->4->3->6->5
 */
 
#include<iostream>
using namespace std;

/**
 * Simple class to store the information of
 * each listnode
 */
 
class ListNode{
	public:
	int val;
    ListNode* next;
	ListNode(int value){
		val = value;
		next = NULL;
	}
};

/**
 * Helper function to create list.
 * The function insert node at the begining of Link List
 */
void appendFirst(ListNode **head,ListNode *node){
	node->next = *(head);
	*(head) = node;
}

/**
 * Helper method responsible for list creation
 */
 
void createList(ListNode **head, int* valuearray ,int size){
	for(int i=size-1;i>=0;i--){
		ListNode* node = new ListNode(*(valuearray + i));
		appendFirst(head,node);
	}
}

/**
 * Helper method to display a list
 */
 
void displayList(ListNode* head){
	ListNode* temp = head;
	if(temp != NULL){
		cout<<"\n List : ";
		while(temp!=NULL){
			cout<<temp->val<<" , ";
			temp=temp->next;
		}
	}else{
		cout<<"Empty List !!!";
	}
}

/**
 * Main method to swap the nodes pair wise.
 */
 
void swapNodePairWise(ListNode** head){
	if(*(head) == NULL){
		cout<<"\n Empty List !!!";
		return;
	}
	ListNode *h = *(head);
	ListNode *temp = NULL;
	//Swap the first two node of a linklist.
	//As for fist two node address of HEAD pointer will be changed
	if(h->next != NULL){
		temp = h->next;
		h->next = temp->next;
		temp->next = h;
		*(head) = temp;
	}
	
	// Iteratively swap the remainig node of the list.
	while(h->next!=NULL && h->next->next != NULL){
		temp = h->next->next;
		h->next->next = temp->next;
		temp->next = h->next;
		h->next = temp;
		h = h->next->next;
	}
	
}
/**
 * Driver function
 */
 
int main(){
	int num1[7]={3,4,5,0,6,2,7};
	ListNode* numlist1 = NULL;
    createList(&numlist1,num1,7);
	displayList(numlist1);
	swapNodePairWise(&numlist1);
	displayList(numlist1);
}


