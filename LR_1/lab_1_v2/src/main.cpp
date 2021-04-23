#include "../inc/MyGraphicView.h"
#include "../inc/MyMainWindow.h"
#include "../inc/MyPointsTableModel.h"


#define OK 0
#define ERR_FILE 1
#define ERR_NO_FILE 2

#include <iostream>
#include <fstream>
/*
typedef struct point point_t;
struct point
{
	int x;
	int y;
};*/

int read_point(std::ifstream &file, point_t *a)
{
	a->x = 0;
	a->y = 0;
	file >> a->x;
	file >> a->y;
	if (file.fail())
		return ERR_FILE;
	return OK;
}

int read_file(char *filename)
{
	point_t a;
	std::ifstream file (filename);
	if (!file)
		return ERR_NO_FILE;
	int rc = OK;
	while (rc == OK)
	{
		rc = read_point(file, &a);
		if (rc == OK)
			std::cout << std::endl << "a " << a.x << " " << a.y << std::endl;
	}
	if (file.eof())
		return OK;
	file.close();
	//if (rc != OK)
	//	return rc;
	//std::cout << std::endl << "a " << a.x << " " << a.y << std::endl;
	return ERR_FILE;
}

int main(int argc, char *argv[])
{
	//int rc = read_file("1.txt");
	//std::cout << "rc " << rc << std::endl;
	QApplication app(argc, argv);
    MyMainWindow *widget = new MyMainWindow;

    widget->show();

	return app.exec();
}