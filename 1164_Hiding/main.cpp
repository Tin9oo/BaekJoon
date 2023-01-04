#include <iostream>
#include <ctime>

#define DEBUG false

int main()
{
    int N, M;
    char temp;

    std::cin >> N >> M;

    char** frame = new char*[N];
    for(int i=0;i<N;++i)
    {
        frame[i]=new char[M];
    }

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            std::cin >> temp;
            frame[i][j]=temp;
            // std::cout << frame[i][j];
        }
    }
    
    clock_t clock_start = clock();

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if((i<=N-2)&&(j<=M-4))
            {
                if((frame[i][j]=='X')&&(frame[i+1][j]=='X')&&(frame[i+1][j+1]=='X')&&(frame[i+1][j+2]=='X')&&(frame[i+1][j+3]=='X')&&(frame[i][j+3]=='X'))
                {
                    frame[i][j]='A';
                    frame[i+1][j]='A';
                    frame[i+1][j+1]='A';
                    frame[i+1][j+2]='A';
                    frame[i+1][j+3]='A';
                    frame[i][j+3]='A';
                }
            }
            if(DEBUG) std::cout << frame[i][j];
        }
        if(DEBUG) std::cout << std::endl;
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if((i<=N-1)&&(j<=M-2))
            {
                if((frame[i][j]=='X')&&(frame[i][j+1]=='X'))
                {
                    frame[i][j]='B';
                    frame[i][j+1]='B';
                }
            }
            if(DEBUG) std::cout << frame[i][j] << " ";
        }
        if(DEBUG) std::cout << std::endl;
    }

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if(frame[i][j]=='X')
            {
                std::cout << -1;
                return 0;
            }
        }
    }

    int cnt=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if(frame[i][j]=='.')
            {
                cnt=cnt+1;
            }
        }
    }
    if(cnt==N*M)
    {
        std::cout << -1;
        return 0;
    }

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            std::cout << frame[i][j];
        }
        std::cout << std::endl;
    }
    
    if(DEBUG) std::cout << sizeof(char) * N * M << " Byte" << std::endl;
    if(DEBUG) std::cout << (float)(clock() - clock_start)/CLOCKS_PER_SEC << " second" << std::endl;

    for(int i=0;i<N;++i)
    {
        delete[] frame[i];
    }
    delete[] frame;

    return 0;

}