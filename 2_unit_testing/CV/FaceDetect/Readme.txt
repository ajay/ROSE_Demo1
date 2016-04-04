Object Detection Was done in multiple ways to choose the best way possible
//To run object detection with matlab using SVM features
1. Download matlab
2. Go into SVM_features folder and open features.m
3. Run it (you can change image 2 to different ones to identify image in different angles)
4. Next run Detection_SVM.m (This has a reference image which you compare with each reference frame from webcam)

//Haar-Cascade
1.Go into opencv_monster
2.Run detect.py to detect face and eyes by typing (python3 detect.py)
3.The cvImage.py can be used to download images from image net after altering their size and color. This is useful in the process of creating your own haar cascades. The haar cascades made by me weren’t high enough quality so I am in the process of making new ones (takes about 5 days for training each).

//SVM
1. Go into object_detection/build
2. Run 'cmake ..' in terminal
3. Run 'make' in terminal
4. Run 'cd..' in terminal
5. Run 'cd bin' in terminal
6. run ./find_object
7. drop the image of the item you want detected into the left side of the application (drop monster can provided)
8. Hit space bar to run the program

