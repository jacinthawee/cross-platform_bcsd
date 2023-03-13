
bool cms_cb(int param_1,CMS_ContentInfo **param_2,undefined4 param_3,BIO **param_4)

{
  CMS_ContentInfo *cms;
  int iVar1;
  BIO *pBVar2;
  
  if (param_2 == (CMS_ContentInfo **)0x0) {
    return true;
  }
  cms = *param_2;
  if (param_1 != 0xb) {
    if (param_1 < 0xc) {
      if (param_1 != 10) {
        return true;
      }
      iVar1 = CMS_stream((uchar ***)(param_4 + 2),cms);
      if (iVar1 < 1) {
        return false;
      }
    }
    else if (param_1 != 0xc) {
      if (param_1 != 0xd) {
        return true;
      }
      goto LAB_0818b478;
    }
    pBVar2 = CMS_dataInit(cms,*param_4);
    param_4[1] = pBVar2;
    return pBVar2 != (BIO *)0x0;
  }
LAB_0818b478:
  iVar1 = CMS_dataFinal(cms,param_4[1]);
  return 0 < iVar1;
}

