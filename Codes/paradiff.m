function result = paradiff(y,x,t,n)
%UNTITLED �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
if mod(n,1)~=0
    error("n should be positive,please check the input and try again")
elseif n==1
    result=diff(y,t)/diff(x,t);
else
    result=diff(paradiff(y,x,t,n-1))/diff(x,t);
end
end

