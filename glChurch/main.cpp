#include <stdio.h>
#include <string.h>
#include <iostream>

#include <GL/glew.h>
#include <GLUT/glut.h>
#include <glm/glm.hpp>
#include "GLM_NR/glm.h"

using namespace std;
const char* datapath = "/Users/Dora/Courses/2016_spring/ComputerGraphics/glChurch";

GLuint VBO;
GLMmodel *obj_bunny;

static void RenderSceneCB()
{
	glmDraw(obj_bunny, GLM_SMOOTH | GLM_MATERIAL);
	/*glClear(GL_COLOR_BUFFER_BIT);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();*/
}


static void InitializeGlutCallbacks()
{
	glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
	glm::vec3 Vertices[1];
	Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}


void init()
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	if (!obj_bunny)
	{
		char filename[256];
		strcpy(filename, datapath);
		strcat(filename, "/Data/bunny.obj");
		obj_bunny = glmReadOBJ(filename);
		if (!obj_bunny)
			exit(0);

		glmUnitize(obj_bunny);
		glmFacetNormals(obj_bunny);
		glmVertexNormals(obj_bunny, 90.0);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Church");

	InitializeGlutCallbacks();

	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	init();
	glutMainLoop();

	return 0;
}