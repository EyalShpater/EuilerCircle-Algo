#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int i_NumOfVertices, int i_numOfEdges, bool i_IsDirected) 
	: k_IsDirected(i_IsDirected), m_NumOfEdges(i_numOfEdges), m_NumOfVertices(i_NumOfVertices)
{
	m_Vertices = new list<int>[m_NumOfVertices + 1];
}

Graph::~Graph()
{
	delete[]m_Vertices;
}

void Graph::AddEdge(int i_inVert, int i_OutVert)
{
	m_Vertices[i_inVert].push_back(i_OutVert);

	if (!k_IsDirected)
	{
		m_Vertices[i_OutVert].push_back(i_inVert);
	}
}

bool Graph::DeleteEdge(int i_inVert, int i_OutVert)
{

}

void Graph::print() const
{
	for (int i = 1; i <= m_NumOfVertices; ++i)
	{
		cout << i << " | ";

		for (auto& edge : m_Vertices[i])
		{
			cout << edge << " ";
		}

		cout << endl;
	}
}

bool Graph::areAllDegreeEqual()
{

}

bool Graph::isDinEqualDout()
{

}

bool Graph::isConnected()
{

}



