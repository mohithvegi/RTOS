#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_Sub_String(char *string, char *subString){

}

int print_name(char *prefix){
    static int state = 0;
    char *string, *p;
    switch(state){
        case 0:
            string = prefix;
            state = 1;
            printf("Searching for prefix : %s\n", string);
            return 0;
        case 1:
            p = strstr(prefix, string);
            if(p){
                printf("%s\n", prefix);
            }
            return 0;
    }
}

int main(){
    print_name("Dear");
    print_name("Dear Mohith");
    print_name("Dr Mohith");
    print_name("Dears");

    return 0;
}
