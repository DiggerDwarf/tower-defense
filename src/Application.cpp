#include "Application.hpp"


Application::Application()
{
    this->m_window = new sf::RenderWindow(sf::VideoMode(Application::WIDTH, Application::HEIGHT), "Tower Defense Prototype", sf::Style::Default);
    this->m_clock.restart();
    this->m_big_path = {
        {{10, 10}, {100, 100}, {50, 250}},
        {{50, 250}, {100, 100}, {300, 140}}
    };

    this->m_window->setFramerateLimit(60);
}

bool Application::is_window_open()
{
    return this->m_window->isOpen();
}

bool Application::Update()
{
    float delta_time = (this->m_clock.getElapsedTime()-this->m_elapsed).asSeconds();
    this->m_elapsed = this->m_clock.getElapsedTime();

    sf::Event event;
    bool out(false);

    while (this->m_window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            this->m_window->close();
            out = true;
            break;
        
        default:
            break;
        }
    }

    this->handle_keyboard(delta_time);

    this->m_buddy_pos = lerp_BIG_PATH(this->m_big_path, this->m_buddy_dist);

    return out;
}

void Application::handle_keyboard(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) this->m_buddy_dist -= dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->m_buddy_dist += dt;    
}

void Application::Draw()
{
    this->m_window->clear(sf::Color(0xff, 0x55, 0x00));

    sf::CircleShape buddy(15.0F);
    buddy.setPosition(this->m_buddy_pos.x, this->m_buddy_pos.y);

    this->m_window->draw(buddy);

    this->m_window->display();
}
