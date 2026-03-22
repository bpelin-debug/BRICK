#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "brick.h"
#include "ball.h"
#include "paddle.h"

namespace game {
	bool read_file(std::string filename);
	void clear();
}
#endif

