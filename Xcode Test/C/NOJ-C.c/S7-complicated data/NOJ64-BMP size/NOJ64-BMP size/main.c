//
//  main.c
//  NOJ64-BMP size
//
//  Created by Steve X on 2017/11/7.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#pragma pack(1)

typedef struct tagBITMAPFILEHEADER{
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffbits;
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
    unsigned int biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
}BITMAPINFOHEADER;

int main()
{
    FILE *bmp;
    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;
    bmp=fopen("DATA5611.BMP","rb");
    if(bmp!=NULL){
        fread(&bmfh,sizeof(BITMAPFILEHEADER),1,bmp);
        fread(&bmih,sizeof(BITMAPINFOHEADER),1,bmp);
        printf("%ld %ld\n",bmih.biWidth,bmih.biHeight);
        fclose(bmp);
    }
    return 0;
}
