
int BN_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  ulong uVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  ulong *puVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  int iVar11;
  
  uVar9 = a->top;
  uVar10 = b->top;
  if (uVar9 == 0 || uVar10 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  BN_CTX_start(ctx);
  iVar11 = uVar9 + uVar10;
  a_00 = r;
  if ((r != b && r != a) || (a_00 = BN_CTX_get(ctx), a_00 != (BIGNUM *)0x0)) {
    a_00->neg = a->neg ^ b->neg;
    iVar6 = uVar9 - uVar10;
    if ((iVar6 == 0) && (uVar9 == 8)) {
      if ((0xf < a_00->dmax) || (pBVar2 = bn_expand2(a_00,0x10), pBVar2 != (BIGNUM *)0x0)) {
        puVar7 = b->d;
        puVar4 = a->d;
        a_00->top = 0x10;
        bn_mul_comba8(a_00->d,puVar4,puVar7);
        iVar11 = a_00->top;
LAB_0008b94a:
        if (0 < iVar11) {
          puVar4 = a_00->d + iVar11 + 0x3fffffff;
          do {
            if (*puVar4 != 0) break;
            iVar11 = iVar11 + -1;
            puVar4 = puVar4 + -1;
          } while (iVar11 != 0);
          a_00->top = iVar11;
        }
        if (r == a_00) {
          iVar11 = 1;
        }
        else {
          BN_copy(r,a_00);
          iVar11 = 1;
        }
        goto LAB_0008b978;
      }
    }
    else {
      uVar8 = uVar9;
      if (0xf < (int)uVar9) {
        uVar8 = uVar10;
      }
      if (((int)uVar8 < 0x10) || (2 < iVar6 + 1U)) {
        if ((a_00->dmax < iVar11) && (pBVar2 = bn_expand2(a_00,iVar11), pBVar2 == (BIGNUM *)0x0)) {
          iVar11 = 0;
          goto LAB_0008b978;
        }
        puVar4 = a->d;
        puVar7 = b->d;
        a_00->top = iVar11;
        bn_mul_normal(a_00->d,puVar4,uVar9,puVar7,uVar10);
        iVar11 = a_00->top;
        goto LAB_0008b94a;
      }
      if (iVar6 == -1) {
        iVar6 = BN_num_bits_word(uVar10);
      }
      else {
        iVar6 = BN_num_bits_word(uVar9);
      }
      uVar8 = 1 << (iVar6 - 1U & 0xff);
      pBVar2 = BN_CTX_get(ctx);
      if (pBVar2 != (BIGNUM *)0x0) {
        iVar6 = uVar9 - uVar8;
        uVar1 = uVar9;
        if ((int)uVar9 <= (int)uVar8) {
          iVar6 = uVar10 - uVar8;
          uVar1 = uVar10;
        }
        iVar5 = pBVar2->dmax;
        if (uVar1 == uVar8 || iVar6 < 0 != SBORROW4(uVar1,uVar8)) {
          iVar6 = uVar8 * 4;
          if (((iVar6 - iVar5 == 0 || iVar6 < iVar5) ||
              (pBVar3 = bn_expand2(pBVar2,iVar6), pBVar3 != (BIGNUM *)0x0)) &&
             ((iVar6 <= a_00->dmax || (pBVar3 = bn_expand2(a_00,iVar6), pBVar3 != (BIGNUM *)0x0))))
          {
            bn_mul_recursive(a_00->d,a->d,b->d,uVar8,uVar9 - uVar8,uVar10 - uVar8,pBVar2->d);
            goto LAB_0008ba5a;
          }
        }
        else {
          iVar6 = uVar8 * 8;
          if (((iVar6 - iVar5 == 0 || iVar6 < iVar5) ||
              (pBVar3 = bn_expand2(pBVar2,iVar6), pBVar3 != (BIGNUM *)0x0)) &&
             ((iVar6 <= a_00->dmax || (pBVar3 = bn_expand2(a_00,iVar6), pBVar3 != (BIGNUM *)0x0))))
          {
            bn_mul_part_recursive(a_00->d,a->d,b->d,uVar8,uVar9 - uVar8,uVar10 - uVar8,pBVar2->d);
LAB_0008ba5a:
            a_00->top = iVar11;
            goto LAB_0008b94a;
          }
        }
      }
    }
  }
  iVar11 = 0;
LAB_0008b978:
  BN_CTX_end(ctx);
  return iVar11;
}

