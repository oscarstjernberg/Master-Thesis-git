function [cp] = wort_cp(T,sugar_content)
%   wort_cp
%   Calculates the specific heat capacity for the wort given the
%   temperature and the sugar content.
%   Inputs:
%   T = The temperature of the wort
%   sugar_content = the sugar content of the wort given in %
% 
%   Outputs:
%   cp= Specific heat capacity
cp = (2.4176e-04+6.3187e-05*sugar_content)*T+(4.1814-0.02471*sugar_content);
end

