
undefined4 dh_param_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  DH *key;
  
  key = d2i_DHparams((DH **)0x0,param_2,param_3);
  if (key != (DH *)0x0) {
    EVP_PKEY_assign(param_1,0x1c,key);
    return 1;
  }
  ERR_put_error(5,0x6b,5,"dh_ameth.c",0x130);
  return 0;
}

