#include "../include/Interface.h"
#include "../include/Tests.h"
#include "../include/PieceInterface.h"

#include <iostream>
#include <vector>

using namespace std;

int main(){
	//King king;
	//King king1(king);

	//PieceInterface<King> *test = new PieceInterface<King>(5);
	//Interface inter(4, 8, 1, 2, 3, 4, 5, 6);
	//inter.printBoard();
	//PieceInterface<King>tee(5);

	//PieceInterface<Rook>teest(5);
	//cout<<teest.moveChar()<<endl;
	//cout<<tee.moveSquares().size();

	Interface in(4,4,4);
	in.algorithm();

	//Interface *inter = new Interface(4, 8, 1, 2, 3, 4, 5, 6);
	//inter->printBoard();

	return 0;
}
