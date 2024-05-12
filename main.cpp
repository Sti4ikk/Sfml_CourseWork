#include "structs.h"
#include "enums.h"
#include "prototypes.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <iostream>
#include <array>

sf::RenderWindow window(sf::VideoMode(500, 412), "", sf::Style::None);


int main()
{
    srand(time(NULL));


    std::vector<Employee> employee;;
    std::vector<Authentication> authentication;
    std::vector<int> indexes;                        // вектор для хранения индексов сотрдуников пенсионного возраста
    bool isRememberMePressed;
    int numberOfPersonalEmployee;

    // запись данных в векторы из файлов
    writingToVectorsFromFileAuth(authentication);
    writingToVectorsFromFileEmployee(employee); 
    readIsRememberMeOn(isRememberMePressed);
    numberOfPersonalEmployee = readNumberOfPersonalEmployee();


    if (isRememberMePressed)
        auth_menu(authentication, employee, isRememberMePressed);
    else
        main_menu(authentication, employee, isRememberMePressed, numberOfPersonalEmployee);
    
    return 0;
}