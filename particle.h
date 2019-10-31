#ifndef PARTICLE_H
#define PARTICLE_H


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
    void setAcceleration(const vectorF& acceleration);

    float getLifetime() const;

private:
      vectorF position;
      vectorF velocity;
      vectorF acceleration;

      float mass     = 0.f;
      float lifetime = INF; //milliseconds,
};

#endif // PARTICLE_H
