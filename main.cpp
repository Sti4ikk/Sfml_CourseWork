#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include "structs.h"
#include "enums.h"
#include "prototypes.h"

using namespace sf;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Employee> employee;;
    std::vector<Authentication> authentication;
    // ������ ��� �������� �������� ����������� ����������� ��������
    std::vector<int> indexes;
    bool isRememberMePressed;

    // ������ ������ � ������� �� ������
    writingToVectorsFromFileAuth(authentication);
    writingToVectorsFromFileEmployee(employee); 
    wrtiteIsRememberMeOn(isRememberMePressed);

    if (isRememberMePressed)
        auth_menu(authentication, employee, isRememberMePressed);
    else
        main_menu(employee);
    

    return 0;
}