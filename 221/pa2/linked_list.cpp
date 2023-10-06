class LinkedList{
	Node* head;
	Node* tail;

	LinkedList(): head(nullptr), tail(nullptr){
	}

	


	void insert(const Node other){

	}

	void remove(const Node other){

	}

	void get_head(){
		return head;
	}


}

class Node{
	int* data;
	Node* next;
	Node(): data(nullptr), next(nullptr){
	};

	~Node(){
		delete data;
		delete next;
		data = nullptr;
		next = nullptr;
	}
}
