#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
    Camera(int width, int height);
    void update(int targetX, int targetY, int levelWidth, int levelHeight);

    int getX() const;
    int getY() const;

private:
    int x, y; // Camera position
    int width, height; // Camera viewport dimensions

    // Prevents the camera from going outside the level boundaries
    void clampToLevelBounds(int levelWidth, int levelHeight);
};

#endif // CAMERA_H
#pragma once
