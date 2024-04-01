#ifndef excep_flag
#define excep_flag

#include<iostream>
#include <string>

class MyException {
private:
	std::string message;

public:
	MyException(std::string str = { "Something went wrong" }) :message{ str } {	}

	virtual void what() {
		std::cout << message;
	}

	virtual ~MyException() = default;

};

class StringException :public MyException {

public:
	StringException(std::string str) :MyException{ str } {	}

};

class DateException :public MyException {

public:
	DateException(std::string str) :MyException{ str } {	}
};

class FileException :public MyException {

public:
	FileException(std::string str) :MyException{ str } {	}
};
#endif