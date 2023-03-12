
byte dh_cb(int param_1,DH **param_2)

{
  DH *pDVar1;
  
  if (param_1 == 0) {
    pDVar1 = DH_new();
    *param_2 = pDVar1;
    return ~-(pDVar1 == (DH *)0x0) & 2;
  }
  if (param_1 != 2) {
    return 1;
  }
  DH_free(*param_2);
  *param_2 = (DH *)0x0;
  return 2;
}

