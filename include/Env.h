// Copyright 2022 Zhu Yongkang
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _ENV_H_
#define _ENV_H_
#include <set>
#include <map>
#include <vector>
#include <opencv2/opencv.hpp>

class Env
{
private:
    int m_x_range = 51;
    int m_y_range = 31;
    int m_cell_size = 5;
    cv::Mat m_img;
    std::set<std::pair<int,int>> m_obs_points;
    std::vector<std::pair<int,int>> m_waypoints;
    std::set<std::pair<int,int>> m_visited_points;
    std::pair<int, int> m_start_point{ 5,31 - 6};
    std::pair<int, int> m_end_point{45,5};
public:
    Env(int x_range = 51, int y_range = 31, int cell_size = 10);
    bool Render();
    bool SetVisitedPoint(std::set<std::pair<int,int>> points) {
        m_visited_points = points;
        return true;
    }
    bool SetWayPath(std::vector<std::pair<int,int>> points) {
        m_waypoints = points;
        return true;
    }
    cv::Mat GetMat() {
        return m_img;
    }
    bool animation();
    ~Env();
};

#endif