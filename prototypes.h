#pragma once

#include "structs.h"
#include <vector>


// –¿¡Œ“¿ — ‘¿…À¿Ã»
void writingToVectorsFromFileEmployee(std::vector<Employee>& employee);
void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication);
void wrtiteIsRememberMeOn(bool& isRememberMePressed);
void writeInFileIsRememberOn(bool& isRememberMePressed);
void writeInfoOfNewEmployeeInFile(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, 
	std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void writeInToFileAfterDeleteEmployee(std::vector<Employee>& employee);


// Œ—ÕŒ¬Õ€≈ ‘”Õ ÷»»
std::array<int, 2> checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password);
void addNewEmployee(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, 
	std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void writeEmployeeIntoVector(std::vector<Employee>& employee, std::string str_surName, std::string str_name, std::string str_patronymic, 
	std::string str_gender, std::string str_date_of_birth, std::string str_departmentName, std::string str_post, std::string str_startDate);
void editEmployee(std::vector<Employee>& employee, std::string  str_newInfo, std::string str_number, int kindOfField);


// ‘”Õ ÷»» Ã≈Õﬁ
void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed, int numberOfPersonalEmployee);
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


// —Œ–“»–Œ¬ »
void printEmployeesLoop(std::vector<int>& indexes, std::vector<Employee>& employee);
int successOfSorting_menu(int kindOfSort, int sortUpOrDown, std::vector<Employee>& employee);
void sortWithSurnameDown(std::vector<Employee>& employee);
void sortWithSurnameUp(std::vector<Employee>& employee);
int findSmallestPosition(std::vector<Employee>& employee, int startPosition);
void sortWithPostUp(std::vector<Employee>& employee);
int findBiggestPosition(std::vector<Employee>& employee, int startPosition);
void sortWithPostDown(std::vector<Employee>& employee);
int getNumber(std::vector<Employee>& employee, int index);
void sortWithExperienceDown(std::vector<Employee>& employee);
void sortWithExperienceUp(std::vector<Employee>& employee);


// ‘”Õ ÷»» œŒ»— ¿
void searchWithYear(std::vector<Employee>& employee, std::string str_year, std::vector<int>& indexes);
void searchWithPost(std::vector<Employee>& employee, std::string str_post, std::vector<int>& indexes);
void searchWithSurname(std::vector<Employee>& employee, std::string str_surName, std::vector<int>& indexes);
void searchEmployeeWithSurname_menu(std::vector<Employee>& employee);
void searchEmployeeWithPost_menu(std::vector<Employee>& employee);
void searchEmployeeWithStartYear_menu(std::vector<Employee>& employee);


// ‘”Õ ÷»» —Œ—“ŒﬂÕ»ﬂ
int successOfAdding_menu();
int successOfEdit_menu();
int areYouSure();

void initArrOfRandomNumbers(std::vector<int>& numbers);


int ageOfEmployee(std::vector<Employee>& employee, const int index);
int checkGenderOfEmployee(std::vector<Employee>& employee, const int index);
std::vector<int> searchForEmployeesOfRetirementAge(std::vector<Employee>& employee);

void employeesOfRetirementAge_menu(std::vector<Employee>& employee);
float printEmployeesOfRetirementAge(std::vector<Employee>& employee);

void account_menu(std::vector<Authentication>& authentication, int numberOfPersonalEmployee);


void writeNumberOfPersonalEmployee(int numberOfPersonalEmployee);
int readNumberOfPersonalEmployee();



std::array<std::string, 2> encryptData(std::string &login, std::string &password);
std::array<std::string, 2> decryptData();
void encryptDataForAdmin();
