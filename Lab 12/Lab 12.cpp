#include <iostream>
#include <locale.h>

using namespace std;

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
	if (temp2!=nullptr)
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
	setlocale(LC_CTYPE, "Polish");

	node* tree = nullptr;
	int buf;

	unsigned int opcja;
	bool wyjscie = false;
	cout << "Pervov Maksym, GL13" << endl << "Podstawy Algorytmiki" << endl << "Menu:" << endl;
	do
	{
		cout << endl << "1. Sprawdzenie, czy drzewo jest puste" << endl
					 << "2. Dodanie nowego wêzla do drzewa" << endl
					 << "3. Sprawdzenie, czy klucz o podanej wartoœci wêzla przez u¿ytkownika znajduje siê w drzewie" << endl
					 << "4. Wyœwietlenie drzewa - preorder" << endl
					 << "5. Wyœwietlenie drzewa - inorder" << endl
					 << "6. Wyœwietlenie drzewa - postorder" << endl
					 << "7. Usuniêcie ca³ego drzewa" << endl
					 << "0. Wyjœcie z programu" << endl;

		cout << endl << ">>>>>>>> ";
		cin >> opcja;
		switch (opcja)
		{
		case 1:
			if (isEmpty(tree))
				cout << "Drzewo jest puste" << endl;
			else
				cout << "Drzewo cos zawiera. Ale co?" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Wprowadz wartosc: " << endl;
			cin >> buf;
			if (find_node(tree, buf) == nullptr)
			{
				cout << "Stan przed: " << endl;
				inorder(tree);
				cout << endl;
				add_node(buf, tree);
				cout << "Stan po: " << endl;
				inorder(tree);
				cout << endl;
			}
			else
				cout << "Juz istnije" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Wprowadz wartosc: " << endl;
			cin >> buf;
			if (find_node(tree, buf) == nullptr)
				cout << "Nie ma" << endl;
			else
				cout << "Jest" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			preorder(tree);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			inorder(tree);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			postorder(tree);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "Wprowadz wartosc: " << endl;
			cin >> buf;
			if (find_node(tree, buf) != nullptr)
			{
				cout << "Stan przed: " << endl;
				inorder(tree);
				cout << endl;
				delete_node(tree, find_node(tree, buf));
				cout << "Stan po: " << endl;
				inorder(tree);
				cout << endl;
			}
			else
			cout << "Nie istnieje" << endl;
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "Do widzenia! :)" << endl;
			system("pause");
			return 0;
		}
	} while (!wyjscie);
}
