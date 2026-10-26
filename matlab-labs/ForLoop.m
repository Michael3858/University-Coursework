x = zeros(1, 6); % x 是一個 1x6 大小的零矩陣
for i = 1 : 6
    x(i) = 1 / i;
end
x % 顯示x
format rat % 顯示最簡分數
disp(x)
h = zeros(6); % h 是一個 6x6 大小的零矩陣
for i = 1 : 6
    for j = 1 : 6
        h(i, j) = 1 / (i + j - 1);
    end
end
h
format short % 回到預設形式來顯示所有數值
for i = h % 每一次i的值就是矩陣h的一直行的內容
    disp(norm(i)^2); % 印出每一行的平方和
end
disp(rand(5, 4) * 10 ^ 3) % rand 生成一個0~1之間的隨機數
for i = 1 : 1000
    if prod(1 : i) > 1e100 % prod(1, 5) = 1 x 2 x 3 x 4 x 5 = 120 
        fprintf('%g != %e > 1e100\n', i, prod(1 : i));
        break;
    end
end