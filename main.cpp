#include <iostream>
#include <memory>
#include <vector>

#include "particlesystem.h"




//local includes
#include "Util.h"


int main()
{

    auto particleSystem = std::make_unique<ParticleSystem>();

    particleSystem->SetNumberOfParticles(500);
    particleSystem->InitSystem();

    particleSystem->SetRandonInitPosition();
    particleSystem->SetFramesOutputDir("/home/oscar/src/ParticlePhysics/frames");
    particleSystem->StartSystem();



    std::cout<<"End"<<std::endl;

    return 0;
}
