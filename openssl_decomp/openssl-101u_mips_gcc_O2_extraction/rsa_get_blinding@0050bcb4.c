
/* WARNING: Removing unreachable block (ram,0x0050c348) */
/* WARNING: Removing unreachable block (ram,0x0050c308) */
/* WARNING: Removing unreachable block (ram,0x0050c30c) */
/* WARNING: Removing unreachable block (ram,0x0050c234) */
/* WARNING: Removing unreachable block (ram,0x0050c24c) */
/* WARNING: Removing unreachable block (ram,0x0050c264) */
/* WARNING: Removing unreachable block (ram,0x0050c288) */
/* WARNING: Removing unreachable block (ram,0x0050c2a0) */

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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  bVar1 = false;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_CRYPTO_lock_006a8144)(5,9,&DAT_00666c88,0x106);
  pBVar11 = param_1->blinding;
  if (pBVar11 == (BN_BLINDING *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(6,9,&DAT_00666c88,0x109);
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,9,&DAT_00666c88,0x10a);
    pBVar11 = param_1->blinding;
    if (pBVar11 != (BN_BLINDING *)0x0) {
      bVar1 = true;
      goto LAB_0050bd30;
    }
    pBVar11 = RSA_setup_blinding(param_1,param_3);
    param_1->blinding = pBVar11;
    if (pBVar11 != (BN_BLINDING *)0x0) {
      bVar1 = true;
      goto LAB_0050bd30;
    }
LAB_0050bdfc:
    iVar4 = 0x133;
    s = &DAT_00000009;
    (*(code *)PTR_CRYPTO_lock_006a8144)(10);
  }
  else {
LAB_0050bd30:
    (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(auStack_34);
    uVar3 = (*(code *)PTR_BN_BLINDING_thread_id_006a86dc)(pBVar11);
    iVar4 = (*(code *)PTR_CRYPTO_THREADID_cmp_006a8480)(auStack_34,uVar3);
    if (iVar4 == 0) {
      *param_2 = 1;
    }
    else {
      pBVar11 = param_1->mt_blinding;
      *param_2 = 0;
      if (pBVar11 == (BN_BLINDING *)0x0) {
        if (!bVar1) {
          (*(code *)PTR_CRYPTO_lock_006a8144)(6,9,&DAT_00666c88,0x126);
          (*(code *)PTR_CRYPTO_lock_006a8144)(9,9,&DAT_00666c88,0x127);
          pBVar11 = param_1->mt_blinding;
          if (pBVar11 != (BN_BLINDING *)0x0) goto LAB_0050bdfc;
        }
        pBVar11 = RSA_setup_blinding(param_1,param_3);
        param_1->mt_blinding = pBVar11;
        goto LAB_0050bdfc;
      }
    }
    if (bVar1) goto LAB_0050bdfc;
    iVar4 = 0x135;
    s = &DAT_00000009;
    (*(code *)PTR_CRYPTO_lock_006a8144)(6);
  }
  if (local_2c == *(int *)puVar2) {
    return pBVar11;
  }
  iVar8 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar5 = BN_num_bits(*(BIGNUM **)(iVar4 + 0x10));
  if (0x4000 < iVar5) {
    uVar10 = 0x69;
    uVar3 = 0x273;
LAB_0050c0e8:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x67,uVar10,&DAT_00666c88,uVar3);
    return (BN_BLINDING *)0xffffffff;
  }
  iVar5 = BN_ucmp(*(BIGNUM **)(iVar4 + 0x10),*(BIGNUM **)(iVar4 + 0x14));
  if (iVar5 < 1) {
    uVar10 = 0x65;
    uVar3 = 0x278;
    goto LAB_0050c0e8;
  }
  iVar5 = BN_num_bits(*(BIGNUM **)(iVar4 + 0x10));
  if ((0xc00 < iVar5) && (iVar5 = BN_num_bits(*(BIGNUM **)(iVar4 + 0x14)), 0x40 < iVar5)) {
    uVar10 = 0x65;
    uVar3 = 0x27f;
    goto LAB_0050c0e8;
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
  to = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5,&DAT_00666c88,0x28a);
  if (((ret == (BIGNUM *)0x0) || (a == (BIGNUM *)0x0)) || (to == (uchar *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x67,0x41,&DAT_00666c88,0x28c);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return (BN_BLINDING *)0xffffffff;
    }
    goto LAB_0050c068;
  }
  if (iVar5 < iVar8) {
    uVar10 = 0x6c;
    uVar3 = 0x295;
LAB_0050c034:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x67,uVar10,&DAT_00666c88,uVar3);
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
                               ,*(undefined4 *)(iVar4 + 0x40)), iVar4 == 0)) goto LAB_0050c044;
        BN_bn2bin(a,to);
        uVar10 = 0x76;
        uVar3 = 0x2bd;
      }
      else {
        uVar10 = 0x84;
        uVar3 = 0x29e;
      }
      goto LAB_0050c034;
    }
  }
LAB_0050c044:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_0050c068:
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(to,iVar5);
  (*(code *)PTR_CRYPTO_free_006a6e88)(to);
  return (BN_BLINDING *)0xffffffff;
}

