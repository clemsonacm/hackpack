#include <stdio.h>
int main (){
    //To stdout
    double f = 3.14;
    int    i = 314;
    char*  s = "ACM";
    printf("%5f,%5i,%5s\n", f, i, s);

    //Same thing to a file
    FILE * outputfile;
    outputfile = fopen("outputfile.txt","w");
    fprintf(outputfile,"%5f,%5i,%5s\n", f, i, s);
    fclose(outputfile);
}
