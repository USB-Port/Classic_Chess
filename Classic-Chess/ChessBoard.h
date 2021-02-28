#pragma once
#include "allegro5\allegro.h"

class ChessBoard
{
private:

	ALLEGRO_BITMAP* lightBrownSquare;
	ALLEGRO_BITMAP* darkBrownSquare;

	ALLEGRO_BITMAP* wPawn;
	ALLEGRO_BITMAP* bPawn;

	ALLEGRO_BITMAP* wCastle;
	ALLEGRO_BITMAP* bCastle;

	ALLEGRO_BITMAP* wRook;
	ALLEGRO_BITMAP* bRook;

	ALLEGRO_BITMAP* wKnight;
	ALLEGRO_BITMAP* bKnight;

	ALLEGRO_BITMAP* wKing;
	ALLEGRO_BITMAP* bKing;

	ALLEGRO_BITMAP* wQueen;
	ALLEGRO_BITMAP* bQueen;

	int playerClickedX = -1;
	int playerClickedY = -1;

	int playerLastClickedX = -1;
	int playerLastClickedY = -1;

	bool playerSelected = false;

	char board[8][8];

public:

	ChessBoard();
	~ChessBoard();

	int GetXFromClick(float mouse_x);
	int GetYFromClick(float mouse_y);

	void DrawBoard();
	 
	void drawPieceAtSquare(ALLEGRO_BITMAP* piece, int x, int y);
	void playerClicked(float x, float y);

	bool isValidMove(char playerPiece, int playerX, int playerY);
};