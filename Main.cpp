#include <cstdio>

#include "TreeGen\TreeGen\Tree.hpp"


int main(int argc, char** argv)
{
    Tree tree;
	Visualizer visualizer;
    
    tree.grow(15);
    
	if (!tree.exportObj(visualizer, "test.obj"))
	{
		return -1;
	}

    return 0;
}
