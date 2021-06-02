#pragma once
#include <iostream>
#include "QueueVector.h"
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	//virtual methods
	virtual void process(T val) { cout << val; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;
	//methods
	int height();
	void reflect();
	void breadthScan();

private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

	int height(Node* current);
	void reflect(Node* current);

};
//destrutcor
template <class T>
Tree<T>::~Tree() 
{
	if (root != NULL)
		clear(root);
}
//this func call the height func
template<class T>
int Tree<T>::height()
{
	return Tree<T>::height(root);
}
//this func call the reflect func
template<class T>
void Tree<T>::reflect()
{
	Tree<T>::reflect(root);
}

//this func, receive a node of a tree and print all the tree in a breadth scan
template<class T>
void Tree<T>::breadthScan()
{
	if (root == NULL)  return;

	QueueVector<Node*> q(50);

	q.enqueue(root);

	while (q.isEmpty() == false)
	{
		Node* node = q.front();
		cout << node->value << " ";
		q.dequeue();

		if (node->left != NULL)
			q.enqueue(node->left);

		if (node->right != NULL)
			q.enqueue(node->right);
	}
}
//this func, receive a node of a tree and clear all the tree
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}
//this func retru  of the tree is empty or not
template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}
//this func, receive a node of a tree and return the height of the tree
template<class T>
int Tree<T>::height(Node* current)
{
	if (current == NULL)
		return -1;
	return max(Tree<T>::height(current->left), Tree<T>::height(current->right)) + 1;
}

//this func, receive a node of a tree and interchange all the right side with the left side of the tree
template<class T>
inline void Tree<T>::reflect(Node* current)
{
	typename Tree<T>::Node* tmp;
	if (current)
	{
		reflect(current->left);
		reflect(current->right);
		tmp = current->right;
		current->right = current->left;
		current->left = tmp;
	}
}
