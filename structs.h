#pragma once

#include "enums.h"
#include <string>
#include <array>

// ����
struct Experience
{
	int years;
	int months;
	int days;
};

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

// ������ ��� �����������
struct Authentication
{
	std::string login;
	std::string password;
	Auth_info auth_info;
};