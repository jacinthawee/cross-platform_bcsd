
uchar * KDF1_SHA1(uchar *param_1,size_t param_2,uchar *param_3,uint *param_4)

{
  uchar *puVar1;
  
  if (0x13 < *param_4) {
    *param_4 = 0x14;
    puVar1 = SHA1(param_1,param_2,param_3);
    return puVar1;
  }
  return (uchar *)0x0;
}

