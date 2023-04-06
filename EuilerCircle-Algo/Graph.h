#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <list>
using namespace std;

class Graph
{
public:
	enum class eColor { WHITE, GRAY, BLACK };

private:
	list<int>* m_Vertices;
	const bool k_IsDirected;
	int m_NumOfVertices;
	int m_NumOfEdges;

public:
	Graph(int i_NumOfVertices, int i_numOfEdges, bool i_IsDirected);
	~Graph();

	void AddEdge(int i_inVert, int i_OutVert);
	void DeleteEdge(int i_inVert, int i_OutVert);

	bool IsConnected() const;

	int* CreateDegreeArray() const;
	int* CreateInDegreeArray() const;
	int* CreateOutDegreeArray() const;

	void Visit(int io_Color[], int i_Vertex) const;
	list<int> FindCircuit(int i_Vertex);

	void print() const;
	
private:
	bool areAllDegreeEqual() const;
	bool isDinEqualDout() const;
	bool notDirectedIsConnected() const;
	bool directedIsConnected() const;
	Graph createGraphTranspose() const;
};
#endif // !__GRAPH_H_
