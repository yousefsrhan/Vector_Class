#include <iostream>
//#include <vector>
using namespace std;

class  Vector
{
    private:
        int *arr= nullptr;
        int size = 0;
        int capacity = 0;
    public:
        Vector(int Capacity) :
            capacity( Capacity <=0?1 : Capacity) ,
            size(0),
            arr( new int [Capacity])  {}
        ~Vector(){ delete [] arr ; arr = nullptr;}
        int getByIndex(int index){
            if (index >=0)
            return arr[index];
            return -1;
            }
        int getSize(){
            return this->size;
            }
            int getCapacity(){
            return this->capacity;
            }
        void setVal(int index,int value){
             if (index >=capacity)
                cout << "Index out of range";
             // if acceptable value
             this->arr[index]= value;
            }
        int find(int value)
            {
                for( int i=0 ; i < getSize(); ++i)
                        if (  arr[i] == value)
                            return i;
                return -1;
            }
        void print()
            {
                for( int i=0 ; i<getSize(); ++i)
                    cout << arr[i]<<" ";
                    cout<< endl;
            }
        int getFront(){
            return arr[0];
            }
            int getBack(){
            return arr[size-1];   // don't forget to do minus 1
            }
            // let's push_back[[ version 1.0 ]]
            // 1-Always create other bigger *arr2
            // 2- copy
            // 3- append item at [size]
            // 4-swap (to swap pointers) to keep arr1 in charge
            // 5-delete[]arr2
            // dismiss this section now :
            //..
//        void push_back_noCapacityTrick(int value){
//            int *arr2 = new int [size+1];// steps = size +1
//            //copy
//            for(int i=0 ; i<size;++i) // size steps
//                arr2[i] =arr[i];
//            arr2[size++] = value; //2 steps
//          //size++; // in previous step we increased size and added the newValue
//            swap(arr2, arr);// 3 steps
//            delete [] arr2;
//            }
            // ..
// this push_back has o(n) operation [[ LINEAR ]]
        // create new *ptr
        // copy elememnts from 0 to newsize index -1 to arr
        // swap pointers
        // delete nd ptr
        void push_back_capacityTrickApplied(int val){
        // don't worry this method is used to append , which means you will use it
        //to add to end using the new approach :
        //size here will be linked to number of elements not total chairs
            if(size == capacity){
                // Expand capaicty
                capacity*=2;
                int *arr2 = new int[capacity];
                for(int i=0 ; i<size;++i)
                    arr2[i]= arr[i];
                swap(arr2,arr);
                delete [] arr2;
            }
            // will always happen
            // here I mean the two operations of:
            // [1] size++
            //[2] assigning the new value;
                arr[size++]= val;
                // here size is equal to total number of elements  1 2 3 etc
        }
        void resize(int newSize){
            int *arr2 = new int [newSize];
            for(int i=0 ; i<newSize;++i){
                arr2[i] = arr[i];
            }
            swap(arr2,arr);
            delete [] arr2;
            }
            // insertion is based on shifting elements
            // we shift from end to beginning >> but why?

    //            void insert(int index,int val){
    //            int *arr2 = new int [size*2];
    //            for(int i =0 ; i< size+1;++i){

    //                }// end for loop
      //      }// end insert func

};

int main()
{
   return 0;
}
