function [SUM] = HW1(initial, N)
%HW1 Summary of this function goes here
%   Detailed explanation goes here

SUM = 1;
for i = initial : (N + initial - 1)
    SUM = SUM * i;
end