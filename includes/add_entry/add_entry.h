
#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include <iostream>
using namespace std;

#include "../../includes/array_functions/array_functions.h"



template<typename T>
T* add_entry(T* list, const T& new_entry,int& size, int& capacity){// add entry function
if (size>=capacity){// check for size first
    capacity *= 2;
    list = reallocate(list,size,capacity);
}
_append(list, size, new_entry);// add element to the back
return list;

} 



template<class T>
T* remove_entry(T* list, const T& delete_me,int& size, int& capacity){// remove entry
    T* target= search_entry(list, size, delete_me);// search for the value by using search
    shift_left(list,size,target); // shift left when found
    if (size <= capacity*1/4){// decrease the size when it reaches 1/4 capacity
        capacity/=2;
        list = reallocate(list,size,capacity);}// reallocate
        return list;
}


template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity){
    T* last_entry=(list+size-1); // pointer, set to the end of the array
    popped=*last_entry;// derif to the value of popped
     shift_left(list,size,last_entry); // shift left
    if (size <= capacity*1/4){ // change size
        capacity/=2;
        list = reallocate(list,size,capacity);}
        return list;

}


template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here,int &size,int &capacity){
if (size>=capacity){ // check for size
    capacity *= 2;
    list = reallocate(list,size,capacity); // rallocate
}
    shift_right(list,size,insert_here); // shifr right to create a gap
    T* insert= list+insert_here; // move insert to the posistion of the gap
    *insert=insert_this; // replace that gap with insert this
    return list;
}

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity){ //set pointer to the location of erase
    T* pointer=list+index;
    shift_left(list,size, pointer); // shift left to erase
    if (size <= capacity*1/4){ // check size
        capacity/=2;
        list = reallocate(list,size,capacity);}
        return list;
}

#endif