#pragma once
#include <Windows.h> //Required for Windows
#include <gl/GL.h> //Open GL
#include <gl/GLU.h> //Open GL Utilities
#include "GL/freeglut.h" //freeglut libary
#include "Structures.h"
#include "MeshLoader.h"
#include "Cube.h"
#define REFRESHRATE 16


class HelloGL
{

public:
	//contructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();
	void Update();
	void keyboard(unsigned char key, int x, int y);
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
	

	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLight();

private:
	float rotation;
	Camera* camera;
	SceneObject* objects[200];
	Vector4* _lightPosition;
	Lighting* _lightData;
};

