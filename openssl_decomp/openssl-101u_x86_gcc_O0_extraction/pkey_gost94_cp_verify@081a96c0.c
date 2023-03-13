
undefined4
pkey_gost94_cp_verify
          (EVP_PKEY_CTX *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  EVP_PKEY *pkey;
  DSA_SIG *a;
  void *pvVar1;
  undefined4 uVar2;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  a = (DSA_SIG *)unpack_cp_signature(param_2,param_3);
  if (a != (DSA_SIG *)0x0) {
    uVar2 = 0;
    if (pkey != (EVP_PKEY *)0x0) {
      pvVar1 = EVP_PKEY_get0(pkey);
      uVar2 = gost_do_verify(param_4,param_5,a,pvVar1);
    }
    DSA_SIG_free(a);
    return uVar2;
  }
  return 0;
}

