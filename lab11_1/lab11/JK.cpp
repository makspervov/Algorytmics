#include "lista.h"
#include <iostream>

using namespace std;

void add_tail_JK(single_list&l, int value){
    element_JK *el = new element_JK;
    el->number  = value;
    el->next    = l.head;

    if(l.tail != nullptr){
        l.tail->next = el;
    }
    else{
        l.head = el;
    }
    l.tail = el;
    l.counter++;
}
void add_head_JK(single_list&l, int value){
    element_JK *el = new element_JK;
    el->number  = value;
    el->next    = l.tail;
    l.head      = el;
    if (l.tail == nullptr)
        l.tail = el;
    else
        l.tail->next = l.head;
    l.counter++;
}

void add_position_JK(single_list &l, int value, int position){
    element_JK *el = new element_JK;
    el->number  = value;
    element_JK *temp = l.head;
    int i = 1;
    for(; i < position-1; i++)
        temp = temp->next;

    el->next=temp->next;
    temp->next=el;
    l.counter++;
}
void delete_tail_JK(single_list &l){
    l.counter--;
    element_JK *temp = l.tail;
    if(l.counter == 1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        element_JK *bef_temp = l.head;
        for(int i=1; i<l.counter-1; i++)
            bef_temp=bef_temp->next;

        l.tail=bef_temp;
        l.tail->next=l.head;
    }
    delete temp;
}
void delete_head_JK(single_list &l){
    l.counter--;
    element_JK *temp = l.head;
    l.head = l.head->next;
    if (l.counter == 1){
        l.tail = nullptr;
    }
    delete temp;

}
void delete_position_JK(single_list &l, int position){
    l.counter--;
    element_JK *prev = l.head;
    for(int i=1; i<position-1; i++)
        prev = prev->next;
    element_JK *temp = prev->next;
    prev->next = temp->next;
    delete temp;

}
void show_JK(single_list l){
    element_JK *temp = l.head;
    cout << "Lista jednokierunkowa\n";
    for (int i = 1; i<=l.counter-1; i++){
        cout << i << " - " << temp->number << endl;
        if(!isEmpty_elementJK(*temp))
            temp=temp->next;
    }
}

int srA_JK(single_list l){
    int srA = 0;
    element_JK *temp = l.head;
    for (int i = 1; i<=l.counter-1; i++){
        srA += temp->number;
        if(!isEmpty_elementJK(*temp))
            temp=temp->next;
    }
    return srA/(l.counter-1);
}
int max_JK(single_list l){
    int max = 0;
    element_JK *temp = l.head;
    for (int i = 1; i<=l.counter-1; i++){
        if(max<temp->number)
            max = temp->number;

        if(!isEmpty_elementJK(*temp))
            temp=temp->next;
    }
    return max;
}

bool isEmpty_elementJK(element_JK el){
    if (el.next == nullptr)
        return true;
    return false;
}
bool isEmpty_lista_JK(single_list l){
    if (l.tail == nullptr && l.head == nullptr)
        return true;
    return false;
}
