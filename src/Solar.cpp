#include "../include/Solar.h"

//typedef long double ld;

// --------------------------- Structure Position Implementation ---------------------------
Position::Position(ld init_x, ld init_y, ld init_z)
    : x(init_x), y(init_y), z(init_z) {}
// -------------------------------------------------------------------------------------


// --------------------------- Class Sun Implementation ---------------------------
Sun::Sun()
    : Mass(0.0), Velocity(0.0), Acceleration(0.0), pos(Position(0.0, 0.0, 0.0)) {}

Sun::Sun(ld init_mass, ld init_velocity, ld init_acceleration, const Position& init_position)
    : Mass(init_mass), Velocity(init_velocity), Acceleration(init_acceleration), pos(init_position) {}

Sun::~Sun() {}

ld Sun::getMass() const { return Mass; }

void Sun::setPosition(const Position& newPos) { pos = newPos; }
// ------------------------------------------------------------------------------








