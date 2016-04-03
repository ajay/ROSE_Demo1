%% Clear Everything
clear all;
clc;

%% Import Image
LostBook = imread('LostBook3.jpg');
I = rgb2gray(LostBook);
points = detectSURFFeatures(I);
imshow(I);
hold on;
plot(points.selectStrongest(10));

