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

void addNewEmployee(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate)
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

// удаление сотруника из вектора и запись новых даных в файл
void deleteEmployee(std::vector<Employee>& employee, std::string str_number)
{
	employee.erase(employee.begin() + (std::stoi(str_number) - 1));
	// обновление записей в файле
	writeInToFileAfterDeleteEmployee(employee);
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

void writeInToFileAfterDeleteEmployee(std::vector<Employee>& employee)
{
	std::ofstream empl("Employee_Data.txt");

	for (int i = 0; i < employee.size(); i++)
	{
		empl << employee.at(i).surName << " ";
		empl << employee.at(i).name << " ";
		empl << employee.at(i).patronymic << " ";
		empl << employee.at(i).gender << " ";
		empl << employee.at(i).dateOfBirthday << " ";
		empl << employee.at(i).departmentName << " ";

		if (static_cast<int>(employee.at(i).post) == 1)
			empl << "Junior ";
		else if (static_cast<int>(employee.at(i).post) == 2)
			empl << "Middle ";
		else if (static_cast<int>(employee.at(i).post) == 3)
			empl << "Senior ";
		else if (static_cast<int>(employee.at(i).post) == 4)
			empl << "Team_leader ";
		else if (static_cast<int>(employee.at(i).post) == 5)
			empl << "Project_manager ";
		else if (static_cast<int>(employee.at(i).post) == 6)
			empl << "Director_of_department ";
		else if (static_cast<int>(employee.at(i).post) == 7)
			empl << "Deputy_general_diretor ";
		else if (static_cast<int>(employee.at(i).post) == 8)
			empl << "General_director ";

		empl << employee.at(i).startDate << std::endl;

	}

	empl.close();
}

// ПОИСК ПО ФАМИЛИИ
void searchWithSurname(std::vector<Employee>& employee, std::string str_surName, std::vector<int> &indexes)
{
	for (int i = 0; i < employee.size(); i++)
	{
		if (employee[i].surName == str_surName)
			indexes.push_back(i);
	}
}

// ПОИСК ПО ДОЛЖНОСТИ
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
		// чтобы не было ошибки "переменная не инициализирована"
		post1 = -1;

	for (int i = 0; i < employee.size(); i++)
	{
		if (static_cast<int>(employee.at(i).post) == post1)
			indexes.push_back(i);
	}
}

// ПОИСК ПО ГОДУ НАЧАЛА РАБОТЫ
void searchWithYear(std::vector<Employee>& employee, std::string str_year, std::vector<int>& indexes)
{
	for (int i = 0; i < employee.size(); i++)
	{
		if (std::stoi(employee.at(i).startDate.substr(6)) == std::stoi(str_year))
			indexes.push_back(i);
	}
}