#ifndef PARTICLE_H
#define PARTICLE_H

#include <GL/glew.h>


class Particle
{
public:
    Particle();

private:
    float type;
    Vector3f Pos;
    Vector3f Vel;
};

#endif // PARTICLE_H
