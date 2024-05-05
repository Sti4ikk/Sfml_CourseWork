#pragma once

#include <SFML/Graphics.hpp>
#include "enums.h"
#include <string>

// ���������� � ����������� �����������
struct Employee
{
	std::string surName;
	std::string name;
	std::string patronymic;
	std::string gender;
	std::string dateOfBirthday;
	std::string departmentName;
	Post post;
	std::string startDate;
};

struct Date
{
	int day;
	int months;
	int years;
};

// ������ ��� �����������
struct Authentication
{
	std::string login;
	std::string password;
};

// ��������� ��� ������
struct TextData 
{
	sf::Text text;
	std::string str;
	bool isClicked = false;
};

// ��������� ��� �������
struct SpriteData
{
	sf::Sprite sprite;
	bool isClicked = false;
};