#include "prototypes.h"
#include <string>
#include <vector>
#include "enums.h"
#include <string>
#include "structs.h"
#include <Windows.h>
#include <fstream>


// Проверка введённых данных
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
// удаление сотруника из вектора и запись новых даных в файл
void deleteEmployee(std::vector<Employee>& employee, std::string str_number)
{
	employee.erase(employee.begin() + (std::stoi(str_number) - 1));
	// обновление записей в файле
	writeInToFileAfterDeleteEmployee(employee);
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


// заполнение массива случайными числами для отображения случайных новостей
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

// сортировка по Фамилии в порядке убывания(пузырьком)
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

// сортировка по Фамилии в порядке возрастания(пузырьком)
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

// поиск наименьшего элемента для сортировки выбором
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

// сортировка по должности в порядке возрастания(методом выбора)
void sortWithPostUp(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size(); i++)
	{
		int smallestPosition = findSmallestPosition(employee, i);
		std::swap(employee.at(i), employee.at(smallestPosition));
	}
}

// поиск наибольшего элемента для сортировки выбором
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

// сортировка по должности в порядке убывания(методом выбора)
void sortWithPostDown(std::vector<Employee>& employee)
{
	for (int i = 0; i < employee.size(); i++)
	{
		int biggestPosition = findBiggestPosition(employee, i);
		std::swap(employee.at(i), employee.at(biggestPosition));
	}
}

// функция возвращает целое число типа годМесяцДень
int getNumber(std::vector<Employee>& employee, int index)
{
	std::string number;
	int result;

	// добавил год к number
	number += employee.at(index).startDate.substr(6);
	// добавил месяц
	number += employee.at(index).startDate.substr(3, 2);
	// добавил день
	number += employee.at(index).startDate.substr(0, 2);
	// c_str Возвращает указатель на массив, содержащий последовательность символов, завершающуюся нулем("\0)
	result = atoi(number.c_str());

	return result;
}

// сортировка по стажу в порядке убывания
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

// сортировка по стажу в порядке возрастания
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