#include <iostream>
using namespace std;

class Node {
	public: 
		Node() {};
		~Node() {};
		Node* next;
		int data; 
};

class LinkedList {
	public: 
		LinkedList();
		~LinkedList();
		int get_index(int index);
		void insert_at_front(int data);
		void insert_at_back(int data);
		int get_size();
	private: 
		Node* head;
		int size;
};

LinkedList::LinkedList() {
	this->head = NULL;
	this->size = 0;
}

LinkedList::~LinkedList() {

	Node* curr_node = this->head;
	while(curr_node != NULL) {
		Node* previous = curr_node;
		curr_node = curr_node->next;
		delete previous;
	}

}

int LinkedList::get_size() {
	int size = 0;
	Node* curr_node = this->head;
	while(curr_node != NULL) {
		size++;
		curr_node = curr_node->next;
	}
	return size;	
}

int LinkedList::get_index(int index) {
	Node* curr_node = this->head;
	if (index >= this->get_size()) {
		throw runtime_error("Invalid index");
	}

	for(int i=0; i < index; i++) {
		curr_node = curr_node->next;
	}	
	return curr_node->data;
}

void LinkedList::insert_at_front(int data) {
	Node* new_node = new Node();
	new_node->data = data;
	if (this->head == NULL) {
		this->head = new_node;
		new_node->next = NULL;
	} else {
		new_node->next = this->head; 
		this->head = new_node;
	}
	size+=1;
}

void LinkedList::insert_at_back(int data) {
	
	Node* curr_node = this->head;
	if (curr_node == NULL) {
		Node* new_node = new Node();
		this->head = new_node;
		new_node->next = NULL;
		new_node->data = data;
		this->size += 1;
	} else {
		while( curr_node->next != NULL) {
			curr_node = curr_node->next;
		}
		Node* new_node = new Node();
		curr_node->next = new_node;
		new_node->data = data;
		new_node->next = NULL;
		this->size += 1;
	}
} 


LinkedList* add_lists_forward(LinkedList* first_list, LinkedList* second_list) {
	LinkedList* summation_list = new LinkedList();
	
	int first_size = first_list->get_size();
	int second_size = second_list->get_size();
	
	int sum=0; int carry = 0;
	for(int i = first_size-1; i >= 0; i--) {
		sum = first_list->get_index(i) + second_list->get_index(i) + carry;
		if (sum >= 10) {
			// carry = sum - (sum % 10); // 14... then 14 %10 = 4. 1
			sum = sum % 10;
			carry = 1;
		} else { 
			carry = 0;
		}
		summation_list->insert_at_front(sum);	
	}


	return summation_list;

}



int main(int argc, char* argv[]) {
	LinkedList* my_list = new LinkedList();
	for(int i=5; i<10; i++) {
		my_list->insert_at_back(i);
	}

	LinkedList* second_list = new LinkedList();
	for(int i=1; i<6; i++) {
		second_list -> insert_at_back(1);
	}
	
	// Two linked lists:
	/* 5 -> 6 -> 7 -> 8 -> 9
       1 -> 1 -> 1 -> 1 -> 1
	--------------------------
	   6    7    9    0    0	
	*/

	for(int i=0;i<my_list->get_size();i++) {
		cout << my_list->get_index(i) << " " ;
	}	
	cout << endl;

	for(int i=0;i<second_list->get_size();i++) {
		cout << second_list->get_index(i) << " " ;
	}	
	cout << endl;

	LinkedList* solution_list = add_lists_forward(my_list, second_list); 
	cout << "This is the solution list: " << endl;
	for(int i=0; i<solution_list->get_size(); i++) {
		cout << solution_list->get_index(i);
	}	
	cout << endl;
	return 0;
}
