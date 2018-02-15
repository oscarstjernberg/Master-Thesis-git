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

%% Data from experiment

% Time for cooling procedure
t_cooling= 40 * 60;
% Heigth difference in hot water tank after experiment in m
diff_h_HT = 0.15; 
% Hot tank diameter in m
d_HT = 1.68;
% Volume difference in hot tank aka amount of cooling water used in liters
diff_V_HT = (1.68/2)^2*pi*diff_h_HT*1000;
% Mass flow cooling water
m_dot_H2O = diff_V_HT/t_cooling;


%% Constants list for transfer functions
% Number of plates
n = 25; 
% Area of heat exchange for each plate
A_heat_plate = 6.67/25;
% Total heat exchange area for heat exchanger
Area=n*A_heat_plate;
% Heat capacity wort
cp_wort=4062;
% Heat capacity water
cp_H2O = 4190;
% Temperature in-flow wort
T_wort_in=95;
% Temparatur for out-flow wort
T_wort_out=16;
%Temperature in-flow water
T_H2O_in=5;
% Temperature for out-flow water
T_H2O_out=81.29;
% Density of wort
rho_wort=1.06; % Same as the specific gravity
% Mass of wort in heat exchanger
m_wort=10;
% Mass of water in heat exchanger
m_H2O=m_wort;

% Calculation of heat exchange coefficient U
m_dot_h_data=2954/3600; % Massflow per second
Delta_T1= abs(T_wort_out-T_H2O_out); % Difference in outflow temperature
Delta_T2= abs(T_wort_in-T_H2O_in); % Difference in inflow temperature

U = (m_dot_h_data*cp_wort*(T_wort_in-T_wort_out)*log(Delta_T2/Delta_T1))/...
    (Area*(Delta_T2-Delta_T1));

% Updating parameters to match existing heat exchanger
% Number of plates
n = 37; 
% Total heat exchange area for heat exchanger
Area=n*A_heat_plate;

%% Parameters for model
% Steady state values for the states
x_wort_0=0;
x_H2O_0=0;
% Steady state values for the inputs
u_wort_0=0.23;
u_H2O_0=m_dot_H2O;
% Reference value for the output temperatures
Reference = [20 70];
% Reference flow for the wort and the cooling water for steady
% state
Reference_flow =[1 7];
% Mass flow limits for the wort
wort_up_lim=10;
wort_low_lim=0.1;
% Mass flow limits for the cooling water
H2O_up_lim=100;
H2O_low_lim=0.1;
% Delay for heat exchanger
HE_delay = 25;

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
 
 % Linearized plant from simulink model
%   load("linsys1.mat");
%   %% LQR
%  % Weight matrix for the states
%  Q=diag([3000 1]);
%  % Weights matrix for the inputs
%  R=diag([1 1]);
%  % Create the system from the matrix
%  % SYS=ss(A,B,C,D);
%  SYS= LinearAnalysisToolProject.LocalVariables.Value;
%  % Calculate the LQR-gain
%  [LQR_gain,S,E]= lqr(SYS,Q,R);
%  % Calculating the reference gain
%  Kr=inv(D-(C-D*LQR_gain)*inv(A-B*LQR_gain));
 
 
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
  
 %% Nyquist
 Ts = 1;
 u = 0;
 y = 0;
 
 data = iddata(y,u,Ts);
 
 
 %% PID parameters
 
 Kp = 0.01;
 Ki=0.0001;
 Kd=0;
 Kb=0;
 N=0;
 
 
 
 
 
 
