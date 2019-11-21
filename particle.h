#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>

class Particle
{
    //aliases
    using vectorF = std::vector<float>;
    const float INF = -1.f; //infinite


public:
    Particle();
    void reset();
    void setLifetime(float lifetime);
    void setMass(float mass);
    void setPosition(const vectorF& position);
    void setVelocity(const vectorF& velocity);
    void setForce(const vectorF& force);

    float getMass() const;
    const vectorF& getPosition() const ;
    const vectorF& getVelocity() const;
    const vectorF& getForce() const;

    vectorF& getPosition();
    vectorF& getVelocity();
    vectorF& getForce();



    float getLifetime() const;

    void print();

private:
    vectorF position;
    vectorF velocity;
    vectorF force;

    float mass     = 1.f;
    float lifetime = INF; //milliseconds,
};

#endif // PARTICLE_H
