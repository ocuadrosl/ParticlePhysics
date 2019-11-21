#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H


#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "particle.h"
#include "Util.h"

class ParticleSystem
{

    //vector of Particle pointers
    using particlesV = std::vector<std::unique_ptr<Particle>>;
    using vectorF = std::vector<float>;
    const vectorF gravity = {-0.2f, -0.98f, 0.f};


public:
    ParticleSystem();
    void setNumberOfParticles(unsigned number);
    void updateSystem();
    void initSystem();
    void setRandonInitPosition();
    void startSystem();
    void setSphereRadius(float radius);

private:

    particlesV particles;

    unsigned nParticles = 0;
    float    simulationTime = 0.025f; //time
    const float floorPosition = -15.f;
    float sphereRadius = 5.0f;

    void checkSphereCollition(vectorF & position);

    //CHANGE IT
    std::string directory = "/home/oscar/tmp/frames/";
    void writeFrame(unsigned index);



};

#endif // PARTICLESYSTEM_H
