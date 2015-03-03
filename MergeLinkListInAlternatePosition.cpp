#include<iostream>
using namespace std;

class LinkNode{
	public:
		LinkNode* next;
		int val;
		LinkNode(int x):val(x){
			next = NULL;
		}
};	


void createList(LinkNode** head,int* arr,int n){
	LinkNode* h = (*head);
	for(int i = 0;i<n;i++){
		LinkNode* node = new LinkNode(*(arr+i));
		if(h == NULL){
			*(head) = node;
		}else{
			node->next = h;
			(*head) = node;
		}
	}
}

void displayLinkList(LinkNode* node){
	cout<<"\n Values in list : ";
	while(node!=NULL){
		cout<<node->val<<"  ";
	}

}

void mergeLinkListAlternatively(LinkNode** head1,LinkNode* head2){
	LinkNode* h1 = (*head1);
	LinkNode* nexthead2 = head2;
	if( h1 == NULL || head2 == NULL){
	
	}else{
		while(h1->next != NULL && nexthead2->next != NULL){
			nexthead2 = nexthead2->next;
			head2->next = h1->next;
			h1->next = head2;
			h1 = h1->next->next;	
		}
	}
}
