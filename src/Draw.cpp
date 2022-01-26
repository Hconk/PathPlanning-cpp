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

#include <opencv2/opencv.hpp>
#include <Draw.h>
#include <Utils.h>
Draw::Draw(/* args */)
{
}

Draw::~Draw()
{
}

bool Draw::draw_arrow(cv::Mat &img, int x, int y, double deg, int L, int c)
{
    double theta = Utils::deg2rad(deg);
    double angle = Utils::deg2rad(30);
    double d = 0.5 * L;
    int w = 2;
    int x_start = x;
    int y_start = y;
    int x_end = x + L * std::cos(theta);
    int y_end = y + L * std::sin(theta);
    double theta_hat_L = theta + M_PI - angle;
    double theta_hat_R = theta + M_PI + angle;

    double x_hat_start = x_end;
    double x_hat_end_L =  x_hat_start + d * std::cos(theta_hat_L);
    double x_hat_end_R =  x_hat_start + d * std::cos(theta_hat_R);

    double y_hat_start = y_end;
    double y_hat_end_L =  y_hat_start + d * std::sin(theta_hat_L);
    double y_hat_end_R =  y_hat_start + d * std::sin(theta_hat_R);

    cv::line(img, cv::Point2d(x_start, y_start), cv::Point2d(x_end,y_end), (255, 0, 0),w);
    cv::line(img, cv::Point2d(x_hat_start, y_hat_start), cv::Point2d(x_hat_end_L, y_hat_end_L), (255, 0, 0),w);
    cv::line(img, cv::Point2d(x_hat_start, y_hat_start), cv::Point2d(x_hat_end_R, y_hat_end_R), (255, 0, 0),w);
    return 0;
}
bool Draw::draw_car(cv::Mat &img, int x, int y, double yaw, int w, int L)
{
    double angle = Utils::deg2rad(yaw);
    double theta_B = M_PI + Utils::deg2rad(yaw);

    double xB = x + L / 4 * std::cos(theta_B);
    double yB = y + L / 4 * std::sin(theta_B);

    double theta_BL = theta_B + M_PI / 2;
    double theta_BR = theta_B - M_PI / 2;

    double x_BL = xB + w / 2 * std::cos(theta_BL);
    double y_BL = yB + w / 2 * std::sin(theta_BL);
    double x_BR = xB + w / 2 * std::cos(theta_BR);
    double y_BR = yB + w / 2 * std::sin(theta_BR);

    double x_FL = x_BL + L * std::cos(angle);
    double y_FL = y_BL + L * std::sin(angle);
    double x_FR = x_BR + L * std::cos(angle);
    double y_FR = y_BR + L * std::sin(angle);

    //cv::circle(img, cv::Point2d(x_BL, y_BL), 5, (255,0,0), -1);
    //cv::circle(img, cv::Point2d(x_BR, y_BR), 5, (0,255,0), -1);
    //cv::circle(img, cv::Point2d(x_FR, y_FR), 5, (0,255,0), -1);
    //cv::circle(img, cv::Point2d(x_FL, y_FL), 5, (255,0,0), -1);
    cv::line(img, cv::Point2d(x_BL, y_BL), cv::Point2d(x_BR, y_BR), (255,0,0));
    cv::line(img, cv::Point2d(x_BR, y_BR), cv::Point2d(x_FR, y_FR), (255,0,0));
    cv::line(img, cv::Point2d(x_FR, y_FR), cv::Point2d(x_FL, y_FL), (255,0,0));
    cv::line(img, cv::Point2d(x_FL, y_FL), cv::Point2d(x_BL, y_BL), (255,0,0));
    draw_arrow(img, x, y, yaw, L / 2, 0);


    return 0;
}

bool Draw::animation()
{

    return 0;
}
