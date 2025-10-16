#include <print>
#include <chrono>
#include <thread>
#include <vector>

#include <game.hpp>

GoL::Game::Game(sf::RenderWindow& win):
	grid_rows(win.getSize().y/tile_dim), 
	grid_cols(win.getSize().x/tile_dim), 
	board(grid_rows, grid_cols, tile_dim)
{

	std::println("grid dimensions: {}x{}", grid_rows, grid_cols);

}

size_t GoL::Game::pixel_pos_to_tile_index(int x_pix, int y_pix){
	size_t x = static_cast<size_t>(x_pix) / tile_dim;
	size_t y = static_cast<size_t>(y_pix) / tile_dim;

	return (grid_cols*y) + x;
}

void GoL::Game::draw(sf::RenderWindow& win){
	for(auto &e : board.grid) win.draw(e.cell);
}

void GoL::Game::start_game(sf::RenderWindow& win){
	std::chrono::milliseconds wait_time(100);
	std::vector<size_t> set_cells = board.set_cells();
	Engine runner(set_cells, grid_cols, grid_rows);
	std::vector<bool> *update;

	bool quit = false;



	while(win.isOpen()){
		update = runner.run();
		win.handleEvents([&](const sf::Event::KeyPressed& key){
			if(key.code == sf::Keyboard::Key::Q){
				std::println("pause");
				quit = true;
			}else if(key.code == sf::Keyboard::Key::Escape){
				quit = true;
				win.close();
			}	
		});

		if(quit || update == nullptr){ 
			break;
		}

		board.update_board(*update);		
		draw(win);
		win.display();
		std::this_thread::sleep_for(wait_time);
	}
}


//-------------------------------------------------------
//					Event Handlers
//-------------------------------------------------------
void GoL::Game::key_event(const sf::Event::KeyPressed& key, sf::RenderWindow& win){
	switch (key.code) {
		case sf::Keyboard::Key::Enter:
			std::println("start");
			start_game(win);
			break;

		case sf::Keyboard::Key::R:
			std::println("reset");
			board.reset_board();
			break;
		
		case sf::Keyboard::Key::Escape:
			win.close();
		default:
			break;
	}
	
	draw(win);	
	win.display();
}


void GoL::Game::mouse_event(const sf::Event::MouseButtonPressed& key, sf::RenderWindow& win){
	if(key.button != sf::Mouse::Button::Left) return;
	board.toggle(pixel_pos_to_tile_index(key.position.x, key.position.y));
	
	draw(win);
	win.display();
}


void GoL::Game::resize_event(const sf::Event::Resized& new_size, sf::RenderWindow& win){
	std::println("resize");
	win.setSize(new_size.size);

	size_t x = win.getSize().x;
	size_t y = win.getSize().y;

	grid_rows = y/tile_dim; 
	grid_cols = x/tile_dim;
	board = GoL::Board(grid_rows, grid_cols, tile_dim);
	
	draw(win);
	win.display();
}
