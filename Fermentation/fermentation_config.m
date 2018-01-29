%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Configuration file for the fermentation model in simulink
% Master thesis: Modeling and control of temperature dependent processes of batch beer brewing
% By: Alexander Lydh
%       Oscar Stjernberg
%   2018
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc
clear
close all

%The models is based on the mathematicla model made by Engrasser and
%modified by Douglas A D. and W. Fred Ramirez.

%% constants list for transfer functions
% Fermentation temperature 4, 8 ,12, 16 [C]
i = 2;
T = [4, 8, 12, 16]';
% Glucose concentration, mol/m^3
G_0 = 70;
%G = 
% Maltose concentration, mol/m^3
M_0 = 40;
%M = 
% Maltotriose concentration, mol/m^3
N_0 = 230;
%N = 
% Biomass concentration, mol/m^3
X_0 = 200; % initial biomass
%X = 
% Specific rate of sugar uptake, h^-1
%my_1 = 
%my_2 = 
%my_3 = 
% maximum reaction velocity for ith sugar (G, M, N), h^-1
V_G = [0.0048, 0.013, 0.015, 0.0302]';
V_M = [0.0144, 0.0268, 0.028, 0.0364]';
V_N = [0.087, 0.113, 0.13, 0.151]';
% Michaelis constant for ith sugar  (G, M, N), mol/m^3
K_G = [23.5, 4.7, 1.8, 0.102]';
K_M = [1100, 814, 610, 360]';
K_N = [10900, 7160, 4460, 2410]';
% inhibition constant for ith sugar (G, M)
Ki_G = [123, 182, 240, 262]';
Ki_M = [2090, 6360, 8010, 17500]';
% Reaction parameters
R_EG = 1.92;
R_EM = 3.84;
R_EN = 5.76;
R_XG = 0.134;
R_XM = 0.268;
R_XN = 0.402;
% Initial ethanol
E_0 = 0;
% Gas constant
R = 1.987 % cal/mol*K


% Arrhenius parameters
% activation energy
E_VG = 22.6;
E_VM = 11.3;
E_VN = 7.16;

E_KG = -68.6;
E_KM = -14.4;
E_KN = -19.9;

Ei_KG = 10.2;
Ei_KM = 26.3
% Frequency factor at 8C
V_G0 = 0.013;
V_M0 = 0.0268;
V_N0 = 0.113;

% requency factor for Michaelis constant at 8C
k_G0 = 4.7;
k_M0 = 814;
k_N0 = 7160;

% requency factor for inhibition constant
ki_G0 = 182;
ki_M0 = 6360;

