#ifndef OPENCVFORM_H
#define OPENCVFORM_H
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "vector"

#include <QWidget>

namespace Ui {
class OpenCVForm;
}

class OpenCVForm : public QWidget
{
    Q_OBJECT

public:
    explicit OpenCVForm(QWidget *parent = 0);
    ~OpenCVForm();
    void salt(cv::Mat &image, int n);
    void colorReduce0(cv::Mat &image, int n);
    void imageSubtract(cv::Mat &image1, cv::Mat &image2);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_color_clicked();

    void on_pushButton_grey_clicked();

    void on_pushButton_FeatureDetector_clicked();

    void on_pushButton_ORB_clicked();

    void on_pushButton_Find_ORB_clicked();

    void on_pushButton_Find_BRISK_clicked();

    void on_pushButton_Find_AKAZE_clicked();

    void on_pushButton_Find_ORB_Diff_clicked();

    void on_pushButton_Lable1_clicked();

    void on_pushButton_Lable2_clicked();

    void on_pushButton_compare_clicked();

    void on_pushButton_compare_2_clicked();

    void on_pushButton_Diff_clicked();

    void on_pushButton_Diff_2_clicked();

private:
    Ui::OpenCVForm *ui;
    cv::Mat image, grayImg,temp,imageH,temp2,imageP,tempP;

    cv::Feature2D sift;


    //cv::FastFeatureDetector fast(40);	// 检测的阈值为40

};

#endif // OPENCVFORM_H
