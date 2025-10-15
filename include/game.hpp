#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>


#include <board.hpp>
#include <engine.hpp>

#ifndef GAME
#define GAME
namespace GoL{ 
class Game{
	size_t const tile_dim = 16;
	size_t grid_rows;
	size_t grid_cols;
	Board board;

	size_t pixel_pos_to_tile_index(int x_pix, int y_pix);

	public:
		Game(sf::RenderWindow&);

		void key_event(const sf::Event::KeyPressed&, sf::RenderWindow&);
		void mouse_event(const sf::Event::MouseButtonPressed&, sf::RenderWindow&);
		void resize_event(const sf::Event::Resized&, sf::RenderWindow&);

		void start_game(sf::RenderWindow&);
		void draw(sf::RenderWindow&);
};
}
#endif
