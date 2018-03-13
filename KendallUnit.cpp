//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KendallUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKendallForm *KendallForm;
//---------------------------------------------------------------------------

float kendall_func( float *arr1, float *arr2, int len )
{
    int m1 = 0, m2 = 0, s = 0, nPair , i,j ;
    float cor ;

	for(i = 0; i < len; i++) {
        for(j = i + 1; j < len; j++) {
            if(arr2[i] > arr2[j]) {
                if (arr1[i] > arr1[j]) {
                    s++;
                } else if(arr1[i] < arr1[j]) {
                    s--;
                } else {
                    m1++;
                }
            } else if(arr2[i] < arr2[j]) {
                if (arr1[i] > arr1[j]) {
                    s--;
                } else if(arr1[i] < arr1[j]) {
                    s++;
                } else {
                    m1++;
                }
            } else {
                m2++;

                if(arr1[i] == arr1[j]) {
                    m1++;
                }
            }
        }
    }

    nPair = len * (len - 1) / 2;

    if( m1 < nPair && m2 < nPair )
      cor = s / ( sqrtf((float)(nPair-m1)) * sqrtf((float)(nPair-m2)) ) ;
    else
      cor = 0.0f ;

    return cor ;
}
//---------------------------------------------------------------------------

__fastcall TKendallForm::TKendallForm(TComponent* Owner)
	: TForm(Owner)
{
	try{
		for (int j = 0; j < 2; j++) {
			this->StringGridKendall->Cells[j+1][0] = MainForm->ListBoxMain->Items->Strings[j];
			this->StringGridKendall->Cells[0][j+1] = MainForm->ListBoxMain->Items->Strings[j];
		}
		int t = MainForm->StringGridExcel->RowCount - 1;
		float *arr1, *arr2;
		arr1 = (float*) calloc (t,sizeof(float));
		arr2 = (float*) calloc (t,sizeof(float));
		int j1 = StrToInt(MainForm->ListBoxNumbers->Items->Strings[0]);
		int j2 = StrToInt(MainForm->ListBoxNumbers->Items->Strings[1]);
		bool WAT = true;;
		try{
			for (int i = 1; i < t+1; i++) {
				arr1[i-1] = StrToFloat(MainForm->StringGridExcel->Cells[j1][i]);
				arr2[i-1] = StrToFloat(MainForm->StringGridExcel->Cells[j2][i]);
			}
		}
		catch(...){
			Application->MessageBox(L"Try another data!!",
			L"Error",MB_OK+MB_ICONERROR);
			WAT = false;
		}
		free(arr1);
		free(arr2);
		if (WAT == true) {
			float cor = kendall_func(arr1, arr2, t);
			this->StringGridKendall->Cells[2][1] = cor;
			this->StringGridKendall->Cells[1][2] = cor;
			this->StringGridKendall->Cells[1][1] = 1;
			this->StringGridKendall->Cells[2][2] = 1;
		}
	}
	catch(...){
	}
}
