#include "MyAlgorithmsCircle.hpp"

void Circle4Points(int x, int y, int center_x, int center_y, MyGraphicsItemGroup *group)
{
    group->getPoint(x + center_x, y + center_y);
    group->getPoint(x + center_x, -y + center_y);
    group->getPoint(-x + center_x, y + center_y);
    group->getPoint(-x + center_x, -y + center_y);
}

void drawCircleCanon(int center_x, int center_y, int radius, MyGraphicsItemGroup *group)
{
	const int r2 = radius*radius;
	const int deltaX = qRound(radius / sqrt(2));
	for (int x = 0; x <= deltaX; ++x) 
    {
		const int y = qRound(sqrt(r2 - x*x));
		Circle4Points(x, y, center_x, center_y, group);
		Circle4Points(y, x, center_x, center_y, group);
	}
}

void drawCircleParam(int center_x, int center_y, int radius, MyGraphicsItemGroup *group)
{
    int y;
    int x;
    for (double t = 0; t < M_PI; t+=M_PI/(radius * 2))
    {
        x = radius*cos(t);
        y = radius*sin(t);
		Circle4Points(x, y, center_x, center_y, group);
		Circle4Points(y, x, center_x, center_y, group);
    }
}

void drawCircleBresenhem(int center_x, int center_y, int radius, MyGraphicsItemGroup *group)
{
	int x = 0;
	int y = radius;

	int d = 2 * (1 - radius);
	while (y >= 0) {
		Circle4Points(x, y, center_x, center_y, group);

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
void drawCircleMiddlePoint(int center_x, int center_y, int radius, MyGraphicsItemGroup *group)
{
	int x = 0;
	int y = radius;
	int d = 1 - radius;
	do {
		Circle4Points(x, y, center_x, center_y, group);
		Circle4Points(y, x, center_x, center_y, group);

		++x;
		if (d < 0) 
			d += 2 * x + 1;
		else { 
			--y;
			d += 2 * (x - y) + 1;
		}
	} while (x <= y);
}

void drawCircleLibrary(int center_x, int center_y, int radius, MyGraphicsItemGroup *group)
{
    group->getCircle(center_x, center_y, radius);
}
