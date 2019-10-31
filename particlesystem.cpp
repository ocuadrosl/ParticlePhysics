#include "particlesystem.h"

ParticleSystem::ParticleSystem()
{

}


void ParticleSystem::setNumberOfParticles(unsigned number)
{
    this->numberOfParticles = number;
}

void ParticleSystem::updateSystem()
{
    particles.resize(numberOfParticles);
}


void ParticleSystem::startsystem()
{

    for(auto it=particles.begin();it != particles.end();++it)
    {
        (*it).setLifetime(1000);
     }

}

Particle ParticleSystem::operator[](unsigned index)
{

    return particles[index];
}
