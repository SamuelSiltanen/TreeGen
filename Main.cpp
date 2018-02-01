#include <cstdio>
#include <vector>

/*
    Tree parts:
    - segment
    - bud
*/

enum class Type
{
    Trunk,
    Branch,
    Root,
};

struct Segment
{
    Type    type;
    int     startVertex;
    int     endVertex;    
};

struct Bud
{
    bool    leaf;
    int     startVertex;
};

struct Vertex
{
    float   pos[3];
    float   thickness;
};

class Tree
{
    Tree();

    void grow(int years);
    void export(const char* objFileName);
private:
    void growYear();

    std::vector<Vertex>     vertexList;
    std::vector<Segment>    segmentList;
    std::vector<Bud>        budList;
}

int main(int argc, char** argv)
{
    Tree tree;
    
    tree.grow(15);
    
    tree.export("test.obj");

    return 0;
}
