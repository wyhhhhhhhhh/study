//双目采集图像程序
#include<opencv2/opencv.hpp>
#include<stdlib.h>

using namespace cv;
using namespace std;

#define WIDTH 1280
#define HEIGHT 480
//#define WIDTH 3840
//#define HEIGHT 1080
 
int main(int argc, char  *argv[])
{
	VideoCapture capture(0);
    if (!capture.isOpened())
    {
        cout<<"can not open the camera"<<endl; cin.get(); exit(1);
    }
    capture.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);
    string left_road;
	string right_road; 
	int num = 0;
	int count = 0;

    Rect leftRect(0, 0, WIDTH/2, HEIGHT);   //创建一个Rect框，属于cv中的类，四个参数代表x,y,width,height
    Rect rightRect(WIDTH/2, 0, WIDTH/2, HEIGHT);
    while (1) {
        Mat frame; capture>>frame; //载入图像
        if (frame.empty())
        {
            //判断图像是否载入 cout<<"can not load the frame"<<endl;
        } else {
            count++;
            if (count == 1) {
                cout<<frame.cols<<" "<<frame.rows<<endl;
            }
            Mat leftImg,rightImg;
            frame(leftRect).copyTo(leftImg);
            frame(rightRect).copyTo(rightImg);
            imshow("left",leftImg);
            imshow("right",rightImg);
            char q=waitKey(30);
			if (q == 27) {    //按esc退出
				break;
			}
			if (q == 32)     //按空格保存
			{
				num++;
				cout << num;
				left_road = "F:\\graph\\left\\" + to_string(num) + ".png";
				right_road = "F:\\graph\\right\\"+to_string(num) + ".png";
				imwrite(left_road, leftImg);
                
				imwrite(right_road, rightImg);
			}


        }
    }

}

