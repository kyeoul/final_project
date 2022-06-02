#include "controller.hxx"

ge211::Dims<int> screen_dims {1024, 720};

int
main()
{
    Controller(screen_dims).run();

    return 0;
}
