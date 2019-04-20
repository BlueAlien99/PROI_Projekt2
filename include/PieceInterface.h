#ifndef PIECEINTERFACE_H
#define PIECEINTERFACE_H

#include "Piece.h"

#include <cstdlib>
#include <vector>

template <class T>
class PieceInterface{
	std::vector<T*> pieces;
public:
	PieceInterface(int n = 0);
	~PieceInterface();
	void setLocation(uint n, int x, int y);
	std::pair<int,int> getLocation(uint n);
	const Piece::Moves* getMoves();
	int getCount();
};

#endif
