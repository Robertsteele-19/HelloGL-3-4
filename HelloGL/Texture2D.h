#pragma once
#include <Windows.h> //Required for Windows
#include <gl/GL.h> //Open GL
#include <gl/GLU.h> //Open GL Utilities
#include "GL/freeglut.h" //freeglut libary

class Texture2D
{
private:
	GLuint _ID; //Texture ID
	int _width, _height;

public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};