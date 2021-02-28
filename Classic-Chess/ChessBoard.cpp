#include "ChessBoard.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>  

ChessBoard::ChessBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = ' ';
		}
	}

	// O - W Pawn
	// L - W Castle
	// M - W rooks
	// N - W Knight
	// K - W King
	// V - Queen


	// Setting the Pawns
	for (int i = 0; i < 8; i++) {
		board[i][1] = 'P';
		board[i][6] = 'O';
	}

	// Set the Castle ? idk I forgot the name
	board[0][0] = 'C';
	board[7][0] = 'C';
	board[7][7] = 'L';
	board[0][7] = 'L';

	// Set the rooks
	board[1][0] = 'R';
	board[6][0] = 'R';
	board[1][7] = 'M';
	board[6][7] = 'M';

	// Set the Knight
	board[2][0] = 'H';
	board[5][0] = 'H';
	board[2][7] = 'N';
	board[5][7] = 'N';

	// Set the King
	board[3][0] = 'K';
	board[4][7] = 'B';

	// Set the Queen
	board[4][0] = 'Q';
	board[3][7] = 'V';

	lightBrownSquare = al_load_bitmap("./pics\\square brown light_png_shadow_128px.png");
	darkBrownSquare = al_load_bitmap("./pics\\square brown dark_png_shadow_128px.png");

	wPawn = al_load_bitmap("./pics\\w_pawn_png_shadow_128px.png");
	bPawn = al_load_bitmap("./pics\\b_pawn_png_shadow_128px.png");

	wCastle = al_load_bitmap("./pics\\w_rook_png_shadow_128px.png");
	bCastle = al_load_bitmap("./pics\\b_rook_png_shadow_128px.png");

	wRook = al_load_bitmap("./pics\\w_bishop_png_shadow_128px.png");
	bRook = al_load_bitmap("./pics\\b_bishop_png_shadow_128px.png");

	wKnight = al_load_bitmap("./pics\\w_knight_png_shadow_128px.png");
	bKnight = al_load_bitmap("./pics\\b_knight_png_shadow_128px.png");

	wKing = al_load_bitmap("./pics\\w_king_png_shadow_128px.png");
	bKing = al_load_bitmap("./pics\\b_king_png_shadow_128px.png");

	wQueen = al_load_bitmap("./pics\\w_queen_png_shadow_128px.png");
	bQueen = al_load_bitmap("./pics\\b_queen_png_shadow_128px.png");
	

	//Masking - This is not the correct Mask color
	al_convert_mask_to_alpha(lightBrownSquare, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(darkBrownSquare, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(wPawn, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(bPawn, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(wCastle, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(bCastle, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(wRook, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(bRook, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(wKnight, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(bKnight, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(wKing, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(bKing, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(wQueen, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(bQueen, al_map_rgb(255, 0, 255));

}

ChessBoard::~ChessBoard()
{
	al_destroy_bitmap(lightBrownSquare);
	al_destroy_bitmap(darkBrownSquare);

	al_destroy_bitmap(wPawn);
	al_destroy_bitmap(bPawn);

	al_destroy_bitmap(wCastle);
	al_destroy_bitmap(bCastle);

	al_destroy_bitmap(wRook);
	al_destroy_bitmap(bRook);

	al_destroy_bitmap(wKnight);
	al_destroy_bitmap(bKnight);

	al_destroy_bitmap(wKing);
	al_destroy_bitmap(bKing);

	al_destroy_bitmap(wQueen);
	al_destroy_bitmap(bQueen);
}



int ChessBoard::GetXFromClick(float mouse_x)
{
	return 0;
}

int ChessBoard::GetYFromClick(float mouse_y)
{
	return 0;
}

void ChessBoard::DrawBoard()
{
	// Each pic is 128px 
	// need to draw a grid

	// Draw the background
	bool flipFlop = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (flipFlop) {
				al_draw_bitmap(lightBrownSquare, float((128*i)), float((128*j)), 0);
				flipFlop = false;
			}
			else {
				al_draw_bitmap(darkBrownSquare, float((128 * i)), float((128 * j)), 0);
				flipFlop = true;
			}
		}
		flipFlop = !flipFlop;
	}
	
	// Draw the pieces 
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (board[i][j]) 
			{
			case 'P':
				drawPieceAtSquare(bPawn, i, j);
break;
			case 'O':
				drawPieceAtSquare(wPawn, i, j);
				break;
			case 'C':
				drawPieceAtSquare(bCastle, i, j);
				break;
			case 'L':
				drawPieceAtSquare(wCastle, i, j);
				break;
			case 'R':
				drawPieceAtSquare(bRook, i, j);
				break;
			case 'M':
				drawPieceAtSquare(wRook, i, j);
				break;
			case 'H':
				drawPieceAtSquare(bKnight, i, j);
				break;
			case 'N':
				drawPieceAtSquare(wKnight, i, j);
				break;
			case 'K':
				drawPieceAtSquare(bKing, i, j);
				break;
			case 'B':
				drawPieceAtSquare(wKing, i, j);
				break;
			case 'Q':
				drawPieceAtSquare(bQueen, i, j);
				break;
			case 'V':
				drawPieceAtSquare(wQueen, i, j);
				break;

			}
		}
	}

	if (playerSelected) {
		al_draw_rectangle((playerLastClickedX * 128), (playerLastClickedY * 128), ((playerLastClickedX * 128) + 128), ((playerLastClickedY * 128) + 128), al_map_rgb(255, 0, 255), 5);
	}

	return;
}

void ChessBoard::drawPieceAtSquare(ALLEGRO_BITMAP* piece, int x, int y)
{
	float posX = x * 128;
	float posY = y * 128;

	al_draw_bitmap(piece, posX, posY, 0);
	return;
}

void ChessBoard::playerClicked(float x, float y)
{
	playerClickedX = int(floor(x / 128.f));
	playerClickedY = int(floor(y / 128.f));
	if (!playerSelected) {
		playerSelected = true;
		playerLastClickedX = int(floor(x / 128.f));
		playerLastClickedY = int(floor(y / 128.f));

		fprintf(stderr, "playerLastClickedX: %d playerLastClickedY: %d \n", playerLastClickedX, playerLastClickedY);

	}
	else if (isValidMove(board[playerLastClickedX][playerLastClickedY], playerClickedX, playerClickedY)) {

		board[playerClickedX][playerClickedY] = board[playerLastClickedX][playerLastClickedY];
		board[playerLastClickedX][playerLastClickedY] = ' ';

		fprintf(stderr, "check222\n");

		playerSelected = false;
	}
	else {
		fprintf(stderr, "playerClickedX: %d playerClickedY: %d \n", playerClickedX, playerClickedY);
		playerSelected = false;
	}
}

bool ChessBoard::isValidMove(char playerPiece, int playerX, int playerY)
{
	if (playerPiece == 'O') { // w pawn
		if (playerLastClickedY == 0) { // can't move off the board
			return false;
		}
		else if (playerLastClickedY <= playerY) { // can't move back 
			return false;
		}
		else if ((playerLastClickedY == (playerY + 1)) && (board[playerX][playerY] == ' ') &&
			(playerX == playerLastClickedX)) { // can move up one space
			return true;
		}
		else if (playerLastClickedY == 6) {
			if (board[playerX][playerY] == ' ') {
				if (board[playerX][playerY + 1] == ' ') {
					if (playerX == playerLastClickedX) {
						if (((playerY == 5) || (playerY == 4))) {
							fprintf(stderr, "check\n");
							return true;
						}
					}
				}
			}
		}

			
		
		//else if ((playerLastClickedY == 6) && (board[playerX][playerY] == ' ') && 
		//		(board[playerX][playerY + 1] == ' ') && (playerX = playerLastClickedX) &&
		//		((playerY == 5) || (playerY == 4))) { // starting move
		//	return true;
		//}

	}
	//else if (playerPiece == 'P') {

	//}
	//else {
	//	return false;
	//}

	return false;
}
