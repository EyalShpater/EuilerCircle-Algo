#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <list>
#include <vector>
using namespace std;

class Graph
{
	struct Edge
	{
		int m_Vertix;
		bool m_IsMarked;
		Edge* m_Parallel;

		Edge(int i_Vertix = 0, Edge* i_Parallel = nullptr) : m_Vertix(i_Vertix),
			m_IsMarked(false), m_Parallel(i_Parallel) {}

		bool operator==(int i_Vertex) const
		{
			return i_Vertex == m_Vertix;
		}
	};

public:
	enum class eColor { WHITE, GRAY, BLACK };

protected:
	list<Edge>* m_Vertices;
	const bool k_IsDirected;
	int m_NumOfVertices;
	int m_NumOfEdges;

public:
	Graph(int i_NumOfVertices, int i_numOfEdges, bool i_IsDirected);
	~Graph();

	void AddEdge(int i_inVert, int i_OutVert);
	void DeleteEdge(int i_inVert, int i_OutVert);

	bool IsConnected() const;
	bool IsEulerian() const;

	int* CreateDegreeArray() const;
	int* CreateInDegreeArray() const;
	int* CreateOutDegreeArray() const;

	void Visit(int io_Color[], int i_Vertex) const;
	list<int> FindCircuit(int i_Vertex, vector<list<Edge>::iterator>& io_NextUnmarkedEdge);
	bool Euler(list<int>& o_Circle);

	void print() const;
	
private:
	bool areAllDegreeEven() const;
	bool isDinEqualDout() const;
	bool notDirectedIsConnected() const;
	bool directedIsConnected() const;
	Graph createGraphTranspose() const;
	vector<list<Edge>::iterator> createMarkedEdgesArray() const;
	void resetMarks();
	void markEdge(Edge& io_Edge);
	void findNextUnmarkedEdge(vector<list<Edge>::iterator>& io_EdgesArray, int i_CurrentVertex) const;
	list<int>::iterator findNextUnmarkedVertex(vector<list<Edge>::iterator>& io_VertexArray, list<int>& i_VertexList);
};
#endif // !__GRAPH_H_
