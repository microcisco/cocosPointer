#cocos智能指针
* 设计目的
>解决父节点被移除后子节点被自动销毁，子节点不知道自己被销毁导致的野指针调用问题
* 设计灵感
````
最初的想法是来自oc的respondsToSelector方法
oc中判断对象是否有某个方法可以这么写[object respondsToSelector:@selector(method:)]
具体的实现思路来自QT中的QPointer类
QPointer是一个模板类。它很类似一个普通的指针，不同之处在于，QPointer 可以监视动态分配空间的对象，并且在对象被 delete 的时候及时更新。
````
* 设计思路
AutoPoint中有一个Node成员变量(构造时传过来)，然后把这个成员变量的地址(双指针)给全局变量管理。
然后再Node析构时调用removeGuard把全局变量中对应的那个双指针变为nullptr,因为是双指针所以AutoPoint
中的指针就变成nullptr了，然后就可以直接判断是否存在了。
````
* 示例代码
```
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
```