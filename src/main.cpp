#include "Application.hpp"


int main(int argc, char const *argv[])
{
    float k(1.F);
    k -= 0.5F;

    Application app;

    bool closed(false);

    while (app.is_window_open() | !closed)
    {
         app.Draw();
closed = app.Update();
    }

    return 0;
}
