#include <iostream>
using namespace std;

int main(void) {
    int T, a, b;

    cin >> T;

    int first_contest[]={1,3,6,10,15,21};
    int first_reward[]={500,300,200,50,30,10};
    int second_contest[]={1,3,7,15,31};
    int second_reward[]={512,256,128,64,32};

    int len_fir_cont=sizeof(first_contest)/sizeof(*first_contest);
    int len_sec_cont=sizeof(second_contest)/sizeof(*second_contest);

    int result=0;
    
    for(int i=0;i<T;++i){
        result=0;
        cin >> a >> b;
        for(int j=0;j<len_fir_cont;++j){
            if(a==0) break;
            if(a<=first_contest[j]){
                result=first_reward[j];
                break;
            }
        }
        for(int j=0;j<len_sec_cont;++j){
            if(b==0) break;
            if(b<=second_contest[j]){
                result+=second_reward[j];
                break;
            }
        }

        cout << result*10000 << endl;
    }

    return 0;
}