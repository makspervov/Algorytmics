//солянка из лабораторок

#include <cstdlib> // 11 лаба
#include <time.h> // 11 лаба
#include <iostream> // стандартное начало
#include <fstream> // 10 лаба
#include <locale.h> //языковой параметр

using namespace std; // чтобы не использовать ебучие std::cout и т.д.

void WczytywanieZPliku(int* tab, int n, string nazwa_pliku) 
{
    ifstream odczyt;
    odczyt.open(nazwa_pliku.c_str());
    odczyt >> n;
    tab = new int[n];
    for (int i = 0; i < n; i++)
        odczyt >> tab[i];
    odczyt.close();
}


// Lab 9 (stos)

struct element
{
	int number;
	element* next;
};

void push_stos(element*& stos, int wartosc)
{
	element* el = new element;
	el->number = wartosc;
	el->next = stos;
	stos = el;
}

void pop_stos(element*& stos)
{
	if (stos == nullptr)
	{
		cout << "Stos jest pusty!" << endl;
	}
	element* temp = stos;
	stos = stos->next;
	delete temp;
}

bool czyPusty_Stos(element* stos)
{
	if (stos == nullptr)
	{
		cout << "Stos jest pusty" << endl;
		return true;
	}
	else
	{
		cout << "Stos cos zawiera" << endl;
		return false;
	}
}

int top_stos(element* stos)
{
	return stos->number;
}

// Lab 10 (kolejka)

struct element
{
	char character;
	element* next;
};

struct queue
{
	element* head;
	element* tail;
};

void wczytaj()
{
	ifstream plik;
	plik.open("lab10_tekst.txt");


	plik.close();
}

void push(queue& q, char value)
{
	element* el = new element;
	el->character = value;
	el->next = nullptr;
	if (q.tail != nullptr)
	{
		q.tail->next = el;
	}
	else
	{
		q.head = el;
	}
	q.tail = el;
}

void pop(queue& q)
{
	element* temp = q.head;
	q.head = q.head->next;
	delete temp;
	if (q.head == nullptr)
	{
		q.tail = nullptr;
	}
}

int czyPusty(queue q)
{
	if (q.head == nullptr)
	{
		cout << "Lista jest pusta";
		return 1;
	}
	else
	{
		cout << "Lista nie jest pusta";
		return 0;
	}
}

int pierwszy(queue q)
{
	return q.head->character;
}

// Lab 11 (lista jednokierunkowa)

struct element
{
    int number;
    element* next;
};

struct single_list
{
    element* head;
    element* tail;
    int counter;
};

void add_head(single_list& l, int value)
{
    element* el = new element;
    el->number = value;
    el->next = l.head;
    l.head = el;
    if (l.tail == nullptr) l.tail = el;
}

void add_position(single_list& l, int value, int position)
{
    element* el = new element;
    el->number = value;
    element* temp = l.head;
    for (int i = 1;i < position - 1;i++) temp = temp->next;
    el->next = temp->next;
    temp->next = el;
}

void add_tail(single_list& l, int value)
{
    element* el = new element;
    el->number = value;
    el->next = nullptr;
    if (l.tail != nullptr) l.tail->next = el;
    else l.head = el;
    l.tail = el;
}

void delete_head(single_list& l)
{
    element* temp = l.head;
    l.head = l.head->next;
    if (l.counter == 1) l.tail = nullptr;
    delete temp;
}

void delete_position(single_list& l, int position)
{
    element* prev = l.head;
    for (int i = 1; i < position - 1; i++) prev = prev->next;
    element* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void delete_tail(single_list& l)
{
    element* temp = l.tail;
    if (l.counter == 1)
    {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else
    {
        element* bef_temp = l.head;
        for (int i = 1; i < l.counter - 1; i++)
            bef_temp = bef_temp->next;
        l.tail = bef_temp;
        l.tail->next = nullptr;
    }
    delete temp;
}

int czyPusty(single_list& l)
{
    if (l.head == nullptr)
    {
        cout << "Lista jest pusta";
        return 1;
    }
    else
    {
        cout << "Lista nie jest pusta";
        return 0;
    }
}

void pierwszy(single_list& l)
{
    if (l.head == nullptr) cout << "Lista jest pusta :(" << endl << endl;
    else cout << "Na poczatku lista jest taki znak:" << l.head->number << endl << endl;
}

void ostatni(single_list& l)
{
    if (l.head == nullptr) cout << "Lista jest pusta :(" << endl << endl;
    else cout << "Na koncu tego lista jest taki znak:" << l.tail->number << endl << endl;
}

void show(single_list l)
{
    element* temp = l.head;
    cout << "Lista jednokierunkowa\n";
    for (int i = 1; i <= l.counter - 1; i++) {
        cout << i << " - " << temp->number << endl;
        if (!czyPusty(*temp))
            temp = temp->next;
    }
}

// Lab 11 (lista dwukierunkowa)

struct element
{
    int number;
    element* next;
    element* prev;
};

struct double_list
{
    element* head;
    element* tail;
    int counter;
};

int generatorLiczb() {
    int
        a = 1,
        b = 100;
    return rand() % (b - a + 1) + a;
}

void add_head(double_list& l, int value)
{
    element* el = new element;
    el->number = value;
    el->next = nullptr;
    el->prev = nullptr;
    l.head = el;
    if (l.head != nullptr)
    {
        l.head->prev = el;
        el->next = l.head;
    }
    else l.tail = el;
    l.head = el;
}

void add_position(double_list& l, int value, int position)
{
    element* temp = l.head;
    for (int i = 1;i < position - 1;i++) temp = temp->next;
    element* el = new element;
    el->number = value;
    el->prev = temp;
    el->next = temp->next;
    temp->next->prev = el;
    temp->next = el;
}

void add_tail(double_list& l, int value)
{
    element* el = new element;
    el->number = value;
    el->next = nullptr;
    el->prev = nullptr;
    if (l.tail != nullptr)
    {
        l.tail->next = el;
        el->prev = l.tail;
    }
    else l.head = el;
    l.tail = el;
}

void delete_head(double_list& l)
{
    element* temp = l.head;
    if (l.counter == 1)
    {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else
    {
        l.head = l.head->next;
        l.head->prev = nullptr;
    }
    delete temp;
}

void delete_position(double_list& l, int position)
{
    element* temp = l.head;
    for (int i = 1;i < position - 1;i++) temp = temp->next;
    element* temp_us = temp->next;
    temp->next = temp_us->next;
    temp->next->prev = temp;
    delete temp_us;
}

void delete_tail(double_list& l)
{
    element* temp = l.tail;
    if (l.counter == 1)
    {
        l.tail = nullptr;
        l.head = nullptr;
    }
    else
    {
        l.tail = l.tail->prev;
        l.tail->next = nullptr;
    }
    delete temp;
}

int czyPusty(double_list& l)
{
    if (l.head == nullptr || l.tail == nullptr)
        return 1;
    else
        return 0;
}

bool czyPusty_element(element el)
{
    if (el.next == nullptr)
        return true;
    else
        return false;
}

void show(double_list l, int tryb)
{
    cout << "Lista dwukierunkowa\n";

    if (tryb == 0)
    {
        element* temp = l.head;
        for (int i = 1; i <= l.counter - 1; i++)
        {
            cout << i << " - " << temp->number << endl;
            if (!czyPusty_element(*temp))
                temp = temp->next;
        }
    }
    else
    {
        element* temp = l.tail;
        for (int i = 1; i <= l.counter - 1; i++)
        {
            cout << l.counter - i << " - " << temp->number << endl;
            if (temp->prev != nullptr)
                temp = temp->prev;
        }
    }
}

int min(double_list l)
{
    int min = 0;
    element* temp = l.head;
    for (int i = 1; i <= l.counter - 1; i++)
    {
        if (min > temp->number)
            min = temp->number;

        if (!czyPusty_element(*temp))
            temp = temp->next;
    }
    return min;
}

// Lab 12 (drzewo BST)

struct node
{
    int key;
    node* parent;
    node* left;
    node* right;
};

node* make_node(int value)
{
    node* n = new node;
    n->key = value;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
    return n;
}

void add_node(int value, node*& root)
{
    if (root == nullptr)
    {
        root = make_node(value);
        return;
    }
    node* temp = root;
    while (true)
    {
        if (value >= temp->key)
        {
            if (temp->right == nullptr)
            {
                temp->right = make_node(value);
                temp->right->parent = temp;
                return;
            }
            else temp = temp->right;
        }
        else
        {
            if (temp->left == nullptr)
            {
                temp->left = make_node(value);
                temp->left->parent = temp;
                return;
            }
            else temp = temp->left;
        }
    }
}

void preorder(node* root)
{
    if (root != nullptr)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node*& root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void inorder(node* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

node* find_node(int value, node* root)
{
    while (root != nullptr)
    {
        if (root->key == value)
            return root;
        if (value > root->key)
            root = root->right;
        else
            root = root->left;
    }
    return nullptr;
}

node* find_succesor(node* n)
{
    if (n->right != nullptr)
    {
        n = n->right;
        while (n->left != nullptr)
            n = n->left;
        return n;
    }
    node* temp = n->parent;
    while (temp != nullptr && temp->left != n)
    {
        n = temp;
        temp = temp->parent;
    }
    return temp;
}

void delete_node(node*& root, node* delete_node)
{
    node* temp1, * temp2;
    if (delete_node->left == nullptr || delete_node->right == nullptr)
        temp1 = delete_node;
    else
        temp1 = find_succesor(delete_node);
    if (temp1->left != nullptr)
        temp2 = temp1->left;
    else
        temp2 = temp1->right;
    if (temp2 != nullptr)
        temp2->parent = temp1->parent;
    if (temp1->parent == nullptr)
        root = temp2;
    else
    {
        if (temp1 == temp1->parent->left)
            temp1->parent->left = temp2;
        else
            temp1->parent->right = temp2;
    }
    if (temp1 != delete_node)
        delete_node->key = temp1->key;
    delete temp1;
}

bool isEmpty(node* tree)
{
    if (tree == nullptr)
        return 1;
    else
        return 0;
}

int main()
{
    setlocale(LC_CTYPE, "Polish"); // языковой параметр

    element* stos = nullptr; // 9 лаба

    single_list l; // 11 лаба односторонняя
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;

    double_list l; // 11 лаба двухсторонняя
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 1;

    node* tree = nullptr; // 12 лаба

	system("pause"); //конец программы
	return 0;
}