syms x1 x2 u1 u2

%% constants list for transfer functions
% heat transfer coefficient
U=1000;
% Area of plate
Area=20;
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
x1_0=25;
x2_0=25;
% Steady state values for the inputs
u1_0=1;
u2_0=7;
% Reference value for the wort output temperature
Reference = [25 16];
% Reference flow for the wort and the cooling water for steady state
Reference_flow =[1 7];
% Mass flow limits for the wort
wort_up_lim=10;
wort_low_lim=0.1;
% Mass flow limits for the cooling water
H2O_up_lim=10;
H2O_low_lim=0.1;
% Delay for heat exchanger
HE_delay = 5;


%%

var_list=[x1 x2 u1 u2];
var_val=[T_wort_in T_H2O_in u1_0 u2_0];

%x1_dot= (u1*cp_wort*(x1_0-x1)-U*Area*(x1-x2))/(m_wort*cp_wort);
%x2_dot=(u2*cp_H2O*(x2_0-x2)-U*Area*(x2-x1))/(m_H2O*cp_H2O);

x1_dot = 2/m_wort*(u1*(T_wort_in - x1) + U*Area*log(x1-x2)/cp_wort);
x2_dot = 2/m_H2O*(u2*(T_H2O_in - x2) - U*Area*log(x2-x1)/cp_H2O);

df1dx1=diff(x1_dot,x1);
df2dx1=diff(x2_dot,x1);
df1dx2=diff(x1_dot,x2);
df2dx2=diff(x2_dot,x2);

A=[df1dx1 df1dx2;
    df2dx1 df2dx2];
A=subs(A,var_list,var_val);


df1du1=diff(x1_dot,u1);
df2du1=diff(x2_dot,u1);
df1du2=diff(x1_dot,u2);
df2du2=diff(x2_dot,u2);

B=[df1du1 df1du2;
    df2du1 df2du2];
B=subs(B,var_list,var_val);











