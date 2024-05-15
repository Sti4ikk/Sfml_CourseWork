#include <iostream>
#include <SFML/Graphics.hpp>
#include "structs.h"

// Структура для текста
struct TextData
{
    sf::Text text;
    std::string str;
    bool isClicked = false;
};


// Функция для загрузки текстуры из файла
bool loadTexture(const std::string& filePath, sf::Texture& texture) 
{
    if (!texture.loadFromFile("Images/" + filePath))
    {
        // Если загрузка не удалась, выводим сообщение об ошибке
        std::cerr << "Failed to load texture: " << filePath << std::endl;
        return false;
    }
    return true;
}

// Функция для создания спрайта с заданной текстурой
void createSprite(sf::Sprite& sprite, const sf::Texture& texture, const float x, const float y, const sf::Vector2f& position)
{
    sprite.setTexture(texture);
    sprite.setScale(x, y);
    sprite.setPosition(position);
}

// Функция для создания текста с заданными параметрами
void createText(sf::Text& text, unsigned int characterSize, const sf::Color& color, const sf::Vector2f& position)
{
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    text.setPosition(position);
}

// Функция для создания прямоугольника
void createRectangle(sf::RectangleShape &rectangle, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const float outlineThickness = 0, const sf::Color outlineColor = sf::Color::Black)
{
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    rectangle.setOutlineThickness(outlineThickness);
    rectangle.setOutlineColor(outlineColor);
}

// Функция для загрузки шрифта из файла
bool loadFont(sf::Font& font, const std::string& filePath)
{
    if (!font.loadFromFile(filePath)) 
    {
        // Если загрузка не удалась, выводим сообщение об ошибке
        std::cerr << "Failed to load font: " << filePath << std::endl;
        return false;
    }
    return true;
}

// Функция для обработки текстовых полей
void handleTextField(TextData& textField, sf::Event& event, sf::RenderWindow& window) 
{
    if (textField.isClicked and event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128) 
        {
            if (event.text.unicode == 8 && textField.str.empty())
                return;

            else if (event.text.unicode == 8 && !textField.str.empty())
                // Backspace
            {
                textField.str.pop_back();
            }


            else if (textField.text.getString().getSize() < 15)
            {
                textField.str += static_cast<char>(event.text.unicode);
            }


            textField.text.setString(textField.str);
        }
    }
}

// Функция для обработки текстовых полей
void enterLoginAndPassword(sf::Event &event, std::vector<TextData> &textFields)
{
    // ввод текста в поле логин и пароль
    if (event.type == sf::Event::TextEntered and event.text.unicode < 128)
    {
        if (event.text.unicode == 8 and textFields.at(0).isClicked)
        { // Backspace
            if (!textFields.at(0).str.empty())
                textFields.at(0).str.pop_back();
        }
        else if (textFields.at(0).isClicked and textFields.at(0).text.getString().getSize() < 12)
            textFields.at(0).str += static_cast<char>(event.text.unicode);


        if (event.text.unicode == 8 and textFields.at(1).isClicked)
        { // Backspace
            if (!textFields.at(1).str.empty())
            {
                textFields.at(1).str.pop_back();
                textFields.at(2).str.pop_back();
            }
        }
        else if (textFields.at(1).isClicked and textFields.at(1).text.getString().getSize() < 12)
        {
            textFields.at(1).str += static_cast<char>(event.text.unicode);
            textFields.at(2).str += "*";
        }
        textFields.at(0).text.setString(textFields.at(0).str);
        textFields.at(1).text.setString(textFields.at(1).str);
        textFields.at(2).text.setString(textFields.at(2).str);
    }
}

// Функция для обработки кнопки
bool handleButton(const sf::Text& button, sf::Event& event, sf::RenderWindow& window) 
{
    bool isButtonClicked = false;
    if (event.type == sf::Event::MouseButtonPressed) 
    {
        if (event.mouseButton.button == sf::Mouse::Left) 
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
                isButtonClicked = true;
        }
    }
    return isButtonClicked;
}

// Функция для создания текста
void createText(sf::Text& text, const std::wstring& str, const sf::Font& font, unsigned int size, const sf::Color& color, const sf::Vector2f& position) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
}

// Функция для создания текста
void createText(sf::Text& text, const std::string& str, const sf::Font& font, unsigned int size, const sf::Color& color, const sf::Vector2f& position) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
}

// Функция для выделения текста при наведении
void highlightButton(sf::Text& button, sf::RenderWindow& window) 
{
    if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) 
        // Если курсор находится над кнопкой, меняем ее цвет
        button.setFillColor(sf::Color(255, 51, 6));
    else 
        // В противном случае возвращаем исходный цвет
        button.setFillColor(sf::Color::White);
}

// Функция для выделения прямоугольника при наведении
void highlightButton(sf::RectangleShape& button, sf::RenderWindow& window)
{
    if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        // Если курсор находится над кнопкой, меняем ее цвет
        button.setFillColor(sf::Color(255, 245, 7));
    else 
        // В противном случае возвращаем исходный цвет
        button.setFillColor(sf::Color(255, 193, 7));
}

int isTextEmpty(std::vector<TextData>& textFields)
{
    for (int i = 0; i < textFields.size(); i++)
    {
        if (textFields.at(i).str.empty())
            return 1;
    }
    return 0;
}