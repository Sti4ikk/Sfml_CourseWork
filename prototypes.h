#pragma once

#include "structs.h"
#include <vector>


// РАБОТА С ФАЙЛАМИ
void writingToVectorsFromFileEmployee(std::vector<Employee>& employee);
void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication);
void wrtiteIsRememberMeOn(bool& isRememberMePressed);
void writeInFileIsRememberOn(bool& isRememberMePressed);
void writeInfoOfNewEmployeeInFile(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, 
	std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void writeInToFileAfterDeleteEmployee(std::vector<Employee>& employee);


// ОСНОВНЫЕ ФУНКЦИИ
int checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password);
void addNewEmployee(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, 
	std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void writeEmployeeIntoVector(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, 
	std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void editEmployee(std::vector<Employee>& employee, std::string  str_newInfo, std::string str_number, int kindOfField);


// ФУНКЦИИ МЕНЮ
void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
void auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
void settings_menu();
void aboutApp();
void aboutCompany();
void printAllEmployees_menu(std::vector<Employee>& employee);
float printAllEmployees(std::vector<Employee>& employee, float scrollPosition);
void addNewEmployee_menu(std::vector<Employee>& employee);
void editInfoOfEmployee_menu(std::vector<Employee>& employee);
void editMode(std::vector<Employee>& employee, std::string str_number);
int enterNewInfo_editMode(std::vector<Employee>& employee, std::string str_number, int kindOfField);
float printAllEmployeesForEditingAndDeleting(std::vector<Employee>& employee, float scrollPosition);
void deleteEmployee_menu(std::vector<Employee>& employee);
void deleteEmployee(std::vector<Employee>& employee, std::string str_number);
void printSearchingEmployeesWithSurname(std::vector<Employee>& employee, std::string str_surName, bool isSurnameChanging);
void printEmployeesLoopPost(std::vector<int>& indexes, std::vector<Employee>& employee);
void printSearchingEmployeesWithPost(std::vector<Employee>& employee, std::string str_surName, bool isSurnameChanging);
void printEmployeesLoopYear(std::vector<int>& indexes, std::vector<Employee>& employee);
void printSearchingEmployeesWithYear(std::vector<Employee>& employee, std::string str_year, bool isYearChanging);


// СОРТИРОВКИ
void sortingEmpoyeesWithSurname_menu(std::vector<Employee>& employee);
void printEmployeesLoop(std::vector<int>& indexes, std::vector<Employee>& employee);
int successOfSorting_menu(int kindOfSort, int sortUpOrDown, std::vector<Employee>& employee);
void sortWithSurnameDown(std::vector<Employee>& employee);
void sortWithSurnameUp(std::vector<Employee>& employee);
// поиск наименьшего элемента для сортировки выбором
int findSmallestPosition(std::vector<Employee>& employee, int startPosition);
// сортировка по должности в порядке возрастания(методом выбора)
void sortWithPostUp(std::vector<Employee>& employee);
// поиск наибольшего элемента для сортировки выбором
int findBiggestPosition(std::vector<Employee>& employee, int startPosition);
// сортировка по должности в порядке убывания(методом выбора)
void sortWithPostDown(std::vector<Employee>& employee);
// функция возвращает целое число типа годМесяцДень
int getNumber(std::vector<Employee>& employee, int index);
// сортировка по стажу в порядке убывания
void sortWithExperienceDown(std::vector<Employee>& employee);
// сортировка по стажу в порядке возрастания
void sortWithExperienceUp(std::vector<Employee>& employee);


// ФУНКЦИИ ПОИСКА
void searchWithYear(std::vector<Employee>& employee, std::string str_year, std::vector<int>& indexes);
void searchWithPost(std::vector<Employee>& employee, std::string str_post, std::vector<int>& indexes);
void searchWithSurname(std::vector<Employee>& employee, std::string str_surName, std::vector<int>& indexes);
void searchEmployeeWithSurname_menu(std::vector<Employee>& employee);
void searchEmployeeWithPost_menu(std::vector<Employee>& employee);
void searchEmployeeWithStartYear_menu(std::vector<Employee>& employee);


// ФУНКЦИИ СОСТОЯНИЯ
int successOfAdding_menu();
int successOfEdit_menu();
int areYouSure();


void initArrOfRandomNumbers(std::vector<int>& numbers);