#pragma once
#include <vector>
#include "structs.h"



// работа с файлами
void writingToVectorsFromFileEmployee(std::vector<Employee>& employee);
void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication);
void wrtiteIsRememberMeOn(bool& isRememberMePressed);
void writeInFileIsRememberOn(bool& isRememberMePressed);
void writeInfoOfNewEmployeeInFile(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void writeInToFileAfterDeleteEmployee(std::vector<Employee>& employee);

// основные функции
int checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password);
void addNewEmployee(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void writeEmployeeIntoVector(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void editEmployee(std::vector<Employee>& employee, std::string  str_newInfo, std::string str_number, int kindOfField);
void searchWithSurname(std::vector<Employee>& employee, std::string str_surName, std::vector<int> &indexes);



// функцию меню
void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
int auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
void settings_menu();
void aboutApp();
void aboutCompany();
void printAllEmployees_menu(std::vector<Employee>& employee);
float printAllEmployees(std::vector<Employee>& employee, float scrollPosition);
void addNewEmployee_menu(std::vector<Employee>& employee);

void editInfoOfEmployee_menu(std::vector<Employee>& employee);
void editMode(std::vector<Employee>& employee, std::string str_number);
void enterNewInfo_editMode(std::vector<Employee>& employee, std::string str_number, int kindOfField);
void searchEmployeeWithSurname_menu(std::vector<Employee>& employee);
void searchEmployeeWithPost_menu(std::vector<Employee>& employee);
void searchEmployeeWithStartYear_menu(std::vector<Employee>& employee);


float printAllEmployeesForEditingAndDeleting(std::vector<Employee>& employee, float scrollPosition);

void deleteEmployee_menu(std::vector<Employee>& employee);

int areYouSure();
void deleteEmployee(std::vector<Employee>& employee, std::string str_number);

void printSearchingEmployees(std::vector<Employee>& employee, std::string str_surName, bool isSurnameChanging);