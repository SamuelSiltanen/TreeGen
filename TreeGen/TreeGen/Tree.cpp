#include "Tree.hpp"
#include "Visualizer.hpp"

#include <cstdio>

Tree::Tree()
{
	// The origin is at the root of the tree
	vege::Vertex seedVertex;
	seedVertex.pos[0] = 0.f;
	seedVertex.pos[1] = 0.f;
	seedVertex.pos[2] = 0.f;
	seedVertex.thickness = 0.f;

	int index = static_cast<int>(m_vertexList.size());
	m_vertexList.emplace_back(seedVertex);

	// Create the first buds in both directions, like first shoots from a seed
	vege::Bud leafBud(true, index);
	vege::Bud rootBud(false, index);

	m_budList.emplace_back(leafBud);
	m_budList.emplace_back(rootBud);
}

bool Tree::exportObj(const Visualizer& visualizer, const char* objFileName)
{
	FILE* f = fopen(objFileName, "wb");
	if (!f)
	{
		printf("Export failed: Cannot open file %s for writing", objFileName);
		return false;
	}

	obj::Mesh mesh;
	constructMesh(visualizer, mesh);

	// Write Vertices
	fprintf(f, "# List of vertex positions\n");
	for (const auto& v : mesh.vertices)
	{
		fprintf(f, "v %f %f %f\n", v.pos[0], v.pos[1], v.pos[2]);
	}

	// Write UVs
	fprintf(f, "# List of vertex texture coordinates (UV)\n");
	for (const auto& v : mesh.vertices)
	{
		fprintf(f, "vt %f %f\n", v.uv[0], v.uv[1]);
	}

	// Write Vertex Normals
	fprintf(f, "# List of vertex normals\n");
	for (const auto& v : mesh.vertices)
	{
		fprintf(f, "vn %f %f %f\n", v.pos[0], v.pos[1], v.pos[2]);
	}

	// Write Polygons
	fprintf(f, "# List of polygons (only triangles in this case)\n");
	for (const auto& t : mesh.triangles)
	{
		fprintf(f, "f");
		for (int i = 0; i < 3; i++)
		{
			fprintf(f, " %d/%d/%d", t.index[i], t.index[i], t.index[i]);
		}
		fprintf(f, "\n");
	}

	fclose(f);
}

void Tree::grow(int years)
{
	for (int i = 0; i < years; i++)
	{
		growYear();
	}
}

void Tree::constructMesh(const Visualizer& visualizer, obj::Mesh& mesh)
{
	for (const auto& s : m_segmentList)
	{
		visualizer.visualize(s, mesh);
	}

	for (const auto& b : m_budList)
	{
		visualizer.visualize(b, mesh);
	}
}

void Tree::growYear()
{
	// TODO
}