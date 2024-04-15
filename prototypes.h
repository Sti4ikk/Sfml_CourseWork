#pragma once

#include "structs.h"
#include <vector>



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
void auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
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

void printSearchingEmployeesWithSurname(std::vector<Employee>& employee, std::string str_surName, bool isSurnameChanging);

void printEmployeesLoopPost(std::vector<int>& indexes, std::vector<Employee>& employee);
void printSearchingEmployeesWithPost(std::vector<Employee>& employee, std::string str_surName, bool isSurnameChanging);
void searchWithPost(std::vector<Employee>& employee, std::string str_post, std::vector<int>& indexes);

void printEmployeesLoopYear(std::vector<int>& indexes, std::vector<Employee>& employee);
void printSearchingEmployeesWithYear(std::vector<Employee>& employee, std::string str_year, bool isYearChanging);
void searchWithYear(std::vector<Employee>& employee, std::string str_year, std::vector<int>& indexes);

// —ќ–“»–ќ¬ »
void sortingEmpoyeesWithSurname_menu(std::vector<Employee>& employee);
void printEmployeesLoop(std::vector<int>& indexes, std::vector<Employee>& employee);



void initArrOfRandomNumbers(std::vector<int>& numbers);

// сортировки
void successOfSorting_menu(int kindOfSort, int sortUpOrDown, std::vector<Employee>& employee);
void sortWithSurnameDown(std::vector<Employee>& employee);
void sortWithSurnameUp(std::vector<Employee>& employee);

// поиск наименьшего элемента дл€ сортировки выбором
int findSmallestPosition(std::vector<Employee>& employee, int startPosition);


// сортировка по должности в пор€дке возрастани€(методом выбора)
void sortWithPostUp(std::vector<Employee>& employee);

// поиск наибольшего элемента дл€ сортировки выбором
int findBiggestPosition(std::vector<Employee>& employee, int startPosition);


// сортировка по должности в пор€дке убывани€(методом выбора)
void sortWithPostDown(std::vector<Employee>& employee);


// функци€ возвращает целое число типа годћес€цƒень
int getNumber(std::vector<Employee>& employee, int index);


// сортировка по стажу в пор€дке убывани€
void sortWithExperienceDown(std::vector<Employee>& employee);


// сортировка по стажу в пор€дке возрастани€
void sortWithExperienceUp(std::vector<Employee>& employee);


void successOfAdding_menu();