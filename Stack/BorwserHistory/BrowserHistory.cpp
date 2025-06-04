#include "BrowserHistory.h"
#include<iostream>
using namespace std;
int main()
{
	BrowserHistory<string> obj;
	obj.visit("google.com");
	obj.visit("wikipedia.com");
	obj.visit("youtube.com");
	obj.goBack();
	obj.goBack();
	obj.goForward();
}