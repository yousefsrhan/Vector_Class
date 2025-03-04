#include <iostream>
#include <vector>
using   namespace std;

class Vector {
private:
	int size;
	int capacity = 0;
	int* arr = nullptr;
public:
	Vector(int size) :
		size(size > 0 ? size : 0)
	, capacity(size > 0 ? 2 * size : 1)
	, arr(new int[capacity]) {}
	~Vector() {
		delete [] arr;
		arr = nullptr;
	}
	// (( getter Functions )) count [4]
	int getFront() {
		return arr[0];
	}
	int getBack() {
		return arr[size-1];
	}
	int getSize() {
		  return size;
	  }
	int getCapacity() {
		  return capacity;
	  }
	// bool functions count [1]
	  bool isEmpty() {
		  return (arr == nullptr || size == 0);
	}
	  // find (search) count [1]
	  int find(int val) {
		  for (int i = 0; i < size;++i)
			  if (val == arr[i])
				  return i ;
		  return -1;
	  }
	  // change size/capacity -add/popLast/insert  functions, count [5]
	  void expandCapacity() {
		  capacity= 2 * capacity;
		  int* arr2 = new int[capacity];
		  for (int i = 0; i < size; ++i) {
			  arr2[i] = arr[i];
		  }
		  swap(arr2, arr);
		  delete[] arr2;
	  }
	  void push_back(int val) {
		  if (size == capacity) {
			  expandCapacity();
		  }
		  arr[size++] = val;// no garbage here because size starts from zero so the garbage is cleaned!
	  }
	  int popLast() {
		  int temp = arr[size - 1];
		  arr[size - 1] = NULL;
		  size--;
		  return temp;
	  }
	  int pop(int index) {
		  int temp = arr[index];
		  for (int i = index; i < size;++i)
			  arr[i] = arr[i + 1];
		  arr[size--] = NULL;
		  return temp;
	  }
	  void insert(int index, int val) {
		  if (index < 0 || index > size)
		  {
			  cout << "out of range"<<endl;
			  return;
		  }
		  if (size == capacity)
			  expandCapacity();
		  size++;
		  for (int i = size; i > index;--i)
			  arr[i] = arr[i - 1];
		  arr[index] = val;
	  }
		  void resize(int newSize) {
			  // Do nothing if newSize is invalid or equal to the current capacity.
			  if (newSize <= 0 || newSize == capacity)
				  return;
			  int* arr2 = new int[newSize];
			  int elementsToCopy = (newSize < size) ? newSize : size;
			  for (int i = 0; i < elementsToCopy;++i) {
				  arr2[i] = arr[i];
			  }
			  capacity = newSize;
			  swap(arr2, arr);
			  delete[] arr2;
			  // Adjust the current size if necessary.
			  if (size > newSize)
				  size = newSize;
		  }
		  void display() {
			  for (int i = 0;i < size;++i)
				  cout << arr[i] << " ";
			  cout << endl;
		  }
		  void rightRotation()
		  {
			  int temp = arr[size - 1];
			  for (int i = size - 1; i >= 1;--i)
				  arr[i] = arr[i - 1];
			  arr[0] = temp;
		  }
		  void rightRotation(int n)
		  { 
			  for (int i = 0; i < n;++i) 
				  rightRotation();
		  } 
		  void leftRotation()
		  {
			  int temp = arr[0];
			  for (int i = 0; i < size-1;++i)
				  arr[i] = arr[i + 1];
			  arr[size-1] = temp;
			  
			  //swap(arr[0], arr[size - 1]);
		  }
};
int main()
{
	Vector v(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.pop(1);
	v.display();
	
	//v.rightRotation();

	// output 1 2 3 4 5
	//vector<int> myVector(5);
	//myVector.push_back(1);
	//myVector.push_back(2);
	//myVector.push_back(3);
	//myVector.push_back(4);
	//myVector.push_back(5);
	//for (int i = 0; i < 5; ++i)
	//	cout << myVector[i]<<" ";
	//cout<< endl;
	//// output 0 0 0 0 0
	//for (int i = 0; i < 10; ++i)
	//	cout << myVector[i]<<" ";
	//	// output 0 0 0 0 0 1 2 3 4 5
}
