#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <iostream>
#include <math.h>

class Vector {


public:
	Vector AddVector(Vector a, Vector b);

	Vector SubVecotr(Vector a, Vector b);

	void VectorNormalize(Vector* a); 
	float m_x;
	float m_y;
	
private:
	
	
};
