
undefined4
pkey_gost94_cp_sign(EVP_PKEY_CTX *param_1,void *param_2,undefined4 *param_3,undefined4 param_4,
                   undefined4 param_5)

{
  EVP_PKEY *pkey;
  void *pvVar1;
  DSA_SIG *a;
  int iVar2;
  BIGNUM *pBVar3;
  int iVar4;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  if (param_3 != (undefined4 *)0x0) {
    if (param_2 == (void *)0x0) {
      *param_3 = 0x40;
      return 1;
    }
    pvVar1 = EVP_PKEY_get0(pkey);
    a = (DSA_SIG *)gost_do_sign(param_4,param_5,pvVar1);
    if (a != (DSA_SIG *)0x0) {
      *param_3 = 0x40;
      memset(param_2,0,0x40);
      pBVar3 = a->s;
      iVar2 = BN_num_bits(pBVar3);
      iVar4 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar4 = iVar2 + 7;
      }
      if (iVar4 >> 3 < 0x21) {
        memset(param_2,0,0x20);
        BN_bn2bin(pBVar3,(uchar *)((0x20 - (iVar4 >> 3)) + (int)param_2));
      }
      pBVar3 = a->r;
      iVar2 = BN_num_bits(pBVar3);
      iVar4 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar4 = iVar2 + 7;
      }
      if (iVar4 >> 3 < 0x21) {
        memset((void *)((int)param_2 + 0x20),0,0x20);
        BN_bn2bin(pBVar3,(uchar *)((0x20 - (iVar4 >> 3)) + (int)(void *)((int)param_2 + 0x20)));
      }
      DSA_SIG_free(a);
      return 1;
    }
  }
  return 0;
}

