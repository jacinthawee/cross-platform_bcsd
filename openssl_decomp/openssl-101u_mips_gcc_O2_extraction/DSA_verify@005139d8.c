
int DSA_verify(int type,uchar *dgst,int dgst_len,uchar *sigbuf,int siglen,DSA *dsa)

{
  undefined *puVar1;
  int iVar2;
  BIGNUM *pBVar3;
  uchar *dgst_00;
  BIGNUM *pBVar4;
  undefined1 *sig;
  undefined1 *dsa_00;
  BIGNUM *local_30;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  uchar *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_28 = (BIGNUM *)0x0;
  local_24 = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  pBVar4 = (BIGNUM *)dgst;
  sig = (undefined1 *)dgst_len;
  dsa_00 = sigbuf;
  local_2c = (BIGNUM *)sigbuf;
  local_30 = (BIGNUM *)DSA_SIG_new();
  if (local_30 == (BIGNUM *)0x0) {
    iVar2 = -1;
    goto LAB_00513ac4;
  }
  pBVar4 = (BIGNUM *)&local_2c;
  dsa_00 = DSA_SIG_it;
  sig = (undefined1 *)siglen;
  iVar2 = (*(code *)PTR_ASN1_item_d2i_006a8674)(&local_30);
  if (iVar2 == 0) {
    iVar2 = -1;
  }
  else {
    sig = DSA_SIG_it;
    pBVar4 = (BIGNUM *)&local_28;
    pBVar3 = (BIGNUM *)(*(code *)PTR_ASN1_item_i2d_006a8678)(local_30);
    if ((BIGNUM *)siglen == pBVar3) {
      pBVar4 = local_28;
      sig = (undefined1 *)pBVar3;
      iVar2 = (*(code *)PTR_memcmp_006a9ad0)(sigbuf);
      if (iVar2 != 0) goto LAB_00513a88;
      sig = (undefined1 *)local_30;
      iVar2 = DSA_do_verify(dgst,dgst_len,(DSA_SIG *)local_30,dsa);
      dsa_00 = (undefined1 *)dsa;
    }
    else {
LAB_00513a88:
      dgst_len = (int)pBVar4;
      iVar2 = -1;
    }
    pBVar4 = (BIGNUM *)dgst_len;
    if (0 < (int)pBVar3) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_28);
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_28);
      pBVar4 = pBVar3;
    }
  }
  DSA_SIG_free((DSA_SIG *)local_30);
LAB_00513ac4:
  if (local_24 == *(uchar **)puVar1) {
    return iVar2;
  }
  dgst_00 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00513b68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(*(DSA_METHOD **)((int)dsa_00 + 0x3c))->dsa_do_verify)
                    (dgst_00,(int)pBVar4,(DSA_SIG *)sig,(DSA *)dsa_00);
  return iVar2;
}

