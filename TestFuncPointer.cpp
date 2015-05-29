// TestFuncPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>  
#include <stdio.h>  

//////////////////////////////////////////////////////////////////////////
typedef void (*PFunc)(int);

void RegesterFunc(PFunc pf)
{
	pf(1);
}

//////////////////////////////////////////////////////////////////////////
template <typename T,typename F>  
T supercast(F f)
{
	union FT  
	{  
		T   t;  
		F   f;  
	};
	FT ft;
	ft.f = f;
	return ft.t; //此为技巧，利用联合将地址返回。
}

class Apple
{  
public:  
	Apple(std::string color) : color_(color){}  

	void what(int i)   
	{  
		printf("this is a  apple!\n");  
		//printf("this is a %s apple!\n", color_.c_str());  
	}  

private:  
	std::string   color_;
};

int _tmain(int argc, _TCHAR* argv[])
{
	typedef void(what_t)(Apple*);

	what_t* what_apple = supercast<what_t*>(&Apple::what);  
	
	Apple red_apple("red");
	
	what_apple(&red_apple);

	//RegesterFunc(PFunc,1);
	
	return 0;
}
