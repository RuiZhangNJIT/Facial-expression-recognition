s=pwd;
%A1=imread('.\Gabor_Angry\1.bmp');
%B2=imread('.\Gabor_Happy\1.bmp');
%C3=imread('.\Gabor_Neutral\1.bmp');
%D4=imread('.\Gabor_Surprise\1.bmp');

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
   temp0=imread(['.\Gabor_Angry\' num2str(i) '.bmp']);
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
   temp1=imread(['.\Gabor_Happy\' num2str(i) '.bmp']);
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
   temp2=imread(['.\Gabor_Neutral\' num2str(i) '.bmp']);
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
   temp3=imread(['.\Gabor_Surprise\' num2str(i) '.bmp']);
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

% data has been perfectly collected;
% traing;

%Angry--(1), other---(-1)

t_Angry=linspace(1,1,200);
t_Other=linspace(-1,-1,600);
t_All_Angry=[t_Angry t_Other];

X_All_Angry=[A;B;C;D];

%W1 is testing Angry or Not Angry

W1_Angry=pinv(X_All_Angry)*transpose(t_All_Angry);

%test pic from Gabor_test

test_Angry=linspace(1,1,100);
Test_Angry=imread(['.\Gabor_test\' num2str(j) '.bmp']);
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
   
   
   res_Angry=transpose(W1_Angry)*transpose(test_Angry);
   
   

   
   %traing happy, Happy---(1), Not Happy---(-1)
   
   t_Happy=linspace(1,1,200);
   t_Other_Happy=linspace(-1,-1,600);
   t_All_Happy=[t_Happy t_Other_Happy];

    X_All_Happy=[B;A;C;D];

%W1 is testing Angry or Not Angry

W1_Happy=pinv(X_All_Happy)*transpose(t_All_Happy);

%test pic from Gabor_test
test_Happy=linspace(1,1,100);
Test_Happy=imread(['.\Gabor_test\6.bmp'])
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
   
   
   res_Happy=transpose(W1_Happy)*transpose(test_Happy);
   
  
   
   
   %training neutral
   
  t_Neutral=linspace(1,1,200);
t_Other_Neutral=linspace(-1,-1,600);
t_All_Neutral=[t_Neutral t_Other_Neutral];

X_All_Neutral=[C;A;B;D];

%W1 is testing Angry or Not Angry

W1_Neutral=pinv(X_All_Neutral)*transpose(t_All_Neutral);


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
   
   
   res_Neutral=transpose(W1_Neutral)*transpose(test_Neutral);
  

   %Surprise
   
   t_Surprise=linspace(1,1,200);
t_Other=linspace(-1,-1,600);
t_All_Surprise=[t_Surprise t_Other];

X_All_Surprise=[D;A;B;C];

%W1 is testing Angry or Not Angry

W1_Surprise=pinv(X_All_Surprise)*transpose(t_All_Surprise);

%test pic from Gabor_test

for j=1:100;
test_Surprise=linspace(1,1,100);
Test_Surprise=imread(['.\Gabor_test\' num2str(j) '.bmp']);
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
   
   
   res_Surprise=transpose(W1_Surprise)*transpose(test_Surprise);
   
   plot(j,res_Surprise,'x');
   hold on;
   
end;
   res='can not recoginzie';
   %choose facial expression
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
       
   
