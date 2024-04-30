clear;
close all;
z_c=0.7;
g=9.81;
Tprev=4; %time starwalking
Ts=0.01; %sampleTime


%Cart table model
Ac = [0 1 0;
      0 0 1;
      0 0 0];
Bc = [0;0;1];
Cc = [1 0 -z_c/g];
Dc = [0];

sysd = c2d(ss(Ac,Bc,Cc,Dc),Ts);
%Extended matrixes for the systems
Atilde = [1 sysd.C*sysd.A; zeros(size(sysd.A,1),1) sysd.A];
Btilde = [sysd.C*sysd.B; sysd.B];
Ctilde = [1 zeros(1,size(sysd.A,1))];
Itilde = [1;0;0;0];

N_L=Tprev/Ts
%Riccati relations
Qc=1;
R = 1e-6;


[K, P, E] = dlqry(Atilde,Btilde,Ctilde,0,Qc,R);

GI = K(1)*2; %why?
Gd1 = K(2:end);

tussenterm =  R + Btilde'*P*Btilde;

Actilde=Atilde-Btilde/(tussenterm)*Btilde'*P*Atilde;

Xtilde=-Actilde'*P*Itilde;
Gd(1)=-K(1);

for n=2:N_L
   Gd(n)=1/tussenterm*Btilde'*Xtilde;
   Xtilde=Actilde'*Xtilde;
end
%Gd2(i,j,:)=Gd;
plot(Gd)
Gd=[Gd,Gd1,GI]';
save 'Gd.txt' Gd -ascii;
