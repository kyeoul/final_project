#include "model.hxx"
#include <catch.hxx>

TEST_CASE("Model test - enemy on_frame")
{
    Model m({1024, 720});

    std::vector<Enemy> list_enemies = m.get_list_enemies();

    m.on_frame(0.5);

    std::vector<Enemy> list_enemies_2 = m.get_list_enemies();

    std::vector<Enemy::Posn> list_enemies_pos;
    std::vector<Enemy::Posn> list_enemies_pos_2;

    for(Enemy enemy: list_enemies){
        Enemy::Posn position = enemy.get_box().top_left() + enemy
                .get_velocity() * 0.5;
        list_enemies_pos.push_back(position);
    }

    for(Enemy enemy: list_enemies_2){
        list_enemies_pos_2.push_back(enemy.get_box().top_left());
    }

    CHECK(list_enemies_pos_2 == list_enemies_pos);
}

struct Test_access
{
    Model& model;

    // Constructs a `Test_access` with a reference to the Model under test.
    explicit Test_access(Model&);
    // Sets the player at `posn` to `player`.
    void add_enemy(Enemy enemy);
};

Test_access::Test_access(Model& model)
        : model(model)
{ }

void
Test_access::add_enemy(Enemy enemy)
{
    model.list_enemies.push_back(enemy);
}


TEST_CASE("Model test - test player collision with enemy"){
    Model m({1024, 720});

    Test_access access(m);

    Player::Posn player_pos = m.get_player().get_box().top_right();
    int player_life = m.get_player().get_health();

    Enemy::Dims velocity = {-10, 0};

    Enemy new_enemy(3, {50, 50}, player_pos, velocity);
    access.add_enemy(new_enemy);

    m.on_frame(1);

    CHECK(player_life - 1 == m.get_player().get_health());
}
