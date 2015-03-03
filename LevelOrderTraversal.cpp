#include<iostream>
using namespace std;

class TreeNode{
  public:
	TreeNode* left;
	TreeNode* right;
	int val;
    TreeNode(int x){
		val = x;
		left = NULL;
		right = NULL;
    }
};


class ListNode{
  public:
	ListNode *next;
	TreeNode *val;
	ListNode(TreeNode *node){
		val = node;
		next = NULL;
	}
};

class Queue{
	public:
	ListNode *queue;
	Queue(){
		queue = NULL;
	}
	void enQueue(TreeNode *);
	TreeNode* deQueue();
	bool isEmpty(){
		return (queue == NULL) ? true:false;
	}
};

void Queue::enQueue(TreeNode *node){
	ListNode *newnode = new ListNode(node);
	if(queue == NULL){
		queue = newnode;
	}else{
		ListNode* q = queue;
		while(q->next != NULL){
			q = q->next;
		}
		q->next = newnode;
	}
}

TreeNode* Queue::deQueue(){
    TreeNode *tnode = NULL;
	if(queue != NULL){
		tnode = queue->val;
		queue = queue->next;
	}
	return tnode;
}

void levelOrderTraversal(TreeNode *root){
	cout<<"\n level order traversal started ";
	Queue q ;
	q.enQueue(root);
	while(!q.isEmpty()){
		TreeNode *node = q.deQueue();
		cout<<node->val;
		if(node->left != NULL){
			q.enQueue(node->left);
		}
		if(node->right != NULL){
			q.enQueue(node->right);
		}
	}
}

void createTree(TreeNode* node){
 
	TreeNode* h;
    h = node;
    h->left = new TreeNode(4);
	h->right = new TreeNode(8);
    h->left->left = new TreeNode(2);
	h->left->right = new TreeNode(5);
	h->right->left = new TreeNode(7);
	h->right->right = new TreeNode(9);
	cout<<"Tree creation completed "<<endl;
}

void disPlayTree(TreeNode *node){
	if(node != NULL){
		disPlayTree(node->left);
		cout<<node->val<<" , ";
		disPlayTree(node->right);
	}
}


int main(){
	TreeNode* rootnode = (TreeNode*) new TreeNode(6);
    cout<<" Root : "<<rootnode->val;
    createTree(rootnode);
    levelOrderTraversal(rootnode);
}
