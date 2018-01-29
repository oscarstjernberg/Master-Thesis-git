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

%% constants list for transfer functions
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
x_wort_0=0;
x_H2O_0=0;
% Steady state values for the inputs
u_wort_0=1;
u_H2O_0=7;
% Reference value for the wort output temperature
Reference = [25 16];
% Reference flow for the wort and the cooling water for steady state
Reference_flow =[1 7];
% Mass flow limits for the wort
wort_up_lim=10;
wort_low_lim=0.1;
% Mass flow limits for the cooling water
H2O_up_lim=100;
H2O_low_lim=0.1;
% Delay for heat exchanger
HE_delay = 5;

%% Transfer function definition linearization
% Constructing the linearized A-matrix
A(1,1) = (-u_wort_0*cp_wort-U*Area)/(m_wort*cp_wort);
A(1,2) = U*Area/(m_wort*cp_wort);
A(2,1) = U*Area/(m_H2O*cp_H2O);
A(2,2) = (-u_H2O_0*cp_H2O-U*Area)/(m_H2O*cp_H2O);

 % Constructing the linearized B-Matrix
   B = [(cp_wort*(T_wort_in - x_wort_0))/(m_wort*cp_wort) 0
      0 (cp_H2O*(T_H2O_in - x_H2O_0))/(m_H2O*cp_H2O)];

 % Constructing C-matrix, we want to measure the outgoing temperatures
 C=[1 0 ; 0 1];
 % Constructing the D matrix
 D=zeros(length(C(:,1)),length(B(1,:)));
 
 
  %% LQR
 % Weight matrix for the states
 Q=diag([3 1]);
 % Weights matrix for the inputs
 R=diag([1 1]);
 % Create the system from the matrix
 SYS=ss(A,B,C,D);
 % Calculate the LQR-gain
 [LQR_gain,S,E]= lqr(SYS,Q,R);
 % Calculating the reference gain
 Kr=inv(D-(C-D*LQR_gain)*inv(A-B*LQR_gain));
 
 
 %% Transfer function definition exact linearization
 
 % Constructing the linear parts of the system in the A matrix
 A_exact=[-U*Area/(m_wort*cp_wort) U*Area/(m_wort*cp_wort) ;
     U*Area/(m_H2O*cp_H2O) -U*Area/(m_H2O*cp_H2O)];
  % Constructing the B-Matrix, where the non-linear parts are in u
 B_exact=[1 0 ; 0 1];
  % Constructing C-matrix, we want to measure the outgoing temperatures
 C_exact=[1 0 ; 0 1];
  % Constructing the D matrix
 D=zeros(length(C_exact(:,1)),length(B_exact(1,:)));
 
 
   %% LQR_exact
 % Weight matrix for the states
 Q_exact=diag([300 0.01]);
 % Weights matrix for the inputs
 R_exact=diag([0.01 0.01]);
 % Create the system from the matrix
 SYS_exact=ss(A_exact,B_exact,C_exact,D);
 % Calculate the LQR-gain
 [LQR_gain_exact,S_exact,E_exact]= lqr(SYS_exact,Q_exact,R_exact);
 % Calculating the reference gain
 Kr_exact=inv(D-(C_exact-D*LQR_gain_exact)*inv(A_exact-B_exact*LQR_gain_exact));
  

