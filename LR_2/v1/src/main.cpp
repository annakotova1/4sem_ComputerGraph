#include "../inc/MyMainWindow.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv); // Обработчик событий - создание
	MyMainWindow *window = new MyMainWindow; // Создаем элемент нашего класса (т.е. наше главное окно)
	window->show(); // Показываем наше главное окно
	return app.exec(); // Обработчик событий - запуск*/

	/*DrawFish::MyPoint real1 = DrawFish::MyPoint(-20, -20);
	DrawFish::MyPoint real2 = DrawFish::MyPoint(20, 20);
	DrawFish::MyPoint screen2 = DrawFish::MyPoint(500, 500);

	DrawFish::MyPoint r1 = DrawFish::MyPoint(-6, 3);
	DrawFish::MyPoint r2 = DrawFish::MyPoint(6, -3);
	
	MyViewPort h = MyViewPort(real1, real2, screen2);
	DrawFish::MyPoint s1 = h.getScreenCoordinatesByReal(r1);
	DrawFish::MyPoint s2 = h.getScreenCoordinatesByReal(r2);

	std::cout << "s1x: " << s1.x << " s1y: " << s1.y << " s2x: " << s2.x << " s2y" << s2.y << std::endl;
	return 0;*/
}
