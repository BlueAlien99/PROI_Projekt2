#include "../include/Interface.h"

#include "../include/Utilities.h"
#include "../include/PieceInterface.h"

#include <cstdlib>
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
	int x, y;
public:
	InterfaceImpl(uint xx, uint yy, uint pa, uint ro,
				uint bi, uint qu, uint kn, uint ki){
		pawns = new PieceInterface<Pawn>(pa);
		rooks = new PieceInterface<Rook>(ro);
		bishops = new PieceInterface<Bishop>(bi);
		queens = new PieceInterface<Queen>(qu);
		knights = new PieceInterface<Knight>(kn);
		kings = new PieceInterface<King>(ki);
		board = new int [xx*yy];
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
};

Interface::Interface(uint xx, uint yy, uint pa, uint ro,
					uint bi, uint qu, uint kn, uint ki){
	impl = unique_ptr<InterfaceImpl>(new InterfaceImpl(xx, yy, pa, ro,
													bi, qu, kn, ki));
}
