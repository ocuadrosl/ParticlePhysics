#include "particle.h"

Particle::Particle()
{
    position = vectorF(3, 0.f);
    velocity = vectorF(3, 0.f);
    force = vectorF(3, 0.f);

}

void Particle::reset()
{
    position = vectorF(3, 0.f);
    velocity = vectorF(3, 0.f);
    force    = vectorF(3, 0.f);
    mass = 1.f;
    lifetime = 0.f;
}

void Particle::setLifetime(float lifetime)
{
    this->lifetime = lifetime;

}
void Particle::setMass(float mass)
{
    this->mass = mass;
}

void Particle::setPosition(const vectorF& position)
{
    this->position = position;
}

void Particle::setVelocity(const vectorF& velocity)
{
    this->velocity = velocity;
}

void Particle::setForce(const vectorF& force)
{
    this->force = force;
}

float Particle::getLifetime() const
{
    return lifetime;
}


float Particle::getMass() const
{
    return this->mass;
}

const Particle::vectorF& Particle::getPosition() const
{
    return this->position;
}

const Particle::vectorF& Particle::getVelocity() const
{
    return this->velocity;
}

const Particle::vectorF& Particle::getForce() const
{
    return this->force;
}

Particle::vectorF& Particle::getPosition()
{
    return this->position;
}

Particle::vectorF& Particle::getVelocity()
{
    return this->velocity;
}

Particle::vectorF& Particle::getForce()
{
    return this->force;
}

void Particle::atPosition(unsigned int index, float value)
{
    position[index] = value;

}

void Particle::atVelocity(unsigned int index, float value)
{
    velocity[index] = value;

}

float Particle::atPosition(unsigned index) const
{
    return position[index];
}

float Particle::atVelocity(unsigned index) const
{
    return position[index];
}


void Particle::print()
{

    std::cout<<"Position: "<<position[0]<<", "<<position[1]<<", "<<position[2]<<std::endl;
}



