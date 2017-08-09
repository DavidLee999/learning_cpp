#include <iostream>
#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); 
	glRectf(-0.5f, -0.5f, 0.5f, 0.5);
	glFlush();
}

int main(int argc, char * argv[]) {

	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("第一个OpenGL程序"); 

	glutDisplayFunc(&myDisplay); 
	glutMainLoop(); 

	return 0;
}
