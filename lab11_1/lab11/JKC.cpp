#include <iostream>
#include "lista.h"

using namespace std;

int ileEl_JKC(JednoKierunkowaCykliczna&l){
    int e = 0;
    if(isEmpty_lista_JKC(l))
        return e;
    element_JK *p = l.biezacy;
    do{
        e++;
        p = p->next;
    }while(p!=l.biezacy);
    return e;

}

void add_tail_JKC(JednoKierunkowaCykliczna&l, int value){
    element_JK *el = new element_JK, *pom;
    if(l.biezacy == nullptr){
        el->number  = value;
        el->next    = el;
        l.biezacy   = el;
        return;
    }
    el = l.biezacy;
    int i = 0;
    while(true){
        if (el->next != l.biezacy)
            el=el->next;
        else
            break;
        i++;
    }
    pom = new element_JK;
    pom->next   = el->next;
    pom->number = value;
    el->next = pom;
}

void add_head_JKC(JednoKierunkowaCykliczna&l, int value){
    element_JK *el = new element_JK;
    el->number  = value;

    if(l.biezacy != nullptr){
        el->next = l.biezacy->next;
        l.biezacy->next = el;
    }
    else
        el->next = el;
    l.biezacy = el;

}

void delete_przed_JKC(JednoKierunkowaCykliczna&l){
    element_JK *pom, *el, *end;
    end = l.biezacy, el = l.biezacy->next;
    int i = 0;
    while(true){
        if (el->next != l.biezacy){
            el=el->next;
            end = end->next;
        }
        else
            break;
        i++;
    }
    el = end->next;
    pom = el;
    if (el->next == el){
        pom = l.biezacy->next;
        l.biezacy = nullptr;
    }
    else{
        //l.biezacy = el->next;
        end->next = l.biezacy;
    }
    delete pom;
}

void delete_za_JKC(JednoKierunkowaCykliczna&l){
    element_JK *el  = l.biezacy->next;
    l.biezacy->next = el->next;
    if( el->next == el )
        l.biezacy = nullptr;
    delete el;
}

void delete_biezacy_JKC(JednoKierunkowaCykliczna&l){
    element_JK *pom, *el, *end;
    el = end = l.biezacy;
    int i = 0;
    while(true){
        if (end->next != l.biezacy)
            end=end->next;
        else
            break;
        i++;
    }
    pom = el;
    if (el->next == el){
        pom = l.biezacy->next;
        l.biezacy = nullptr;
    }
    else{
        l.biezacy = el->next;
        end->next = l.biezacy;
    }
    delete pom;
}

void show_JKC(JednoKierunkowaCykliczna l){
    element_JK *temp = l.biezacy;
    cout << "Lista jednokierunkowa\n";
    int i = 1;
    do{
        if (i == 1)
            cout << i << "B -  " << temp->number << endl;
        else
            cout << i << "  -  " << temp->number << endl;
        temp=temp->next;
        i++;
    }while(temp!=l.biezacy);
}


bool isEmpty_lista_JKC(JednoKierunkowaCykliczna l){
    if (l.biezacy == nullptr)
        return true;
    return false;
}
