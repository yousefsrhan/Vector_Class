// Doubly linked list.cpp 
using namespace std;
#include <iostream>
class ListNode
{
public:

    int data;
    // int size =0;
    ListNode* next;
    ListNode* previous;
    //ListNode() {} // empty (default constructor
    ListNode(int val) : next(nullptr), previous(nullptr), data(val) {} // end constructor
};// end Class 
class doubly_linked_list {
public:
    ListNode* head;
    ListNode* tail;
    //int index;
    int size;
    
    doubly_linked_list() : head(nullptr), tail(nullptr) , size (0) {}
    
    void addToBeginning(int val) 
    {
        if (!head)
        {
            tail = head = new ListNode(val);// precedence of oeprations RTL !
            size++;
        }
        else 
        {
            ListNode* newNode = new ListNode(val);
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            size++;
        }
    }

    void append(int val)
    {
        if (!head)
        {
            tail = head = new ListNode(val);
            size++;
        }
        else
        {
            ListNode* newNode = new ListNode(val);
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
            size++;// size ++
        }
    }
    void insert_at_position(int val , int index) 
    { 
        if (index > size + 1 || index < 1)   // I corrected size +1 (my mistake about prevention from appebding)
            cout << "Unreachable index !";
        // in doubly linked lists inserting at head or tail are both edge cases [headache]!! ( Corrected this point)
        else if (index == 1)// regualr add to beginning
            addToBeginning(val);
        else if (index == size + 1) // regualr append
            append(val);
        else // insert in middle -> need to find shortest path !
        {
            ListNode* newNode = new ListNode(val);
                // determine to :
                // [1] go forward OR [2]  backward !
                // [ imagine line of numbers] ==>>
                //   1- - - - -IDX- - - - -tail -> calculate the Shortest-Distance! 
                ListNode* current = index-1  <= size-index ? head : tail;
                if( current  == head) // distance calcluated from size+1 since 
                {
                    int currentIdx = 1;
                    while (currentIdx < index-1) // corrected stop point to index -1 not index (just miss of foucs!)
                    {
                        currentIdx++;
                        current = current->next;// the last node you will stop at
                        // will be the node right before your index/targeted node
                    }
                    newNode->next = current->next;
                    current->next->previous = newNode;
                    newNode->previous = current;
                    current->next = newNode;
                    // Now,the node right after you now is the target!!
                    size++; // don't forget!!
                } 
                else if( current  == tail)
                {
                    int currentIdx = size;
                    while (currentIdx > index+1) 
                    {
                        currentIdx--;
                        current = current->previous;
                    }
                    // Now,the node right before you now is the target!!
                    newNode->next = current->next;
                    current->next->previous = newNode;
                    newNode->previous = current;
                    current->next = newNode;
                    size++;
                }
        }
    }// insert at position
};
    
int main()
{

}
