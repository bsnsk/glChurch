#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

using namespace std;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25,0.25,0.0);
	glVertex3f(0.75,0.25,0.0);
	glVertex3f(0.75,0.75,0.0);
	glVertex3f(0.25,0.75,0.0);
	glEnd();
	
	glFlush();
	
}

void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, const char * argv[]) {
	// insert code here...
	
	cout << "Hello World";
	glutInit(&argc,(char **)argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}