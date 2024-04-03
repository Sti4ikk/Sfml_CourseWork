#pragma once


#include <vector>
#include "structs.h"




// работа с файлами
void writingToVectorsFromFileEmployee(std::vector<Employee>& employee);
void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication);
void wrtiteIsRememberMeOn(bool& isRememberMePressed);
void writeInFileIsRememberOn(bool& isRememberMePressed);

// основные функции
int checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password);

// функцию меню
void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
int auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
void settings_menu();
void aboutApp();
void aboutCompany();
void printAllEmployees_menu(std::vector<Employee>& employee);
float printAllEmployees(std::vector<Employee>& employee, float scrollPosition);
//void printNews(int num1, int num2, int num3, int num4, int num5);

void openUrl(const std::string& url);