
#pragma GCC optimize("Ofast")
#ifndef SOLAR_H

#define SOLAR_H




// ----------- DEFINE MARCO DIRECTIVE -------------//

typedef long double ld;

struct Position {
    ld x, y, z;
    
    Position(ld init_x = 0.0, ld init_y = 0.0, ld init_z = 0.0);
};



class Sun {
private:
    ld Mass;
public:
    ld Velocity, Acceleration;
    Position pos;

    Sun();
    Sun(ld init_mass, ld init_velocity, ld init_acceleration, const Position& init_position);
    ~Sun();

    ld getMass() const;
    void setPosition(const Position& newPos);
};

#endif 