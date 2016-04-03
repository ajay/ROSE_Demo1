%% Clear workspace 
close all;
clear all;
clc;

%% First Image
I1 = imread('monster.jpg');
%% Detect SURF features
points1 = detectSURFFeatures(rgb2gray(I1));
%% Extract Features
[feats1,validpts1] = extractFeatures(rgb2gray(I1),points1);
%% Display 100 strongest features from I1
figure;
imshow(I1);
hold on;
plot(validpts1.selectStrongest(100),'showOrientation',true);
title('Detected Features');
%% Camera
cam = webcam(1);
preview(cam);
runLoop = true;
frameCount = 0;
%% Loop
while runLoop == true
    videoFrame = snapshot(cam);
    grayVideoFrame = rgb2gray(videoFrame)
    
    













