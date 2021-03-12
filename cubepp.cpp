#include <GL/glu.h>
#include <GL/glut.h>
#include <gl/gl.h>

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Cube coordinates
	static GLfloat coords[]=
	{
		-0.5, -0.5, -0.5,
		0.5, -0.5, -0.5,
		0.5, 0.5, -0.5,
		-0.5, 0.5, -0.5,
		-0.5, -0.5, 0.5,
		0.5, -0.5, 0.5,
		0.5, 0.5, 0.5,
		-0.5, 0.5, 0.5
	};
	
	// Cube colors
	static GLfloat color[6][3]=
	{
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 },
		{ 0.0, 1.0, 1.0 },
		{ 1.0, 1.0, 0.0 },
		{ 1.0, 0.0, 1.0 },
	};
	
	// Here's where the faces are stored, every vertex owns a number
	static GLubyte num[6][4]=
	{
		{ 0, 1, 2, 3 },
		{ 1, 5, 6, 2 },
		{ 4, 5, 6, 7 },
		{ 0, 4, 7, 3 },
		{ 0, 1, 5, 4 },
		{ 2, 6, 7, 3 }
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, coords);
	glRotatef(0.06, 0.0127, 0.025, 0.025);	// Cube rotation
	
	// Draw cube
	for(int x=0; x!=6; x++)
	{
		glBegin(GL_QUADS);
		glColor3f(color[x][0], color[x][1], color[x][2]);	// Set color for one face
		for(int i=0; i!=4; ++i)
		glArrayElement(num[x][i]);
		glEnd();
	}
	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27 :		// Press Esc to quit
			exit(0);
	}
}

void glInit(void)
{
	glEnable(GL_DEPTH_TEST);	// Activate depth
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cube++");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glInit();
	glutMainLoop();
	return 0;
}
