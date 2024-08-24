#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
using namespace std;

#include "../../includes/node/node.h"

//Linked List General Functions:
    template <typename ITEM_TYPE>
    void _print_list(node<ITEM_TYPE>* head);

    //recursive fun! :)
    template <typename ITEM_TYPE>
    void _print_list_backwards(node<ITEM_TYPE> *head);

    //return ptr to key or NULL
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head,
                                ITEM_TYPE key);


    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head,
                                ITEM_TYPE insert_this);

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,
                                 node<ITEM_TYPE> *after_this,
                                 ITEM_TYPE insert_this);

    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,
                                  node<ITEM_TYPE>* before_this,
                                  ITEM_TYPE insert_this);

    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,
                                  node<ITEM_TYPE>* prev_to_this);

    //delete, return item
    template <typename ITEM_TYPE>
    ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head,
                         node<ITEM_TYPE>* delete_this);

    //duplicate the list...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head);

    //duplicate list and return the last node of the copy
    template <typename T>
    node<T> *_copy_list(node<T>* &dest, node<T> *src);


    //delete all the nodes
    template <typename ITEM_TYPE>
    void _clear_list(node<ITEM_TYPE>*& head);

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos);

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head,       //insert
                                  ITEM_TYPE item,
                                  bool ascending=true);

    //insert or add if a dup
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,
                                          ITEM_TYPE item,
                                          bool ascending=true);
    //node after which this item goes order: 0 ascending
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head,
                                   ITEM_TYPE item,
                                   bool ascending=true);
    //Last Node in the list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head);  
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//Linked List General Functions:
    template <typename ITEM_TYPE>
    void _print_list(node<ITEM_TYPE>* head){
        node<ITEM_TYPE>* p=head; // set a node to head
        while (p!=nullptr){// while node isnt nullptr, keep printing
            cout<<*p;
            p=p->_next;
        }
        cout<<"|||";
        

    }


    //return ptr to key or NULL
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head,
                                ITEM_TYPE key){
    node<ITEM_TYPE>* temp=head;
    while (temp!=nullptr){ // while node isnt nullptr
        if (temp->_item==key){ // keep finding key, if ==
            return temp; // return that ptr
        } temp=temp->_next; // move
    }
    return nullptr; // return nullptr
    }



    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head, ITEM_TYPE insert_this){
       node<ITEM_TYPE>* tempo = new node <ITEM_TYPE> (insert_this);
        tempo->_next = head; // move old head down
        head=tempo; // set new head to tempo
        return tempo; // return the new node 
      }

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,node<ITEM_TYPE> *after_this,
     ITEM_TYPE insert_this){
        if ( head==nullptr){
           return _insert_head(head, insert_this);
        }
        node<ITEM_TYPE>* tempo = new node<ITEM_TYPE> (insert_this); // make new node
        tempo->_next= after_this->_next; // create the connection between the two 
        after_this->_next=tempo; // set the element after to the tempo node
       
        return tempo; // return the node
     }

    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,
                                  node<ITEM_TYPE>* before_this,
                                  ITEM_TYPE insert_this){
        node<ITEM_TYPE>* tempo = new node<ITEM_TYPE> (insert_this);
        node<ITEM_TYPE>* tempprev=_previous_node(head,before_this);
         if ( head==before_this){
           return _insert_head(head, insert_this);// if null ptr insert
        }
        tempo->_next= tempprev->_next; // create a connection for the linked list 
        tempprev->_next=tempo;// previous after = insert element
        return tempo;
         }
        
    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,
                                  node<ITEM_TYPE>* prev_to_this){
        //assert(head);
        //assert(prev_to_this);
        if (head == prev_to_this){
            return nullptr;
        }
        node<ITEM_TYPE>* walker=head; // node to the head
        while( walker->_next != prev_to_this){ // move the node down before it hits the prev to this so that ots before 
            walker = walker->_next;
        }   
        return walker;
 }

 

    //delete, return item
    template <typename ITEM_TYPE>
    ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head,
                         node<ITEM_TYPE>* delete_this){
    node <ITEM_TYPE>* prev_node= _previous_node(head,delete_this);// new node using the value of prev node
    ITEM_TYPE itemholder=delete_this->_item;
    node <ITEM_TYPE>* headholder=head;
        if (prev_node==nullptr){         
            node<ITEM_TYPE>* walker = prev_node; 
            head = head->_next;
            delete walker;
        }
       else {
        node<ITEM_TYPE>* tempo = prev_node->_next; // create a tempo = to previous node
        prev_node->_next=tempo->_next; // set the tempo node array to previous so it doesnt lose whatever comes after
        delete tempo; // delete that one since its not connected anymore
        
        }
        return itemholder;
        
}
    

    //duplicate the list...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head){
        if (head==nullptr){
            return nullptr;
        } 
            node<ITEM_TYPE>* walker = head;// node to the src
            node<ITEM_TYPE>* newhead = nullptr; // new linked list to nithing for now cuz empty
            node<ITEM_TYPE>* walkersec = newhead; // walker for the new node so that it doesnt leave head
        
        while ( walker != nullptr){  // while the old linked list not nulptr
            walkersec=_insert_after( newhead,walkersec,walker->_item); // insert from the old to the new
            walker=walker->_next; // move walker so that it could insert next stuff
        }   
        return newhead; // return new list
    }

    //duplicate list and return the last node of the copy
    template <typename T>
    node<T> *_copy_list(node<T>* &dest, node<T> *src){
        if (src==nullptr){
            return nullptr;
        } 
            node<T>* walker = src;// node to the src
            dest = nullptr; // new linked list to nithing for now cuz empty
            node<T>* walkersec = dest; // walker for the new node so that it doesnt leave head
        
        while ( walker != nullptr){  // while the old linked list not nulptr
            walkersec=_insert_after( dest,walkersec,walker->_item); // insert from the old to the new
            walker=walker->_next; // move walker so that it could insert next stuff
        }   
        return walkersec; // return new list
    }


    //delete all the nodes
    template <typename ITEM_TYPE>
    void _clear_list(node<ITEM_TYPE>*& head){
        node<ITEM_TYPE>* temp=head;
       
        while (head!=nullptr){ // call delete node and clear everything until it hits null  
            _delete_node(head,temp);
            temp=temp->_next;
        }
    }

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos){
        node<ITEM_TYPE>* temp=head; // finding item given the index 
        for (int i=0;i<pos; i++){  
            temp=temp->_next;    
        } 
        return temp->_item;
        assert(temp!=nullptr);
    }
    

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head,       //insert
                                  ITEM_TYPE item,
                                  bool ascending){

        node<ITEM_TYPE>* walker=_where_this_goes(head,item,ascending);
       
       if (walker == nullptr){
        return _insert_head(head, item);
       }
       else {
       return _insert_after(head, walker, item);}
    
  }

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head,
                                   ITEM_TYPE item,
                                   bool ascending){
     

        if(head == nullptr)
        {
            return nullptr;
        }

        else if (ascending){
        node<ITEM_TYPE>* walker=head;
        node<ITEM_TYPE>* walker2=head->_next;

            if(walker->_item > item){
                return nullptr;
            }

            while (walker!=nullptr) {
                if(walker2 == nullptr){
                return walker;}

                else if (walker2->_item>item){ // before it hits the item that bigger than it, insert the element, going down the list 
                    while(walker->_item==walker2->_item){
                        walker=walker->_next;
                        walker2=walker2->_next;
                    }
                  return walker;
                } 
            walker=walker->_next;  
            walker2=walker2->_next; }
        }


        else if (!ascending) {
            node<ITEM_TYPE>* walker=head;
            node<ITEM_TYPE>* walker2=head->_next;
            if(walker->_item < item){
                return nullptr;
            }

            while (walker!=nullptr){
                if(walker2 == nullptr){
                    return walker;}

                else if (walker2->_item<item){ // before it hits the item that bigger than it, insert the element, going down the list 
                    while(walker->_item==walker2->_item){
                        walker=walker->_next;
                        walker2=walker2->_next;
                    }
                    return walker;
                } 
            walker=walker->_next;  
            walker2=walker2->_next; 
            }
        }
            return nullptr;
    }


  template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,
                                          ITEM_TYPE item,
                                          bool ascending){
    node<ITEM_TYPE>* walker=_where_this_goes(head,item, ascending);
    if (walker==nullptr){
        return _insert_head(head, item);
    }
    if (walker->_item==item){
        walker->_item=walker->_item+item;
        return walker;
    }
     return _insert_after(head,walker,item); }



template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head){
        node<ITEM_TYPE>* walker= head;
        while (walker->_next!= nullptr){
            walker=walker->_next;
        }
        return walker;
    }

   
   #endif