#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <print>
#include <vector>

#include <game.hpp>



int main(){
	std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();
	if(videoModes.empty()){
		std::println(stderr, "No video modes detected");
		exit(-1);
	}
	
	sf::RenderWindow window(videoModes[0], "GoL");
	GoL::Game game(window);
	
	if(window.isOpen()){
		game.draw(window);
		window.display();
	}


	while(window.isOpen()){
		if(!window.hasFocus())continue;
	
		window.handleEvents(
				std::bind(&GoL::Game::key_event, std::ref(game), std::placeholders::_1, std::ref(window)),
				std::bind(&GoL::Game::mouse_event, std::ref(game), std::placeholders::_1, std::ref(window)),
				std::bind(&GoL::Game::resize_event, std::ref(game), std::placeholders::_1, std::ref(window))
		);		
	}
	window.close();
}


