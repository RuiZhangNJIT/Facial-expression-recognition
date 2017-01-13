%t:Angry---0 other 1
%A--Angry; B--Happy; C--Neutral ; D--Surprise;

q=[1,2,3;4,5,6;7,8,9];
q1=sum(q(1:2,:),1);
A=zeros(200,100);
B=zeros(200,100);
C=zeros(200,100);
D=zeros(200,100);
for i=0:199;
    
    %Angry;
   temp0=imread(['.\Gabor_Angry\',num2str(i),'.bmp']);
    %get the mean of z-axi
   temp01=sum(temp0(:,:,1:3),3)/3;
   k0=1;
   %plus every 20 cols
   for m=1:20:181 %rows
    temp02=sum(temp01(m:m+19,:),1);
   
    for n=1:20:181 %coloums
     temp021=temp02;
     temp021=sum(temp021(:,n:n+19),2);
     temp021=temp021/400;
      A(i+1,k0)=temp021;
     
     k0=k0+1;
     
     
   end;
   
   end;
   
   
   %Happy;
   temp1=imread(['.\Gabor_Happy\',num2str(i),'.bmp']);
   temp11=sum(temp1(:,:,1:3),3)/3;
   k1=1;
   %plus every 20 cols
   for m=1:20:181 %rows
    temp12=sum(temp11(m:m+19,:),1);
   
    for n=1:20:181 %coloums
     temp121=temp12;
     temp121=sum(temp121(:,n:n+19),2);
     temp121=temp121/400;
      B(i+1,k1)=temp121;
     
     k1=k1+1;
     
     
   end;
   
   end;
   
  
   %Neutral;
   temp2=imread(['.\Gabor_Neutral\',num2str(i),'.bmp']);
   %get the mean of z-axi
   temp21=sum(temp2(:,:,1:3),3)/3;
   k2=1;
   %plus every 20 cols
   for m=1:20:181 %rows
    temp22=sum(temp21(m:m+19,:),1);
   
    for n=1:20:181 %coloums
     temp221=temp22;
     temp221=sum(temp221(:,n:n+19),2);
     temp221=temp221/400;
      C(i+1,k2)=temp221;
     
     k2=k2+1;
     
     
   end;
   
   end;
   
   
   %Surprise
   temp3=imread(['.\Gabor_Surprise\',num2str(i),'.bmp']);
    %get the mean of z-axi
   temp31=sum(temp3(:,:,1:3),3)/3;
   k3=1;
   %plus every 20 cols
   for m=1:20:181 %rows
    temp32=sum(temp31(m:m+19,:),1);
   
    for n=1:20:181 %coloums
     temp321=temp32;
     temp321=sum(temp321(:,n:n+19),2);
     temp321=temp321/400;
      D(i+1,k3)=temp321;
     
     k3=k3+1;
     
     
   end;
   
   end;
   
end

% data has been processed;

%training 	w1_Angry  Angry=1 others=-1
N=800;
A1=A';
B1=B';
C1=C';
D1=D';
x1=[ones(N,1) [A;B;C;D]];
w1=[ones(1,101)]';
p=randperm(N);
for n1=1:800
    if p(n1)<=N/4
        x11=[1;A1(:,p(n1))];
        if(w1'*x11<0)
            w1=w1+x11*1
        end
    elseif p(n1)>N/4 & p(n1)<=N/2
        x11=[1;B1(:,p(n1)-N/4)];
        if(w1'*x11>0)
            w1=w1+x11*(-1)
        end
    elseif p(n1)>N/2 & p(n1)<=3*N/4
        x11=[1;C1(:,p(n1)-N/2)];
        if(w1'*x11>0)
            w1=w1+x11*(-1)
        end
    elseif p(n1)>3*N/4
        x11=[1;D1(:,p(n1)-3*N/4)];
        if(w1'*x11>0)
            w1=w1+x11*(-1)
        end
    end
end

%test pictures from Gabor_test

test_Angry=linspace(1,1,100);
Test_Angry=imread('.\Gabor_test\6.bmp');
Test0_Angry=sum(Test_Angry(:,:,1:3),3)/3;
k5=1;
   %plus every 20 cols
   for m=1:20:181 %rows
    temp52=sum(Test0_Angry(m:m+19,:),1);
   
    for n=1:20:181 %coloums
     temp521=temp52;
     temp521=sum(temp521(:,n:n+19),2);
     temp521=temp521/400;
     test_Angry(:,k5)=temp521;
     
     k5=k5+1;
     
     
   end;
   
   end;

   x111=[1;test_Angry'];
   res_Angry=w1'*x111;
   
 
   
%training w2_Happy Happy=1 others=-1

x2=[ones(N,1) [B;A;C;D]];
w2=[ones(1,101)]';
p=randperm(N);
for n1=1:800
    if p(n1)<=N/4
        x22=[1;B1(:,p(n1))];
        if(w2'*x22<0)
            w2=w2+x22*1
        end
    elseif p(n1)>N/4 & p(n1)<=N/2
        x22=[1;A1(:,p(n1)-N/4)];
        if(w2'*x22>0)
            w2=w2+x22*(-1)
        end
    elseif p(n1)>N/2 & p(n1)<=3*N/4
        x22=[1;C1(:,p(n1)-N/2)];
        if(w2'*x22>0)
            w2=w2+x22*(-1)
        end
    elseif p(n1)>3*N/4
        x22=[1;D1(:,p(n1)-3*N/4)];
        if(w2'*x22>0)
            w2=w2+x22*(-1)
        end
    end
end


%test pic from Gabor_test


test_Happy=linspace(1,1,100);
Test_Happy=imread(['.\Gabor_test\6.bmp']);
Test0_Happy=sum(Test_Happy(:,:,1:3),3)/3;
k6=1;
   
%plus every 20 cols
   for m=1:20:181 %rows
    temp62=sum(Test0_Happy(m:m+19,:),1);
   
    for n=1:20:181 %coloums
     temp621=temp62;
     temp621=sum(temp621(:,n:n+19),2);
     temp621=temp621/400;
     test_Happy(:,k6)=temp621;
     
     k6=k6+1;
     
     
   end;
   end;
   
   
   x222=[1;test_Happy'];
   res_Happy=w2'*x222;
   
 
   %training w3_Neutral Neutral=1 others=-1

x3=[ones(N,1) [C;A;B;D]];
w3=[ones(1,101)]';
p=randperm(N);
for n1=1:800
    if p(n1)<=N/4
        x33=[1;C1(:,p(n1))];
        if(w3'*x33<0)
            w3=w3+x33*1
        end
    elseif p(n1)>N/4 & p(n1)<=N/2
        x33=[1;A1(:,p(n1)-N/4)];
        if(w3'*x33>0)
            w3=w3+x33*(-1)
        end
    elseif p(n1)>N/2 & p(n1)<=3*N/4
        x33=[1;B1(:,p(n1)-N/2)];
        if(w3'*x33>0)
            w3=w3+x33*(-1)
        end
    elseif p(n1)>3*N/4
        x33=[1;D1(:,p(n1)-3*N/4)];
        if(w3'*x33>0)
           w3=w3+x33*(-1)
        end
    end
end

%test pic from Gabor_test


test_Neutral=linspace(1,1,100);
Test_Neutral=imread(['.\Gabor_test\6.bmp']);
Test0_Neutral=sum(Test_Neutral(:,:,1:3),3)/3;
k7=1;
   %plus every 20 cols
   for m=1:20:181 %rows
    temp72=sum(Test0_Neutral(m:m+19,:),1);
   
    for n=1:20:181 %coloums
     temp721=temp72;
     temp721=sum(temp721(:,n:n+19),2);
     temp721=temp721/400;
     test_Neutral(:,k7)=temp721;
     
     k7=k7+1;
     
     
   end;
   
   end;
   
   x333=[1;test_Neutral'];
   res_Neutral=w3'*x333;
   
   
%training w4_Surprise Surprise=1 others=-1

x4=[ones(N,1) [D;A;B;C]];
w4=[ones(1,101)]';
p=randperm(N);
for n1=1:800
    if p(n1)<=N/4
        x44=[1;D1(:,p(n1))];
        if(w4'*x44<0)
            w4=w4+x44*1
        end
    elseif p(n1)>N/4 & p(n1)<=N/2
        x44=[1;A1(:,p(n1)-N/4)];
        if(w4'*x44>0)
            w4=w4+x44*(-1)
        end
    elseif p(n1)>N/2 & p(n1)<=3*N/4
        x44=[1;B1(:,p(n1)-N/2)];
        if(w4'*x44>0)
            w4=w4+x44*(-1)
        end
    elseif p(n1)>3*N/4
        x44=[1;C1(:,p(n1)-3*N/4)];
        if(w4'*x44>0)
           w4=w4+x44*(-1)
        end
    end
end

%test pic from Gabor_test

for j=1:100;
test_Surprise=linspace(1,1,100);
Test_Surprise=imread(['.\Gabor_test\',num2str(j),'.bmp']);
Test0_Surprise=sum(Test_Surprise(:,:,1:3),3)/3;
k8=1;

%plus every 20 cols
   for m=1:20:181 %rows
    temp82=sum(Test0_Surprise(m:m+19,:),1);
   
    for n=1:20:181 %coloums
     temp821=temp82;
     temp821=sum(temp821(:,n:n+19),2);
     temp821=temp821/400;
     test_Surprise(:,k8)=temp821;
     
     k8=k8+1;
     
     
   end;
   
   end;
   
   x444=[1;test_Surprise'];
   res_Surprise=w4'*x444;
   plot(j,res_Surprise,'x');
   hold on;
end;
   res='can not recoginzie';
   
   if res_Angry>0
       res='Angry';
   end
   
   if res_Happy>0
       res='Happy';
   end
   
   if res_Neutral>0
      
       res='Neutral';
   end
   
   if res_Surprise>0
       res='Surprise';
   end
       