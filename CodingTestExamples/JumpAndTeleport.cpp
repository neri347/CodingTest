/// ������ �����̵�
/// https://school.programmers.co.kr/learn/courses/30/lessons/12980
/// ��Ģ�� �� ã�ƺ���.
#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
	int ans = 0;
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n--;
			ans++;
		}
	}

	return ans;
}

//#include <bitset>
//using namespace std;
//
//int solution(int n)
//{
//	return bitset<32>(n).count();
//}

int main()
{

	return 0;
}