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

#ifndef _MAP2D_H_
#define _MAP2D_H_
#include <Node.h>
#include <vector>

class Map2d
{
private:
    int m_x_range;
    int m_y_range;
    Node m_start;
    Node m_goal;
    std::vector<std::vector<Node>> m_data;
    std::vector<Node> m_obs_nodes;
public:
    Map2d(/* args */);
    Map2d(int x_range, int y_range);
    NODETYPE get_type(int x, int y) {
        if(x >= m_x_range || y >= m_y_range) {
            return INVALID;
        }
    }
    Node get_start_node() {
        return m_start;
    }
    Node get_goal_node() {
        return m_goal;
    }
    void set_goal(int x, int y) {
        m_start = Node(x, y, GOAL);
        m_data[x][y].set_type(GOAL);
    }
    void set_start(int x, int y) {
        m_start = Node(x, y, START);
        m_data[x][y].set_type(START);
    }
    void set_node_paraent(int x, int y, std::shared_ptr<Node> node) {
        m_data[x][y].set_paraent(node);
    }
    void set_node_step(int x, int y, int step) {
        m_data[x][y].set_step(step);
    }
    int get_step(int x, int y) {
        return m_data[x][y].get_step();
    }
    Node get_node(int x, int y) {
        if(x >= m_x_range || x < 0 || y >= m_y_range || y < 0) {
            return Node(x,y, INVALID);
        }
        /*
        if(x == m_goal.x_pos() && y == m_goal.x_pos()) {
            type = GOAL;
        } 

        if(x == m_start.x_pos() && y == m_start.x_pos()) {
            type = START;
        } 
        for(auto it: m_obs_nodes) {
            if(it.x_pos() == x && it.y_pos() == y) {
                type = VALID;
            }
        }
        double priority = std::pow((x - m_goal.x_pos()),2) + std::pow((y - m_goal.y_pos()), 2);
        Node node(x, y, type,priority);
        */
        return m_data[x][y];
    }
    void show();

    ~Map2d();
};


#endif