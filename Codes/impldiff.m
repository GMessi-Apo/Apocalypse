function dyx = impldiff(f,x,y,n)
%UNTITLED3 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
if mod(n,1)~=0
    error('n should be positive please check and try again')
else
    F1=-simplify(diff(f,x)/diff(f,y));
    dyx=F1;
    for i=2:n
    dyx=simplify(diff(dyx,x)+diff(dyx,y)*F1);
    end
end
end

