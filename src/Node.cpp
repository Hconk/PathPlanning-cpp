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

#include <Node.h>
#include <iostream>
#include <fmt/format.h>

Node::Node()
{

}

Node::Node(const Node&n) {
    m_paraent = n.m_paraent;
    m_priority = n.m_priority;
    m_type = n.m_type;
    m_x_pos = n.m_x_pos;
    m_y_pos = n.m_y_pos;
    m_step = n.m_step;
}

Node::Node(int x, int y, NODETYPE type):m_x_pos(x), m_y_pos(y),m_type(type)
{
}
Node::Node(int x, int y, NODETYPE type, double priority):m_x_pos(x), m_y_pos(y),m_type(type), m_priority(priority)
{
}
Node::~Node()
{
}

void Node::print()
{
    std::cout << fmt::format("Node(x:{},y: {}) -> prority: {}, type: {} .", m_x_pos, m_y_pos, m_priority, m_type) << std::endl;
}