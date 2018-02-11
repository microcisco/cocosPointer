#include "Node.h"



Node::Node()
{
}


Node::~Node()
{
	app::getinstance()->removeGuard(this);

}

void Node::setText(std::string str)
{
	std::cout << "ÉèÖÃ±êÌâ";
}

