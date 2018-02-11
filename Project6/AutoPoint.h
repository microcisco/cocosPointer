#pragma once
#include "app.h"

template<class T>
class AutoPoint
{
public:
	T* point;
	AutoPoint(T* node) 
	{
		app * g = app::getinstance();
		point = node;
		g->addGuard((void**)&point);
	};
	~AutoPoint() {};

	bool isNull() 
	{
		return point == nullptr;
	};

	T* operator->() 
	{
		return point;
	};
};

