#include <GL/glut.h>
#include <cmath>

// Draw line (like graphics.h)
void drawLine(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
    glEnd();
}

// Draw rectangle (outline)
void drawRect(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINE_LOOP);
        glVertex2i(x1, y1);
        glVertex2i(x2, y1);
        glVertex2i(x2, y2);
        glVertex2i(x1, y2);
    glEnd();
}

// Draw filled circle
void drawCircle(int cx, int cy, int r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2 * 3.1416 * i / 100;
        int x = cx + r * cos(angle);
        int y = cy + r * sin(angle);
        glVertex2i(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ======================
    // BASE
    // ======================
    glColor3f(1,1,1);

    drawLine(100, 300, 500, 300);
    drawLine(150, 325, 450, 325);
    drawLine(200, 350, 400, 350);

    // ======================
    // RED CIRCLE
    // ======================
    glColor3f(1,0,0);
    drawCircle(300, 225, 60);

    // ======================
    // SIDE PILLARS
    // ======================
    glColor3f(1,1,1);

    drawRect(150, 230, 180, 300);
    drawRect(200, 200, 230, 300);

    drawRect(370, 200, 400, 300);
    drawRect(420, 230, 450, 300);

    // ======================
    // CENTRAL PILLARS
    // ======================
    drawRect(270, 150, 300, 300);
    drawRect(310, 150, 340, 300);

    // ======================
    // TOP TILT
    // ======================
    drawLine(270,150,260,120);
    drawLine(340,150,350,120);
    drawLine(260,120,350,120);

    // ======================
    // INNER LINES
    // ======================
    drawLine(285,150,285,300);
    drawLine(325,150,325,300);

    glFlush();
}

void init() {
    glClearColor(0,0,0,1);

    // IMPORTANT: pixel coordinate system like graphics.h
    gluOrtho2D(0, 600, 600, 0);  // flipped Y to match graphics.h
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Shahid Minar (OpenGL Pixel Mode)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}