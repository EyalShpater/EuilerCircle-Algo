#include "Graph.h"

#include <iostream>
#include <algorithm>
using namespace std;

void print(int num) { cout << num << " "; }

int main()
{
	//int in, out;
	int numOfVer = 6, numOfEdges = 10;
	bool isDir = false;

	//cin >> numOfVer >> numOfEdges >> isDir;

	Graph g(numOfVer, numOfEdges, isDir);

	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(2, 3);
	g.AddEdge(2, 4);
	g.AddEdge(2, 5);
	g.AddEdge(3, 4);
	g.AddEdge(3, 5);
	g.AddEdge(4, 5);
	g.AddEdge(4, 6);
	g.AddEdge(5, 6);
	
	cout << endl << "================" << endl;
	g.print();

	cout << (g.IsConnected() ? "Connected" : "Not connected :(") << endl;

	cout << endl << "================" << endl;

	list<int> cir;
	g.Euler(cir);

	for_each(cir.begin(), cir.end(), print);

	return 0;
}