// C++ code to reverse a singly linked 
// list in groups of K size
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Helper function to reverse K nodes
Node* reverseKNodes(Node* head, int k) {
    Node* curr = head, * prev = nullptr, * next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    return prev;
}

// Recursive function to reverse in groups of K
Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr) {
        return head;
    }
    Node* groupHead = nullptr;
    Node* newHead = nullptr;

    // Move temp to the next group
    Node* KthNode = head;
    int count = 0;
    while (KthNode && count < k) {
        KthNode = KthNode->next;
        count++;
    }

    // Reverse the first K nodes
    groupHead = reverseKNodes(head, k);

    // Connect the reversed group with the next part ( this part works only for first group)
    if (newHead == nullptr) {
        newHead = groupHead;
    }

    // Recursion for the next group
    head->next = reverseKGroup(KthNode, k);

    return newHead;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // Creating a sample singly linked list:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head = reverseKGroup(head, 3);
    printList(head);

    return 0;
}
