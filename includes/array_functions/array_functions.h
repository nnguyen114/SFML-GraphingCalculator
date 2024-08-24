
#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <iostream>
using namespace std;

const int MINIMUM_CAPACITY = 3;

template<typename T>
void print(T* a, int how_many){
    T *walker=a;// set walker to walk through the array so that *a doesnt have to leave
    for (int i=0; i<how_many; i++)
    {
        cout<<" "<< *walker<< " "; //cout the value at that index
        walker++;// moving to the next index
    }
}


template<typename T>
void print_array(T *a, int size, int capacity=0){ 
   cout<< "("<<size<<"/"<<capacity<<") ";// simply cout the size and capacity in (/) form
   print(a,size);
   cout<<endl;
}



template <class T>
int search(T* a, int size, const T& find_me){
    T *walker=a; // search for target at an index
    for (int i=0; i<size; i++){
        if (*walker==find_me){// if it's equal to
            return i; //returning index of that value
        } walker++;
    } return -1;//if can't find return -1
}

template<class T>
T* search_entry(T* a, int size, const T& find_me){
    T *walker=a; //search for the address of the target
    for (int i=0; i<size; i++){
        if (*walker==find_me){ //same concept as before but return the address instead of the index
            return walker;
        } walker++;
    } return nullptr;} // since it's a pointer, can't return -1
    
template <class T>
void shift_left(T* a, int& size, int shift_here){
  T*w1=a; // set two walkers, one at the value shifting and one in front
  T*w2=a; // in front
  T*w3=a+size-1;// indicate the end of the array
  w1=w1+shift_here; // move this to value want to shift
  w2=w2+(shift_here+1); // value in front of the one to shift
  
    while(w1!=w3 && size!=0){ // as long as w1!= to the end of the array
        *w1=*w2; // copy and paste, *w1 take value of *w2
        w1++; // move up 
        w2++; // move up
    }size--; // decrease size
  
  
  //print(a,size);
}

template <class T>
void shift_left(T* a, int& size, T* shift_here){
    int address=shift_here-a;
    shift_left(a, size, address);// address of index of target - address of the start of the array
}           //the difference = the index of the value to shift

template <class T>
void shift_right(T *a, int &size, int shift_here){
  T*w1=a+shift_here-1; // go to the location in front of the target value
  T*w3=a+size-1;// the end of array
  T* w2=w3+1;// one index pointing after the end
  while(w1!=w3 && size!=0){// keep going until it hit the value before the target
     *w2=*w3; // w2 takes the value of w3
      w2--; // move down the array
      w3--;// moved down 
  } size++;
  //print(a,size);
}

template <class T>
void shift_right(T* a, int& size, T* shift_here){
    int address=shift_here-a;
    shift_right(a, size, address);
}


template <class T>
string array_string(const T *a, int size){
    string s="";// empty string
    const T *walker= a;// walker to read the array
    if (isalpha(*walker)){// if walker detects characters
        for (int i=0; i<size; i++){
          s += *walker;// run loop to convert string to char
        walker++;} }
    else 
        for (int i=0; i<size; i++){ // else run loop convert string to int
          s += to_string(*walker);
          walker++;
    }
    return s;}// return string

 

template<class T>
T* allocate(int capacity= MINIMUM_CAPACITY){// creating a empty new array 
   T *Array= new T [capacity];
   return Array;
    }                                   

template<class T>
void copy_array(T *dest, const T* src, int many_to_copy){
  const T *walker = src;// set the old array to a walker
   T *walker2 = dest; // set the new empty array to a walker
    for (int i=0; i<many_to_copy; i++){
       *walker2=*walker;// copy the old into the new
        walker++;// move forward along the index
        walker2++;
    }
}

template <class T>
T* copy_array(const T *src, int size){
  T* dest= allocate<int>(size);// creating a new empty array 
  copy_array(dest,src,size);// call copy to perform the copy and paste of new and old array
  return dest;// return the new array
}

template<class T>
T* reallocate(T* a, int size, int capacity){
    T *NewArray=new T [capacity];// create an empty array 
    copy_array(NewArray, a, size);// call the function to transfer over 
    delete[] a;// releasing the old array since we're done with it
    a=NULL;
    return NewArray;// return the new just tranferred array
}

template<class T>
void _append(T* a, int &size, T element){
 a+=size;
 *a=element;
 size++;
}

template<class T>
void _array_init(T* a, int &size, int x){
    T* arraywalker=a;
    for (int i=0; i < size; i++){
        *arraywalker=x;
        arraywalker++;
    }
}


#endif                                                        