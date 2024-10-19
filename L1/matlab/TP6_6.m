%---------EXO6---------
%------I------
A = [1:3; 4:6; 7:9];
B = transpose(A);
c = A * B;
D = A .* B;
%------II------
v = [-1 -3 -5 -7];
x = [v; 2*v; 3*v; 4*v];
disp(diag(x))
disp(x(2, 3:4))
disp(x(3, 3:4))
disp(tril(x))
disp(triu(x))
%------III------
y = [1 2 3 0; 0 5 4 5; 7 2 9 6; 1 8 3 7];

