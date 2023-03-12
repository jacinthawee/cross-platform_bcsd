
BN_BLINDING * rsa_get_blinding(RSA *param_1,undefined4 *param_2,BN_CTX *param_3)

{
  bool bVar1;
  CRYPTO_THREADID *b;
  int iVar2;
  BN_BLINDING *pBVar3;
  CRYPTO_THREADID CStack_20;
  
  CRYPTO_lock(5,9,"rsa_eay.c",0x105);
  pBVar3 = param_1->blinding;
  bVar1 = false;
  if (pBVar3 == (BN_BLINDING *)0x0) {
    CRYPTO_lock(6,9,"rsa_eay.c",0x109);
    CRYPTO_lock(9,9,"rsa_eay.c",0x10a);
    pBVar3 = param_1->blinding;
    if (pBVar3 == (BN_BLINDING *)0x0) {
      pBVar3 = RSA_setup_blinding(param_1,param_3);
      param_1->blinding = pBVar3;
      if (pBVar3 == (BN_BLINDING *)0x0) goto LAB_00095c8a;
    }
    bVar1 = true;
  }
  CRYPTO_THREADID_current(&CStack_20);
  b = BN_BLINDING_thread_id(pBVar3);
  iVar2 = CRYPTO_THREADID_cmp(&CStack_20,b);
  if (iVar2 == 0) {
    *param_2 = 1;
  }
  else {
    pBVar3 = param_1->mt_blinding;
    *param_2 = 0;
    if (pBVar3 == (BN_BLINDING *)0x0) {
      if (!bVar1) {
        CRYPTO_lock(6,9,"rsa_eay.c",0x12a);
        CRYPTO_lock(9,9,"rsa_eay.c",299);
        pBVar3 = param_1->mt_blinding;
        if (pBVar3 != (BN_BLINDING *)0x0) goto LAB_00095c8a;
      }
      pBVar3 = RSA_setup_blinding(param_1,param_3);
      param_1->mt_blinding = pBVar3;
      goto LAB_00095c8a;
    }
  }
  if (!bVar1) {
    CRYPTO_lock(6,9,"rsa_eay.c",0x139);
    return pBVar3;
  }
LAB_00095c8a:
  CRYPTO_lock(10,9,"rsa_eay.c",0x137);
  return pBVar3;
}

