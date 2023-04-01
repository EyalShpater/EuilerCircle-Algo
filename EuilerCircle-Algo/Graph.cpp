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

void Graph::DeleteEdge(int i_inVert, int i_OutVert)
{
	m_Vertices[i_inVert].remove(i_OutVert);

	if (!k_IsDirected)
	{
		m_Vertices[i_OutVert].remove(i_inVert);
	}
}

bool Graph::IsConnected() const
{
	if (k_IsDirected)
		return directedIsConnected();
	else
		return notDirectedIsConnected();
}

int* Graph::CreateDegreeArray() const
{
	int* degreeArray = new int[m_NumOfVertices + 1] {0};

	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		auto currVer = m_Vertices[i].begin();
		auto endItr = m_Vertices[i].end();
		
		while (currVer != endItr)
		{
			degreeArray[i]++;
			++currVer;
		}
	}

	return degreeArray;
}

int* Graph::CreateInDegreeArray() const
{
	int* degreeArray = new int[m_NumOfVertices + 1] {0};

	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		auto currVer = m_Vertices[i].begin();
		auto endItr = m_Vertices[i].end();

		while (currVer != endItr)
		{
			degreeArray[*currVer]++;
			++currVer;
		}
	}

	return degreeArray;
}

int* Graph::CreateOutDegreeArray() const
{
	return CreateDegreeArray();
}

void Graph::Visit(int io_Color[], int i_Vertex) const
{
	io_Color[i_Vertex] = (int)eColor::GRAY;

	auto currVer = m_Vertices[i_Vertex].begin();
	auto endItr = m_Vertices[i_Vertex].end();

	while (currVer != endItr)
	{
		if (io_Color[*currVer] == (int)eColor::WHITE)
		{
			Visit(io_Color, *currVer);
		}
	}

	io_Color[i_Vertex] = (int)eColor::BLACK;
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

bool Graph::areAllDegreeEqual() const
{
	int* degree = CreateDegreeArray();
	bool isAllEqual = true;

	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		if (degree[i] % 2 != 0)
		{
			isAllEqual = false;
		}
	}

	delete[]degree;

	return isAllEqual;
}

bool Graph::isDinEqualDout() const
{
	int* inDegree = CreateInDegreeArray();
	int* outDegree = CreateOutDegreeArray();
	bool isAllEqual = true;

	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		if (inDegree[i] != outDegree[i])
		{
			isAllEqual = false;
		}
	}

	delete[]inDegree;
	delete[]outDegree;

	return isAllEqual;
}

bool Graph::notDirectedIsConnected() const
{
	int* color = new int[m_NumOfVertices + 1];
	bool isConnected = true;

	Visit(color, 1);

	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		if (color[i] == (int)eColor::WHITE)
		{
			isConnected = false;
		}
	}

	delete[]color;

	return isConnected;
}

bool Graph::directedIsConnected() const
{

}



