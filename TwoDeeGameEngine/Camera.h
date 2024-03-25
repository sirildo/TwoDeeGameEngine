#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
    Camera(int width, int height);
    void update(int targetX, int targetY, int areaWidth, int areaHeight);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

private:
    int x, y; // Camera position
    int width, height; // Camera viewport dimensions

    // Prevents the camera from going outside the level boundaries
    void clampToAreaBounds(int areaWidth, int areaHeight);
};

#endif // CAMERA_H
#pragma once
