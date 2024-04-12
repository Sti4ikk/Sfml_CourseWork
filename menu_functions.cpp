#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include "structs.h"
#include "enums.h"
#include "prototypes.h"
#include <iostream>
#include <array>

void printEmployeesLoop(std::vector<int>& indexes, std::vector<Employee>& employee);
extern sf::RenderWindow window;
using namespace sf;

int auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool &isRememberMePressed)
{
    window.create(sf::VideoMode(500, 412), "", sf::Style::None);

    sf::Font font;
    if (!font.loadFromFile("shrift.ttf")) {
        // Обработка ошибки загрузки шрифта
        return EXIT_FAILURE;
    }

    // Создаем прямоугольник размером 70х100
    sf::RectangleShape rectangle1(Vector2f(430.f, 70.f));
    sf::RectangleShape rectangle2(Vector2f(430.f, 70.f));
    sf::RectangleShape rectangle3(Vector2f(430.f, 70.f));
    sf::RectangleShape square(Vector2f(25.f, 25.f));
    sf::RectangleShape line1(Vector2f(1.f, 70.f));
    sf::RectangleShape line2(Vector2f(1.f, 70.f));

    rectangle1.move(35, 80);
    rectangle2.move(35, 160);
    rectangle3.move(35, 255);
    square.move(45, 340);
    line1.move(99, 80);
    line2.move(99, 160);
    // Устанавливаем ему цвет
    rectangle1.setFillColor(Color::Black);
    rectangle2.setFillColor(Color::Black);
    rectangle3.setFillColor(Color(255, 193, 7));
    square.setFillColor(Color(59, 60, 54));
    line1.setFillColor(Color(59, 60, 54));
    line2.setFillColor(Color(59, 60, 54));

    rectangle1.setOutlineThickness(1.f); // толщина контура
    rectangle2.setOutlineThickness(1.f); // толщина контура
    rectangle1.setOutlineColor(sf::Color(59, 60, 54)); // цвет контура
    rectangle2.setOutlineColor(sf::Color(59, 60, 54)); // цвет контура

    sf::Text text(L"Авторизация", font);
    text.setCharacterSize(46); // Установка размера шрифта
    text.setFillColor(sf::Color::White); // Установка цвета текста
    // Установка начального положения текста
    text.setPosition(88.f, 8.f); // Новые координаты (x, y)


    sf::Text entrance(L"Войти", font);
    entrance.setCharacterSize(30); // Установка размера шрифта
    entrance.setFillColor(sf::Color::White); // Установка цвета текста
    entrance.setPosition(188.f, 272.f); // Новые координаты (x, y)

    sf::Text rememberMe(L"Запомнить меня", font);
    rememberMe.setCharacterSize(14); // Установка размера шрифта
    rememberMe.setFillColor(sf::Color(59, 60, 54)); // Установка цвета текста
    rememberMe.setPosition(81.f, 344.f); // Новые координаты (x, y)

    sf::Text login("", font);
    login.setCharacterSize(28); // Установка размера шрифта
    login.setFillColor(sf::Color::White); // Установка цвета текста
    login.setPosition(110.f, 98.f); // Новые координаты (x, y)

    sf::Text password1("", font);
    password1.setCharacterSize(28); // Установка размера шрифта
    password1.setFillColor(sf::Color::White); // Установка цвета текста
    password1.setPosition(110.f, 178.f); // Новые координаты (x, y)

    sf::Text password2("", font);
    password2.setCharacterSize(44); // Установка размера шрифта
    password2.setFillColor(sf::Color::White); // Установка цвета текста
    password2.setPosition(110.f, 178.f); // Новые координаты (x, y)

    sf::Text error(L"Неверный логин или пароль!", font);
    error.setCharacterSize(16); // Установка размера шрифта
    error.setFillColor(sf::Color::Red); // Установка цвета текста
    error.setPosition(126.f, 380.f); // Новые координаты (x, y)



    // Загрузка изображения в текстуру
    sf::Texture texture1;
    if (!texture1.loadFromFile("user.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    // Загрузка изображения в текстуру
    sf::Texture texture2;
    if (!texture2.loadFromFile("password1.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    // Загрузка изображения в текстуру
    sf::Texture texture3;
    if (!texture3.loadFromFile("hide_eye.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture texture4;
    if (!texture4.loadFromFile("open_eye.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture galka;
    if (!galka.loadFromFile("galka.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture krest;
    if (!krest.loadFromFile("krest.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }


    // Создание спрайта и установка текстуры
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);
    sf::Sprite sprite3(texture3);
    sf::Sprite sprite4(texture4);
    sf::Sprite sprite_galka(galka);
    sf::Sprite sprite_krest(krest);

    sprite1.setScale(1.f / 10.f, 1.f / 10.f);
    sprite2.setScale(1.f / 10.f, 1.f / 10.f);
    sprite3.setScale(1.f / 12.f, 1.f / 12.f);
    sprite4.setScale(1.f / 12.f, 1.f / 12.f);
    sprite_galka.setScale(1.f / 19.f, 1.f / 19.f);
    sprite_krest.setScale(1.f / 30.f, 1.f / 30.f);

    // Установка начального положения спрайта
    sprite1.setPosition(42.f, 92.f);
    sprite2.setPosition(43.f, 172.f);
    sprite3.setPosition(416.f, 175.f);
    sprite4.setPosition(416.f, 175.f);
    sprite_galka.setPosition(44.f, 339.f);
    sprite_krest.setPosition(478.f, 6.f);

    // првоерка, какое поле выбрал для ввода
    bool isRectangle1Clicked = false;
    bool isRectangle2Clicked = false;
    bool isPasswordOpen = false;
    bool isTextPasswordOpen = false;
    bool isRememberMeOn = false;
    bool isIncorrectData = false;
    // для перемещения окна
    bool isDragging = false;
    sf::Vector2i clickPosition;
    std::string str_login;
    std::string str_password;
    std::string str_password_close;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_krest.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        window.close();
                }
            }
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();


            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // Запоминаем позицию, в которой была нажата кнопка мыши
                isDragging = true;
                clickPosition = sf::Mouse::getPosition(window);
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                // Когда кнопка мыши отпущена, заканчиваем перетаскивание
                isDragging = false;
            }
            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isIncorrectData = false;
                        isRectangle1Clicked = true;
                        isRectangle2Clicked = false;
                    }
                    else if (rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isIncorrectData = false;
                        isRectangle1Clicked = false;
                        isRectangle2Clicked = true;
                    }
                }
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (rectangle3.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                rectangle3.setFillColor(Color(255, 245, 7));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                rectangle3.setFillColor(Color(255, 193, 7));

            // проверка на галочку
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (square.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isRememberMeOn)
                    {
                        isRememberMeOn = true;
                        isRememberMePressed = false;
                        writeInFileIsRememberOn(isRememberMePressed);
                    }
                    else if (square.getGlobalBounds().contains(mousePos.x, mousePos.y) and isRememberMeOn)
                    {
                        isRememberMeOn = false;
                        isRememberMePressed = true;
                        writeInFileIsRememberOn(isRememberMePressed);
                    }
                }
            }
            /*
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Backspace) {
                    // Удаление предыдущего символа из текстового поля
                    std::string currentText = login.getString();
                    if (!currentText.empty()) {
                        currentText.pop_back();
                        login.setString(currentText);
                    }
                }
            }                                  */

            // ввод текста в поле логин и пароль
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 and isRectangle1Clicked)
                    { // Backspace
                        if (!str_login.empty()) 
                            str_login.pop_back();
                    }
                    else if (isRectangle1Clicked and login.getString().getSize() < 12)
                        str_login += static_cast<char>(event.text.unicode);


                    if (event.text.unicode == 8 and isRectangle2Clicked)
                    { // Backspace
                        if (!str_password.empty())
                        {
                            str_password.pop_back();
                            str_password_close.pop_back();
                        }
                    }
                    else if (isRectangle2Clicked and password1.getString().getSize() < 12)
                    {
                        str_password += static_cast<char>(event.text.unicode);
                        str_password_close += "*";
                    }
                }
                login.setString(str_login);
                password1.setString(str_password);
                password2.setString(str_password_close);
            }
            

            // проверка на нажатие кнопки видимости пароля
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite3.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isPasswordOpen)
                    {
                        isPasswordOpen = true;
                        isTextPasswordOpen = true;
                    }
                    else if (sprite4.getGlobalBounds().contains(mousePos.x, mousePos.y) and isPasswordOpen)
                    {
                        isPasswordOpen = false;
                        isTextPasswordOpen = false;
                    }
                }
            }
            // проверка на правильность введенных данных
            if (event.type == sf::Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    if (rectangle3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::string login1;
                        std::string password5;
                        login1 = login.getString();
                        password5 = password1.getString();
                        
                        if (checkDataOfUser(authentication, login1, password5))
                        {
                            window.close();
                            main_menu(authentication, employee, isRememberMePressed);
                        }
                        else
                        {
                            str_login = "";
                            str_password = "";
                            str_password_close = "";
                            login.setString(str_login);
                            password1.setString(str_password);
                            password2.setString(str_password_close);
                            isIncorrectData = true;
                        }
                    }

                }
            }
        }
       /*if (isDragging)
        {
            // Вычисляем разницу между текущей позицией мыши и позицией, где была нажата кнопка мыши
            sf::Vector2i delta = sf::Mouse::getPosition(window) - clickPosition;
            // Получаем текущее положение окна и сдвигаем его на delta
            window.setPosition(sf::Vector2i(window.getPosition()) + delta);
            // Обновляем позицию clickPosition
            clickPosition = sf::Mouse::getPosition(window);
        }      */

        window.clear(sf::Color(10, 10, 10));
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(square);
        window.draw(line1);
        window.draw(line2);
        window.draw(text);
        window.draw(entrance);
        window.draw(login);
        window.draw(rememberMe);
        if (isTextPasswordOpen) window.draw(password1);
        else window.draw(password2);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite_krest);
        if (isPasswordOpen)  window.draw(sprite4);
        else  window.draw(sprite3);
        if (isRememberMeOn) window.draw(sprite_galka);
        if (isIncorrectData) window.draw(error);
        window.display();
    }
}

void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed)
{
    window.create(sf::VideoMode(1920, 1080), "", sf::Style::None);

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;

    sf::Font font;
    if (!font.loadFromFile("shrift2.ttf"))
        return;


   
    // Создаем массив вершин, который будет содержать три точки
    sf::VertexArray triangle1(sf::Triangles, 3);
    sf::VertexArray triangle2(sf::Triangles, 3);
    sf::VertexArray triangle3(sf::Triangles, 3);
    sf::VertexArray triangle4(sf::Triangles, 3);

    // Определяем вершины треугольника и их цвета
    triangle4[0].position = sf::Vector2f(1445, 540);
    triangle4[1].position = sf::Vector2f(1435, 530);
    triangle4[2].position = sf::Vector2f(1435, 550);
    triangle4[0].color = sf::Color::White;
    triangle4[1].color = sf::Color::White;
    triangle4[2].color = sf::Color::White;

    // Определяем вершины треугольника и их цвета
    triangle3[0].position = sf::Vector2f(1868, 540);
    triangle3[1].position = sf::Vector2f(1878, 530);
    triangle3[2].position = sf::Vector2f(1878, 550);
    triangle3[0].color = sf::Color::White;
    triangle3[1].color = sf::Color::White;
    triangle3[2].color = sf::Color::White;
    // Определяем вершины треугольника и их цвета
    triangle1[0].position = sf::Vector2f(1886, 84);
    triangle1[1].position = sf::Vector2f(1894, 76);
    triangle1[2].position = sf::Vector2f(1878, 76);
    triangle1[0].color = sf::Color::White;
    triangle1[1].color = sf::Color::White;
    triangle1[2].color = sf::Color::White;
    // Определяем вершины треугольника и их цвета
    triangle2[0].position = sf::Vector2f(1886, 76);
    triangle2[1].position = sf::Vector2f(1894, 84);
    triangle2[2].position = sf::Vector2f(1878, 84);
    triangle2[0].color = sf::Color::White;
    triangle2[1].color = sf::Color::White;
    triangle2[2].color = sf::Color::White;

    sf::RectangleShape account(Vector2f(240.f, 90.f));
    sf::RectangleShape polosa(Vector2f(1000.f, 1080.f));
    sf::RectangleShape line1(Vector2f(1.f, 1080.f));

    account.setFillColor(sf::Color(59, 60, 54, 190));
    polosa.setFillColor(sf::Color::White);
    line1.setFillColor(Color(59, 60, 54));


    account.move(1660, 94);
    polosa.move(530, 0);


    sf::Text name("Pixel World", font);
    name.setCharacterSize(24);
    name.setFillColor(sf::Color::White);
    name.setPosition(30.f, 16.f);

    sf::Text text_editing(L"Редактирование", font2);
    text_editing.setCharacterSize(45);
    text_editing.setFillColor(sf::Color::White);
    text_editing.setPosition(45.f, 385.f);

    sf::Text text_proccesing(L"Обработка", font2);
    text_proccesing.setCharacterSize(45);
    text_proccesing.setFillColor(sf::Color::White);
    text_proccesing.setPosition(45.f, 455.f);

    sf::Text text_settings(L"Настройки", font2);
    text_settings.setCharacterSize(45);
    text_settings.setFillColor(sf::Color::White);
    text_settings.setPosition(45.f, 525.f);
    
    sf::Text text_exit(L"Выход", font2);
    text_exit.setCharacterSize(45);
    text_exit.setFillColor(sf::Color::White);
    text_exit.setPosition(45.f, 595.f);

    sf::Text text_account(L"Учётная запись", font2);
    text_account.setCharacterSize(22);
    text_account.setFillColor(sf::Color::White);
    text_account.setPosition(1685.f, 106.f);

    sf::Text text_leave_from_acc(L"Выход из аккаунта", font2);
    text_leave_from_acc.setCharacterSize(22);
    text_leave_from_acc.setFillColor(sf::Color::White);
    text_leave_from_acc.setPosition(1662.f, 140.f);


    sf::Text text_print_all(L"Список сотрудников", font2);
    text_print_all.setCharacterSize(40);
    text_print_all.setFillColor(sf::Color::White);
    text_print_all.setPosition(25.f, 385.f);

    sf::Text text_add_employee(L"Добавить сотрудника", font2);
    text_add_employee.setCharacterSize(40);
    text_add_employee.setFillColor(sf::Color::White);
    text_add_employee.setPosition(25.f, 455.f);

    sf::Text text_edit_info(L"Редактировать данные", font2);
    text_edit_info.setCharacterSize(40);
    text_edit_info.setFillColor(sf::Color::White);
    text_edit_info.setPosition(25.f, 525.f);

    sf::Text text_delete_employee(L"Удалить сотрудника", font2);
    text_delete_employee.setCharacterSize(40);
    text_delete_employee.setFillColor(sf::Color::White);
    text_delete_employee.setPosition(25.f, 595.f);

    sf::Text text_get_back(L"Назад", font2);
    text_get_back.setCharacterSize(40);
    text_get_back.setFillColor(sf::Color::White);
    text_get_back.setPosition(25.f, 665.f);


    sf::Text text_search(L"Поиск", font2);
    text_search.setCharacterSize(40);
    text_search.setFillColor(sf::Color::White);
    text_search.setPosition(25.f, 385.f);

    sf::Text text_sorting(L"Сортировка", font2);
    text_sorting.setCharacterSize(40);
    text_sorting.setFillColor(sf::Color::White);
    text_sorting.setPosition(25.f, 455.f);

    sf::Text text_search1(L"Поиск сотрудников", font2);
    text_search1.setCharacterSize(40);
    text_search1.setFillColor(sf::Color::White);
    text_search1.setPosition(25.f, 525.f);

    sf::Text text_search2(L"пенсионного возраста", font2);
    text_search2.setCharacterSize(40);
    text_search2.setFillColor(sf::Color::White);
    text_search2.setPosition(25.f, 570.f);

    sf::Text text_get_back1(L"Назад", font2);
    text_get_back1.setCharacterSize(40);
    text_get_back1.setFillColor(sf::Color::White);
    text_get_back1.setPosition(25.f, 640.f);


    // ПОИСК
    sf::Text text_search_with_post(L"Поиск по должности", font2);
    text_search_with_post.setCharacterSize(40);
    text_search_with_post.setFillColor(sf::Color::White);
    text_search_with_post.setPosition(25.f, 455.f);

    sf::Text text_search_with_surname(L"Поиск по фамилии", font2);
    text_search_with_surname.setCharacterSize(40);
    text_search_with_surname.setFillColor(sf::Color::White);
    text_search_with_surname.setPosition(25.f, 385.f);

    sf::Text text_search_with_year(L"Поиск по году\nначала работы", font2);
    text_search_with_year.setCharacterSize(40);
    text_search_with_year.setFillColor(sf::Color::White);
    text_search_with_year.setPosition(25.f, 525.f);

    sf::Text text_get_back2(L"Назад", font2);
    text_get_back2.setCharacterSize(40);
    text_get_back2.setFillColor(sf::Color::White);
    text_get_back2.setPosition(25.f, 640.f);

    // СОРТИРОВКА
    sf::Text text_sorting_with_post(L"По должности", font2);
    text_sorting_with_post.setCharacterSize(40);
    text_sorting_with_post.setFillColor(sf::Color::White);
    text_sorting_with_post.setPosition(25.f, 455.f);

    sf::Text text_sorting_with_surname(L"По фамилии", font2);
    text_sorting_with_surname.setCharacterSize(40);
    text_sorting_with_surname.setFillColor(sf::Color::White);
    text_sorting_with_surname.setPosition(25.f, 385.f);

    sf::Text text_sorting_with_experience(L"По стажу", font2);
    text_sorting_with_experience.setCharacterSize(40);
    text_sorting_with_experience.setFillColor(sf::Color::White);
    text_sorting_with_experience.setPosition(25.f, 525.f);

    sf::Text text_get_back3(L"Назад", font2);
    text_get_back3.setCharacterSize(40);
    text_get_back3.setFillColor(sf::Color::White);
    text_get_back3.setPosition(25.f, 595.f);



    sf::Texture acc;
    if (!acc.loadFromFile("acc.png"))
        return;
    sf::Sprite sprite_acc(acc);
    sprite_acc.setScale(1.f / 7.f, 1.f / 7.f);
    sprite_acc.setPosition(1810, 15);

    sf::Texture shtorka;
    if (!shtorka.loadFromFile("shtorka1.png"))
        return;
    sf::Sprite sprite_shtorka(shtorka);
    sprite_shtorka.setScale(0.6, 0.6);
    sprite_shtorka.setPosition(1888, 386);


    sf::Texture shtorka1;
    if (!shtorka1.loadFromFile("shtorka1.png"))
        return;
    sf::Sprite sprite_shtorka1(shtorka1);
    sprite_shtorka1.setScale(0.6, 0.6);
    sprite_shtorka1.setPosition(1426, 386);

    sf::Texture shtorka_orange1;
    if (!shtorka_orange1.loadFromFile("shtorka_orange.png"))
        return;
    sf::Sprite sprite_shtorka_orange1(shtorka_orange1);
    sprite_shtorka_orange1.setScale(0.6, 0.6);
    sprite_shtorka_orange1.setPosition(1426, 386);



    sf::Texture shtorka_orange;
    if (!shtorka_orange.loadFromFile("shtorka_orange.png"))
        return;
    sf::Sprite sprite_shtorka_orange(shtorka_orange);
    sprite_shtorka_orange.setScale(0.6, 0.6);
    sprite_shtorka_orange.setPosition(1888, 386);

    sf::Texture bg_news;
    if (!bg_news.loadFromFile("bg_news4.png"))
        return;
    sf::Sprite sprite_bg_news(bg_news);
    sprite_bg_news.setScale(0.5, 0.5);
    sprite_bg_news.setPosition(1330, 192);

   
    sf::Texture logo;
    if (!logo.loadFromFile("logo10_4.png"))
        return;
    sf::Sprite sprite_logo(logo);
    sprite_logo.setScale(0.8, 0.8);
    sprite_logo.setPosition(570, 130);



    int count = 0;                                                   //СДЕЛАТЬ ФУНКЦИ
    int number;
    int index = 0;
    // массив случайных чисел для отображения случайных новостей
    std::vector<int>numbers;
    numbers.reserve(5);
    for (int i = 0; numbers.size() != 5; i++)
    {
        number = rand() % 9 + 1;

        for (int j = 0; j < numbers.size(); j++)
        {
            if (numbers.at(j) == number)
                count++;
        }

        if (!count)
        {
            numbers.push_back(number);
            index++;
        }


        count = 0;
    }

    sf::Texture news1;
    if (!news1.loadFromFile("news\\news" + std::to_string(numbers.at(0)) + ".png"))
        return;
    sf::Sprite sprite_news1(news1);
    sprite_news1.setScale(0.26, 0.26);
    sprite_news1.setPosition(1485, 150);

    sf::Texture news2;
    if (!news2.loadFromFile("news\\news" + std::to_string(numbers.at(1)) + ".png"))
        return;
    sf::Sprite sprite_news2(news2);
    sprite_news2.setScale(0.26, 0.26);
    sprite_news2.setPosition(1485, 280);

    sf::Texture news3;
    if (!news3.loadFromFile("news\\news" + std::to_string(numbers.at(2)) + ".png"))
        return;
    sf::Sprite sprite_news3(news3);
    sprite_news3.setScale(0.26, 0.26);
    sprite_news3.setPosition(1485, 420);

    sf::Texture news4;
    if (!news4.loadFromFile("news\\news" + std::to_string(numbers.at(3)) + ".png"))
        return;
    sf::Sprite sprite_news4(news4);
    sprite_news4.setScale(0.26, 0.26);
    sprite_news4.setPosition(1485, 540);

    sf::Texture news5;
    if (!news5.loadFromFile("news\\news" + std::to_string(numbers.at(4)) + ".png"))
        return;
    sf::Sprite sprite_news5(news5);
    sprite_news5.setScale(0.26, 0.26);
    sprite_news5.setPosition(1485, 670);

                                       

    bool isAccPressed = false;
    bool isMouseOnShtorka = false;
    bool isMouseOnShtorka1 = false;
    bool triangleIsMouseOnShtorka1 = false;
    bool triangleIsMouseOnShtorka = false;
    bool isNewsOpen = false;
    bool editingMode = false;
    bool proccesingMode = false;

    bool isSearchPressed = false;
    bool isSortingPressed = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            // закрытие приложения
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen and !editingMode and !proccesingMode)
                        window.close();
                }
            }


            // подсвечивание кнопок при наведении на них
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_shtorka.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                // Изменение цвета прямоугольника, если курсор находится над ним
                isMouseOnShtorka = true;
                triangleIsMouseOnShtorka = true;
            }
            else
            {
                triangleIsMouseOnShtorka = false;
                isMouseOnShtorka = false;
            }

            // проерка на подсвечивание шторки после открытия новостей
            if (sprite_shtorka1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                // Изменение цвета прямоугольника, если курсор находится над ним
                isMouseOnShtorka1 = true;
                triangleIsMouseOnShtorka1 = true;
            }
            else
            {
                triangleIsMouseOnShtorka1 = false;
                isMouseOnShtorka1 = false;
            }

            if (text_editing.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_editing.setFillColor(Color(255, 51, 6));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_editing.setFillColor(sf::Color::White);
            if (text_proccesing.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_proccesing.setFillColor(Color(255, 51, 6));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_proccesing.setFillColor(sf::Color::White);
            if (text_settings.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_settings.setFillColor(Color(255, 51, 6));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_settings.setFillColor(sf::Color::White);
            if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_exit.setFillColor(Color(255, 51, 6));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_exit.setFillColor(sf::Color::White);
            if (text_account.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_account.setFillColor(Color(255, 51, 6));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_account.setFillColor(sf::Color::White);
            if (text_leave_from_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_leave_from_acc.setFillColor(Color(255, 51, 6));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_leave_from_acc.setFillColor(sf::Color::White);

            if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                triangle1[0].color = sf::Color(255, 51, 6);
                triangle1[1].color = sf::Color(255, 51, 6);
                triangle1[2].color = sf::Color(255, 51, 6);
            }
            else
            {
                triangle1[0].color = sf::Color::White;
                triangle1[1].color = sf::Color::White;
                triangle1[2].color = sf::Color::White;
            }
            if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                triangle2[0].color = sf::Color(255, 51, 6);
                triangle2[1].color = sf::Color(255, 51, 6);
                triangle2[2].color = sf::Color(255, 51, 6);
            }
            else
            {
                triangle2[0].color = sf::Color::White;
                triangle2[1].color = sf::Color::White;
                triangle2[2].color = sf::Color::White;
            }
            if (text_print_all.getGlobalBounds().contains(mousePos.x, mousePos.y) and editingMode)
                text_print_all.setFillColor(Color(255, 51, 6));
            else
                text_print_all.setFillColor(sf::Color::White);
            if (text_add_employee.getGlobalBounds().contains(mousePos.x, mousePos.y) and editingMode)
                text_add_employee.setFillColor(Color(255, 51, 6));
            else
                text_add_employee.setFillColor(sf::Color::White);
            if (text_edit_info.getGlobalBounds().contains(mousePos.x, mousePos.y) and editingMode)
                text_edit_info.setFillColor(Color(255, 51, 6));
            else
                text_edit_info.setFillColor(sf::Color::White);
            if (text_delete_employee.getGlobalBounds().contains(mousePos.x, mousePos.y) and editingMode)
                text_delete_employee.setFillColor(Color(255, 51, 6));
            else
                text_delete_employee.setFillColor(sf::Color::White);
            if (text_get_back.getGlobalBounds().contains(mousePos.x, mousePos.y) and editingMode)
                text_get_back.setFillColor(Color(255, 51, 6));
            else
                text_get_back.setFillColor(sf::Color::White);

            if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and proccesingMode)
                text_search.setFillColor(Color(255, 51, 6));
            else
                text_search.setFillColor(sf::Color::White);
            if (text_sorting.getGlobalBounds().contains(mousePos.x, mousePos.y) and proccesingMode)
                text_sorting.setFillColor(Color(255, 51, 6));
            else
                text_sorting.setFillColor(sf::Color::White);
            if ((text_search1.getGlobalBounds().contains(mousePos.x, mousePos.y) or text_search2.getGlobalBounds().contains(mousePos.x, mousePos.y)) and proccesingMode)
            {
                text_search1.setFillColor(Color(255, 51, 6));
                text_search2.setFillColor(Color(255, 51, 6));
            }
            else
            {
                text_search1.setFillColor(sf::Color::White);
                text_search2.setFillColor(sf::Color::White);
            }
            if (text_get_back1.getGlobalBounds().contains(mousePos.x, mousePos.y) and proccesingMode)
                text_get_back1.setFillColor(Color(255, 51, 6));
            else
                text_get_back1.setFillColor(sf::Color::White);
                                                // подсветка кнопок в меню ПОИСК
            if (text_search_with_surname.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSearchPressed)
                text_search_with_surname.setFillColor(Color(255, 51, 6));
            else
                text_search_with_surname.setFillColor(sf::Color::White);
            if (text_search_with_post.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSearchPressed)
                text_search_with_post.setFillColor(Color(255, 51, 6));
            else
                text_search_with_post.setFillColor(sf::Color::White);
            if (text_search_with_year.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSearchPressed)
                text_search_with_year.setFillColor(Color(255, 51, 6));
            else
                text_search_with_year.setFillColor(sf::Color::White);
            if (text_get_back2.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSearchPressed)
                text_get_back2.setFillColor(Color(255, 51, 6));
            else
                text_get_back2.setFillColor(sf::Color::White);
                                                            // подсветка кнопок в меню СОРТИРОВКА
            if (text_sorting_with_surname.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSortingPressed)
                text_sorting_with_surname.setFillColor(Color(255, 51, 6));
            else
                text_sorting_with_surname.setFillColor(sf::Color::White);
            if (text_sorting_with_post.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSortingPressed)
                text_sorting_with_post.setFillColor(Color(255, 51, 6));
            else
                text_sorting_with_post.setFillColor(sf::Color::White);
            if (text_sorting_with_experience.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSortingPressed)
                text_sorting_with_experience.setFillColor(Color(255, 51, 6));
            else
                text_sorting_with_experience.setFillColor(sf::Color::White);
            if (text_get_back3.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSortingPressed)
                text_get_back3.setFillColor(Color(255, 51, 6));
            else
                text_get_back3.setFillColor(sf::Color::White);
            
            // проверка на кнопку НАЗАД
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_get_back.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !proccesingMode)
                        editingMode = false;

                }
            }



            // проверка на нажатие на ПОИСК ПО ФАМИЛИИ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_search_with_surname.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSearchPressed)
                        searchEmployeeWithSurname_menu(employee);
                }
            }
            // проверка на нажатие на ПОИСК ПО ДОЛЖНОСТИ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_search_with_post.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSearchPressed)
                        searchEmployeeWithPost_menu(employee);
                }
            }
            // проверка на нажатие на ПОИСК ПО ГОДУ НАЧАЛА РАБОТЫ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_search_with_year.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSearchPressed)
                        searchEmployeeWithStartYear_menu(employee);
                }
            }



                                                                            // ПОИСК
                // проверка на кнопку ПОИСК
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSortingPressed and proccesingMode)
                        isSearchPressed = true;
                }
            }
            // проверка на кнопку НАЗАД
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_get_back2.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSortingPressed)
                        isSearchPressed = false;

                }
            } 
                                                                    //СОРТИРОВКА
                 // проверка на кнопку ПОИСК
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_sorting.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSearchPressed and proccesingMode)
                        isSortingPressed = true;
                }
            }
            // проверка на кнопку НАЗАД
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_get_back3.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSearchPressed)
                        isSortingPressed = false;

                }
            }



            // проверка на кнопку ВЫВЕСТИ ВСЕХ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_print_all.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and editingMode)
                        printAllEmployees_menu(employee);
                }
            }

            // проверка на кнопку ДОБАВЛЕНИЕ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_add_employee.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and editingMode)
                        addNewEmployee_menu(employee);
                }
            }

            // проверка на кнопку РЕДАКТИРОВАНИЕ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_edit_info.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and editingMode)
                        editInfoOfEmployee_menu(employee);
                }
            }

            // проверка на кнопку УДАЛИТЬ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_delete_employee.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and editingMode)
                        deleteEmployee_menu(employee);
                }
            }

            // проверка на кнопку НАЗАД
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_get_back1.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode)
                        proccesingMode = false;

                }
            }

            // проверка на нажатие иконки АККАУНТ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed)
                        isAccPressed = true;
                    else if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y) and isAccPressed)
                        isAccPressed = false;
                }
            }

            // проверка на нажатие на новости
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_shtorka_orange.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen)
                        isNewsOpen = true;

                    else if (sprite_shtorka_orange1.getGlobalBounds().contains(mousePos.x, mousePos.y) and isNewsOpen)
                        isNewsOpen = false;
                }
            }

            // проверка на нажатие на выход из аккаунта
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_leave_from_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))  // тут убрал !isNewsOpen
                    {
                        isRememberMePressed = 1;
                        writeInFileIsRememberOn(isRememberMePressed);
                        auth_menu(authentication, employee, isRememberMePressed);
                    }
                }
            }

            // проверка на нажатие на НАСТРОЙКИ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_settings.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen and !editingMode and !proccesingMode)
                        settings_menu();
                }
            }

            // проверка на нажатие на РЕДАКТИРОВАНИЕ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_editing.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen and !editingMode and !proccesingMode)
                        editingMode = true;
                }
            }

            // проверка на нажатие на ОБРАБОТКА
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_proccesing.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen and !proccesingMode and !editingMode)
                        proccesingMode = true;
                }
            }

                                                                          

        }

        window.clear(sf::Color::Black);
        window.draw(name);
        window.draw(sprite_acc);
        if (!editingMode and !proccesingMode)
        {
            line1.setPosition(490, 0);
            window.draw(text_editing);
            window.draw(text_proccesing);
            window.draw(text_exit);
            window.draw(text_settings);
        }
        else if(!proccesingMode and editingMode)
        {
            line1.setPosition(560, 0);
            window.draw(text_print_all);
            window.draw(text_add_employee);
            window.draw(text_edit_info);
            window.draw(text_delete_employee);
            window.draw(text_get_back);
        }
        else if (proccesingMode and isSortingPressed)
        {
            line1.setPosition(380, 0);
            window.draw(text_sorting_with_post);
            window.draw(text_sorting_with_surname);
            window.draw(text_sorting_with_experience);
            window.draw(text_get_back3);
        }
        else if (proccesingMode and isSearchPressed)
        {
            line1.setPosition(530, 0);
            window.draw(text_search_with_post);
            window.draw(text_search_with_surname);
            window.draw(text_search_with_year);
            window.draw(text_get_back2);
        }
        else if (proccesingMode and !editingMode)
        {
            line1.setPosition(540, 0);
            window.draw(text_search);
            window.draw(text_sorting);
            window.draw(text_search1);
            window.draw(text_search2);
            window.draw(text_get_back1);
        }

        if (isAccPressed)
        {
            window.draw(triangle2);
            window.draw(account);
            window.draw(text_account);
            window.draw(text_leave_from_acc);
        }
        else
            window.draw(triangle1);

        if (triangleIsMouseOnShtorka and !isNewsOpen)
            window.draw(triangle3);

        if (isMouseOnShtorka and !isNewsOpen)
            window.draw(sprite_shtorka_orange);
        else if(!isNewsOpen)
            window.draw(sprite_shtorka);

        if (isNewsOpen)
        {
            window.draw(sprite_shtorka1);
            window.draw(sprite_bg_news);

            window.draw(sprite_news1);
            window.draw(sprite_news2);
            window.draw(sprite_news3);
            window.draw(sprite_news4);
            window.draw(sprite_news5);

            if (isMouseOnShtorka1)
                window.draw(sprite_shtorka_orange1);
            else
                window.draw(sprite_shtorka1);

            if (triangleIsMouseOnShtorka1)
                window.draw(triangle4);
        }


        window.draw(sprite_logo);
        window.draw(line1);
        window.display();
    }
}

void settings_menu()
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf")) 
        return;


    sf::Text text_settigns(L"НАСТРОЙКИ", font2);
    text_settigns.setCharacterSize(64);
    text_settigns.setFillColor(sf::Color::White);
    text_settigns.setPosition(730.f, 50.f);

    sf::Text text_about_app(L"О приложении", font2);
    text_about_app.setCharacterSize(46);
    text_about_app.setFillColor(sf::Color::Black);
    text_about_app.setPosition(776.f, 310.f);

    sf::Text text_about_company(L"О компании", font2);
    text_about_company.setCharacterSize(46);
    text_about_company.setFillColor(sf::Color::Black);
    text_about_company.setPosition(800.f, 500.f);

    sf::Text text_tech_support(L"Техподдержка", font2);
    text_tech_support.setCharacterSize(46);
    text_tech_support.setFillColor(sf::Color::Black);
    text_tech_support.setPosition(766.f, 690.f);




    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);

    sf::Texture rectangle1;
    if (!rectangle1.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_rectangle1(rectangle1);
    sprite_rectangle1.setScale(0.6, 0.6);
    sprite_rectangle1.setPosition(560, 260);

    sf::Texture rectangle2;
    if (!rectangle2.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_rectangle2(rectangle2);
    sprite_rectangle2.setScale(0.6, 0.6);
    sprite_rectangle2.setPosition(560, 450);

    sf::Texture rectangle3;
    if (!rectangle3.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_rectangle3(rectangle3);
    sprite_rectangle3.setScale(0.6, 0.6);
    sprite_rectangle3.setPosition(560, 640);

    sf::Texture rectangle_orange;
    if (!rectangle_orange.loadFromFile("rectangle_orange.png"))
        return;
    sf::Sprite sprite_rectangle_orange(rectangle_orange);
    sprite_rectangle_orange.setScale(0.2437, 0.2437);

    

    bool isMouseOnArrow = false;
    bool isMouseOnRectangle1 = false;
    bool isMouseOnRectangle2 = false;
    bool isMouseOnRectangle3 = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }
            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            if (sprite_rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle1 = true;
            else
                isMouseOnRectangle1 = false;
            if (sprite_rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle2 = true;
            else
                isMouseOnRectangle2 = false;
            if (sprite_rectangle3.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle3= true;
            else
                isMouseOnRectangle3 = false;

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        aboutApp();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        aboutCompany();
                }
            }
            
           
        }
        sprite_rectangle_orange.setPosition(560, 640);




        window.clear(sf::Color::Black);
        //window.draw(sprite_logo);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);

        if (isMouseOnRectangle1)
        {
            sprite_rectangle_orange.setPosition(560, 260);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_rectangle1);
        if (isMouseOnRectangle2)
        {
            sprite_rectangle_orange.setPosition(560, 450);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_rectangle2);
        if (isMouseOnRectangle3)
        {
            sprite_rectangle_orange.setPosition(560, 640);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_rectangle3);

            

        window.draw(text_settigns);
        window.draw(text_tech_support);
        window.draw(text_about_app);
        window.draw(text_about_company);
        window.display();
    }
}

void aboutApp()
{
    sf::Font font2;              
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_name_Of_app(L"Название приложения : Учет стажа сотрудников", font2);
    text_name_Of_app.setCharacterSize(34);
    text_name_Of_app.setFillColor(sf::Color::White);
    text_name_Of_app.setPosition(500.f, 200.f);

    sf::Text text_description_Of_app1(L"Описание: Наше приложение предназначено для учета и отслеживания стажа работы ", font2);
    text_description_Of_app1.setCharacterSize(34);
    text_description_Of_app1.setFillColor(sf::Color::White);
    text_description_Of_app1.setPosition(130.f, 320.f);

    sf::Text text_description_Of_app2(L"сотрудников на предприятии. Оно поможет вам следить за датами приема на работу,", font2);
    text_description_Of_app2.setCharacterSize(34);
    text_description_Of_app2.setFillColor(sf::Color::White);
    text_description_Of_app2.setPosition(128.f, 390.f);

    sf::Text text_description_Of_app3(L"периодами отпусков и другими важными событиями в трудовой биографии сотрудников.", font2);
    text_description_Of_app3.setCharacterSize(34);
    text_description_Of_app3.setFillColor(sf::Color::White);
    text_description_Of_app3.setPosition(100.f, 460.f);

    sf::Text text_contacts1(L"Контакты: Если у вас есть вопросы или предложения, свяжитесь с нами по адресу", font2);
    text_contacts1.setCharacterSize(34);
    text_contacts1.setFillColor(sf::Color::White);
    text_contacts1.setPosition(160.f, 580.f);

    sf::Text text_contacts2(L"support@companytracker.com", font2);
    text_contacts2.setCharacterSize(34);
    text_contacts2.setFillColor(sf::Color::White);
    text_contacts2.setPosition(660.f, 650.f);

    sf::Text text_license(L"Лицензия и авторские права: © 2024 Учет стажа сотрудников", font2);
    text_license.setCharacterSize(26);
    text_license.setFillColor(sf::Color::White);
    text_license.setPosition(500.f, 1020.f);



    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    bool isMouseOnArrow = false;
    while (window.isOpen())
    {
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }

            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;


        }

        window.clear(sf::Color::Black);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);

        window.draw(text_description_Of_app1);
        window.draw(text_description_Of_app2);
        window.draw(text_description_Of_app3);
        window.draw(text_contacts1);
        window.draw(text_contacts2);
        window.draw(text_name_Of_app);
        window.draw(text_license);
        window.display();
    }
}

void aboutCompany()
{
    float scrollPosition = 0.0f;

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;
    sf::Font font;
    if (!font.loadFromFile("shrift2.ttf"))
        return;


    sf::Text text_name_Of_company(L"Pixel World", font);
    text_name_Of_company.setCharacterSize(64);
    text_name_Of_company.setFillColor(sf::Color::White);

    sf::Text text_history1(L"“Pixel World” была основана в 2010 году группой энтузиастов, объединенных общей страстью", font2);
    text_history1.setCharacterSize(34);
    text_history1.setFillColor(sf::Color::White);

    sf::Text text_history2(L"к видеоиграм. От скромных начинаний в гараже мы выросли в успешную компанию", font2);
    text_history2.setCharacterSize(34);
    text_history2.setFillColor(sf::Color::White);

    sf::Text text_history3(L"с международным признанием.", font2);
    text_history3.setCharacterSize(34);
    text_history3.setFillColor(sf::Color::White);

    sf::Text text_mission1(L"Мы стремимся создавать увлекательные, креативные и инновационные игры,", font2);
    text_mission1.setCharacterSize(34);
    text_mission1.setFillColor(sf::Color::White);

    sf::Text text_mission2(L"которые приносят радость и развлечение нашим игрокам.", font2);
    text_mission2.setCharacterSize(34);
    text_mission2.setFillColor(sf::Color::White);
    
    sf::Text text_games1(L"Наша компания специализируется на создании игр для различных платформ, ", font2);
    text_games1.setCharacterSize(34);
    text_games1.setFillColor(sf::Color::White);

    sf::Text text_games2(L"включая мобильные устройства, ПК и консоли.", font2);
    text_games2.setCharacterSize(34);
    text_games2.setFillColor(sf::Color::White);

    sf::Text text_type(L"Разрабатываем игры в разных жанрах: от аркад и головоломок до RPG и симуляторов.", font2);
    text_type.setCharacterSize(34);
    text_type.setFillColor(sf::Color::White);

    sf::Text text_advantages1(L"Конкурентные преимущества:", font2);
    text_advantages1.setCharacterSize(34);
    text_advantages1.setFillColor(sf::Color::White);

    sf::Text text_advantages2(L"Уникальный стиль: Наша команда талантливых художников и дизайнеров создает", font2);
    text_advantages2.setCharacterSize(34);
    text_advantages2.setFillColor(sf::Color::White);

    sf::Text text_advantages3(L"узнаваемый пиксельный стиль, который отличает наши игры от других.", font2);
    text_advantages3.setCharacterSize(34);
    text_advantages3.setFillColor(sf::Color::White);

    sf::Text text_advantages4(L"Геймплей и сюжет: Уделяем особое внимание интересному геймплею и захватывающим сюжетам.", font2);
    text_advantages4.setCharacterSize(34);
    text_advantages4.setFillColor(sf::Color::White);

    sf::Text text_partners1(L"Мы сотрудничаем с издателями, платформами и другими игровыми компаниями, такими как", font2);
    text_partners1.setCharacterSize(34);
    text_partners1.setFillColor(sf::Color::White);

    sf::Text text_partners2(L"Windows, Apple, Steam, EpicGames и другими.", font2);
    text_partners2.setCharacterSize(34);
    text_partners2.setFillColor(sf::Color::White);

    sf::Text text_contact_info(L"Контактная информация:", font2);
    text_contact_info.setCharacterSize(34);
    text_contact_info.setFillColor(sf::Color::White);

    sf::Text text_contact_info1(L"Адрес: г. Минск, ул. Геймплейная, 42", font2);
    text_contact_info1.setCharacterSize(30);
    text_contact_info1.setFillColor(sf::Color::White);

    sf::Text text_contact_info2(L"Телефон: +375 29 123 4567", font2);
    text_contact_info2.setCharacterSize(30);
    text_contact_info2.setFillColor(sf::Color::White);

    sf::Text text_contact_info3(L"Электронная почта: info@pixelworldgames.com", font2);
    text_contact_info3.setCharacterSize(30);
    text_contact_info3.setFillColor(sf::Color::White);

    sf::Text text_end(L"Мы гордимся нашей командой и продуктами и с нетерпением ждем новых вызовов и возможностей в мире игр!", font2);
    text_end.setCharacterSize(28);
    text_end.setFillColor(sf::Color::White);

    


    sf::Texture ofice;
    if (!ofice.loadFromFile("ofice.jpg"))
        return;
    sf::Sprite sprite_ofice(ofice);
    sprite_ofice.setScale(0.6, 0.6);
    


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;


            if (event.type == sf::Event::MouseWheelScrolled)
            {
                // Обработка прокрутки колесика мыши
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    // Проверяем, выходит ли текст за границы окна
                    float lastTextBottom = 2600 + text_end.getLocalBounds().height + 15;
                    float windowHeight = window.getSize().y;


                    if (lastTextBottom > windowHeight || lastTextBottom < windowHeight) // Добавлена проверка на случай, если текст не заполняет окно полностью
                    {
                        // Прокрутка вниз
                        if (event.mouseWheelScroll.delta > 0)
                        {

                            scrollPosition += event.mouseWheelScroll.delta * 25.0f;
                            // Проверяем, чтобы scrollPosition не выходил за границы
                            if (scrollPosition >= 0)
                                scrollPosition = 0;
                            if (scrollPosition > 0) // Прокрутка вниз недоступна, если текст уже полностью виден
                                scrollPosition = 0;
                        }
                        // Прокрутка вверх
                        else if (event.mouseWheelScroll.delta < 0 or lastTextBottom < windowHeight) // Добавлена проверка, чтобы позволить прокрутку вверх, если текст не заполняет окно полностью
                        {
                            scrollPosition += event.mouseWheelScroll.delta * 25.0f;
                            // Проверяем, чтобы scrollPosition не выходил за границы
                            float minScrollPosition = windowHeight - lastTextBottom;
                            if (scrollPosition > 0)
                                scrollPosition = 0;
                            if (scrollPosition < minScrollPosition) // Прокрутка вверх недоступна, если достигнут конец текста
                                scrollPosition = minScrollPosition;
                        }
                    }
                }
            }



        }
        text_name_Of_company.setPosition(700.f, 50 + scrollPosition);
        text_history1.setPosition(60.f, 200 + scrollPosition);
        text_history2.setPosition(126.f, 270 + scrollPosition);
        text_history3.setPosition(676.f, 340 + scrollPosition);
        text_mission1.setPosition(200.f, 460 + scrollPosition);
        text_mission2.setPosition(410.f, 530 + scrollPosition);
        text_games1.setPosition(216.f, 650 + scrollPosition);
        text_games2.setPosition(520.f, 720 + scrollPosition);
        text_type.setPosition(120.f,790 + scrollPosition);
        text_advantages1.setPosition(660.f, 910 + scrollPosition);
        text_advantages2.setPosition(170.f, 980 + scrollPosition);
        text_advantages3.setPosition(270.f, 1050 + scrollPosition);
        text_advantages4.setPosition(20.f, 1120 + scrollPosition);
        text_partners1.setPosition(66.f, 1240 + scrollPosition);
        text_partners2.setPosition(520.f, 1310 + scrollPosition);

        sprite_ofice.setPosition(390, 1460 + scrollPosition);

        text_contact_info.setPosition(160.f, 2280 + scrollPosition);
        text_contact_info1.setPosition(220.f, 2350 + scrollPosition);
        text_contact_info2.setPosition(220.f, 2420 + scrollPosition);
        text_contact_info3.setPosition(220.f, 2490 + scrollPosition);
        text_end.setPosition(60.f, 2600 + scrollPosition);



        window.clear(sf::Color::Black);
        window.draw(text_name_Of_company);
        window.draw(text_history1);
        window.draw(text_history2);
        window.draw(text_history3);
        window.draw(text_mission1);
        window.draw(text_mission2);
        window.draw(text_games1);
        window.draw(text_games2);
        window.draw(text_type);
        window.draw(text_advantages1);
        window.draw(text_advantages2);
        window.draw(text_advantages3);
        window.draw(text_advantages4);
        window.draw(text_partners1);
        window.draw(text_partners2);
        window.draw(sprite_ofice);
        window.draw(text_contact_info);
        window.draw(text_contact_info1);
        window.draw(text_contact_info2);
        window.draw(text_contact_info3);
        window.draw(text_end);


        window.display();
    }
}

void printAllEmployees_menu(std::vector<Employee>& employee)
{
    float scrollPosition = 0.0f;
    float y = 0.0f;

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;

            if (event.type == sf::Event::MouseWheelScrolled)
            {
                // Обработка прокрутки колесика мыши
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    // Проверяем, выходит ли текст за границы окна
                    float lastTextBottom = y + 32;
                    float windowHeight = window.getSize().y;
                    if (lastTextBottom > windowHeight || lastTextBottom < windowHeight) // Добавлена проверка на случай, если текст не заполняет окно полностью
                    {
                        // Прокрутка вниз
                        if (event.mouseWheelScroll.delta > 0)
                        {
                            scrollPosition += event.mouseWheelScroll.delta * 25.0f;
                            // Проверяем, чтобы scrollPosition не выходил за границы
                            if (scrollPosition >= 0)
                                scrollPosition = 0;
                            if (scrollPosition > 0) // Прокрутка вниз недоступна, если текст уже полностью виден
                                scrollPosition = 0;
                        }
                        // Прокрутка вверх
                        else if (event.mouseWheelScroll.delta < 0 or lastTextBottom < windowHeight) // Добавлена проверка, чтобы позволить прокрутку вверх, если текст не заполняет окно полностью
                        {
                            scrollPosition += event.mouseWheelScroll.delta * 25.0f;
                            // Проверяем, чтобы scrollPosition не выходил за границы
                            float minScrollPosition = windowHeight - lastTextBottom;
                            if (scrollPosition > 0)
                                scrollPosition = 0;
                            if (scrollPosition < minScrollPosition) // Прокрутка вверх недоступна, если достигнут конец текста
                                scrollPosition = minScrollPosition;
                        }
                    }
                }
            }

        }


        window.clear(sf::Color::Black);
        y = printAllEmployees(employee, scrollPosition);
        window.display();
    }
}

float printAllEmployees(std::vector<Employee>& employee, float scrollPosition)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return 0.0;



    sf::Text text_listOfEmployees(L"Список сотрудников", font2);
    text_listOfEmployees.setCharacterSize(64);
    text_listOfEmployees.setFillColor(sf::Color::White);


    sf::Text employee1(L"", font2);
    employee1.setCharacterSize(32);
    employee1.setFillColor(sf::Color::White);
    employee1.setPosition(30.f, 30.f);


    float x = 120.0;
    float y = 120.0f;
    std::string currentEmployee;

    for (int i = 0; i < employee.size(); i++)
    {
        employee1.setPosition(x, y);
        currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(i).surName + " " + employee.at(i).name + " " + employee.at(i).patronymic + " " + employee.at(i).gender + " " + employee.at(i).dateOfBirthday
            + " " + employee.at(i).departmentName + " " + employee.at(i).startDate;
        employee1.setString(currentEmployee);

        // Проверяем, виден ли текст на экране
        if (y + scrollPosition >= 0 && y + scrollPosition < window.getSize().y)
        {
            // Устанавливаем позицию текста только если он виден
            employee1.setPosition(x, y + scrollPosition);
            text_listOfEmployees.setPosition(570.f, 10.f + scrollPosition);
            window.draw(text_listOfEmployees);
            window.draw(employee1);
        }

        // Обновляем позицию для следующего текста
        y += 50;

        // Если достигнут нижний предел прокрутки, прерываем цикл
        if (y + scrollPosition >= window.getSize().y)
            break;
    }

    return y;   // Возвращаем текущую позицию, которая будет использоваться в следующем вызове
}

void addNewEmployee_menu(std::vector<Employee>& employee)
{

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_add_employee(L"Добавление сотрудника", font2);
    text_add_employee.setCharacterSize(64);
    text_add_employee.setFillColor(sf::Color::White);
    text_add_employee.setPosition(520.f, 30.f);

    sf::Text text_surName(L"Фамилия", font2);
    text_surName.setCharacterSize(42);
    text_surName.setFillColor(sf::Color::White);
    text_surName.setPosition(420.f, 164.f);

    sf::Text text_name(L"Имя", font2);
    text_name.setCharacterSize(42);
    text_name.setFillColor(sf::Color::White);
    text_name.setPosition(480.f, 360.f);

    sf::Text text_patronymic(L"Отчество", font2);
    text_patronymic.setCharacterSize(42);
    text_patronymic.setFillColor(sf::Color::White);
    text_patronymic.setPosition(420.f, 550.f);

    sf::Text text_gender(L"Пол", font2);
    text_gender.setCharacterSize(42);
    text_gender.setFillColor(sf::Color::White);
    text_gender.setPosition(480.f, 740.f);

    sf::Text text_DOB(L"Дата рождения", font2);
    text_DOB.setCharacterSize(42);
    text_DOB.setFillColor(sf::Color::White);
    text_DOB.setPosition(1160.f, 164.f);

    sf::Text text_departmentName(L"Название отдела", font2);
    text_departmentName.setCharacterSize(42);
    text_departmentName.setFillColor(sf::Color::White);
    text_departmentName.setPosition(1150.f, 360.f);

    sf::Text text_post(L"Должность", font2);
    text_post.setCharacterSize(42);
    text_post.setFillColor(sf::Color::White);
    text_post.setPosition(1200.f, 550.f);

    sf::Text text_startDate(L"Дата начала работы", font2);
    text_startDate.setCharacterSize(42);
    text_startDate.setFillColor(sf::Color::White);
    text_startDate.setPosition(1100.f, 740.f);

    sf::Text text_add(L"Добавить", font2);
    text_add.setCharacterSize(50);
    text_add.setFillColor(sf::Color::White);
    text_add.setPosition(1620.f, 970.f);



    std::string str_surName;
    std::string str_name;
    std::string str_patronymic;
    std::string str_startDate;
    std::string str_gender;
    std::string str_date_of_birth;
    std::string str_departmentName;
    std::string str_post;
  
    sf::Text surName("", font2);
    surName.setCharacterSize(38);
    surName.setFillColor(sf::Color::Black);
    surName.setPosition(270.f, 256.f);

    sf::Text name("", font2);
    name.setCharacterSize(38);
    name.setFillColor(sf::Color::Black);
    name.setPosition(270.f, 446.f);

    sf::Text startDate("", font2);
    startDate.setCharacterSize(38);
    startDate.setFillColor(sf::Color::Black);
    startDate.setPosition(1070.f, 826.f);

    sf::Text patronymic("", font2);
    patronymic.setCharacterSize(38);
    patronymic.setFillColor(sf::Color::Black);
    patronymic.setPosition(270.f, 636.f);

    sf::Text gender("", font2);
    gender.setCharacterSize(38);
    gender.setFillColor(sf::Color::Black);
    gender.setPosition(270.f, 826.f);

    sf::Text date_of_birth("", font2);
    date_of_birth.setCharacterSize(38);
    date_of_birth.setFillColor(sf::Color::Black);
    date_of_birth.setPosition(1070.f, 256.f);

    sf::Text departmentName("", font2);
    departmentName.setCharacterSize(38);
    departmentName.setFillColor(sf::Color::Black);
    departmentName.setPosition(1070.f, 446.f);

    sf::Text post("", font2);
    post.setCharacterSize(38);
    post.setFillColor(sf::Color::Black);
    post.setPosition(1070.f, 636.f);



    sf::Texture rectangle1;
    if (!rectangle1.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_surName(rectangle1);
    sprite_surName.setScale(0.5, 0.5);
    sprite_surName.setPosition(200, 210);

    sf::Texture rectangle2;
    if (!rectangle2.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_name(rectangle2);
    sprite_name.setScale(0.5, 0.5);
    sprite_name.setPosition(200, 400);

    sf::Texture rectangle3;
    if (!rectangle3.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_patronymic(rectangle3);
    sprite_patronymic.setScale(0.5, 0.5);
    sprite_patronymic.setPosition(200, 590);

    sf::Texture rectangle4;
    if (!rectangle4.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_gender(rectangle4);
    sprite_gender.setScale(0.5, 0.5);
    sprite_gender.setPosition(200, 780);

    sf::Texture rectangle5;
    if (!rectangle5.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_date_of_birth(rectangle5);
    sprite_date_of_birth.setScale(0.5, 0.5);
    sprite_date_of_birth.setPosition(1000, 210);

    sf::Texture rectangle6;
    if (!rectangle6.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_department_name(rectangle6);
    sprite_department_name.setScale(0.5, 0.5);
    sprite_department_name.setPosition(1000, 400);

    sf::Texture rectangle7;
    if (!rectangle7.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_post(rectangle7);
    sprite_post.setScale(0.5, 0.5);
    sprite_post.setPosition(1000, 590);

    sf::Texture rectangle8;
    if (!rectangle8.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_startDate(rectangle8);
    sprite_startDate.setScale(0.5, 0.5);
    sprite_startDate.setPosition(1000, 780);


    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    bool isMouseOnArrow = false;
    bool isMouseOnTextAdd = false;

    bool sprite_surNameClicked = false;
    bool sprite_nameClicked = false;
    bool sprite_patronymicClicked = false;
    bool sprite_genderClicked = false;
    bool sprite_date_of_birthClicked = false;
    bool sprite_department_nameClicked = false;
    bool sprite_postClicked = false;
    bool sprite_startDateClicked = false;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;
            if (text_add.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnTextAdd = true;
            else
                isMouseOnTextAdd = false;

            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_surName.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        sprite_surNameClicked = true;
                        sprite_nameClicked = false;
                        sprite_patronymicClicked = false;
                        sprite_genderClicked = false;
                        sprite_date_of_birthClicked = false;
                        sprite_department_nameClicked = false;
                        sprite_postClicked = false;
                        sprite_startDateClicked = false;

                    }
                    else if (sprite_name.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        sprite_nameClicked = true;
                        sprite_surNameClicked = false;
                        sprite_patronymicClicked = false;
                        sprite_genderClicked = false;
                        sprite_date_of_birthClicked = false;
                        sprite_department_nameClicked = false;
                        sprite_postClicked = false;
                        sprite_startDateClicked = false;

                    }
                    else if (sprite_patronymic.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        sprite_patronymicClicked = true;
                        sprite_nameClicked = false;
                        sprite_surNameClicked = false;
                        sprite_genderClicked = false;
                        sprite_date_of_birthClicked = false;
                        sprite_department_nameClicked = false;
                        sprite_postClicked = false;
                        sprite_startDateClicked = false;

                    }
                    else if (sprite_gender.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        sprite_genderClicked = true;
                        sprite_nameClicked = false;
                        sprite_patronymicClicked = false;
                        sprite_surNameClicked = false;
                        sprite_date_of_birthClicked = false;
                        sprite_department_nameClicked = false;
                        sprite_postClicked = false;
                        sprite_startDateClicked = false;

                    }
                    else if (sprite_date_of_birth.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        sprite_date_of_birthClicked = true;
                        sprite_nameClicked = false;
                        sprite_patronymicClicked = false;
                        sprite_genderClicked = false;
                        sprite_surNameClicked = false;
                        sprite_department_nameClicked = false;
                        sprite_postClicked = false;
                        sprite_startDateClicked = false;

                    }
                    else if (sprite_department_name.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        sprite_department_nameClicked = true;
                        sprite_nameClicked = false;
                        sprite_patronymicClicked = false;
                        sprite_genderClicked = false;
                        sprite_date_of_birthClicked = false;
                        sprite_surNameClicked = false;
                        sprite_postClicked = false;
                        sprite_startDateClicked = false;

                    }
                    else if (sprite_post.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        sprite_postClicked = true;
                        sprite_nameClicked = false;
                        sprite_patronymicClicked = false;
                        sprite_genderClicked = false;
                        sprite_date_of_birthClicked = false;
                        sprite_department_nameClicked = false;
                        sprite_surNameClicked = false;
                        sprite_startDateClicked = false;

                    }
                    else if (sprite_startDate.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        sprite_startDateClicked = true;
                        sprite_nameClicked = false;
                        sprite_patronymicClicked = false;
                        sprite_genderClicked = false;
                        sprite_date_of_birthClicked = false;
                        sprite_department_nameClicked = false;
                        sprite_postClicked = false;
                        sprite_surNameClicked = false;

                    }
                }
            }


            // ввод текста в поле логин и пароль
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 and sprite_surNameClicked)
                    { // Backspace
                        if (!str_surName.empty())
                            str_surName.pop_back();
                    }
                    else if (sprite_surNameClicked and surName.getString().getSize() < 15)
                        str_surName += static_cast<char>(event.text.unicode);

                    if (event.text.unicode == 8 and sprite_nameClicked)
                    { // Backspace
                        if (!str_name.empty())
                            str_name.pop_back();
                    }
                    else if (sprite_nameClicked and name.getString().getSize() < 15)
                        str_name += static_cast<char>(event.text.unicode);

                    if (event.text.unicode == 8 and sprite_patronymicClicked)
                    { // Backspace
                        if (!str_patronymic.empty())
                            str_patronymic.pop_back();
                    }
                    else if (sprite_patronymicClicked and patronymic.getString().getSize() < 15)
                        str_patronymic += static_cast<char>(event.text.unicode);

                    if (event.text.unicode == 8 and sprite_genderClicked)
                    { // Backspace
                        if (!str_gender.empty())
                            str_gender.pop_back();
                    }
                    else if (sprite_genderClicked and gender.getString().getSize() < 15)
                        str_gender += static_cast<char>(event.text.unicode);

                    if (event.text.unicode == 8 and sprite_date_of_birthClicked)
                    { // Backspace
                        if (!str_date_of_birth.empty())
                            str_date_of_birth.pop_back();
                    }
                    else if (sprite_date_of_birthClicked and date_of_birth.getString().getSize() < 15)
                        str_date_of_birth += static_cast<char>(event.text.unicode);

                    if (event.text.unicode == 8 and sprite_department_nameClicked)
                    { // Backspace
                        if (!str_departmentName.empty())
                            str_departmentName.pop_back();
                    }
                    else if (sprite_department_nameClicked and departmentName.getString().getSize() < 15)
                        str_departmentName += static_cast<char>(event.text.unicode);

                    if (event.text.unicode == 8 and sprite_postClicked)
                    { // Backspace
                        if (!str_post.empty())
                            str_post.pop_back();
                    }
                    else if (sprite_postClicked and post.getString().getSize() < 15)
                        str_post += static_cast<char>(event.text.unicode);

                    if (event.text.unicode == 8 and sprite_startDateClicked)
                    { // Backspace
                        if (!str_startDate.empty())
                            str_startDate.pop_back();
                    }
                    else if (sprite_startDateClicked and startDate.getString().getSize() < 15)
                        str_startDate += static_cast<char>(event.text.unicode);
                }
                surName.setString(str_surName);
                name.setString(str_name);
                patronymic.setString(str_patronymic);
                gender.setString(str_gender);
                date_of_birth.setString(str_date_of_birth);
                departmentName.setString(str_departmentName);
                post.setString(str_post);
                startDate.setString(str_startDate);
            }
           //обработка кнопки добавить
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_add.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        addNewEmployee(employee, str_surName, str_name, str_patronymic, str_gender, str_date_of_birth, str_departmentName, str_post, str_startDate);


                        sf::RenderWindow window2(sf::VideoMode(500, 412), "", sf::Style::None);

                        sf::Text text_success(L"Запись данных прошла успешно!", font2);
                        text_success.setCharacterSize(16);
                        text_success.setFillColor(sf::Color::White);
                        text_success.setPosition(20.f, 100.f);

                        sf::Text text_exit(L"Выйти в меню", font2);
                        text_exit.setCharacterSize(22);
                        text_exit.setFillColor(sf::Color::White);
                        text_exit.setPosition(200.f, 250.f);

                        while (window2.isOpen())
                        {
                            sf::Event event;
                            while (window2.pollEvent(event))
                            {
                                if (event.type == sf::Event::MouseButtonPressed)
                                {
                                    if (event.mouseButton.button == sf::Mouse::Left)
                                    {
                                        sf::Vector2i mousePos = sf::Mouse::getPosition(window2);
                                        if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                                        {
                                            window2.close();
                                            return;
                                        }
                                    }
                                }
                            }

                            window2.clear(sf::Color::Black);
                            window2.draw(text_exit);
                            window2.draw(text_success);
                            window2.display();
                        }


                    }

                }
            }


        }


        window.clear(sf::Color::Black);
        window.draw(text_add_employee);
        window.draw(text_surName);
        window.draw(text_name);
        window.draw(text_patronymic);
        window.draw(text_DOB);
        window.draw(text_departmentName);
        window.draw(text_gender);
        window.draw(text_post);
        window.draw(text_startDate);
        if (isMouseOnTextAdd)
        {
            text_add.setFillColor(sf::Color(255, 51, 6));
            window.draw(text_add);
        }          
        else
        {
            text_add.setFillColor(sf::Color::White);
            window.draw(text_add);
        }

        window.draw(sprite_surName);
        window.draw(sprite_name);
        window.draw(sprite_patronymic);
        window.draw(sprite_gender);
        window.draw(sprite_date_of_birth);
        window.draw(sprite_department_name);
        window.draw(sprite_post);
        window.draw(sprite_startDate);


        window.draw(surName);
        window.draw(name);
        window.draw(patronymic);
        window.draw(gender);
        window.draw(date_of_birth);
        window.draw(departmentName);
        window.draw(post);
        window.draw(startDate);
        
        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);
        window.display();
    }
}

void editInfoOfEmployee_menu(std::vector<Employee>& employee)
{
    float scrollPosition = 0.0f;
    float y = 0.0f;

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;

    sf::RectangleShape line(Vector2f(140.f, 2.f));
    sf::RectangleShape rectangle(Vector2f(90.f, 46.f));
    line.setFillColor(sf::Color::White);
    rectangle.setFillColor(sf::Color(0, 0, 0, 255));


    sf::Text text_choose_number(L"Выберите номер сотрудника из списка, чьи данные вы хотите отредактировать: ", font2);
    text_choose_number.setCharacterSize(32);
    text_choose_number.setFillColor(sf::Color::White);


    sf::Text text_edit_info(L"Редактирование", font2);
    text_edit_info.setCharacterSize(64);
    text_edit_info.setFillColor(sf::Color::White);

    sf::Text text_accept(L"Принять", font2);
    text_accept.setCharacterSize(48);
    text_accept.setFillColor(sf::Color::White);


    sf::Text text_number(L"", font2);
    text_number.setCharacterSize(45);
    text_number.setFillColor(sf::Color::White);


    std::string str_number;
    bool isRectangleClicked = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;


            if (event.type == sf::Event::MouseWheelScrolled)
            {
                // Обработка прокрутки колесика мыши
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    // Проверяем, выходит ли текст за границы окна
                    float lastTextBottom = y + 32;
                    float windowHeight = window.getSize().y;
                    if (lastTextBottom > windowHeight || lastTextBottom < windowHeight) // Добавлена проверка на случай, если текст не заполняет окно полностью
                    {
                        // Прокрутка вниз
                        if (event.mouseWheelScroll.delta > 0)
                        {
                            scrollPosition += event.mouseWheelScroll.delta * 25.0f;
                            // Проверяем, чтобы scrollPosition не выходил за границы
                            if (scrollPosition >= 0)
                                scrollPosition = 0;
                            if (scrollPosition > 0) // Прокрутка вниз недоступна, если текст уже полностью виден
                                scrollPosition = 0;
                        }
                        // Прокрутка вверх
                        else if (event.mouseWheelScroll.delta < 0 or lastTextBottom < windowHeight) // Добавлена проверка, чтобы позволить прокрутку вверх, если текст не заполняет окно полностью
                        {
                            scrollPosition += event.mouseWheelScroll.delta * 25.0f;
                            // Проверяем, чтобы scrollPosition не выходил за границы
                            float minScrollPosition = windowHeight - lastTextBottom;
                            if (scrollPosition > 0)
                                scrollPosition = 0;
                            if (scrollPosition < minScrollPosition) // Прокрутка вверх недоступна, если достигнут конец текста
                                scrollPosition = minScrollPosition;
                        }
                    }
                }
            }

            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isRectangleClicked = true;
                }
            }

            // проверка на поле для ПРИНЯТЬ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_accept.getGlobalBounds().contains(mousePos.x, mousePos.y) and !str_number.empty())
                    {
                        editMode(employee, str_number);
                    }

                }
            }

            // ввод текста в поле цифры
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 and isRectangleClicked)
                    { // Backspace
                        if (!str_number.empty())
                            str_number.pop_back();
                    }
                    else if (isRectangleClicked and text_number.getString().getSize() < 4)
                        str_number += static_cast<char>(event.text.unicode);
                }
                text_number.setString(str_number);

            }

            // ПОДСВЕЧИВАНИЕ КНОПКИ ПРИНЯТЬ
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (text_accept.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_accept.setFillColor(Color(255, 51, 6));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_accept.setFillColor(sf::Color::White);



        }
        text_choose_number.setPosition(20.f, 180.f + scrollPosition);
        text_edit_info.setPosition(660.f, 30.f + scrollPosition);
        text_number.setPosition(1484.f, 170.f + scrollPosition);
        line.setPosition(1480.f, 226.f + scrollPosition);
        rectangle.setPosition(1474, 180 + scrollPosition);
        text_accept.setPosition(1650, 170 + scrollPosition);


        window.clear(sf::Color::Black);
        y = printAllEmployeesForEditingAndDeleting(employee, scrollPosition);

        window.draw(text_edit_info);
        window.draw(text_accept);
        window.draw(text_choose_number);
        window.draw(rectangle);
        window.draw(line);
        window.draw(text_number);

        window.display();
    }
}

void editMode(std::vector<Employee> &employee, std::string str_number)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_choise(L"Выберите, что хотите отредактировать", font2);
    text_choise.setCharacterSize(46);
    text_choise.setFillColor(sf::Color::White);
    text_choise.setPosition(450.f, 30.f);

    sf::Text text_surName(L"Фамилия", font2);
    text_surName.setCharacterSize(46);
    text_surName.setFillColor(sf::Color::Black);
    text_surName.setPosition(420.f, 250.f);

    sf::Text text_name(L"Имя", font2);
    text_name.setCharacterSize(46);
    text_name.setFillColor(sf::Color::Black);
    text_name.setPosition(470.f, 440.f);

    sf::Text text_patronymic(L"Отчество", font2);
    text_patronymic.setCharacterSize(46);
    text_patronymic.setFillColor(sf::Color::Black);
    text_patronymic.setPosition(420.f, 630.f);

    sf::Text text_gender(L"Пол", font2);
    text_gender.setCharacterSize(46);
    text_gender.setFillColor(sf::Color::Black);
    text_gender.setPosition(470.f, 820.f);

    sf::Text text_DOB(L"Дата рождения", font2);
    text_DOB.setCharacterSize(46);
    text_DOB.setFillColor(sf::Color::Black);
    text_DOB.setPosition(1150.f, 250.f);

    sf::Text text_departmentName(L"Название отдела", font2);
    text_departmentName.setCharacterSize(46);
    text_departmentName.setFillColor(sf::Color::Black);
    text_departmentName.setPosition(1120.f, 440.f);

    sf::Text text_post(L"Должность", font2);
    text_post.setCharacterSize(46);
    text_post.setFillColor(sf::Color::Black);
    text_post.setPosition(1190.f, 630.f);

    sf::Text text_startDate(L"Дата начала работы", font2);
    text_startDate.setCharacterSize(46);
    text_startDate.setFillColor(sf::Color::Black);
    text_startDate.setPosition(1070.f, 820.f);




    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);

    // ПРЯМОУГОЛЬНИКИ
    sf::Texture rectangle1;
    if (!rectangle1.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_surName(rectangle1);
    sprite_surName.setScale(0.5, 0.5);
    sprite_surName.setPosition(200, 210);

    sf::Texture rectangle2;
    if (!rectangle2.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_name(rectangle2);
    sprite_name.setScale(0.5, 0.5);
    sprite_name.setPosition(200, 400);

    sf::Texture rectangle3;
    if (!rectangle3.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_patronymic(rectangle3);
    sprite_patronymic.setScale(0.5, 0.5);
    sprite_patronymic.setPosition(200, 590);

    sf::Texture rectangle4;
    if (!rectangle4.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_gender(rectangle4);
    sprite_gender.setScale(0.5, 0.5);
    sprite_gender.setPosition(200, 780);

    sf::Texture rectangle5;
    if (!rectangle5.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_date_of_birth(rectangle5);
    sprite_date_of_birth.setScale(0.5, 0.5);
    sprite_date_of_birth.setPosition(1000, 210);

    sf::Texture rectangle6;
    if (!rectangle6.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_department_name(rectangle6);
    sprite_department_name.setScale(0.5, 0.5);
    sprite_department_name.setPosition(1000, 400);

    sf::Texture rectangle7;
    if (!rectangle7.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_post(rectangle7);
    sprite_post.setScale(0.5, 0.5);
    sprite_post.setPosition(1000, 590);

    sf::Texture rectangle8;
    if (!rectangle8.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_startDate(rectangle8);
    sprite_startDate.setScale(0.5, 0.5);
    sprite_startDate.setPosition(1000, 780);

    //ОРАНЖЕВЫЕ СПРАЙТЫ
    sf::Texture rectangle_orange;
    if (!rectangle_orange.loadFromFile("rectangle_orange.png"))
        return;
    sf::Sprite sprite_rectangle_orange(rectangle_orange);
    sprite_rectangle_orange.setScale(0.21, 0.21);


    bool isMouseOnArrow = false;
    bool isMouseOnRectangle1 = false;
    bool isMouseOnRectangle2 = false;
    bool isMouseOnRectangle3 = false;
    bool isMouseOnRectangle4 = false;
    bool isMouseOnRectangle5 = false;
    bool isMouseOnRectangle6 = false;
    bool isMouseOnRectangle7 = false;
    bool isMouseOnRectangle8 = false;

    int kindOfFIeld;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }

            //ПРОВЕРКА НА НАЖАТИЕ НА ПРЯМОУГОЛЬНИКИ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_surName.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        kindOfFIeld = 1;

                    else if (sprite_name.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        kindOfFIeld = 2;
                    else if (sprite_patronymic.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        kindOfFIeld = 3;
                    else if (sprite_gender.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        kindOfFIeld = 4;
                    else if (sprite_date_of_birth.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        kindOfFIeld = 5;
                    else if (sprite_department_name.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        kindOfFIeld = 6;
                    else if (sprite_post.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        kindOfFIeld = 7;
                    else if (sprite_startDate.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        kindOfFIeld = 8;
                }
                enterNewInfo_editMode(employee, str_number, kindOfFIeld);
            }


            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            if (sprite_surName.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle1 = true;
            else
                isMouseOnRectangle1 = false;
            if (sprite_name.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle2 = true;
            else
                isMouseOnRectangle2 = false;
            if (sprite_patronymic.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle3 = true;
            else
                isMouseOnRectangle3 = false;
            if (sprite_gender.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle4 = true;
            else
                isMouseOnRectangle4 = false;
            if (sprite_date_of_birth.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle5 = true;
            else
                isMouseOnRectangle5 = false;
            if (sprite_department_name.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle6 = true;
            else
                isMouseOnRectangle6 = false;
            if (sprite_post.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle7 = true;
            else
                isMouseOnRectangle7 = false;
            if (sprite_startDate.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle8 = true;
            else
                isMouseOnRectangle8 = false;
        }

        window.clear(sf::Color::Black);
        
        //СПРАЙТЫ
        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);

        if (isMouseOnRectangle1)
        {
            sprite_rectangle_orange.setPosition(200, 210);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_surName);
        if (isMouseOnRectangle2)
        {
            sprite_rectangle_orange.setPosition(200, 400);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_name);
        if (isMouseOnRectangle3)
        {
            sprite_rectangle_orange.setPosition(200, 590);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_patronymic);
        if (isMouseOnRectangle4)
        {
            sprite_rectangle_orange.setPosition(200, 780);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_gender);
        if (isMouseOnRectangle5)
        {
            sprite_rectangle_orange.setPosition(1000, 210);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_date_of_birth);
        if (isMouseOnRectangle6)
        {
            sprite_rectangle_orange.setPosition(1000, 400);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_department_name);
        if (isMouseOnRectangle7)
        {
            sprite_rectangle_orange.setPosition(1000, 590);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_post);
        if (isMouseOnRectangle8)
        {
            sprite_rectangle_orange.setPosition(1000, 780);
            window.draw(sprite_rectangle_orange);
        }
        else
            window.draw(sprite_startDate);

        window.draw(text_choise);
        window.draw(text_surName);
        window.draw(text_name);
        window.draw(text_patronymic);
        window.draw(text_DOB);
        window.draw(text_departmentName);
        window.draw(text_gender);
        window.draw(text_post);
        window.draw(text_startDate);

        window.display();
    }
}

void enterNewInfo_editMode(std::vector<Employee>& employee, std::string str_number, int kindOfField)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    std::string str_newInfo;

    sf::Text text_newInfo("", font2);
    text_newInfo.setCharacterSize(48);
    text_newInfo.setFillColor(sf::Color::Black);
    text_newInfo.setPosition(638.f, 450.f);

    sf::Text text_enterNewInfo(L"Введите новую информацию", font2);
    text_enterNewInfo.setCharacterSize(52);
    text_enterNewInfo.setFillColor(sf::Color::White);
    text_enterNewInfo.setPosition(560.f, 50.f);

    sf::Text text_edit(L"Изменить", font2);
    text_edit.setCharacterSize(50);
    text_edit.setFillColor(sf::Color::White);
    text_edit.setPosition(1620.f, 970.f);


    sf::Texture rectangle;
    if (!rectangle.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_rectangle(rectangle);
    sprite_rectangle.setScale(0.6, 0.6);
    sprite_rectangle.setPosition(570, 400);

    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    bool isMouseOnArrow = false;
    bool isRectangleClicked = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }

            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;
            if (text_edit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_edit.setFillColor(sf::Color(255, 51, 6));
            else
                text_edit.setFillColor(sf::Color::White);

            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isRectangleClicked = true;
                }
            }

            // проверка на поле ИЗМЕНИТЬ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_edit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        editEmployee(employee, str_newInfo, str_number, kindOfField); // получает новую инфо,номер сотдурника и номер поля для изменения
                        return;
                    }
                        
                }
            }

            // ввод текста в поле НОВАЯ ИНФА
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 and isRectangleClicked)
                    { // Backspace
                        if (!str_newInfo.empty())
                            str_newInfo.pop_back();
                    }
                    else if (text_newInfo.getString().getSize() < 15 and isRectangleClicked)
                        str_newInfo += static_cast<char>(event.text.unicode);
                }
                text_newInfo.setString(str_newInfo);
            }

        }

        window.clear(sf::Color::Black);

        window.draw(sprite_rectangle);
        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);
        window.draw(text_enterNewInfo);
        window.draw(text_edit);
        window.draw(text_newInfo);

        window.display();
    }
}

float printAllEmployeesForEditingAndDeleting(std::vector<Employee>& employee, float scrollPosition)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return 0.0;


    sf::Text employee1(L"", font2);
    employee1.setCharacterSize(32);
    employee1.setFillColor(sf::Color::White);
    employee1.setPosition(30.f, 30.f);


    float x = 120.0;
    float y = 310.0f;
    std::string currentEmployee;

    for (int i = 0; i < employee.size(); i++)
    {
        employee1.setPosition(x, y);
        currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(i).surName + " " + employee.at(i).name + " " + employee.at(i).patronymic + " " + employee.at(i).gender + " " + employee.at(i).dateOfBirthday
            + " " + employee.at(i).departmentName + " " + employee.at(i).startDate;
        employee1.setString(currentEmployee);

        // Проверяем, виден ли текст на экране
        if (y + scrollPosition >= 0 && y + scrollPosition < window.getSize().y)
        {
            // Устанавливаем позицию текста только если он виден
            employee1.setPosition(x, y + scrollPosition);
            window.draw(employee1);
        }

        // Обновляем позицию для следующего текста
        y += 50;

        // Если достигнут нижний предел прокрутки, прерываем цикл
        if (y + scrollPosition >= window.getSize().y)
            break;
    }

    return y;   // Возвращаем текущую позицию, которая будет использоваться в следующем вызове
}

void deleteEmployee_menu(std::vector<Employee>& employee)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;

    float scrollPosition = 0.0f;
    float y = 0.0f;


    sf::RectangleShape line(Vector2f(140.f, 2.f));
    sf::RectangleShape rectangle(Vector2f(160.f, 46.f));
    line.setFillColor(sf::Color::White);
    rectangle.setFillColor(sf::Color(0, 0, 0, 255));


    sf::Text text_choose_number(L"Выберите номер сотрудника из списка, чьи данные вы хотите удалить: ", font2);
    text_choose_number.setCharacterSize(32);
    text_choose_number.setFillColor(sf::Color::White);


    sf::Text text_delete_info(L"Удаление", font2);
    text_delete_info.setCharacterSize(64);
    text_delete_info.setFillColor(sf::Color::White);

    sf::Text text_accept(L"Принять", font2);
    text_accept.setCharacterSize(48);
    text_accept.setFillColor(sf::Color::White);


    sf::Text text_number(L"", font2);
    text_number.setCharacterSize(45);
    text_number.setFillColor(sf::Color::White);


    std::string str_number;
    bool isRectangleClicked = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;


            if (event.type == sf::Event::MouseWheelScrolled)
            {
                // Обработка прокрутки колесика мыши
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    // Проверяем, выходит ли текст за границы окна
                    float lastTextBottom = y + 32;
                    float windowHeight = window.getSize().y;
                    if (lastTextBottom > windowHeight || lastTextBottom < windowHeight) // Добавлена проверка на случай, если текст не заполняет окно полностью
                    {
                        // Прокрутка вниз
                        if (event.mouseWheelScroll.delta > 0)
                        {
                            scrollPosition += event.mouseWheelScroll.delta * 25.0f;
                            // Проверяем, чтобы scrollPosition не выходил за границы
                            if (scrollPosition >= 0)
                                scrollPosition = 0;
                            if (scrollPosition > 0) // Прокрутка вниз недоступна, если текст уже полностью виден
                                scrollPosition = 0;
                        }
                        // Прокрутка вверх
                        else if (event.mouseWheelScroll.delta < 0 or lastTextBottom < windowHeight) // Добавлена проверка, чтобы позволить прокрутку вверх, если текст не заполняет окно полностью
                        {
                            scrollPosition += event.mouseWheelScroll.delta * 25.0f;
                            // Проверяем, чтобы scrollPosition не выходил за границы
                            float minScrollPosition = windowHeight - lastTextBottom;
                            if (scrollPosition > 0)
                                scrollPosition = 0;
                            if (scrollPosition < minScrollPosition) // Прокрутка вверх недоступна, если достигнут конец текста
                                scrollPosition = minScrollPosition;
                        }
                    }
                }
            }

            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isRectangleClicked = true;
                }
            }

            // проверка на поле для ПРИНЯТЬ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_accept.getGlobalBounds().contains(mousePos.x, mousePos.y) and !str_number.empty())
                        if (areYouSure())
                            deleteEmployee(employee, str_number);


                }
            }

            // ввод текста в поле цифры
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 and isRectangleClicked)
                    { // Backspace
                        if (!str_number.empty())
                            str_number.pop_back();
                    }
                    else if (isRectangleClicked and text_number.getString().getSize() < 4)
                        str_number += static_cast<char>(event.text.unicode);
                }
                text_number.setString(str_number);

            }

            // ПОДСВЕЧИВАНИЕ КНОПКИ ПРИНЯТЬ
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (text_accept.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_accept.setFillColor(Color(255, 51, 6));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_accept.setFillColor(sf::Color::White);



        }
        text_choose_number.setPosition(20.f, 180.f + scrollPosition);
        text_delete_info.setPosition(780.f, 30.f + scrollPosition);
        text_number.setPosition(1334.f, 170.f + scrollPosition);
        line.setPosition(1330.f, 226.f + scrollPosition);
        rectangle.setPosition(1324, 180 + scrollPosition);
        text_accept.setPosition(1500, 170 + scrollPosition);


        window.clear(sf::Color::Black);
        y = printAllEmployeesForEditingAndDeleting(employee, scrollPosition);

        window.draw(text_delete_info);
        window.draw(text_accept);
        window.draw(text_choose_number);
        window.draw(rectangle);
        window.draw(line);
        window.draw(text_number);

        window.display();
    }
}

int areYouSure()
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return -1;


    sf::RectangleShape rectangle(Vector2f(400.f, 200.f));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(760, 400);

    sf::Text text_yes(L"Да", font2);
    text_yes.setCharacterSize(36);
    text_yes.setFillColor(sf::Color::White);
    text_yes.setPosition(790, 560);

    sf::Text text_no(L"Отмена", font2);
    text_no.setCharacterSize(36);
    text_no.setFillColor(sf::Color::White);
    text_no.setPosition(1000, 560);

    sf::Text text_areYouSure(L"Вы уверены?", font2);
    text_areYouSure.setCharacterSize(44);
    text_areYouSure.setFillColor(sf::Color::White);
    text_areYouSure.setPosition(804, 420);

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return -1;
            
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (text_yes.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_yes.setFillColor(Color(255, 51, 6));
            else
                text_yes.setFillColor(sf::Color::White);
            if (text_no.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_no.setFillColor(Color(255, 51, 6));
            else
                text_no.setFillColor(sf::Color::White);


            // проверка на поле для ДА
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_yes.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return 1;
                }
            }

            // проверка на поле для НЕТ
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_no.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return 0;
                }
            }

        }

        window.draw(rectangle);
        window.draw(text_yes);
        window.draw(text_no);
        window.draw(text_areYouSure);
        window.display();
    }
}


// ПОИСК

// ПО ФАМИЛИИ
void searchEmployeeWithSurname_menu(std::vector<Employee>& employee)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_enterSurname(L"Введите фамилию сотрудника", font2);
    text_enterSurname.setCharacterSize(48);
    text_enterSurname.setFillColor(sf::Color::White);
    text_enterSurname.setPosition(560.f, 50.f);

    sf::Text text_search(L"Поиск", font2);
    text_search.setCharacterSize(48);
    text_search.setFillColor(sf::Color::White);
    text_search.setPosition(1700.f, 970.f);

    sf::Text text_empty(L"Введите хотя бы один символ", font2);
    text_empty.setCharacterSize(30);
    text_empty.setFillColor(sf::Color::Red);
    text_empty.setPosition(692.f, 574.f);

    sf::Text text_newInfo("", font2);
    text_newInfo.setCharacterSize(48);
    text_newInfo.setFillColor(sf::Color::Black);
    text_newInfo.setPosition(638.f, 450.f);

    std::string str_surName;

    sf::Texture rectangle;
    if (!rectangle.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_rectangle(rectangle);
    sprite_rectangle.setScale(0.6, 0.6);
    sprite_rectangle.setPosition(570, 400);


    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    bool isMouseOnArrow = false;
    bool isRectangleClicked = false;
    bool isSurnameChanging = false;
    bool isTextEmpty = true;
    bool isButtonClicked = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }

            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_search.setFillColor(sf::Color(255, 51, 6));
            else
                text_search.setFillColor(sf::Color::White);


            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isButtonClicked = true;
                    if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isTextEmpty)
                        printSearchingEmployeesWithSurname(employee, str_surName, isSurnameChanging);
                }
            }

            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isRectangleClicked = true;
                }
            }


            // ввод текста в поле НОВАЯ ИНФА
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 and isRectangleClicked)
                    { // Backspace
                        if (!str_surName.empty())
                            str_surName.pop_back();
                    }
                    else if (text_newInfo.getString().getSize() < 15 and isRectangleClicked)
                        str_surName += static_cast<char>(event.text.unicode);
                }
                text_newInfo.setString(str_surName);

                if (str_surName.empty())
                    isTextEmpty = true;
                else
                    isTextEmpty = false;

                isSurnameChanging = false;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(sprite_rectangle);
        window.draw(text_enterSurname);
        window.draw(text_search);
        window.draw(text_newInfo);

        if (isTextEmpty and isButtonClicked)
            window.draw(text_empty);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);

        window.display();
    }
}
void printSearchingEmployeesWithSurname(std::vector<Employee>& employee, std::string str_surName, bool isSurnameChanging)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_searchEmployees(L"Найденные сотрудники", font2);
    text_searchEmployees.setCharacterSize(46);
    text_searchEmployees.setFillColor(sf::Color::White);
    text_searchEmployees.setPosition(670.f, 30.f);

    sf::Text text_currentEmployeeNo(L"Сотрудников с такой фамилией не найдено!", font2);
    text_currentEmployeeNo.setCharacterSize(46);
    text_currentEmployeeNo.setFillColor(sf::Color::White);
    text_currentEmployeeNo.setPosition(420.f, 500.f);


    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    std::vector<int> indexes;
    indexes.reserve(10);

    bool isMouseOnArrow = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }


            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

        }

        window.clear(sf::Color::Black);



        if (!isSurnameChanging)
        {
            searchWithSurname(employee, str_surName, indexes);
            isSurnameChanging = true;
        }
        printEmployeesLoop(indexes, employee);
        window.draw(text_searchEmployees);

        if (indexes.empty())
            window.draw(text_currentEmployeeNo);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);


        window.display();
    }
}
void printEmployeesLoop(std::vector<int>& indexes, std::vector<Employee>& employee)
{

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_currentEmployee("", font2);
    text_currentEmployee.setCharacterSize(32);
    text_currentEmployee.setFillColor(sf::Color::White);

    std::string str_currentEmployee;

    float x = 120.0;
    float y = 120.0f;
    int count = 0;
    for (int i = 0; i < indexes.size(); i++)
    {
        text_currentEmployee.setPosition(x, y);
        str_currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(indexes.at(count)).surName + " " +
            employee.at(indexes.at(count)).name + " " + employee.at(indexes.at(count)).patronymic + " " + employee.at(indexes.at(count)).gender +
            " " + employee.at(indexes.at(count)).dateOfBirthday + " " + employee.at(indexes.at(count)).departmentName + " " + employee.at(indexes.at(count)).startDate;
        text_currentEmployee.setString(str_currentEmployee);

        y += 50;
        count++;
        window.draw(text_currentEmployee);
    }
}

// ПО ДОЛЖНОСТИ
void searchEmployeeWithPost_menu(std::vector<Employee>& employee)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_enterPost(L"Введите должность сотрудника", font2);
    text_enterPost.setCharacterSize(48);
    text_enterPost.setFillColor(sf::Color::White);
    text_enterPost.setPosition(560.f, 50.f);

    sf::Text text_search(L"Поиск", font2);
    text_search.setCharacterSize(48);
    text_search.setFillColor(sf::Color::White);
    text_search.setPosition(1700.f, 970.f);

    sf::Text text_empty(L"Введите хотя бы один символ", font2);
    text_empty.setCharacterSize(30);
    text_empty.setFillColor(sf::Color::Red);
    text_empty.setPosition(692.f, 574.f);

    sf::Text text_newInfo("", font2);
    text_newInfo.setCharacterSize(48);
    text_newInfo.setFillColor(sf::Color::Black);
    text_newInfo.setPosition(638.f, 450.f);

    std::string str_post;

    sf::Texture rectangle;
    if (!rectangle.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_rectangle(rectangle);
    sprite_rectangle.setScale(0.6, 0.6);
    sprite_rectangle.setPosition(570, 400);


    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    bool isMouseOnArrow = false;
    bool isRectangleClicked = false;
    bool isPostChanging = false;
    bool isTextEmpty = true;
    bool isButtonClicked = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }

            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_search.setFillColor(sf::Color(255, 51, 6));
            else
                text_search.setFillColor(sf::Color::White);


            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isButtonClicked = true;
                    if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isTextEmpty)
                        printSearchingEmployeesWithPost(employee, str_post, isPostChanging);
                }
            }

            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isRectangleClicked = true;
                }
            }


            // ввод текста в поле НОВАЯ ИНФА
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 and isRectangleClicked)
                    { // Backspace
                        if (!str_post.empty())
                            str_post.pop_back();
                    }
                    else if (text_newInfo.getString().getSize() < 15 and isRectangleClicked)
                        str_post += static_cast<char>(event.text.unicode);
                }
                text_newInfo.setString(str_post);

                if (str_post.empty())
                    isTextEmpty = true;
                else
                    isTextEmpty = false;

                isPostChanging = false;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(sprite_rectangle);
        window.draw(text_enterPost);
        window.draw(text_search);
        window.draw(text_newInfo);

        if (isTextEmpty and isButtonClicked)
            window.draw(text_empty);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);

        window.display();
    }
}
void printSearchingEmployeesWithPost(std::vector<Employee>& employee, std::string str_post, bool isPostChanging)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_searchEmployees(L"Найденные сотрудники", font2);
    text_searchEmployees.setCharacterSize(46);
    text_searchEmployees.setFillColor(sf::Color::White);
    text_searchEmployees.setPosition(670.f, 30.f);

    sf::Text text_currentEmployeeNo(L"Сотрудников с такой должностью не найдено!", font2);
    text_currentEmployeeNo.setCharacterSize(46);
    text_currentEmployeeNo.setFillColor(sf::Color::White);
    text_currentEmployeeNo.setPosition(420.f, 500.f);


    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    std::vector<int> indexes;
    indexes.reserve(10);

    bool isMouseOnArrow = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }


            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

        }

        window.clear(sf::Color::Black);



        if (!isPostChanging)
        {
            searchWithPost(employee, str_post, indexes);
            isPostChanging = true;
        }
        printEmployeesLoopPost(indexes, employee);
        window.draw(text_searchEmployees);

        if (indexes.empty())
            window.draw(text_currentEmployeeNo);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);


        window.display();
    }
}
void printEmployeesLoopPost(std::vector<int>& indexes, std::vector<Employee>& employee)
{

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_currentEmployee("", font2);
    text_currentEmployee.setCharacterSize(32);
    text_currentEmployee.setFillColor(sf::Color::White);

    std::string str_currentEmployee;

    float x = 120.0;
    float y = 120.0f;
    int count = 0;
    for (int i = 0; i < indexes.size(); i++)
    {
        text_currentEmployee.setPosition(x, y);
        str_currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(indexes.at(count)).surName + " " +
            employee.at(indexes.at(count)).name + " " + employee.at(indexes.at(count)).patronymic + " " + employee.at(indexes.at(count)).gender +
            " " + employee.at(indexes.at(count)).dateOfBirthday + " " + employee.at(indexes.at(count)).departmentName + " " + employee.at(indexes.at(count)).startDate;
        text_currentEmployee.setString(str_currentEmployee);

        y += 50;
        count++;
        window.draw(text_currentEmployee);
    }
}


void searchEmployeeWithStartYear_menu(std::vector<Employee> &employee)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_enterYear(L"Введите год начала работы сотрудника", font2);
    text_enterYear.setCharacterSize(48);
    text_enterYear.setFillColor(sf::Color::White);
    text_enterYear.setPosition(560.f, 50.f);

    sf::Text text_search(L"Поиск", font2);
    text_search.setCharacterSize(48);
    text_search.setFillColor(sf::Color::White);
    text_search.setPosition(1700.f, 970.f);

    sf::Text text_empty(L"Введите хотя бы один символ", font2);
    text_empty.setCharacterSize(30);
    text_empty.setFillColor(sf::Color::Red);
    text_empty.setPosition(692.f, 574.f);

    sf::Text text_newInfo("", font2);
    text_newInfo.setCharacterSize(48);
    text_newInfo.setFillColor(sf::Color::Black);
    text_newInfo.setPosition(638.f, 450.f);

    std::string str_year;

    sf::Texture rectangle;
    if (!rectangle.loadFromFile("rectangle.png"))
        return;
    sf::Sprite sprite_rectangle(rectangle);
    sprite_rectangle.setScale(0.6, 0.6);
    sprite_rectangle.setPosition(570, 400);


    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    bool isMouseOnArrow = false;
    bool isRectangleClicked = false;
    bool isYearChanging = false;
    bool isTextEmpty = true;
    bool isButtonClicked = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }

            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_search.setFillColor(sf::Color(255, 51, 6));
            else
                text_search.setFillColor(sf::Color::White);


            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isButtonClicked = true;
                    if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isTextEmpty)
                        printSearchingEmployeesWithYear(employee, str_year, isYearChanging);
                }
            }

            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        isRectangleClicked = true;
                }
            }


            // ввод текста в поле НОВАЯ ИНФА
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 and isRectangleClicked)
                    { // Backspace
                        if (!str_year.empty())
                            str_year.pop_back();
                    }
                    else if (text_newInfo.getString().getSize() < 15 and isRectangleClicked)
                        str_year += static_cast<char>(event.text.unicode);
                }
                text_newInfo.setString(str_year);

                if (str_year.empty())
                    isTextEmpty = true;
                else
                    isTextEmpty = false;

                isYearChanging = false;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(sprite_rectangle);
        window.draw(text_enterYear);
        window.draw(text_search);
        window.draw(text_newInfo);

        if (isTextEmpty and isButtonClicked)
            window.draw(text_empty);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);

        window.display();
    }
}
void printSearchingEmployeesWithYear(std::vector<Employee>& employee, std::string str_year, bool isYearChanging)
{
    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_searchEmployees(L"Найденные сотрудники", font2);
    text_searchEmployees.setCharacterSize(46);
    text_searchEmployees.setFillColor(sf::Color::White);
    text_searchEmployees.setPosition(670.f, 30.f);

    sf::Text text_currentEmployeeNo(L"Сотрудников с такой датой не найдено!", font2);
    text_currentEmployeeNo.setCharacterSize(46);
    text_currentEmployeeNo.setFillColor(sf::Color::White);
    text_currentEmployeeNo.setPosition(420.f, 500.f);


    sf::Texture arrow_back_white;
    if (!arrow_back_white.loadFromFile("arrow_back_white.png"))
        return;
    sf::Sprite sprite_arrow_back_white(arrow_back_white);
    sprite_arrow_back_white.setScale(0.2, 0.2);
    sprite_arrow_back_white.setPosition(50, 950);

    sf::Texture arrow_back_orange;
    if (!arrow_back_orange.loadFromFile("arrow_back.png"))
        return;
    sf::Sprite sprite_arrow_back_orange(arrow_back_orange);
    sprite_arrow_back_orange.setScale(0.2, 0.2);
    sprite_arrow_back_orange.setPosition(50, 950);


    std::vector<int> indexes;
    indexes.reserve(10);

    bool isMouseOnArrow = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;
                }
            }


            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

        }

        window.clear(sf::Color::Black);



        if (!isYearChanging)
        {
            searchWithYear(employee, str_year, indexes);
            isYearChanging = true;
        }
        printEmployeesLoopYear(indexes, employee);
        window.draw(text_searchEmployees);

        if (indexes.empty())
            window.draw(text_currentEmployeeNo);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);


        window.display();
    }
}
void printEmployeesLoopYear(std::vector<int>& indexes, std::vector<Employee>& employee)
{

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf"))
        return;


    sf::Text text_currentEmployee("", font2);
    text_currentEmployee.setCharacterSize(32);
    text_currentEmployee.setFillColor(sf::Color::White);

    std::string str_currentEmployee;

    float x = 120.0;
    float y = 120.0f;
    int count = 0;
    for (int i = 0; i < indexes.size(); i++)
    {
        text_currentEmployee.setPosition(x, y);
        str_currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(indexes.at(count)).surName + " " +
            employee.at(indexes.at(count)).name + " " + employee.at(indexes.at(count)).patronymic + " " + employee.at(indexes.at(count)).gender +
            " " + employee.at(indexes.at(count)).dateOfBirthday + " " + employee.at(indexes.at(count)).departmentName + " " + employee.at(indexes.at(count)).startDate;
        text_currentEmployee.setString(str_currentEmployee);

        y += 50;
        count++;
        window.draw(text_currentEmployee);
    }
}


// СООРТИРОВКА
