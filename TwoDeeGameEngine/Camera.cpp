#include "Camera.h"

Camera::Camera(int width, int height) : x(0), y(0), width(width), height(height) {}

void Camera::update(int targetX, int targetY, int levelWidth, int levelHeight) {
    // Center the camera over the target
    x = targetX - width / 2;
    y = targetY - height / 2;

    // Adjust the camera to stay within the level boundaries
    clampToLevelBounds(levelWidth, levelHeight);
}

void Camera::clampToLevelBounds(int levelWidth, int levelHeight) {
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > levelWidth - width) x = levelWidth - width;
    if (y > levelHeight - height) y = levelHeight - height;
}

int Camera::getX() const {
    return x;
}

int Camera::getY() const {
    return y;
}

int Camera::getWidth() const {
    return width;
}

int Camera::getHeight() const {
    return height;
}
