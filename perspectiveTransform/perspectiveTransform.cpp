#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\Files\\lena.jpg");//读取图像
	if (srcMat.empty())//检测图像是否读取成功
	{
		return -1;
	}
	//变换前四点坐标
	const cv::Point2f pst1[] = {
									cv::Point2f(150,150),
									cv::Point2f(150,300),
									cv::Point2f(350,300),
									cv::Point2f(350,150) };
	//变换后四点坐标
	const cv::Point2f pst2[] = {
									cv::Point2f(200,150),
									cv::Point2f(200,300),
									cv::Point2f(340,270),
									cv::Point2f(340,180) };
	//计算投影矩阵
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pst1, pst2);
	//进行投影变换
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());
	cv::imshow("src", srcMat);//输出原图像
	cv::imshow("dst", dstMat);//输出投影变换后图像
	waitKey(0);
}