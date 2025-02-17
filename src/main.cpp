#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Vector2f shapeVelocity(2,2);

    sf::CircleShape shape2(100.f);
    shape2.setFillColor(sf::Color::Red);
    shape2.setPosition(sf::Vector2f(500, 755));
    sf::Vector2f shapeVelocity2(2, 2);

    //Game Loop
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        //move the shape
        shape.move(shapeVelocity);
        shape2.move(shapeVelocity2);


        //Boundary checks
        if (shape.getPosition().x > window.getSize().x - shape.getRadius() * 2)
        {
            shapeVelocity.x *= -1;
        }
        else if (shape.getPosition().x < 0)
        {
            shapeVelocity.x *= -1;
        }

        if (shape.getPosition().y > window.getSize().y - shape.getRadius() * 2)
        {
            shapeVelocity.y *= -1;
        }
        else if (shape.getPosition().y < 0)
        {
            shapeVelocity.y *= -1;
        }

        if (shape2.getPosition().x > window.getSize().x - shape2.getRadius() * 2)
        {
            shapeVelocity2.x *= -1;
        }
        else if (shape2.getPosition().x < 0)
        {
            shapeVelocity2.x *= -1;
        }

        if (shape2.getPosition().y > window.getSize().y - shape2.getRadius() * 2)
        {
            shapeVelocity2.y *= -1;
        }
        else if (shape2.getPosition().y < 0)
        {
            shapeVelocity2.y *= -1;
        }

        
        if (shape.getGlobalBounds().findIntersection(shape2.getGlobalBounds()))
        {
            shapeVelocity.x *= -1;
            shapeVelocity.y *= -1;
            shapeVelocity2.x *= -1;
            shapeVelocity2.y *= -1;
        }

        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.display();
    }
}
