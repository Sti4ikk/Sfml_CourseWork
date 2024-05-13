#include "enums.h"
#include "prototypes.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include <array>
#include "structs.h"

struct TextData
{
    sf::Text text;
    std::string str;
    bool isClicked = false;
};

void handleTextField(TextData& textField, sf::Event& event, sf::RenderWindow& window);
bool handleButton(const sf::Text& button, sf::Event& event, sf::RenderWindow& window);
void createText(sf::Text& text, const std::wstring& str, const sf::Font& font, unsigned int size, const sf::Color& color, const sf::Vector2f& position);
void createText(sf::Text& text, const std::string& str, const sf::Font& font, unsigned int size, const sf::Color& color, const sf::Vector2f& position);
void highlightButton(sf::Text& button, sf::RenderWindow& window);
void highlightButton(sf::RectangleShape& button, sf::RenderWindow& window);
void enterLoginAndPassword(sf::Event& event, std::vector<TextData>& textFields);
bool loadFont(sf::Font& font, const std::string& filePath);
bool loadTexture(const std::string& filePath, sf::Texture& texture);
void createSprite(sf::Sprite& sprite, const sf::Texture& texture, const float x, const float y, const sf::Vector2f& position);
void createText(sf::Text& text, unsigned int characterSize, const sf::Color& color, const sf::Vector2f& position);
void createRectangle(sf::RectangleShape& rectangle, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const float outlineThickness = 0, const sf::Color outlineColor = sf::Color(0, 0, 0, 255));

extern sf::RenderWindow window;


// ОСНОВНЫЕ ФУНКЦИИ МЕНЮ
void main_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed, int numberOfPersonalEmployee)
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


    // Создание прямоугольников
    sf::RectangleShape account(sf::Vector2f(240.f, 90.f));
    createRectangle(account, sf::Vector2f(240.f, 90.f), sf::Vector2f(1660.f, 94.f), sf::Color(59, 60, 54, 190));

    sf::RectangleShape polosa(sf::Vector2f(1000.f, 1080.f));
    createRectangle(polosa, sf::Vector2f(1000.f, 1080.f), sf::Vector2f(530.f, 0.f), sf::Color::White);

    sf::RectangleShape line1(sf::Vector2f(1.f, 1080.f));
    createRectangle(line1, sf::Vector2f(1.f, 1080.f), sf::Vector2f(0.f, 0.f), sf::Color(59, 60, 54));


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

    sf::Text text_search1(L"Поиск сотрудников\nпенсионного возраста", font2);
    createText(text_search1, 40, sf::Color::White, sf::Vector2f(25.f, 525.f));

    sf::Text text_experience(L"Стаж сотрудников", font2);
    createText(text_experience, 40, sf::Color::White, sf::Vector2f(25.f, 640.f));

    sf::Text text_get_back1(L"Назад", font2);
    createText(text_get_back1, 40, sf::Color::White, sf::Vector2f(25.f, 710.f));

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
    loadTexture("shtorka1.png", shtorka);

    sf::Texture shtorka1;
    loadTexture("shtorka1.png", shtorka1);

    sf::Texture shtorka_orange1;
    loadTexture("shtorka_orange.png", shtorka_orange1);

    sf::Texture shtorka_orange;
    loadTexture("shtorka_orange.png", shtorka_orange);

    sf::Texture triangle;
    loadTexture("triangle.png", triangle);

    sf::Texture triangle_orange;
    loadTexture("triangle_orange.png", triangle_orange);

    sf::Texture triangleForNews;
    loadTexture("triangle.png", triangleForNews);

    sf::Texture triangleForNews_orange;
    loadTexture("triangle_orange.png", triangleForNews_orange);

    sf::Sprite sprite_triangleForNews;
    createSprite(sprite_triangleForNews, triangle, 0.04, 0.04, sf::Vector2f(1875, 540));

    // Установка точки начала в центр спрайта
    sprite_triangleForNews.setOrigin(sprite_triangleForNews.getLocalBounds().width / 2, sprite_triangleForNews.getLocalBounds().height / 2);
    sprite_triangleForNews.setRotation(90.f);


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

    sf::Sprite sprite_triangle;
    createSprite(sprite_triangle, triangle, 0.04, 0.04, sf::Vector2f(1884.f, 80.f));

    sf::Sprite sprite_triangle_orange;
    createSprite(sprite_triangle_orange, triangle_orange, 0.04, 0.04, sf::Vector2f(1884.f, 80.f));
    // Установка точки начала в центр спрайта
    sprite_triangle.setOrigin(sprite_triangle.getLocalBounds().width / 2, sprite_triangle.getLocalBounds().height / 2);
    sprite_triangle_orange.setOrigin(sprite_triangle.getLocalBounds().width / 2, sprite_triangle.getLocalBounds().height / 2);

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

    bool isMouseOnAcc = false;


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
            if (sprite_shtorka.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                // Изменение цвета прямоугольника, если курсор находится над ним
                isMouseOnShtorka = true;
                triangleIsMouseOnShtorka = true;
            }
            else
            {
                triangleIsMouseOnShtorka = false;
                isMouseOnShtorka = false;
            }

            if (sprite_shtorka.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
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
            if (sprite_shtorka1.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                // Изменение цвета прямоугольника, если курсор находится над ним
                isMouseOnShtorka1 = true;
                triangleIsMouseOnShtorka1 = true;
            }
            else
            {
                triangleIsMouseOnShtorka1 = false;
                isMouseOnShtorka1 = false;
            }

            highlightButton(text_editing, window);
            highlightButton(text_proccesing, window);
            highlightButton(text_settings, window);
            highlightButton(text_exit, window);
            highlightButton(text_account, window);
            highlightButton(text_leave_from_acc, window);
            highlightButton(text_print_all, window);
            highlightButton(text_leave_from_acc, window);
            highlightButton(text_add_employee, window);
            highlightButton(text_edit_info, window);
            highlightButton(text_delete_employee, window);

            highlightButton(text_get_back, window);
            highlightButton(text_search, window);
            highlightButton(text_sorting, window);
            highlightButton(text_delete_employee, window);


            if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnAcc = true;
            else
                isMouseOnAcc = false;



            // подсветка кнопок в меню ОБРАБОТКА
            if (proccesingMode)
            {
                highlightButton(text_search1, window);
                highlightButton(text_experience, window);
                highlightButton(text_get_back1, window);
            }
            // подсветка кнопок в меню ПОИСК
            if (isSearchPressed)
            {
                highlightButton(text_search_with_surname, window);
                highlightButton(text_search_with_post, window);
                highlightButton(text_search_with_year, window);
                highlightButton(text_get_back2, window);
            }
            // подсветка кнопок в меню СОРТИРОВКА
            if (isSortingPressed)
            {
                highlightButton(text_sorting_with_surname, window);
                highlightButton(text_sorting_with_post, window);
                highlightButton(text_sorting_with_experience, window);
                highlightButton(text_get_back3, window);
                highlightButton(text_get_back4, window);
                highlightButton(text_sort_up, window);
                highlightButton(text_sort_down, window);
            }


            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_account.getGlobalBounds().contains(mousePos.x, mousePos.y) and isAccPressed)
                    account_menu(authentication, numberOfPersonalEmployee);
            }


            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_search1.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and proccesingMode and !isSearchPressed and !isSortingPressed)
                    employeesOfRetirementAge_menu(employee);
            }
           

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

            

            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (text_experience.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and !isSortingPressed and !isSearchPressed and proccesingMode)
                    printExperience_menu(employee);
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
                if (text_sort_up.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isAccPressed and !editingMode and isSortingModePressed)
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
        else if (!proccesingMode and editingMode)
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
            window.draw(text_experience);
            window.draw(text_get_back1);
        }


        if (isAccPressed)
        {
            sprite_triangle.setRotation(180.f);
            sprite_triangle_orange.setRotation(180.f);
            window.draw(account);
            window.draw(text_account);
            window.draw(text_leave_from_acc);
        }
        else
        {
            sprite_triangle.setRotation(0.f);
            sprite_triangle_orange.setRotation(0.f);
        }


        if (triangleIsMouseOnShtorka and !isNewsOpen)
        {
            sprite_triangleForNews.setRotation(90.f);
            sprite_triangleForNews.setPosition(1875, 540);
            window.draw(sprite_triangleForNews);
        }


        if (isMouseOnShtorka and !isNewsOpen)
            window.draw(sprite_shtorka_orange);
        else if (!isNewsOpen)
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
            {
                sprite_triangleForNews.setRotation(270.f);
                sprite_triangleForNews.setPosition(1436, 540);
                window.draw(sprite_triangleForNews);
            }

        }

        if (isMouseOnAcc)
            window.draw(sprite_triangle_orange);
        else
            window.draw(sprite_triangle);




        window.draw(sprite_logo);
        window.draw(line1);
        window.display();
    }
}
void auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool& isRememberMePressed)
{
    // Создание окна
    window.create(sf::VideoMode(500, 412), "", sf::Style::None);


    // Загрузка шрифта
    sf::Font font;
    loadFont(font, "shrift.ttf");


    // Создание прямоугольников
    sf::RectangleShape rectangle1;
    createRectangle(rectangle1, sf::Vector2f(430.f, 70.f), sf::Vector2f(35.f, 80.f), sf::Color::Black, 1.f, sf::Color(59, 60, 54));

    sf::RectangleShape rectangle2;
    createRectangle(rectangle2, sf::Vector2f(430.f, 70.f), sf::Vector2f(35.f, 160.f), sf::Color::Black, 1.f, sf::Color(59, 60, 54));

    sf::RectangleShape rectangle3;
    createRectangle(rectangle3, sf::Vector2f(430.f, 70.f), sf::Vector2f(35.f, 255.f), sf::Color(255, 193, 7));

    sf::RectangleShape square;
    createRectangle(square, sf::Vector2f(25.f, 25.f), sf::Vector2f(45.f, 340.f), sf::Color(59, 60, 54));

    sf::RectangleShape line1;
    createRectangle(line1, sf::Vector2f(1.f, 70.f), sf::Vector2f(99.f, 80.f), sf::Color(59, 60, 54));

    sf::RectangleShape line2;
    createRectangle(line2, sf::Vector2f(1.f, 70.f), sf::Vector2f(99.f, 160.f), sf::Color(59, 60, 54));


    // Создание текста
    std::vector<TextData> textFields;

    for (int i = 0; i < 3; ++i)
    {
        TextData textField;
        textFields.push_back(textField);
    }

    std::vector<sf::Vector2f> textPositions = {
        sf::Vector2f(110.f, 98.f),
        sf::Vector2f(110.f, 178.f),
        sf::Vector2f(110.f, 178.f) };

    std::array<int, 3> fontSize = { 28, 28, 44 };

    // Инициализация текста
    for (int i = 0; i < textFields.size(); ++i)
        createText(textFields[i].text, "", font, fontSize.at(i), sf::Color::White, textPositions.at(i));

    sf::Text text(L"Авторизация", font);
    createText(text, 46, sf::Color::White, sf::Vector2f(88.f, 8.f));

    sf::Text entrance(L"Войти", font);
    createText(entrance, 30, sf::Color::White, sf::Vector2f(188.f, 272.f));

    sf::Text rememberMe(L"Запомнить меня", font);
    createText(rememberMe, 14, sf::Color(59, 60, 54), sf::Vector2f(81.f, 344.f));

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
    bool isPasswordOpen = false;
    bool isTextPasswordOpen = false;
    bool isRememberMeOn = false;
    bool isIncorrectData = false;
    bool isDragging = false;

    // Координаты текущего клика
    sf::Vector2i clickPosition;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_krest.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    window.close();


                // проверка на поле для ввода
                if (rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    isIncorrectData = false;
                    textFields.at(0).isClicked = true;
                    textFields.at(1).isClicked = false;
                }
                else if (rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    isIncorrectData = false;
                    textFields.at(0).isClicked = false;
                    textFields.at(1).isClicked = true;
                }


                // ПРОВЕРКА НА НАЖАТИЕ ГАЛОЧКИ
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


                // проверка на нажатие кнопки видимости пароля
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


                // ПРОЕВРКА НА ПРАВИЛЬНОСТЬ ВВДЕННЫХ ДАННЫХ
                if (rectangle3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    std::string login1;
                    std::string password5;
                    login1 = textFields.at(0).text.getString();
                    password5 = textFields.at(1).text.getString();

                    std::array<int, 2> arr = checkDataOfUser(authentication, login1, password5);

                    if (arr.at(0))
                    {
                        window.close();
                        main_menu(authentication, employee, isRememberMePressed, arr.at(1));
                    }
                    else
                    {
                        textFields.at(0).str = "";
                        textFields.at(1).str = "";
                        textFields.at(2).str = "";
                        textFields.at(0).text.setString(textFields.at(0).str);
                        textFields.at(1).text.setString(textFields.at(1).str);
                        textFields.at(2).text.setString(textFields.at(2).str);
                        isIncorrectData = true;
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                // Запоминаем позицию, в которой была нажата кнопка мыши
                isDragging = true;
                clickPosition = sf::Mouse::getPosition(window);
            }
            else if (event.type == sf::Event::MouseButtonReleased and event.mouseButton.button == sf::Mouse::Left)
                // Когда кнопка мыши отпущена, заканчиваем перетаскивание
                isDragging = false;


            // Изменение цвета прямоугольника, если курсор находится над ним
            highlightButton(rectangle3, window);

            // ВВОД ЛОГИНА И ПАРОЛЯ
            enterLoginAndPassword(event, textFields);
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
        window.draw(textFields.at(0).text);
        window.draw(rememberMe);
        if (isTextPasswordOpen) window.draw(textFields.at(1).text);
        else window.draw(textFields.at(2).text);
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
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;
                else if(sprite_rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    aboutApp();
                else if (sprite_rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    aboutCompany();

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
                isMouseOnRectangle3 = true;
            else
                isMouseOnRectangle3 = false;

        }
        sprite_rectangle_orange.setPosition(560, 640);


        window.clear(sf::Color::Black);

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


    // Создание текста
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
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");

    sf::Font font;
    loadFont(font, "shrift2.ttf");

    // Создание текста
    std::vector<TextData> textFields;

    for (int i = 0; i < 20; ++i)
    {
        TextData textField;
        textFields.push_back(textField);
    }

    std::array<int, 20> fontSize = { 64, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34
    , 34, 30, 30, 30, 28 };

    std::wstring textLabels[20] =
    {
        L"Pixel World", // Заголовок
        L"“Pixel World” была основана в 2010 году группой энтузиастов, объединенных общей страстью", // История - часть 1
        L"к видеоиграм. От скромных начинаний в гараже мы выросли в успешную компанию", // История - часть 2
        L"с международным признанием.", // История - часть 3
        L"Мы стремимся создавать увлекательные, креативные и инновационные игры,", // Миссия - часть 1
        L"которые приносят радость и развлечение нашим игрокам.", // Миссия - часть 2
        L"Наша компания специализируется на создании игр для различных платформ,", // Игры - часть 1
        L"включая мобильные устройства, ПК и консоли.", // Игры - часть 2
        L"Разрабатываем игры в разных жанрах: от аркад и головоломок до RPG и симуляторов.", // Типы игр
        L"Конкурентные преимущества:", // Преимущества - часть 1
        L"Уникальный стиль: Наша команда талантливых художников и дизайнеров создает", // Преимущества - часть 2
        L"узнаваемый пиксельный стиль, который отличает наши игры от других.", // Преимущества - часть 3
        L"Геймплей и сюжет: Уделяем особое внимание интересному геймплею и захватывающим сюжетам.", // Преимущества - часть 4
        L"Мы сотрудничаем с издателями, платформами и другими игровыми компаниями, такими как", // Партнеры - часть 1
        L"Windows, Apple, Steam, EpicGames и другими.", // Партнеры - часть 2
        L"Контактная информация:", // Контактная информация - заголовок
        L"Адрес: г. Минск, ул. Геймплейная, 42", // Контактная информация - адрес
        L"Телефон: +375 29 123 4567", // Контактная информация - телефон
        L"Электронная почта: info@pixelworldgames.com", // Контактная информация - электронная почта
        L"Мы гордимся нашей командой и продуктами и с нетерпением ждем новых вызовов и возможностей в мире игр!" // Заключительный текст
    };

    // Инициализация текста
    for (int i = 0; i < textFields.size(); ++i)
        createText(textFields[i].text, textLabels[i], (i == 0) ? font : font2, fontSize.at(i), sf::Color::White, sf::Vector2f(0, 0));


    // Создание текстур
    sf::Texture ofice;
    loadTexture("ofice.jpg", ofice);


    // Создание спрайтов
    sf::Sprite sprite_ofice;
    createSprite(sprite_ofice, ofice, 0.6, 0.6, sf::Vector2f(0, 0));


    float scrollPosition = 0.0f;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;

            if (event.type == sf::Event::MouseWheelScrolled)
            {
                // Обработка прокрутки колесика мыши
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    // Проверяем, выходит ли текст за границы окна
                    float lastTextBottom = 2600 + textFields.at(textFields.size() - 1).text.getLocalBounds().height + 15;
                    float windowHeight = window.getSize().y;

                    if (lastTextBottom > windowHeight or lastTextBottom < windowHeight) // Добавлена проверка на случай, если текст не заполняет окно полностью
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
        std::vector<sf::Vector2f> textPositions = {
             sf::Vector2f(700.f, 50 + scrollPosition), // Позиция для "Pixel World"
             sf::Vector2f(60.f, 200 + scrollPosition), // Позиция для истории - часть 1
             sf::Vector2f(126.f, 270 + scrollPosition), // Позиция для истории - часть 2
             sf::Vector2f(676.f, 340 + scrollPosition), // Позиция для истории - часть 3
             sf::Vector2f(200.f, 460 + scrollPosition), // Позиция для миссии - часть 1
             sf::Vector2f(410.f, 530 + scrollPosition), // Позиция для миссии - часть 2
             sf::Vector2f(216.f, 650 + scrollPosition), // Позиция для игр - часть 1
             sf::Vector2f(520.f, 720 + scrollPosition), // Позиция для игр - часть 2
             sf::Vector2f(120.f, 790 + scrollPosition), // Позиция для типов игр
             sf::Vector2f(660.f, 910 + scrollPosition), // Позиция для преимуществ - часть 1
             sf::Vector2f(170.f, 980 + scrollPosition), // Позиция для преимуществ - часть 2
             sf::Vector2f(270.f, 1050 + scrollPosition), // Позиция для преимуществ - часть 3
             sf::Vector2f(20.f, 1120 + scrollPosition), // Позиция для преимуществ - часть 4
             sf::Vector2f(66.f, 1240 + scrollPosition), // Позиция для партнеров - часть 1
             sf::Vector2f(520.f, 1310 + scrollPosition), // Позиция для партнеров - часть 2
             sf::Vector2f(160.f, 2280 + scrollPosition), // Позиция для контактной информации - заголовок
             sf::Vector2f(220.f, 2350 + scrollPosition), // Позиция для контактной информации - адрес
             sf::Vector2f(220.f, 2420 + scrollPosition), // Позиция для контактной информации - телефон
             sf::Vector2f(220.f, 2490 + scrollPosition), // Позиция для контактной информации - электронная почта
             sf::Vector2f(60.f, 2600 + scrollPosition) // Позиция для заключительного текста
        };

        // Изменение положения элементов на экране
        for (int i = 0; i < 20; i++)
            textFields.at(i).text.setPosition(textPositions.at(i));

        sprite_ofice.setPosition(390, 1460 + scrollPosition);

        // Отображение на экране
        window.clear(sf::Color::Black);
        for (auto& text : textFields)
            window.draw(text.text);
        window.draw(sprite_ofice);

        window.display();
    }
}
void printAllEmployees_menu(std::vector<Employee>& employee)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    float scrollPosition = 0.0f;
    float y = 0.0f;

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
    createText(employee1, 28, sf::Color::White, sf::Vector2f(30, 30));


    float x = 100.0;
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    sf::Text employee1(L"", font2);
    createText(employee1, 30, sf::Color::White, sf::Vector2f(30.f, 30.f));


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


    // ЗАГРУЗКА ТЕКСТУР
    sf::Texture rectangleTexture;
    loadTexture("rectangle.png", rectangleTexture);

    sf::Texture arrowBackWhiteTexture;
    loadTexture("arrow_back_white.png", arrowBackWhiteTexture);

    sf::Texture arrowBackOrangeTexture;
    loadTexture("arrow_back.png", arrowBackOrangeTexture);


    // СОЗДАНИЕ ТЕКСТОВЫХ ПОЛЕЙ
    std::vector<TextData> textFields;
    std::vector<TextData> textFields1;    // для пометки прямоугольников

    for (int i = 0; i < 8; ++i)
    {
        TextData textField;
        textFields.push_back(textField);
    }

    for (int i = 0; i < 8; ++i)
    {
        TextData textField;
        textFields1.push_back(textField);
    }

    std::wstring textLabels[] =
    {
        L"Фамилия", L"Имя", L"Отчество", L"Пол",
        L"Дата рождения", L"Название отдела", L"Должность", L"Дата начала работы"
    };

    std::vector<sf::Vector2f> spritePositions =
    {
    sf::Vector2f(200.f, 210.f),    // Позиция для sprite_surName
    sf::Vector2f(200.f, 400.f),    // Позиция для sprite_name
    sf::Vector2f(200.f, 590.f),    // Позиция для sprite_patronymic
    sf::Vector2f(200.f, 780.f),    // Позиция для sprite_gender
    sf::Vector2f(1000.f, 210.f),    // Позиция для sprite_date_of_birth
    sf::Vector2f(1000.f, 400.f),    // Позиция для sprite_department_name
    sf::Vector2f(1000.f, 590.f),    // Позиция для sprite_post
    sf::Vector2f(1000.f, 780.f)    // Позиция для sprite_startDate
    };

    std::vector<sf::Vector2f> textPositions1 =
    {
    sf::Vector2f(420.f, 164.f),
    sf::Vector2f(480.f, 360.f),
    sf::Vector2f(420.f, 550.f),
    sf::Vector2f(480.f, 740.f),
    sf::Vector2f(1160.f, 164.f),
    sf::Vector2f(1150.f, 360.f),
    sf::Vector2f(1200.f, 550.f),
    sf::Vector2f(1100.f, 740.f)
    };

    std::vector<sf::Vector2f> textPositions =
    {
    sf::Vector2f(270.f, 256.f),    // Позиция для surName
    sf::Vector2f(270.f, 446.f),    // Позиция для name
    sf::Vector2f(270.f, 636.f),    // Позиция для patronymic
    sf::Vector2f(270.f, 826.f),    // Позиция для gender
    sf::Vector2f(1070.f, 256.f),    // Позиция для date_of_birth
    sf::Vector2f(1070.f, 446.f),    // Позиция для department_name
    sf::Vector2f(1070.f, 636.f),    // Позиция для post
    sf::Vector2f(1070.f, 826.f)    // Позиция для startDate
    };

    // Инициализация текста
    for (int i = 0; i < textFields.size(); ++i)
        createText(textFields[i].text, "", font2, 42, sf::Color::Black, textPositions.at(i));
    for (int i = 0; i < textFields1.size(); ++i)
        createText(textFields1[i].text, textLabels[i], font2, 42, sf::Color::White, textPositions1.at(i));

    sf::Text addButton(L"Добавить", font2, 50);
    addButton.setFillColor(sf::Color::White);
    addButton.setPosition(1620.f, 970.f);

    sf::Text text_add_employee(L"Добавление сотрудника", font2);
    createText(text_add_employee, 64, sf::Color::White, sf::Vector2f(520.f, 30.f));


    // СОЗДАНИЕ СПРАЙТОВ
    std::vector<sf::Sprite> sprites =
    {
        sf::Sprite(), // Фамилия
        sf::Sprite(), // Имя
        sf::Sprite(), // Отчество
        sf::Sprite(), // Пол
        sf::Sprite(), // Дата рождения
        sf::Sprite(), // Название отдела
        sf::Sprite(), // Должность
        sf::Sprite()  // Дата начала работы
    };

    for (int i = 0; i < sprites.size(); ++i)
        createSprite(sprites[i], rectangleTexture, 0.5, 0.5, spritePositions.at(i));

    sf::Sprite arrowBackWhiteSprite;
    createSprite(arrowBackWhiteSprite, arrowBackWhiteTexture, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite arrowBackOrangeSprite;
    createSprite(arrowBackOrangeSprite, arrowBackOrangeTexture, 0.2, 0.2, sf::Vector2f(50, 950));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                window.close();


            // ПОДСВЕТКА КНОПОК
            highlightButton(addButton, window);


            // ОБРАБОТКА НАЖАТИЯ НА ПОЛЯ
            for (int i = 0; i < 8; i++)
            {
                if (sprites.at(i).getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // Если спрайт был нажат
                    for (auto& s : textFields)
                    {
                        // Выключаем все спрайты
                        s.isClicked = false;
                    }
                    // Включаем только текущий спрайт
                    textFields.at(i).isClicked = true;
                }
            }

            // ОБРАБОТКА ТЕКСТОВЫХ ПОЛЕЙ
            for (auto& textField : textFields)
                handleTextField(textField, event, window);


            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                if (arrowBackOrangeSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    return;

                // Обработка нажатия кнопки "Добавить"
                if (handleButton(addButton, event, window))
                {
                    addNewEmployee(employee, textFields[0].str, textFields[1].str, textFields[2].str, textFields[3].str,
                        textFields[4].str, textFields[5].str, textFields[6].str, textFields[7].str);

                    if (successOfAdding_menu() == 1)
                        return;
                }
            }
        }

        window.clear(sf::Color::Black);
        for (const auto& sprite : sprites)
            window.draw(sprite);

        for (const auto& textField : textFields)
            window.draw(textField.text);

        for (const auto& textField : textFields1)
            window.draw(textField.text);

        if (arrowBackOrangeSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            window.draw(arrowBackOrangeSprite);
        else
            window.draw(arrowBackWhiteSprite);

        window.draw(addButton);
        window.draw(text_add_employee);

        window.display();
    }
}
void editInfoOfEmployee_menu(std::vector<Employee>& employee)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание прмяугольнкиов
    sf::RectangleShape line;
    createRectangle(line, sf::Vector2f(140.f, 2.f), sf::Vector2f(0.f, 0.f), sf::Color::White);

    sf::RectangleShape rectangle;
    createRectangle(rectangle, sf::Vector2f(90.f, 46.f), sf::Vector2f(0.f, 0.f), sf::Color(0, 0, 0, 255));


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
    float scrollPosition = 0.0f;
    float y = 0.0f;

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
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isRectangleClicked = true;

                // проверка на поле для ПРИНЯТЬ
                if (text_accept.getGlobalBounds().contains(mousePos.x, mousePos.y) and !str_number.empty())
                    editMode(employee, str_number);
            }


            // ввод текста в поле цифры
            if (event.type == sf::Event::TextEntered and event.text.unicode < 128)
            {
                if (event.text.unicode == 8 and isRectangleClicked)
                { // Backspace
                    if (!str_number.empty())
                        str_number.pop_back();
                }
                else if (isRectangleClicked and text_number.getString().getSize() < 4)
                    str_number += static_cast<char>(event.text.unicode);

                text_number.setString(str_number);
            }

            // ПОДСВЕЧИВАНИЕ КНОПКИ ПРИНЯТЬ
            highlightButton(text_accept, window);

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
void editMode(std::vector<Employee>& employee, std::string str_number)
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
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;

                if (sprite_surName.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    kindOfFIeld = 1;

                //ПРОВЕРКА НА НАЖАТИЕ НА ПРЯМОУГОЛЬНИКИ
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
    std::string str_newInfo;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return 0;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 0;

                // проверка на поле для ввода
                if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isRectangleClicked = true;

                // проверка на поле ИЗМЕНИТЬ
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


            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            highlightButton(text_edit, window);
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


    // Создание фигур
    sf::RectangleShape line(sf::Vector2f(140.f, 2.f));
    createRectangle(line, sf::Vector2f(140.f, 2.f), sf::Vector2f(1660.f, 94.f), sf::Color::White);

    sf::RectangleShape rectangle(sf::Vector2f(160.f, 46.f));
    createRectangle(rectangle, sf::Vector2f(160.f, 46.f), sf::Vector2f(1660.f, 94.f), sf::Color(0, 0, 0, 255));


    // Создание текста
    sf::Text text_choose_number(L"Выберите номер сотрудника из списка, чьи данные вы хотите удалить: ", font2);
    createText(text_choose_number, 32, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_delete_info(L"Удаление", font2);
    createText(text_delete_info, 64, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_accept(L"Принять", font2);
    createText(text_accept, 48, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text text_number(L"", font2);
    createText(text_number, 45, sf::Color::White, sf::Vector2f(0, 0));


    std::string str_number;
    bool isRectangleClicked = false;
    float scrollPosition = 0.0f;
    float y = 0.0f;

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
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isRectangleClicked = true;

                // проверка на поле для ПРИНЯТЬ
                if (text_accept.getGlobalBounds().contains(mousePos.x, mousePos.y) and !str_number.empty())
                    if (areYouSure() == 1)
                    {
                        deleteEmployee(employee, str_number);
                        return;
                    }
            }


            // ввод текста в поле цифры
            if (event.type == sf::Event::TextEntered and event.text.unicode < 128)
            {
                if (event.text.unicode == 8 and isRectangleClicked)
                { // Backspace
                    if (!str_number.empty())
                        str_number.pop_back();
                }
                else if (isRectangleClicked and text_number.getString().getSize() < 4)
                    str_number += static_cast<char>(event.text.unicode);

                text_number.setString(str_number);
            }


            // ПОДСВЕЧИВАНИЕ КНОПКИ ПРИНЯТЬ
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            highlightButton(text_accept, window);

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
void account_menu(std::vector<Authentication>& authentication, int numberOfPersonalEmployee)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Сздание текста
    sf::Text text_account(L"Учётная запись", font2);
    createText(text_account, 64, sf::Color::White, sf::Vector2f(704, 40));

    sf::Text text_add_personal_employee(L"Добавить сотрудника", font2);
    createText(text_add_personal_employee, 28, sf::Color::Black, sf::Vector2f(796, 776));

    sf::Text text_name;
    if (numberOfPersonalEmployee == -1)
    {
        text_name.setString("admin");
        text_name.setFont(font2);
        createText(text_name, 34, sf::Color::White, sf::Vector2f(920, 590));
    }
    else
    {
        text_name.setString(authentication.at(numberOfPersonalEmployee).auth_info.surName + " " + authentication.at(numberOfPersonalEmployee).auth_info.name + " " +
            authentication.at(numberOfPersonalEmployee).auth_info.patronymic);
        text_name.setFont(font2);
        createText(text_name, 34, sf::Color::White, sf::Vector2f(700, 590));
    }


    std::string post;
    if (numberOfPersonalEmployee == -1)
        post = "";
    else
        post = "Post: " + authentication.at(numberOfPersonalEmployee).auth_info.post;
    sf::Text text_post(post, font2);

    createText(text_post, 34, sf::Color::White, sf::Vector2f(800, 650));


    // Создание текстур
    sf::Texture texture_photo;
    if (numberOfPersonalEmployee == -1)
        loadTexture("admin.jpg", texture_photo);
    else
        loadTexture(authentication.at(numberOfPersonalEmployee).auth_info.photoLink, texture_photo);

    // Создание текстур
    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);

    sf::Texture rectangleTexture;
    loadTexture("rectangle.png", rectangleTexture);

    sf::Texture rectangle_orange;
    loadTexture("rectangle_orange.png", rectangle_orange);


    // Создание спрайтов
    sf::Sprite sprite_photo;
    createSprite(sprite_photo, texture_photo, 1, 1, sf::Vector2f(800, 160));

    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_rectangle;
    createSprite(sprite_rectangle, rectangleTexture, 0.4, 0.4, sf::Vector2f(710, 740));

    sf::Sprite sprite_rectangle_orange;
    createSprite(sprite_rectangle_orange, rectangle_orange, 0.162467, 0.162467, sf::Vector2f(710, 740));


    bool isMouseOnArrow = false;
    bool isMouseOnRectangle = false;        // Находится ли курсор на спрайте-прмяугольнике1

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        return;

                    if (sprite_rectangle_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        addNewPersonalEmployee(authentication);
                }
            }
            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;
            if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnRectangle = true;
            else
                isMouseOnRectangle = false;
        }

        window.clear(sf::Color::Black);

        window.draw(text_account);
        window.draw(sprite_photo);
        window.draw(text_name);
        window.draw(text_post);

        if (isMouseOnArrow)
            window.draw(sprite_arrow_back_orange);
        else
            window.draw(sprite_arrow_back_white);

        if (!isMouseOnRectangle and numberOfPersonalEmployee == -1)
        {
            window.draw(sprite_rectangle);
            window.draw(text_add_personal_employee);
        }
        else if (isMouseOnRectangle and numberOfPersonalEmployee == -1)
        {
            window.draw(sprite_rectangle_orange);
            window.draw(text_add_personal_employee);
        }

        window.display();
    }
}
void addNewPersonalEmployee(std::vector<Authentication>& authentication)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");

    // Сздание текста
    sf::Text text_add(L"Добавление сотрудника", font2);
    createText(text_add, 64, sf::Color::White, sf::Vector2f(588, 40));

    // Сздание текста
    sf::Text button_add(L"Добавить", font2);
    createText(button_add, 50, sf::Color::White, sf::Vector2f(1620.f, 970.f));


    // ЗАГРУЗКА ТЕКСТУР
    sf::Texture rectangleTexture;
    loadTexture("rectangle.png", rectangleTexture);

    sf::Texture arrowBackWhiteTexture;
    loadTexture("arrow_back_white.png", arrowBackWhiteTexture);

    sf::Texture arrowBackOrangeTexture;
    loadTexture("arrow_back.png", arrowBackOrangeTexture);

    sf::Texture success;
    loadTexture("Success1.png", success);


    // Создание спрайтов
    sf::Sprite sprite_success;
    createSprite(sprite_success, success, 0.6, 0.6, sf::Vector2f(680.f, 350.f));


    // СОЗДАНИЕ ТЕКСТОВЫХ ПОЛЕЙ
    std::vector<TextData> textFields;
    std::vector<TextData> textFields1;    // для пометки прямоугольников

    for (int i = 0; i < 7; ++i)
    {
        TextData textField;
        textFields.push_back(textField);
    }

    for (int i = 0; i < 7; ++i)
    {
        TextData textField;
        textFields1.push_back(textField);
    }

    std::wstring textLabels[] =
    {
        L"Логин", L"Пароль", L"Фамилия", L"Имя",
        L"Отчество", L"Путь файла", L"Должность"
    };

    std::vector<sf::Vector2f> spritePositions =
    {
    sf::Vector2f(200.f, 210.f),    // Позиция для sprite_surName
    sf::Vector2f(200.f, 400.f),    // Позиция для sprite_name
    sf::Vector2f(200.f, 590.f),    // Позиция для sprite_patronymic
    sf::Vector2f(600.f, 780.f),    // Позиция для sprite_gender
    sf::Vector2f(1000.f, 210.f),    // Позиция для sprite_date_of_birth
    sf::Vector2f(1000.f, 400.f),    // Позиция для sprite_department_name
    sf::Vector2f(1000.f, 590.f),    // Позиция для sprite_post
    };

    std::vector<sf::Vector2f> textPositions1 =
    {
    sf::Vector2f(450.f, 164.f),
    sf::Vector2f(450.f, 360.f),
    sf::Vector2f(420.f, 550.f),
    sf::Vector2f(880.f, 740.f),
    sf::Vector2f(1222.f, 164.f),
    sf::Vector2f(1200.f, 360.f),
    sf::Vector2f(1220.f, 550.f),
    };

    std::vector<sf::Vector2f> textPositions =
    {
    sf::Vector2f(270.f, 256.f),    // Позиция для Логина
    sf::Vector2f(270.f, 446.f),    // Позиция для Паролья
    sf::Vector2f(270.f, 636.f),    // Позиция для Фамилии
    sf::Vector2f(670.f, 826.f),    // Позиция для Имя
    sf::Vector2f(1070.f, 256.f),    // Позиция для Отчетсво
    sf::Vector2f(1070.f, 446.f),    // Позиция для Путь к файлу
    sf::Vector2f(1070.f, 636.f),    // Позиция для должности
    };

    // Инициализация текста
    for (int i = 0; i < textFields.size(); ++i)
        createText(textFields[i].text, "", font2, 42, sf::Color::Black, textPositions.at(i));
    for (int i = 0; i < textFields1.size(); ++i)
        createText(textFields1[i].text, textLabels[i], font2, 42, sf::Color::White, textPositions1.at(i));


    // СОЗДАНИЕ СПРАЙТОВ
    std::vector<sf::Sprite> sprites =
    {
        sf::Sprite(), // Логин
        sf::Sprite(), // Пароль
        sf::Sprite(), // Фамилия
        sf::Sprite(), // Имя
        sf::Sprite(), // Отчество
        sf::Sprite(), // Адрес фото
        sf::Sprite() // Должность
    };

    for (int i = 0; i < sprites.size(); ++i)
        createSprite(sprites[i], rectangleTexture, 0.5, 0.5, spritePositions.at(i));

    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrowBackWhiteTexture, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrowBackOrangeTexture, 0.2, 0.2, sf::Vector2f(50, 950));


    bool isMouseOnArrow = false;
    bool isRectangleClicked1 = false;
    bool isRectangleClicked2 = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;

            }

            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                // Обработка нажатия кнопки "Добавить"
                if (handleButton(button_add, event, window))
                {
                    writeNewPersonalEmployee(authentication, textFields[0].str, textFields[1].str, textFields[2].str, textFields[3].str,
                        textFields[4].str, textFields[5].str, textFields[6].str);

                    if (successOfAdding_menu() == 1)
                        return;
                }
            }


            // ОБРАБОТКА НАЖАТИЯ НА ПОЛЯ
            for (int i = 0; i < 7; i++)
            {
                if (sprites.at(i).getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // Если спрайт был нажат
                    for (auto& s : textFields)
                    {
                        // Выключаем все спрайты
                        s.isClicked = false;
                    }
                    // Включаем только текущий спрайт
                    textFields.at(i).isClicked = true;
                }
            }

            // ОБРАБОТКА ТЕКСТОВЫХ ПОЛЕЙ
            for (auto& textField : textFields)
                handleTextField(textField, event, window);


            // ПОДСВЕТКА КНОПОК
            highlightButton(button_add, window);
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

        for (const auto& sprite : sprites)
            window.draw(sprite);

        for (const auto& textField : textFields)
            window.draw(textField.text);

        for (const auto& textField : textFields1)
            window.draw(textField.text);

        window.draw(text_add);
        window.draw(button_add);

        window.display();
    }
}
void printExperience_menu(std::vector<Employee>& employee)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    float scrollPosition = 0.0f;
    float y = 0.0f;

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
        y = printAllEmployeesExperience(employee, scrollPosition);
        window.display();
    }
}
float printAllEmployeesExperience(std::vector<Employee>& employee, float scrollPosition)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_listOfEmployees(L"Стаж сотрудников", font2);
    createText(text_listOfEmployees, 64, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text employee1(L"", font2);
    createText(employee1, 30, sf::Color::White, sf::Vector2f(30, 30));


    float x = 100.0;
    float y = 120.0f;
    std::string currentEmployee;

    for (int i = 0; i < employee.size(); i++)
    {
        employee1.setPosition(x, y);
        getExperienceOfEmployees(employee);

        currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(i).surName + " " + employee.at(i).name + " " + employee.at(i).patronymic + "\t\t\t\t\t" +
            std::to_string(employee.at(i).experience.years) + " years, " + std::to_string(employee.at(i).experience.months) + " months, " + std::to_string(employee.at(i).experience.days) + " days";
        employee1.setString(currentEmployee);

        // Проверяем, виден ли текст на экране
        if (y + scrollPosition >= 0 and y + scrollPosition < window.getSize().y)
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


// ПОИСК

// по фамилии
void searchEmployeeWithSurname_menu(std::vector<Employee>& employee) 
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_enterSurname(L"Введите фамилию сотрудника", font2);
    createText(text_enterSurname, 48, sf::Color::White, sf::Vector2f(560.f, 50.f));

    sf::Text text_search(L"Поиск", font2);
    createText(text_search, 48, sf::Color::White, sf::Vector2f(1700.f, 970.f));

    sf::Text text_empty(L"Введите хотя бы один символ", font2);
    createText(text_empty, 30, sf::Color::Red, sf::Vector2f(692.f, 574.f));

    sf::Text text_newInfo("", font2);
    createText(text_newInfo, 48, sf::Color::Black, sf::Vector2f(638.f, 450.f));


    // Создание текстур
    sf::Texture rectangle;
    loadTexture("rectangle.png", rectangle);

    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);

    
    // Создание спрайтов
    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_rectangle;
    createSprite(sprite_rectangle, rectangle, 0.6, 0.6, sf::Vector2f(570, 400));

    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));


    bool isMouseOnArrow = false;
    bool isRectangleClicked = false;
    bool isSurnameChanging = false;
    bool isTextEmpty = true;
    bool isButtonClicked = false;
    std::string str_surName;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;


                if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isButtonClicked = true;
                if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isTextEmpty)
                    printSearchingEmployeesWithSurname(employee, str_surName, isSurnameChanging);


                // проверка на поле для ввода
                if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isRectangleClicked = true;
            }
            else if (event.type == sf::Event::KeyPressed and event.mouseButton.button == sf::Keyboard::Enter)
                printSearchingEmployeesWithSurname(employee, str_surName, isSurnameChanging);

            // ввод текста в поле НОВАЯ ИНФА
            if (event.type == sf::Event::TextEntered and event.text.unicode < 128)
            {
                if (event.text.unicode == 8 and isRectangleClicked)
                { // Backspace
                    if (!str_surName.empty())
                        str_surName.pop_back();
                }
                else if (text_newInfo.getString().getSize() < 15 and isRectangleClicked)
                    str_surName += static_cast<char>(event.text.unicode);

                text_newInfo.setString(str_surName);

                if (str_surName.empty())
                    isTextEmpty = true;
                else
                    isTextEmpty = false;

                isSurnameChanging = false;
            }


            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            highlightButton(text_search, window);
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_searchEmployees(L"Найденные сотрудники", font2);
    createText(text_searchEmployees, 46, sf::Color::White, sf::Vector2f(670.f, 30.f));

    sf::Text text_currentEmployeeNo(L"Сотрудников с такой фамилией не найдено!", font2);
    createText(text_currentEmployeeNo, 46, sf::Color::White, sf::Vector2f(420.f, 500.f));


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
    std::vector<int> indexes;
    indexes.reserve(10);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_currentEmployee("", font2);
    createText(text_currentEmployee, 30, sf::Color::White, sf::Vector2f(0, 0));


    std::string str_currentEmployee;
    float x = 100.0;
    float y = 120.0f;
    int count = 0;

    for (int i = 0; i < indexes.size(); i++)
    {
        std::string post;
        if (employee.at(indexes.at(i)).post == Post::JUNIOR)
            post = "Junior";
        else if (employee.at(indexes.at(i)).post == Post::MIDDLE)
            post = "Middle";
        else if (employee.at(indexes.at(i)).post == Post::SENIOR)
            post = "Senior";
        else if (employee.at(indexes.at(i)).post == Post::TEAM_LEADER)
            post = "Team leader";
        else if (employee.at(indexes.at(i)).post == Post::PROJECT_MANAGER)
            post = "Project manager";
        else if (employee.at(indexes.at(i)).post == Post::DIRECTOR_OF_DEPARTMENT)
            post = "Director of department";
        else if (employee.at(indexes.at(i)).post == Post::DEPUTY_GENERAL_DIRECTOR)
            post = "Deputy general director";
        else if (employee.at(indexes.at(i)).post == Post::GENERAL_DIRECTOR)
            post = "General director";

        text_currentEmployee.setPosition(x, y);
        str_currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(indexes.at(i)).surName + " " + employee.at(indexes.at(i)).name + " " +
            employee.at(indexes.at(i)).patronymic + " " + employee.at(indexes.at(i)).gender + " " + employee.at(indexes.at(i)).dateOfBirthday
            + " " + employee.at(indexes.at(i)).departmentName + " " + post + " " + employee.at(indexes.at(i)).startDate;

        text_currentEmployee.setString(str_currentEmployee);

        y += 50;
        count++;
        window.draw(text_currentEmployee);
    }
}

// по должности
void searchEmployeeWithPost_menu(std::vector<Employee>& employee)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_enterPost(L"Введите должность сотрудника", font2);
    createText(text_enterPost, 48, sf::Color::White, sf::Vector2f(560.f, 50.f));

    sf::Text text_search(L"Поиск", font2);
    createText(text_search, 48, sf::Color::White, sf::Vector2f(1700.f, 970.f));

    sf::Text text_empty(L"Введите хотя бы один символ", font2);
    createText(text_empty, 30, sf::Color::Red, sf::Vector2f(692.f, 574.f));

    sf::Text text_newInfo("", font2);
    createText(text_newInfo, 48, sf::Color::Black, sf::Vector2f(638.f, 450.f));


    // Создание текстур
    sf::Texture rectangle;
    loadTexture("rectangle.png", rectangle);

    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);


    // Создание спрайтов
    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_rectangle;
    createSprite(sprite_rectangle, rectangle, 0.6, 0.6, sf::Vector2f(570, 400));

    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));


    bool isMouseOnArrow = false;
    bool isRectangleClicked = false;
    bool isPostChanging = false;
    bool isTextEmpty = true;
    bool isButtonClicked = false;
    std::string str_post;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;


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



            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            highlightButton(text_search, window);


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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    sf::Text text_searchEmployees(L"Найденные сотрудники", font2);
    createText(text_searchEmployees, 46, sf::Color::White, sf::Vector2f(670.f, 30.f));

    sf::Text text_currentEmployeeNo(L"Сотрудников с такой должностью не найдено!", font2);
    createText(text_currentEmployeeNo, 46, sf::Color::White, sf::Vector2f(420.f, 500.f));


    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);


    // Создание спрайтов
    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));


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
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_currentEmployee("", font2);
    createText(text_currentEmployee, 30, sf::Color::White, sf::Vector2f(0, 0));


    std::string str_currentEmployee;
    float x = 100.0;
    float y = 120.0f;
    int count = 0;

    for (int i = 0; i < indexes.size(); i++)
    {
        std::string post;
        if (employee.at(indexes.at(i)).post == Post::JUNIOR)
            post = "Junior";
        else if (employee.at(indexes.at(i)).post == Post::MIDDLE)
            post = "Middle";
        else if (employee.at(indexes.at(i)).post == Post::SENIOR)
            post = "Senior";
        else if (employee.at(indexes.at(i)).post == Post::TEAM_LEADER)
            post = "Team leader";
        else if (employee.at(indexes.at(i)).post == Post::PROJECT_MANAGER)
            post = "Project manager";
        else if (employee.at(indexes.at(i)).post == Post::DIRECTOR_OF_DEPARTMENT)
            post = "Director of department";
        else if (employee.at(indexes.at(i)).post == Post::DEPUTY_GENERAL_DIRECTOR)
            post = "Deputy general director";
        else if (employee.at(indexes.at(i)).post == Post::GENERAL_DIRECTOR)
            post = "General director";

        text_currentEmployee.setPosition(x, y);
        str_currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(indexes.at(i)).surName + " " + employee.at(indexes.at(i)).name + " " +
            employee.at(indexes.at(i)).patronymic + " " + employee.at(indexes.at(i)).gender + " " + employee.at(indexes.at(i)).dateOfBirthday
            + " " + employee.at(indexes.at(i)).departmentName + " " + post + " " + employee.at(indexes.at(i)).startDate;
        text_currentEmployee.setString(str_currentEmployee);

        y += 50;
        count++;
        window.draw(text_currentEmployee);
    }
}

// по дате начала работы
void searchEmployeeWithStartYear_menu(std::vector<Employee>& employee)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_enterYear(L"Введите год начала работы сотрудника", font2);
    createText(text_enterYear, 48, sf::Color::White, sf::Vector2f(470.f, 50.f));

    sf::Text text_search(L"Поиск", font2);
    createText(text_search, 48, sf::Color::White, sf::Vector2f(1700.f, 970.f));

    sf::Text text_empty(L"Введите хотя бы один символ", font2);
    createText(text_empty, 30, sf::Color::Red, sf::Vector2f(692.f, 574.f));

    sf::Text text_newInfo("", font2);
    createText(text_newInfo, 48, sf::Color::Black, sf::Vector2f(638.f, 450.f));


    // Создание текстур
    sf::Texture rectangle;
    loadTexture("rectangle.png", rectangle);

    sf::Texture arrow_back_white;
    loadTexture("arrow_back_white.png", arrow_back_white);

    sf::Texture arrow_back_orange;
    loadTexture("arrow_back.png", arrow_back_orange);


    // Создание спрайтов
    sf::Sprite sprite_arrow_back_orange;
    createSprite(sprite_arrow_back_orange, arrow_back_orange, 0.2, 0.2, sf::Vector2f(50, 950));

    sf::Sprite sprite_rectangle;
    createSprite(sprite_rectangle, rectangle, 0.6, 0.6, sf::Vector2f(570, 400));

    sf::Sprite sprite_arrow_back_white;
    createSprite(sprite_arrow_back_white, arrow_back_white, 0.2, 0.2, sf::Vector2f(50, 950));


    bool isMouseOnArrow = false;
    bool isRectangleClicked = false;
    bool isYearChanging = false;
    bool isTextEmpty = true;
    bool isButtonClicked = false;
    std::string str_year;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;

                if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isButtonClicked = true;
                if (text_search.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isTextEmpty)
                    printSearchingEmployeesWithYear(employee, str_year, isYearChanging);
            }
            else if (event.type == sf::Event::KeyPressed and event.mouseButton.button == sf::Keyboard::Enter)
                printSearchingEmployeesWithYear(employee, str_year, isYearChanging);


            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    isRectangleClicked = true;
            }


            // ввод текста в поле НОВАЯ ИНФО
            if (event.type == sf::Event::TextEntered and event.text.unicode < 128)
            {
                if (event.text.unicode == 8 and isRectangleClicked)
                { // Backspace
                    if (!str_year.empty())
                        str_year.pop_back();
                }
                else if (text_newInfo.getString().getSize() < 15 and isRectangleClicked)
                    str_year += static_cast<char>(event.text.unicode);

                text_newInfo.setString(str_year);

                if (str_year.empty())
                    isTextEmpty = true;
                else
                    isTextEmpty = false;

                isYearChanging = false;
            }


            // подсвечивание
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite_arrow_back_white.getGlobalBounds().contains(mousePos.x, mousePos.y))
                isMouseOnArrow = true;
            else
                isMouseOnArrow = false;

            highlightButton(text_search, window);
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_searchEmployees(L"Найденные сотрудники", font2);
    createText(text_searchEmployees, 46, sf::Color::White, sf::Vector2f(670.f, 30.f));

    sf::Text text_currentEmployeeNo(L"Сотрудников с такой датой не найдено!", font2);
    createText(text_currentEmployeeNo, 46, sf::Color::White, sf::Vector2f(420.f, 500.f));


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
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (sprite_arrow_back_orange.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return;
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
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_currentEmployee("", font2);
    createText(text_currentEmployee, 30, sf::Color::White, sf::Vector2f(670.f, 30.f));


    std::string str_currentEmployee;
    float x = 100.0;
    float y = 120.0f;
    int count = 0;

    for (int i = 0; i < indexes.size(); i++)
    {
        std::string post;
        if (employee.at(indexes.at(i)).post == Post::JUNIOR)
            post = "Junior";
        else if (employee.at(indexes.at(i)).post == Post::MIDDLE)
            post = "Middle";
        else if (employee.at(indexes.at(i)).post == Post::SENIOR)
            post = "Senior";
        else if (employee.at(indexes.at(i)).post == Post::TEAM_LEADER)
            post = "Team leader";
        else if (employee.at(indexes.at(i)).post == Post::PROJECT_MANAGER)
            post = "Project manager";
        else if (employee.at(indexes.at(i)).post == Post::DIRECTOR_OF_DEPARTMENT)
            post = "Director of department";
        else if (employee.at(indexes.at(i)).post == Post::DEPUTY_GENERAL_DIRECTOR)
            post = "Deputy general director";
        else if (employee.at(indexes.at(i)).post == Post::GENERAL_DIRECTOR)
            post = "General director";

        text_currentEmployee.setPosition(x, y);
        str_currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(indexes.at(i)).surName + " " + employee.at(indexes.at(i)).name + " " +
            employee.at(indexes.at(i)).patronymic + " " + employee.at(indexes.at(i)).gender + " " + employee.at(indexes.at(i)).dateOfBirthday
            + " " + employee.at(indexes.at(i)).departmentName + " " + post + " " + employee.at(indexes.at(i)).startDate;
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
    sf::RectangleShape yes(sf::Vector2f(240.f, 90.f));
    createRectangle(yes, sf::Vector2f(535.f, 100.f), sf::Vector2f(680.f, 596.f), sf::Color(59, 60, 54, 190));


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
    sf::RectangleShape yes(sf::Vector2f(240.f, 90.f));
    createRectangle(yes, sf::Vector2f(535.f, 100.f), sf::Vector2f(680.f, 596.f), sf::Color(59, 60, 54, 190));


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
    sf::RectangleShape yes(sf::Vector2f(240.f, 90.f));
    createRectangle(yes, sf::Vector2f(535.f, 100.f), sf::Vector2f(680.f, 596.f), sf::Color(59, 60, 54, 190));


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
int areYouSure()
{
    sf::Texture success;
    loadTexture("AreYouSure1.png", success);


    // Создание спрайтов
    sf::Sprite sprite_success;
    createSprite(sprite_success, success, 0.6, 0.6, sf::Vector2f(680.f, 350.f));

    // Создание прямоугольников
    sf::RectangleShape yes(sf::Vector2f(240.f, 90.f));
    createRectangle(yes, sf::Vector2f(267.f, 100.f), sf::Vector2f(680.f, 596.f), sf::Color(59, 60, 54, 190));

    sf::RectangleShape no(sf::Vector2f(240.f, 90.f));
    createRectangle(no, sf::Vector2f(267.f, 100.f), sf::Vector2f(947.f, 596.f), sf::Color(59, 60, 54, 190));

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
                else if (no.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 0;
            }
        }

        window.draw(sprite_success);
        window.display();
    }
}


// ПОИСК СОСТРУДНИКОВ ПЕНСИОННОГО ВОЗРАСТА
void employeesOfRetirementAge_menu(std::vector<Employee> &employee)
{
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
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                return;

        }

        window.clear(sf::Color::Black);
        y = printEmployeesOfRetirementAge(employee);
        window.display();
    }
}
float printEmployeesOfRetirementAge(std::vector<Employee>& employee)
{
    // Загрузка шрифтов
    sf::Font font2;
    loadFont(font2, "shrift.ttf");


    // Создание текстов
    sf::Text text_listOfEmployees(L"Список сотрудников пенсионного возраста", font2);
    createText(text_listOfEmployees, 64, sf::Color::White, sf::Vector2f(0, 0));

    sf::Text employee1(L"", font2);
    createText(employee1, 30, sf::Color::White, sf::Vector2f(30, 30));


    std::vector<int> indexes = searchForEmployeesOfRetirementAge(employee);
    float x = 120.0;
    float y = 120.0f;
    std::string currentEmployee;

    for (int i = 0; i < indexes.size(); i++)
    {
        employee1.setPosition(x, y);

        std::string post;
        if (employee.at(indexes.at(i)).post == Post::JUNIOR)
            post = "Junior";
        else if (employee.at(indexes.at(i)).post == Post::MIDDLE)
            post = "Middle";
        else if (employee.at(indexes.at(i)).post == Post::SENIOR)
            post = "Senior";
        else if (employee.at(indexes.at(i)).post == Post::TEAM_LEADER)
            post = "Team leader";
        else if (employee.at(indexes.at(i)).post == Post::PROJECT_MANAGER)
            post = "Project manager";
        else if (employee.at(indexes.at(i)).post == Post::DIRECTOR_OF_DEPARTMENT)
            post = "Director of department";
        else if (employee.at(indexes.at(i)).post == Post::DEPUTY_GENERAL_DIRECTOR)
            post = "Deputy general director";
        else if (employee.at(indexes.at(i)).post == Post::GENERAL_DIRECTOR)
            post = "General director";

        currentEmployee = std::to_string(i + 1) + ((i < 9) ? ".   " : ".  ") + employee.at(indexes.at(i)).surName + " " + employee.at(indexes.at(i)).name + " " + 
            employee.at(indexes.at(i)).patronymic + " " + employee.at(indexes.at(i)).gender + " " + employee.at(indexes.at(i)).dateOfBirthday
            + " " + employee.at(indexes.at(i)).departmentName + " " + post + " " + employee.at(indexes.at(i)).startDate;
        employee1.setString(currentEmployee);


        employee1.setPosition(x, y);
        text_listOfEmployees.setPosition(170.f, 10.f);
        window.draw(text_listOfEmployees);
        window.draw(employee1);


        // Обновляем позицию для следующего текста
        y += 50;
    }

    return y;   // Возвращаем текущую позицию, которая будет использоваться в следующем вызове
}