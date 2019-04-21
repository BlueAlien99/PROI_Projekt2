#ifndef SETUP_H
#define SETUP_H

#include <memory>

class Setup{
	class SetupImpl;
	std::unique_ptr<SetupImpl> impl;
public:
	Setup();
};

#endif
