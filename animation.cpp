#include <GL/glut.h>

// position of square
float posX = 0;

void drawSquare(float x) {
    glBegin(GL_POLYGON);
        glVertex2f(x, 200);
        glVertex2f(x + 100, 200);
        glVertex2f(x + 100, 300);
        glVertex2f(x, 300);
    glEnd();
}

// Display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0); // red square
    drawSquare(posX);

    glFlush();
}

// Timer function (called repeatedly)
void update(int value) {
    posX += 5;  // move right

    // reset position (loop)
    if (posX > 600)
        posX = -100;

    glutPostRedisplay(); // redraw
    glutTimerFunc(30, update, 0); // repeat every 30ms
}

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 600, 600, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Basic Animation");

    init();
    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0); // start animation

    glutMainLoop();
}