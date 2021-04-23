#ifndef MYARHIVE_H
#define MYARHIVE_H

#include "MyMatrixWork.h"

typedef std::vector<matrix_t> states_t;

class MyArhive
{
public:
	MyArhive();
	~MyArhive();
	matrix_t getNextAction();
	matrix_t getLastAction();
	void writeAction(matrix_t new_state);
	void clearNextActions();
	int getListLen();
	int getCurrentIndex();
	void setCurrentIndex(int i);

private:
	states_t list;
	int current_state_index = 0;
};

#endif