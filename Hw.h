#ifndef HW_H
#define HW_H
#include "kfc.h"
#include "imageform.h"
#include "map"
#include "math.h"
KImageGray rgbtorgray(KImageColor input);
KImageGray rgbtoggray(KImageColor input);
KImageGray rgbtobgray(KImageColor input);
void rgbtohsv(KArray<KHSV>& rgb, KImageColor color);
void rgbtohsv(KArray<KHSV> HSV, KImageColor& color);
void otsuth(KImageGray icMain, KImageGray& otsu, KHisto htmp);
void J_erode(KImageGray input, KImageGray& output, int Kernel);
void J_Dilate(KImageGray input, KImageGray& output, int Kernel);
void J_Histogram(KImageGray img, KVector& vec);
void J_HE(KImageGray input, KImageGray& output);
void color_HE(KImageColor input, KImageColor& output);
void J_deviation(KVector input, double& deviation);
void J_HM(KImageGray input,KImageGray REF,KImageGray& output);
void color_HM(KImageColor sourse, KImageColor REF, KImageColor& out);
#endif // HW_H
