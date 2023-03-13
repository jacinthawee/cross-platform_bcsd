
undefined4 __regparm3 make_cp_exchange_key(BIGNUM *param_1,EVP_PKEY *param_2,undefined4 param_3)

{
  uchar uVar1;
  DH *dh;
  BIGNUM *pBVar2;
  void *pvVar3;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int in_GS_OFFSET;
  byte bVar9;
  undefined local_190 [112];
  undefined4 local_120 [31];
  uchar local_a1 [129];
  int local_20;
  
  bVar9 = 0;
  uVar8 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  dh = DH_new();
  if (dh != (DH *)0x0) {
    puVar7 = local_120;
    for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
    }
    pBVar2 = BN_dup(((param_2->pkey).rsa)->e);
    dh->g = pBVar2;
    pBVar2 = BN_dup(((param_2->pkey).dsa)->p);
    dh->p = pBVar2;
    pBVar2 = BN_dup(param_1);
    dh->priv_key = pBVar2;
    pvVar3 = EVP_PKEY_get0(param_2);
    iVar5 = DH_compute_key(local_a1 + 1,*(BIGNUM **)((int)pvVar3 + 0x18),dh);
    if (iVar5 == 0) {
      DH_free(dh);
    }
    else {
      puVar7 = local_120;
      for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
      }
      if (0 < iVar5) {
        puVar4 = local_a1 + iVar5;
        puVar7 = local_120;
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + -1;
          *(uchar *)puVar7 = uVar1;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        } while (puVar4 != local_a1);
      }
      DH_free(dh);
      init_gost_hash_ctx(local_190,GostR3411_94_CryptoProParamSet);
      start_hash(local_190);
      hash_block(local_190,local_120,0x80);
      uVar8 = 1;
      finish_hash(local_190,param_3);
      done_gost_hash_ctx(local_190);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

