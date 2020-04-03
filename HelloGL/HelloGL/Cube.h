#pragma once
#include <Windows.h>
#include <gl/GL.h> 
#include <gl/GLU.h>
#include "GL/freeglut.h" 
#include "Structures.h"
#include "SceneObject.h"

class Cube : public SceneObject
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static Vertex verticies[];
	static Color colors[];
	static int numVertices, numColors, numIndices;
	GLfloat _rotation;


	struct Vector3_position
	{
		float x;
		float y;
		float z;
	};

	Vector3 _position;

public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();

	void Draw() override;
	void Update();
	/*static bool Load(char* path);*/
};

