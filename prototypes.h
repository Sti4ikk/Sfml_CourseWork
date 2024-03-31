#pragma once


#include <vector>
#include "structs.h"




// ������ � �������
void writingToVectorsFromFileEmployee(std::vector<Employee>& employee);
void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication);
void wrtiteIsRememberMeOn(bool& isRememberMePressed);
void writeInFileIsRememberOn(bool& isRememberMePressed);

// �������� �������
int checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password);

// ������� ����
void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
int auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed);
void settings_menu();
void aboutApp();
void aboutCompany();


void openUrl(const std::string& url);