#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
float h(float);
float g(float);

stack<float> sineStack;
stack<float> sinecosstack;
int main(int argc, char** argv) {
cout << "---Hyp Sine Function---" << endl;
for(float i = -.9; i < 1.0; i += .1)
{
    stack<float> clear;
    sineStack.swap(clear);
    sinecosstack.swap(clear);
    cout << i << " Radians of hyp cos(x) is: " << h(i) << "There is " << sineStack.size() << " sine calls and " << sinecosstack.size() << " sine and cosine calls." << endl;
}
//Testing out recursive trig functions
/*float angDeg=45;
float angRad=angDeg*atan(1)/45;
cout<<"Angle = "<<angDeg<<" sinh = "<<sinh(angRad)<<
" our h = "<<h(angRad)<<endl;
cout<<"Angle = "<<angDeg<<" cosh = "<<cosh(angRad)<<
" our g = "<<g(angRad)<<endl;
//Exit stage right*/
return 0;
}
float h(float angR){
float tol=1e-6;
sineStack.push(angR);
if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
sineStack.push(angR);
return 2*h(angR/2)*g(angR/2);

}
float g(float angR){
sinecosstack.push(angR);
float tol=1e-6;
if(angR>-tol&&angR<tol)return 1+angR*angR/2;
float b=h(angR/2);
return 1+2*b*b;
}