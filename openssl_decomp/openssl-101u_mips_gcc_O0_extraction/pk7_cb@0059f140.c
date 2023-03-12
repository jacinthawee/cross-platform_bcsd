
bool pk7_cb(int param_1,PKCS7 **param_2,undefined4 param_3,BIO **param_4)

{
  BIO *pBVar1;
  int iVar2;
  
  if (param_1 == 0xb) {
LAB_0059f1b8:
    iVar2 = PKCS7_dataFinal(*param_2,param_4[1]);
    return 0 < iVar2;
  }
  if (param_1 < 0xc) {
    if (param_1 != 10) {
      return true;
    }
    iVar2 = PKCS7_stream((uchar ***)(param_4 + 2),*param_2);
    if (iVar2 < 1) {
      return false;
    }
  }
  else if (param_1 != 0xc) {
    if (param_1 != 0xd) {
      return true;
    }
    goto LAB_0059f1b8;
  }
  pBVar1 = PKCS7_dataInit(*param_2,*param_4);
  param_4[1] = pBVar1;
  return pBVar1 != (BIO *)0x0;
}

