#ifndef PIECE_H
#define PIECE_H

#include <vector>

class Piece{
protected:
	struct Moves{
		int count;
		bool v, h, d;
		std::vector<std::pair<int,int> > sq;
		Moves();
	};
	Moves *mv;
	std::pair<int,int> loc;
public:
	Piece();
	~Piece();
	Piece(const Piece &piece);
	void setLocation(int x, int y);
	std::pair<int,int> getLocation();
	const Moves* getMoves();
};

class Pawn: public Piece{
public:
	Pawn();
};

class Rook: public Piece{
public:
	Rook();
};

class Bishop: public Piece{
public:
	Bishop();
};

class Queen: public Piece{
public:
	Queen();
};

class Knight: public Piece{
public:
	Knight();
};

class King: public Piece{
public:
	King();
};

#endif
