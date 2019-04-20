#include "../include/PieceInterface.h"

#include "../include/Piece.h"

#include <cstdlib>
#include <vector>

using namespace std;

template <class T>
PieceInterface<T>::PieceInterface(int n){
	if(n > 0){
		pieces.push_back(new T);
	}
	while(--n > 0){
		pieces.push_back(new T(pieces[0]));
	}
}

template <class T>
PieceInterface<T>::~PieceInterface(){
	while(pieces.size()){
		delete pieces.back();
		pieces.pop_back();
	}
}

template <class T>
PieceInterface<T>::PieceInterface(const PieceInterface &pint){

}

template <class T>
PieceInterface<T>& PieceInterface<T>::operator=(const PieceInterface &pint){

}

template <class T>
void PieceInterface<T>::setLocation(uint n, int x, int y){
	if(n < pieces.size()){
		pieces[n]->setLocation(x, y);
	}
}

template <class T>
pair<int,int> PieceInterface<T>::getLocation(uint n){
	if(n < pieces.size()){
		return pieces[n]->getLocation();
	}
	return make_pair(-2, -2);
}

template <class T>
const Piece::Moves* PieceInterface<T>::getMoves(){
	if(pieces.size() > 0){
		return pieces[0]->getMoves();
	}
	return NULL;
}

template <class T>
int PieceInterface<T>::getCount(){
	return pieces.size();
}