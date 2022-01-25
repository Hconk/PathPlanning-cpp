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

#include <Env.h>


Env::Env(int x_range, int y_range, int cell_size): m_x_range(x_range), m_y_range(y_range),m_cell_size(cell_size)
{
    m_img = cv::Mat(m_y_range*m_cell_size, m_x_range*m_cell_size, CV_8UC3, cv::Scalar(255,255,255));
    for(int i = 0;i < m_x_range;i++) {
        m_obs_points.insert(std::pair(i, 0));
        m_obs_points.insert(std::pair(i, m_y_range-1));
    }

    for(int i = 0;i < m_y_range;i++) {
        m_obs_points.insert(std::pair(0, i));
        m_obs_points.insert(std::pair(m_x_range-1, i));
    }
    for(int i = 10;i < 21;i++) {
        m_obs_points.insert(std::pair(i, 15));
    }

    for(int i = 15;i < 30;i++) {
        m_obs_points.insert(std::pair(30, m_y_range - i - 1));
    }

    for(int i = 0;i < 15;i++) {
        m_obs_points.insert(std::pair(20, m_y_range - i - 1));
    }
    for(int i = 0;i < 16;i++) {
        m_obs_points.insert(std::pair(40, m_y_range - i - 1));
    }

}

Env::~Env()
{
}

bool Env::Render()
{
    m_img = cv::Mat(m_y_range*m_cell_size, m_x_range*m_cell_size, CV_8UC3, cv::Scalar(255,255,255));
    for(int i = 0;i < m_x_range;i++) {
        cv::line(m_img, cv::Point2d(i * m_cell_size, 0), cv::Point2d(i * m_cell_size, m_y_range*m_cell_size), (220,220,220), 1);
    }

    for(int i = 0;i < m_y_range;i++) {
        cv::line(m_img, cv::Point2d(0, i * m_cell_size), cv::Point2d(m_x_range * m_cell_size, i * m_cell_size), (220,220,220), 1);
    }

    for(auto point: m_obs_points) {
        cv::rectangle(m_img, cv::Rect2d(point.first * m_cell_size, point.second*m_cell_size, m_cell_size, m_cell_size), (0,0,0), -1);

    }

    cv::rectangle(m_img, cv::Rect2d(m_start_point.first * m_cell_size, m_start_point.second*m_cell_size, m_cell_size, m_cell_size), cv::Scalar(0,0,255), -1);
    cv::rectangle(m_img, cv::Rect2d(m_end_point.first * m_cell_size, m_end_point.second*m_cell_size, m_cell_size, m_cell_size), cv::Scalar(255,0,0), -1);
    for(auto point: m_visited_points) {
        cv::rectangle(m_img, cv::Rect2d(point.first * m_cell_size, point.second*m_cell_size, m_cell_size, m_cell_size), cv::Scalar(210,210,210), -1);

    }

    return true;
}