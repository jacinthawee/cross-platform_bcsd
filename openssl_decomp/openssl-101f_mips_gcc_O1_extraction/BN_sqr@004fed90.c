
int BN_sqr(BIGNUM *r,BIGNUM *a,BN_CTX *ctx)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined *puVar3;
  BIGNUM *a_00;
  ulong *puVar4;
  BIGNUM *pBVar5;
  BIGNUM *a_01;
  uint *puVar6;
  BIGNUM *pBVar7;
  BN_CTX *pBVar8;
  ulong *in_a3;
  uint uVar9;
  BN_CTX *pBVar10;
  int iVar11;
  BIGNUM *words;
  ulong auStack_ac [32];
  uint *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pBVar10 = (BN_CTX *)a->top;
  local_2c = *(uint **)PTR___stack_chk_guard_006aabf0;
  if ((int)pBVar10 < 1) {
    r->top = 0;
    iVar11 = 1;
    goto LAB_004feedc;
  }
  pBVar7 = a;
  pBVar8 = ctx;
  BN_CTX_start(ctx);
  a_01 = r;
  if (a == r) {
    a_01 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if (((a_01 == (BIGNUM *)0x0) || (a_00 == (BIGNUM *)0x0)) ||
     ((words = (BIGNUM *)((int)pBVar10 * 2), a_01->dmax < (int)words &&
      (pBVar7 = words, pBVar5 = bn_expand2(a_01,(int)words), pBVar5 == (BIGNUM *)0x0))))
  goto LAB_004feec4;
  if (pBVar10 == (BN_CTX *)&SUB_00000004) {
    pBVar10 = (BN_CTX *)&SUB_00000004;
    pBVar7 = (BIGNUM *)a->d;
    bn_sqr_comba4(a_01->d);
LAB_004fee6c:
    puVar4 = a->d;
    a_01->neg = 0;
    if (puVar4[(int)(pBVar10 + -1)] == (puVar4[(int)(pBVar10 + -1)] & 0xffff)) {
      words = (BIGNUM *)((int)&words[-1].flags + 3);
    }
    a_01->top = (int)words;
    if (a_01 == r) {
      iVar11 = 1;
    }
    else {
      iVar11 = 1;
      BN_copy(r,a_01);
      pBVar7 = a_01;
    }
  }
  else {
    if (pBVar10 == (BN_CTX *)&DAT_00000008) {
      pBVar10 = (BN_CTX *)&DAT_00000008;
      pBVar7 = (BIGNUM *)a->d;
      bn_sqr_comba8(a_01->d);
      goto LAB_004fee6c;
    }
    if ((int)pBVar10 < 0x10) {
      pBVar7 = (BIGNUM *)a->d;
      in_a3 = auStack_ac;
      pBVar8 = pBVar10;
      bn_sqr_normal(a_01->d);
      goto LAB_004fee6c;
    }
    iVar11 = BN_num_bits_word((ulong)pBVar10);
    if (pBVar10 == (BN_CTX *)(1 << (iVar11 - 1U & 0x1f))) {
      pBVar7 = (BIGNUM *)((int)pBVar10 << 2);
      if (a_00->dmax < (int)pBVar7) {
        pBVar5 = bn_expand2(a_00,(int)pBVar7);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_004feec4;
        in_a3 = a_00->d;
      }
      else {
        in_a3 = a_00->d;
      }
      pBVar7 = (BIGNUM *)a->d;
      pBVar8 = pBVar10;
      bn_sqr_recursive(a_01->d);
      goto LAB_004fee6c;
    }
    if ((int)words <= a_00->dmax) {
      in_a3 = a_00->d;
LAB_004fef58:
      pBVar7 = (BIGNUM *)a->d;
      pBVar8 = pBVar10;
      bn_sqr_normal(a_01->d);
      goto LAB_004fee6c;
    }
    pBVar7 = words;
    pBVar5 = bn_expand2(a_00,(int)words);
    if (pBVar5 != (BIGNUM *)0x0) {
      in_a3 = a_00->d;
      goto LAB_004fef58;
    }
LAB_004feec4:
    iVar11 = 0;
  }
  BN_CTX_end(ctx);
  a = pBVar7;
  ctx = pBVar8;
LAB_004feedc:
  if (local_2c == *(uint **)puVar3) {
    return iVar11;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar11 = 0;
  if (0 < (int)ctx) {
    puVar6 = local_2c;
    pBVar7 = a;
    if (((uint)ctx & 0xfffffffc) != 0) {
      do {
        a = (BIGNUM *)&pBVar7->flags;
        uVar9 = *puVar6 + iVar11;
        local_2c = puVar6 + 4;
        ctx = ctx + -4;
        uVar1 = (ulonglong)CONCAT14(uVar9 < *puVar6,uVar9) + ZEXT48(pBVar7->d) * ZEXT48(in_a3);
        *puVar6 = (uint)uVar1;
        uVar1 = (ulonglong)puVar6[1] + (ulonglong)(uint)pBVar7->top * ZEXT48(in_a3) +
                (uVar1 >> 0x20);
        puVar6[1] = (uint)uVar1;
        uVar1 = (ulonglong)puVar6[2] + (ulonglong)(uint)pBVar7->dmax * ZEXT48(in_a3) +
                (uVar1 >> 0x20);
        puVar6[2] = (uint)uVar1;
        lVar2 = (ulonglong)puVar6[3] + (ulonglong)(uint)pBVar7->neg * ZEXT48(in_a3) +
                (uVar1 >> 0x20);
        puVar6[3] = (uint)lVar2;
        iVar11 = (int)((ulonglong)lVar2 >> 0x20);
        puVar6 = local_2c;
        pBVar7 = a;
      } while (((uint)ctx & 0xfffffffc) != 0);
      if (ctx == (BN_CTX *)0x0) {
        return iVar11;
      }
    }
    uVar9 = *local_2c + iVar11;
    lVar2 = ZEXT48(a->d) * ZEXT48(in_a3) + (ulonglong)CONCAT14(uVar9 < *local_2c,uVar9);
    *local_2c = (uint)lVar2;
    iVar11 = (int)((ulonglong)lVar2 >> 0x20);
    if (ctx != (BN_CTX *)0x1) {
      uVar9 = local_2c[1] + iVar11;
      lVar2 = (ulonglong)(uint)a->top * ZEXT48(in_a3) +
              (ulonglong)CONCAT14(uVar9 < local_2c[1],uVar9);
      local_2c[1] = (uint)lVar2;
      iVar11 = (int)((ulonglong)lVar2 >> 0x20);
      if (ctx != (BN_CTX *)&SUB_00000002) {
        uVar9 = local_2c[2] + iVar11;
        lVar2 = (ulonglong)(uint)a->dmax * ZEXT48(in_a3) +
                (ulonglong)CONCAT14(uVar9 < local_2c[2],uVar9);
        iVar11 = (int)((ulonglong)lVar2 >> 0x20);
        local_2c[2] = (uint)lVar2;
      }
    }
  }
  return iVar11;
}

