#pragma once

#include "TreeTypes.hpp"
#include "Visualizer.hpp"

#include <vector>

class Tree
{
public:
	Tree();

	void grow(int years);
	bool exportObj(const Visualizer& visualizer, const char* objFileName);
private:
	void growYear();
	void constructMesh(const Visualizer& visualizer, obj::Mesh& mesh);

	std::vector<vege::Vertex>     m_vertexList;
	std::vector<vege::Segment>    m_segmentList;
	std::vector<vege::Bud>        m_budList;
};
