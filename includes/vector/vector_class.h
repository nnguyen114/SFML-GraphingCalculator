#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H

#include <iomanip>
#include <cstring>
using namespace std;
#include "../../includes/add_entry/add_entry.h"
#include "../../includes/array_functions/array_functions.h"

template <class T>
class Vector{
public:

    Vector(int capacity=3);
    Vector(T *arr, int size);
    // big three:
    Vector(const Vector &other);
    Vector &operator=(const Vector &rhs);
    ~Vector();
    
    //...
    //member access functions:
    T& operator [](int index);
    const T& operator [](int index) const;

    T& at(int index);              //return reference to item at position index
    const T& at(int index) const;  //return a const item at position index

    T& front();                         //return item at position 0.
    T& back();                          //return item at the last position


    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back
    void push_back(const T& item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_this_index);        //erase item at position
    int index_of(const T& item);             //search for item. retur index.

    //size and capacity:
    void set_size(int size);              //enlarge the vector to this size
    void set_capacity(int capacity);      //allocate this space
    int size() const ; //return _size
    int capacity() const; //return _capacity

    bool empty() const;                    //return true if vector is empty

    //OUTPUT:
    friend ostream& operator <<(ostream& outs, const Vector& _a){
         outs <<"("<< _a._size <<"/"<<_a._capacity<<")\t";
         outs<< "[";
         for(int i = 0; i < _a.size(); i++)
         {  
             outs<<setw(4)<<_a.at(i) <<" ";
         }
         outs<< "]";
         return outs;
     
    }
private:
    int _capacity;
    int _size;
    T* array;

};

template <class T>
Vector<T>::Vector(int capacity ){// allocating private vector
   _size=0;
   _capacity=capacity;// set private variables
   array = allocate<T>(_capacity);// create the vector for private pointer
}

template <class T>
Vector<T>::Vector(T *arr, int size): _size(0), _capacity(3){ // copy the given arrat into the given variable 
  array = allocate<T>(_capacity); // allocate the private pointer with the given sizes from given
  T* arrayWalker = arr; // set walker
  for(int i = 0; i < size; i++, arrayWalker++)
  {
    push_back(*arrayWalker); // push back, add every single element
  }
}

template <class T>
Vector<T>::Vector(const Vector &other){
    _size=other._size; // copy the other array, rhs, into the private array
    _capacity=other._capacity;
    array = allocate <T> (_capacity + 1);
    copy_array(array, other.array,_size);
  }

template <class T>
Vector<T> &Vector<T> ::operator=(const Vector &rhs){
    if (this == &rhs){ // if its the same then dont need to copy, assigning the right hand size to our private
      return *this;
    }
    delete[] array;
    _size=rhs._size;
    _capacity=rhs._capacity;
    array = allocate <T> (_capacity + 1);
    
    copy_array(array, rhs.array, _size);
    return *this;
  }

template <class T>
Vector<T>::~Vector(){ // simply release the private array 
    delete[] array;
  }

template <class T>
T& Vector<T>::operator [](int index){ // location/ object on given index
  T& location=at(index); // assigning the object at the location
  return location;
}

template <class T>
const T& Vector<T>::operator [](int index) const{
  const T& location=at(index);
  return location;
}


template <class T>
T& Vector<T>::at(int index){ // obhect at the given index
  T* walker=array; // set walker
  walker+=index; // move walker to the index 
  return *walker; // deref the walker
}

template <class T>           
const T& Vector<T>::at(int index) const{
  const T* walker=array;
  walker+=index;
  return *walker;
} 

template <class T>
T& Vector<T>::front(){ // set pointer to the front of the array
 T* _begin=array;
 return *_begin; // return that deref pointer 
}  

template <class T>
T& Vector<T>::back(){ // set pointer to the back of the array
 T* _end=(array+_size-1);
  return *_end; // return that deref pointer 
}                         


template <class T>
Vector<T>& Vector<T>::operator +=(const T& item){
   push_back(item); // add item to the back, same as push back 
   return *this; // return the action just did 
}

template <class T>
void Vector<T>::push_back(const T& item){
  array = add_entry(array, item, _size,_capacity ); // normal add entry to the end 
}     //append to the end

template <class T>
T Vector<T>::pop_back(){
  T item; // create a local var to store 
  array=remove_last_entry(array, item, _size, _capacity); // remove that item at the end 
  return item; // return that last item that just got removed 
}                   


//Insert and Erase:
template <class T>
void Vector<T>::insert(int insert_here, const T& insert_this){
  array= insert_entry(array, insert_this, insert_here, _size, _capacity); // insert at given location 
} 

template <class T>
void Vector<T>::erase(int erase_this_index){
  array = erase_entry(array, erase_this_index, _size, _capacity); // erase at given location 
}       

template <class T>
int Vector<T>::index_of(const T& item){
  return search(array, _size, item); // search for index 
}  


//size and capacity:
template <class T>
void Vector<T>::set_size(int size){
  _size=size;
}

template <class T>              
void Vector<T>::set_capacity(int capacity){
  _capacity=capacity;
}   



template <class T>
bool Vector<T>::empty() const{
  if (_size!=0){
    return false;
  }
    return true;
}     


template <class T>
 int Vector<T>::size() const {return _size;}  

 template <class T>
 int Vector<T>::capacity() const {return _capacity;}


#endif