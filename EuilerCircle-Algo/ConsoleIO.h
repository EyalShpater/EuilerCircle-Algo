#ifndef __CONSOLE_IO_H_
#define __CONSOLE_IO_H_

#include "Graph.h"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

class ConsoleIO
{
public:
	static void GetUserInput(bool& o_IsDirected, int& o_NumOfVert, int& o_NumOfEdges) noexcept(false)
	{
		char answer;

		cout << "Is the graph directed : y / n" << endl;
		cin >> answer >> o_NumOfVert >> o_NumOfEdges;
		o_IsDirected = (answer == 'y');

		if (answer != 'y' && answer != 'n')
		{
			throw "invalid input";
		}
	}

	static void GetEdgesFromUser(Graph& io_Graph) noexcept(false)
	{
		const int numOfEdges = io_Graph.GetNumOfEdges();
		const int numOfVer = io_Graph.GetNumOfVertices();

		for (int i = 1; i <= numOfEdges; i++)
		{
			int in, out;

			cin >> in >> out;
			if (in < 1 || in > numOfVer || out < 1 || out > numOfVer)
			{
				throw "invalid input";
			}

			io_Graph.AddEdge(in, out);
		}
	}

	static void PrintIfEulerian(Graph& io_Graph)
	{
		bool isEulerian;
		list<int> euler;

		isEulerian = io_Graph.Euler(euler);
		if (isEulerian)
		{
			cout << "The graph is aulerian" << endl << "{ ";
			for_each(euler.begin(), euler.end(), [](int n) { cout << n << " "; });
			cout << "}";
		}
		else
		{
			cout << "The graph is not aulerian" << endl;
		}
	}
};

#endif // !__CONSOLE_IO_H_