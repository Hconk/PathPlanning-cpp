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

#ifndef _DRAW_H_
#define _DRAW_H_
#include <opencv2/opencv.hpp>

class Draw
{
private:
    /* data */
public:
    Draw(/* args */);
    bool draw_arrow(cv::Mat &img, int x, int y, double angle, int L, int c);
    bool draw_car(cv::Mat &img, int x, int y, double yaw, int w, int L);
    bool show();
    ~Draw();
};



#endif 