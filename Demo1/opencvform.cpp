#include "opencvform.h"
#include "ui_opencvform.h"
#include "QFileDialog"
#include "QDebug"
using namespace cv;
using namespace std;

#define RATIO    0.5 //错误匹配，0.5是系数，系数大小不同，匹配的结果页不同

OpenCVForm::OpenCVForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenCVForm)
{
    ui->setupUi(this);
}

OpenCVForm::~OpenCVForm()
{
    delete ui;
}

//打开
void OpenCVForm::on_pushButton_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files(*.png *.jpg *.jpeg)"));

    //彩色图
    image=cv::imread(fileName.toStdString(),4);
    cv::cvtColor(image, temp, CV_BGR2RGB);//BGR convert to RGB
    QImage img  = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);

    //灰度图
    imageH=cv::imread(fileName.toStdString());
    cv::cvtColor(imageH, grayImg, CV_BGR2GRAY);//BGR convert to GRAY,Mat类图像是按照BGR顺序存储的图像，而QImage是按照RGB顺序存储的，在类型转换前需要将通道更改
    cv::cvtColor(grayImg, temp2, CV_GRAY2RGB);//
    QImage imgHuidu  = QImage((const unsigned char*)(temp2.data), temp2.cols, temp2.rows, temp2.step, QImage::Format_RGB888);

    //设定图像大小自适应label窗口的大小
    //img = img.scaled(ui->label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.size());

    //灰度图像
    ui->label_Show->setPixmap(QPixmap::fromImage(imgHuidu));
    ui->label_Show->resize(imgHuidu.size());
}

//salt
void OpenCVForm::on_pushButton_2_clicked()
{

}

void OpenCVForm::salt(cv::Mat &image, int n)
{
    int i,j;
    for (int k=0; k<n; k++)
    {


        i= qrand()%image.cols;
        j= qrand()%image.rows;


        if (image.channels() == 1)
        { // gray-level image


            image.at<uchar>(j,i)= 255;


        }
        else if (image.channels() == 3)
        { // color image


            image.at<cv::Vec3b>(j,i)[0]= 255;
            image.at<cv::Vec3b>(j,i)[1]= 255;
            image.at<cv::Vec3b>(j,i)[2]= 255;
        }
    }
}
void OpenCVForm::colorReduce0(cv::Mat &image, int div)
{


    int nl= image.rows; // number of lines
    int nc= image.cols * image.channels(); // total number of elements per line


    for (int j=0; j<nl; j++)
    {


        uchar* data= image.ptr<uchar>(j);


        for (int i=0; i<nc; i++)
        {


            // process each pixel ---------------------
            data[i]= data[i]/div*div+div/2;


            // end of pixel processing ----------------


        } // end of line
    }
}

void OpenCVForm::on_pushButton_color_clicked()
{

}

void OpenCVForm::on_pushButton_grey_clicked()
{

}

//ORB
void OpenCVForm::on_pushButton_ORB_clicked()
{
    QString strOri=  ui->textEdit_1->toPlainText();
    QString fileName = ui->textEdit_2->toPlainText();

    //QString strOri="/home/dg/EquipDemo/21-P.png";
    //彩色图
    imageP=cv::imread(strOri.toStdString(),4);//特征图
    cv::cvtColor(imageP, tempP, CV_BGR2RGB);//BGR convert to RGB

    //QString fileName="/home/dg/EquipDemo/21.png";
    //QString fileName=QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files(*.png *.jpg *.jpeg)"));

    //彩色图
    image=cv::imread(fileName.toStdString(),4);
    cv::cvtColor(image, temp, CV_BGR2RGB);//BGR convert to RGB

    QImage img  = QImage((const unsigned char*)(tempP.data), tempP.cols, tempP.rows, tempP.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.size());//原始图像


    // ORB特征点检测
    int minHessian = 100;//值越大,特征点越多
    Ptr<ORB> detectorORB = ORB::create(minHessian);//和surf的区别：只是SURF→ORB
    vector<KeyPoint> keypointsORB;
    //detectorORB->detect(temp, keypointsORB, Mat());//找出关键点
    Mat descriptors_sence;
    detectorORB->detectAndCompute(temp,Mat(),keypointsORB,descriptors_sence);

    // 绘制关键点
    Mat keypoint_img;

    //#将关键点勾画到图片上
    //#参数image代表原始图片
    //#参数keypoints代表图片的关键点
    //#参数outImage是指输出在哪张图片上
    //#参数color代表勾画的色彩模式
    //#参数flags代表关键点的勾画方式
    drawKeypoints(temp, keypointsORB, keypoint_img, Scalar::all(-1), DrawMatchesFlags::DEFAULT);


    QImage imgNew  = QImage((const unsigned char*)(keypoint_img.data), keypoint_img.cols, keypoint_img.rows, keypoint_img.step, QImage::Format_RGB888);
    //增加标注点的图像
    ui->label_Show->setPixmap(QPixmap::fromImage(imgNew));
    ui->label_Show->resize(imgNew.size());
}

//FeatureDetector
void OpenCVForm::on_pushButton_FeatureDetector_clicked()
{
    QString strFind=  ui->textEdit_1->toPlainText();
    QString fileName = ui->textEdit_2->toPlainText();
    //Mat boxLoad = imread(file1.toStdString());
    //Mat sceneLoad = imread(file2.toStdString());

    //QString strFind="/home/dg/EquipDemo/21-P.png";
    //彩色图
    imageP=cv::imread(strFind.toStdString(),4);//特征图
    cv::cvtColor(imageP, tempP, CV_BGR2RGB);//BGR convert to RGB

    //QString fileName="/home/dg/EquipDemo/21.png";
    //QString fileName=QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files(*.png *.jpg *.jpeg)"));

    //彩色图
    image=cv::imread(fileName.toStdString(),4);
    cv::cvtColor(image, temp, CV_BGR2RGB);//BGR convert to RGB
    QImage img  = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.size());//原始图像

    //#描述符是对关键点的描述，可用于图片匹配
    std::vector<cv::KeyPoint> keypoints;

    std::vector<cv::KeyPoint> keypoints2;

    cv::Ptr<cv::FeatureDetector> fast =cv::FastFeatureDetector::create (100, true,cv::FastFeatureDetector::TYPE_9_16 );//100:数越大,特征点越少
    Mat descriptors_sence;
    //fast->detectAndCompute(image,Mat(),keypoints,descriptors_sence);

    fast->detect(image, keypoints);
    //fast->detect(imageP, keypoints2);

    //#将关键点勾画到图片上
    //#参数image代表原始图片
    //#参数keypoints代表图片的关键点
    //#参数outImage是指输出在哪张图片上
    //#参数color代表勾画的色彩模式
    //#参数flags代表关键点的勾画方式
    cv::drawKeypoints(temp,keypoints,temp,cv::Scalar(0,255,0),0);
    QImage imgNew  = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    //增加标注点的图像
    ui->label_Show->setPixmap(QPixmap::fromImage(imgNew));
    ui->label_Show->resize(imgNew.size());



    //    SurfFeatureDetector featureDetector;
    //    SiftFeatureDetector featureDetector;
    //    featureDetector.detect(image1, image1_kp);
    // surf 特征提取
    //int minHessian = 450;
    //cv::Ptr<SURF> detector = SURF::create(minHessian);


    //    cv::Ptr<cv::FastFeatureDetector> detector =cv::FastFeatureDetector::create (10, true,cv::FastFeatureDetector::TYPE_9_16 );
    //    Mat srcImage = imread("/home/dg/EquipDemo/21-P.png");
    //    Mat dstImage = imread("/home/dg/EquipDemo/21.png");
    //    vector<KeyPoint> keypoints_src;
    //    vector<KeyPoint> keypoints_dst;
    //    cv::Mat descriptor_src, descriptor_dst;

    //    detector->detectAndCompute(srcImage, Mat(), keypoints_src, descriptor_src);
    //    detector->detectAndCompute(dstImage, Mat(), keypoints_dst, descriptor_dst);

    //    // matching
    //    FlannBasedMatcher matcher;
    //    vector<DMatch> matches;
    //    matcher.match(descriptor_dst, descriptor_src, matches);


    //cv::FlannBasedMatcher()
    //#定义FLANN匹配器
    //indexParams=dict(algorithm=0,trees=10)
    //searchParams=dict(checks=50)
    //flann=cv2.FlannBasedMatcher(indexParams,searchParams)
    //#使用KNN算法实现图像匹配，并对匹配结果排序
    //matches=flann.knnMatch(des1,des2,k=2)
    //matches=sorted(matches,key=lambda x:x[0].distance)

    //#去除错误匹配，0.5是系数，系数大小不同，匹配的结果页不同
    //goodMatches=[]
    //for m,n in matches:
    //    if m.distance<0.5*n.distance:
    //        goodMatches.append(m)

}

//ORB匹配
void OpenCVForm::on_pushButton_Find_ORB_clicked()
{
    QString file1=  ui->textEdit_1->toPlainText();
    QString file2 = ui->textEdit_2->toPlainText();
    Mat boxLoad = imread(file1.toStdString());
    Mat sceneLoad = imread(file2.toStdString());
    //    Mat boxLoad = imread("/home/dg/EquipDemo/21.png");
    //    Mat sceneLoad = imread("/home/dg/EquipDemo/21-1.png");
    Mat box,scene;

    //彩色图
    cv::cvtColor(boxLoad, box, CV_BGR2RGB);//BGR convert to RGB
    cv::cvtColor(sceneLoad, scene, CV_BGR2RGB);//BGR convert to RGB

    if (scene.empty()) {
        printf("could not load image...\n");
    }
    //imshow("input image", scene);

    vector<KeyPoint> keypoints_obj, keypoints_sence;
    Mat descriptors_box, descriptors_sence;

    Ptr<Feature2D> detectBRISK = BRISK::create();

    int minHessian = 30;//特征点数量,keypoints_obj/keypoints_sence的数量
    Ptr<ORB> detector = ORB::create(minHessian);
    detector->detectAndCompute(scene, Mat(), keypoints_sence, descriptors_sence);
    detector->detectAndCompute(box, Mat(), keypoints_obj, descriptors_box);

    qDebug()<<"keypoints_obj.size : "<< keypoints_obj.size();
    qDebug()<<"keypoints_sence.size : "<< keypoints_sence.size();


    vector<DMatch> matches;
    FlannBasedMatcher fbmatcher(new flann::LshIndexParams(20, 10, 2));

    // 初始化flann匹配
    //Ptr<FlannBasedMatcher> matcher = FlannBasedMatcher::create(); // default is bad, using local sensitive hash(LSH)
    Ptr<DescriptorMatcher> matcher = makePtr<FlannBasedMatcher>(makePtr<flann::LshIndexParams>(12, 20, 2));//(12, 20, 2)

    matcher->match(descriptors_box, descriptors_sence, matches);

    //匹配描述子
    //fbmatcher.match(descriptors_box, descriptors_sence, matches);
    qDebug()<<"total match points : "<<matches.size();

    // 发现匹配
    vector<DMatch> goodMatches;

    float maxdist = 0;
    for (unsigned int i = 0; i < matches.size(); ++i) {

        qDebug()<<"matches[i].distance : "<< matches[i].distance;

        maxdist = max(maxdist, matches[i].distance);
    }
    qDebug()<<"maxdist : "<< maxdist;

    for (unsigned int i = 0; i < matches.size(); ++i) {
        if (matches[i].distance < maxdist*RATIO)
            goodMatches.push_back(matches[i]);
    }

    Mat dst;
    cv::drawMatches(box, keypoints_obj, scene, keypoints_sence, goodMatches, dst);

    QImage img  = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, dst.step, QImage::Format_RGB888);
    ui->label_Show->setPixmap(QPixmap::fromImage(img));
    ui->label_Show->resize(img.size());

    QImage imgOri  = QImage((const unsigned char*)(box.data), box.cols, box.rows, box.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(imgOri));
    ui->label->resize(imgOri.size());
}

//BRISK匹配
void OpenCVForm::on_pushButton_Find_BRISK_clicked()
{
    QString file1=  ui->textEdit_1->toPlainText();
    QString file2 = ui->textEdit_2->toPlainText();
    Mat boxLoad = imread(file1.toStdString());
    Mat sceneLoad = imread(file2.toStdString());
    //    Mat boxLoad = imread("/home/dg/EquipDemo/0-1_0.jpg");
    //    Mat sceneLoad = imread("/home/dg/EquipDemo/0-1_00.jpg");
    //    Mat boxLoad = imread("/home/dg/EquipDemo/21.png");
    //    Mat sceneLoad = imread("/home/dg/EquipDemo/21-1.png");
    Mat box,scene;

    //彩色图
    cv::cvtColor(boxLoad, box, CV_BGR2RGB);//BGR convert to RGB
    cv::cvtColor(sceneLoad, scene, CV_BGR2RGB);//BGR convert to RGB


    if (scene.empty()) {
        printf("could not load image...\n");
    }
    //imshow("input image", scene);

    vector<KeyPoint> keypoints_obj, keypoints_sence;
    Mat descriptors_box, descriptors_sence;

    int minHessian = 30;//特征点
    Ptr<BRISK> detector = BRISK::create();//创建一个BRISK类对象并初始化
    //Ptr<AKAZE> detector = AKAZE::create();

    //detector->detect(scene, Mat(), keypoints_sence);

    detector->detectAndCompute(scene, Mat(), keypoints_sence, descriptors_sence);
    detector->detectAndCompute(box, Mat(), keypoints_obj, descriptors_box);

    qDebug()<<"keypoints_obj.size : "<< keypoints_obj.size();
    qDebug()<<"keypoints_sence.size : "<< keypoints_sence.size();


    vector<DMatch> matches;
    FlannBasedMatcher fbmatcher(new flann::LshIndexParams(20, 10, 2));

    //初始化flann匹配
    //Ptr<FlannBasedMatcher> matcher = FlannBasedMatcher::create(); // default is bad, using local sensitive hash(LSH)
    //Ptr<DescriptorMatcher> matcher = makePtr<FlannBasedMatcher>(makePtr<flann::LshIndexParams>(12, 20, 2));//(12, 20, 2)
    //matcher->match(descriptors_box, descriptors_sence, matches);

    //匹配描述子
    fbmatcher.match(descriptors_box, descriptors_sence, matches);

    qDebug()<<"total match points : "<<matches.size();

    // 发现匹配
    vector<DMatch> goodMatches;
    double minDist = 1000, maxDist = 0;
    float maxdist = 0;

    for (unsigned int i = 0; i < matches.size(); ++i) {

        qDebug()<<"matches[i].distance : "<< matches[i].distance;

        double dist = matches[i].distance;
        if (dist < minDist) {
            minDist = dist;
        }
        if (dist > maxDist) {
            maxDist = dist;
        }
    }
    qDebug()<<"min distance : "<< minDist;
    qDebug()<<"max distance : "<< maxDist;


    for (unsigned int i = 0; i < matches.size(); ++i) {

        //        if (matches[i].distance < maxdist*RATIO)
        //            goodMatches.push_back(matches[i]);
        if (matches[i].distance>0 && matches[i].distance  < maxDist) {

            goodMatches.push_back(matches[i]);
        }

    }
    qDebug()<<"goodMatches: "<< goodMatches.size();

    Mat dst;
    cv::drawMatches(box, keypoints_obj, scene, keypoints_sence, goodMatches, dst);

    QImage img  = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, dst.step, QImage::Format_RGB888);
    ui->label_Show->setPixmap(QPixmap::fromImage(img));
    ui->label_Show->resize(img.size());

    QImage imgOri  = QImage((const unsigned char*)(box.data), box.cols, box.rows, box.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(imgOri));
    ui->label->resize(imgOri.size());
}

//AKAZE匹配
void OpenCVForm::on_pushButton_Find_AKAZE_clicked()
{
    QString file1=  ui->textEdit_1->toPlainText();
    QString file2 = ui->textEdit_2->toPlainText();
    Mat boxLoad = imread(file1.toStdString());
    Mat sceneLoad = imread(file2.toStdString());
    //    Mat boxLoad = imread("/home/dg/EquipDemo/0-1_0.jpg");
    //    Mat sceneLoad = imread("/home/dg/EquipDemo/0-1_00.jpg");
    //Mat boxLoad = imread("/home/dg/EquipDemo/21.png");
    //Mat sceneLoad = imread("/home/dg/EquipDemo/21-1.png");
    Mat box,scene;

    //彩色图
    cv::cvtColor(boxLoad, box, CV_BGR2RGB);//BGR convert to RGB
    cv::cvtColor(sceneLoad, scene, CV_BGR2RGB);//BGR convert to RGB

    vector<KeyPoint> keypoints_obj, keypoints_sence;
    Mat descriptors_box, descriptors_sence;

    int minHessian = 30;//特征点
    //Ptr<ORB> detector = ORB::create(minHessian);
    Ptr<AKAZE> detector = AKAZE::create();//创建一个BRISK类对象并初始化
    detector->detectAndCompute(scene, Mat(), keypoints_sence, descriptors_sence);
    detector->detectAndCompute(box, Mat(), keypoints_obj, descriptors_box);

    qDebug()<<"keypoints_obj.size : "<< keypoints_obj.size();
    qDebug()<<"keypoints_sence.size : "<< keypoints_sence.size();

    //匹配描述子
    vector<DMatch> matches;

    //初始化flann匹配
    //Ptr<FlannBasedMatcher> matcher = FlannBasedMatcher::create(); // default is bad, using local sensitive hash(LSH)
    Ptr<DescriptorMatcher> matcher = makePtr<FlannBasedMatcher>(makePtr<flann::LshIndexParams>(12, 20, 2));//(12, 20, 2)
    matcher->match(descriptors_box, descriptors_sence, matches);

    FlannBasedMatcher fbmatcher(new flann::LshIndexParams(20, 10, 2));
    //fbmatcher.match(descriptors_box, descriptors_sence, matches);

    qDebug()<<"total match points : "<<matches.size();

    // 发现匹配
    vector<DMatch> goodMatches;
    double minDist = 1000, maxDist = 0;
    float maxdist = 0;

    for (unsigned int i = 0; i < matches.size(); ++i) {
        double dist = matches[i].distance;
        if (dist < minDist) {
            minDist = dist;
        }
        if (dist > maxDist) {
            maxDist = dist;
        }
    }
    qDebug()<<"min distance : "<< minDist;
    qDebug()<<"max distance : "<< maxDist;

    for (unsigned int i = 0; i < matches.size(); ++i) {

        matches[i].distance;
        //        if (matches[i].distance < maxdist*RATIO)
        //            goodMatches.push_back(matches[i]);
        if (matches[i].distance>0 && matches[i].distance  < maxDist) {
            goodMatches.push_back(matches[i]);
        }
    }
    qDebug()<<"goodMatches: "<< goodMatches.size();

    Mat dst;//增加标记的
    cv::drawMatches(box, keypoints_obj, scene, keypoints_sence, goodMatches, dst);

    //cv::drawContours();//画边框

    QImage img  = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, dst.step, QImage::Format_RGB888);
    ui->label_Show->setPixmap(QPixmap::fromImage(img));
    ui->label_Show->resize(img.size());

    //原图
    //    QImage imgOri  = QImage((const unsigned char*)(box.data), box.cols, box.rows, box.step, QImage::Format_RGB888);
    //    ui->label->setPixmap(QPixmap::fromImage(imgOri));
    //    ui->label->resize(imgOri.size());


    //画出不一样的点
    vector<KeyPoint> keypoints_diff;
    for (unsigned int i = 0; i < keypoints_sence.size(); ++i) {
        bool have=false;
        for (unsigned int j = 0; j < keypoints_obj.size(); ++j) {
            KeyPoint kp=  keypoints_sence[i];
            KeyPoint kpObj=  keypoints_obj[j];

            if(kpObj.pt.x==kp.pt.x&&kpObj.pt.y==kp.pt.y)
            {
                have=true;
                break;
            }
        }
        if(!have)
            keypoints_diff.push_back(keypoints_sence[i]);
    }
    qDebug()<<"keypoints_diff : "<< keypoints_diff.size();
    for (unsigned int i = 0; i < keypoints_diff.size(); ++i) {
        KeyPoint kp=  keypoints_diff[i];
        qDebug()<<"x : "<< kp.pt.x;
        qDebug()<<"y : "<< kp.pt.y;

    }
    Mat dstDiff;

    cv::drawKeypoints(box,keypoints_diff,dstDiff,cv::Scalar(0,255,0),0);
    QImage imgOri  = QImage((const unsigned char*)(dstDiff.data), dstDiff.cols, dstDiff.rows, dstDiff.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(imgOri));
    ui->label->resize(imgOri.size());
}

//ORB不同
void OpenCVForm::on_pushButton_Find_ORB_Diff_clicked()
{
    //        Mat boxLoad = imread("/home/dg/EquipDemo/0-1_0.jpg");
    //       Mat sceneLoad = imread("/home/dg/EquipDemo/0-1_00.jpg");
    QString file1=  ui->textEdit_1->toPlainText();
    QString file2 = ui->textEdit_2->toPlainText();
    Mat boxLoad = imread(file1.toStdString());
    Mat sceneLoad = imread(file2.toStdString());
    //Mat boxLoad = imread("/home/dg/EquipDemo/21.png");
    //Mat sceneLoad = imread("/home/dg/EquipDemo/21-1.png");

    Mat box,scene;

    //彩色图
    cv::cvtColor(boxLoad, box, CV_BGR2RGB);//BGR convert to RGB
    cv::cvtColor(sceneLoad, scene, CV_BGR2RGB);//BGR convert to RGB


    //cv::cvtColor(boxLoad, box, CV_BGR2GRAY);//BGR convert to RGB
    //cv::cvtColor(sceneLoad, scene, CV_BGR2GRAY);//BGR convert to RGB


    vector<KeyPoint> keypoints_obj, keypoints_sence;
    Mat descriptors_box, descriptors_sence;

    int minHessian = 100;//特征点
    Ptr<ORB> detector = ORB::create(minHessian);
    //Ptr<AKAZE> detector = AKAZE::create();//创建一个BRISK类对象并初始化
    detector->detectAndCompute(scene, Mat(), keypoints_sence, descriptors_sence);
    detector->detectAndCompute(box, Mat(), keypoints_obj, descriptors_box);

    qDebug()<<"keypoints_obj.size : "<< keypoints_obj.size();
    qDebug()<<"keypoints_sence.size : "<< keypoints_sence.size();

    //匹配描述子
    vector<DMatch> matches;

    //初始化flann匹配
    Ptr<DescriptorMatcher> matcher = makePtr<FlannBasedMatcher>(makePtr<flann::LshIndexParams>(12, 20, 2));
    matcher->match(descriptors_box, descriptors_sence, matches);

    //FlannBasedMatcher fbmatcher(new flann::LshIndexParams(20, 10, 2));
    //fbmatcher.match(descriptors_box, descriptors_sence, matches);

    qDebug()<<"total match points : "<<matches.size();

    // 发现匹配
    vector<DMatch> goodMatches;
    double minDist = 1000, maxDist = 0;
    float maxdist = 0;

    for (unsigned int i = 0; i < matches.size(); ++i) {
        double dist = matches[i].distance;
        if (dist < minDist) {
            minDist = dist;
        }
        if (dist > maxDist) {
            maxDist = dist;
        }
    }
    qDebug()<<"min distance : "<< minDist;
    qDebug()<<"max distance : "<< maxDist;

    for (unsigned int i = 0; i < matches.size(); ++i) {
        matches[i].distance;
        //        if (matches[i].distance < maxdist*RATIO)
        //            goodMatches.push_back(matches[i]);
        //matches[i].distance>0 &&
        if (matches[i].distance < maxDist*RATIO) {
            goodMatches.push_back(matches[i]);
        }
    }
    qDebug()<<"goodMatches: "<< goodMatches.size();

    Mat dst;//增加对比标记
    cv::drawMatches(box, keypoints_obj, scene, keypoints_sence, goodMatches, dst);
    //    QImage img  = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, dst.step, QImage::Format_RGB888);
    //    ui->label_Show->setPixmap(QPixmap::fromImage(img));
    //    ui->label_Show->resize(img.size());

    //画出不一样的点
    vector<KeyPoint> keypoints_diff;
    for (unsigned int i = 0; i < keypoints_sence.size(); ++i) {
        bool have=false;
        for (unsigned int j = 0; j < keypoints_obj.size(); ++j) {
            KeyPoint kp=  keypoints_sence[i];
            KeyPoint kpObj=  keypoints_obj[j];

            if(kpObj.pt.x==kp.pt.x&&kpObj.pt.y==kp.pt.y)
            {
                have=true;
                break;
            }
        }
        if(!have)
            keypoints_diff.push_back(keypoints_sence[i]);
    }

    qDebug()<<"keypoints_diff : "<< keypoints_diff.size();
    //    for (unsigned int i = 0; i < keypoints_diff.size(); ++i) {
    //        KeyPoint kp=  keypoints_diff[i];
    //        qDebug()<<"x : "<< kp.pt.x;
    //        qDebug()<<"y : "<< kp.pt.y;
    //    }
    Mat dstDiff;
    cv::drawKeypoints(scene,keypoints_diff,dstDiff,cv::Scalar(0,255,0),0);
    QImage imgOri  = QImage((const unsigned char*)(dstDiff.data), dstDiff.cols, dstDiff.rows, dstDiff.step, QImage::Format_RGB888);
    ui->label_Show->setPixmap(QPixmap::fromImage(imgOri));
    ui->label_Show->resize(imgOri.size());

    //原图
    QImage img  = QImage((const unsigned char*)(box.data), box.cols, box.rows, box.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.size());
}

void OpenCVForm::on_pushButton_Lable1_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files(*.png *.jpg *.jpeg)"));
    ui->textEdit_1->setText(fileName);
}

void OpenCVForm::on_pushButton_Lable2_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files(*.png *.jpg *.jpeg)"));
    ui->textEdit_2->setText(fileName);
}


//直方图比对
//加载图像；
//先用 cvtColor() 把图像从 RGB 色彩空间转换到 HSV 色彩空间；
//使用 calcHist() 函数计算图像的直方图；
//使用 normalize() 函数将计算得到的直方图归一化到[0~1]之间；
//使用 compareHist() 函数，选择上述枚举类型 HistCompMethods 中的方法之一进行比较；
//展示结果。
double compareFacesByHist(Mat img,Mat orgImg)
{
    Mat tmpImg;
    resize(img, tmpImg, Size(orgImg.cols, orgImg.rows));

    //HSV颜色特征模型(色调H,饱和度S，亮度V)
    cvtColor(tmpImg, tmpImg, COLOR_BGR2HSV);
    cvtColor(orgImg, orgImg, COLOR_BGR2HSV);
    //直方图尺寸设置
    //一个灰度值可以设定一个bins，256个灰度值就可以设定256个bins
    //对应HSV格式,构建二维直方图
    //每个维度的直方图灰度值划分为256块进行统计，也可以使用其他值
    int hBins = 256, sBins = 256;
    int histSize[] = { hBins,sBins };
    //H:0~180, S:0~255,V:0~255
    //H色调取值范围
    float hRanges[] = { 0,180 };
    //S饱和度取值范围
    float sRanges[] = { 0,255 };
    const float* ranges[] = { hRanges,sRanges };
    int channels[] = { 0,1 };//二维直方图
    MatND hist1, hist2;

    calcHist(&tmpImg, 1, channels, Mat(), hist1,2,histSize, ranges, true, false);
    normalize(hist1, hist1, 0, 1, NORM_MINMAX, -1, Mat());
    calcHist(&orgImg, 1, channels, Mat(), hist2, 2, histSize, ranges, true, false);
    normalize(hist2, hist2, 0, 1, NORM_MINMAX, -1, Mat());
    double similarityValue = compareHist(hist1, hist2, CV_COMP_CORREL);
    qDebug() << "相似度：" << similarityValue;
    //    similarityValue = compareHist(hist1, hist2, 1);
    //    qDebug() << "相似度1：" << similarityValue;
    //    similarityValue = compareHist(hist1, hist2, 2);
    //    qDebug() << "相似度2：" << similarityValue;
    //    similarityValue = compareHist(hist1, hist2, 3);
    //    qDebug() << "相似度3：" << similarityValue;
    //    similarityValue = compareHist(hist1, hist2, 4);
    //    qDebug() << "相似度4：" << similarityValue;
    //    similarityValue = compareHist(hist1, hist2, 5);
    //    qDebug() << "相似度5：" << similarityValue;
    //    if (similarityValue >= 0.85)
    //    {
    //        return true;
    //    }
    //return false;
    return similarityValue;
}
//int getORB(char * imagePatha,char * imagePathb){
int getORB(Mat img_1,Mat img_2){
    double t;
    t=getTickCount();
    //Mat img_1 = imread(imagePatha);
    //Mat img_2 = imread(imagePathb);
    //    if (!img_1.data || !img_2.data)
    //    {
    //        qDebug() << "error reading images ";
    //        return -1;
    //    }
    //ORB orb;
    // ORB特征点检测
    int minHessian = 100;//值越大,特征点越多
    Ptr<ORB> orb = ORB::create(minHessian);//和surf的区别：只是SURF→ORB

    vector<KeyPoint> keyPoints_1, keyPoints_2;
    Mat descriptors_1, descriptors_2;
    orb->detectAndCompute(img_1, Mat(), keyPoints_1, descriptors_1);
    orb->detectAndCompute(img_2, Mat(), keyPoints_2, descriptors_2);

    //BruteForceMatcher<HammingLUT> matcher;

    //FlannBasedMatcher fbmatcher(new flann::LshIndexParams(20, 10, 2));
    // 初始化flann匹配
    //Ptr<FlannBasedMatcher> matcher = FlannBasedMatcher::create(); // default is bad, using local sensitive hash(LSH)
    Ptr<DescriptorMatcher> matcher = makePtr<FlannBasedMatcher>(makePtr<flann::LshIndexParams>(12, 20, 2));//(12, 20, 2)

    vector<DMatch> matches;
    matcher->match(descriptors_1, descriptors_2, matches);

    double max_dist = 0; double min_dist = 100;
    for( int i = 0; i < descriptors_1.rows; i++ )
    {
        double dist = matches[i].distance;
        if( dist < min_dist ) min_dist = dist;
        if( dist > max_dist ) max_dist = dist;
    }
    qDebug() <<"-- Max dist : "<< max_dist;
    qDebug() <<"-- Min dist : "<<min_dist;
    vector< DMatch > good_matches;
    for( int i = 0; i < descriptors_1.rows; i++ )
    {
        if( matches[i].distance < 0.6*max_dist )
        {
            good_matches.push_back(matches[i]);
        }
    }
    t=getTickCount()-t;
    t=t*1000/getTickFrequency();
    Mat img_matches;
    drawMatches(img_1, keyPoints_1, img_2, keyPoints_2,good_matches, img_matches,Scalar::all(-1), Scalar::all(-1),vector<char>(),DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
    qDebug() <<  "t :"<<t;

    return t;
}
void OpenCVForm::on_pushButton_compare_clicked()
{
    QString file1=  ui->textEdit_1->toPlainText();
    QString file2 = ui->textEdit_2->toPlainText();
    Mat boxLoad = imread(file1.toStdString());
    Mat sceneLoad = imread(file2.toStdString());
    Mat box,scene;

    //彩色图
    cv::cvtColor(boxLoad, box, CV_BGR2RGB);//BGR convert to RGB
    cv::cvtColor(sceneLoad, scene, CV_BGR2RGB);//BGR convert to RGB

    //cv::cvtColor(boxLoad, box, CV_BGR2GRAY);//BGR convert to RGB
    //cv::cvtColor(sceneLoad, scene, CV_BGR2GRAY);//BGR convert to RGB

    vector<KeyPoint> keypoints_box, keypoints_sence;
    Mat descriptors_box, descriptors_sence;

    int minHessian = 100;//特征点
    Ptr<ORB> detector = ORB::create(minHessian);
    //Ptr<AKAZE> detector = AKAZE::create();//创建一个BRISK类对象并初始化
    detector->detectAndCompute(scene, Mat(), keypoints_sence, descriptors_sence);
    detector->detectAndCompute(box, Mat(), keypoints_box, descriptors_box);

    qDebug()<<"keypoints_box.size : "<< keypoints_box.size();
    qDebug()<<"keypoints_sence.size : "<< keypoints_sence.size();

    //匹配描述子
    vector<DMatch> matches;

    //初始化flann匹配
    Ptr<DescriptorMatcher> matcher = makePtr<FlannBasedMatcher>(makePtr<flann::LshIndexParams>(12, 20, 2));
    matcher->match(descriptors_box, descriptors_sence, matches);

    //FlannBasedMatcher fbmatcher(new flann::LshIndexParams(20, 10, 2));
    //fbmatcher.match(descriptors_box, descriptors_sence, matches);

    qDebug()<<"total match points : "<<matches.size();

    // 发现匹配
    vector<DMatch> goodMatches;
    double minDist = 1000, maxDist = 0;
    float maxdist = 0;

    for (unsigned int i = 0; i < matches.size(); ++i) {
        double dist = matches[i].distance;
        if (dist < minDist) {
            minDist = dist;
        }
        if (dist > maxDist) {
            maxDist = dist;
        }
    }
    qDebug()<<"min distance : "<< minDist;
    qDebug()<<"max distance : "<< maxDist;

    for (unsigned int i = 0; i < matches.size(); ++i) {
        matches[i].distance;
        //        if (matches[i].distance < maxdist*RATIO)
        //            goodMatches.push_back(matches[i]);
        //matches[i].distance>0 &&
        if (matches[i].distance < maxDist*RATIO) {
            goodMatches.push_back(matches[i]);
        }
    }
    qDebug()<<"goodMatches: "<< goodMatches.size();

    Mat dst;//增加对比标记
    cv::drawMatches(box, keypoints_box, scene, keypoints_sence, goodMatches, dst);

    //画出不一样的点
    vector<KeyPoint> keypoints_diff;
    for (unsigned int i = 0; i < keypoints_sence.size(); ++i) {
        bool have=false;
        for (unsigned int j = 0; j < keypoints_box.size(); ++j) {
            KeyPoint kp=  keypoints_sence[i];
            KeyPoint kpObj=  keypoints_box[j];

            if(kpObj.pt.x==kp.pt.x&&kpObj.pt.y==kp.pt.y)
            {
                have=true;
                break;
            }
        }
        if(!have)
            keypoints_diff.push_back(keypoints_sence[i]);
    }

    qDebug()<<"keypoints_diff : "<< keypoints_diff.size();
    Mat dstDiff;
    cv::drawKeypoints(scene,keypoints_diff,dstDiff,cv::Scalar(0,255,0),0);
    QImage imgOri  = QImage((const unsigned char*)(dstDiff.data), dstDiff.cols, dstDiff.rows, dstDiff.step, QImage::Format_RGB888);
    ui->label_Show->setPixmap(QPixmap::fromImage(imgOri));
    ui->label_Show->resize(imgOri.size());
    //原图
    QImage img  = QImage((const unsigned char*)(box.data), box.cols, box.rows, box.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.size());

    //bool res=false;
    double similarityValue= compareFacesByHist(box,scene);
    //ui->textEdit_RES->setText(QString::number(similarityValue));
    qDebug()<<"相似度 = "<<similarityValue;

    //    if (similarityValue >= 0.85)
    //    {
    //        return true;
    //    }
    //return false;
    ui->textEdit_RES_compare->setText(QString::number(similarityValue));
}

//相似度-ORB
void OpenCVForm::on_pushButton_compare_2_clicked()
{
    QString file1=  ui->textEdit_1->toPlainText();
    QString file2 = ui->textEdit_2->toPlainText();
    Mat boxLoad = imread(file1.toStdString());
    Mat sceneLoad = imread(file2.toStdString());
    Mat box,scene;

    //彩色图
    cv::cvtColor(boxLoad, box, CV_BGR2RGB);//BGR convert to RGB
    cv::cvtColor(sceneLoad, scene, CV_BGR2RGB);//BGR convert to RGB

    //cv::cvtColor(boxLoad, box, CV_BGR2GRAY);//BGR convert to RGB
    //cv::cvtColor(sceneLoad, scene, CV_BGR2GRAY);//BGR convert to RGB

    vector<KeyPoint> keypoints_box, keypoints_sence;
    Mat descriptors_box, descriptors_sence;

    int minHessian = 100;//特征点
    Ptr<ORB> detector = ORB::create(minHessian);
    //Ptr<AKAZE> detector = AKAZE::create();//创建一个BRISK类对象并初始化
    detector->detectAndCompute(scene, Mat(), keypoints_sence, descriptors_sence);
    detector->detectAndCompute(box, Mat(), keypoints_box, descriptors_box);

    qDebug()<<"keypoints_box.size : "<< keypoints_box.size();
    qDebug()<<"keypoints_sence.size : "<< keypoints_sence.size();

    //匹配描述子
    vector<DMatch> matches;

    //初始化flann匹配
    Ptr<DescriptorMatcher> matcher = makePtr<FlannBasedMatcher>(makePtr<flann::LshIndexParams>(12, 20, 2));
    matcher->match(descriptors_box, descriptors_sence, matches);

    //FlannBasedMatcher fbmatcher(new flann::LshIndexParams(20, 10, 2));
    //fbmatcher.match(descriptors_box, descriptors_sence, matches);

    qDebug()<<"total match points : "<<matches.size();

    // 发现匹配
    vector<DMatch> goodMatches;
    double minDist = 1000, maxDist = 0;
    float maxdist = 0;

    for (unsigned int i = 0; i < matches.size(); ++i) {
        double dist = matches[i].distance;
        if (dist < minDist) {
            minDist = dist;
        }
        if (dist > maxDist) {
            maxDist = dist;
        }
    }
    qDebug()<<"min distance : "<< minDist;
    qDebug()<<"max distance : "<< maxDist;

    for (unsigned int i = 0; i < matches.size(); ++i) {
        matches[i].distance;
        //        if (matches[i].distance < maxdist*RATIO)
        //            goodMatches.push_back(matches[i]);
        //matches[i].distance>0 &&
        if (matches[i].distance < maxDist*RATIO) {
            goodMatches.push_back(matches[i]);
        }
    }
    qDebug()<<"goodMatches: "<< goodMatches.size();

    Mat dst;//增加对比标记
    cv::drawMatches(box, keypoints_box, scene, keypoints_sence, goodMatches, dst);

    //画出不一样的点
    vector<KeyPoint> keypoints_diff;
    for (unsigned int i = 0; i < keypoints_sence.size(); ++i) {
        bool have=false;
        for (unsigned int j = 0; j < keypoints_box.size(); ++j) {
            KeyPoint kp=  keypoints_sence[i];
            KeyPoint kpObj=  keypoints_box[j];

            if(kpObj.pt.x==kp.pt.x&&kpObj.pt.y==kp.pt.y)
            {
                have=true;
                break;
            }
        }
        if(!have)
            keypoints_diff.push_back(keypoints_sence[i]);
    }

    qDebug()<<"keypoints_diff : "<< keypoints_diff.size();
    Mat dstDiff;
    cv::drawKeypoints(scene,keypoints_diff,dstDiff,cv::Scalar(0,255,0),0);
    QImage imgOri  = QImage((const unsigned char*)(dstDiff.data), dstDiff.cols, dstDiff.rows, dstDiff.step, QImage::Format_RGB888);
    ui->label_Show->setPixmap(QPixmap::fromImage(imgOri));
    ui->label_Show->resize(imgOri.size());
    //原图
    QImage img  = QImage((const unsigned char*)(box.data), box.cols, box.rows, box.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.size());

    int res=getORB(box,scene);
    ui->textEdit_RES->setText(QString::number(res));
    qDebug()<<"res = "<<res;

}

//图片差异
void OpenCVForm::on_pushButton_Diff_clicked()
{
    QString file1=  ui->textEdit_1->toPlainText();
    QString file2 = ui->textEdit_2->toPlainText();
    Mat boxLoad = imread(file1.toStdString());
    Mat sceneLoad = imread(file2.toStdString());
    Mat box,scene;

    //彩色图
    cv::cvtColor(boxLoad, box, CV_BGR2RGB);//BGR convert to RGB
    cv::cvtColor(sceneLoad, scene, CV_BGR2RGB);//BGR convert to RGB

    imageSubtract(box,scene);
}

void OpenCVForm::imageSubtract(Mat &image1, Mat &image2)
{
    if ((image1.rows != image2.rows) || (image1.cols != image2.cols))
    {
        if (image1.rows > image2.rows)
        {
            //resize(image1, image1, image2.size(), 0, 0, INTER_LINEAR);
            //resize(image2.size());
        }
        else if (image1.rows < image2.rows)
        {
            //resize(image2, image2, image1.size(), 0, 0, INTER_LINEAR);
            //resize(image1.size());
        }
    }

    Mat image1_gary, image2_gary;
    if (image1.channels() != 1)
    {
        cvtColor(image1, image1_gary, COLOR_BGR2GRAY);
    }
    if (image2.channels() != 1)
    {
        cvtColor(image2, image2_gary, COLOR_BGR2GRAY);
    }

    Mat frameDifference, absFrameDifferece;
    Mat previousGrayFrame = image2_gary.clone();
    //图1减图2
    subtract(image1_gary, image2_gary, frameDifference, Mat(), CV_16SC1);

    //取绝对值
    absFrameDifferece = abs(frameDifference);

    //位深的改变
    absFrameDifferece.convertTo(absFrameDifferece, CV_8UC1, 1, 0);
    //    imshow("absFrameDifferece", absFrameDifferece);
    Mat segmentation;

    //阈值处理（这一步很关键，要调好二值化的值）
    threshold(absFrameDifferece, segmentation,3, 255, THRESH_BINARY);

    //中值滤波
    medianBlur(segmentation, segmentation, 3);

    //形态学处理(开闭运算)
    //形态学处理用到的算子
    Mat morphologyKernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
    morphologyEx(segmentation, segmentation, MORPH_CLOSE, morphologyKernel, Point(-1, -1), 2, BORDER_REPLICATE);

    //    //显示二值化图片
    //    //imshow("segmentation", segmentation);

    //找边界
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(segmentation, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));//CV_RETR_TREE

    qDebug()<<"contours: "<<contours.size();

    vector< vector<Point> > contours_poly(contours.size());

    vector<Rect> boundRect;
    boundRect.clear();

    for (int index = 0; index < contours.size(); index++)
    {
        vector<Point> tt=contours[index];
        qDebug()<<"差异点坐标集:"<<tt.size();
        approxPolyDP(Mat(contours[index]), contours_poly[index], 3, true);

        Rect rect = boundingRect(Mat(contours_poly[index]));
        rectangle(image2, rect, Scalar(0, 255, 255), 2);//在图2上圈出差异的地方
    }

    QImage imgOri  = QImage((const unsigned char*)(image2.data), image2.cols, image2.rows, image2.step, QImage::Format_RGB888);
    ui->label_Show->setPixmap(QPixmap::fromImage(imgOri));
    ui->label_Show->resize(imgOri.size());

    //原图
    QImage img  = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.size());

}
//图片差异
void OpenCVForm::on_pushButton_Diff_2_clicked()
{
    QString file1=  ui->textEdit_1->toPlainText();
    QString file2 = ui->textEdit_2->toPlainText();

    Mat box = imread(file1.toStdString());
    Mat scene = imread(file2.toStdString());
    Mat img1,img2;

    //彩色图
    cv::cvtColor(box, img1, CV_BGR2RGB);//BGR convert to RGB
    cv::cvtColor(scene, img2, CV_BGR2RGB);//BGR convert to RGB

    //Mat img1 = imread(ch);
    //Mat img2 = imread(ch2);//两幅图像的大小需要一致

    Mat img3,img4;

    cv::resize(img1,img3,img1.size(),0,0,CV_INTER_LINEAR);
    cv::resize(img2,img4,img2.size(),0,0,CV_INTER_LINEAR);

    Mat img_result1, img_result2,img_result;

    img_result1 = 2*abs(img3 - img4);//不同的地方

    add(img_result1, img3, img_result);

    //imwrite("3.png", img_result);//图片输出

    QImage img  = QImage((const unsigned char*)(img_result.data), img_result.cols, img_result.rows, img_result.step, QImage::Format_RGB888);
    ui->label_Show->setPixmap(QPixmap::fromImage(img));
    ui->label_Show->resize(img.size());

    //原图
    QImage imgOri  = QImage((const unsigned char*)(img3.data), img3.cols, img3.rows, img3.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(imgOri));
    ui->label->resize(imgOri.size());
}
