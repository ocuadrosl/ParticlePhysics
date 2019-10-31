#include "particle.h"

Particle::Particle()
{
    position.resize(3,0.f);
    velocity.resize(3,0.f);
    acceleration.resize(3,0.f);
}

void Particle::reset()
{
    position.resize(3,0.f);
    velocity.resize(3,0.f);
    acceleration.resize(3,0.f);
    mass = 0.f;
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

void Particle::setAcceleration(const vectorF& acceleration)
{
    this->acceleration = acceleration;
}

float Particle::getLifetime() const
{
    return lifetime;
}
