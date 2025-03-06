/// ���̽�ƽ
/// https://school.programmers.co.kr/learn/courses/30/lessons/42860
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;
	int sz = name.size();
	int move = sz - 1; // ó������ ������ Ŀ�� �̵��ϴ� Ƚ��
	for (int i = 0; i < sz; i++)
	{
		answer += min(name[i] - 'A', 'Z' - name[i] + 1);
		// 1. ó������ i���� �̵� ��, ó������ �ǵ��ư��� ������ �ε������� ó������ A�� ������ �ε��� ��������.
		// 2. i���� ������ �Ųٷ� �ǵ��ư��� ������ �ε������� ó������ A�� ������ �ε��� �������� ���ٰ� 
		// �ٽ� ���������� �� ���� i���� �ǵ��ƿ��� ���.
		int index = i + 1; // �� �̻� A ������ �ʴ� �ε���
		while (index < sz && name[index] == 'A')
		{
			++index;
		}
		move = min({ move, 2 * i + (sz - index), 2 * (sz - index) + i });
	}

	return answer + move;
}

int main()
{

	return 0;
}