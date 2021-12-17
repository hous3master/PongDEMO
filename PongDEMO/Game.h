#pragma once
#include "Ball.h"
#include "Player.h"
class Game
{
private:
	Player* player1;
	Player* player2;
	Ball* ball;
	int player1_points, player2_points;
public:
	Game();
	~Game();
	void Draw_Objects(Graphics^ g);
	void Collision();
	void new_orientation_player1(direction new_data);
	void new_orientation_player2(direction new_data);
	System::String^ return_player_points(int player_number);
	System::String^ return_player_winner();
	bool End_Game();
};

