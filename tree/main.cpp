#include <iostream>
#include <random>
#include <cmath>
#include "rrt.h"

constexpr int Width{ 800 };
constexpr int Height{ 600 };
constexpr int StepSize{ 10 };

RRT::Coord sample()
{

    static std::mt19937 mt { std::random_device{}() };
    std::uniform_int_distribution x {0, Width};
    std::uniform_int_distribution y {0, Height};

    return {static_cast<double>(x(mt)), static_cast<double>(y(mt))};
}

double euclidianDistance(const RRT::Coord& p, const RRT::Coord& q)
{
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

RRT::Node* nearest(RRT tree, RRT::Node *newNode)
{
    double min { sqrt(Height * Height + Width * Width) };
    RRT::Node *near = tree.nodes()[0];

    for (const auto& node : tree.nodes()){
        double distance { euclidianDistance(node->coord, newNode->coord) };
        if (distance < min) {
            min = distance;
            near = node;
        }    
    }

    return  near;
}

RRT::Coord steer(const RRT::Coord& target, const RRT::Coord& start)
{
    double dx { target.x - start.x };
    double dy { target.y - start.y };

    double length { sqrt(dx * dx + dy * dy) };

    double stepDx { StepSize * (dx/length) };
    double stepDy { StepSize * (dy/length) };

    std::cout << "STEPDX: " << stepDx << std::endl;
    std::cout << "STEPDY: " << stepDy << std::endl;

    return {start.x + stepDx, start.y + stepDy };
}



int main()
{

    RRT rrt({0.0,0.0});
    rrt.addNode({1.0,2.0}, rrt.nodes()[0]);

    steer({500, 500}, {0,0});


    std::cout << "Hello, World!\n";
    return 0;
}
