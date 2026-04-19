#include <GL/glut.h>
#include <cmath>

#define PI 3.1416

// Function to draw a proper star
void drawStar(float cx, float cy, float r, float g, float b) {
    glColor3f(r, g, b);

    float outerRadius = 0.2;
    float innerRadius = 0.08;

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 10; i++) {
        float angle = i * PI / 5; // 36 degrees step

        float radius;
        if (i % 2 == 0)
            radius = outerRadius; // outer point
        else
            radius = innerRadius; // inner point

        float x = cx + radius * cos(angle - PI/2);
        float y = cy + radius * sin(angle - PI/2);

        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 4 stars (same shape, different colors)
    drawStar(-0.6, 0.6, 1.0, 0.0, 0.0); // Red
    drawStar(0.6, 0.6, 0.0, 1.0, 0.0);  // Green
    drawStar(-0.6, -0.6, 0.0, 0.0, 1.0); // Blue
    drawStar(0.6, -0.6, 1.0, 1.0, 0.0); // Yellow

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Proper Star Shape");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}