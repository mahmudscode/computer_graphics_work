#include <GL/glut.h>
#include <iostream>
#include <iomanip>
using namespace std;

int xc, yc, r;

// Draw points (8-way symmetry)
void drawPoints(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
    glEnd();
}

// Print table row
void printRow(int step, int x, int y, int p) {
    cout << setw(5) << step
         << setw(5) << x
         << setw(5) << y
         << setw(8) << p << "   ";

    // Q1
    cout << "(" << xc + x << "," << yc + y << ") "
         << "(" << xc + y << "," << yc + x << ")   ";

    // Q2
    cout << "(" << xc - x << "," << yc + y << ") "
         << "(" << xc - y << "," << yc + x << ")   ";

    // Q3
    cout << "(" << xc - x << "," << yc - y << ") "
         << "(" << xc - y << "," << yc - x << ")   ";

    // Q4
    cout << "(" << xc + x << "," << yc - y << ") "
         << "(" << xc + y << "," << yc - x << ")";

    cout << endl;
}

// Midpoint Algorithm
void drawCircle() {
    int x = 0;
    int y = r;
    int p = 1 - r;
    int step = 1;

    cout << "\nStep   x   y   p      Q1 Points        Q2 Points        Q3 Points        Q4 Points\n";
    cout << "------------------------------------------------------------------------------------------\n";

    while (x <= y) {
        printRow(step, x, y, p);
        drawPoints(x, y);

        x++;

        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }

        step++;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);

    glColor3f(1, 1, 1);
    drawCircle();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv) {
    cout << "Enter center (xc yc): ";
    cin >> xc >> yc;

    cout << "Enter radius: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Midpoint Circle with Table");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}