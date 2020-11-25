#pragma once

#include "Menu.h"
#include "Queue1.h"

class QueueMenu : public Menu
{
	Queue1 queue;

public:
	QueueMenu();

	void processMenuItem(int number) override;
};

