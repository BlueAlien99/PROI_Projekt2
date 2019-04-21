#include "../include/Setup.h"

#include "../include/Utilities.h"

#include <memory>

using namespace std;

class Setup::SetupImpl{

public:

};

Setup::Setup(){
	impl = unique_ptr<SetupImpl>(new SetupImpl());
}
