#pragma once
#include <iostream>
using namespace std;

template<typename T>
class MinHeap
{
	int maxHeight;
	T* data;
	T* timestamp;
	int timecount = 0;
	int nodesCount = 0;
	int index=0;
public:
	MinHeap()
	{

	}
	MinHeap(int h)
	{
		maxHeight = pow(2, h) - 1;
		timestamp = new T[maxHeight];
		data = new T[maxHeight];
		
	}
	T getMinValue()
	{
		if (data[0])return data[0];
	}
	void insert(T val)
	{	
		data[nodesCount] = val;
		timestamp[nodesCount] = timecount++;
		int x = nodesCount+1;
			while (x > 1 && data[x - 1] < data[(x / 2) - 1])
			{
				swap(data[x-1], data[(x/2)-1]);
				swap(timestamp[x - 1], timestamp[(x / 2) - 1]);
				x = x / 2;
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
	void decrease_value(int i, int val)
	{
		data[i] = val;
		while (i != 0 && data[(i - 1) / 2] > data[i])
		{
			swap(data[i], data[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void remove_min()
	{
		data[0] = data[--nodesCount];
		removeMin(0);

	}
	void removeMin(int i)
	{
		
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < nodesCount || r < nodesCount)
		{
			if (data[l] < data[r] || (data[l] == data[r] && timestamp[l]<timestamp[r]))
			{
				swap(data[i], data[l]);
				swap(timestamp[i], timestamp[l]);
				removeMin(l);
			}
			else if (data[l] > data[r] || (data[l] == data[r] && timestamp[l] > timestamp[r]))
			{
				swap(data[i], data[r]);
				swap(timestamp[i], timestamp[r]);
				removeMin(r);
			}
			else if (data[l] < data[r] && data[l] != data[r] )
			{
				swap(data[i], data[l]);
				removeMin(l);
			}
			else if (data[l] > data[r] && data[l] != data[r])
			{
				swap(data[i], data[r]);
				removeMin(r);
			}
		}
	}
	void remove(T val)
	{
		int index = search(0, val);
		if (index == -1)return;
		decrease_value(index, -1);
		remove_min();
	}
	void display()
	{
		for (int i = 0; i < nodesCount; i++)
		{
			cout << data[i] << " ";
		}cout << endl;
	}
	//heapsort
	void convertToMax()
	{
		for (int i = nodesCount / 2; i > 0; i--)
			heapify(i-1);
	}
	void heapify(int a)
	{
		int l = 2 * a+1;
		int r=2*a+2	;
		int max = a;
		if (l<nodesCount && data[max]<data[l])
			max = l;
		if (r<nodesCount && data[max]<data[r])
			max = r;
		if (max != a)
		{
			swap(data[max], data[a]);
			heapify(max);
		}

	}
};