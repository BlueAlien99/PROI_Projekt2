#include "../include/Interface.h"

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
		x = xx;
		if(!x){
			x = 1;
		}
		y = yy;
		if(!y){
			y = 1;
		}
		board = new int [x*y] ();
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

	bool algorithm(){
		if(algoPlace<Pawn>(pawns, 0, 0) && algoPlace<Rook>(rooks, 0, 0)
		&& algoPlace<Bishop>(bishops, 0, 0) && algoPlace<Queen>(queens, 0, 0)
		&& algoPlace<Knight>(knights, 0, 0) && algoPlace<King>(kings, 0, 0)){
			printBoard();
			return 1;
		} else{
			cout<<endl<<"Placement impossible!"<<endl;
			return 0;
		}
	}

	template <class T>
	bool algoPlace(PieceInterface<T> *piece, uint xx, uint yy){
		for(uint i = yy*x + xx; i < x*y; ++i){
			uint ny = i/x;
			uint nx = i - x*ny;
			if(isSqFree(nx, ny) == -1){
				cout<<"algoPlace out of board: "<<nx<<' '<<ny;
				exit(EXIT_FAILURE);
			}
			if(!isSqFree(nx, ny)){
				continue;
			}
			//TODO place
			if(){

			}
			//TODO revert
			
		}
		return 0;
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

bool Interface::algorithm(){
	return impl->algorithm();
}

void Interface::printBoard(){
	impl->printBoard();
}
