#pragma once
#include "Entity.h"
class Ball: public Entity
{
public:
	Ball();
	Ball(int px, int py, int pw, int ph);
	~Ball();
	void Move(Graphics^ g);
	void Draw_Ball(Graphics^ g);
};

