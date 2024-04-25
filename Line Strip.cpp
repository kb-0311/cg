#include <windows.h>
#include <GL/glut.h>

void display() {
    glClearColor(255, 255, 255, 255);
    glOrtho(-4, 4, -4, 4, -4, 4);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 1);
    glVertex2f(0, -3);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1, 0);
    glVertex2f(-3, 0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL lab");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}