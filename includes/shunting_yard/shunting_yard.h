#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H
#include <iostream>
#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"


using namespace std;

class ShuntingYard{

    public:
    template <typename T>
        class Iterator{
    public:
        friend class ShuntingYard;          //give access to list to access _ptr
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

ShuntingYard(){}
ShuntingYard(Queue<Token*> _postfix):postfix_(_postfix)
    {}

Queue<Token*>infix(Queue<Token*> _postfix){
    return postfix_=_postfix;
}

Queue<Token*> postfix(){
return shuntingyard();
}

Queue<Token*> postfix(const Queue<Token*>& _postfix){
    postfix_ = _postfix;
    return shuntingyard();
}

Queue<Token*>shuntingyard(){
    Queue<Token*> q;
    Stack<Token*> s;
    Queue<Token*>::Iterator walker=postfix_.begin();
    while (walker!=nullptr){
        int type= (*walker)->type();
        if (type==1){
            q.push(*walker);
        }
        else if (type==2){// check prec before push to stack 
            if(!s.empty()){
                while(static_cast<Operator*>(s.top())->Prece_Type() >= static_cast<Operator*>(*walker)->Prece_Type()){
                    q.push(s.pop());
                    if(s.empty())
                        break;
                }

                s.push(*walker);
            }

            else {
                s.push(*walker);
            }
        }
        else if (type==3){
             s.push(*walker);
             
        }
        else if (type==4){
              if(!s.empty()){
                 while (static_cast<Token*>(s.top())->type()!=3){
                   assert(!s.empty()); 
                    q.push(s.pop());
                     if(s.empty())
                         break;
                 }
              } 
              if (static_cast<Token*>(s.top())->type()==3){
                s.pop();
              }
              
        }

            walker++;
    }
       
    
    // if stack is not empty, pop everything and put them into queue
    if(!s.empty()){
        Stack<Token*>::Iterator stackwalker=s.begin();
        while (stackwalker!=nullptr){
            q.push(*stackwalker);
            stackwalker++;
        }
    }
   
     return q;

    }



private:

Queue<Token*> postfix_;

};
#endif