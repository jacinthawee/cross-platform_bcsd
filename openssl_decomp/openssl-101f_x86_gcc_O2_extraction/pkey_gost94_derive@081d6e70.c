
undefined4 pkey_gost94_derive(EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3)

{
  uchar uVar1;
  DH *dh;
  BIGNUM *pBVar2;
  void *pvVar3;
  uchar *puVar4;
  EVP_PKEY *pkey;
  BIGNUM *pBVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int in_GS_OFFSET;
  byte bVar10;
  undefined auStack_190 [112];
  undefined4 auStack_120 [31];
  uchar auStack_a1 [113];
  undefined4 uStack_30;
  int iStack_20;
  
  bVar10 = 0;
  uStack_30 = 0x81d6e89;
  pkey = EVP_PKEY_CTX_get0_peerkey(param_1);
  uStack_30 = 0x81d6e93;
  EVP_PKEY_CTX_get0_pkey(param_1);
  *param_3 = 0x20;
  if (param_2 == 0) {
    return 1;
  }
  uStack_30 = 0x81d6ea9;
  pBVar5 = (BIGNUM *)gost_get0_priv_key();
  uVar9 = 0;
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  dh = DH_new();
  if (dh != (DH *)0x0) {
    puVar8 = auStack_120;
    for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + (uint)bVar10 * -2 + 1;
    }
    pBVar2 = BN_dup(((pkey->pkey).rsa)->e);
    *(BIGNUM **)&dh->field_0xc = pBVar2;
    pBVar2 = BN_dup(((pkey->pkey).dsa)->p);
    *(BIGNUM **)&dh->field_0x8 = pBVar2;
    pBVar5 = BN_dup(pBVar5);
    *(BIGNUM **)&dh->field_0x18 = pBVar5;
    pvVar3 = EVP_PKEY_get0(pkey);
    iVar6 = DH_compute_key(auStack_a1 + 1,*(BIGNUM **)((int)pvVar3 + 0x18),dh);
    if (iVar6 == 0) {
      DH_free(dh);
    }
    else {
      puVar8 = auStack_120;
      for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + (uint)bVar10 * -2 + 1;
      }
      if (0 < iVar6) {
        puVar4 = auStack_a1 + iVar6;
        puVar8 = auStack_120;
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + -1;
          *(uchar *)puVar8 = uVar1;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        } while (puVar4 != auStack_a1);
      }
      DH_free(dh);
      init_gost_hash_ctx(auStack_190,GostR3411_94_CryptoProParamSet);
      start_hash(auStack_190);
      hash_block(auStack_190,auStack_120,0x80);
      uVar9 = 1;
      finish_hash(auStack_190,param_2);
      done_gost_hash_ctx(auStack_190);
    }
  }
  if (iStack_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

