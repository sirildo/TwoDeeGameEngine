#ifndef AREA_H
#define AREA_H

#include <SDL.h>

class Area {
public:
    explicit Area(bool isOverworldArea = false);
    virtual ~Area();

    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;

    bool isOverworldArea() const;

protected:
    bool isOverworld;
};

#endif // AREA_H
