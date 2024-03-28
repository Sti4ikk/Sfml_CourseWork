#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include "structs.h"
#include "enums.h"
#include "prototypes.h"
#include <SFML/System.hpp>

using namespace sf;

int auth_menu(std::vector<Authentication>& authentication, std::vector<Employee>& employee, bool &isRememberMePressed)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(500, 412), "", sf::Style::None);

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
            // ввод текста в поле логин и пароль
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (isRectangle1Clicked and login.getString().getSize() < 12)
                    {
                        login.setString(login.getString() + static_cast<char>(event.text.unicode));

                    }
                    if (isRectangle2Clicked and password1.getString().getSize() < 12)
                    {
                        password1.setString(password1.getString() + static_cast<char>(event.text.unicode));
                        password2.setString(password2.getString() + '*');
                    }
                }
            }
            // удаление текста
            if (event.type == sf::Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    if (login.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
                    {
                        login.setString("");
                    }
                    if (password2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
                    {
                        password2.setString("");
                        password1.setString("");
                    }
                }
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
                        if (login1 == "pornhub")                       // пасхалка
                            openUrl("https://rt.pornhub.com/");

                        if (checkDataOfUser(authentication, login1, password5))
                        {
                            window.close();
                            main_menu(authentication, employee, isRememberMePressed);
                        }
                        else
                        {
                            login.setString("");
                            password2.setString("");
                            password1.setString("");
                            isIncorrectData = true;
                        }
                    }

                }
            }
        }
        if (isDragging)
        {
            // Вычисляем разницу между текущей позицией мыши и позицией, где была нажата кнопка мыши
            sf::Vector2i delta = sf::Mouse::getPosition(window) - clickPosition;
            // Получаем текущее положение окна и сдвигаем его на delta
            window.setPosition(sf::Vector2i(window.getPosition()) + delta);
            // Обновляем позицию clickPosition
            clickPosition = sf::Mouse::getPosition(window);
        }

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
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "", sf::Style::None);

    sf::Font font2;
    if (!font2.loadFromFile("shrift.ttf")) {
        // Обработка ошибки загрузки шрифта
        return;
    }
    sf::Font font;
    if (!font.loadFromFile("shrift2.ttf")) {
        // Обработка ошибки загрузки шрифта
        return;
    }

   

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

    line1.move(490, 0);
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


    sf::Texture acc;
    if (!acc.loadFromFile("acc.png"))
        return;
    sf::Sprite sprite_acc(acc);
    sprite_acc.setScale(1.f / 7.f, 1.f / 7.f);
    sprite_acc.setPosition(1810, 15);

    sf::Texture shtorka;
    if (!shtorka.loadFromFile("shtorka.png"))
        return;
    sf::Sprite sprite_shtorka(shtorka);
    sprite_shtorka.setScale(0.6, 0.6);
    sprite_shtorka.setPosition(1888, 386);


    sf::Texture shtorka1;
    if (!shtorka1.loadFromFile("shtorka.png"))
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
    if (!bg_news.loadFromFile("bg_news.png"))
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
                                       

    bool isAccPressed = false;
    bool isMouseOnShtorka = false;
    bool isMouseOnShtorka1 = false;
    bool triangleIsMouseOnShtorka1 = false;
    bool triangleIsMouseOnShtorka = false;
    bool isNewsOpen = false;

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
                    if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y))
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
                text_editing.setFillColor(Color(255, 100, 7));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_editing.setFillColor(sf::Color::White);
            if (text_proccesing.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_proccesing.setFillColor(Color(255, 100, 7));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_proccesing.setFillColor(sf::Color::White);
            if (text_settings.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_settings.setFillColor(Color(255, 100, 7));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_settings.setFillColor(sf::Color::White);
            if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_exit.setFillColor(Color(255, 100, 7));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_exit.setFillColor(sf::Color::White);
            if (text_account.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_account.setFillColor(Color(255, 100, 7));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_account.setFillColor(sf::Color::White);
            if (text_leave_from_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_leave_from_acc.setFillColor(Color(255, 100, 7));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_leave_from_acc.setFillColor(sf::Color::White);

            if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                triangle1[0].color = sf::Color(255, 100, 7);
                triangle1[1].color = sf::Color(255, 100, 7);
                triangle1[2].color = sf::Color(255, 100, 7);
            }
            else
            {
                triangle1[0].color = sf::Color::White;
                triangle1[1].color = sf::Color::White;
                triangle1[2].color = sf::Color::White;
            }
            if (sprite_acc.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                triangle2[0].color = sf::Color(255, 100, 7);
                triangle2[1].color = sf::Color(255, 100, 7);
                triangle2[2].color = sf::Color(255, 100, 7);
            }
            else
            {
                triangle2[0].color = sf::Color::White;
                triangle2[1].color = sf::Color::White;
                triangle2[2].color = sf::Color::White;
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
                    if (text_leave_from_acc.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isNewsOpen)
                    {
                        isRememberMePressed = 1;
                        writeInFileIsRememberOn(isRememberMePressed);
                        window.close();
                        auth_menu(authentication, employee, isRememberMePressed);
                    }
                }
            }

                                                                          

        }

        window.clear(sf::Color::Black);
        window.draw(name);
        window.draw(sprite_acc);
        window.draw(text_editing);
        window.draw(text_proccesing);
        window.draw(text_exit);
        window.draw(text_settings);
        if (isAccPressed)
        {
            window.draw(triangle2);
            window.draw(account);
            window.draw(text_account);
            window.draw(text_leave_from_acc);
        }
        else
            window.draw(triangle1);

        if (triangleIsMouseOnShtorka)
            window.draw(triangle3);

        if (isMouseOnShtorka and !isNewsOpen)
            window.draw(sprite_shtorka_orange);
        else
            window.draw(sprite_shtorka);

        if (isNewsOpen)
        {
            window.draw(sprite_shtorka1);
            window.draw(sprite_bg_news);

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