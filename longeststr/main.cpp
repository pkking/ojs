#include <iostream>
#include <string>
#include <cctype>

std::string test(const std::string & in) 
{
    std::size_t len = 0;
    std::size_t maxlen = 0;
    std::size_t dotindex = 0;
    bool dot = false;
    std::size_t afterdot = 0, beforedot = 0;
    std::size_t start = 0;
    char c ;
    std::string maxstr;

    std::cout << "begin to process:"<<in<<std::endl;
    for (std::size_t i = 0; i != in.size(); i++) {
        c = in[i];
        if (isdigit(c)) {
            if (len == 0) {
                start = i;
            }
            len++;
            beforedot++;
            if (dot) {
                afterdot++;
            }
            if (len >= maxlen && in.substr(start, len) > maxstr) {
                maxlen = len;
                maxstr = in.substr(start, maxlen);
                std::cout << "1 maxstr:"<<maxstr<<std::endl;
            }
            std::cout << "1 now maxlen:"<<maxlen << " dotindex:"<<dotindex<<" beforedot:"<<beforedot<<" afterdot:"<<afterdot<<std::endl;
        } else if( c == '.' ) {
            if (len == 0) {
                start = i;
            }
            
            if (dot) {
                if (len >= maxlen && in.substr(start, len) > maxstr) {
                    maxlen = len;
                    maxstr = in.substr(start, maxlen);
                    std::cout << "2 maxstr:"<<maxstr<<std::endl;
                }
                beforedot = afterdot;
                len = afterdot + 1;
                afterdot = 0;
                start = dotindex+1;
                afterdot = 0;
            } else {
                len++;
                dot = true;
                if (len >= maxlen && in.substr(start, len) > maxstr) {
                    maxlen = len;
                    maxstr = in.substr(start, maxlen);
                    std::cout << "3 maxstr:"<<maxstr<<std::endl;
                }
            }
            dotindex = i;
            std::cout << "2 now maxlen:"<<maxlen << " dotindex:"<<dotindex<<" beforedot:"<<beforedot<<" afterdot:"<<afterdot<<std::endl;
        } else {
            if (len != 0 ) {
                len = 0;
                beforedot = 0;
                afterdot = 0;
                dot = false;
                dotindex = 0;
                start = 0;
                std::cout << "3 now maxlen:"<<maxlen << " dotindex:"<<dotindex<<" beforedot:"<<beforedot<<" afterdot:"<<afterdot<<std::endl;
            }
        }
    }
    
    return maxstr;
  
}

int main()
{
    std::string teststr;

    std::cin >> teststr;

    std::cout << test(teststr);

    return 0;
}