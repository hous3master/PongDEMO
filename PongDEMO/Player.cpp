#include "Player.h"
Player::Player() {}
Player::Player(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 1, 1, 0, 0) {
	lifes = 5;
	vertical_velocity = 25;
	horizontal_velocity = 0;
	new_orientation(direction::still);
}
Player::~Player() {}
void Player::Draw_player_rectangle(Graphics^ g, int player_number) {
	Pen^ p = gcnew Pen(Color::Red);
	SolidBrush^ b;
	p->Width = 5;
	if (player_number == 1)
		b = gcnew SolidBrush(Color::Yellow);
	else
		b = gcnew SolidBrush(Color::Green);
	
	g->DrawRectangle(p, x, y, w, h);
	g->FillRectangle(b, x, y, w, h);
}
void Player::new_lifes(int new_data) { lifes = new_data; }
int Player::return_lifes() { return lifes; }
