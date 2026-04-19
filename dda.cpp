#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int x1_, y1_, x2_, y2_;

// Plot pixel
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

// DDA Algorithm
void drawLineDDA() {
    int dx = x2_ - x1_;
    int dy = y2_ - y1_;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1_;
    float y = y1_;

    cout << "\nVisited Points (DDA):\n";

    for (int i = 0; i <= steps; i++) {
        int px = round(x);
        int py = round(y);

        cout << "(" << px << ", " << py << ")\n";

        drawPixel(px, py);

        x += xInc;
        y += yInc;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);

    glColor3f(1, 1, 1);
    drawLineDDA();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1: ";
    cin >> x1_ >> y1_;
    cout << "Enter x2 y2: ";
    cin >> x2_ >> y2_;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("DDA Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}