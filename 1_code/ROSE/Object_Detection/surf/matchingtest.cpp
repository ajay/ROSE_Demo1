#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <armadillo>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;
using namespace cv::flann;
using namespace arma;

Mat drawMatches(Mat img1, vector<KeyPoint> kp1, Mat img2, vector<KeyPoint> kp2, vector<DMatch> matches) {
  int rows1 = img1.rows;
  int cols1 = img1.cols;
  int rows2 = img2.rows;
  int cols2 = img2.cols;

  Mat color1, color2;
  cvtColor(img1, color1, COLOR_GRAY2BGR);
  cvtColor(img2, color2, COLOR_GRAY2BGR);

  Mat out(MAX(rows1, rows2), cols1+cols2, CV_8UC3);
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      out.at<Vec3b>(i, j) = color1.at<Vec3b>(i, j);
    }
  }
  for (int i = 0; i < rows2; i++) {
    for (int j = 0; j < cols2; j++) {
      out.at<Vec3b>(i, j+cols1) = color2.at<Vec3b>(i, j);
    }
  }

  for (DMatch m : matches) {
    int img1_idx = m.queryIdx;
    int img2_idx = m.trainIdx;

    int x1 = (int)kp1[img1_idx].pt.x;
    int y1 = (int)kp1[img1_idx].pt.y;
    int x2 = (int)kp2[img2_idx].pt.x;
    int y2 = (int)kp2[img2_idx].pt.y;

    Vec3b color(rand() % 255, rand() % 255, rand() % 255);
    circle(out, Point(x1,y1), 4, color, 1);
    circle(out, Point(x2+cols1,y1), 4, color, 1);
    line(out, Point(x1,y1), Point(x2+cols1,y2), color, 1);
  }
  return out;
}

int main() {

  // load the images
  Mat img1 = imread("coke.jpeg", IMREAD_GRAYSCALE);
  Mat img2 = imread("soda.jpg", IMREAD_GRAYSCALE);

  // get the descriptors
  vector<KeyPoint> kp1, kp2;
  Mat des1, des2;
  Ptr<SURF> surf = SURF::create();
  surf->detectAndCompute(img1, noArray(), kp1, des1);
  surf->detectAndCompute(img2, noArray(), kp2, des2);

  // now try to match the descriptors
  Ptr<IndexParams> indexParams = makePtr<KDTreeIndexParams>(5);
  Ptr<SearchParams> searchParams = makePtr<SearchParams>(50);
  FlannBasedMatcher flann(indexParams, searchParams);
  vector< vector<DMatch> > matches;
  flann.knnMatch(des1, des2, matches, 2);

  // filter bad matches
  vector<Point2f> pts1, pts2;
  vector<DMatch> good;
  for (int i = 0; i < matches.size(); i++) {
    DMatch m = matches[i][0];
    DMatch n = matches[i][1];
    if (m.distance < 0.75 * n.distance) {
      good.push_back(m);
      pts2.push_back(kp2[m.trainIdx].pt);
      pts1.push_back(kp1[m.queryIdx].pt);
    }
  }

  // arma::mat pts(good.size, 2);
  // sigma = zeros<mat>(3, 3);
  // // var = (Particle's x_i-Mean)^2 / N 
  // for(int i=0; i<good.size(); i++)
  // {

  // }
  // printf("hi \n");
  //Get rid of outliers

  // draw the matches
  Mat I = drawMatches(img1, kp1, img2, kp2, good);
  Mat F ;
  resize( I, F, Size(640, 480));
  imshow("matches", F);
  waitKey(0);

  return 0;
}
