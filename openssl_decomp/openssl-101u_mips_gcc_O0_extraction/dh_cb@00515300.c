
undefined4 dh_cb(int param_1,DH **param_2)

{
  DH *pDVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    pDVar1 = DH_new();
    uVar2 = 2;
    if (pDVar1 == (DH *)0x0) {
      uVar2 = 0;
    }
    *param_2 = pDVar1;
    return uVar2;
  }
  if (param_1 != 2) {
    return 1;
  }
  DH_free(*param_2);
  *param_2 = (DH *)0x0;
  return 2;
}
