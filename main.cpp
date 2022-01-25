#include <Draw.h>
#include <opencv2/opencv.hpp>
#include <Env.h>

int main() {
    Env env;
    env.Render();
    cv::Mat img = env.GetMat();
    cv::imshow("env", img);
    cv::waitKey(0);
    /*
    Draw draw;
    cv::namedWindow("img");
    for(int i = 0;i < 360;i++) {
        cv::Mat img(cv::Size(500,500),CV_8UC3);
        // draw.draw_arrow(img, 250, 250, 180, 40, 0);
        draw.draw_car(img, 250, 250, i, 40, 60);
        cv::imshow("img", img);
        cv::waitKey(10);
    }
    */
    return 0;
}