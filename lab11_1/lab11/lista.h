#ifndef LISTA_H
#define LISTA_H

//JednoKierunkowa
struct element_JK{
    int number;
    element_JK* next;
};
struct single_list{
    element_JK* head;
    element_JK* tail;
    int counter;
};

void add_tail_JK(single_list&l, int value);
void add_head_JK(single_list&l, int value);
void add_position_JK(single_list &l, int value, int position);
void delete_tail_JK(single_list &l);
void delete_head_JK(single_list &l);
void delete_position_JK(single_list &l, int position);
void show_JK(single_list l);
bool isEmpty_elementJK(element_JK el);
bool isEmpty_lista_JK(single_list l);
int srA_JK(single_list l);
int max_JK(single_list l);
void allDel_JK(single_list l);

//JednoKierunkowa Cykliczna
struct JednoKierunkowaCykliczna{
    element_JK* biezacy;
};

int ileEl_JKC(JednoKierunkowaCykliczna&l);
void add_tail_JKC(JednoKierunkowaCykliczna&l, int value);
void add_head_JKC(JednoKierunkowaCykliczna&l, int value);
bool isEmpty_lista_JKC(JednoKierunkowaCykliczna l);
void show_JKC(JednoKierunkowaCykliczna l);
void delete_biezacy_JKC(JednoKierunkowaCykliczna&l);
void delete_za_JKC(JednoKierunkowaCykliczna&l);
void delete_przed_JKC(JednoKierunkowaCykliczna&l);


//DwuKierunkowa
struct element_DK{
    int number;
    element_DK* next;
    element_DK* prev;
};

struct double_list{
    element_DK* head;
    element_DK* tail;
    int counter;
};

void add_tail_DK(double_list &l, int value);
void add_head_DK(double_list &l, int value);
void add_position_DK(double_list &l, int value, int position);
void delete_tail_DK(double_list &l);
void delete_head_DK(double_list &l);
void delete_position_DK(double_list &l, int position);
void show_DK(double_list l, int tryb);
bool isEmpty_DK(double_list l);
int min_DK(double_list l);
bool isEmpty_elementDK(element_DK el);

//DwuKierunkowa Cykliczna

struct DwuKierunkowaCykliczna{
    element_DK* biezacy;
};
int ileEl_DKC(DwuKierunkowaCykliczna&l);
void add_tail_DKC(DwuKierunkowaCykliczna&l, int value);
void add_head_DKC(DwuKierunkowaCykliczna&l, int value);
bool isEmpty_lista_DKC(DwuKierunkowaCykliczna l);
void delete_biezacy_DKC(DwuKierunkowaCykliczna&l);
void delete_za_DKC(DwuKierunkowaCykliczna&l);
void delete_przed_DKC(DwuKierunkowaCykliczna&l);
void show_DKC(DwuKierunkowaCykliczna l, short tryb);

#endif // LISTA_H
