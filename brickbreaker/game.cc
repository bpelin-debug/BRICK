#include "game.h"
#include "messages.h"
#include "constants.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;



void skip (ifstream& file){ // bunu getline ile
	char c;
	
	while (file >> ws and file.get(c)){ //ws ile bosluklari gectik,file.get karakter aldik
		if(c=="#"){
			string dummyline; //inspired by chat, useless string line
			getline(file, dummyline); // o an bulundugu satiri komple okuyo
			return;
		} else {
			file.putback(c);//aldigim karakteri geri koy
			return;
		}
	}
}


bool game::read_file(string filename){
	ifstream file(filename);
	if(filename.fail()) {return false;}
	
	int score;
	int lives;
	int nb_brick;
	int nb_balls;
	
	double paddle_x, paddle_y, paddle_r; // paddle radius
	
	Circle paddle_circle;
	vector<Square> brick_list;
	vector<Circle> ball_list;
	
	//score okumak 
	skip(file);
	file >> score;
	if(file.fail() and score < 0){
		cout << messages::invalid_score(score);
		return false;}
	
	skip(file);
	file >> lives;
	if(file.fail() and lives < 0){
		cout << messages::invalid_lives(lives);
		return false;}
	
	skip(file);
	file >> paddle_x >> paddle_y >> paddle_r;
	if(file.fail()){
		cout << messages::paddle_outside(paddle_x, paddle_y;
		return false;}
	paddle_circle.center = {paddle_x, paddle_y};
    paddle_circle.radius = paddle_r;

    /
    {
        double y = paddle_y;
        double r = paddle_r;

        if (y > 0.0 || y + r <= 0.0) {
            cout << message::paddle_outside(paddle_x, paddle_y);
            return false;
        }

        double dx = sqrt(r * r - y * y);
        double x_left  = paddle_x - dx;
        double x_right = paddle_x + dx;

        if (x_left < 0.0 || x_right > arena_size) {
            cout << message::paddle_outside(paddle_x, paddle_y);
            return false;
        }
    }
 
	
	skip(file);
	file >> nb_brick;
	if (file.fail() and nb_brick < 0) {return false;}
	
	for(int i(0); i < nb_brick; i++){
		int type;
		int o(0);
		double bx;
		double by;
		double size;
		
		skip(file);
		file >> type >> bx >> by >> size;
		if(file.fail()) {return false;}
		
		if(type == 0) {
			file >> 0;
			if (file.fail()){return false;}
		}
	}
		
	skip(file);
	file >> nb_balls;
	if(file.file() and nb_balls < 0) {return false;}
	
	for (int i = 0; i < nb_brick; ++i) {
        int type;
        int hit_p = 0;
        double bx, by, size;

        skip(file);
        file >> type >> bx >> by >> size;
        if (file.fail()) {
            return false;
        }

        if (type < 0 || type > 2) {
            cout << message::invalid_brick_type(type);
            return false;
        }

        if (size < brick_size_min) {
            cout << message::invalid_brick_size(size);
            return false;
        }

        if (type == 0) {
            file >> hit_p;
            if (file.fail() || hit_p < 1 || hit_p > 7) {
                cout << message::invalid_hit_points(hit_p);
                return false;
            }
        }

        Square s;
        s.center = {bx, by};
        s.length = size;

        // Brick arena içinde mi?
        {
            double half = size / 2.0;
            if (bx - half < 0.0 || bx + half > arena_size ||
                by - half < 0.0 || by + half > arena_size) {
                cout << message::brick_outside(bx, by);
                return false;
            }
        }

        // Paddle ile çakışıyor mu?
        if (intersect_cs(paddle_circle, s)) {
            cout << message::collision_paddle_brick(i);
            return false;
        }

        // Önceki brick'lerle çakışıyor mu?
        for (size_t j = 0; j < brick_list.size(); ++j) {
            if (intersect_ss(s, brick_list[j])) {
                cout << message::collision_bricks(j, i);
                return false;
            }
        }

        brick_list.push_back(s);

        // İstersen burada gerçek Brick nesneni de oluşturup saklayabilirsin:
        // TODO: Brick b(type, bx, by, size, hit_p);
        // TODO: bricks.push_back(b);
    }

    // ---------------- NUMBER OF BALLS ----------------
    skip(file);
    file >> nb_balls;
    if (file.fail() || nb_balls < 0) {
        return false;
    }

    // Arena karesi (ball include kontrolü için)
    Square arena;
    arena.center = {arena_size / 2.0, arena_size / 2.0};
    arena.length = arena_size;

    // ---------------- BALLS ----------------
    for (int i = 0; i < nb_balls; ++i) {
        double x, y, r, dx, dy;

        skip(file);
        file >> x >> y >> r >> dx >> dy;
        if (file.fail()) {
            return false;
        }

        Circle c;
        c.center = {x, y};
        c.radius = r;

        // Ball arena içinde mi?
        // Alt sınırda radius ignore ediliyor.
        if (x - r < 0.0 || x + r > arena_size || y + r > arena_size || y < 0.0) {
            cout << message::ball_outside(x, y);
            return false;
        }

        // Delta norm kontrolü
        if (sqrt(dx * dx + dy * dy) > delta_norm_max) {
            cout << message::invalid_delta(dx, dy);
            return false;
        }

        // Paddle ile çakışıyor mu?
        if (intersect_cc(c, paddle_circle)) {
            cout << message::collision_paddle_ball(i);
            return false;
        }

        // Brick'lerle çakışıyor mu?
        for (size_t j = 0; j < brick_list.size(); ++j) {
            if (intersect_cs(c, brick_list[j])) {
                cout << message::collision_ball_brick(i, j);
                return false;
            }
        }

        // Önceki ball'larla çakışıyor mu?
        for (size_t j = 0; j < ball_list.size(); ++j) {
            if (intersect_cc(c, ball_list[j])) {
                cout << message::collision_balls(j, i);
                return false;
            }
        }

        ball_list.push_back(c);

        // İstersen burada gerçek Ball nesneni de oluşturup saklayabilirsin:
        // TODO: Ball b(x, y, r, dx, dy);
        // TODO: balls.push_back(b);
    }

    file.close();
    cout << message::success();

    // ------------------------------
		
