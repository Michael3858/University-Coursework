function [y] = simponmethod(n)
y = 0;
x = 0;
for i = 0:n
    b = mod(i, 2);
    if(i == 0 || i == n)
        c = 1;
    elseif(b == 0)
        c = 2;
    else
        c = 4;
    end
    y = y + c * (1 / (1 + x ^ 2)); % 0~1/2 (1/1+x^2)dx
    x = x + (1 / 2) * (1 / n);
end
t = 3 * 2 * n;
y = y / t;
end