#pragma once

#include "enums.h"
#include <string>
#include <array>

// СТАЖ
struct Experience
{
	int years;
	int months;
	int days;
};

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
	Experience experience;
};

struct Auth_info
{
	std::string surName;
	std::string name;
	std::string patronymic;
	std::string photoLink;
	std::string post;
};

// данные для авторизации
struct Authentication
{
	std::string login;
	std::string password;
	Auth_info auth_info;
};