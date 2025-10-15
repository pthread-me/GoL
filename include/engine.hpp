#include <vector>

#ifndef ENGINE
#define ENGINE
namespace GoL {
class Engine{
	size_t const grid_cols;
	size_t const grid_rows;
	std::vector<std::vector<bool>> grids; // 2 grids
	bool g = false;	
		
	int set_neighboors(size_t, bool);

	public:
		Engine(std::vector<size_t>, size_t, size_t);
		std::vector<bool>* run();
};
}

#endif
