#include "structs.h"
#include "enums.h"
#include "prototypes.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>

sf::RenderWindow window(sf::VideoMode(500, 412), "", sf::Style::None);


int main()
{
    srand(time(NULL));

    std::vector<Employee> employee;;
    std::vector<Authentication> authentication;
    // вектор для хранения индексов сотрдуников пенсионного возраста
    std::vector<int> indexes;
    bool isRememberMePressed;

    // запись данных в векторы из файлов
    writingToVectorsFromFileAuth(authentication);
    writingToVectorsFromFileEmployee(employee); 
    wrtiteIsRememberMeOn(isRememberMePressed);


    if (isRememberMePressed)
        auth_menu(authentication, employee, isRememberMePressed);
    else
        main_menu(authentication, employee, isRememberMePressed);
    
    return 0;
}