function result = paradiff(y,x,t,n)
%UNTITLED 此处显示有关此函数的摘要
%   此处显示详细说明
if mod(n,1)~=0
    error("n should be positive,please check the input and try again")
elseif n==1
    result=diff(y,t)/diff(x,t);
else
    result=diff(paradiff(y,x,t,n-1))/diff(x,t);
end
end

