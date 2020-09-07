// Define a Group to be a container of Shapes with suitable operations applied to the various members of the Group.
// Hint: Vector_ref.Use a Group to define a checkers(draughts) board where pieces can be moved under program
// control.

#include "Simple_window.h"
#include "Graph.h"

namespace Graph_lib {
    
    enum class Dir {
        NE = 0, NW, SE, SW 
    };

    struct Group : public Shape {
    public:
        Group();
        void move_red(int i, Dir d);
        void move_black(int i, Dir d);
        void draw_lines() const override;

    private:
        Vector_ref<Circle> red;
        Vector_ref<Circle> black;
        Vector_ref<Rectangle> board;
    };

    Group::Group() {
        double size = 75;
        double window_size = 600;
        bool check{ false };


        // create board
        for (int i = 0; i < 8; i++) {
            check = !check;
            
            for (int j = 0; j < 8; j++) {
                board.push_back(new Rectangle{ Point{j*size, i*size}, size, size });
                
	    if (check) {
    		board[board.size() - 1].set_color(Color::black);
    		board[board.size() - 1].set_fill_color(Color::black);
    		check = !check;
	    }
	    else {
    		board[board.size() - 1].set_color(Color::white);
    		board[board.size() - 1].set_fill_color(Color::white);
    		check = !check;
	    }
        }

        // create red checkers
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == 1)
                    red.push_back(new Circle{ Point{ 2 * j * size + size / 2 + size, window_size - size / 2 - i * size }, 30 });
                else
                    red.push_back(new Circle{ Point{ 2 * j * size + size / 2, window_size - size / 2 - i * size }, 30 });
                red[red.size() - 1].set_color(Color::black);
                red[red.size() - 1].set_fill_color(Color::red);
            }
        }

        // create black checkers
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == 1)
                    black.push_back(new Circle{ Point{ 2 * j * size + size / 2 + size, size / 2 + i * size }, 30 });
                else
                    black.push_back(new Circle{ Point{ 2 * j * size + size / 2, size / 2 + i * size }, 30 });
                black[black.size() - 1].set_color(Color::red);
                black[black.size() - 1].set_fill_color(Color::black);
            }
        }
    }

    void Group::move_red(int i, Dir d) {
        int size = board[0].width();

        switch (d) {
        case Dir::NE:
            red[i].move(size, -size);
            break;
        case Dir::NW:
            red[i].move(-size, -size);
            break;
        case Dir::SE:
            red[i].move(size, size);
            break;
        case Dir::SW:
            red[i].move(-size, size);
            break;
        default:
            break;
        }
    }

    void Group::move_black(int i, Dir d) {
        int size = board[0].width();

        switch (d) {
        case Dir::NE:
            black[i].move(size, -size);
            break;
        case Dir::NW:
            black[i].move(-size, -size);
            break;
        case Dir::SE:
            black[i].move(size, size);
            break;
        case Dir::SW:
            black[i].move(-size, size);
            break;
        default:
            break;
        }
    }

    void Group::draw_lines() const {
        for (int i = 0; i < board.size(); i++) {
            board[i].draw_lines();
        }
        for (int i = 0; i < red.size(); i++) {
            red[i].draw_lines();
        }
        for (int i = 0; i < black.size(); i++) {
            black[i].draw_lines();
        }
    }
}


int main()
try {
    Graph_lib::Simple_window win{ Graph_lib::Point{100,0}, 600, 600, "Excersise 9" };

    Graph_lib::Group game;

    for (int i = 0; i < 8; i++) {
        win.attach(game);
        win.wait_for_button();
        game.move_black(11, Graph_lib::Dir::SW);
    }

    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
