#pragma once

#include <SFML/Graphics.hpp>
#include "enums.h"
#include <string>

// Информация о сотрудниках предприятия
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

// данные для авторизации
struct Authentication
{
	std::string login;
	std::string password;
};

// Структура для текста
struct TextData 
{
	sf::Text text;
	std::string str;
	bool isClicked = false;
};

// Структура для спрайта
struct SpriteData
{
	sf::Sprite sprite;
	bool isClicked = false;
};