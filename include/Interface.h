#ifndef INTERFACE_H
#define INTERFACE_H

#include <memory>

class Interface{
	class InterfaceImpl;
	std::unique_ptr<InterfaceImpl> impl;
public:
	
};

#endif
