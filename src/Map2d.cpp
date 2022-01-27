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

#include <Map2d.h>
#include <iostream>
Map2d::Map2d()
{

}

Map2d::Map2d(int x_range, int y_range)
{
    m_x_range = x_range;
    m_y_range = y_range;
    for(int i = 0;i < x_range;i++) {
        std::vector<Node> line;
        for(int j = 0;j < y_range;j++) {
            if(i == 0 || j == 0) {
                line.push_back(Node(i,j,INVALID));
            } else if(j == y_range - 1 || i == x_range -1) {
                line.push_back(Node(i,j,INVALID));
            } else {
                line.push_back(Node(i,j,VALID));
            }
        }
        m_data.push_back(line);
    }
}

Map2d::~Map2d()
{

}

void Map2d::show()
{
    int len = m_data.size();
    std::cout << "len: " << len << std::endl;
    if(len == 0) {
        return;
    }
    int height = m_data[0].size();
    std::cout << "height: " << height << std::endl;
    if(m_data[0].size() == 0) {
        return;
    }

    for(int i = 0;i < height;i++) {
        for(int j = 0;j < len;j++) {
            Node n = m_data[j][i];
            if(n.get_type() == VALID) {
                std::cout << "*" << " ";
            } else if(n.get_type() == INVALID) {
                std::cout << "X" << " ";
            } else if(n.get_type() == GOAL) {
                std::cout << "○" << " ";
            } else if(n.get_type() == START) {
                std::cout << "●" << " ";
            }
        }
        std::cout << std::endl;
    }
}