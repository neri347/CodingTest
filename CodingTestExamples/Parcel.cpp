/// 택배
/// https://www.acmicpc.net/problem/8980
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Parcel
{
	int from, to, count;
};

bool Cmp(const Parcel& a, const Parcel& b)
{
	// 받는 마을 번호 작은 순, 보내는 마을 번호 작은 순으로 정렬
	if (a.to == b.to)
	{
		return a.from < b.from;
	}
	return a.to < b.to;
}

int main()
{
	int N, C;
	cin >> N >> C;
	int M;
	cin >> M;
	vector<Parcel> parcels;
	for (int i = 0; i < M; i++)
	{
		int from, to, count;
		cin >> from >> to >> count;
		parcels.push_back({from, to, count});
	}

	sort(parcels.begin(), parcels.end(), Cmp);

	int answer = 0;
	vector<int> weights(N, 0);
	for (int i = 0; i < M; i++)
	{
		int from = parcels[i].from;
		int to = parcels[i].to;
		int count = parcels[i].count;

		int maxWeight = 0;
		// 트럭이 from ~ to - 1 까지 오는데 사용한 무게의 최대값. 트럭용량에서 이 최대값을 뺀 만큼 트럭에 더 실을 수 있다.
		for (int j = from; j < to; j++)
		{
			maxWeight = max(maxWeight, weights[j]);
		}
		
		int deliveryCount = min(count, C - maxWeight);
		// 트럭이 from ~ to - 1까지 오는데 deliveryCount 만큼 무게를 사용할 것이므로 배열에 더해준다.
		for (int j = from; j < to; j++)
		{
			weights[j] += deliveryCount;
		}
		answer += deliveryCount;
	}
	
	cout << answer;
	return 0;
}