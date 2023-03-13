
byte dsa_cb(int param_1,DSA **param_2)

{
  DSA *pDVar1;
  
  if (param_1 == 0) {
    pDVar1 = DSA_new();
    *param_2 = pDVar1;
    return ~-(pDVar1 == (DSA *)0x0) & 2;
  }
  if (param_1 != 2) {
    return 1;
  }
  DSA_free(*param_2);
  *param_2 = (DSA *)0x0;
  return 2;
}

