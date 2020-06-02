#include <iostream>
#include <memory>
#include <vector>

#include "particlesystem.h"



//local includes
#include "Util.h"


int main()
{

    auto particleSystem = std::make_unique<ParticleSystem>();

    particleSystem->InitSystem();
    particleSystem->SetFramesOutputDir("/home/oscar/Desktop/frames");
    particleSystem->StartSystem();



    std::cout<<"End"<<std::endl;

    return 0;
}
