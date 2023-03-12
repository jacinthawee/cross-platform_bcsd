
undefined4 dh_param_decode(undefined4 param_1,uchar **param_2,long param_3)

{
  DH *pDVar1;
  
  pDVar1 = d2i_DHparams((DH **)0x0,param_2,param_3);
  if (pDVar1 != (DH *)0x0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x1c,pDVar1);
    return 1;
  }
  ERR_put_error(5,0x6b,5,"dh_ameth.c",0x130);
  return 0;
}

