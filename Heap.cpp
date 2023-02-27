#include <iostream>
#include"MinHeap.h"
#include"MaxHeap.h"
using namespace std;


int main()
{
	/*MinHeap<int> b1(6);
	b1.insert(6);
	b1.insert(33);
	b1.insert(21);
	b1.insert(40);
	b1.insert(50);
	b1.insert(27);
	b1.insert(66);
	b1.insert(81);
	b1.insert(75);
	b1.remove(40);
	b1.display();
	b1.convertToMax();
	b1.display();
	cout <<endl <<  b1.getMinValue();*/

	MaxHeap<int> b1(6);
	b1.insert(6);
	b1.insert(33);
	b1.insert(2);
	b1.insert(40);
	b1.insert(50);
	b1.insert(27);
	b1.insert(66);
	b1.insert(81);
	b1.insert(75);
	cout << endl << b1.getMaxValue();
	cout << endl;
	b1.remove(40);
	b1.display();
	b1.convertToMin();
	b1.display();

}