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
    using particlesV = std::vector<Particle>;
    using vectorF = std::vector<float>;

    //gravity
    const vectorF force = {-0.0f, -0.98f, 0.f};


public:
    ParticleSystem();
    void SetNumberOfParticles(unsigned number);
    void UpdateSystem();
    void InitSystem();
    void SetRandonInitPosition();
    void StartSystem();
    void SetSphereRadius(float radius);
    void SetFramesOutputDir(const std::string& dir);

private:

    particlesV particles;

    unsigned nParticles = 0;
    float    simulationTime = 0.0009f; //time

    const float floorPosition = -15.f;
    float sphereRadius = 5.0f;

    void CheckSphereCollition(vectorF & position);

    //CHANGE IT
    std::string directory;
    void writeFrame(unsigned index);



};

#endif // PARTICLESYSTEM_H
