
undefined4 dsa_cb(int param_1,DSA **param_2)

{
  DSA *pDVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    pDVar1 = DSA_new();
    uVar2 = 2;
    if (pDVar1 == (DSA *)0x0) {
      uVar2 = 0;
    }
    *param_2 = pDVar1;
    return uVar2;
  }
  if (param_1 != 2) {
    return 1;
  }
  DSA_free(*param_2);
  *param_2 = (DSA *)0x0;
  return 2;
}

