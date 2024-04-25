
#include <GL/glut.h>
#include <cmath>


const float PI = 3.14159265f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-5, 5, -5, 5, -5, 5);
    glColor3f(255, 255, 255);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float angle = i * PI / 180.0f;
        float x = cos(angle);
        float y = sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(480, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("CIRCLE");
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
