#include "Graph.h"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

void print(int num) { cout << num << " "; }

int main()
{
	int numOfVer, numOfEdges;
	char answer;
	bool isDir, isEulerian;
	list<int> euler;

	cout << "Is the graph directed : y / n" << endl;
	cin >> answer >> numOfVer >> numOfEdges;
	isDir = (answer == 'y');

	Graph g(numOfVer, numOfEdges, isDir);

	for (int i = 1; i <= numOfEdges; i++)
	{
		int in, out;

		cin >> in >> out;
		g.AddEdge(in, out);
	}

	isEulerian = g.Euler(euler);
	if (isEulerian)
	{
		cout << "The graph is aulerian" << endl;
		for_each(euler.begin(), euler.end(), [](int n) { cout << n << " "; });
	}

	return 0;
}