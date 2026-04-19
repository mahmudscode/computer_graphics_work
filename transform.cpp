#include <GL/glut.h>
#include <cmath>

// original triangle
float tri[3][2] = {
    {100, 100},
    {200, 100},
    {150, 200}
};

// draw triangle
void drawTriangle(float t[3][2]) {
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++)
        glVertex2f(t[i][0], t[i][1]);
    glEnd();
}

// ======================
// TRANSLATION
// ======================
void translate(float t[3][2], float tx, float ty) {
    for(int i=0;i<3;i++) {
        t[i][0] += tx;
        t[i][1] += ty;
    }
}

// ======================
// SCALING
// ======================
void scale(float t[3][2], float sx, float sy) {
    for(int i=0;i<3;i++) {
        t[i][0] *= sx;
        t[i][1] *= sy;
    }
}

// ======================
// ROTATION
// ======================
void rotate(float t[3][2], float angle) {
    float rad = angle * 3.1416 / 180;

    for(int i=0;i<3;i++) {
        float x = t[i][0];
        float y = t[i][1];

        t[i][0] = x*cos(rad) - y*sin(rad);
        t[i][1] = x*sin(rad) + y*cos(rad);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // original
    glColor3f(1,1,1);
    drawTriangle(tri);

    // copy triangle
    float t1[3][2];
    for(int i=0;i<3;i++){
        t1[i][0] = tri[i][0];
        t1[i][1] = tri[i][1];
    }

    // apply transformations
    translate(t1, 200, 0);   // move right
    rotate(t1, 30);          // rotate 30 degrees
    scale(t1, 0.5, 0.5);     // shrink

    glColor3f(1,0,0);
    drawTriangle(t1);

    glFlush();
}

void init() {
    glClearColor(0,0,0,1);
    gluOrtho2D(0, 600, 600, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("2D Transformations");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}