#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <list>
#include <vector>
using namespace std;

class Graph
{
	list<int> m_Edges;
	vector<list<int>> m_Vertices;
	const bool k_IsDirected;
	int m_NumOfVertices;
	int m_NumOfEdges;

public:
	Graph(int i_NumOfVertices, int i_numOfEdges, bool i_IsDirected);

	void AddEdge(int i_inVert, int i_OutVert);
	void DeleteEdge(int i_inVert, int i_OutVert);

};
#endif // !__GRAPH_H_
