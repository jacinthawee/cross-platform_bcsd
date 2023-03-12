
int i2d_ocsp_nonce(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    (*(code *)PTR_memcpy_006aabf4)(*param_2,param_1[2],*param_1,param_4,&_gp);
    iVar1 = *param_1;
    *param_2 = *param_2 + iVar1;
    return iVar1;
  }
  return *param_1;
}

