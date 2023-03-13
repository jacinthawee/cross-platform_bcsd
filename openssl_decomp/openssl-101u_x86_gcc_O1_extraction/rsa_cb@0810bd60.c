
byte rsa_cb(int param_1,RSA **param_2)

{
  RSA *pRVar1;
  
  if (param_1 == 0) {
    pRVar1 = RSA_new();
    *param_2 = pRVar1;
    return ~-(pRVar1 == (RSA *)0x0) & 2;
  }
  if (param_1 != 2) {
    return 1;
  }
  RSA_free(*param_2);
  *param_2 = (RSA *)0x0;
  return 2;
}

