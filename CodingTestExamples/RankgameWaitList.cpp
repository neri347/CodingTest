/// ��ŷ�� ��⿭
/// https://www.acmicpc.net/problem/20006
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int P, M;

struct Room
{
	Room(string nickname, int level) : maxCount(M), masterLevel(level), isStarted(false) 
	{
		players.insert({nickname, level});
		if (players.size() == maxCount)
		{
			isStarted = true;
		}
	}
	int maxCount;
	int masterLevel;
	bool isStarted;
	map<string, int> players;
};

vector<Room> rooms;

int main()
{
	cin >> P >> M;
	for (int p = 0; p < P; p++)
	{
		int level;
		string nickname;
		cin >> level >> nickname;
		// ���� ������ �� Ȯ��
		bool entryFlag = false;
		for (int i = 0; i < rooms.size(); i++)
		{
			if (!rooms[i].isStarted)
			{
				if (rooms[i].masterLevel - 10 <= level && level <= rooms[i].masterLevel + 10)
				{
					rooms[i].players.insert({ nickname, level });
					entryFlag = true;
					if (rooms[i].players.size() == rooms[i].maxCount)
					{
						rooms[i].isStarted = true;
					}
					break;
				}
			}
		}

		// �� ������ �����
		if (!entryFlag)
		{
			Room newRoom(nickname, level);
			rooms.push_back(newRoom);
		}
	}

	for (auto& room : rooms)
	{
		if (room.isStarted)
		{
			cout << "Started!\n";
		}
		else
		{
			cout << "Waiting!\n";
		}
		for (auto& player : room.players)
		{
			cout << player.second << ' ' << player.first << '\n';
		}
	}

	return 0;
}