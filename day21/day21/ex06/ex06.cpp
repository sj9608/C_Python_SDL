

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct s_object {
	int hp=0;
	int mp=0;
	std::string name;
};

bool _comapreHP(s_object a, s_object b)
{
	if (a.hp > b.hp) return true;
	else return false;
}

bool _comapreMP(s_object a, s_object b)
{
	if (a.mp > b.mp) return true;
	else return false;
}

int main()
{
	std::vector<s_object> objs;

	{
	s_object obj1;
	obj1.hp = 100;
	obj1.mp = 50;
	obj1.name = std::string("knight_1");
	objs.push_back(obj1);
	}

	{
		s_object obj1;
		obj1.hp = 120;
		obj1.mp = 60;
		obj1.name = std::string("knight_2");
		objs.push_back(obj1);
	}

	{
		s_object obj1;
		obj1.hp = 80;
		obj1.mp = 120;
		obj1.name = std::string("knight_3");
		objs.push_back(obj1);
	}

	for (int i = 0; i < objs.size(); i++)
	{
		std::cout << objs[i].name << "," << objs[i].hp << "," << objs[i].mp << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;

	std::sort(objs.begin(), objs.end(), _comapreHP); //hp로 정렬하는 함수
	for (int i = 0; i < objs.size(); i++)
	{
		std::cout << objs[i].name << "," << objs[i].hp << "," << objs[i].mp << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;

	std::sort(objs.begin(), objs.end(), _comapreMP); //mp로 정렬하는 함수
	for (int i = 0; i < objs.size(); i++)
	{
		std::cout << objs[i].name << "," << objs[i].hp << "," << objs[i].mp << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;

	return 0;
}