%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Configuration file for heat exchanger model in simulink
% Master thesis: Modeling and control of temperature dependent processes of batch beer brewing
% By: Alexander Lydh
%       Oscar Stjernberg
%   2018
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc
clear
close all

%% Variable list for transfer functions
% heat transfer coefficient
U=1000;
% Area of plate
Area=2;
% Heat capacity wort
cp_wort=4000;
% Heat capacity water
cp_H2O = 4190;
% Temperature in-flow wort
T_wort_in=70;
%Temperature in-flow water
T_H2O_in=10;
% Density of wort
rho_wort=1.06; % Same as the specific gravity
% Mass of wort in heat exchanger
m_wort=1;
% Mass of water in heat exchanger
m_H2O=1;
% Steady state values for the states
x_wort_0=30;
x_H2O_0=60;
% Steady state values for the inputs
u_wort_0=5;
u_H2O_0=5;
% Reference value for the wort output temperature
Reference = [25 0];
% Mass flow limits for the wort
wort_up_lim=10;
wort_low_lim=0.1;
% Mass flow limits for the cooling water
water_up_lim=10;
water_low_lim=0.1;
% Delay for heat exchanger
HE_delay = 5;

%% Transfer function definition
% Constructing the linearized A-matrix
A(1,1) = (-u_wort_0*cp_wort-U*Area)/(m_wort*cp_wort);
A(1,2) = U*Area/(m_wort*cp_wort);
A(2,1) = U*Area/(m_H2O*cp_H2O);
A(2,2) = (-u_H2O_0*cp_H2O-U*Area)/(m_H2O*cp_H2O);

% Constructing the linearized B-Matrix
  B = [(cp_H2O*(T_H2O_in - x_H2O_0))/(m_H2O*cp_H2O) -(cp_wort*(T_wort_in - x_wort_0))/(m_wort*cp_wort)
     -(cp_H2O*(T_H2O_in - x_H2O_0))/(m_H2O*cp_H2O) (cp_wort*(T_wort_in - x_wort_0))/(m_wort*cp_wort)];

 % Constructing C-matrix, we want to measure the outgoing temperature of
 % the wort
 C=[1 0 ; 0 1];
 % Constructing the D matrix
 D=zeros(length(C(:,1)),length(B(1,:)));
  
 %% LQR
 % Weight matrix for the states
 Q=diag([1 1]);
 % Weights matrix for the inputs
 R=diag([1 1]);
 % Create the system from the matrix
 SYS=ss(A,B,C,D);
 % Calculate the LQR-gain
 [LQR_gain,S,E]= lqr(SYS,Q,R);
 
 Kr=inv(D-(C-D*LQR_gain)*inv(A-B*LQR_gain));
