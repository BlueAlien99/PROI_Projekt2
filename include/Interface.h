#ifndef INTERFACE_H
#define INTERFACE_H

#include <memory>

class Interface{
	class InterfaceImpl;
	std::unique_ptr<InterfaceImpl> impl;
public:
	Interface(uint xx, uint yy, uint pa, uint ro,
			uint bi, uint qu, uint kn, uint ki);
	int isSqFree(uint xx, uint yy);
	void printBoard();
};

#endif
