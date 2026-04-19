#include <GL/glut.h>

void drawHouse()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ======================
    // MAIN BODY
    // ======================
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.9, -0.25);
    glVertex2f(0.9, -0.25);
    glVertex2f(0.9, 0.25);
    glVertex2f(-0.9, 0.25);
    glEnd();

    // ======================
    // ROOF (FLAT TRAPEZOID)
    // ======================
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.9, 0.25);
    glVertex2f(0.9, 0.25);
    glVertex2f(0.6, 0.6);
    glVertex2f(-0.6, 0.6);
    glEnd();

    // ======================
    // DOOR (3D INSET STYLE)
    // ======================

    // Outer boundary (optional - matches your image frame)
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.15, -0.25);
    glVertex2f(0.15, -0.25);
    glVertex2f(0.15, 0.15);
    glVertex2f(-0.15, 0.15);
    glEnd();

    // Top slanted lines (inward)
    glBegin(GL_LINES);
    glVertex2f(-0.15, 0.15);
    glVertex2f(-0.05, 0.05);

    glVertex2f(0.15, 0.15);
    glVertex2f(0.05, 0.05);
    glEnd();

    // Inner vertical lines
    glBegin(GL_LINES);
    glVertex2f(-0.05, 0.05);
    glVertex2f(-0.05, -0.15);

    glVertex2f(0.05, 0.05);
    glVertex2f(0.05, -0.15);
    glEnd();

    // Bottom slanted lines
    glBegin(GL_LINES);
    glVertex2f(-0.05, -0.15);
    glVertex2f(-0.15, -0.25);

    glVertex2f(0.05, -0.15);
    glVertex2f(0.15, -0.25);
    glEnd();

    // ======================
    // LEFT WINDOW (THIN)
    // ======================
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7, 0.0);
    glVertex2f(-0.3, 0.0);
    glVertex2f(-0.3, 0.12);
    glVertex2f(-0.7, 0.12);
    glEnd();

    // Window cross (slightly lower)
    glBegin(GL_LINES);
    glVertex2f(-0.5, 0.0);
    glVertex2f(-0.5, 0.12);

    glVertex2f(-0.7, 0.06);
    glVertex2f(-0.3, 0.06);
    glEnd();

    // ======================
    // RIGHT WINDOW
    // ======================
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.7, 0.0);
    glVertex2f(0.7, 0.12);
    glVertex2f(0.3, 0.12);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, 0.12);

    glVertex2f(0.3, 0.06);
    glVertex2f(0.7, 0.06);
    glEnd();

    // ======================
    // BASE PLATFORM (LONG & THIN)
    // ======================
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7, -0.25);
    glVertex2f(0.7, -0.25);
    glVertex2f(0.7, -0.33);
    glVertex2f(-0.7, -0.33);
    glEnd();

    // ======================
    // LOWER STEP (WIDE)
    // ======================
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4, -0.33);
    glVertex2f(0.4, -0.33);
    glVertex2f(0.4, -0.5);
    glVertex2f(-0.4, -0.5);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // black
    glColor3f(1.0, 1.0, 1.0);         // white

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Exact House (Final Match)");

    init();
    glutDisplayFunc(drawHouse);
    glutMainLoop();

    return 0;
}