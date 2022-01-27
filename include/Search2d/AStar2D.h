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

#ifndef _ASTAR_H_
#define _ASTAR_H_
#include <utility>
#include <queue>
#include <vector>
#include <Node.h>
#include <Map2d.h>
#include <set>

class AStar2D
{
private:
    std::vector<std::pair<int, int>> m_move_table = {{-1,-1}, {-1,0}, {-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    Map2d m_map;
    std::vector<Node> m_visited;
    std::vector<Node> m_path;
    std::multiset<Node, std::greater<Node>> m_open_list;
    std::vector<Node> m_close_list;
public:
    AStar2D(/* args */);
    bool SetMap(Map2d map) {
        m_map = map;
        return true;
    }
    bool solver();
    std::vector<Node> get_path();
    std::vector<Node> get_visited_nodes();
    bool is_close_node(const Node &n);
    bool is_open_node(const Node &n);
    bool is_valid_node(const Node &n);
    Map2d get_result() {
        return m_map;
    }
    ~AStar2D();
};

#endif