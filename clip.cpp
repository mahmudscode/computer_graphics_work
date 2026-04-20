#include <GL/glut.h>
#include <iostream>
using namespace std;

// Clipping window
float xmin = 100, ymin = 100, xmax = 500, ymax = 500;

// Line points
float x1, y1, x2, y2;

// Region codes
int computeCode(float x, float y) {
    int code = 0;

    if (x < xmin) code |= 1;      // left
    else if (x > xmax) code |= 2; // right

    if (y < ymin) code |= 4;      // bottom
    else if (y > ymax) code |= 8; // top

    return code;
}

// Cohen-Sutherland Algorithm
void clipLine() {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        }
        else if (code1 & code2) {
            break;
        }
        else {
            int codeOut = code1 ? code1 : code2;
            float x, y;

            if (codeOut & 8) { // top
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & 4) { // bottom
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & 2) { // right
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else { // left
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        glColor3f(0, 1, 0); // green clipped line
        glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw clipping window
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin, ymin);
        glVertex2f(xmax, ymin);
        glVertex2f(xmax, ymax);
        glVertex2f(xmin, ymax);
    glEnd();

    // Draw original line
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();

    // Clip and draw
    clipLine();

    glFlush();
}

void init() {
    glClearColor(0,0,0,1);
    gluOrtho2D(0, 600, 600, 0);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2 y2: ";
    cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Line Clipping");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}