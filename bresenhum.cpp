#include <GL/glut.h>
#include <iostream>
using namespace std;

int x1_, y1_, x2_, y2_;

// Plot pixel
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

// Bresenham Algorithm
void drawLineBresenham() {
    int dx = abs(x2_ - x1_);
    int dy = abs(y2_ - y1_);

    int sx = (x1_ < x2_) ? 1 : -1;
    int sy = (y1_ < y2_) ? 1 : -1;

    int err = dx - dy;

    int x = x1_;
    int y = y1_;

    cout << "\nVisited Points (Bresenham):\n";

    while (true) {
        cout << "(" << x << ", " << y << ")\n";
        drawPixel(x, y);

        if (x == x2_ && y == y2_) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }

        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);

    glColor3f(1, 1, 1);
    drawLineBresenham();

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
    glutCreateWindow("Bresenham Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}