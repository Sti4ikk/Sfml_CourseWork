#include <Windows.h>
#include <string>
#include "structs.h"
#include "enums.h"
#include "prototypes.h"
#include <vector>
#include <fstream>


// Чтение данных пользователей из файла
void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication)
{
	std::ifstream auth("Authentication_Data.txt");

	int i = 0;
	while (!auth.eof())
	{
		Authentication authen;
		auth >> authen.login;
		auth >> authen.password;
		auth >> authen.auth_info.surName;
		auth >> authen.auth_info.name;
		auth >> authen.auth_info.patronymic;
		auth >> authen.auth_info.photoLink;
		auth >> authen.auth_info.post;

		authentication.push_back(authen);
		i++;
	}
	auth.close();
}

// Чтение данных сотрудников из файла
void writingToVectorsFromFileEmployee(std::vector<Employee>& employee)
{
	std::ifstream empl("Employee_Data.txt");
	int j = 0;
	while (!empl.eof())
	{
		Employee emp;
		std::string post1;

		empl >> emp.surName;
		empl >> emp.name;
		empl >> emp.patronymic;
		empl >> emp.gender;
		empl >> emp.dateOfBirthday;
		empl >> emp.departmentName;
		empl >> post1;

		if (post1 == "Junior")
			emp.post = Post::JUNIOR;
		else if (post1 == "Middle")
			emp.post = Post::MIDDLE;
		else if (post1 == "Senior")
			emp.post = Post::SENIOR;
		else if (post1 == "Team_leader")
			emp.post = Post::TEAM_LEADER;
		else if (post1 == "Project_manager")
			emp.post = Post::PROJECT_MANAGER;
		else if (post1 == "Director_of_department")
			emp.post = Post::DIRECTOR_OF_DEPARTMENT;
		else if (post1 == "Deputy_general_director")
			emp.post = Post::DEPUTY_GENERAL_DIRECTOR;
		else if (post1 == "General_director")
			emp.post = Post::GENERAL_DIRECTOR;

		empl >> emp.startDate;

		employee.push_back(emp);

		j++;
	}
	empl.close();
}

// Чтение из файла переменной-состояния входа
void readIsRememberMeOn(bool &isRememberMePressed)
{
	std::fstream file("isRememberMePressed.txt");

	file >> isRememberMePressed;

	file.close();
}

// Запись в файл переменной-состояния входа
void writeInFileIsRememberOn(bool& isRememberMePressed)
{
	std::fstream file("isRememberMePressed.txt");

	file << isRememberMePressed;
	file.close();
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
		
		if (i != 0) empl << std::endl;
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

		empl << employee.at(i).startDate;

	}

	empl.close();
}

// запись в файл номера аккаунта
void writeNumberOfPersonalEmployee(int numberOfPersonalEmployee)
{
	std::fstream file("numberOfPersonalEmployee.txt");
	file << numberOfPersonalEmployee;
	file.close();
}

// Читаем число из файла для идентификации работника
int readNumberOfPersonalEmployee()
{
	std::fstream file("numberOfPersonalEmployee.txt");
	int num;
	file >> num;

	return num;
}

// Функция для записи в файл нового аккаунта
void writeNewPersonalEmployee(std::vector<Authentication>& authentication, std::string str_login, std::string str_password, std::string str_surName, std::string str_name,
	std::string str_patronymic, std::string str_link, std::string str_post)
{
	std::fstream file("Authentication_Data.txt", std::ios::app);
	file <<std::endl<< str_login << " ";
	std::string hashPassword = sha256(str_password);
	file << hashPassword << " ";
	file << str_surName << " ";
	file << str_name << " ";
	file << str_patronymic << " ";
	file << str_link << " ";
	file << str_post;

	file.close();
}

// Перезапись файла после удаления аккаунта
void writeInToFileAfterDeleteRersonalEmployee(std::vector<Authentication>& authentication)
{
	std::ofstream empl("Authentication_Data.txt");

	for (int i = 0; i < authentication.size(); i++)
	{

		if (i != 0) empl << std::endl;
		empl << authentication.at(i).login << " ";
		empl << authentication.at(i).password << " ";
		empl << authentication.at(i).auth_info.surName << " ";
		empl << authentication.at(i).auth_info.name << " ";
		empl << authentication.at(i).auth_info.patronymic << " ";
		empl << authentication.at(i).auth_info.photoLink << " ";
		empl << authentication.at(i).auth_info.post;
	}

	empl.close();
}