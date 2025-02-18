#include "HW.h"
#include <iostream>
void rgbtohsv(KArray<KHSV>& rgb, KImageColor color){
    KArray<KHSV> HSV(color.Row(), color.Col());

    double dMin, dMax,dDiff;

    for(int i=color.Row(),ii=0; i; i--,ii++)
        for(int j=color.Col(),jj=0; j ; j--,jj++){
            dMin  = _MIN(_MIN(color._ppA[ii][jj].r,color._ppA[ii][jj].g),color._ppA[ii][jj].b);
            dMax  = _MAX(_MAX(color._ppA[ii][jj].r,color._ppA[ii][jj].g),color._ppA[ii][jj].b);
            dDiff = dMax - dMin;

            if(dDiff == 0){
                HSV[ii][jj].h = 0;
                HSV[ii][jj].s = 0.1;
                HSV[ii][jj].v = dMax;
            }
            else{
                //V
                HSV[ii][jj].v = dMax;
                //S
                HSV[ii][jj].s = dDiff/dMax;
                //H
                if(dMax == (double)(color._ppA[ii][jj].r)){
                    HSV[ii][jj].h = 60*(color._ppA[ii][jj].g - color._ppA[ii][jj].b)/dDiff;}
                else if(dMax == (double)(color._ppA[ii][jj].g)){
                    HSV[ii][jj].h = 60*(color._ppA[ii][jj].b - color._ppA[ii][jj].r)/dDiff + 120;}
                else{
                    HSV[ii][jj].h = 60*(color._ppA[ii][jj].r - color._ppA[ii][jj].g)/dDiff + 240;}
            }

        }
}

KImageGray rgbtorgray(KImageColor input){
    KImageGray out(input.Row(), input.Col());
    for(int i = 0, ii = input.Row();ii;ii--,i++)
        for(int j = 0, jj = input.Col();jj;jj--,j++)
            out[i][j] = input[i][j].r;
    return out;
}

KImageGray rgbtoggray(KImageColor input){
    KImageGray out(input.Row(), input.Col());
    for(int i = 0, ii = input.Row();ii;ii--,i++)
        for(int j = 0, jj = input.Col();jj;jj--,j++)
            out[i][j] = input[i][j].g;
    return out;
}

KImageGray rgbtobgray(KImageColor input){
    KImageGray out(input.Row(), input.Col());
    for(int i = 0, ii = input.Row();ii;ii--,i++)
        for(int j = 0, jj = input.Col();jj;jj--,j++)
            out[i][j] = input[i][j].b;
    return out;
}

void rgbtohsv(KArray<KHSV> HSV, KImageColor& color){

    float h,s,v,f,p,q,t;
    int   idx;
    for(int i=0; i<color.Row(); i++)
        for(int j=0; j<color.Col(); j++){
            h = HSV[i][j].h;
            s = HSV[i][j].s;
            v = HSV[i][j].v;

            if(s == 0.0)
            {
                color._ppA[i][j].r = color._ppA[i][j].g = color._ppA[i][j].b = (h == -1.0 ? (unsigned char)v : 0);
                continue;
            }

            if(h == 360.0)h = 0.0;
            h /= 60.0;
            idx = (int)h;
            f = h-idx;
            p = v*(1.0-s);
            q = v*(1.0-s*f);
            t = v*(1.0-s*(1.0-f));

            switch(idx)
            {
            case 0: color._ppA[i][j].r=v; color._ppA[i][j].g=t; color._ppA[i][j].b=p; break;
            case 1: color._ppA[i][j].r=q; color._ppA[i][j].g=v; color._ppA[i][j].b=p; break;
            case 2: color._ppA[i][j].r=p; color._ppA[i][j].g=v; color._ppA[i][j].b=t; break;
            case 3: color._ppA[i][j].r=p; color._ppA[i][j].g=q; color._ppA[i][j].b=v; break;
            case 4: color._ppA[i][j].r=t; color._ppA[i][j].g=p; color._ppA[i][j].b=v; break;
            case 5: color._ppA[i][j].r=v; color._ppA[i][j].g=p; color._ppA[i][j].b=q; break;
            default: color._ppA[i][j].r=100; color._ppA[i][j].g=100; color._ppA[i][j].b=100; break;
            }
        }

}

void otsuth(KImageGray icMain, KImageGray& otsu, KHisto htmp){

    //apply Ostu' thresholding
    double      q1[256],m1[256],m2[256],P[256];
    double		u 	= 0;

    int			nThresh = 1;
    double		dMax 	= 0.0, dSigmaB;

    q1[0]   	= htmp[0]/icMain.Size();
    m1[0] 	= 0.0;

    for(int i=0; i<254; i++){
        P[i] = htmp[i]/icMain.Size();
    }

    for(int i=0; i<254; i++){
        u += (i+1)*P[i+1];
    }

    for(int i=0; i<254; i++)
    {
        q1[i+1] 	= q1[i] + P[i+1];
        if(q1[i+1]  == 0.0){
            m1[i+1] = 0.0;

        }
        else{
            m1[i+1]	= (q1[i]*m1[i] + (double)(i+1)*P[i+1])/q1[i+1];
            m2[i+1] =  (u-q1[i+1]*m1[i+1]) / (1.0 - q1[i+1]);
            dSigmaB = q1[i+1]*(1.0-q1[i+1])*_SQR(m1[i+1] - m2[i+1]);
            //max
            if(dSigmaB > dMax)
            {
                dMax 	 	= dSigmaB;
                nThresh  	= i+1;
            }
        }
    }

    for(int i=icMain.Row(),ii=0; i; i--,ii++)
        for(int j=icMain.Col(),jj=0; j ; j--,jj++){
            if(icMain[ii][jj] <= nThresh)otsu[ii][jj] = 0;
            else otsu[ii][jj] = 255;
        }
}


void J_erode(KImageGray input, KImageGray& output, int Kernel){
    output = input;
    //    int K =(float)Kernel/2;
    //    for(int i = K, ii = input.Row()-K+1; ii ;i++,ii--)
    //        for(int j = K, jj = input.Col()-K+1; jj;j++,jj--){
    //            if(input[ii][jj] == 0)
    //        }


    if(Kernel == 3){
        for(int i=1,ii=input.Row()-2; ii; i++,ii--)
            for(int j=1,jj=input.Col()-2; jj; j++,jj--)
            {
                if(input._ppA[i][j])
                    if(input._ppA[i-1][j-1]==0 || input._ppA[i-1][j]==0 || input._ppA[i-1][j+1]==0 || input._ppA[i][j-1]==0
                        || input._ppA[i][j+1]==0 || input._ppA[i+1][j-1]==0 || input._ppA[i+1][j]==0 || input._ppA[i+1][j+1]==0)
                        output._ppA[i][j] = 0;
            }
    }
    else if(Kernel == 5){
        for(int i=1,ii=input.Row()-4; ii; i++,ii--)
            for(int j=1,jj=input.Col()-4; jj; j++,jj--)
            {
                if(input._ppA[i][j])
                    if(input[i-2][j-2] ==0 ||input[i-2][j-1]==0 ||input[i-2][j]==0 ||input[i-2][j+1]==0 ||input[i-2][j+2]==0)
                        if(input[i-1][j-2] ==0|| input[i-1][j-1] ==0||input[i-1][j]==0 ||input[i-1][j+1] ==0||input[i-1][j+2]==0)
                            if(input[i][j-2]==0 ||input[i][j-1] ==0||input[i][j+1] ==0||input[i][j+2]==0||input[i+1][j-2]==0)
                                if( input[i+1][j-1]==0 ||input[i+1][j] ==0||input[i+1][j+1] ==0||input[i+1][j+2]==0)
                                    if(input[i+2][j-2]==0 || input[i+2][j-1] ==0||input[i+2][j]==0 ||input[i+2][j+1]==0 ||input[i+2][j+2]==0)
                                        output[i][j] = 0;
            }
    }


}

void J_Dilate(KImageGray input, KImageGray& output, int Kernel){
    output = input;
    if(Kernel == 3){
        for(int i=1,ii=input.Row()-2; ii; i++,ii--)
            for(int j=1,jj=input.Col()-2; jj; j++,jj--)
            {
                if(input[i][j] == 0)
                    if(input[i-1][j-1] || input[i-1][j] || input[i-1][j+1] || input[i][j-1]
                        || input[i][j+1] || input[i+1][j-1] || input[i+1][j] || input[i+1][j+1])
                        output[i][j] = 255;
            }
    }
    else if(Kernel == 5){
        for(int i=2,ii=input.Row()-4; ii; i++,ii--)
            for(int j=2,jj=input.Col()-4; jj; j++,jj--)
            {
                if(input[i][j] == 0)
                    if(input[i-2][j-2] ||input[i-2][j-1] ||input[i-2][j] ||input[i-2][j+1] ||input[i-2][j+2])
                        if(input[i-1][j-2] || input[i-1][j-1] ||input[i-1][j] ||input[i-1][j+1] ||input[i-1][j+2])
                            if(input[i][j-2] ||input[i][j-1] ||input[i][j+1] ||input[i][j+2]||input[i+1][j-2])
                                if( input[i+1][j-1] ||input[i+1][j] ||input[i+1][j+1] ||input[i+1][j+2])
                                    if(input[i+2][j-2] || input[i+2][j-1] ||input[i+2][j] ||input[i+2][j+1] ||input[i+2][j+2])
                                        output[i][j] = 255;

            }
    }
}

void J_Histogram(KImageGray img, KVector& vec){
    //init.
    vec.Create(256);

    //Histogram
    for(int ii=img.Row(),i=0; ii; ii--, i++)
        for(int jj=img.Col(),j=0; jj; jj--, j++)
            vec[img[i][j]] ++;

}

//gray image Histogram Equalization
void J_HE(KImageGray input, KImageGray& output){

    KVector vec;
    J_Histogram(input, vec);

    //accumulated histogram
    double*  dp = vec.Address();
    for(int i=1, ic=vec.Size()-1; ic; ic--, i++)
        dp[i] += dp[i-1];

    //Histogram Equalization
    for(int i=0, ic=vec.Size(); ic; ic--, i++)
        dp[i] = dp[i] / (double)(input.Size());

    for(int ic=input.Row(),i=0; ic; ic--,i++)
        for(int jc=input.Col(),j=0; jc; jc--,j++)
            output[i][j] = (unsigned char)(dp[input[i][j]]*255.0 + 0.5);

}

//RGB Image histogram Equalization
void color_HE(KImageColor input, KImageColor& output){
    //RGB Image to gray image
    KImageGray R(input.Row(),input.Col());
    R = rgbtorgray(input);
    KImageGray G(input.Row(),input.Col());
    G = rgbtoggray(input);
    KImageGray B(input.Row(),input.Col());
    B = rgbtobgray(input);

    //gray image Histogram Equalization
    J_HE(R, R);
    J_HE(G, G);
    J_HE(B, B);

    //change the output RGB image
    for(int i = 0, ii = input.Row();ii;ii--,i++)
        for(int j = 0, jj = input.Col();jj;jj--,j++){
            output[i][j].r = R[i][j];
            output[i][j].g = G[i][j];
            output[i][j].b = B[i][j];
        }
}

//sum
void J_deviation(KVector input, double& N){
    double dSum = 0.0;

    for(int i=0,ii=input.Dim(); ii; i++,ii--)
    {
        dSum 	+= input[i];
    }
    N = dSum;
}

void J_HM(KImageGray input,KImageGray REF,KImageGray& output){

    //initialize
    KImageGray r(input.Row(),input.Col()), s(REF.Row(),REF.Col());
    KVector r_vec, s_vec, yr_vec, ys_vec;
    J_Histogram(input, r_vec);
    J_Histogram(REF, s_vec);
    double r_d,s_d;

    //Source image
    yr_vec.Create(256);
    J_deviation(r_vec, r_d);
    for(int i=0,ii=r_vec.Size(); ii; i++,ii--){
        int tmp = i+1;
        for(int j = 0;tmp;j++,tmp--){
            yr_vec[i] += r_vec[j];
        }
        yr_vec[i] /= r_d;

    }

    //reference image
    ys_vec.Create(256);
    J_deviation(s_vec,s_d);
    for(int i=0,ii=s_vec.Size(); ii; i++,ii--){
        int tmp = i+1;
        for(int j = 0;tmp;j++,tmp--){
            ys_vec[i] += s_vec[j];
        }
        ys_vec[i] /= s_d;
    }

    //Histogram Matching
    KVector out_num(256);
    KVector out_val(256);
    double tmp = 1;
    for(int i=0,ii=r_vec.Size(); ii; i++,ii--){
        tmp = 1;
        for(int j=0,jj=s_vec.Size(); jj; j++,jj--){
            if(abs(yr_vec[i]-ys_vec[j]) <= tmp){
                out_num[i]=j;
                tmp = abs(yr_vec[i]-ys_vec[j]);
            }
        }
    }
    for(int i=0,ii=r_vec.Size(); ii; i++,ii--){
        out_val[i] = yr_vec[out_num[i]];
    }
    for(int i=0,ii=output.Row(); ii; i++,ii--)
        for(int j=0,jj=output.Col(); jj; j++,jj--){
            output[i][j] = (unsigned char)(out_val[input[i][j]]*255.0+0.5);
        }
}

//RGB Image Histogram Matching
void color_HM(KImageColor sourse, KImageColor REF, KImageColor& out){

    //source image to gray
    KImageGray s_R(sourse.Row(),sourse.Col());
    s_R = rgbtorgray(sourse);
    KImageGray s_G(sourse.Row(),sourse.Col());
    s_G = rgbtoggray(sourse);
    KImageGray s_B(sourse.Row(),sourse.Col());
    s_B = rgbtobgray(sourse);

    //reference image to gray
    KImageGray r_R(REF.Row(),REF.Col());
    r_R = rgbtorgray(REF);
    KImageGray r_G(REF.Row(),REF.Col());
    r_G = rgbtoggray(REF);
    KImageGray r_B(REF.Row(),REF.Col());
    r_B = rgbtobgray(REF);

    //gray image Histogram Matching
    J_HM(s_R, r_R, s_R);
    J_HM(s_G, r_G, s_G);
    J_HM(s_B, r_B, s_B);

    //change the output RGB image
    for(int i = 0, ii = sourse.Row();ii;ii--,i++)
        for(int j = 0, jj = sourse.Col();jj;jj--,j++){
            out[i][j].r = s_R[i][j];
            out[i][j].g = s_G[i][j];
            out[i][j].b = s_B[i][j];
        }
}





