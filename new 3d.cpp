#include <windows.h>
#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glEnable(GL_DEPTH_TEST); // Enable depth testing
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
    glLoadIdentity(); // Reset the model-view matrix

    // Set camera position and orientation
    gluLookAt(0.0, 2.0, 5.0, // Eye position
        0.0, 0.0, 0.0, // Look-at position
        0.0, 1.0, 0.0); // Up vector

    // Draw a pyramid
    glBegin(GL_TRIANGLES); // Begin drawing triangles
    glColor3f(1.0, 0.0, 0.0); // Set color to red

    // Front face
    glVertex3f(0.0, 1.0, 0.0); // Top
    glVertex3f(-1.0, -1.0, 1.0); // Bottom left
    glVertex3f(1.0, -1.0, 1.0); // Bottom right

    // Right face
    glColor3f(0.0, 1.0, 0.0); // Set color to green
    glVertex3f(0.0, 1.0, 0.0); // Top
    glVertex3f(1.0, -1.0, 1.0); // Bottom left
    glVertex3f(1.0, -1.0, -1.0); // Bottom right

    // Back face
    glColor3f(0.0, 0.0, 1.0); // Set color to blue
    glVertex3f(0.0, 1.0, 0.0); // Top
    glVertex3f(1.0, -1.0, -1.0); // Bottom left
    glVertex3f(-1.0, -1.0, -1.0); // Bottom right

    // Left face
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow
    glVertex3f(0.0, 1.0, 0.0); // Top
    glVertex3f(-1.0, -1.0, -1.0); // Bottom left
    glVertex3f(-1.0, -1.0, 1.0); // Bottom right
    glEnd(); // End drawing triangles

    // Draw the base of the pyramid
    glBegin(GL_QUADS); // Begin drawing quads
    glColor3f(1.0, 0.0, 1.0); // Set color to magenta

    glVertex3f(-1.0, -1.0, 1.0); // Bottom left
    glVertex3f(1.0, -1.0, 1.0); // Bottom right
    glVertex3f(1.0, -1.0, -1.0); // Top right
    glVertex3f(-1.0, -1.0, -1.0); // Top left

    glEnd(); // End drawing quads

    glFlush(); // Flush OpenGL buffer
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h); // Set the viewport to cover the new window
    glMatrixMode(GL_PROJECTION); // Switch to projection matrix
    glLoadIdentity(); // Reset the projection matrix

    // Set perspective projection
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW); // Switch back to model-view matrix
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Enable depth buffer
    glutInitWindowSize(500, 500); // Set the window size
    glutCreateWindow("Pyramid"); // Create a window with the given title

    init(); // Initialize OpenGL settings
    glutDisplayFunc(display); // Register display callback function
    glutReshapeFunc(reshape); // Register reshape callback function

    glutMainLoop(); // Enter the event loop

    return 0;
}