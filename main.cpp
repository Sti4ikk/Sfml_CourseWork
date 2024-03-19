#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>

using namespace sf;

int main()
{
    system("color F");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    sf::Font font;
    if (!font.loadFromFile("shrift.ttf")) {
        // Обработка ошибки загрузки шрифта
        return EXIT_FAILURE;
    }

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(500, 340), "Authentication");
    
    // Загрузка изображения для иконки окна
    sf::Image icon;
    if (!icon.loadFromFile("icon.jpg")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Создаем прямоугольник размером 70х100
    sf::RectangleShape rectangle1(Vector2f(430.f, 70.f));
    sf::RectangleShape rectangle2(Vector2f(430.f, 70.f));
    sf::RectangleShape rectangle3(Vector2f(190.f, 55.f));

    rectangle1.move(35, 70);
    rectangle2.move(35, 160);
    rectangle3.move(275, 260);
    // Устанавливаем ему цвет
    rectangle1.setFillColor(Color(175, 180, 240));
    rectangle2.setFillColor(Color(175, 180, 240));
    rectangle3.setFillColor(Color(175, 180, 240));

    sf::Text text(L"АВТОРИЗАЦИЯ", font);
    text.setCharacterSize(48); // Установка размера шрифта
    text.setFillColor(sf::Color::Black); // Установка цвета текста
    // Установка начального положения текста
    text.setPosition(145.f, 8.f); // Новые координаты (x, y)


    sf::Text entrance(L"ВОЙТИ", font);
    entrance.setCharacterSize(36); // Установка размера шрифта
    entrance.setFillColor(sf::Color::Black); // Установка цвета текста
    entrance.setPosition(330.f, 263.f); // Новые координаты (x, y)



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

    // Создание спрайта и установка текстуры
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);

    sprite1.setScale(1.f / 9.f, 1.f / 9.f);
    sprite2.setScale(1.f / 9.f, 1.f / 9.f);

    // Установка начального положения спрайта
    sprite1.setPosition(400.f, 77.f); // Новые координаты (x, y)
    sprite2.setPosition(400.f, 167.f); // Новые координаты (x, y)

    sf::Text login("", font);
    login.setCharacterSize(42); // Установка размера шрифта
    login.setFillColor(sf::Color::Black); // Установка цвета текста
    login.setPosition(90.f, 80.f); // Новые координаты (x, y)

    sf::Text password("", font);
    password.setCharacterSize(42); // Установка размера шрифта
    password.setFillColor(sf::Color::Black); // Установка цвета текста
    password.setPosition(90.f, 170.f); // Новые координаты (x, y)

    // првоерка, какое поле выбпал для ввода
    bool isRectangle1Clicked = false;
    bool isRectangle2Clicked = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isRectangle1Clicked = true;
                        isRectangle2Clicked = false;
                    }
                    else if (rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isRectangle1Clicked = false;
                        isRectangle2Clicked = true;
                    }
                }

            }

            
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (isRectangle1Clicked && login.getString().getSize() < 12)
                    {
                        login.setString(login.getString() + static_cast<char>(event.text.unicode));
                    }
                    

                    if (isRectangle2Clicked && password.getString().getSize() < 12)
                    {
                        password.setString(password.getString() + static_cast<char>(event.text.unicode));
                    }
                }
            }


            // удаление текста
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (login.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        login.setString("");
                    }
                    if (password.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        password.setString("");
                    }
                }
            }
        }

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            // Изменение размера окна на 1920x1080
            window.setSize(sf::Vector2u(1920, 1080));
            // Центрирование окна после изменения размера
            window.setPosition(sf::Vector2i((desktop.width - window.getSize().x) / 2, (desktop.height - window.getSize().y) / 2));
        }  */

        window.clear(sf::Color::White);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        // Замена символов пароля на *
        sf::String maskedPassword;
        for (std::size_t i = 0; i < password.getSize(); ++i) {
            maskedPassword += '*';
        }
        window.draw(text);
        window.draw(entrance);
        window.draw(login);
        window.draw(password);
        window.draw(sprite1);
        window.draw(sprite2);
        window.display();
    }

    return 0;
}