function test()
while(1)
clc;
close all;
n=input('Enter number of intervals:');
h=(2/n);
fprintf('X\t\t\tY\n');
for i=0:h:2
    fprintf('%.2f\t\t',i);
    fprintf('%.3f\n',integrand(i));
end
if(rem(n,6)==0)
    fprintf('Press 3:Weddle\nPress 2:Simpson\nPress 1:Trapezoidal');
    ch=input('');
elseif(rem(n,2)==0)
    fprintf('Press 2:simpson\nPress 1:Trapezoidal');
    ch=input('');
else
    fprintf('We are going for trapezoidal rule');
    ch=1;
end
switch ch
    case 1
        trapezoid(n,h)
    case 2
        simpsons(n,h)
    case 3
        weddle(n,h)
end
fprintf('Press 4:for exit\n Press any other integer to continue\n')
ch=input('Enter your choice: ');
if(ch==4)
    clc
    return
end
end
end
function f=integrand(x)
f=x.^3;
end
function trapezoid(n,h)
sum=0.0;
for i=0:1:n
    if(i==0)||(i==n)
        sum=sum+integrand(i*h);
    else
        sum=sum+2*integrand(i*h);
    end
end
fprintf('Area=%.3f\n',(h/2)*sum)
end
function simpsons(n,h)
sum=0.0;
for i=0:1:n
    
    if (i==0)||(i==n)
        sum=sum+integrand(i*h);
    elseif rem(i,2)~=0
         sum=sum+(4.0*integrand(i*h));
    else
        sum=sum+(2.0*integrand(i*h));
    end
    
end
fprintf('Area=%.3f\n',(h/3)*sum)  
end
function weddle(n,h)
sum=0;
pos=1;
for i=0:1:n
    if(i==0)||(i==n)
        sum=sum+integrand(i*h);
    elseif rem(i,2)~=0
        if(rem(pos,2)~=0);sum=sum+(5*integrand(i*h));else sum=sum+(6*integrand(i*h));end
        pos=pos+1;
    else
        sum=sum+integrand(i*h);
    end
end
fprintf('Area=%.3f\n',(3/10)*h*sum);
end
        
 

        
 


