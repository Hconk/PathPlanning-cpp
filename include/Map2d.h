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
    std::vector<std::vector<Node>> m_nodes;
public:
    Map2d(/* args */);
    NODETYPE get_type(int x, int y) {
        if(x >= m_x_range || y >= m_y_range) {
            return INVALID;
        }
        return m_nodes[x][y].get_type();
    }
    ~Map2d();
};


#endif