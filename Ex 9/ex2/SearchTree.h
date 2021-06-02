#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{
public:
	//public methods
	void add(T value) override;
	bool  search (T value) override
	{
		return search(Tree<T>::root, value);
	}

	void remove(T val) override;
	T successor(T val);
	void deleteDuplicates();

private:
	//privates methods
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);

	typename Tree<T>::Node* remove(typename Tree<T>::Node* current, T val);
	void deleteDuplicates(typename Tree<T>::Node* current);
	T successor(typename Tree<T>::Node* current, T val);

};

//this func, receive a val and add it to the tree
template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}
//this func, call the remove function
template<class T>
void SearchTree<T>::remove(T val)
{
	Tree<T>::root = SearchTree<T>::remove(Tree<T>::root,val);
}
//this func call the successor function
template<class T>
T SearchTree<T>::successor(T val)
{
	try
	{
		return successor(Tree<T>::root, val);
	}
	catch (const char* str)
	{
		throw "no successor";
	}
}
//this func call the deleteDuplicates function
template<class T>
void SearchTree<T>::deleteDuplicates()
{
	deleteDuplicates(Tree<T>::root);
}
//this func, receive a node of a tree and a val, and add the val to the tree
template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	//if val is smaller than node val, go the left of the tree
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	//if val is bigger or equal than node val, go the right
	else
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}
//this func, receive a node of a tree and a val, and return true or false of the val is in the tree
template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}
//this func, receive a node of a tree and a val, and remove the node from the tree
template<class T>
typename Tree<T>::Node* SearchTree<T>::remove(typename Tree<T>::Node* current, T val)
{
	//the val is not in the tree
	if (current == NULL)
		return current;

	//the val is smaller than the node val
	if (current->value > val)
	{
		current->left = remove(current->left, val);
		return current;
	}
	//the val is bigger than the node val
	else if (current->value < val)
	{
		current->right = remove(current->right, val);
		return current;
	}
	if (current->left == NULL)
	{
		typename Tree<T>::Node* temp = current->right;
		delete current;
		return temp;
	}
	else if (current->right == NULL)
	{
		typename Tree<T>::Node*  temp = current->left;
		delete current;
		return temp;
	}
	else {

		typename Tree<T>::Node* succParent = current;

		typename Tree<T>::Node* succ = current->right;
		//search the succesor of the node
		while (succ->left != NULL)
		{
			succParent = succ;
			succ = succ->left;
		}
		if (succParent != current)
			succParent->left = succ->right;
		else
			succParent->right = succ->right;

		current->value = succ->value;

		delete succ;
		return current;
	}
}
//this func, receive a node of a tree and remove all the duplicates val from this tree
template<class T>
void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current)
{
	static QueueVector<T> q(50);
	if (current)
	{	//enter all the values of the tree into a queue
		deleteDuplicates(current->left);
		q.enqueue(current->value);
		deleteDuplicates(current->right);
	}
	if (current == Tree<T>::root)
	{
		//check all the duplicates values that are in the queue
		//and remove these values from the tree

		T val1, val2;
		if (!q.isEmpty())
			val1 = q.dequeue();

		while (!q.isEmpty())
		{
			val2 = q.dequeue();
			if (val1 == val2)
				remove(val1);
			val1 = val2;
		}
	}
}
//this func, receive a node of a tree and a value, and return the successor of this value in this tree
template<class T>
inline T SearchTree<T>::successor(typename Tree<T>::Node* current, T val)
{
	//no successor
	if (current == NULL)  
		throw "no successor";

	if (current->value == val)
	{
		typename Tree<T>::Node* suc = NULL;
		if (current->right != NULL)
		{
			typename Tree<T>::Node* tmp = current->right;
			while (tmp->left)
				tmp = tmp->left;
			suc = tmp;

			if (suc != NULL)
				return suc->value;
			throw "no successor";
		}
		else {   
			typename Tree<T>::Node* successor = NULL;
			typename Tree<T>::Node* ancestor = Tree<T>::root;
			while (ancestor != current) {
				if (current->value < ancestor->value) {
					successor = ancestor;
					ancestor = ancestor->left;
				}
				else
					ancestor = ancestor->right;
			}
			if (successor != NULL)
				return successor->value;
			throw "no successor";
		}
	}

	if (current->value > val)
		successor(current->left, val);
	else 
		successor(current->right, val);
}
