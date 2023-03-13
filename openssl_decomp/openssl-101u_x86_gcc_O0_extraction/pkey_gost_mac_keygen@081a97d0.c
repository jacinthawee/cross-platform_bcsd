
undefined4 pkey_gost_mac_keygen(EVP_PKEY_CTX *param_1,EVP_PKEY *param_2)

{
  int *piVar1;
  int *key;
  
  piVar1 = (int *)EVP_PKEY_CTX_get_data(param_1);
  if (*piVar1 != 0) {
    key = (int *)CRYPTO_malloc(0x20,"gost_pmeth.c",0x20f);
    *key = piVar1[2];
    key[1] = piVar1[3];
    key[2] = piVar1[4];
    key[3] = piVar1[5];
    key[4] = piVar1[6];
    key[5] = piVar1[7];
    key[6] = piVar1[8];
    key[7] = piVar1[9];
    EVP_PKEY_assign(param_2,0x32f,key);
    return 1;
  }
  ERR_GOST_error(0x82,0x74,"gost_pmeth.c",0x20c);
  return 0;
}

