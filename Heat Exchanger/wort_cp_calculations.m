%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Calculations relating to the wort_cp.m function
% Master thesis: Modeling and control of temperature dependent processes of batch beer brewing
% By: Alexander Lydh
%       Oscar Stjernberg
%   2018
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc
clear
close all

% Load the measured specific heat capacity for different sugar contents
% Numbers from 
wort_cp_data=load("wort_cp_data.txt");
% Temperature
T= wort_cp_data(:,1);
% Sugar content 0%
s_0=wort_cp_data(:,2);	
% Sugar content 10%
s_10=wort_cp_data(:,3);	
% Sugar content 20%
s_20=wort_cp_data(:,4);

 plot(T,s_0)
 hold on
 plot(T,s_10)
 plot(T,s_20)
 legend("0%","10%","20%")

% Find best fitting polynomial for sugar concentration = 0%
P0=polyfit(T,s_0,1);
% Find best fitting polynomial for sugar concentration = 10%
P1=polyfit(T,s_10,1);
% Find best fitting polynomial for sugar concentration = 20%
P2=polyfit(T,s_20,1);

% calculating the average coefficients of the specific heat capacity given
% sugar concentration
k_cp_wort=P0(1);
m_cp_wort=P0(2);

% Find the change of the coefficients depending on the sugar content
k_diff_sugar=mean(diff([P0(1) P1(1) P2(1)]));
m_cp_diff=mean(diff([P0(2) P1(2) P2(2)]));

% Construct 3d-plot to visualize the function
temp=linspace(0,100);
s_content=linspace(0,20);

for i=1:length(temp)
    for j=1:length(s_content)
    cp(i,j)=wort_cp(temp(i),s_content(j));
    end
end

surf(temp,s_content,cp)
title("Specific heat capacity of wort depending on sugar content and temperature")
xlabel("Temperature [C]")
ylabel("Sugar content [%]")
zlabel("Specific heat capacity ^{kgm^2}/_{Ks^2}")











