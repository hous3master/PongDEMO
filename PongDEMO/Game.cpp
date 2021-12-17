#include "Game.h"
Game::Game() {
	player1 = new Player(10, 300, 30, 100);
	player2 = new Player(550, 300, 30, 100);
	ball = new Ball(300, 300, 30, 30);
	player1_points = player2_points = 0;
}
Game::~Game(){
	delete player1, player2, ball;
}
void Game::Draw_Objects(Graphics^ g) {
	player1->Draw_player_rectangle(g, 1);
	player2->Draw_player_rectangle(g, 2);
	ball->Draw_Ball(g);
	player1->Move(g);
	player2->Move(g);
	ball->Move(g);
}
void Game::Collision() {
	System::Random^ rnd = gcnew System::Random();
	int tempY = rnd->Next(0, 2);
	int ball_dx, ball_dy;
	if (tempY)
		ball_dy = rnd->Next(10, 20);
	else
		ball_dy = -rnd->Next(10, 20);
	//Ball collides with player
	if (ball->return_rectangle().IntersectsWith(player1->return_rectangle()) || ball->return_rectangle().IntersectsWith(player2->return_rectangle())) {
		ball->new_dx(ball->return_dx() * -1);
		ball->new_dy(ball_dy);
		ball->new_flag(false);
	}
	//Ball collides with wall or DETECT ERROR
	else if (ball->return_flag() || ball->return_dx() == 0) {
		//Left wall: point to player 2
		if (ball->return_x() < 300)
			player2_points++;
		//Right wall: point to player 1
		if (ball->return_x() > 300)
			player1_points++;
		//Ball and players resets
		ball->new_x(300);
		ball->new_y(300);
		ball->new_dx(30);
		ball->new_dy(0);
		ball->new_flag(false);
		player1->new_dy(0);
		player1->new_y(300);
		player2->new_dy(0);
		player2->new_y(300);
	}
	
	
}
void Game::new_orientation_player1(direction new_data) {
	player1->new_orientation(new_data);
}
void Game::new_orientation_player2(direction new_data) {
	player2->new_orientation(new_data);
}
System::String^ Game::return_player_points(int player_number) {
	System::String^ points_text;
	if (player_number == 1)
		points_text = player1_points.ToString();
	else
		points_text = player2_points.ToString();

	return points_text;
}
System::String^ Game::return_player_winner() {
	System::String^ winner_text;
	if (player1_points > player2_points)
		winner_text = "Player 1 Wins!";
	else
		winner_text = "Player 2 Wins!";
	return winner_text;
}
bool Game::End_Game() {
	if (player1_points >= 5 || player2_points >= 5)
		return true;
	return false;
}