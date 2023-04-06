#ifndef __FIND_CIRCUIT_GRAPH_H_
#define __FIND_CURCUIT_GRAPH_H_

#include "Graph.h"
#include <list>
using namespace std;

class FindCircuitGraph : Graph
{
	class Edge
	{
		int m_Vertex;
		bool m_IsMarked;
		Edge* m_Parallel;

	public:
		Edge(int i_Vertex, Edge* i_Parallel) :
			m_Vertex(i_Vertex), m_IsMarked(false), m_Parallel(i_Parallel) {}
	};

	struct ListHead
	{
		list<Edge> m_ListHead;
		Edge* m_NextMarked;
	};

	ListHead* m_DetailedVertices;

public:
	FindCircuitGraph(Graph& i_SourceGraph);

};

#endif // !__FIND_CIRCUIT_GRAPH_H_

