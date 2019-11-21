#include "particlesystem.h"

ParticleSystem::ParticleSystem()
{

}


void ParticleSystem::setNumberOfParticles(unsigned number)
{
    this->nParticles = number;
}

void ParticleSystem::updateSystem()
{
    //particles.resize(nParticles);
}


void ParticleSystem::initSystem()
{


    particles = particlesV(nParticles);

    for(auto it=particles.begin();it != particles.end();++it)
    {
        std::unique_ptr<Particle> particle(new Particle);
        (*it) = std::move(particle);
        (*it)->setMass(0.1f);


    }

}
void ParticleSystem::setRandonInitPosition()
{

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for(auto it=particles.begin(); it != particles.end(); ++it)
    {

        //alias definitions
        vectorF &position =  (*it)->getPosition();

        position[0] = (std::rand() % 1001 + (-500))/100.f ;
        position[1] =  std::rand() % 20;
        position[2] = (std::rand() % 1001 + (-500))/100.f;



     }

}



void ParticleSystem::startSystem()
{
    //time step
    unsigned frameNumber = 1;
    for(float t = 0.f; t<=simulationTime; t+=0.0001f)
    {
        //for each particle
        for(auto pt = particles.begin(); pt != particles.end(); ++pt)
        {
            //alias to current particle
            auto &p = *pt;

            //more alias
            vectorF &position =  p->getPosition();
            vectorF &velocity =  p->getVelocity();

            //Euler's method
            position[0] = velocity[0]*t + position[0];
            position[1] = velocity[1]*t + position[1];
            position[2] = velocity[2]*t + position[2];

            const float mass = p->getMass();

            velocity[0] = (force[0]/mass)*t + velocity[0];
            velocity[1] = (force[1]/mass)*t + velocity[1];
            velocity[2] = (force[2]/mass)*t + velocity[2];


            //Check sphere collition
            checkSphereCollition(position);

            //Check floor collition
            if(position[1]<floorPosition)
            {
                position[1] = floorPosition;
            }

            //p->print();



        }
        writeFrame(frameNumber++);

    }


    std::cout<<"Writing frames [OK]"<<std::endl;
}


void ParticleSystem::checkSphereCollition(vectorF & position)
{

    float sLength = util::squaredLength(position);

    if( sLength < sphereRadius*sphereRadius)
    {

        vectorF normPos;
        util::normalize(position, normPos);
        position[0] = normPos[0]*sphereRadius;
        position[1] = normPos[1]*sphereRadius;
        position[2] = normPos[2]*sphereRadius;

    }


}


void ParticleSystem::setSphereRadius(float radius)
{
    sphereRadius = radius;
}

/*
Writing an ASCII vtk file
*/
void ParticleSystem::writeFrame(unsigned index)
{

    std::string fileName  = directory+"/frame_"+std::to_string(index)+".vtk";

    std::ofstream frame (fileName);

    if (!frame.is_open())
    {
        std::cerr<<"Error opening "<<fileName <<std::endl;
        return;
    }

    //headers
    frame << "# vtk DataFile Version 2.0"<<std::endl;
    frame<< "Particle system"<<std::endl;
    frame<<"ASCII"<<std::endl;
    frame<<"DATASET UNSTRUCTURED_GRID"<<std::endl;
    frame<<"POINTS "<< nParticles<< " float"<< std::endl;

    for(auto it = particles.begin(); it != particles.end(); ++it)
    {

        const auto& position  = (*it)->getPosition();

        frame <<position[0]<<" "<<position[1]<<" "<<position[2]<<std::endl;
    }

    frame<<"CELLS "<< nParticles<< " "<< nParticles*2<< std::endl;

    for(unsigned i=0;i<nParticles;++i)
    {
        frame<<1<<" "<<i<<std::endl;

    }

    frame<<"CELL_TYPES "<< nParticles<< std::endl;
    for(unsigned i=0;i<nParticles;++i)
    {
        frame<<1<<std::endl;
    }

    frame<<"CELL_DATA "<< nParticles<< std::endl;
    frame<<"SCALARS cell_scalars float 1"<< std::endl;
    frame<<"LOOKUP_TABLE ParticleColors "<< std::endl;
    for(unsigned i=0;i<nParticles;++i)
    {
        frame<< "0.0" <<std::endl;
    }

    //Green color
    frame<<"LOOKUP_TABLE ParticleColors "<< nParticles<< std::endl;
    for(unsigned i=0;i<nParticles;++i)
    {
        frame<< "0.0 1.0 0.0 1.0" <<std::endl;
    }



}



void ParticleSystem::setFramesOutputDir(const std::string& dir)
{

    this->directory = dir;

}






