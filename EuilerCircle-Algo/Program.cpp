#include "Graph.h"
#include "ConsoleIO.h"

#define REF

int main()
{
	try
	{
		int numOfVer, numOfEdges;
		bool isDir;

		ConsoleIO::GetUserInput(REF isDir, REF numOfVer, REF numOfEdges);
		Graph g(numOfVer, numOfEdges, isDir);
		ConsoleIO::GetEdgesFromUser(REF g);
		ConsoleIO::PrintIfEulerian(REF g);

		return 0;
	}
	catch(const char* msg)
	{
		cout << msg;
	}
}