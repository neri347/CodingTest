/// p.481 ����39 ����-���� �˰���
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// ���� ������ �� �������� �ּ� ����� ���� ���͸� ��ȯ
// ���� ��ȯ�� �ִٸ� -1 ��ȯ
vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source)
{
	
}

int main()
{
	int num_vertices = 5;
	vector<tuple<int, int, int>> edges;
	tuple<int, int, int> t1(0, 1, 4);
	tuple<int, int, int> t2(0, 2, 3);
	tuple<int, int, int> t3(0, 4, -6);
	tuple<int, int, int> t4(1, 3, 5);
	tuple<int, int, int> t5(2, 1, 2);
	tuple<int, int, int> t6(3, 0, 7);
	tuple<int, int, int> t7(3, 2, 4);
	tuple<int, int, int> t8(4, 2, 2);
	edges.push_back(t1);
	edges.push_back(t2);
	edges.push_back(t3);
	edges.push_back(t4);
	edges.push_back(t5);
	edges.push_back(t6);
	edges.push_back(t7);
	edges.push_back(t8);
	int source = 0;
	for (int e : solution(num_vertices, edges, source))
	{
		cout << e << " ";
	}

	return 0;
}