#include <Windows.h>
#include <string>
#include "structs.h"
#include "enums.h"
#include "prototypes.h"
#include <vector>
#include <fstream>

void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication)
{
	std::ifstream auth("Authentication_Data.txt");

	int i = 0;
	while (!auth.eof())
	{
		Authentication authen;
		auth >> authen.login;
		auth >> authen.password;

		authentication.push_back(authen);
		i++;
	}
	auth.close();
}

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

void wrtiteIsRememberMeOn(bool &isRememberMePressed)
{
	std::fstream file("isRememberMePressed.txt");

	file >> isRememberMePressed;

	file.close();
}

void writeInFileIsRememberOn(bool& isRememberMePressed)
{
	std::fstream file("isRememberMePressed.txt");

	file << isRememberMePressed;
	file.close();
}