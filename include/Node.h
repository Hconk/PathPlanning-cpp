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

#ifndef _NODE_H_
#define _NODE_H_
#include <memory>

enum NODETYPE {
    START,
    GOAL,
    OBS,
    VALID,
    INVALID
};
class Node
{
public:

    Node();
    Node(int x, int y, NODETYPE type);
    Node(int x, int y, NODETYPE type, double priority);
    Node(const Node& n);
    NODETYPE get_type() {
        return m_type;
    }
    void set_type(NODETYPE type) {
        m_type = type;
    }
    int get_step() const {
        return m_step;
    }
    void set_step(int step) {
        m_step = step;
    }
    int x_pos() const {
        return m_x_pos;
    }
    int y_pos() const {
        return m_y_pos;
    }
    void set_priority(double priority)  {
        m_priority = priority;
    }
    bool equal(const Node&n) {
        return n.m_x_pos == m_x_pos && n.m_y_pos == m_y_pos;
    }
    void set_paraent(const std::shared_ptr<Node>& paraent) {
        m_paraent = paraent;
    }
    void print();


    friend bool operator > (const Node&n1, const Node &n2);
    ~Node();
private:
    NODETYPE m_type;
    double m_priority=0;
    std::shared_ptr<Node> m_paraent;
    int m_x_pos;
    int m_y_pos;
    int m_step = 0;
};

inline bool operator > (const Node &n1, const Node &n2) 
{
    return n1.m_priority > n2.m_priority;
}



#endif