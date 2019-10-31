#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H


#include <vector>
#include "particle.h"

class ParticleSystem
{

    using particlesV = std::vector<Particle>;



public:
    ParticleSystem();
    void setNumberOfParticles(unsigned number);
    void updateSystem();
    void startsystem();

    Particle operator[](unsigned index);

private:

    particlesV particles;
    unsigned numberOfParticles = 0;



};

#endif // PARTICLESYSTEM_H
