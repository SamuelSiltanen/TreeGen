#pragma once

#include <vector>

namespace obj
{
	struct Vertex
	{
		float pos[3];
		float uv[2];
		float norm[3];
	};

	struct Triangle
	{
		int index[3];
	};

	struct Mesh
	{
		std::vector<Vertex>		vertices;
		std::vector<Triangle>	triangles;
	};
}
