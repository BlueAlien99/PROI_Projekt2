#include "../include/Setup.h"

#include "../include/Utilities.h"
#include "../include/Interface.h"

#include <iostream>
#include <memory>

using namespace std;

class Setup::SetupImpl{
	Interface *interface;

public:

	SetupImpl(){
		interface = NULL;
	}

	~SetupImpl(){
		delete interface;
	}

	void help(){
		cout<<endl;
		cout<<"----  MENU  ----"<<endl;
		cout<<"1 - Create new board"<<endl;
		cout<<"2 - Run algorithm"<<endl;
		cout<<"0 - Exit"<<endl;
	}

	void run(){
		uint menu = 1;
		while(menu){
			cout<<endl<<"Back to menu..."<<endl;
			switch((menu = Utilities::get_uint())){
				case 1:
					newBoard();
					break;
				case 2:
					algorithm();
					break;
				case 0:
					cout<<"Exiting..."<<endl;
					break;
				default:
					cout<<"Not available!"<<endl;
					break;
			}
		}
	}

	void newBoard(){
		cout<<endl<<"Enter following info:";
		cout<<endl<<"Width Height Pawns Rooks Bishops Queens Knights Kings"<<endl;
		uint x = Utilities::get_uint();
		uint y = Utilities::get_uint();
		uint pa = Utilities::get_uint();
		uint ro = Utilities::get_uint();
		uint bi = Utilities::get_uint();
		uint qu = Utilities::get_uint();
		uint kn = Utilities::get_uint();
		uint ki = Utilities::get_uint();
		cout<<endl;
		cout<<"Width   = "<<x<<endl;
		cout<<"Height  = "<<y<<endl;
		cout<<"Pawns   = "<<pa<<endl;
		cout<<"Rooks   = "<<ro<<endl;
		cout<<"Bishops = "<<bi<<endl;
		cout<<"Queens  = "<<qu<<endl;
		cout<<"Knights = "<<kn<<endl;
		cout<<"Kings   = "<<ki<<endl;
		interface = new Interface(x, y, pa, ro, bi, qu, kn, ki);
	}

	void algorithm(){
		if(interface){
			interface->algorithm();
		} else{
			cout<<endl<<"Board has not been initialized!"<<endl;
		}
	}
};

Setup::Setup(){
	impl = unique_ptr<SetupImpl>(new SetupImpl());
}

Setup::~Setup() = default;

void Setup::help(){
	impl->help();
}

void Setup::run(){
	impl->run();
}

void Setup::newBoard(){
	impl->newBoard();
}

void Setup::algorithm(){
	impl->algorithm();
}
