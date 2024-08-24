#ifndef QUEUE_H
#define QUEUE_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;

#include "../../includes/linked_list_functions/linked_list_functions.h"


template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        friend class Queue;          //give access to list to access _ptr
        Iterator(){
            _ptr=nullptr;
        }                //default ctor
        Iterator(node<T>* p){
            _ptr=p;
        }       //Point Iterator to where
        //...        
        
        operator bool(){
            if (_ptr!=nullptr){
                return true;
            }
            else {return false;}
        }                               //casting operator: true if _ptr not NULL
                                                        //      this turned out to be a pain!


        T& operator *(){

            return _ptr->_item;
        }                       //dereference operator
        T* operator ->(){
            return &_ptr->_item;
        }                      //member access operator

        bool is_null(){
            if (_ptr==nullptr){
                return true;
            }
            else {
                return false;
            }
        }                                 //true if _ptr is NULL

        friend bool operator !=(const Iterator& left, const Iterator& right){
            return left._ptr != right._ptr;
        } //true if left != right

        friend bool operator ==(const Iterator& left, const Iterator& right){
            return left._ptr == right._ptr;
        } //true if left == right

        Iterator& operator++(){
            _ptr=_ptr->_next;
            return *this;
        }                         //member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator& it,
                                   int unused){
        Iterator hold;
        hold = it;
        it._ptr =it._ptr->_next;
        return hold;
          }        //friend operator: it++                //  p is pointing to
 
    private:
        node<T>* _ptr;               //pointer being encapsulated
    };

    Queue();

    Queue(const Queue<T>& copyMe);
    ~Queue();
    Queue& operator=(const Queue<T>& RHS);

    bool empty();
    T front();
    T back();

    void push(T item);
    T pop();

    Iterator begin() const;            //Iterator to the head node
    Iterator end() const;              //Iterator to NULL
    void print_pointers();
    int size() const;
   

    friend ostream& operator << (ostream& outs, const Queue& printMe){
        node<T>* walker = printMe._front;
        while (walker != nullptr){
        cout << *walker;
        walker = walker-> _next;
        }
        cout<< "|||"; // run loop so that it prints everything
    return outs;
    }
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};

 template <typename T>
 Queue<T>::Queue(){
    _front=nullptr;
    _rear=nullptr;
    _size=0;
 }

template <typename T>
Queue<T>::Queue(const Queue<T>& copyMe){
    _size=copyMe._size;
    _front=_copy_list(copyMe._front);
    _rear=_copy_list(_front, copyMe._front);// try the opther ctor 
}

template <typename T>
Queue<T>::~Queue(){
     _clear_list (_front);
     
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& RHS){
    if (this == &RHS){ // if its the same then dont need to copy, assigning the right hand size to our private
            return *this;
        }
    _clear_list (_front);
    _size=RHS._size;
    _front=_copy_list(RHS._front);
    _rear=_copy_list(_front, RHS._front);
    return *this;
}


template <typename T>
bool Queue<T>:: empty(){
    return _front == nullptr;
}


template <typename T>
T Queue<T>::front(){
    return _front->_item;
}

template <typename T>
T Queue<T>::back(){
    return _rear->_item;
}

template <typename T>
void Queue<T>::push(T item){
    
     if (_front==nullptr){
       _size++;
       _insert_head(_front,item);
       _rear=_front;
     }

     else {
        _rear=_insert_after(_front,_rear,item);
        _size++;
     }
}

template <typename T>
T Queue<T> ::pop(){
    _size--;
    node<T>* walker=_front;
    _delete_node(_front,walker);
    return walker->_item;
}

template <typename T>//Iterator to the head node
typename Queue <T> :: Iterator Queue <T>:: begin() const{
    return _front;
    }                                    
    
template <typename T>
typename Queue <T> :: Iterator Queue <T>:: end() const{
    return nullptr;
    }                   

template <typename T>
void Queue<T>::print_pointers()
{  
    node<T>* walker=_front;
    while ( walker!=nullptr){
    cout<< *walker<<"-->";
    walker++;
    }
}

template <typename T>
int Queue <T> ::size() const {
     return _size; }
#endif