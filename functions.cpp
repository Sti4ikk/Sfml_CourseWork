#include <string>
#include <vector>
#include "enums.h"
#include <string>
#include "structs.h"
#include <Windows.h>
#include <fstream>
#include "prototypes.h"

int checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password)
{
	// проверка правильности для вывода сообщение об ошибке
	bool check = false;

	for (int i = 0; i < authentication.size(); i++)
	{
		if (login == authentication.at(i).login and password == authentication.at(i).password)
			return 1;
	}
	if (!check)
		return 0;
}

void openUrl(const std::string& url)
{
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void addNewEmployee(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate)
{

	writeInfoOfNewEmployeeInFile(employee, str_surName, str_name, str_patronymic, str_gender, str_date_of_birth, str_departmentName, str_post, str_startDate);
	writeEmployeeIntoVector(employee, str_surName, str_name, str_patronymic, str_gender, str_date_of_birth, str_departmentName, str_post, str_startDate);

}

// добавление сотрудника в вектор после добавления нового сотрудника
void writeEmployeeIntoVector(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate)
{
	Employee emp;
	emp.surName = str_surName;
	emp.name = str_name;
	emp.patronymic = str_patronymic;
	emp.gender = str_gender;
	emp.dateOfBirthday = str_date_of_birth;
	emp.departmentName = str_departmentName;

	if (str_post == "Junior")
		emp.post = Post::JUNIOR;
	else if (str_post == "Middle")
		emp.post = Post::MIDDLE;
	else if (str_post == "Senior")
		emp.post = Post::SENIOR;
	else if (str_post == "Team_leader")
		emp.post = Post::TEAM_LEADER;
	else if (str_post == "Project_manager")
		emp.post = Post::PROJECT_MANAGER;
	else if (str_post == "Director_of_department")
		emp.post = Post::DIRECTOR_OF_DEPARTMENT;
	else if (str_post == "Deputy_general_director")
		emp.post = Post::DEPUTY_GENERAL_DIRECTOR;
	else if (str_post == "General_director")
		emp.post = Post::GENERAL_DIRECTOR;

	emp.startDate = str_startDate;

	employee.push_back(emp);
}

// запись в файл нового сотрудника
void writeInfoOfNewEmployeeInFile(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate)
{
	std::ofstream empl("Employee_Data.txt", std::ios::app);
	empl << "\n";
	empl << str_surName << " ";
	empl << str_name << " ";
	empl << str_patronymic << " ";
	empl << str_gender << " ";
	empl << str_date_of_birth << " ";
	empl << str_departmentName << " ";
	empl << str_post << " ";
	empl << str_startDate;

	empl.close();
}
