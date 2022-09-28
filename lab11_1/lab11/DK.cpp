#include <iostream>
#include "lista.h"

using namespace std;

void add_tail_DK(double_list &l, int value){
    element_DK *el = new element_DK;
    el->number = value;
    el->next   = l.head;
    el->prev   = l.tail;
    if(l.tail != nullptr){
        l.tail->next = el;
        el->prev     = l.tail;
    }
    else{
        l.head = el;
    }
    l.tail = el;
    l.counter++;
}
void add_head_DK(double_list &l, int value){
    element_DK *el = new element_DK;
    el->number    = value;
    el->next      = nullptr;//l.head
    el->prev      = nullptr;//l.tail

    if(l.head != nullptr){
        l.head->prev = el;
        el->next     = l.head;
    }
    else{
        l.tail = el;
    }
    l.head = el;
    l.head->prev = l.tail;
    l.tail->next = l.head;
    l.counter++;
}
void add_position_DK(double_list &l, int value, int position){
    element_DK *temp = l.head;
    for(int i=1; i<position-1; i++)
        temp=temp->next;
    element_DK *el = new element_DK;
    el->number     = value;
    el->prev       = temp;
    el->next       = temp->next;
    temp->next->prev=el;
    temp->next     = el;
    l.counter++;
}
void delete_tail_DK(double_list &l){
    l.counter--;
    element_DK *temp = l.tail;
    if(l.counter==1){
        l.tail = nullptr;
        l.head = nullptr;
    }
    else{
        l.tail = l.tail->prev;
        l.tail->next=l.head;
    }
    delete temp;
}
void delete_head_DK(double_list &l){
    l.counter--;
    element_DK *temp = l.head;
    if(l.counter==1){
        l.tail = nullptr;
        l.head = nullptr;
    }
    else{
        l.head = l.head->next;
        l.head->prev=l.tail;
    }
    delete temp;
}
void delete_position_DK(double_list &l, int position){
    l.counter--;
    element_DK *temp = l.head;
    for(int i=1; i<position-1; i++)
        temp=temp->next;
    element_DK *temp_us = temp->next;
    temp->next = temp_us->next;
    temp->next->prev = temp;
    delete temp_us;
}
void show_DK(double_list l, int tryb){
    cout << "Lista dwukierunkowa\n";

    if (tryb == 0){
        element_DK *temp = l.head;
        for (int i = 1; i<=l.counter-1; i++){
            cout << i << " - " << temp->number << endl;
            if(!isEmpty_elementDK(*temp))
                temp=temp->next;
        }
    }
    else{
        element_DK *temp = l.tail;
        for (int i = 1; i<=l.counter-1; i++){
            cout << l.counter-i << " - " << temp->number << endl;
            if(temp->prev != nullptr)
                temp = temp->prev;
        }
    }
}
bool isEmpty_elementDK(element_DK el){
    if (el.next == nullptr)
        return true;
    return false;
}
bool isEmpty_DK(double_list l){
    if (l.head == nullptr && l.tail == nullptr)
        return true;
    return false;
}

int min_DK(double_list l){
    int min = 0;
    element_DK *temp = l.head;
    for (int i = 1; i<=l.counter-1; i++){
        if(min>temp->number)
            min = temp->number;

        if(!isEmpty_elementDK(*temp))
            temp=temp->next;
    }
    return min;
}
