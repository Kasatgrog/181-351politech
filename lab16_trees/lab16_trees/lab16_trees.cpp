// lab16_trees.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программ
#include "pch.h"
#include <iostream>
using namespace std;
template<typename T>
class myTree 
{
	struct Node 
	{
		T item;
		Node *son;
		Node *bro;

		Node(T i, Node *s = NULL, Node *b = NULL) 
		{
			item = i;
			son = s;
			bro = b;
		}
	};
	Node *root;
public:
	myTree() 
	{
		root = NULL;
	}
	~myTree() 
	{
		Delete(root);
	}
	int GetHeight() 
	{
		return GetHeight(root);
	}
	int GetNodesOnLevel(int level) 
	{
		return GetNodesOnLevel(root, level);
	}
	void add(const T &elem) 
	{
		add(root, elem);
	}
	void print() 
	{
		print(root);
	}
	void printSon() 
	{
		printSon(root);
	}
	void printBro() 
	{
		printBro(root);
	}
private:
	void add(Node *&node, const T &elem);
	void print(Node *&node);
	void printSon(Node *&node);
	void printBro(Node *&node);
	void Delete(Node *node);
	int GetHeight(Node *node);
	int GetNodesOnLevel(Node *node, int level);
};
///////////////////////////////////////////////////////
int main() {
	myTree<int> tree;
	int n, a;
	cout << "Count" << std::endl;
	cin >> n;
	cout << endl << "Elements" << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> a;
		tree.add(a);
	}
	cout << endl << "Tree" << endl;
	tree.print();

	system("pause");
	return 0;
}

template<typename T>
void myTree<T>::add(Node *& node, const T & item)
{
	if (node == NULL) 
	{
		node = new Node(item);
	}
	else if (item < node->item) 
	{
		add(node->son, item);
	}
	else 
	{
		add(node->bro, item);
	}
}

template<typename T>
void myTree<T>::print(Node *& node)
{

	printBro();
	cout << endl;
	printSon();
}

template<typename T>
void myTree<T>::printSon(Node *& node)
{
	if (node != NULL) 
	{
		if (node->son != NULL) 
		{
			printBro(node->son);
		}
		if (node->bro != NULL) 
		{
			printSon(node->bro);
		}
		else cout << endl;
		printSon(node->son);
	}
}

template<typename T>
void myTree<T>::printBro(Node *& node)
{
	if (node != NULL) 
	{
		cout << node->item << '\t';
		if (node->bro != NULL) 
		{
			printBro(node->bro);
		}
		else cout << '\t';
	}
}

template<typename T>
void myTree<T>::Delete(Node * node)
{
	if (node) 
	{
		Delete(node->son);
		Delete(node->bro);
		delete node;
	}
}

template<typename T>
int myTree<T>::GetHeight(Node * node)
{
	if (node == NULL)
		return 0;
	int max = 0;
	for (Node *current = node->son; current; current = current->bro) 
	{
		int curHeight = GetHeight(current);
		if (curHeight > max)
			max = curHeight;
	}
	return max + 1;
}

template<typename T>
int myTree<T>::GetNodesOnLevel(Node * node, int level)
{
	if (node == NULL)
		return 0;
	if (level <= 0)
		return 0;

	return GetNodesOnLevel(node->son, level - 1) +
		(level == 1) +
		GetNodesOnLevel(node->bro, level);
}