#pragma once

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

struct Auth_info
{
	std::string surName;
	std::string name;
	std::string patronymic;
	std::string photoLink;
	std::string post;
};

// ������ ��� �����������
struct Authentication
{
	std::string login;
	std::string password;
	Auth_info auth_info;
};