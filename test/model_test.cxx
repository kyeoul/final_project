#include "model.hxx"
#include <catch.hxx>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//

TEST_CASE("Model test - enemy")
{
    Model m({1024, 720});

    std::vector<Enemy> list_enemies = m.get_list_enemies();

    m.on_frame(0.5);

    std::vector<Enemy> list_enemies2 = m.get_list_enemies();
}
