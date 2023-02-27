#pragma once
#include <iostream>
using namespace std;

template<typename T>
class MaxHeap
{
	int maxHeight;
	T* data;
	int nodesCount = 0;
	int index = 0;
public:
	MaxHeap()
	{

	}
	MaxHeap(int h)
	{
		maxHeight = pow(2, h) - 1;
		data = new T[maxHeight];

	}
	T getMaxValue()
	{
		if (data[0])return data[0];
	}
	void insert(T val)
	{
		data[nodesCount] = val;
		int x = nodesCount + 1;
		if (x > 1 && data[x - 1] > data[(x / 2) - 1])
		{
			while (x > 1 && data[x - 1] > data[(x / 2) - 1])
			{
				swap(data[x - 1], data[(x / 2) - 1]);
				x = x / 2;
			}
		}
		nodesCount++;
		index++;
	}

	int search(int i, T key)
	{
		int status = -1;
		if (data[i] == key)status = i;

		if (status == -1 && 2 * i + 1 < maxHeight)
			status = search(2 * i + 1, key);

		if (status == -1 && 2 * i + 2 < maxHeight)
			status = search(2 * i + 2, key);

		return status;
	}
	void increase_value(int i, int val)
	{
		data[i] = val;
		while (i != 0 && data[(i - 1) / 2] < data[i])
		{
			swap(data[i], data[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void remove_max()
	{
		data[0] = data[--nodesCount];
		removeMax(0);

	}
	void removeMax(int i)
	{

		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < nodesCount || r < nodesCount)
		{
			if (data[l] > data[r])
			{
				swap(data[i], data[l]);
				removeMax(l);
			}
			else
			{
				swap(data[i], data[r]);
				removeMax(r);
			}
		}
	}
	void remove(T val)
	{
		int index = search(0, val);
		if (index == -1)return;
		increase_value(index, INT_MAX);
		remove_max();
	}
	void display()
	{
		for (int i = 0; i < nodesCount; i++)
		{
			cout << data[i] << " ";
		}cout << endl;
	}
	//heapsort
	void convertToMin()
	{
		for (int i = nodesCount / 2; i >= 0; i--)
			heapify(i);
	}
	void heapify(int a)
	{
		int l = 2 * a;
		int r = 2 * a + 1;
		int min = a;
		if (l < nodesCount && data[min] > data[l])
			min = l;
		if (r < nodesCount && data[min] > data[r])
			min = r;
		if (min != a)
		{
			swap(data[min], data[a]);
			heapify(min);
		}

	}
};