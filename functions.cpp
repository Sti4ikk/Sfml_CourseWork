#include "prototypes.h"
#include <string>
#include <vector>
#include "enums.h"
#include <string>
#include "structs.h"
#include <Windows.h>
#include <fstream>
#include <array>
#include <sstream>
#include <iostream>


// �������� �������� ������
std::array<int, 2> checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password)
{
	// �������� ������������ ��� ������ ��������� �� ������
	bool check = false;
	std::array<int, 2> arr;

	encryptDataForAdmin();
	std::array<std::string, 2> admin_data = decryptData();


	if (login == admin_data.at(0) and password == admin_data.at(1))
	{
		arr.at(0) = 1;
		arr.at(1) = -1;
		writeNumberOfPersonalEmployee(arr.at(1));
		return arr;
	}



	for (int i = 0; i < authentication.size(); i++)
	{
		if (login == authentication.at(i).login and password == authentication.at(i).password)
		{
			arr.at(0) = 1;
			arr.at(1) = i;
			writeNumberOfPersonalEmployee(arr.at(1));
			return arr;
		}
	}
	if (!check)
	{
		arr.at(0) = 0;
		arr.at(1) = 0;
		return arr;
	}
}



void addNewEmployee(std::vector<Employee>& employee, std::string str_surName, std::string str_name, 
	std::string str_patronymic, std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate)
{

	writeInfoOfNewEmployeeInFile(employee, str_surName, str_name, str_patronymic, str_gender, str_date_of_birth, str_departmentName, str_post, str_startDate);
	writeEmployeeIntoVector(employee, str_surName, str_name, str_patronymic, str_gender, str_date_of_birth, str_departmentName, str_post, str_startDate);
}
void editEmployee(std::vector<Employee>& employee, std::string  str_newInfo, std::string str_number, int kindOfField)
{
	switch (kindOfField)
	{
	case(1): employee.at(std::stoi(str_number) - 1).surName = str_newInfo; break;
	case(2): employee.at(std::stoi(str_number) - 1).name = str_newInfo; break;
	case(3): employee.at(std::stoi(str_number) - 1).patronymic = str_newInfo; break;
	case(4): employee.at(std::stoi(str_number) - 1).gender = str_newInfo; break;
	case(5): employee.at(std::stoi(str_number) - 1).dateOfBirthday = str_newInfo; break;
	case(6): employee.at(std::stoi(str_number) - 1).departmentName = str_newInfo; break;
	case(7):
	{
		if (str_newInfo == "Junior")
		{
			employee.at(std::stoi(str_number) - 1).post = Post::JUNIOR;
			break;
		}
		else if (str_newInfo == "Middle")
		{
			employee.at(std::stoi(str_number) - 1).post = Post::MIDDLE;
			break;
		}
		else if (str_newInfo == "Senior")
		{
			employee.at(std::stoi(str_number) - 1).post = Post::SENIOR;
			break;
		}
		else if (str_newInfo == "Team_leader")
		{
			employee.at(std::stoi(str_number) - 1).post = Post::TEAM_LEADER;
			break;
		}
		else if (str_newInfo == "Project_manager")
		{
			employee.at(std::stoi(str_number) - 1).post = Post::PROJECT_MANAGER;
			break;
		}
		else if (str_newInfo == "Director_of_department")
		{
			employee.at(std::stoi(str_number) - 1).post = Post::DIRECTOR_OF_DEPARTMENT;
			break;
		}
		else if (str_newInfo == "Deputy_general_director")
		{
			employee.at(std::stoi(str_number) - 1).post = Post::DEPUTY_GENERAL_DIRECTOR;
			break;
		}
		else if (str_newInfo == "General_director")
		{
			employee.at(std::stoi(str_number) - 1).post = Post::GENERAL_DIRECTOR;
			break;
		}
	}
	case(8): employee.at(std::stoi(str_number)).startDate = str_newInfo; break;
	}

	writeInToFileAfterDeleteEmployee(employee);
}
// �������� ��������� �� ������� � ������ ����� ����� � ����
void deleteEmployee(std::vector<Employee>& employee, std::string str_number)
{
	employee.erase(employee.begin() + (std::stoi(str_number) - 1));
	// ���������� ������� � �����
	writeInToFileAfterDeleteEmployee(employee);
}


// ����� �� �������
void searchWithSurname(std::vector<Employee>& employee, std::string str_surName, std::vector<int> &indexes)
{
	for (int i = 0; i < employee.size(); i++)
	{
		if (employee[i].surName == str_surName)
			indexes.push_back(i);
	}
}

// ����� �� ���������
void searchWithPost(std::vector<Employee>& employee, std::string str_post, std::vector<int>& indexes)
{
	int post1;

	if (str_post == "Junior")
		post1 = static_cast<int>(Post::JUNIOR);
	else if (str_post == "Middle")
		post1 = static_cast<int>(Post::MIDDLE);
	else if (str_post == "Senior")
		post1 = static_cast<int>(Post::SENIOR);
	else if (str_post == "Team_leader")
		post1 = static_cast<int>(Post::TEAM_LEADER);
	else if (str_post == "Project_manager")
		post1 = static_cast<int>(Post::PROJECT_MANAGER);
	else if (str_post == "Director_of_department")
		post1 = static_cast<int>(Post::DIRECTOR_OF_DEPARTMENT);
	else if (str_post == "Deputy_general_director")
		post1 = static_cast<int>(Post::DEPUTY_GENERAL_DIRECTOR);
	else if (str_post == "General_director")
		post1 = static_cast<int>(Post::GENERAL_DIRECTOR);
	else
		// ����� �� ���� ������ "���������� �� ����������������"
		post1 = -1;

	for (int i = 0; i < employee.size(); i++)
	{
		if (static_cast<int>(employee.at(i).post) == post1)
			indexes.push_back(i);
	}
}

// ����� �� ���� ������ ������
void searchWithYear(std::vector<Employee>& employee, std::string str_year, std::vector<int>& indexes)
{
	for (int i = 0; i < employee.size(); i++)
	{
		if (std::stoi(employee.at(i).startDate.substr(6)) == std::stoi(str_year))
			indexes.push_back(i);
	}
}


// ���������� ������� ���������� ������� ��� ����������� ��������� ��������
void initArrOfRandomNumbers(std::vector<int> &numbers)
{
	int count = 0;
	int number;
	int index = 0;

	numbers.reserve(5);
	for (int i = 0; numbers.size() != 5; i++)
	{
		number = rand() % 9 + 1;

		for (int j = 0; j < numbers.size(); j++)
		{
			if (numbers.at(j) == number)
				count++;
		}

		if (!count)
		{
			numbers.push_back(number);
			index++;
		}

		count = 0;
	}
}

// ���������� �� ������� � ������� ��������(���������)
void sortWithSurnameDown(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size() - 1; i++)
	{
		bool swapped = false;
		int endOfArr = employee.size() - i;
		for (int j = 0; j < endOfArr - 1; j++)
		{

			if (employee.at(j).surName < employee.at(j + 1).surName)
			{
				std::swap(employee.at(j), employee.at(j + 1));
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

// ���������� �� ������� � ������� �����������(���������)
void sortWithSurnameUp(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size() - 1; i++)
	{
		bool swapped = false;
		int endOfArr = employee.size() - i;
		for (int j = 0; j < endOfArr - 1; j++)
		{
			if (employee.at(j).surName > employee.at(j + 1).surName)
			{
				std::swap(employee.at(j), employee.at(j + 1));
				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}

// ����� ����������� �������� ��� ���������� �������
int findSmallestPosition(std::vector<Employee>& employee, int startPosition)
{
	int smallestPosition = startPosition;

	for (int i = startPosition; i < employee.size(); i++)
	{
		if (employee.at(i).post < employee.at(smallestPosition).post)
			smallestPosition = i;
	}
	return smallestPosition;
}

// ���������� �� ��������� � ������� �����������(������� ������)
void sortWithPostUp(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size(); i++)
	{
		int smallestPosition = findSmallestPosition(employee, i);
		std::swap(employee.at(i), employee.at(smallestPosition));
	}
}

// ����� ����������� �������� ��� ���������� �������
int findBiggestPosition(std::vector<Employee>& employee, int startPosition)
{
	int biggestPosition = startPosition;

	for (int i = startPosition; i < employee.size(); i++)
	{
		if (employee.at(i).post > employee.at(biggestPosition).post)
			biggestPosition = i;
	}
	return biggestPosition;
}

// ���������� �� ��������� � ������� ��������(������� ������)
void sortWithPostDown(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size(); i++)
	{
		int biggestPosition = findBiggestPosition(employee, i);
		std::swap(employee.at(i), employee.at(biggestPosition));
	}
}

// ������� ���������� ����� ����� ���� ������������
int getNumber(std::vector<Employee>& employee, int index)
{
	std::string number;
	int result;

	// ������� ��� � number
	number += employee.at(index).startDate.substr(6);
	// ������� �����
	number += employee.at(index).startDate.substr(3, 2);
	// ������� ����
	number += employee.at(index).startDate.substr(0, 2);
	// c_str ���������� ��������� �� ������, ���������� ������������������ ��������, ������������� �����("\0)
	result = atoi(number.c_str());

	return result;
}

// ���������� �� ����� � ������� ��������
void sortWithExperienceDown(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size() - 1; i++)
	{
		bool swapped = false;
		int endOfArr = employee.size() - i;
		for (int j = 0; j < endOfArr - 1; j++)
		{
			int exp1 = getNumber(employee, j);
			int exp2 = getNumber(employee, j + 1);
			if (exp1 > exp2)
			{
				std::swap(employee.at(j), employee.at(j + 1));
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

// ���������� �� ����� � ������� �����������
void sortWithExperienceUp(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size() - 1; i++)
	{
		bool swapped = false;
		int endOfArr = employee.size() - i;
		for (int j = 0; j < endOfArr - 1; j++)
		{

			if (getNumber(employee, j) < getNumber(employee, j + 1))
			{
				std::swap(employee.at(j), employee.at(j + 1));
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}



// ��������� ������� ����������(� �����)
int ageOfEmployee(std::vector<Employee>& employee, const int index)
{
	std::tm timeinfo = {};
	timeinfo.tm_year = atoi(employee.at(index).dateOfBirthday.substr(6).c_str()) - 1900;  // ��� ��������� �� 1900
	timeinfo.tm_mon = atoi(employee.at(index).dateOfBirthday.substr(3, 2).c_str()) - 1;
	timeinfo.tm_mday = atoi(employee.at(index).dateOfBirthday.substr(0, 2).c_str());

	std::time_t custom_time = std::mktime(&timeinfo);

	// �������� ������� ����
	std::time_t end = std::time(nullptr);

	// ������������ �������
	std::tm end_tm = {};
	localtime_s(&end_tm, &end);
	int years = end_tm.tm_year - timeinfo.tm_year;

	// ���������, ��������� �� ���� �������� � ���� ����
	if (end_tm.tm_mon < timeinfo.tm_mon or (end_tm.tm_mon == timeinfo.tm_mon && end_tm.tm_mday < timeinfo.tm_mday))
		--years; // ���� ��� �� ������, ��������� ������� �� 1 ���

	return years;
}

// �������� �� ��� ����������
int checkGenderOfEmployee(std::vector<Employee>& employee, const int index)
{
	if (employee.at(index).gender == "Man")
		return 1;
	else if (employee.at(index).gender == "Woman")
		return 0;
}

// ����� ����������� � ���������� ���������
std::vector<int> searchForEmployeesOfRetirementAge(std::vector<Employee>& employee)
{
	// ������ ��� �������� �������� ����������� ����������� ��������
	std::vector<int> indexes;
	indexes.reserve(employee.size());

	for (int index = 0; index < employee.size(); index++)
	{
		if ((checkGenderOfEmployee(employee, index) and ageOfEmployee(employee, index) >= 63) or (!checkGenderOfEmployee(employee, index) and ageOfEmployee(employee, index) >= 58))
			indexes.push_back(index);
	}

	return indexes;
}



// ������� ��� ���������� ������ ������� ������� ������
std::array<std::string, 2> encryptData(std::string &login, std::string& password)
{
	std::array<std::string, 2> ciphertext = { login, password };

	// ������ ������� ������: ������ 'A' ���������� �� 'Z', 'B' �� 'Y' � ��� �����
	for (char& c : ciphertext.at(0)) 
	{
		if (std::isalpha(c)) 
		{
			c += 1;
		}
	}
	for (char& c : ciphertext.at(1))
	{
		if (std::isalpha(c))
		{
			c += 1;
		}
	}

	std::fstream file("Admin_data.txt");
	file << ciphertext.at(0);
	file << std::endl;
	file << ciphertext.at(1);
	file.close();

	return ciphertext;
}

// ������� ��� ������������ ������ ������� ������� ������
std::array<std::string, 2> decryptData()
{
	std::fstream file("Admin_data.txt");
	std::array<std::string, 2> ciphertext;

	file >> ciphertext.at(0);
	file >> ciphertext.at(1);

	std::array<std::string, 2> plaintext;

	// �������� �� ������ ������������� ������ � ��������� �������� ��������������
	for (size_t i = 0; i < 2; ++i)
	{
		std::string decryptedString;
		int count = 0;
		for (char c : ciphertext[i])
		{
			// ��������� �������� ��������������: ������ 'Z' �������� �� 'A', 'Y' �� 'B' � ��� �����
			if (std::isalpha(c))
			{
				decryptedString.push_back(c - 1);
			}
		}

		plaintext[i] = decryptedString;
	}

	return plaintext;
}

void encryptDataForAdmin()
{
	// ������������� ������ ��� ������
	std::string login = "adminOne";
	std::string password = "AdminXX";
	encryptData(login, password);
}


// �������� ���� ����������� � �����, ������� � ����
void getExperienceOfEmployees(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size(); i++)
	{
		// ����� ���������� start � ���������� ���� � �����
		std::tm timeinfo = {};
		timeinfo.tm_year = atoi(employee.at(i).startDate.substr(6).c_str()) - 1900;  // ��� ��������� �� 1900
		timeinfo.tm_mon = atoi(employee.at(i).startDate.substr(3, 2).c_str()) - 1;
		timeinfo.tm_mday = atoi(employee.at(i).startDate.substr(0, 2).c_str());

		std::time_t custom_time = std::mktime(&timeinfo);

		// �������� ������� ����
		std::time_t end = std::time(nullptr);

		// ��������� ������� � ��������
		std::time_t diff = end - custom_time;

		// ��������� ������� � ����, ������ � ���
		int years = diff / (60 * 60 * 24 * 365);
		int months = (diff % (60 * 60 * 24 * 365)) / (60 * 60 * 24 * 30);
		int days = ((diff % (60 * 60 * 24 * 365)) % (60 * 60 * 24 * 30)) / (60 * 60 * 24);


		employee.at(i).experience.years = years;
		employee.at(i).experience.months = months;
		employee.at(i).experience.days = days;
	}
}