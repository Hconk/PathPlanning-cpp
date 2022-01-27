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

#include <Search2d/AStar2D.h>

AStar2D::AStar2D(/* args */)
{
}

AStar2D::~AStar2D()
{
}

bool AStar2D::solver()
{
    Node start_node = m_map.get_start_node();
    Node goal_node = m_map.get_goal_node();
    double distance;
    m_open_list.insert(start_node);
    while(!m_open_list.empty()) {
        Node tmp_node = *m_open_list.begin();
        m_close_list.push_back(tmp_node);
        for(auto move: m_move_table) {
            int move_x = tmp_node.x_pos() + move.first;
            int move_y = tmp_node.y_pos() + move.second;
            Node move_node = m_map.get_node(tmp_node.x_pos() + move.first, tmp_node.y_pos()+move.second);

            if(move_node.get_type() == INVALID || is_close_node(move_node)) {
                continue;
            }
            if(!is_open_node(move_node)) {
                m_open_list.insert(move_node);
                m_map.set_node_paraent(move_x,move_y, std::make_shared<Node>(tmp_node));
                continue;
            }

            if(is_open_node(move_node)) {
                int step = m_map.get_step(tmp_node.x_pos(), tmp_node.y_pos()) + std::pow(move.first,2) + std::pow(move.second,2);
                if(m_map.get_step(move_x,move_y) >= step) {
                    m_map.set_node_paraent(move_x,move_y, std::make_shared<Node>(tmp_node));
                }
            }
            if(move_node.x_pos() == goal_node.x_pos() && move_node.y_pos() == goal_node.y_pos()) {
                return true;
            }
        }
        m_open_list.erase(m_open_list.begin());
    }
    
    return false;
}

bool AStar2D::is_close_node(const Node&n)
{
    for(auto node: m_close_list) {
        if(node.equal(n)) {
            return true;
        }
    }
    return false;
}
bool AStar2D::is_open_node(const Node&n)
{
    auto tmp_open_list = m_open_list;
    while(!tmp_open_list.empty()) {
        Node tmp = *tmp_open_list.begin();
        if(tmp.x_pos() == n.x_pos() && tmp.y_pos() == n.y_pos()){
            return true;
        }
        tmp_open_list.erase(tmp_open_list.begin());
    }
    return false;
}
