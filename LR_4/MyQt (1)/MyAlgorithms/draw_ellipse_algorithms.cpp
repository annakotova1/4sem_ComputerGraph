#include "MyAlgorithmsEllipse.hpp"

void Ellipse4Points(int x, int y, int center_x, int center_y, MyGraphicsItemGroup *group)
{
    group->getPoint(x + center_x, y + center_y);
    group->getPoint(x + center_x, -y + center_y);
    group->getPoint(-x + center_x, y + center_y);
    group->getPoint(-x + center_x, -y + center_y);
}
void Ellipse4Points1(int x, int y, int center_x, int center_y, MyGraphicsItemGroup *group)
{
    group->getPoint(x, y);
    group->getPoint(x, -y);
    group->getPoint(-x, y);
    group->getPoint(-x, -y);
}

void drawEllipseCanon(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group)
{
	const int a2 = a * a;
	const int b2 = b * b;

	const float bDivA = static_cast<float>(b) / a;
	const int deltaX = qRound(a2 / sqrt(a2 + b2));
	for (int x = 0; x <= deltaX; ++x) {
		const int y = qRound(sqrt(static_cast<float>(a2 - x*x)) * bDivA);
		Ellipse4Points(x, y, center_x, center_y, group);
	}

	const float aDivB = static_cast<float>(a) / b;
	const int deltaY = qRound(b2 / sqrt(a2 + b2));
	for (int y = 0; y <= deltaY; ++y) {
		const int x = qRound(sqrt(static_cast<float>(b2 - y*y)) * aDivB);
		Ellipse4Points(x, y, center_x, center_y, group);
	}
}

void drawEllipseParam(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group)
{
    int y;
    int x;
	int s = a;
	if (a < b)
	{
		s = b;
	}
    for (double t = 0; t < M_PI*2; t+=M_PI/(s*2))
    {
        x = a*cos(t);
        y = b*sin(t);
		Ellipse4Points(x, y, center_x, center_y, group);
    }
}

void drawEllipseBresenhem(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group)
{
	int x = 0;
	int y = b;
	float coefx = (float)a/(float)b, coefy = 1;
	if (a > b)
	{
		coefx = 1;
		coefy = (float)b/(float)a;
		y = a;
	}

	int d = 2 * (1 - y);
	while (y >= 0) {
		Ellipse4Points((((float)x)*coefx), (((float)y))*coefy, center_x, center_y, group);

		if (d < 0) { 
			const int d1 = 2 * (d + y) - 1; // lг - lд
			++x;
			if (d1 <= 0)
				d += 2 * x + 1;
			else { 
				--y;
				d += 2 * (x - y + 1);
			}
		}
		else if (d > 0) {
			const int d2 = 2 * (d - x) - 1; // lв - lд
			--y;
			if (d2 > 0)
				d += 1 - 2 * y;
			else { 
				++x;
				d += 2 * (x - y + 1);
			}
		}
		else { 
			++x;
			--y;
			d += 2 * (x - y + 1);
		}
	}
}
void drawEllipseMiddlePoint(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group)
{	
    const int a2 = a * a;
	const int b2 = b * b;

	int x = 0;
	int y = b;

	int f = b2 + a2 * (y - 0.5f) * (y - 0.5) - static_cast<long long>(a2) * b2;
	const int deltaX = a2 / sqrt(b2 + a2);
	while (x <= deltaX) {
		Ellipse4Points(x, y, center_x, center_y, group);

		++x;
		if (f > 0) {
			--y;
			f += -2 * a2 * y; // f += dy;
		}
		f += b2 * (2 * x + 1); // f += df;
	}

	f += 0.75f * (a2 - b2) - (b2 * x + a2 * y);
	while (y >= 0){
		Ellipse4Points(x, y, center_x, center_y, group);

		--y;
		if (f < 0) {
			++x;
			f += 2 * b2 * x; // f += dx;
		}
		f += a2 * (1 - 2 * y); // f += df;
	}

}

void drawEllipseLibrary(int center_x, int center_y, int a, int b, MyGraphicsItemGroup *group)
{
    group->getEllipse(center_x, center_y, a, b);
}


