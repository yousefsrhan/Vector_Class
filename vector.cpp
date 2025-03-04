#include <iostream>
using   namespace std;

class Vector {
private:
	int size;
	int capacity = 0;
	int* arr = nullptr;
public:
	Vector(int size) :
	size(size >= 0 ? size : -1)
	, capacity(size > 0 ? 2 * size : 1)
	, arr(new int[capacity]) {}
	~Vector() {
		delete [] arr;
		arr = nullptr;
	}
	// (( getter Functions ))
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
	  bool isEmpty() {
		  return (arr == nullptr || capacity == 0);
	}
	  int find(int val) {
		  for (int i = 0; i < size;++i)
			  if (val == arr[i])
				  return i ;
		  return -1;
	  }

	  void expandCapacity() {
		  int tmp = 2 * capacity;
		  int* arr2 = new int[tmp];
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
		  arr[size++] = val;
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
};
int main()
{
}
