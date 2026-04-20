#include <GL/glut.h>

float angle = 0;
float posX = 0, posY = 0, posZ = 0;
float scale = 1.0;

// Cube
void drawCube() {
    glutWireCube(2);
}

// Display
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(0, 0, 10,   0, 0, 0,   0, 1, 0);

    // ======================
    // TRANSFORMATIONS
    // ======================
    glTranslatef(posX, posY, posZ);
    glRotatef(angle, 1, 1, 0);
    glScalef(scale, scale, scale);

    glColor3f(1, 1, 1);
    drawCube();

    glutSwapBuffers();
}

// Keyboard control
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'a': posX -= 0.5; break;
        case 'd': posX += 0.5; break;
        case 'w': posY += 0.5; break;
        case 's': posY -= 0.5; break;
        case 'q': posZ += 0.5; break;
        case 'e': posZ -= 0.5; break;

        case '+': scale += 0.1; break;
        case '-': scale -= 0.1; break;

        case 'r': angle += 10; break;
    }

    glutPostRedisplay();
}

// Init
void init() {
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 1, 100);

    glMatrixMode(GL_MODELVIEW);
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("3D Transformations");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}