#ifndef APPLICATION_INCLUDED
#define APPLICATION_INCLUDED

#include <SFML/Graphics.hpp>
#include "Path.hpp"

class Application
{
    public:
        const unsigned int WIDTH  = 1280;
        const unsigned int HEIGHT = 720;
    private:
        sf::RenderWindow*  m_window;
        sf::Clock          m_clock;
        BIG_PATH           m_big_path;
        VERTEX             m_buddy_pos;
    public:
        Application();

        bool is_window_open();

        bool Update();
        void Draw();
};

#endif