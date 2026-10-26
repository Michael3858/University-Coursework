function [ANS] = newton(x)
%NEWTON Summary of this function goes here
%   Detailed explanation goes here
for i = 1 : 100
    ANS = x - (x - 2 * sin(x)) / (1 - 2 * cos(x));
    x = ANS;
end
