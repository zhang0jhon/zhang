#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>

IplImage *g_pSrcImage, *g_pSmooth,*g_pCannyImg;
const char *pstrWindowsCannyTitle = "边缘检测图";
//cvCreateTrackbar的回调函数
void on_trackbar(int threshold)
{
    //cvSmooth(g_pSrcImage,g_pSmooth,CV_MEDIAN,threshold * 2 + 1);
    // cvSmooth(g_pSrcImage,g_pSmooth,CV_GAUSSIAN,threshold * 2 + 1,threshold * 2 + 1);
    //canny边缘检测
    cvCanny(g_pSmooth, g_pCannyImg, threshold, threshold * 3, 3);
    //cvSobel(g_pSrcImage, g_pCannyImg, 1, 1 , 5);
    cvShowImage(pstrWindowsCannyTitle, g_pCannyImg);
    //cvSaveImage("/home/zhang/Desktop/test/999_3D_PS_2_margin.bmp",g_pCannyImg);
    //cvShowImage("smooth", g_pSmooth);
}
int main()
{
    const char *pstrImageName = "/home/zhang/Desktop/test/999_3D_PS_2.bmp";
    const char *pstrWindowsSrcTitle = "原图";
    const char *pstrWindowsToolBar = "滑动条";

    //从文件中载入图像的灰度图CV_LOAD_IMAGE_GRAYSCALE
    g_pSrcImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_GRAYSCALE);
    g_pSmooth = cvCreateImage(cvGetSize(g_pSrcImage), IPL_DEPTH_8U, 1);
    g_pCannyImg = cvCreateImage(cvGetSize(g_pSrcImage), IPL_DEPTH_8U, 1);
    //cvSmooth(g_pSrcImage,g_pSmooth,CV_GAUSSIAN,9,9);
    cvSmooth(g_pSrcImage,g_pSmooth,CV_MEDIAN,9);
    //创建窗口
    cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);
    cvNamedWindow("smooth", CV_WINDOW_AUTOSIZE);
    cvNamedWindow(pstrWindowsCannyTitle, CV_WINDOW_AUTOSIZE);

//创建滑动条
    int nThresholdEdge = 1;
    cvCreateTrackbar(pstrWindowsToolBar, pstrWindowsCannyTitle, &nThresholdEdge, 200, on_trackbar);

    //在指定窗口中显示图像
    cvShowImage(pstrWindowsSrcTitle, g_pSrcImage);
    cvShowImage("smooth", g_pSmooth);
    on_trackbar(27);

    //等待按键事件
    cvWaitKey();

    cvDestroyWindow(pstrWindowsSrcTitle);
    cvDestroyWindow("smooth");
    cvDestroyWindow(pstrWindowsCannyTitle);
    cvReleaseImage(&g_pSrcImage);
    cvReleaseImage(&g_pSmooth);
    cvReleaseImage(&g_pCannyImg);
    return 0;
}