#include <iostream>
#include "lista.h"

using namespace std;

int ileEl_DKC(DwuKierunkowaCykliczna &l){
    int e = 0;
    if(isEmpty_lista_DKC(l))
        return e;
    element_DK *p = l.biezacy;
    do{
        e++;
        p = p->next;
    }while(p!=l.biezacy);
    return e;
}

bool isEmpty_lista_DKC(DwuKierunkowaCykliczna l){
    if (l.biezacy == nullptr)
        return true;
    return false;
}

void show_DKC(DwuKierunkowaCykliczna l, short tryb){
    element_DK *temp = l.biezacy;
    cout << "Lista dwukierunkowa\n";
    int i = 1;
    do{
        if (i == 1)
            cout << i << "B -  " << temp->number << endl;
        else
            cout << i << "  -  " << temp->number << endl;
        if (tryb == 0)
            temp=temp->next;
        else
            temp=temp->prev;
        i++;
    }while(temp!=l.biezacy);
}


void add_tail_DKC(DwuKierunkowaCykliczna&l, int value){
    element_DK *end, *el = new element_DK;
    if(l.biezacy == nullptr){
        el->number = value;
        el->next   = el;
        el->prev   = el->next;
        l.biezacy  = el;
        return;
    }
    end = l.biezacy->prev;

    el->next   = end->next;
    el->number = value;
    el->prev   = end;
    end->next  = el;
    end = el;
    end->next->prev = end;
}

void add_head_DKC(DwuKierunkowaCykliczna &l, int value){
    element_DK *el = new element_DK, *end;
    if(l.biezacy == nullptr){
        el->number = value;
        el->next   = el;
        el->prev   = el->next;
        l.biezacy  = el;
        return;
    }
    end = l.biezacy->prev;
    el->number    = value;

    l.biezacy->prev = el;
    el->next     = l.biezacy;

    l.biezacy = el;
    l.biezacy->prev = end;
    end->next = l.biezacy;
}

void delete_za_DKC(DwuKierunkowaCykliczna &l){
    element_DK *el  = l.biezacy->next;
    l.biezacy->next = el->next;
    l.biezacy->next->prev = el->prev;
    if( el->next == el )
        l.biezacy = nullptr;
    delete el;
}

void delete_przed_DKC(DwuKierunkowaCykliczna&l){
    element_DK *pom, *el, *end;
    end = l.biezacy->prev->prev;
    el = end->next;
    pom = el;
    if (el->next == el){
        pom = l.biezacy->next;
        l.biezacy = nullptr;
    }
    else{
        //l.biezacy = el->next;
        end->next = l.biezacy;
        l.biezacy->prev = el->prev;
    }
    delete pom;

}

void delete_biezacy_DKC(DwuKierunkowaCykliczna &l){
    element_DK *pom, *el, *end;
    el = l.biezacy;
    end = l.biezacy->prev;
    pom = el;
    if (el->next == el){
        pom = l.biezacy->next;
        l.biezacy = nullptr;
    }
    else{
        l.biezacy = el->next;
        l.biezacy->prev = el->prev;
        end->next = l.biezacy;
    }
    delete pom;
}

