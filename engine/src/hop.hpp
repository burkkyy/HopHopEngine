
/**
 * @file hop.cpp
 * @author Caleb Burke
 * @date Nov 5, 2023
 *
 * Main header file users of library will use.
 * Other helper functions and constants defined here.
 *
 */

#ifndef HOPENGINE_HEADER
#define HOPENGINE_HEADER

#include <Input/input.hpp>
#include <Engine/engine.hpp>
#include "definitions.hpp"
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include <chrono>
#include <memory>


namespace hop {
typedef std::shared_ptr<hop::EngineRectangle> Rectangle;
typedef std::shared_ptr<hop::EngineCircle> Circle;
typedef std::shared_ptr<hop::EngineGameObject> Triangle;
typedef std::shared_ptr<hop::EngineGameObject> GameObject;

// Colors objects can be set to
#define RED Color{1.0f, 0.0f, 0.0f}
#define GREEN Color{0.0f, 1.0f, 0.0f}
#define BLUE Color{0.0f, 0.0f, 1.0f}
#define BLACK Color{0.0f, 0.0f, 0.0f}
#define WHITE Color{1.0f, 1.0f, 1.0f}

class Keyboard;

class Game{
    
    public:

    Game(const char* window_name);
    bool set_window_size(int width, int height);
    void set_fullscreen();
    void set_windowed();
    void run();
    int get_resolution_width();
    int get_resolution_height();

    Rectangle create_rectangle(int x, int y, int width, int height, Color color);
    Circle create_circle(int x, int y, int radius, Color color);
    Triangle create_triangle(int v1x, int v1y, int v2x, int v2y, int v3x, int v3y, Color color);

    bool is_running();
    void update();
    bool monitor_key(int key_code);
    static std::vector<int> keys_pressed;
    static std::vector<int> keys_held;
    static std::vector<int> keys_monitored;
    bool key_pressed(int key);
    void stop();
    std::vector<int> get_pressed_keys();
    std::vector<int> get_held_keys();
    std::vector<int> get_released_keys();

    private:
    std::shared_ptr<Engine> graphics_engine;
    std::shared_ptr<Keyboard> keyboard;
    bool engine_stopped = false;
    bool fullscreen = false;


};

class ObjectGroup{

    public:

    ObjectGroup(int x, int y,int width, int height);
    
    bool create_rectangle(int x, int y, int width, int height, Color color);
    bool create_circle(int x, int y, int radius, Color color);
    bool create_triangle(int v1x, int v1y, int v2x, int v2y, int v3x, int v3y, Color color);
    inline static void set_game(Game* game);
    void set_color(hop::Color color);
    void move(int x, int y);

    private:
    int x;
    int y;
    int width;
    int height;
    std::vector<GameObject> game_objects;
    inline static Game* game;
};

}
#endif 