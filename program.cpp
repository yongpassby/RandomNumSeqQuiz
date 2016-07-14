#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<time.h>

const int SEQLN = 6;
//const int METHODTYP = 3;

struct problemstr{
    int sq[SEQLN];
    std::string about;
};

void addinfo(int ,std::string &);
void probseqgen00(problemstr *);
void probseqgen01(problemstr *);
void probseqgen02(problemstr *);
void probseqgen03(problemstr *);

int main(){
    problemstr prb;
    int methodID,rndpick,ans,usrinput;
    void (*F[])(problemstr *)={probseqgen00,probseqgen01,probseqgen02,probseqgen03};
    do{
        srand(time(0));
        methodID=rand()&0x3;
        (*F[methodID])(&prb);

        srand(time(0));
        rndpick=rand()%SEQLN;
        ans=prb.sq[rndpick];

        for(int i=0;i<SEQLN;i++){
            if(i==rndpick){std::cout<<"__";}
            else{std::cout<<prb.sq[i];}
            if(i!=5){std::cout<<',';}else{std::cout<<'\n';}
        }
        std::cout<<"the answer is:";
        if(std::cin>>usrinput){;}else{break;}
        if(usrinput==ans){std::cout<<"+1\n";}else{std::cout<<"X, correct ans="<<ans<<'\n';}
        std::cout<<"(orig rnd ""proc result-->MethodID="<<methodID<<')'<<"||"<<prb.about;
        std::cout<<'\n'<<'\n';

    }while(1);
    return 0;
}

void probseqgen00(problemstr *p){
    p->about="C.p.n,\tmultip=";//(the Lazy Caterer's sequence): n(n+1)/2 + 1
    p->sq[0]=rand()&0xF;
    int factor=(rand()&0x7)+1;
    for(int i=1;i<6;i++){
        p->sq[i]=p->sq[i-1]+i*factor;
    }
    addinfo(factor,p->about);
    return;
}

void probseqgen01(problemstr *p){
    p->about="Cake nbrs,\tmultip=";//a(n) = (n+1)*(n^2-n+6)/6
    p->sq[0]=rand()&0xF;
    int factor=(rand()&0x7)+1;
    int tmpmed=factor;
    for(int i=1;i<=5;i++){
        p->sq[i]=p->sq[i-1]+tmpmed;
        tmpmed+=i*factor;
    }
    addinfo(factor,p->about);
    return;
}

void probseqgen02(problemstr *p){
    p->about="add\tinterval=";
    int firstitem=rand()&0xFF,addinterval;
    while(!(addinterval=rand()&0xE)){rand();}
    p->sq[0]=firstitem;
    for(int i=1;i<6;i++){
        p->sq[i]=p->sq[i-1]+addinterval;
    }
    addinfo(addinterval,p->about);
    return;
}

void probseqgen03(problemstr *p){
    p->about="multip\tfactor=";
    int firstitem=rand()&0x0F,multip=(rand()&0x7)+2;
    p->sq[0]=firstitem;
    for(int i=1;i<6;i++){
        p->sq[i]=p->sq[i-1]*multip;
    }
    addinfo(multip,p->about);
    return;
}

void addinfo(int data,std::string &s){
    std::stringstream strsrm;
    strsrm<<data;
    std::string tmpstr;
    strsrm>>tmpstr;
    s+=tmpstr;
}
