Object Detection Was done in multiple ways to choose the best way possible
//To run object detection with matlab using SVM features
1. Download matlab
2. Go into features folder and open features.m
3. Run it (you can change image 2 to different ones to identify image in different angles)
4. Next run Detection_SVM.m (This has a reference image which you compare with each reference frame from webcam)

//Haar-Cascade
1.Go into FaceDetect folder
2.Run detect.py to detect face and eyes by typing (python3 detect.py)
3.The cvImage.py can be used to download images from image net after altering their size and color. This is useful in the process of creating your own haar cascades. The haar cascades made by me weren’t high enough quality so I am in the process of making new ones (takes about 5 days for training each).

//SVM
1. Go to Surf folder
2. Run the following in terminal: make
3. Run the following in terminal: ./mathchingtest
4. This will find the surf features of two images, and search for image one's features in image two.

//find_object (If this doesn't work, I gave direction on how to make it work in Readme.txt located in the following directory: Rose_Demo1/1_code/ROSE/Object_Detection/Readme.txt )
1. Open the compiled c++ program called find_object
2. Place the MonsterEnergy-512x512.png on the left side of application
3. Hit spacebar to open webcam and place the object infront of webcam and it will make a box around the application.
