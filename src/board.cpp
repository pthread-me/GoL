#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <board.hpp>
#include <print>
#include <stdexcept>
#include <vector>

GoL::Board::Board(size_t rows, size_t cols, size_t tile_dim):
	grid_rows(rows), 
	grid_cols(cols), 
	tile_dim(tile_dim),
	grid(grid_rows * grid_cols){
	

	for(size_t i=0; i< grid.size(); ++i){
		grid[i].cell = sf::RectangleShape({static_cast<float>(tile_dim), static_cast<float>(tile_dim)});
		grid[i].state = false;

		size_t x = (i%grid_cols) * tile_dim;
		size_t y = (i/grid_cols) * tile_dim;

		grid[i].cell.setPosition(sf::Vector2<float>(static_cast<float>(x), static_cast<float>(y)));
		grid[i].cell.setFillColor(sf::Color::Black);
		
	}
}


GoL::Board& GoL::Board::operator=(GoL::Board&& board){
	grid_rows = std::move(board.grid_rows);
	grid_cols = std::move(board.grid_cols);
	tile_dim  = std::move(board.tile_dim);
	grid = std::move(board.grid);

	return *this;
}

void GoL::Board::reset_board(){
	for(auto &e: grid){
		e.cell.setFillColor(sf::Color::Black);	
		e.state = false;
	}
}

void GoL::Board::toggle(size_t i){
	if(grid[i].cell.getFillColor() == sf::Color::White && grid[i].state == true){
		grid[i].cell.setFillColor(sf::Color::Black);
		grid[i].state = false;
	}else if(grid[i].cell.getFillColor() == sf::Color::Black && grid[i].state == false){
		grid[i].cell.setFillColor(sf::Color::White);
		grid[i].state = true;
	}else{
		throw std::runtime_error("Missmatched color and state");
	}
}

std::vector<size_t> GoL::Board::set_cells(){
	std::vector<size_t> set;
	for(size_t i=0; i<grid.size(); ++i){
		if(grid[i].cell.getFillColor() == sf::Color::White){
			set.push_back(i);
		}
	}

	return set;
}

void GoL::Board::update_board(std::vector<bool>& new_grid){
	assert(grid.size() == new_grid.size());

	for(size_t i=0; i<grid.size(); ++i){
		if(grid[i].state != new_grid[i]){
			toggle(i);
		}
	}
}
