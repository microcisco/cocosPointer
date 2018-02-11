#pragma once
#include<map>

class app
{
private:
	app();
public:

	~app();

	void addGuard(void **);
	void removeGuard(void *);
	bool isNumm(void *);

	
	static std::map<void *, void **>* GuardHash;

	static app* _install;
	static app* getinstance();
};

