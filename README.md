OpenCV-Windows-Forms-IP-camera
==============================

This program can take image from IP-camera by link like: 
http://192.168.1.111/image?res=full&amp;x0=0&amp;y0=0&amp;x1=1600&amp;y1=1200.jpg 

First, program downloads image to file "img.jpg"
Then it reads this file to cv::Mat
Then it converts to .Net image
Last it shows imege on pictureBox
