#ifndef __PLAYEXCEPTION_H__
#define __PLAYEXCEPTION_H__

#include<exception>
using namespace std;


struct KartuDisabledException : public exception  {
	const char* what() const throw() {
		return "LOL kena disabled";
	}
};


#endif