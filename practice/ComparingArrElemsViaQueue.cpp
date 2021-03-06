// ComparingArrElemsViaQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>

using namespace std;

#define MAX 100

typedef queue<int> intq;

void printQ(intq q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}


int main()
{
	int n = 0; cout << "Number count: "; cin >> n;
	int arr[MAX];

	int a=0, b=0; 
	cout << "a,b :";
	cin >> a>> b;

	intq q1, q2, q;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] < a)
			q.push(arr[i]);
		else if (arr[i] >= a && arr[i] <= b)
			q1.push(arr[i]);
		else if (arr[i] > b)
			q2.push(arr[i]);
	}
	cout << endl;
	cout << "x < a : ";
	printQ(q);
	cout << "x e [a,b]: ";
	printQ(q1);
	cout << "x > b: ";
	printQ(q2);



    return 0;
}

