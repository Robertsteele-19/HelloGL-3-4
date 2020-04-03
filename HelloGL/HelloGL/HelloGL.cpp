#include "HelloGL.h"
#include "GLUTCallbacks.h"

#include <iostream>
#include <ctime>


HelloGL::HelloGL(int argc, char* argv[])
{
	srand(time(NULL));

	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 10.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	
	rotation = 0.0f;

	InitGL(argc, argv);
	InitObjects();
	InitLight();
	

	glutMainLoop();
}

void HelloGL::Display()
{
	//2D based code below

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	//DrawCubeIndexed(); //draws cube
	for (int i = 0; i < 200; i++)
	{
		objects[i]->Draw();
	}
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();




}


void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
				camera->center.x, camera->center.y, camera->center.z,
					camera->up.x, camera->up.y, camera->up.z);

	for (int i = 0; i < 200; i++)
	{
		objects[i]->Update();
	}

	if (rotation >= 360.0f)
		rotation = 0.0f;

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	glutPostRedisplay();
	//Sleep(10);
}

void HelloGL::keyboard(unsigned char key, int x, int y)
{

	if (key == 'd')
		rotation += 0.5f;

	if (key == 'a')
		rotation -= 0.5f;

	if (key == 'm')
		camera->eye.z += 0.1f;
	
	if (key == 'n')
		camera->eye.z -= 0.1f;
}

void HelloGL::InitObjects()
{
	Mesh *CubeMesh = MeshLoader::Load((char*)"cube.txt");
	Texture2D* texture = new Texture2D();
	texture->Load((char*)"penguins.raw", 512, 512);

	for (int i = 0; i < 200; i++)
	{
		objects[i] = new Cube(CubeMesh,texture,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
}
//for some reason I can't skip through the debug
//Robert can you run it and let us know what happens. We won't be able to see the output
// Luke: 
// hi James and Luke
void HelloGL::InitLight()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");

	glutDisplayFunc(GLUTCallbacks::Display);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);

	//Set the correct perspective
	gluPerspective(45, 1, 0.1, 1000);

	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D); // without this you get white boxes
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glCullFace(GL_BACK);
}





HelloGL::~HelloGL(void)
{
	delete camera;
}

