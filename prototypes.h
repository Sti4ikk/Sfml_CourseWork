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
int auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool &isRememberMePressed);
void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
void openUrl(const std::string& url);