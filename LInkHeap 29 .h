#pragma once
#include<iostream>
using namespace std;
#include"Stack.h"
template<class T>
struct HNode
{
	T info;
	HNode<T>* right;
	HNode<T>* left;
	HNode() { right = left = nullptr; }
	HNode(T val) { info = val; right = left = nullptr; }
};

template<class T>
class Heap
{
	HNode<T>* root;
	int noOfElements;
	void VLR(HNode<T>* p);
	void getNode(int noOfNodes, Stack<HNode<T>*>& p);

public:
	Heap() { root = nullptr; noOfElements = 0; }
	void insert(T val);
	T getMin();
	T delMin();
	int isEmpty();
	void display() { if (root)VLR(root); }
};
template<class T>
void Heap<T>::getNode(int noOfNodes, Stack<HNode<T>*>& p)
{
	if (noOfNodes / 2 / 2 == 0)
		return;
	getNode(noOfNodes / 2, p);

	if (noOfNodes / 2 % 2 == 0)
		p.push(p.stackTop()->left);
	else
		p.push(p.stackTop()->right);

}
template<class T>
inline void Heap<T>::VLR(HNode<T>* p)
{
	cout << p->info << " ";
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
}
template<class T>
inline void Heap<T>::insert(T val)
{
	noOfElements++;
	if (!root)
	{
		root = new HNode<T>(val);
		return;
	}
	HNode<T>* newNode = new HNode<T>(val);
	Stack<HNode<T>*>stack;
	stack.push(root);
	getNode(noOfElements, stack);
	if (noOfElements % 2 == 0)
		stack.pop()->left = newNode;
	else
		stack.pop()->right = newNode;

	HNode<T>* child = newNode;
	HNode<T>* parent;
	while (!stack.isEmpty())
	{
		parent = stack.pop();
		if (child->info < parent->info)
			swap(child->info, parent->info);
		else
			break;
		child = parent;
	}
}