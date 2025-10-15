#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>

#ifndef BOARD
#define BOARD
namespace GoL {
typedef struct{
	sf::RectangleShape cell;
	bool state;
} Cell;

class Board{
		size_t  grid_rows;
		size_t  grid_cols;
		size_t  tile_dim; 
	
	public:
		std::vector<Cell> grid;

		Board(size_t,size_t,size_t);
		
		Board(Board&&);
		Board& operator=(Board&&);
		
		void reset_board();
		void toggle(size_t);
		std::vector<size_t> set_cells();
		void update_board(std::vector<bool>&);
};
}

#endif
