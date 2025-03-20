#include <iostream>
using namespace std;
struct Node {
public:
	int data;
	Node* next;
	Node() : data(NULL) , next(nullptr) { }
};
struct linkedList {
private:
	Node* head;
public:
	linkedList() :head(nullptr) {} // Constructor  as initialization_list syntax
	// boolean function
	bool isEmpty () {
		return head == nullptr;
	}
	bool search( int val) {
		Node* current = head;
		bool found = false;
		while (current != nullptr) {
			if (current->data == val) {
				found = true;
				break;
			}// else 
			current = current->next;
		}
		return found;
	}

	void insert_at_beginning(int val) {
		Node* newNode = new Node();// we use circular brackets to create new node here as nameless pointer !!
		// megacode advice above here !!
		newNode->next = head;
		newNode->data = val;
		head = newNode;	
	}
	int getSize() {
		long long size = 0; // size started at one as head won't be included if counted from zero;
		Node* current = head;
		while (current != nullptr) {
			current = current->next;
			size++;
		}
		return size;
	}
	// get position method 
	int getIndex(int val) {
		Node* current = head;
		bool found = false;
		int zeroIndex = 0;
		while (current != nullptr) {
			if (current->data == val) {
				found = true;
				break;
			}
			// else increment index by one 
			zeroIndex++;
			current = current->next;
		}
		return (found? zeroIndex: -1) ;
	}
	void insert(int val , int index = 0) {
		// cannot happen in my life time my friend !
		if (index > getSize()) {
			cout << "out of bounds index";
			return;
		}
		if (index == 0) {
			insert_at_beginning(val);
			return;
		}
		// now we can me the next two steps fixed ! 
		Node* newNode = new Node();
		newNode->data = val;
		Node* previous = head;
		for(long long counter = 0;counter < index - 1; counter ++){
			previous= previous->next;
		}
		newNode->next = previous->next;
		previous->next = newNode;
	}
	void display() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << endl;
			current = current->next;
		}
	}
	~linkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
		head = nullptr; // optional but for more safety !
	}	
};
int main()
{

}
