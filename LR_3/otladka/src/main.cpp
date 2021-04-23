#include "../inc/MyMainWindow.hpp"
#include <QApplication>

int main(int argc, char ** argv)
{
	QApplication app(argc, argv);
	MyMainWindow *window = new MyMainWindow(); 
	window->show();
	return app.exec();
}