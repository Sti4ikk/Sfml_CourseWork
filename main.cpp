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
    sf::RenderWindow window(sf::VideoMode(500, 340), "Authentication",  sf::Style::Close);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.jpg")) 
    {
        // ��������� ������ �������� �����������
        return 1;
    }
    // �������� ������� ��� ����
    sf::Sprite backgroundSprite(backgroundTexture);
    
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
    sf::RectangleShape rectangle3(Vector2f(190.f, 55.f));

    rectangle1.move(35, 80);
    rectangle2.move(35, 170);
    rectangle3.move(275, 260);
    // ������������� ��� ����
    rectangle1.setFillColor(Color(254, 128, 181));
    rectangle2.setFillColor(Color(254, 128, 181));
    rectangle3.setFillColor(Color(10, 161, 255));

    sf::Text text(L"�����������", font);
    text.setCharacterSize(52); // ��������� ������� ������
    text.setFillColor(sf::Color::Black); // ��������� ����� ������
    // ��������� ���������� ��������� ������
    text.setPosition(140.f, 8.f); // ����� ���������� (x, y)


    sf::Text entrance(L"�����", font);
    entrance.setCharacterSize(36); // ��������� ������� ������
    entrance.setFillColor(sf::Color::Black); // ��������� ����� ������
    entrance.setPosition(330.f, 265.f); // ����� ���������� (x, y)



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


    // �������� ������� � ��������� ��������
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);
    sf::Sprite sprite3(texture3);
    sf::Sprite sprite4(texture4);

    sprite1.setScale(1.f / 9.f, 1.f / 9.f);
    sprite2.setScale(1.f / 12.f, 1.f / 12.f);
    sprite3.setScale(1.f / 12.f, 1.f / 12.f);
    sprite4.setScale(1.f / 12.f, 1.f / 12.f);

    // ��������� ���������� ��������� �������
    sprite1.setPosition(40.f, 87.f);
    sprite2.setPosition(40.f, 177.f);
    sprite3.setPosition(417.f, 185.f);
    sprite4.setPosition(417.f, 185.f);

    sf::Text login("", font);
    login.setCharacterSize(38); // ��������� ������� ������
    login.setFillColor(sf::Color::Black); // ��������� ����� ������
    login.setPosition(110.f, 93.f); // ����� ���������� (x, y)

    sf::Text password1("", font);
    password1.setCharacterSize(38); // ��������� ������� ������
    password1.setFillColor(sf::Color::Black); // ��������� ����� ������
    password1.setPosition(110.f, 183.f); // ����� ���������� (x, y)

    sf::Text password2("", font);
    password2.setCharacterSize(72); // ��������� ������� ������
    password2.setFillColor(sf::Color::Black); // ��������� ����� ������
    password2.setPosition(110.f, 183.f); // ����� ���������� (x, y)

    // ��������, ����� ���� ������ ��� �����
    bool isRectangle1Clicked = false;
    bool isRectangle2Clicked = false;
    bool isPasswordOpen = false;
    bool isTextPasswordOpen = false;

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

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            // ��������� ������� ���� �� 1920x1080
            window.setSize(sf::Vector2u(1920, 1080));
            // ������������� ���� ����� ��������� �������
            window.setPosition(sf::Vector2i((desktop.width - window.getSize().x) / 2, (desktop.height - window.getSize().y) / 2));
        }  */

        window.clear();
        window.draw(backgroundSprite);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(text);
        window.draw(entrance);
        window.draw(login);
        if (isTextPasswordOpen) window.draw(password1);
        else window.draw(password2);
        window.draw(sprite1);
        window.draw(sprite2);
        if (isPasswordOpen)  window.draw(sprite4);
        else  window.draw(sprite3);
        window.display();
    }

    return 0;
}