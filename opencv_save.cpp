#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
  VideoCapture videoInput(2);
  if (!videoInput.isOpened()) {
    return -1;
  }
  float fpsInput = 5;                 //获取帧率
  float pauseInput = 1000 / fpsInput; //设置帧间隔
  Mat frame;
  // Size
  // videoSize=Size(videoInput.get(CV_CAP_PROP_FRAME_WIDTH),videoInput.get(CV_CAP_PROP_FRAME_HEIGHT));
  Size videoSize = Size(1280, 720);

  string videoPath1 =
      "/home/bdca/workspace/opencv_save/video/videoRecordPIM1.avi";
  int fourcc1 = CV_FOURCC('P', 'I', 'M', '1');
  VideoWriter videoOutput1(videoPath1, fourcc1, fpsInput, videoSize, true);

  string videoPath2 =
      "/home/bdca/workspace/opencv_save/video/videoRecordMJPG.avi";
  int fourcc2 = CV_FOURCC('M', 'J', 'P', 'G');
  VideoWriter videoOutput2(videoPath2, fourcc2, fpsInput, videoSize, true);

  string videoPath3 =
      "/home/bdca/workspace/opencv_save/video/videoRecordMP42.avi";
  int fourcc3 = CV_FOURCC('M', 'P', '4', '2');
  VideoWriter videoOutput3(videoPath3, fourcc3, fpsInput, videoSize, true);

  string videoPath4 =
      "/home/bdca/workspace/opencv_save/video/videoRecordDIV3.avi";
  int fourcc4 = CV_FOURCC('D', 'I', 'V', '3');
  VideoWriter videoOutput4(videoPath4, fourcc4, fpsInput, videoSize, true);

  string videoPath5 =
      "/home/bdca/workspace/opencv_save/video/videoRecordDIVX.avi";
  int fourcc5 = CV_FOURCC('D', 'I', 'V', 'X');
  VideoWriter videoOutput5(videoPath5, fourcc5, fpsInput, videoSize, true);

  string videoPath6 =
      "/home/bdca/workspace/opencv_save/video/videoRecordFLV1.avi";
  int fourcc6 = CV_FOURCC('F', 'L', 'V', '1');
  VideoWriter videoOutput6(videoPath6, fourcc6, fpsInput, videoSize, true);

  if (!videoOutput1.isOpened()) {
    return -1;
  }
  if (!videoOutput2.isOpened()) {
    return -1;
  }
  if (!videoOutput3.isOpened()) {
    return -1;
  }
  if (!videoOutput4.isOpened()) {
    return -1;
  }
  if (!videoOutput5.isOpened()) {
    return -1;
  }

  if (!videoOutput6.isOpened()) {
    return -1;
  }

  while (true) {
    videoInput >> frame;
    if (frame.empty() || waitKey(pauseInput) == 27) {
      break;
    }
    resize(frame, frame, videoSize);
    videoOutput1 << frame;
    videoOutput2 << frame;
    videoOutput3 << frame;
    videoOutput4 << frame;
    videoOutput5 << frame;
    videoOutput6 << frame;
    imshow("Video", frame);
  }
  waitKey();
  return 0;
}