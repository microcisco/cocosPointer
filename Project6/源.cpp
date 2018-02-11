#include<iostream>
#include"app.h"
#include"AutoPoint.h"
#include"Node.h"


void main()
{
	Node* node = new Node;
	AutoPoint<Node> p(node);
	delete node;

	if (!p.isNull()) 
	{
		p->setText("title");
	}
	
	system("pause");
}