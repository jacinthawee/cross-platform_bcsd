
/* WARNING: Removing unreachable block (ram,0x0050e5b8) */
/* WARNING: Removing unreachable block (ram,0x0050e578) */
/* WARNING: Removing unreachable block (ram,0x0050e57c) */
/* WARNING: Removing unreachable block (ram,0x0050e4a4) */
/* WARNING: Removing unreachable block (ram,0x0050e4bc) */
/* WARNING: Removing unreachable block (ram,0x0050e4d4) */
/* WARNING: Removing unreachable block (ram,0x0050e4f8) */
/* WARNING: Removing unreachable block (ram,0x0050e510) */

BN_BLINDING * rsa_get_blinding(RSA *param_1,undefined4 *param_2,BN_CTX *param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  int iVar6;
  uchar *to;
  BIGNUM *pBVar7;
  int iVar8;
  BN_MONT_CTX *pBVar9;
  uchar *s;
  undefined4 uVar10;
  BN_BLINDING *pBVar11;
  undefined auStack_34 [8];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  bVar1 = false;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_CRYPTO_lock_006a926c)(5,9,&DAT_006675d8,0x105);
  pBVar11 = param_1->blinding;
  if (pBVar11 == (BN_BLINDING *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(6,9,&DAT_006675d8,0x109);
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,9,&DAT_006675d8,0x10a);
    pBVar11 = param_1->blinding;
    if (pBVar11 != (BN_BLINDING *)0x0) {
      bVar1 = true;
      goto LAB_0050dfa0;
    }
    pBVar11 = RSA_setup_blinding(param_1,param_3);
    param_1->blinding = pBVar11;
    if (pBVar11 != (BN_BLINDING *)0x0) {
      bVar1 = true;
      goto LAB_0050dfa0;
    }
LAB_0050e06c:
    iVar4 = 0x137;
    s = &DAT_00000009;
    (*(code *)PTR_CRYPTO_lock_006a926c)(10);
  }
  else {
LAB_0050dfa0:
    (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(auStack_34);
    uVar3 = (*(code *)PTR_BN_BLINDING_thread_id_006a9800)(pBVar11);
    iVar4 = (*(code *)PTR_CRYPTO_THREADID_cmp_006a95a0)(auStack_34,uVar3);
    if (iVar4 == 0) {
      *param_2 = 1;
    }
    else {
      pBVar11 = param_1->mt_blinding;
      *param_2 = 0;
      if (pBVar11 == (BN_BLINDING *)0x0) {
        if (!bVar1) {
          (*(code *)PTR_CRYPTO_lock_006a926c)(6,9,&DAT_006675d8,0x12a);
          (*(code *)PTR_CRYPTO_lock_006a926c)(9,9,&DAT_006675d8,299);
          pBVar11 = param_1->mt_blinding;
          if (pBVar11 != (BN_BLINDING *)0x0) goto LAB_0050e06c;
        }
        pBVar11 = RSA_setup_blinding(param_1,param_3);
        param_1->mt_blinding = pBVar11;
        goto LAB_0050e06c;
      }
    }
    if (bVar1) goto LAB_0050e06c;
    iVar4 = 0x139;
    s = &DAT_00000009;
    (*(code *)PTR_CRYPTO_lock_006a926c)(6);
  }
  if (local_2c == *(int *)puVar2) {
    return pBVar11;
  }
  iVar8 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar5 = BN_num_bits(*(BIGNUM **)(iVar4 + 0x10));
  if (0x4000 < iVar5) {
    uVar10 = 0x69;
    uVar3 = 0x284;
LAB_0050e358:
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x67,uVar10,&DAT_006675d8,uVar3);
    return (BN_BLINDING *)0xffffffff;
  }
  iVar5 = BN_ucmp(*(BIGNUM **)(iVar4 + 0x10),*(BIGNUM **)(iVar4 + 0x14));
  if (iVar5 < 1) {
    uVar10 = 0x65;
    uVar3 = 0x28a;
    goto LAB_0050e358;
  }
  iVar5 = BN_num_bits(*(BIGNUM **)(iVar4 + 0x10));
  if ((0xc00 < iVar5) && (iVar5 = BN_num_bits(*(BIGNUM **)(iVar4 + 0x14)), 0x40 < iVar5)) {
    uVar10 = 0x65;
    uVar3 = 0x293;
    goto LAB_0050e358;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return (BN_BLINDING *)0xffffffff;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  a = BN_CTX_get(ctx);
  iVar6 = BN_num_bits(*(BIGNUM **)(iVar4 + 0x10));
  iVar5 = iVar6 + 7;
  if (iVar6 + 7 < 0) {
    iVar5 = iVar6 + 0xe;
  }
  iVar5 = iVar5 >> 3;
  to = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar5,&DAT_006675d8,0x29d);
  if (((ret == (BIGNUM *)0x0) || (a == (BIGNUM *)0x0)) || (to == (uchar *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x67,0x41,&DAT_006675d8,0x2a0);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return (BN_BLINDING *)0xffffffff;
    }
    goto LAB_0050e2d8;
  }
  if (iVar5 < iVar8) {
    uVar10 = 0x6c;
    uVar3 = 0x2a8;
LAB_0050e2a4:
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x67,uVar10,&DAT_006675d8,uVar3);
  }
  else {
    pBVar7 = BN_bin2bn(s,iVar8,ret);
    if (pBVar7 != (BIGNUM *)0x0) {
      iVar8 = BN_ucmp(ret,*(BIGNUM **)(iVar4 + 0x10));
      if (iVar8 < 0) {
        if ((((*(uint *)(iVar4 + 0x3c) & 2) != 0) &&
            (pBVar9 = BN_MONT_CTX_set_locked
                                ((BN_MONT_CTX **)(iVar4 + 0x40),9,*(BIGNUM **)(iVar4 + 0x10),ctx),
            pBVar9 == (BN_MONT_CTX *)0x0)) ||
           (iVar4 = (**(code **)(*(int *)(iVar4 + 8) + 0x18))
                              (a,ret,*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x10),ctx
                               ,*(undefined4 *)(iVar4 + 0x40)), iVar4 == 0)) goto LAB_0050e2b4;
        BN_bn2bin(a,to);
        uVar10 = 0x76;
        uVar3 = 0x2cd;
      }
      else {
        uVar10 = 0x84;
        uVar3 = 0x2b0;
      }
      goto LAB_0050e2a4;
    }
  }
LAB_0050e2b4:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_0050e2d8:
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(to,iVar5);
  (*(code *)PTR_CRYPTO_free_006a7f88)(to);
  return (BN_BLINDING *)0xffffffff;
}

