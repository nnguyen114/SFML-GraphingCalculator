#ifndef STACK_H
#define STACK_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;

#include "../../includes/linked_list_functions/linked_list_functions.h"


template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;                     //give access to list to access _ptr
        Iterator(){_ptr = nullptr;}                //default ctor
        Iterator(node<T>* p){_ptr =p;}          //Point Iterator to where
                                                //  p is pointing to
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
          }        //friend operator: it++
    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Stack();
    Stack(const Stack<T>& copyMe);
    ~Stack();
    Stack<T>& operator=(const Stack<T>& RHS);
    T top();
    bool empty();
    void push(T item);
    T pop();
    

    friend ostream& operator<<(ostream& outs, 
                                        const Stack& printMe){
        node<T>* walker = printMe._top;
        while (walker != nullptr){
        cout << *walker;
        walker = walker-> _next;
        }
        cout<< "|||"; // run loop so that it prints everything
    return outs;
                    
                                        }

    Iterator begin() const;              //Iterator to the head node
    Iterator end() const;                //Iterator to NULL
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};


template <typename T>
Stack<T>::Stack(){
    _top=nullptr;
    _size=0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& copyMe){
     _size=copyMe._size;
    _top= new node <T>(_size);
    _top=_copy_list(copyMe._top);
}

template <typename T>
Stack<T>::~Stack(){
    _clear_list(_top);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& RHS){
      if (this == &RHS){ // if its the same then dont need to copy, assigning the right hand size to our private
            return *this;
        }
        _clear_list(_top);
     _size=RHS._size;
    _top= new node <T>(_size);
    _top=_copy_list(RHS._top);
    return *this;
}

template <typename T>
T Stack<T>:: top(){
    return _top->_item;
}

template <typename T>
bool Stack<T>::empty(){
    return _top == nullptr;
}

template <typename T>
void Stack<T>::push(T item){
    _insert_head(_top,item);
    _size++;
}

template <typename T>
T Stack<T>::pop(){
    assert (_top!=nullptr);
    node<T>* walker=_top;
    _delete_node(_top,walker);
    _size--;
    return walker->_item;

}

    template <typename T>//Iterator to the head node
    typename Stack <T> :: Iterator Stack <T>:: begin() const{
        return _top;
     }                                    
     
     template <typename T>
     typename Stack <T> :: Iterator Stack <T>:: end() const{
        return nullptr;
     }                     
#endif