function [ANS] = fixedpoint(x)
%HW2 Summary of this function goes here
%   Detailed explanation goes here
if 2 * cos(x) >= 1
    disp('請重新輸入一個x值');
else
    for i = 1 : 100
        ANS = 2 * sin(x);
        x = ANS;
    end
end