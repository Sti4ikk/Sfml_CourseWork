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
        // ��������� ������ �������� ������
        return EXIT_FAILURE;
    }

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(500, 412), "", sf::Style::None);

    
    // �������� ����������� ��� ������ ����
    sf::Image icon;
    if (!icon.loadFromFile("icon.jpg")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // ������� ������������� �������� 70�100
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
    // ������������� ��� ����
    rectangle1.setFillColor(Color::Black);
    rectangle2.setFillColor(Color::Black);
    rectangle3.setFillColor(Color(255, 193, 7));
    square.setFillColor(Color(59, 60, 54));
    line1.setFillColor(Color(59, 60, 54));
    line2.setFillColor(Color(59, 60, 54));

    rectangle1.setOutlineThickness(1.f); // ������� �������
    rectangle2.setOutlineThickness(1.f); // ������� �������
    rectangle1.setOutlineColor(sf::Color(59, 60, 54)); // ���� �������
    rectangle2.setOutlineColor(sf::Color(59, 60, 54)); // ���� �������

    sf::Text text(L"�����������", font);
    text.setCharacterSize(46); // ��������� ������� ������
    text.setFillColor(sf::Color::White); // ��������� ����� ������
    // ��������� ���������� ��������� ������
    text.setPosition(88.f, 8.f); // ����� ���������� (x, y)


    sf::Text entrance(L"�����", font);
    entrance.setCharacterSize(30); // ��������� ������� ������
    entrance.setFillColor(sf::Color::White); // ��������� ����� ������
    entrance.setPosition(188.f, 272.f); // ����� ���������� (x, y)

    sf::Text rememberMe(L"��������� ����", font);
    rememberMe.setCharacterSize(14); // ��������� ������� ������
    rememberMe.setFillColor(sf::Color(59, 60, 54)); // ��������� ����� ������
    rememberMe.setPosition(81.f, 344.f); // ����� ���������� (x, y)



    // �������� ����������� � ��������
    sf::Texture texture1;
    if (!texture1.loadFromFile("user.png")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }
    // �������� ����������� � ��������
    sf::Texture texture2;
    if (!texture2.loadFromFile("password1.png")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }
    // �������� ����������� � ��������
    sf::Texture texture3;
    if (!texture3.loadFromFile("hide_eye.png")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }
    sf::Texture texture4;
    if (!texture4.loadFromFile("open_eye.png")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }
    sf::Texture galka;
    if (!galka.loadFromFile("galka.png")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }
    sf::Texture krest;
    if (!krest.loadFromFile("krest.png")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }


    // �������� ������� � ��������� ��������
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

    // ��������� ���������� ��������� �������
    sprite1.setPosition(42.f, 92.f);
    sprite2.setPosition(43.f, 172.f);
    sprite3.setPosition(416.f, 175.f);
    sprite4.setPosition(416.f, 175.f);
    sprite_galka.setPosition(44.f, 339.f);
    sprite_krest.setPosition(478.f, 6.f);
 
    sf::Text login("", font);
    login.setCharacterSize(28); // ��������� ������� ������
    login.setFillColor(sf::Color::White); // ��������� ����� ������
    login.setPosition(110.f, 98.f); // ����� ���������� (x, y)

    sf::Text password1("", font);
    password1.setCharacterSize(28); // ��������� ������� ������
    password1.setFillColor(sf::Color::White); // ��������� ����� ������
    password1.setPosition(110.f, 178.f); // ����� ���������� (x, y)

    sf::Text password2("", font);
    password2.setCharacterSize(44); // ��������� ������� ������
    password2.setFillColor(sf::Color::White); // ��������� ����� ������
    password2.setPosition(110.f, 178.f); // ����� ���������� (x, y)

    // ��������, ����� ���� ������ ��� �����
    bool isRectangle1Clicked = false;
    bool isRectangle2Clicked = false;
    bool isPasswordOpen = false;
    bool isTextPasswordOpen = false;
    bool isRememberMeOn = false;
    // ��� ����������� ����
    bool isDragging = false;
    sf::Vector2i clickPosition;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // �������� ����������
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_krest.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        window.close();
                }
            }
            // ��� �������� �� ������ �����
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();


            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // ���������� �������, � ������� ���� ������ ������ ����
                isDragging = true;
                clickPosition = sf::Mouse::getPosition(window);
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                // ����� ������ ���� ��������, ����������� ��������������
                isDragging = false;
            }
            // �������� �� ���� ��� �����
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
            // �������� �� �������
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (square.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isRememberMeOn)
                    {
                        isRememberMeOn = true;
                    }
                    else if (square.getGlobalBounds().contains(mousePos.x, mousePos.y) and isRememberMeOn)
                    {
                        isRememberMeOn = false;
                    }
                }
            }

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
            // �������� ������
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (login.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        login.setString("");
                    }
                    if (password2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        password2.setString("");
                        password1.setString("");
                    }
                }
            }
            // �������� �� ������� ������ ��������� ������
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


        }

        if (isDragging)
        {
            // ��������� ������� ����� ������� �������� ���� � ��������, ��� ���� ������ ������ ����
            sf::Vector2i delta = sf::Mouse::getPosition(window) - clickPosition;
            // �������� ������� ��������� ���� � �������� ��� �� delta
            window.setPosition(sf::Vector2i(window.getPosition()) + delta);
            // ��������� ������� clickPosition
            clickPosition = sf::Mouse::getPosition(window);
        }

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            // ��������� ������� ���� �� 1920x1080
            window.setSize(sf::Vector2u(1920, 1080));
            // ������������� ���� ����� ��������� �������
            window.setPosition(sf::Vector2i((desktop.width - window.getSize().x) / 2, (desktop.height - window.getSize().y) / 2));
        }  */

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
        window.display();
    }

    return 0;
}