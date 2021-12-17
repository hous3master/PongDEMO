#include "Ball.h"
Ball::Ball() {}
Ball::Ball(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 1, 1, 0, 0) {
	dx = 30;
	dy = 0;
}
Ball::~Ball() {}
void Ball::Move(Graphics^ g) {
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width) {
		flag = true;
		dx = 0;
	}
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height)
		dy = dy * -1;
	x += dx;
	y += dy;
}
void Ball::Draw_Ball(Graphics^ g) {
	Pen^ p = gcnew Pen(Color::Blue);
	p->Width = 5;
	SolidBrush^ b = gcnew SolidBrush(Color::White);

	g->DrawEllipse(p, x, y, w, h);
	g->FillEllipse(b, x, y, w, h);
}
