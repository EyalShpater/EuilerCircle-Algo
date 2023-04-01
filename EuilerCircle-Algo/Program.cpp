#include "Graph.h"

#include <iostream>
using namespace std;

int main()
{
	int in, out;
	int numOfVer, numOfEdges;
	bool isDir;

	cin >> numOfVer >> numOfEdges >> isDir;

	Graph g(numOfVer, numOfEdges, isDir);

	for (int i = 1; i <= numOfEdges; i++)
	{
		cin >> in >> out;

		g.AddEdge(in, out);
	}
	
	cout << endl << "================" << endl;
	g.print();

	cout << (g.IsConnected() ? "Connected" : "Not connected :(") << endl;

	cin >> isDir;

	return 0;
}