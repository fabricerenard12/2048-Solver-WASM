// Game class for the 2048 game logic
// Author: Fabrice Renard
// Date : 23 / 06 / 2023

#ifndef GAME_H
#define GAME_H

#include <bitset>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <random>
#include <QApplication>
#include <QDebug>
#include <QObject>
#include <vector>
// #include <gtest/gtest.h>

using Grid = uint64_t;
constexpr int GRID_SIZE = 4;
enum class Move { LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3 };

struct Compare {
	bool operator() (const int& a, const int& b) const {
		return a > b;
	}
};

class Game : public QObject {
	Q_OBJECT
public:
	Game();
	Game(const Game& other);
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();
	int getScore();
	Grid getGrid();
	void setGrid(Grid grid); //TODO: set as private
	int getGridSize();
	bool isGameOver();
	bool makeMove(Move move); // TODO: set as private

	friend bool operator==(const Game& left, const Game& right);
	friend std::ostream& operator<<(std::ostream& os, const Game& game);
    friend class GameTest_AddTileWorksCorrectly_Test;
    friend class GameTest_AddTileFailsWhenGridIsFull_Test;

public slots:
	void handleKeyPress(char key, Move bestMove, std::shared_ptr<Game> game);

private:
	bool merge();
	bool compress();
	void flip();
	void transpose();
	bool addTile();

	Grid grid_;
	int score_;
	std::random_device rd_;
	std::mt19937 gen_;

	// FRIEND_TEST(GameTest, AddTileWorksCorrectly);
	// FRIEND_TEST(GameTest, AddTileFailsWhenGridIsFull);
	// FRIEND_TEST(GameTest, MoveLeftWorks);
	// FRIEND_TEST(GameTest, MoveRightWorks);
	// FRIEND_TEST(GameTest, MoveUpWorks);
	// FRIEND_TEST(GameTest, MoveDownWorks);
	// FRIEND_TEST(GameTest, IsGameOver);
	// FRIEND_TEST(GameTest, ScoreCalculation);
	friend class GameWindow;
};

#endif // !GAME_H