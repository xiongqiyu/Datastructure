#include <iostream>

int main()
{
    int int_a[128];
    int tmp;
    int i=0;

    std::cout<<"enter a number: "<<std::endl;
    std::cin>>tmp;

    while(tmp!=0){
        int_a[i]=tmp;
        i++;

        std::cout<<"enter a number: "<<std::endl;
        std::cin>>tmp;
    }
    int int_a_size=i;
    std::cout<<"you entered the following numbers: "<<std::endl;
    for(int i=0; i<int_a_size; i++){
        std::cout<<int_a[i]<<std::endl;
    }

    std::cout<<"that in reverse order are: "<<std::endl;
    for(int i=int_a_size-1; i>=0; i--){
      std::cout<<int_a[i]<<std::endl;
    }

    return 0;
}
