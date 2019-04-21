#include "../include/Interface.h"

#include "../include/Utilities.h"
#include "../include/PieceInterface.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Interface::InterfaceImpl{
	PieceInterface<Pawn> *pawns;
	PieceInterface<Rook> *rooks;
	PieceInterface<Bishop> *bishops;
	PieceInterface<Queen> *queens;
	PieceInterface<Knight> *knights;
	PieceInterface<King> *kings;
	int *board;
	uint x, y;
public:
	InterfaceImpl(uint xx, uint yy, uint pa, uint ro,
				uint bi, uint qu, uint kn, uint ki){
		pawns = new PieceInterface<Pawn>(pa);
		rooks = new PieceInterface<Rook>(ro);
		bishops = new PieceInterface<Bishop>(bi);
		queens = new PieceInterface<Queen>(qu);
		knights = new PieceInterface<Knight>(kn);
		kings = new PieceInterface<King>(ki);
		board = new int [xx*yy] ();
		x = xx;
		y = yy;
	}
	~InterfaceImpl(){
		delete pawns;
		delete rooks;
		delete bishops;
		delete queens;
		delete knights;
		delete kings;
		delete board;
	}
	int isSqFree(uint xx, uint yy){
		if(xx >= x || yy >= y){
			return -1;
		}
		else if(board[yy*x + xx] == 0){
			return 1;
		} else{
			return 0;
		}
	}
	void printBoard(){
		cout<<endl<<"  ";
		for(uint i = 0; i < x; ++i){
			cout<<i%10;
		}
		cout<<endl<<"  ";
		for(uint i = 0; i < x; ++i){
			cout<<'#';
		}
		for(uint i = 0; i < y; ++i){
			cout<<endl<<y%10<<'#';
			for(uint j = 0; j < x; ++j){
				if(board[i*x + j] >= 0){
					cout<<abs(board[i*x + j])%10;
				} else{
					switch(board[i*x + j]){
						case -10:
							cout<<'P';
							break;
						case -20:
							cout<<'R';
							break;
						case -30:
							cout<<'B';
							break;
						case -40:
							cout<<'Q';
							break;
						case -50:
							cout<<'N';
							break;
						case -60:
							cout<<'K';
							break;
						default:
							cout<<'x';
					}
				}
			}
		}
		cout<<endl;
	}
};

Interface::Interface(uint xx, uint yy, uint pa, uint ro,
					uint bi, uint qu, uint kn, uint ki){
	impl = unique_ptr<InterfaceImpl>(new InterfaceImpl(xx, yy, pa, ro,
													bi, qu, kn, ki));
}

int Interface::isSqFree(uint xx, uint yy){
	return impl->isSqFree(xx, yy);
}

void Interface::printBoard(){
	impl->printBoard();
}
