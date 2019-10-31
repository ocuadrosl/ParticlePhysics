#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include "particlesystem.h"

using namespace std;


void displayMe(void)
{
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glFlush();
    */

    ParticleSystem particleSystem;
    particleSystem.setNumberOfParticles(100);
    particleSystem.updateSystem();

    glVertexPointer( 3, GL_FLOAT, sizeof(Particle), nullptr);
    glDrawElements(GL_TRIANGLES, 1, GL_UNSIGNED_INT, nullptr);


}




int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    glEnable(GL_BLEND);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Particle Physics");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
