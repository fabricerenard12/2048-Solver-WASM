// Monte Carlo methods to compute the best move at each state
// Author: Fabrice Renard
// Date : 23 / 06 / 2023

#ifndef MONTECARLO_H
#define MONTECARLO_H

// #include <vector>
// #include <thread>
// #include <mutex>
// #include <map>
// #include <random>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QVector>
#include <QMap>
#include <random>
#include "Game.hpp"

// Game move(Game game, Move move);

// void simulate(Game& game, std::mt19937& localGen, double& localScore);

Move performMC(Game game, int numberOfSimulationsPerMove);

#endif // !MONTECARLO_H