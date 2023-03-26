#include "Graph.h"

Graph::Graph(int i_NumOfVertices, int i_numOfEdges, bool i_IsDirected) 
	: k_IsDirected(i_IsDirected), m_NumOfEdges(i_numOfEdges), m_NumOfVertices(i_NumOfVertices + 1)
{
	m_Vertices.reserve(m_NumOfVertices + 1);

	auto itr = m_Vertices.begin();
	auto itrEnd = m_Vertices.end();

	while (itr != itrEnd)
	{
		(*itr).empty();
		++itr;
	}
}

void Graph::AddEdge(int i_inVert, int i_OutVert)
{
	m_Vertices[i_inVert].push_back(i_OutVert);

	if (!k_IsDirected)
	{
		m_Vertices[i_OutVert].push_back(i_inVert);
	}
}

void Graph::DeleteEdge(int i_inVert, int i_OutVert)
{

}