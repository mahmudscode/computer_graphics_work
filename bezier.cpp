#include <GL/glut.h>

float P0[2] = {100, 300};
float P1[2] = {200, 100};
float P2[2] = {400, 100};
float P3[2] = {500, 300};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);

    glBegin(GL_LINE_STRIP);

    for(float t = 0; t <= 1; t += 0.01) {
        float x =
            (1-t)*(1-t)*(1-t)*P0[0] +
            3*t*(1-t)*(1-t)*P1[0] +
            3*t*t*(1-t)*P2[0] +
            t*t*t*P3[0];

        float y =
            (1-t)*(1-t)*(1-t)*P0[1] +
            3*t*(1-t)*(1-t)*P1[1] +
            3*t*t*(1-t)*P2[1] +
            t*t*t*P3[1];

        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

void init() {
    glClearColor(0,0,0,1);
    gluOrtho2D(0,600,600,0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Bezier Curve");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}