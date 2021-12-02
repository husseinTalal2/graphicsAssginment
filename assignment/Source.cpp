
#include <GL/glut.h>

static float yPosition = 0;
static float zPosition = 0;

float xPos = 0.75;
float yPos = 0.75;
float zPos = 0;
float startXPos = 0.5;
float startYPos = 0.5;
float angle = 0;

int yDirection = 0; //1-up, 0-down
int xDirection = 0; //1-right, 0-left
float width = 1200.0f;
float height = 720.0f;
float r = 0;
float g = 0;
float b = 0;
void hexagon() {
	
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0, 0.5);
	glVertex2d(0.25, 0.25);
	glVertex2d(0.25, -0.25);
	glVertex2d(0, -0.5);
	glVertex2d(-0.25, -0.25);
	glVertex2d(-0.25, 0.25);
	glEnd();
}
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(-width, width, -height, height);
	
}

void checkEdges() {
	if (xDirection == 0 && xPos > 0.0) {
		xDirection = 0;
	}

	if (xDirection == 0 && xPos < 0.0) {
		xDirection = 1;
	}

	if (xDirection == 1 && xPos < startXPos) {
		xDirection = 1;
	}

	if (xDirection == 1 && xPos > startYPos) {
		xDirection = 0;
	}
}
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glColor3f(1, 0, 0);

	glTranslated(xPos, yPos, zPos);
	glRotatef(angle, 0, 1, 0);

	hexagon();
	glutSwapBuffers();
	angle += 0.02;
	if (xDirection == 0) { //if moving left
		xPos -= 0.0002;	//move in a negative direction along the xaxis	
		yPos -= 0.0002; 
	}
	else if (xDirection == 1) {
		xPos += 0.0002;	//otherwise move in the positive direction
		yPos += 0.0002;
	}

	checkEdges();

	glutPostRedisplay();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); 

	glutInitWindowSize(1200, 720);
	glutInitWindowPosition(0, 0);

	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
