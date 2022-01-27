#include <Draw.h>
#include <Node.h>
#include <opencv2/opencv.hpp>
#include <Env.h>
#include <queue>
#include <Map2d.h>
#include <Search2d/AStar2D.h>

int main() {
    Env env;
    env.Render();
    std::set<std::pair<int,int>> points;
    for(int i = 2;i < 10;i++) {
        for(int j = 2;j<10;j++) {
            points.insert({i,j});
        }
    }
    std::vector<std::pair<int,int>> path;
    for(int i = 2;i < 10;i++) {
        path.push_back({i,i});
    }
    env.SetVisitedPoint(points);
    env.SetWayPath(path);
    // env.animation();

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> que;
    for(int i = 10;i > 0;i--) {
        Node node(1,2,INVALID, i);
        que.push(node);
    }
    while(!que.empty()) {
        auto node = que.top();
        node.print();
        que.pop();
    }
    
    Map2d m(51, 31);
    m.set_goal(40,20);
    m.set_start(2,5);

    m.show();
    AStar2D astar;
    astar.SetMap(m);
    bool status = astar.solver();
    std::cout << "solver result: " << status << std::endl;
    auto result = astar.get_result();
    result.show();
    

    cv::waitKey(0);
    return 0;
}