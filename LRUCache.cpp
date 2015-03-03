#include <iostream>
using namespace std;

class DLLNode{
  public:
	DLLNode *prev;
	DLLNode *next;
	int val;
	DLLNode(int vv):val(vv){
		prev = NULL;
		next = NULL;    
	}
};

class PriorityQueue{
   public:
   	DLLNode *head;
	DLLNode *tail;
	int MAX_SIZE;
   	int c_value;
   	PriorityQueue(int);
	void insertRecordAtHead(DLLNode*);
   	int fetchRecord(int);  
	void moveRecordAtFirst(DLLNode**);  
	void displayData();
};

PriorityQueue::PriorityQueue(int max){
	MAX_SIZE = max;
	c_value = 0;
	head = NULL;
	tail = NULL;
}


int PriorityQueue::fetchRecord(int x){

	DLLNode *h = head;
	bool found = false;
	
	if(head == NULL){
		insertRecordAtHead(new DLLNode(x));
		return x;	
	}else{
		while(h != NULL){
			if(h->val == x){
				cout<<"\n Record :  "<<x<<" found in cache";
				moveRecordAtFirst(&h);
				found = true;
				break;
			}
			h = h->next;
		}
		if(!found){
			cout<<"\n Record :  "<<x<<" not found in cache";
			if(c_value <MAX_SIZE){
				insertRecordAtHead(new DLLNode(x));
			}else{
				tail->val = x;
				moveRecordAtFirst(&tail);
			}
		}
		return x;	
	}
}

void PriorityQueue::insertRecordAtHead(DLLNode* node){
	if(c_value < MAX_SIZE){
		if(head==NULL){
			head = node;
			tail = node;		
		}else{
			head->prev = node;
			node->next = head;
			node->prev = NULL;
			head = node;
		}
		c_value++;
	}
	cout<<"\n Record is now most recent page . . . ";
}



void PriorityQueue::moveRecordAtFirst(DLLNode** node){

	DLLNode *temp = (*node);
	cout<<"\n Moving record at the latest page . . . ";

	if(temp == head){

	}else if(temp->next != NULL){
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		temp->next = head;
		head->prev = NULL;
		head = temp;
	}else{
		tail = temp->prev;
		temp->prev->next = NULL;
		temp->next = head;
		head->prev = temp;
        head = temp;
	}
}

void PriorityQueue::displayData(){
	DLLNode* h = head;
	if(head == NULL){
		cout<<" Empty Cache.";
	}else{
		while(h!=NULL){
			cout<<h->val<<"  |  ";
			h = h->next;
		}
	}
}


class LRUCache{
    PriorityQueue *storage;
    int MAX_SIZE;
  public:
    LRUCache(int);
    int fetch(int);
    void printCache();

};

LRUCache::LRUCache(int size){
	storage = new PriorityQueue(size);
	MAX_SIZE = size;
}

int LRUCache::fetch(int x){
    return storage->fetchRecord(x);
}

void LRUCache::printCache(){
	cout<<"\n Data in Cache : " ;
	storage->displayData();
}

int main(){
	int arr[12] ={1,2,4,5,1,3,6,2,3,1,4,6};
	int SIZE = 12;
	LRUCache cache(5);
	for(int i=0;i<SIZE;i++){
		cout<<"\n\n Record to serach : "<<arr[i]<<endl;
		cache.fetch(arr[i]);
		cache.printCache();
	}
}
