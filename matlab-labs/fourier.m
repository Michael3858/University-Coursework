function [y] = fourier(n)
syms x
y = (pi) / 4;
for i = 1:n
    sol = (1 - cos(i * pi)) * (cos(i * x)) / (i * i * (pi)) + (1 / i) * sin(i * x);
    y = y + sol;
end
ezplot(y,[-10, 10]);
end