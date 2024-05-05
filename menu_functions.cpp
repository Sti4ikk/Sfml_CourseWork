#include "structs.h"
#include "enums.h"
#include "prototypes.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include <array>


bool loadFont(sf::Font& font, const std::string& filePath);
bool loadTexture(const std::string& filePath, sf::Texture& texture);
void createSprite(sf::Sprite& sprite, const sf::Texture& texture, const float x, const float y, const sf::Vector2f& position);
void createText(sf::Text& text, unsigned int characterSize, const sf::Color& color, const sf::Vector2f& position);
void createRectangle(sf::RectangleShape& rectangle, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const float outlineThickness = 0, const sf::Color outlineColor = sf::Color(0, 0, 0, 255));


extern sf::RenderWindow window;
using namespace sf;


void auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool &isRememberMePressed)
{
    // Создание окна
    window.create(sf::VideoMode(500, 412), "", sf::Style::None);


    // Загрузка шрифта
    sf::Font font;
    loadFont(font, "shrift.ttf");


    // Создание прямоугольников
    sf::RectangleShape rectangle1;
    createRectangle(rectangle1, Vector2f(430.f, 70.f), Vector2f(35.f, 80.f), sf::Color::Black, 1.f, sf::Color(59, 60, 54));

    sf::RectangleShape rectangle2;
    createRectangle(rectangle2, Vector2f(430.f, 70.f), Vector2f(35.f, 160.f), sf::Color::Black, 1.f, sf::Color(59, 60, 54));

    sf::RectangleShape rectangle3;
    createRectangle(rectangle3, Vector2f(430.f, 70.f), Vector2f(35.f, 255.f), sf::Color(255, 193, 7));

    sf::RectangleShape square;
    createRectangle(square, Vector2f(25.f, 25.f), Vector2f(45.f, 340.f), Color(59, 60, 54));

    sf::RectangleShape line1;
    createRectangle(line1, Vector2f(1.f, 70.f), Vector2f(99.f, 80.f), Color(59, 60, 54));

    sf::RectangleShape line2;
    createRectangle(line2, Vector2f(1.f, 70.f), Vector2f(99.f, 160.f), Color(59, 60, 54));


    // Создание текста
    sf::Text text(L"Авторизация", font);
    createText(text, 46, sf::Color::White, sf::Vector2f(88.f, 8.f));

    sf::Text entrance(L"Войти", font);
    createText(entrance, 30, sf::Color::White, sf::Vector2f(188.f, 272.f));

    sf::Text rememberMe(L"Запомнить меня", font);
    createText(rememberMe, 14, sf::Color(59, 60, 54), sf::Vector2f(81.f, 344.f));

    sf::Text login("", font);
    createText(login, 28, sf::Color::White, sf::Vector2f(110.f, 98.f));

    sf::Text password1("", font);
    createText(password1, 28, sf::Color::White, sf::Vector2f(110.f, 178.f));

    sf::Text password2("", font);
    createText(password2, 44, sf::Color::White, sf::Vector2f(110.f, 178.f));

    sf::Text error(L"Неверный логин или пароль!", font);
    createText(error, 16, sf::Color::Red, sf::Vector2f(126.f, 380.f));


    // Загрузка текстур
    sf::Texture texture1;
    loadTexture("user.png", texture1);
    sf::Texture texture2;
    loadTexture("password1.png", texture2);
    sf::Texture texture3;
    loadTexture("hide_eye.png", texture3);
    sf::Texture texture4;
    loadTexture("open_eye.png", texture4);
    sf::Texture galka;
    loadTexture("galka.png", galka);
    sf::Texture krest;
    loadTexture("krest.png", krest);


    // Создание спрайта и установка текстуры
    sf::Sprite sprite1;
    createSprite(sprite1, texture1, 1.f / 10.f, 1.f / 10.f, sf::Vector2f(42.f, 92.f));
    sf::Sprite sprite2;
    createSprite(sprite2, texture2, 1.f / 10.f, 1.f / 10.f, sf::Vector2f(43.f, 172.f));
    sf::Sprite sprite3;
    createSprite(sprite3, texture3, 1.f / 12.f, 1.f / 12.f, sf::Vector2f(416.f, 175.f));
    sf::Sprite sprite4;
    createSprite(sprite4, texture4, 1.f / 12.f, 1.f / 12.f, sf::Vector2f(416.f, 175.f));
    sf::Sprite sprite_galka;
    createSprite(sprite_galka, galka, 1.f / 19.f, 1.f / 19.f, sf::Vector2f(44.f, 339.f));
    sf::Sprite sprite_krest;
    createSprite(sprite_krest, krest, 1.f / 30.f, 1.f / 30.f, sf::Vector2f(478.f, 6.f));


    // Проверка, какое поле выбрали для ввода
    bool isRectangle1Clicked = false;
    bool isRectangle2Clicked = false;
    bool isPasswordOpen = false;
    bool isTextPasswordOpen = false;
    bool isRememberMeOn = false;
    bool isIncorrectData = false;
    bool isDragging = false;


    // Координаты текущего клика
    sf::Vector2i clickPosition;

    // String-переменные для ввода логина и пароля
    std::string str_login;
    std::string str_password;
    std::string str_password_close;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_krest.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    window.close();
            }
            // для закрытия из панели задач и по клавише ESCAPE
            if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape))
                window.close();


            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                // Запоминаем позицию, в которой была нажата кнопка мыши
                isDragging = true;
                clickPosition = sf::Mouse::getPosition(window);
            }
            else if (event.type == sf::Event::MouseButtonReleased and event.mouseButton.button == sf::Mouse::Left)
                // Когда кнопка мыши отпущена, заканчиваем перетаскивание
                isDragging = false;


            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
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


            // Изменение цвета прямоугольника, если курсор находится над ним
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (rectangle3.getGlobalBounds().contains(mousePos.x, mousePos.y))
                rectangle3.setFillColor(Color(255, 245, 7));
            else
                rectangle3.setFillColor(Color(255, 193, 7));


            // проверка на галочку
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
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


            // ввод текста в поле логин и пароль
            if (event.type == sf::Event::TextEntered and event.text.unicode < 128)
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
                login.setString(str_login);
                password1.setString(str_password);
                password2.setString(str_password_close);
            }
            

            // проверка на нажатие кнопки видимости пароля
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
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


            // проверка на правильность введенных данных
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
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


        // ПЕРЕМЕЩЕНИЕ ОКНА АВТОРИЗАЦИИ 
        if (isDragging)
        {
            // Вычисляем разницу между текущей позицией мыши и позицией, где была нажата кнопка мыши
            sf::Vector2i delta = sf::Mouse::getPosition(window) - clickPosition;
            // Получаем текущее положение окна и сдвигаем его на delta
            window.setPosition(sf::Vector2i(window.getPosition()) + delta);
            // Обновляем позицию clickPosition
            clickPosition = sf::Mouse::getPosition(window);
        }


        // Отрисовка всех элементов
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


// ОСНОВНЫЕ ФУНКЦИИ МЕНЮ
void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed)
{
    window.create(sf::VideoMode(1920, 1080), "", sf::Style::None);

    // массив случайных чисел для отображения случайных новостей
    std::vector<int>numbers;
    initArrOfRandomNumbers(numbers);


    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");

    sf::Font font;
    loadFont(font, "shrift2.ttf");

    
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


    // Создание прямоугольников
    sf::RectangleShape account(Vector2f(240.f, 90.f));
    createRectangle(account, Vector2f(240.f, 90.f), Vector2f(1660.f, 94.f), sf::Color(59, 60, 54, 190));

    sf::RectangleShape polosa(Vector2f(1000.f, 1080.f));
    createRectangle(polosa, Vector2f(1000.f, 1080.f), Vector2f(530.f, 0.f), sf::Color::White);

    sf::RectangleShape line1(Vector2f(1.f, 1080.f));
    createRectangle(line1, Vector2f(1.f, 1080.f), Vector2f(0.f, 0.f), sf::Color(59, 60, 54));


    // Создание текста ГЛАВНОГО МЕНЮ
    sf::Text name("Pixel World", font);
    createText(name, 24, sf::Color::White, sf::Vector2f(30.f, 16.f));

    sf::Text text_editing(L"Редактирование", font2);
    createText(text_editing, 45, sf::Color::White, sf::Vector2f(45.f, 385.f));

    sf::Text text_proccesing(L"Обработка", font2);
    createText(text_proccesing, 45, sf::Color::White, sf::Vector2f(45.f, 455.f));

    sf::Text text_settings(L"Настройки", font2);
    createText(text_settings, 45, sf::Color::White, sf::Vector2f(45.f, 525.f));
    
    sf::Text text_exit(L"Выход", font2);
    createText(text_exit, 45, sf::Color::White, sf::Vector2f(45.f, 595.f));

    sf::Text text_account(L"Учётная запись", font2);
    createText(text_account, 22, sf::Color::White, sf::Vector2f(1685.f, 106.f));

    sf::Text text_leave_from_acc(L"Выход из аккаунта", font2);
    createText(text_leave_from_acc, 22, sf::Color::White, sf::Vector2f(1662.f, 140.f));

    // Создание текста МЕНЮ РЕДАКТИРОВАНИЕ
    sf::Text text_print_all(L"Список сотрудников", font2);
    createText(text_print_all, 40, sf::Color::White, sf::Vector2f(25.f, 385.f));

    sf::Text text_add_employee(L"Добавить сотрудника", font2);
    createText(text_add_employee, 40, sf::Color::White, sf::Vector2f(25.f, 455.f));

    sf::Text text_edit_info(L"Редактировать данные", font2);
    createText(text_edit_info, 40, sf::Color::White, sf::Vector2f(25.f, 525.f));

    sf::Text text_delete_employee(L"Удалить сотрудника", font2);
    createText(text_delete_employee, 40, sf::Color::White, sf::Vector2f(25.f, 595.f));

    sf::Text text_get_back(L"Назад", font2);
    createText(text_get_back, 40, sf::Color::White, sf::Vector2f(25.f, 665.f));

    // Создание текста МЕНЮ ОБРАБОТКА
    sf::Text text_search(L"Поиск", font2);
    createText(text_search, 40, sf::Color::White, sf::Vector2f(25.f, 385.f));

    sf::Text text_sorting(L"Сортировка", font2);
    createText(text_sorting, 40, sf::Color::White, sf::Vector2f(25.f, 455.f));

    sf::Text text_search1(L"Поиск сотрудников", font2);
    createText(text_search1, 40, sf::Color::White, sf::Vector2f(25.f, 525.f));

    sf::Text text_search2(L"пенсионного возраста", font2);
    createText(text_search2, 40, sf::Color::White, sf::Vector2f(25.f, 570.f));

    sf::Text text_get_back1(L"Назад", font2);
    createText(text_get_back1, 40, sf::Color::White, sf::Vector2f(25.f, 640.f));

    // Создание текста МЕНЮ ПОИСК
    sf::Text text_search_with_post(L"Поиск по должности", font2);
    createText(text_search_with_post, 40, sf::Color::White, sf::Vector2f(25.f, 455.f));

    sf::Text text_search_with_surname(L"Поиск по фамилии", font2);
    createText(text_search_with_surname, 40, sf::Color::White, sf::Vector2f(25.f, 385.f));

    sf::Text text_search_with_year(L"Поиск по году\nначала работы", font2);
    createText(text_search_with_year, 40, sf::Color::White, sf::Vector2f(25.f, 525.f));

    sf::Text text_get_back2(L"Назад", font2);
    createText(text_get_back2, 40, sf::Color::White, sf::Vector2f(25.f, 640.f));

    // Создание текста МЕНЮ СОРТИРОВКА
    sf::Text text_sorting_with_post(L"По должности", font2);
    createText(text_sorting_with_post, 40, sf::Color::White, sf::Vector2f(25.f, 455.f));

    sf::Text text_sorting_with_surname(L"По фамилии", font2);
    createText(text_sorting_with_surname, 40, sf::Color::White, sf::Vector2f(25.f, 385.f));

    sf::Text text_sorting_with_experience(L"По стажу", font2);
    createText(text_sorting_with_experience, 40, sf::Color::White, sf::Vector2f(25.f, 525.f));

    sf::Text text_get_back3(L"Назад", font2);
    createText(text_get_back3, 40, sf::Color::White, sf::Vector2f(25.f, 595.f));

    sf::Text text_sort_up(L"По возрастанию", font2);
    createText(text_sort_up, 40, sf::Color::White, sf::Vector2f(25.f, 455.f));

    sf::Text text_sort_down(L"По убыванию", font2);
    createText(text_sort_down, 40, sf::Color::White, sf::Vector2f(25.f, 525.f));

    sf::Text text_get_back4(L"Назад", font2);
    createText(text_get_back4, 40, sf::Color::White, sf::Vector2f(25.f, 595.f));


    // Создание текстур
    sf::Texture acc;
    loadTexture("acc.png", acc);
    
    sf::Texture shtorka;
    loadTexture("shtorka.png", shtorka);

    sf::Texture shtorka1;
    loadTexture("shtorka1.png", shtorka1);

    sf::Texture shtorka_orange1;
    loadTexture("shtorka_orange.png", shtorka_orange1);

    sf::Texture shtorka_orange;
    loadTexture("shtorka_orange.png", shtorka_orange);

    sf::Texture bg_news;
    loadTexture("bg_news4.png", bg_news);

    sf::Texture logo;
    loadTexture("logo10_4.png", logo);

    sf::Texture news1;
    loadTexture("news\\news" + std::to_string(numbers.at(0)) + ".png", news1);

    sf::Texture news2;
    loadTexture("news\\news" + std::to_string(numbers.at(1)) + ".png", news2);

    sf::Texture news3;
    loadTexture("news\\news" + std::to_string(numbers.at(2)) + ".png", news3);

    sf::Texture news4;
    loadTexture("news\\news" + std::to_string(numbers.at(3)) + ".png", news4);

    sf::Texture news5;
    loadTexture("news\\news" + std::to_string(numbers.at(4)) + ".png", news5);

    
    // Создание спрайтов
    sf::Sprite sprite_acc;
    createSprite(sprite_acc, acc, 1.f / 7.f, 1.f / 7.f, sf::Vector2f(1810.f, 15.f));

    sf::Sprite sprite_shtorka;
    createSprite(sprite_shtorka, shtorka1, 0.6, 0.6, sf::Vector2f(1888, 386));

    sf::Sprite sprite_shtorka1;
    createSprite(sprite_shtorka1, shtorka1, 0.6, 0.6, sf::Vector2f(1426, 386));

    sf::Sprite sprite_shtorka_orange1;
    createSprite(sprite_shtorka_orange1, shtorka_orange1, 0.6, 0.6, sf::Vector2f(1426, 386));

    sf::Sprite sprite_shtorka_orange;
    createSprite(sprite_shtorka_orange, shtorka_orange, 0.6, 0.6, sf::Vector2f(1888, 386));

    sf::Sprite sprite_bg_news;
    createSprite(sprite_bg_news, bg_news, 0.5, 0.5, sf::Vector2f(1330, 192));

    sf::Sprite sprite_logo;
    createSprite(sprite_logo, logo, 0.8, 0.8, sf::Vector2f(570, 130));

    sf::Sprite sprite_news1;
    createSprite(sprite_news1, news1, 0.26, 0.26, sf::Vector2f(1485, 150));

    sf::Sprite sprite_news2;
    createSprite(sprite_news2, news2, 0.26, 0.26, sf::Vector2f(1485, 280));

    sf::Sprite sprite_news3;
    createSprite(sprite_news3, news3, 0.26, 0.26, sf::Vector2f(1485, 410));

    sf::Sprite sprite_news4;
    createSprite(sprite_news4, news4, 0.26, 0.26, sf::Vector2f(1485, 540));

    sf::Sprite sprite_news5;
    createSprite(sprite_news5, news5, 0.26, 0.26, sf::Vector2f(1485, 670));
           

    // Переменные состояния
    bool isAccPressed = false;                // Нажали ли на спрайт acc
    bool isMouseOnShtorka = false;            // Нажали ли на шторку1 (до открытия новостей)
    bool isMouseOnShtorka1 = false;           // Нажали ли на шторку2 (после открытия новостей)
    bool triangleIsMouseOnShtorka1 = false;   // Нахоится ли курсор на шторке1
    bool triangleIsMouseOnShtorka = false;    // Нахоится ли курсор на шторке2
    bool isNewsOpen = false;                  // Открыта ли вкладка новостей
    bool editingMode = false;                 // Нажали ли на кнопку РЕДАКТИРОВАНИЕ
    bool proccesingMode = false;              // Нажали ли на кнопку ОБРАБОТКА
    bool isSearchPressed = false;             // Нажали ли на кнопку ПОИСК 
    bool isSortingPressed = false;            // Нажали ли на кнопку СОРТИРОВКА
    bool isSortingModePressed = false;        // Выбрали ли тип сортировки в меню СОРТИРОВКА


    int kindOfSort = -1;
    int sortUpOrDown = -1;

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
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen and !editingMode and !proccesingMode)
                    window.close();
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
                text_proccesing.setFillColor(Color(255, 51, 6));
            else
                text_proccesing.setFillColor(sf::Color::White);
            if (text_settings.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_settings.setFillColor(Color(255, 51, 6));
            else
                text_settings.setFillColor(sf::Color::White);
            if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_exit.setFillColor(Color(255, 51, 6));
            else
                text_exit.setFillColor(sf::Color::White);
            if (text_account.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_account.setFillColor(Color(255, 51, 6));
            else
                text_account.setFillColor(sf::Color::White);
            if (text_leave_from_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))
                text_leave_from_acc.setFillColor(Color(255, 51, 6));
            else
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

            if (text_get_back4.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSortingPressed)
                text_get_back4.setFillColor(Color(255, 51, 6));
            else
                text_get_back4.setFillColor(sf::Color::White);
            if (text_sort_up.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSortingPressed)
                text_sort_up.setFillColor(Color(255, 51, 6));
            else
                text_sort_up.setFillColor(sf::Color::White);
            if (text_sort_down.getGlobalBounds().contains(mousePos.x, mousePos.y) and isSortingPressed)
                text_sort_down.setFillColor(Color(255, 51, 6));
            else
                text_sort_down.setFillColor(sf::Color::White);

            
            // проверка на кнопку НАЗАД
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_get_back.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !proccesingMode)
                    editingMode = false;
            }


            // проверка на нажатие на ПОИСК ПО ФАМИЛИИ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_search_with_surname.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSearchPressed)
                    searchEmployeeWithSurname_menu(employee);
            }
            // проверка на нажатие на ПОИСК ПО ДОЛЖНОСТИ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_search_with_post.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSearchPressed)
                    searchEmployeeWithPost_menu(employee);
            }
            // проверка на нажатие на ПОИСК ПО ГОДУ НАЧАЛА РАБОТЫ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_search_with_year.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSearchPressed)
                    searchEmployeeWithStartYear_menu(employee);
            }



                                                                            // ПОИСК
                // проверка на кнопку ПОИСК
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSortingPressed and proccesingMode)
                    isSearchPressed = true;
            }
            // проверка на кнопку НАЗАД
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_get_back2.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSortingPressed)
                    isSearchPressed = false;
            } 
                                                                    //СОРТИРОВКА
                                                                    // 
                      // проверка на кнопку SORT UP и SORT DOWN
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_sort_up.getGlobalBounds().contains(mousePos.x, mousePos.y)  and !isAccPressed and !editingMode and isSortingModePressed)
                {
                    sortUpOrDown = 1;
                    successOfSorting_menu(kindOfSort, sortUpOrDown, employee);
                    isSortingModePressed = false;
                }
            }
            // проверка на кнопку SORT DOWN
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_sort_down.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and isSortingModePressed)
                {
                    sortUpOrDown = 2;
                    successOfSorting_menu(kindOfSort, sortUpOrDown, employee);
                    isSortingModePressed = false;
                }
            }

            // проверка на кнопку СОРТИРОВКА ПО ФАМИЛИИ И ДР
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_sorting_with_surname.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSortingPressed)
                {
                    kindOfSort = 1;
                    isSortingModePressed = true;
                }

            }

            // проверка на кнопку СОРТИРОВКА ПО ФАМИЛИИ И ДР
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_sorting_with_post.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSortingPressed)
                {
                    kindOfSort = 2;
                    isSortingModePressed = true;
                }
            }

            // проверка на кнопку СОРТИРОВКА ПО ФАМИЛИИ И ДР
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_sorting_with_experience.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and isSortingPressed)
                {
                    kindOfSort = 3;
                    isSortingModePressed = true;
                }
            }


            // проверка на кнопку НАЗАД В СОРТИРОВКЕ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_get_back4.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSearchPressed)
                    isSortingModePressed = false;
            }

                 // проверка на кнопку СОРТИРОВКА
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_sorting.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !isSearchPressed and proccesingMode)
                    isSortingPressed = true;
            }
            // проверка на кнопку НАЗАД В СОРТИРОВКЕ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_get_back3.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSearchPressed)
                    isSortingPressed = false;
            }

            // проверка на кнопку НАЗАД
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_get_back4.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and isSortingPressed)
                    isSortingModePressed = false;
            }

  

                                                        // РЕДАКТИРОВАНИЕ
            // проверка на кнопку ВЫВЕСТИ ВСЕХ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_print_all.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and editingMode)
                    printAllEmployees_menu(employee);
            }

            // проверка на кнопку ДОБАВЛЕНИЕ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_add_employee.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and editingMode)
                    addNewEmployee_menu(employee);
            }

            // проверка на кнопку РЕДАКТИРОВАНИЕ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_edit_info.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and editingMode)
                    editInfoOfEmployee_menu(employee);
            }

            // проверка на кнопку УДАЛИТЬ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_delete_employee.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and editingMode)
                    deleteEmployee_menu(employee);
            }

            // проверка на кнопку НАЗАД
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_get_back1.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode)
                    proccesingMode = false;
            }

            // проверка на нажатие иконки АККАУНТ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed)
                    isAccPressed = true;
                else if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y) and isAccPressed)
                    isAccPressed = false;
            }

            // проверка на нажатие на новости
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_shtorka_orange.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen)
                    isNewsOpen = true;

                else if (sprite_shtorka_orange1.getGlobalBounds().contains(mousePos.x, mousePos.y) and isNewsOpen)
                    isNewsOpen = false;
            }

            // проверка на нажатие на выход из аккаунта
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_leave_from_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))  // тут убрал !isNewsOpen
                {
                    isRememberMePressed = 1;
                    writeInFileIsRememberOn(isRememberMePressed);
                    auth_menu(authentication, employee, isRememberMePressed);
                }
            }

            // проверка на нажатие на НАСТРОЙКИ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_settings.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen and !editingMode and !proccesingMode)
                    settings_menu();
            }

            // проверка на нажатие на РЕДАКТИРОВАНИЕ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_editing.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen and !editingMode and !proccesingMode)
                    editingMode = true;
            }

            // проверка на нажатие на ОБРАБОТКА
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_proccesing.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen and !proccesingMode and !editingMode)
                    proccesingMode = true;
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
        else if (isSortingModePressed)
        {
            line1.setPosition(450, 0);
            window.draw(text_sort_up);
            window.draw(text_sort_down);
            window.draw(text_get_back4);
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");

    // Создание текста
    sf::Text text_settigns(L"НАСТРОЙКИ", font2);
    createText(text_settigns, 64, sf::Color::White, sf::Vector2f(730.f, 50.f));

    sf::Text text_about_app(L"О приложении", font2);
    createText(text_about_app, 46, sf::Color::Black, sf::Vector2f(776.f, 310.f));

    sf::Text text_about_company(L"О компании", font2);
    createText(text_about_company, 46, sf::Color::Black, sf::Vector2f(800.f, 500.f));

    sf::Text text_tech_support(L"Техподдержка", font2);
    createText(text_tech_support, 46, sf::Color::Black, sf::Vector2f(766.f, 690.f));


    // Создание текстур
    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);

    sf::Texture rectangle1;
    loadTexture("rectangle.png", rectangle1);

    sf::Texture rectangle2;
    loadTexture("rectangle.png", rectangle2);

    sf::Texture rectangle3;
    loadTexture("rectangle.png", rectangle3);

    sf::Texture rectangle_orange;
    loadTexture("rectangle_orange.png", rectangle_orange);


    // Создание спрайтов
    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_rectangle1;
    createSprite(sprite_rectangle1, rectangle1, 0.6, 0.6, sf::Vector2f(560, 260));

    sf::Sprite sprite_rectangle2;
    createSprite(sprite_rectangle2, rectangle2, 0.6, 0.6, sf::Vector2f(560, 450));

    sf::Sprite sprite_rectangle3;
    createSprite(sprite_rectangle3, rectangle3, 0.6, 0.6, sf::Vector2f(560, 640));

    sf::Sprite sprite_rectangle_orange;
    createSprite(sprite_rectangle_orange, rectangle_orange, 0.2437, 0.2437, sf::Vector2f(0, 0));

    
    // Переменныя состоянияя
    bool isMouseOnArrow = false;             // Находится ли курсор на спрайте-стрелке(назад)
    bool isMouseOnRectangle1 = false;        // Находится ли курсор на спрайте-прмяугольнике1
    bool isMouseOnRectangle2 = false;        // Находится ли курсор на спрайте-прмяугольнике2
    bool isMouseOnRectangle3 = false;        // Находится ли курсор на спрайте-прмяугольнике3


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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    sf::Text text_name_Of_app(L"Название приложения : Учет стажа сотрудников", font2);
    createText(text_name_Of_app, 34, sf::Color::White, sf::Vector2f(500.f, 200.f));


    sf::Text text_description_Of_app1(L"Описание: Наше приложение предназначено для учета и отслеживания стажа работы ", font2);
    createText(text_description_Of_app1, 34, sf::Color::White, sf::Vector2f(130.f, 320.f));

    sf::Text text_description_Of_app2(L"сотрудников на предприятии. Оно поможет вам следить за датами приема на работу,", font2);
    createText(text_description_Of_app2, 34, sf::Color::White, sf::Vector2f(128.f, 390.f));

    sf::Text text_description_Of_app3(L"периодами отпусков и другими важными событиями в трудовой биографии сотрудников.", font2);
    createText(text_description_Of_app3, 34, sf::Color::White, sf::Vector2f(100.f, 460.f));

    sf::Text text_contacts1(L"Контакты: Если у вас есть вопросы или предложения, свяжитесь с нами по адресу", font2);
    createText(text_contacts1, 34, sf::Color::White, sf::Vector2f(160.f, 580.f));

    sf::Text text_contacts2(L"support@companytracker.com", font2);
    createText(text_contacts2, 34, sf::Color::White, sf::Vector2f(660.f, 650.f));

    sf::Text text_license(L"Лицензия и авторские права: © 2024 Учет стажа сотрудников", font2);
    createText(text_license, 26, sf::Color::White, sf::Vector2f(500.f, 1020.f));


    // Создание текстур
    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);


    // Создание спрайтов
    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));


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

    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");

    sf::Font font;
    loadFont(font, "shrift2.ttf");


    // Создание текста
    sf::Text text_name_Of_company("Pixel World", font);
    createText(text_name_Of_company, 64, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_history1(L"“Pixel World” была основана в 2010 году группой энтузиастов, объединенных общей страстью", font2);
    createText(text_history1, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_history2(L"к видеоиграм. От скромных начинаний в гараже мы выросли в успешную компанию", font2);
    createText(text_history2, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_history3(L"с международным признанием.", font2);
    createText(text_history3, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_mission1(L"Мы стремимся создавать увлекательные, креативные и инновационные игры,", font2);
    createText(text_mission1, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_mission2(L"которые приносят радость и развлечение нашим игрокам.", font2);
    createText(text_mission2, 34, sf::Color::White, sf::Vector2f(0, 0));
    
    sf::Text text_games1(L"Наша компания специализируется на создании игр для различных платформ, ", font2);
    createText(text_games1, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_games2(L"включая мобильные устройства, ПК и консоли.", font2);
    createText(text_games2, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_type(L"Разрабатываем игры в разных жанрах: от аркад и головоломок до RPG и симуляторов.", font2);
    createText(text_type, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_advantages1(L"Конкурентные преимущества:", font2);
    createText(text_advantages1, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_advantages2(L"Уникальный стиль: Наша команда талантливых художников и дизайнеров создает", font2);
    createText(text_advantages2, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_advantages3(L"узнаваемый пиксельный стиль, который отличает наши игры от других.", font2);
    createText(text_advantages3, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_advantages4(L"Геймплей и сюжет: Уделяем особое внимание интересному геймплею и захватывающим сюжетам.", font2);
    createText(text_advantages4, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_partners1(L"Мы сотрудничаем с издателями, платформами и другими игровыми компаниями, такими как", font2);
    createText(text_partners1, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_partners2(L"Windows, Apple, Steam, EpicGames и другими.", font2);
    createText(text_partners2, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_contact_info(L"Контактная информация:", font2);
    createText(text_contact_info, 34, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_contact_info1(L"Адрес: г. Минск, ул. Геймплейная, 42", font2);
    createText(text_contact_info1, 30, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_contact_info2(L"Телефон: +375 29 123 4567", font2);
    createText(text_contact_info2, 30, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_contact_info3(L"Электронная почта: info@pixelworldgames.com", font2);
    createText(text_contact_info3, 30, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_end(L"Мы гордимся нашей командой и продуктами и с нетерпением ждем новых вызовов и возможностей в мире игр!", font2);
    createText(text_end, 28, sf::Color::White, sf::Vector2f(0, 0));

    
    // Создание текстур
    sf::Texture ofice;
    loadTexture("ofice.jpg", ofice);


    // Создание спрайтов
    sf::Sprite sprite_ofice;
    createSprite(sprite_ofice, ofice, 0.6, 0.6, sf::Vector2f(0, 0));


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

        // Изменение положения элементов на экране
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


        // Отображение на экране
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

    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    sf::Text text_listOfEmployees(L"Список сотрудников", font2);
    createText(text_listOfEmployees, 64, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text employee1(L"", font2);
    createText(employee1, 32, sf::Color::White, sf::Vector2f(30, 30));


    float x = 120.0;
    float y = 120.0f;
    std::string currentEmployee;

    for (int i = 0; i < employee.size(); i++)
    {
        employee1.setPosition(x, y);

        std::string post;
        if (employee.at(i).post == Post::JUNIOR)
            post = "Junior";
        else if (employee.at(i).post == Post::MIDDLE)
            post = "Middle";
        else if (employee.at(i).post == Post::SENIOR)
            post = "Senior";
        else if (employee.at(i).post == Post::TEAM_LEADER)
            post = "Team leader";
        else if (employee.at(i).post == Post::PROJECT_MANAGER)
            post = "Project manager";
        else if (employee.at(i).post == Post::DIRECTOR_OF_DEPARTMENT)
            post = "Director of department";
        else if (employee.at(i).post == Post::DEPUTY_GENERAL_DIRECTOR)
            post = "Deputy general director";
        else if (employee.at(i).post == Post::GENERAL_DIRECTOR)
            post = "General director";

        currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(i).surName + " " + employee.at(i).name + " " + employee.at(i).patronymic + " " + employee.at(i).gender + " " + employee.at(i).dateOfBirthday
            + " " + employee.at(i).departmentName + " " + post + " " + employee.at(i).startDate;
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

        std::string post;
        if (employee.at(i).post == Post::JUNIOR)
            post = "Junior";
        else if (employee.at(i).post == Post::MIDDLE)
            post = "Middle";
        else if (employee.at(i).post == Post::SENIOR)
            post = "Senior";
        else if (employee.at(i).post == Post::TEAM_LEADER)
            post = "Team leader";
        else if (employee.at(i).post == Post::PROJECT_MANAGER)
            post = "Project manager";
        else if (employee.at(i).post == Post::DIRECTOR_OF_DEPARTMENT)
            post = "Director of department";
        else if (employee.at(i).post == Post::DEPUTY_GENERAL_DIRECTOR)
            post = "Deputy general director";
        else if (employee.at(i).post == Post::GENERAL_DIRECTOR)
            post = "General director";

        currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(i).surName + " " + employee.at(i).name + " " + employee.at(i).patronymic + " " + employee.at(i).gender + " " + employee.at(i).dateOfBirthday
            + " " + employee.at(i).departmentName + " " + post + " " + employee.at(i).startDate;
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





void addNewEmployee_menu(std::vector<Employee>& employee)
{
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текста
    sf::Text text_add_employee(L"Добавление сотрудника", font2);
    createText(text_add_employee, 64, sf::Color::White, sf::Vector2f(520.f, 30.f));

    sf::Text text_surName(L"Фамилия", font2);
    createText(text_surName, 42, sf::Color::White, sf::Vector2f(420.f, 164.f));

    sf::Text text_name(L"Имя", font2);
    createText(text_name, 42, sf::Color::White, sf::Vector2f(480.f, 360.f));

    sf::Text text_patronymic(L"Отчество", font2);
    createText(text_patronymic, 42, sf::Color::White, sf::Vector2f(420.f, 550.f));

    sf::Text text_gender(L"Пол", font2);
    createText(text_gender, 42, sf::Color::White, sf::Vector2f(480.f, 740.f));

    sf::Text text_DOB(L"Дата рождения", font2);
    createText(text_DOB, 42, sf::Color::White, sf::Vector2f(1160.f, 164.f));

    sf::Text text_departmentName(L"Название отдела", font2);
    createText(text_departmentName, 42, sf::Color::White, sf::Vector2f(1150.f, 360.f));

    sf::Text text_post(L"Должность", font2);
    createText(text_post, 42, sf::Color::White, sf::Vector2f(1200.f, 550.f));

    sf::Text text_startDate(L"Дата начала работы", font2);
    createText(text_startDate, 42, sf::Color::White, sf::Vector2f(1100.f, 740.f));

    sf::Text text_add(L"Добавить", font2);
    createText(text_add, 50, sf::Color::White, sf::Vector2f(1620.f, 970.f));

    sf::Text surName("", font2);
    createText(surName, 38, sf::Color::Black, sf::Vector2f(270.f, 256.f));

    sf::Text name("", font2);
    createText(name, 38, sf::Color::Black, sf::Vector2f(270.f, 446.f));

    sf::Text startDate("", font2);
    createText(startDate, 38, sf::Color::Black, sf::Vector2f(1070.f, 826.f));

    sf::Text patronymic("", font2);
    createText(patronymic, 38, sf::Color::Black, sf::Vector2f(270.f, 636.f));

    sf::Text gender("", font2);
    createText(gender, 38, sf::Color::Black, sf::Vector2f(270.f, 826.f));

    sf::Text date_of_birth("", font2);
    createText(date_of_birth, 38, sf::Color::Black, sf::Vector2f(1070.f, 256.f));

    sf::Text departmentName("", font2);
    createText(departmentName, 38, sf::Color::Black, sf::Vector2f(1070.f, 446.f));

    sf::Text post("", font2);
    createText(post, 38, sf::Color::Black, sf::Vector2f(1070.f, 636.f));


    // Stirng-переменные для ввода
    std::string str_surName;
    std::string str_name;
    std::string str_patronymic;
    std::string str_startDate;
    std::string str_gender;
    std::string str_date_of_birth;
    std::string str_departmentName;
    std::string str_post;
  


    // Создание текстур
    sf::Texture rectangle1;
    loadTexture("rectangle.png", rectangle1);

    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);


    // Создание спрайтов
    sf::Sprite sprite_surName;
    createSprite(sprite_surName, rectangle1, 0.5, 0.5, sf::Vector2f(200, 210));

    sf::Sprite sprite_name;
    createSprite(sprite_name, rectangle1, 0.5, 0.5, sf::Vector2f(200, 400));

    sf::Sprite sprite_patronymic;
    createSprite(sprite_patronymic, rectangle1, 0.5, 0.5, sf::Vector2f(200, 590));

    sf::Sprite sprite_gender;
    createSprite(sprite_gender, rectangle1, 0.5, 0.5, sf::Vector2f(200, 780));

    sf::Sprite sprite_date_of_birth;
    createSprite(sprite_date_of_birth, rectangle1, 0.5, 0.5, sf::Vector2f(1000, 210));

    sf::Sprite sprite_department_name;
    createSprite(sprite_department_name, rectangle1, 0.5, 0.5, sf::Vector2f(1000, 400));

    sf::Sprite sprite_post;
    createSprite(sprite_post, rectangle1, 0.5, 0.5, sf::Vector2f(1000, 590));

    sf::Sprite sprite_startDate;
    createSprite(sprite_startDate, rectangle1, 0.5, 0.5, sf::Vector2f(1000, 780));

    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));


    // Переменные состояния
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

                        if (successOfAdding_menu() == 1)
                            return;
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

    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание прмяугольнкиов
    sf::RectangleShape line;
    createRectangle(line, Vector2f(140.f, 2.f), Vector2f(0.f, 0.f), sf::Color::White);

    sf::RectangleShape rectangle;
    createRectangle(rectangle, Vector2f(90.f, 46.f), Vector2f(0.f, 0.f), sf::Color(0, 0, 0, 255));


    // Сздание текста
    sf::Text text_choose_number(L"Выберите номер сотрудника из списка, чьи данные вы хотите отредактировать: ", font2);
    createText(text_choose_number, 32, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_edit_info(L"Редактирование", font2);
    createText(text_edit_info, 64, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_accept(L"Принять", font2);
    createText(text_accept, 48, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_number(L"", font2);
    createText(text_number, 45, sf::Color::White, sf::Vector2f(0, 0));


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
                        editMode(employee, str_number);
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текста
    sf::Text text_choise(L"Выберите, что хотите отредактировать", font2);
    createText(text_choise, 46, sf::Color::White, sf::Vector2f(450.f, 30.f));

    sf::Text text_surName(L"Фамилия", font2);
    createText(text_surName, 46, sf::Color::Black, sf::Vector2f(420.f, 250.f));

    sf::Text text_name(L"Имя", font2);
    createText(text_name, 46, sf::Color::Black, sf::Vector2f(470.f, 440.f));

    sf::Text text_patronymic(L"Отчество", font2);
    createText(text_patronymic, 46, sf::Color::Black, sf::Vector2f(420.f, 630.f));

    sf::Text text_gender(L"Пол", font2);
    createText(text_gender, 46, sf::Color::Black, sf::Vector2f(470.f, 820.f));

    sf::Text text_DOB(L"Дата рождения", font2);
    createText(text_DOB, 46, sf::Color::Black, sf::Vector2f(1150.f, 250.f));

    sf::Text text_departmentName(L"Название отдела", font2);
    createText(text_departmentName, 46, sf::Color::Black, sf::Vector2f(1120.f, 440.f));

    sf::Text text_post(L"Должность", font2);
    createText(text_post, 46, sf::Color::Black, sf::Vector2f(1190.f, 630.f));

    sf::Text text_startDate(L"Дата начала работы", font2);
    createText(text_startDate, 46, sf::Color::Black, sf::Vector2f(1070.f, 820.f));


    // Создание текстур
    sf::Texture rectangle1;
    loadTexture("rectangle.png", rectangle1);

    sf::Texture rectangle_orange;
    loadTexture("rectangle_orange.png", rectangle_orange);

    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);


    // Создание спрайтов
    sf::Sprite sprite_surName;
    createSprite(sprite_surName, rectangle1, 0.5, 0.5, sf::Vector2f(200, 210));

    sf::Sprite sprite_name;
    createSprite(sprite_name, rectangle1, 0.5, 0.5, sf::Vector2f(200, 400));

    sf::Sprite sprite_patronymic;
    createSprite(sprite_patronymic, rectangle1, 0.5, 0.5, sf::Vector2f(200, 590));

    sf::Sprite sprite_gender;
    createSprite(sprite_gender, rectangle1, 0.5, 0.5, sf::Vector2f(200, 780));

    sf::Sprite sprite_date_of_birth;
    createSprite(sprite_date_of_birth, rectangle1, 0.5, 0.5, sf::Vector2f(1000, 210));

    sf::Sprite sprite_department_name;
    createSprite(sprite_department_name, rectangle1, 0.5, 0.5, sf::Vector2f(1000, 400));

    sf::Sprite sprite_post;
    createSprite(sprite_post, rectangle1, 0.5, 0.5, sf::Vector2f(1000, 590));

    sf::Sprite sprite_startDate;
    createSprite(sprite_startDate, rectangle1, 0.5, 0.5, sf::Vector2f(1000, 780));

    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_rectangle_orange;
    createSprite(sprite_rectangle_orange, rectangle_orange, 0.21, 0.21, sf::Vector2f(0, 0));


    // Переменные состояния
    bool isMouseOnArrow = false;
    bool isMouseOnRectangle1 = false;
    bool isMouseOnRectangle2 = false;
    bool isMouseOnRectangle3 = false;
    bool isMouseOnRectangle4 = false;
    bool isMouseOnRectangle5 = false;
    bool isMouseOnRectangle6 = false;
    bool isMouseOnRectangle7 = false;
    bool isMouseOnRectangle8 = false;

    // Переменная, хранящая выбранное поле структуры
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
                if (enterNewInfo_editMode(employee, str_number, kindOfFIeld) == 1)
                    return;
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
int enterNewInfo_editMode(std::vector<Employee>& employee, std::string str_number, int kindOfField)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");

    std::string str_newInfo;

    // Создание текста
    sf::Text text_newInfo("", font2);
    createText(text_newInfo, 48, sf::Color::Black, sf::Vector2f(638.f, 450.f));

    sf::Text text_enterNewInfo(L"Введите новую информацию", font2);
    createText(text_enterNewInfo, 52, sf::Color::White, sf::Vector2f(560.f, 50.f));

    sf::Text text_edit(L"Изменить", font2);
    createText(text_edit, 50, sf::Color::White, sf::Vector2f(1620.f, 970.f));


    // Создание текстур
    sf::Texture rectangle;
    loadTexture("rectangle.png", rectangle);

    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);


    // Создание спрайтов
    sf::Sprite sprite_rectangle;
    createSprite(sprite_rectangle, rectangle, 0.6, 0.6, sf::Vector2f(570, 400));

    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));


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
                return 0;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 0;
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
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isRectangleClicked = true;
            }

            // проверка на поле ИЗМЕНИТЬ
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_edit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    editEmployee(employee, str_newInfo, str_number, kindOfField); // получает новую инфо,номер сотдурника и номер поля для изменения
                    if (successOfEdit_menu() == 1)
                        return 1;
                }
            }

            // ввод текста в поле НОВАЯ ИНФА
            if (event.type == sf::Event::TextEntered and event.text.unicode < 128)
            {
                if (event.text.unicode == 8 and isRectangleClicked)
                { // Backspace
                    if (!str_newInfo.empty())
                        str_newInfo.pop_back();
                }
                else if (text_newInfo.getString().getSize() < 15 and isRectangleClicked)
                    str_newInfo += static_cast<char>(event.text.unicode);

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
                        if (areYouSure() == 1)
                        {
                            deleteEmployee(employee, str_number);
                            return;
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
    sf::Texture success;
    loadTexture("AreYouSure1.png", success);


    // Создание спрайтов
    sf::Sprite sprite_success;
    createSprite(sprite_success, success, 0.6, 0.6, sf::Vector2f(680.f, 350.f));

    // Создание прямоугольников
    sf::RectangleShape yes(Vector2f(240.f, 90.f));
    createRectangle(yes, Vector2f(267.f, 100.f), Vector2f(680.f, 596.f), sf::Color(59, 60, 54, 190));

    // Создание прямоугольников
    sf::RectangleShape no(Vector2f(240.f, 90.f));
    createRectangle(no, Vector2f(267.f, 100.f), Vector2f(947.f, 596.f), sf::Color(59, 60, 54, 190));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (yes.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 1;
            }

            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (no.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 0;
            }
        }

        window.draw(sprite_success);
        window.display();
    }
}


// ПОИСК

// по фамилии
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
            else if (event.type == sf::Event::KeyPressed and event.mouseButton.button == sf::Keyboard::Enter)
                printSearchingEmployeesWithSurname(employee, str_surName, isSurnameChanging);

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

// по должности
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


            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isButtonClicked = true;
                if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isTextEmpty)
                    printSearchingEmployeesWithPost(employee, str_post, isPostChanging);
            }
            else if (event.type == sf::Event::KeyPressed and event.mouseButton.button == sf::Keyboard::Enter)
                printSearchingEmployeesWithPost(employee, str_post, isPostChanging);

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

// по дате начала работы
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
            else if (event.type == sf::Event::KeyPressed and event.mouseButton.button == sf::Keyboard::Enter)
                printSearchingEmployeesWithYear(employee, str_year, isYearChanging);

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


//  ВСПЛЫВАЮЩИЕ ОКНА О СОСТОЯНИИ
int successOfSorting_menu(int kindOfSort, int sortUpOrDown, std::vector<Employee>& employee)
{
    if (kindOfSort == 1 and sortUpOrDown == 1)
        sortWithSurnameUp(employee);
    else if (kindOfSort == 2 and sortUpOrDown == 1)
        sortWithPostUp(employee);
    else if (kindOfSort == 3 and sortUpOrDown == 1)
        sortWithExperienceUp(employee);
    else if (kindOfSort == 1 and sortUpOrDown == 2)
        sortWithSurnameDown(employee);
    else if (kindOfSort == 2 and sortUpOrDown == 2)
        sortWithPostDown(employee);
    else if (kindOfSort == 3 and sortUpOrDown == 2)
        sortWithExperienceDown(employee);

    writeInToFileAfterDeleteEmployee(employee);

    sf::Texture success;
    loadTexture("SuccessSort.png", success);


    // Создание спрайтов
    sf::Sprite sprite_success;
    createSprite(sprite_success, success, 0.6, 0.6, sf::Vector2f(680.f, 350.f));

    // Создание прямоугольников
    sf::RectangleShape yes(Vector2f(240.f, 90.f));
    createRectangle(yes, Vector2f(535.f, 100.f), Vector2f(680.f, 596.f), sf::Color(59, 60, 54, 190));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (yes.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 1;
            }
        }

        window.draw(sprite_success);
        window.display();
    }
}
int successOfAdding_menu()
{
    sf::Texture success;
    loadTexture("Success1.png", success);


    // Создание спрайтов
    sf::Sprite sprite_success;
    createSprite(sprite_success, success, 0.6, 0.6, sf::Vector2f(680.f, 350.f));

    // Создание прямоугольников
    sf::RectangleShape yes(Vector2f(240.f, 90.f));
    createRectangle(yes, Vector2f(535.f, 100.f), Vector2f(680.f, 596.f), sf::Color(59, 60, 54, 190));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (yes.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 1;
            }
        }

        window.draw(sprite_success);
        window.display();
    }
}
int successOfEdit_menu()
{
    sf::Texture success;
    loadTexture("SuccessEdit.png", success);


    // Создание спрайтов
    sf::Sprite sprite_success;
    createSprite(sprite_success, success, 0.6, 0.6, sf::Vector2f(680.f, 350.f));

    // Создание прямоугольников
    sf::RectangleShape yes(Vector2f(240.f, 90.f));
    createRectangle(yes, Vector2f(535.f, 100.f), Vector2f(680.f, 596.f), sf::Color(59, 60, 54, 190));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (yes.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 1;
            }
        }

        window.draw(sprite_success);
        window.display();
    }
}