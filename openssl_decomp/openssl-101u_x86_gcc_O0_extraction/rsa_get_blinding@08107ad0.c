
BN_BLINDING * __regparm3 rsa_get_blinding(RSA *param_1,undefined4 *param_2,BN_CTX *param_3)

{
  bool bVar1;
  int mode;
  CRYPTO_THREADID *b;
  BN_BLINDING *mode_00;
  BN_BLINDING *pBVar2;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_28;
  int local_20;
  
  bVar1 = false;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  mode = 0;
  CRYPTO_lock(0,5,(char *)0x9,(int)"rsa_eay.c");
  pBVar2 = param_1->blinding;
  if (param_1->blinding == (BN_BLINDING *)0x0) {
    bVar1 = true;
    CRYPTO_lock(mode,6,(char *)0x9,(int)"rsa_eay.c");
    CRYPTO_lock(mode,9,(char *)0x9,(int)"rsa_eay.c");
    pBVar2 = param_1->blinding;
    if (param_1->blinding != (BN_BLINDING *)0x0) goto LAB_08107b0e;
    mode_00 = RSA_setup_blinding(param_1,param_3);
    param_1->blinding = mode_00;
    pBVar2 = mode_00;
    if (mode_00 != (BN_BLINDING *)0x0) goto LAB_08107b0e;
  }
  else {
LAB_08107b0e:
    CRYPTO_THREADID_current(&local_28);
    b = BN_BLINDING_thread_id(pBVar2);
    mode_00 = (BN_BLINDING *)CRYPTO_THREADID_cmp(&local_28,b);
    if (mode_00 == (BN_BLINDING *)0x0) {
      *param_2 = 1;
    }
    else {
      pBVar2 = param_1->mt_blinding;
      *param_2 = 0;
      if (pBVar2 == (BN_BLINDING *)0x0) {
        if (!bVar1) {
          CRYPTO_lock((int)mode_00,6,(char *)0x9,(int)"rsa_eay.c");
          CRYPTO_lock((int)mode_00,9,(char *)0x9,(int)"rsa_eay.c");
          pBVar2 = param_1->mt_blinding;
          if (param_1->mt_blinding != (BN_BLINDING *)0x0) goto LAB_08107b92;
        }
        mode_00 = RSA_setup_blinding(param_1,param_3);
        param_1->mt_blinding = mode_00;
        pBVar2 = mode_00;
        goto LAB_08107b92;
      }
    }
    if (!bVar1) {
      CRYPTO_lock((int)mode_00,6,(char *)0x9,(int)"rsa_eay.c");
      goto LAB_08107b66;
    }
  }
LAB_08107b92:
  CRYPTO_lock((int)mode_00,10,(char *)0x9,(int)"rsa_eay.c");
LAB_08107b66:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pBVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

