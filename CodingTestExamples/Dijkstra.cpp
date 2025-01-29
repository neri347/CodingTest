/// p.474 문제 38 다익스트라 알고리즘
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int main()
{
	int start = 0;
	//int numNodes = 3;
	int numNodes = 4;
	vector<tuple<int, int, int>> edges;
	/*tuple<int, int, int> t1(0, 1, 9);
	tuple<int, int, int> t2(0, 2, 3);
	tuple<int, int, int> t3(1, 0, 5);
	tuple<int, int, int> t4(2, 1, 1);
	edges.push_back(t1);
	edges.push_back(t2);
	edges.push_back(t3);
	edges.push_back(t4);*/
	tuple<int, int, int> t1(0, 1, 1);
	tuple<int, int, int> t2(1, 2, 5);
	tuple<int, int, int> t3(2, 3, 1);
	edges.push_back(t1);
	edges.push_back(t2);
	edges.push_back(t3);
	for (int e : solution(start, numNodes, edges))
	{
		cout << e << " ";
	}
	return 0;
}