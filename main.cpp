#include <SFML/Graphics.hpp>
#include <Windows.h>

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
    sf::RenderWindow window(sf::VideoMode(500, 340), "Authentication");
    
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

    rectangle1.move(35, 70);
    rectangle2.move(35, 160);
    rectangle3.move(275, 260);
    // ������������� ��� ����
    rectangle1.setFillColor(Color(175, 180, 240));
    rectangle2.setFillColor(Color(175, 180, 240));
    rectangle3.setFillColor(Color(175, 180, 240));

    sf::Text text(L"�����������", font);
    text.setCharacterSize(44); // ��������� ������� ������
    text.setFillColor(sf::Color::Black); // ��������� ����� ������
    // ��������� ���������� ��������� ������
    text.setPosition(150.f, 15.f); // ����� ���������� (x, y)


    sf::Text login(L"�����", font);
    login.setCharacterSize(36); // ��������� ������� ������
    login.setFillColor(sf::Color::Black); // ��������� ����� ������
    login.setPosition(330.f, 263.f); // ����� ���������� (x, y)



    // �������� ����������� � ��������
    sf::Texture texture1;
    if (!texture1.loadFromFile("user.png")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }

    // �������� ����������� � ��������
    sf::Texture texture2;
    if (!texture2.loadFromFile("password.png")) {
        // ��������� ������ �������� �����������
        return EXIT_FAILURE;
    }

    // �������� ������� � ��������� ��������
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);

    sprite1.setScale(1.f / 9.f, 1.f / 9.f);
    sprite2.setScale(1.f / 9.f, 1.f / 9.f);

    // ��������� ���������� ��������� �������
    sprite1.setPosition(40.f, 77.f); // ����� ���������� (x, y)
    sprite2.setPosition(40.f, 167.f); // ����� ���������� (x, y)



    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            // ��������� ������� ���� �� 1920x1080
            window.setSize(sf::Vector2u(1920, 1080));
            // ������������� ���� ����� ��������� �������
            window.setPosition(sf::Vector2i((desktop.width - window.getSize().x) / 2, (desktop.height - window.getSize().y) / 2));
        }  */

        window.clear(sf::Color::White);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(text);
        window.draw(login);
        window.draw(sprite1);
        window.draw(sprite2);
        window.display();
    }

    return 0;
}