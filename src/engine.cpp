#include<engine.hpp>
#include <print>
#include <vector>

GoL::Engine::Engine(std::vector<size_t> init, size_t x, size_t y):
	grid_cols(x), grid_rows(y),
	grids(std::vector<std::vector<bool>>(
				{std::vector<bool>(x*y), std::vector<bool>(x*y)}))
{
	for(size_t e: init) grids[g][e] = true;
}


int GoL::Engine::set_neighboors(size_t i, bool c){
	int res = 0;
	if(i>grid_cols){
		if(i-1%grid_cols >0) res += grids[c][i-grid_cols-1];
		res += grids[c][i-grid_cols];
		if( (i+1)%grid_cols >0) res += grids[c][i-grid_cols+1];
	}
	
	if(i>0 && (i-1)%grid_cols >0) res += grids[c][i-1];
	if((i+1>0) && (i+1)%grid_cols >0) res += grids[c][i+1];
	

	if(i<(grid_cols*(grid_rows-1))){
		if(i>0 && (i-1)%grid_cols >0) res += grids[c][i+grid_cols-1];
		res += grids[c][i+grid_cols];
		if((i+1>0) && (i+1)%grid_cols >0) res += grids[c][i+grid_cols+1];
	}
	
	
	return res;

}

std::vector<bool>* GoL::Engine::run(){
	size_t changed = 0;
	
	for(size_t i=0; i<grids[g].size(); ++i){
		int neighboors = set_neighboors(i, g);
		if(grids[g][i] == false){
			if(neighboors==3){
				grids[!g][i] = true;
				changed++;
			}else{
				grids[!g][i] = false;
			}
		}else if(grids[g][i] == true){
			if(neighboors<2 || neighboors>3){
				grids[!g][i] = false;
				changed ++;
			}else{
				grids[!g][i] = true;
			}
		}
	}
	
	g = !g;
	return changed > 0? &grids[g]: nullptr;
}
