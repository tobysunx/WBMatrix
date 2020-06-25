#include "WBMatrix.h"
#define TEST8 100000
#define TEST16 100000
#define TEST32 20000
#define TEST64 5000
#define TEST128 2000
void InvTMatM8(M8 *Mat)//generate 8*8 invertible matrix
{
    M8 temp;
    randM8(&temp);
    while(!isinvertM8(temp))
    {
        randM8(&temp);
    }
    copyM8(temp,Mat);
}
void randMat_m8_test()
{
    M8 Mat[TEST8];
    FILE *fd = fopen("RandMat_8bits.bin","wb");
    if(fd == NULL)
    {
        perror("open failed!");
        exit(1);
    }
    for(int i = 0; i < TEST8; i++)
    {
        InvTMatM8(&Mat[i]);
    }
    fwrite(Mat, sizeof(M8), TEST8, fd);
    fclose(fd);
}
void rGInvTMatM8(M8 *Mat)//generate 8*8 invertible matrix
{
    int randAdd;
    int randExc;
    uint8_t temp;
    srand(time(NULL));
    for(int i=7;i>=0;i--)
    {
        for(int j=0;j<8;j++)//Add
        {
            if(j!=i)
            {
                randAdd=rand()%2;
                if(randAdd) (*Mat).M[j]^=(*Mat).M[i];
            }
        }
        if(i<7)//Exchange
        {
            randExc=i+1+rand()%(7-i);
            temp=(*Mat).M[i];
            (*Mat).M[i]=(*Mat).M[randExc];
            (*Mat).M[randExc]=temp;
        }   
    }
}
void reGauss_m8_test()
{
    M8 Mat[TEST8];
    FILE *fd = fopen("ReGauss_8bits.bin","wb");
    if(fd == NULL)
    {
        perror("open failed!");
        exit(1);
    }
    for(int i = 0; i < TEST8; i++)
    {
        rGInvTMatM8(&Mat[i]);
    }
    fwrite(Mat, sizeof(M8), TEST8, fd);
    fclose(fd);
}
void m8_test()
{
    M8 Mat1[TEST8], Mat2[TEST8];
    FILE *fd = fopen("WBMatix_8bits.bin","wb");
    if(fd == NULL)
    {
        perror("open failed!");
        exit(1);
    }
    for(int i = 0; i < TEST8; i++)
    {
        genMatpairM8(&Mat1[i], &Mat2[i]);
    }
    fwrite(Mat1, sizeof(M8), TEST8, fd);
    fclose(fd);
}
void m16_test()
{
    M16 Mat1[TEST16], Mat2[TEST16];
    FILE *fd = fopen("WBMatix_16bits.bin","wb");
    if(fd == NULL)
    {
        printf("open failed!");
        exit(1);
    }
    for(int i = 0; i < TEST16; i++)
    {
        genMatpairM16(&Mat1[i], &Mat2[i]);
    }
    fwrite(Mat1, sizeof(M16), TEST16, fd);
    fclose(fd);
}
void m32_test()
{
    M32 Mat1[TEST32], Mat2[TEST32];
    FILE *fd = fopen("WBMatix_32bits.bin","wb");
    if(fd == NULL)
    {
        printf("open failed!");
        exit(1);
    }
    for(int i = 0; i < TEST32; i++)
    {
        genMatpairM32(&Mat1[i], &Mat2[i]);
    }
    fwrite(Mat1, sizeof(M32), TEST32, fd);
    fclose(fd);
}
void m64_test()
{
    M64 Mat1[TEST64], Mat2[TEST64];
    FILE *fd = fopen("WBMatix_64bits.bin","wb");
    if(fd == NULL)
    {
        printf("open failed!");
        exit(1);
    }
    for(int i = 0; i < TEST64; i++)
    {
        genMatpairM64(&Mat1[i], &Mat2[i]);
    }
    fwrite(Mat1, sizeof(M64), TEST64, fd);
    fclose(fd);
}
void m128_test()
{
    M128 Mat1[TEST128], Mat2[TEST128];
    FILE *fd = fopen("WBMatix_128bits.bin","wb");
    if(fd == NULL)
    {
        printf("open failed!");
        exit(1);
    }
    for(int i = 0; i < TEST128; i++)
    {
        genMatpairM128(&Mat1[i], &Mat2[i]);
    }
    fwrite(Mat1, sizeof(M128), TEST128, fd);
    fclose(fd);
}
int main()
{
    //m8_test();
    //m16_test();
    //m32_test();
    //m64_test();
    //m128_test();
    //randMat_m8_test();
    reGauss_m8_test();
    return 0;
}