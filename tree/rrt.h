#ifndef RRT_H
#define RRT_H

#include <vector>

class RRT
{
public:

    struct Coord
    {
        double x;
        double y;
    };
    
    struct Node
    {
        Coord coord;
        Node *parent;

        private:
            Node(const Coord& c, Node *p) : coord(c), parent(p) {}
            friend class RRT;
    };

    RRT(const Coord& c) 
    {
        Node *root = new Node(c, nullptr);
        tree.push_back(root);
    }

    ~RRT()
    {
        for (const auto& node : tree){
            delete node;
        }
    }

    void addNode(const Coord& coord, Node *parent)
    {
        Node *newNode = new Node(coord, parent);
        tree.push_back(newNode);
    }

    std::vector<Node*> nodes() const { return tree; }

    std::vector<Coord> tracePath(Node *start)
    {
        std::vector<Coord> path{};
        Node *current = start;

        while(current != nullptr){
            path.push_back(current->coord);
            current = current->parent;
        }

        return path;
    }


private:

    std::vector<Node*> tree;

};


#endif //RRT_H
