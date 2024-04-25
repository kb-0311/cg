#include <windows.h>
#include <GL/glut.h>

void display() {
  glClearColor(255, 255, 255, 255);
  glOrtho(-4, 4, -4, 4, -4, 4);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex2f(-3.0f, -3.0f);
  glVertex2f(3.0f, -3.0f);
  glVertex2f(3.0f, 3.0f);
  glVertex2f(-2.0f, 2.0f);
  glEnd();

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutCreateWindow("QUADRILATERAL");
  glutInitWindowSize(320, 320);
  glutInitWindowPosition(50, 50);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}