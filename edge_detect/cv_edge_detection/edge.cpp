#include <stdio.h>		 //for printf()
#include <opencv\cv.hpp> //for Mat, imread, cvtColor ...

using namespace cv;
Mat src_img, src_grey, src_blr, edges, edges_wht, dst;

int main(int argc, char* argv[]) {
	src_img = imread("lena.jpg"); //read in the file and store it in the src_img matrix
	if (src_img.data == NULL)
	{
		return -1;		//if no file present
	}
	cvtColor(src_img, src_grey, CV_RGB2GRAY);				//convert to grayscale 
	GaussianBlur(src_grey, src_blr, Size(5, 5), 2.1, 2.1);  //blur image to remove many unneded edges  
	Canny(src_blr, edges, 0, 30, 3);						//find edges with Canny detection algorithm
	bitwise_not(edges, edges_wht);							//convert to white background from black
	//imwrite("edges_wht.jpg", edges_wht);					//save the file
	imshow("edge_detection on white background", edges_wht);//show the edges on white background
	int kp = waitKey(20000);								//wait for 20 seconds or press any key
	return 0;
}