
void make_cp_exchange_key(BIGNUM *param_1,EVP_PKEY *param_2,undefined4 param_3)

{
  DH *dh;
  BIGNUM *pBVar1;
  void *pvVar2;
  DH *pDVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar uStack_129;
  uchar local_128 [128];
  uchar auStack_a8 [132];
  int local_24;
  
  local_24 = __stack_chk_guard;
  dh = DH_new();
  pDVar3 = dh;
  if (dh != (DH *)0x0) {
    memset(local_128,0,0x80);
    pBVar1 = BN_dup(((param_2->pkey).rsa)->e);
    dh->g = pBVar1;
    pBVar1 = BN_dup(((param_2->pkey).dsa)->p);
    dh->p = pBVar1;
    pBVar1 = BN_dup(param_1);
    dh->priv_key = pBVar1;
    pvVar2 = EVP_PKEY_get0(param_2);
    pDVar3 = (DH *)DH_compute_key(auStack_a8,*(BIGNUM **)((int)pvVar2 + 0x18),dh);
    if (pDVar3 == (DH *)0x0) {
      DH_free(dh);
    }
    else {
      memset(local_128,0,0x80);
      if (0 < (int)pDVar3) {
        puVar4 = auStack_a8 + (int)pDVar3;
        puVar5 = &uStack_129;
        do {
          puVar4 = puVar4 + -1;
          puVar5 = puVar5 + 1;
          *puVar5 = *puVar4;
        } while (puVar4 != auStack_a8);
      }
      DH_free(dh);
      init_gost_hash_ctx(auStack_a8,GostR3411_94_CryptoProParamSet);
      start_hash(auStack_a8);
      hash_block(auStack_a8,local_128,0x80);
      finish_hash(auStack_a8,param_3);
      done_gost_hash_ctx(auStack_a8);
      pDVar3 = (DH *)0x1;
    }
  }
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pDVar3);
}

