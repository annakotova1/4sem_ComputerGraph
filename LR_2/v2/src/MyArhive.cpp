#include "../inc/MyArhive.h"


MyArhive::MyArhive()
{
	list = {{{1,0,0}, {0, 1, 0}, {0,0,1}}};
}

MyArhive::~MyArhive()
{
}

matrix_t MyArhive::getNextAction()
{
	++current_state_index;
	return (list)[current_state_index];
}
matrix_t MyArhive::getLastAction()
{
	--current_state_index;
	return (list)[current_state_index];
}
void MyArhive::writeAction(matrix_t new_state)
{
	list.push_back(new_state);
	current_state_index++;
}
void MyArhive::clearNextActions()
{
	for (int i = current_state_index + 1; i < list.size(); i++)
	{
		list.pop_back();
	}
}

int MyArhive::getListLen()
{
	return list.size();
}

int MyArhive::getCurrentIndex()
{
	return current_state_index;
}

void MyArhive::setCurrentIndex(int i)
{
	current_state_index = i;
}