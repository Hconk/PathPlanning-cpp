#include <Draw.h>
#include <opencv2/opencv.hpp>
#include <Env.h>

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
    env.animation();
    cv::waitKey(0);
    return 0;
}