%% Detecting an Object in the Image of a Cluttered Scene Demo
% Copyright 2014 The MathWorks, Inc.

%% Clear workspace 
close all;
clear all;
clc;
%% Read Images
I1 = imread('coke.png');
I2 = imread('coke2.jpeg');    
%% Detect SURF Features
points1 = detectSURFFeatures(rgb2gray(I1));
points2 = detectSURFFeatures(rgb2gray(I2));
%% Extract Features
[feats1,validpts1] = extractFeatures(rgb2gray(I1),points1);
[feats2,validpts2] = extractFeatures(rgb2gray(I2),points2);
%% Match Features
index_pairs = matchFeatures(feats1, feats2,...
                             'Prenormalized', true);
matched_pts1 = validpts1(index_pairs(:, 1));
matched_pts2 = validpts2(index_pairs(:, 2));

% Define location of object in image
boxPolygon = [1, 1;...                           % top-left
             size(I1, 2), 1;...                  % top-right
             size(I1, 2), size(I1, 1);...        % bottom-right
             1, size(I1, 1);...                  % bottom-left
             1, 1];                               % top-left again to close the polygon

%% Remove outliers while estimating geometric transform using RANSAC
[tform, inlieroints1, inlierPoints2] = estimateGeometricTransform(matched_pts1,matched_pts2,'affine');
%% Use estimated transfor to locate object 
newBoxPolygon = transformPointsForward(tform, boxPolygon);
%% Overlat the detected location of object in Image I2
figure; 
imshow(I2);
hold on;
line(newBoxPolygon(:, 1), newBoxPolygon(:, 2), 'Color', 'g','LineWidth',2);
title('Detected object');
