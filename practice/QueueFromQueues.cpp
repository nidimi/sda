﻿// QueueFromQueues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

typedef queue<int> intQ;
typedef queue<intQ> queueQ;

void print(queueQ qq)
{
	while (!qq.empty())
	{
		while (!qq.front().empty())
		{
			cout << qq.front().front()<<" ";
			qq.front().pop();
		}
		cout << endl;
		qq.pop();
	}
}

int main()
{
	queueQ qq;
	int n = 0; cout << "Queues number: "; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		intQ q;
		for (int j = i; j <= 2 * i; j++)
			q.push(j);
		qq.push(q);
	}

	print(qq);
	
	/*
	n = 5
	1 2
	2 3 4
	3 4 5 6
	4 5 6 7 8
	5 6 7 8 9 10
	*/


    return 0;
}

