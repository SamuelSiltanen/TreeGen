#pragma once

// Using namespace to separate abstract data from 3D-object data
namespace vege
{
	/*
	Tree parts:
	- segment
	- bud
	*/

	enum class Type
	{
		Undefined,
		Trunk,
		Branch,
		Root,
	};

	struct Segment
	{
		Type    type;
		int     startVertex;
		int     endVertex;

		Segment() :
			type(Type::Undefined),
			startVertex(-1),
			endVertex(-1)
		{}

		Segment(Type type, int startVertex, int endVertex) :
			type(type),
			startVertex(startVertex),
			endVertex(endVertex)
		{}
	};

	struct Bud
	{
		bool    leaf;
		int     vertex;

		Bud() :
			leaf(false),
			vertex(-1)
		{}

		Bud(bool leaf, int vertex) :
			leaf(leaf),
			vertex(vertex)
		{}
	};

	struct Vertex
	{
		float   pos[3];
		float   thickness;
	};
}
