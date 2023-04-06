#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int i_NumOfVertices, int i_numOfEdges, bool i_IsDirected) 
	: k_IsDirected(i_IsDirected), m_NumOfEdges(i_numOfEdges), m_NumOfVertices(i_NumOfVertices)
{
	m_Vertices = new list<Edge>[m_NumOfVertices + 1];
}

Graph::~Graph()
{
	delete[]m_Vertices;
}

void Graph::AddEdge(int i_InVert, int i_OutVert)
{
	m_Vertices[i_InVert].push_back(Edge(i_OutVert, nullptr));

	if (!k_IsDirected)
	{
		Edge* lastEdge = &(m_Vertices[i_InVert].back());
		m_Vertices[i_OutVert].push_back(Edge(i_InVert, lastEdge));
		lastEdge = &(m_Vertices[i_OutVert].back());
		m_Vertices[i_InVert].back().m_Parallel = lastEdge;
	}
}

//void Graph::DeleteEdge(int i_inVert, int i_OutVert)
//{
//	m_Vertices[i_inVert].remove(i_OutVert);
//
//	if (!k_IsDirected)
//	{
//		m_Vertices[i_OutVert].remove(i_inVert);
//	}
//}

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
			degreeArray[(*currVer).m_Vertix]++;
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
		if (io_Color[(*currVer).m_Vertix] == (int)eColor::WHITE)
		{
			Visit(io_Color, (*currVer).m_Vertix);
		}

		++currVer;
	}

	io_Color[i_Vertex] = (int)eColor::BLACK;
}

list<int> Graph::FindCircuit(int i_Vertex)
{
	int currentVertex = i_Vertex;
	Edge* neighbour;
	list<int> circuit;
	vector<list<Edge>::iterator> nextUnmarkedEdge = createMarkedEdgesArray();

	circuit.push_back(i_Vertex);
	while (nextUnmarkedEdge[i_Vertex] != m_Vertices[i_Vertex].end()) 
	{
		neighbour = &(*(nextUnmarkedEdge[currentVertex]));
		markEdge(*neighbour);
		circuit.push_back(neighbour->m_Vertix);
		currentVertex = neighbour->m_Vertix;
		findNextUnmarkedEdge(nextUnmarkedEdge, currentVertex);
	} 

	resetMarks();

	return circuit;
}

void Graph::print() const
{
	for (int i = 1; i <= m_NumOfVertices; ++i)
	{
		cout << i << " | ";

		for (auto& edge : m_Vertices[i])
		{
			cout << edge.m_Vertix << " ";
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
	int* color = new int[m_NumOfVertices + 1] {(int)eColor::WHITE};
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
	bool isConnected = notDirectedIsConnected();

	if(isConnected)
	{
		Graph trans = createGraphTranspose();

		isConnected = trans.notDirectedIsConnected();
	}

	return isConnected;
}

Graph Graph::createGraphTranspose() const
{
	Graph res(m_NumOfVertices, m_NumOfEdges, k_IsDirected);

	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		auto currVer = m_Vertices[i].begin();
		auto endItr = m_Vertices[i].end();

		while (currVer != endItr)
		{
			res.AddEdge((*currVer).m_Vertix, i);
			++currVer;
		}
	}

	return res;
}

vector<list<Graph::Edge>::iterator> Graph::createMarkedEdgesArray() const
{
	vector<list<Edge>::iterator> res;

	res.reserve(m_NumOfVertices + 1);
	for (int i = 0; i <= m_NumOfVertices; i++)
	{
		res.push_back(m_Vertices[i].begin());
	}

	return res;
}

void Graph::resetMarks()
{
	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		auto currVer = m_Vertices[i].begin();
		auto endItr = m_Vertices[i].end();

		while (currVer != endItr)
		{
			(*currVer).m_IsMarked = false;
			++currVer;
		}
	}
}

void Graph::markEdge(Edge& io_Edge)
{
	io_Edge.m_IsMarked = true;
	if (!k_IsDirected)
	{
		io_Edge.m_Parallel->m_IsMarked = true;
	}
}

void Graph::findNextUnmarkedEdge(vector<list<Edge>::iterator>& io_EdgesArray, int i_CurrentVertex) const
{
	while (io_EdgesArray[i_CurrentVertex] != m_Vertices[i_CurrentVertex].end() && 
		io_EdgesArray[i_CurrentVertex]->m_IsMarked)
	{
		++io_EdgesArray[i_CurrentVertex];
	}
}