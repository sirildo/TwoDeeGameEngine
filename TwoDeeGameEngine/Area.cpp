#include "Area.h"

Area::Area(bool isOverworldArea) : isOverworld(isOverworldArea) {}

Area::~Area() {
    // Cleanup resources specific to the area if necessary
}

bool Area::isOverworldArea() const {
    return isOverworld;
}
