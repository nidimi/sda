// GameOfTwoStacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int games;
	cin >> games;
	for (int g = 0; g < games; g++)
	{
		int n, m, x;
		cin >> n >> m >> x;
		stack<int> helpA;
		stack<int> a;
		stack<int> helpB;
		stack<int> b;
		stack<int> help;
		int number, sum = 0, score=0;
		for (int i = 0; i < n; i++)
		{
			cin >> number;
			helpA.push(number);
			help.push(helpA.top());
		}
		for (int i = 0; i < m; i++)
		{
			cin >> number;
			helpB.push(number);
		}
		for (int i = 0; i < n; i++)
		{
			a.push(helpA.top());
			helpA.pop();
		}
		for (int i = 0; i < m; i++)
		{
			b.push(helpB.top());
			helpB.pop();
		}

		if (n >= m)
		{
			for (int i = 0; i < n; i++)
			{
				if (i % 2 == 0)
				{
					sum += a.top();
					a.pop();
				}
				else
				{
					if (b.empty())
					{
						sum += a.top();
						a.pop();
					}
					else
					{
						sum += b.top();
						b.pop();
					}
				}
				if (sum > x)
				{
					score = i;
					break;
				}
			}
		}
		else if (n < m)
		{
			for (int i = 0; i < m; i++)
			{
				if (i % 2 == 0)
				{
					sum += b.top();
					b.pop();
				}
				else
				{
					if (a.empty())
					{
						sum += b.top();
						b.pop();
					}
					else
					{
						sum += a.top();
						a.pop();
					}
				}
				if (sum > x)
				{
					score = i;
					break;
				}
			}
		}
		else if (m == 0)
		{
			for (int i = 0; i < n; i++)
			{				
				sum += a.top();
				a.pop();
				if (sum > x)
				{
					score = i;
					break;
				}
			}
		}
		else if (n == 0)
		{
			for (int i = 0; i < m; i++)
			{
				sum += b.top();
				b.pop();
				if (sum > x)
				{
					score = i;
					break;
				}
			}
		}
		cout << score << endl;
	}

    return 0;
}

