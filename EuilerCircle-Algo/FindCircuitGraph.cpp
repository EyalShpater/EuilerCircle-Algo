#include "FindCircuitGraph.h"

FindCircuitGraph::FindCircuitGraph(Graph& i_SourceGraph) : Graph(i_SourceGraph)
{
	m_DetailedVertices = new ListHead[m_NumOfVertices + 1];

	for (int i = 1; i <= m_NumOfVertices; i++)
	{
		auto itr = m_Vertices[i].begin();
		auto itrEnd = m_Vertices[i].end();

		for (; itr != itrEnd; ++itr)
		{
			//m_DetailedVertices[i].m_ListHead.push_back(Edge(*itr, nullptr));
			m_DetailedVertices[i].m_NextMarked = &m_DetailedVertices[i].m_ListHead.front();

			if (!k_IsDirected)
			{

			}
		}
	}

}