#pragma once

#include "TreeTypes.hpp"
#include "ObjTypes.hpp"

#include <vector>

// Transforms an abstract representation of a tree into a visualizable object
class Visualizer
{
public:
	void visualize(const vege::Segment& segment, obj::Mesh& mesh) const;
	void visualize(const vege::Bud&	bud, obj::Mesh& mesh) const;
private:

};
