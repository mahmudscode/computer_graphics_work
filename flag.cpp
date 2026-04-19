#include <GL/glut.h>
#include <cmath>

// Flag dimensions (scaled)
float flagLength = 1.0;     // total length
float flagHeight = 0.6;     // 10:6 ratio

// Circle properties
float radius = flagLength / 5.0;         // 1/5 of length
float circleX = -flagLength/2 + (2*flagLength/5); // 2/5 from left
float circleY = 0.0;

// Draw filled circle
void drawCircle(float cx, float cy, float r) {
    glColor3f(1, 0, 0); // Red

    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2 * 3.1416 * i / 100;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ======================
    // GREEN FLAG
    // ======================
    glColor3f(0, 0.6, 0);

    glBegin(GL_POLYGON);
        glVertex2f(-flagLength/2,  flagHeight/2);
        glVertex2f( flagLength/2,  flagHeight/2);
        glVertex2f( flagLength/2, -flagHeight/2);
        glVertex2f(-flagLength/2, -flagHeight/2);
    glEnd();

    // ======================
    // RED CIRCLE (ACCURATE)
    // ======================
    drawCircle(circleX, circleY, radius);

    // ======================
    // FLAG POLE
    // ======================
    glColor3f(1,1,1);

    float poleX = -flagLength/2 - 0.05;

    glBegin(GL_POLYGON);
        glVertex2f(poleX, 0.5);
        glVertex2f(poleX + 0.02, 0.5);
        glVertex2f(poleX + 0.02, -0.5);
        glVertex2f(poleX, -0.5);
    glEnd();

    // Base
    glBegin(GL_POLYGON);
        glVertex2f(poleX - 0.05, -0.5);
        glVertex2f(poleX + 0.07, -0.5);
        glVertex2f(poleX + 0.07, -0.55);
        glVertex2f(poleX - 0.05, -0.55);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Bangladesh Flag (Accurate 🇧🇩)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}