#include <iostream>
#include <SFML/Graphics.hpp>


// ������� ��� �������� �������� �� �����
bool loadTexture(const std::string& filePath, sf::Texture& texture) 
{
    if (!texture.loadFromFile(filePath)) 
    {
        // ���� �������� �� �������, ������� ��������� �� ������
        std::cerr << "Failed to load texture: " << filePath << std::endl;
        return false;
    }
    return true;
}


// ������� ��� �������� ������� � �������� ���������
void createSprite(sf::Sprite& sprite, const sf::Texture& texture, const float x, const float y, const sf::Vector2f& position)
{
    sprite.setTexture(texture);
    sprite.setScale(x, y);
    sprite.setPosition(position);
}

// ������� ��� �������� ������ � ��������� �����������
void createText(sf::Text& text, unsigned int characterSize, const sf::Color& color, const sf::Vector2f& position)
{
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    text.setPosition(position);
}

void createRectangle(sf::RectangleShape &rectangle, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const float outlineThickness = 0, const sf::Color outlineColor = sf::Color::Black)
{
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    rectangle.setOutlineThickness(outlineThickness);
    rectangle.setOutlineColor(outlineColor);
}

// ������� ��� �������� ������ �� �����
bool loadFont(sf::Font& font, const std::string& filePath)
{
    if (!font.loadFromFile(filePath)) {
        // ���� �������� �� �������, ������� ��������� �� ������
        std::cerr << "Failed to load font: " << filePath << std::endl;
        return false;
    }
    return true;
}