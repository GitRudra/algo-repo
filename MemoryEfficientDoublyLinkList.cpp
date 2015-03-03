#include<iostream>
using namespace std;

class ListNode{
	public:
	int val;
	ListNode *ptrdiff;
};

ListNode* nextNode(ListNode* prev, ListNode* current){
	return (ListNode*)((int)prev ^ (int)current);
}

void appendFirst(ListNode** head, ListNode** tail, ListNode *newnode){
	if(*(head) == NULL && *(tail) == NULL){
		newnode->ptrdiff = (ListNode*)((int)(*(head))^(int)(*(tail)));
		*(head) = *(tail) = newnode;
	}else{
		(*(head))->ptrdiff = (ListNode*)((int)(*(head)));
	}
}

void appendLast(ListNode **head, ListNode** tail, ListNode *newnode){
	
}

void insertNode(ListNode* head, ListNode* newnode , int element){
	
	ListNode *prev, *next, *current;
	prev = NULL;
	current = head;
	while(current){
		next = nextNode(prev,current);
		if(current->val == element){
			if(next){
				next->ptrdiff = (ListNode*)((int)next->ptrdiff ^ (int)current ^ (int)prev);
				current->ptrdiff = (ListNode*)((int)newnode ^ (int)prev ^ (int)current->ptrdiff);
				newnode->ptrdiff = (ListNode*)((int)current ^ (int)next);
				break;
			}
		}
		prev = current;
		current = next;
	}
}
