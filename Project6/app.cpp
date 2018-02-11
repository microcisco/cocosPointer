#include "app.h"

void app::addGuard(void ** node)
{
	void** i1 =(void**) *node;
	void* t = (i1);
//	void* i2 = *i1;


	app::GuardHash->insert(std::pair<void*, void**>(*node, node));


	/*
	std::map<void *, void **>* sb = app::GuardHash;
	sb->insert(std::pair<void *, void **>(*node, node));
	(*sb)[*node];
	*/


	/*
	std::map<void *, void **> sb;
	sb.insert(std::pair<void *, void **>(*node, node));
	sb[*node];
	*/

}
void app::removeGuard(void * node)
{
	void ** p= (*app::GuardHash)[node];
	*p = nullptr;
	
	(*app::GuardHash)[node] = nullptr;
}

bool app::isNumm(void* node)
{
	return (*app::GuardHash)[node] == nullptr;
}

app::app()
{
}


app::~app()
{
}

std::map<void *, void **>* app::GuardHash = new std::map<void *, void **>();

 app* app::_install = new app;
app* app::getinstance() 
{
	return app::_install;
}
