
int BN_div(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  longlong lVar1;
  longlong lVar2;
  BIGNUM *pBVar3;
  BIGNUM *r;
  BIGNUM *r_00;
  int iVar4;
  int iVar5;
  ulong *puVar6;
  BIGNUM *pBVar7;
  ulong *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  uint w;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  uint local_a4;
  int local_a0;
  ulong *local_90;
  ulong *local_78;
  BIGNUM local_3c;
  
  if ((0 < m->top) && (m->d[m->top + 0x3fffffff] == 0)) {
    ERR_put_error(3,0x6b,0x6b,"bn_div.c",0xc4);
    return 0;
  }
  if ((m->flags << 0x1d < 0) || (local_a4 = d->flags & 4, local_a4 != 0)) {
    if (d->top == 0) goto LAB_00102b08;
    local_a4 = 1;
  }
  else {
    if (d->top == 0) {
LAB_00102b08:
      ERR_put_error(3,0x6b,0x67,"bn_div.c",0xd6);
      return 0;
    }
    iVar4 = BN_ucmp(m,d);
    if (iVar4 < 0) {
      if ((rem != (BIGNUM *)0x0) && (pBVar3 = BN_copy(rem,m), pBVar3 == (BIGNUM *)0x0)) {
        return 0;
      }
      if (dv != (BIGNUM *)0x0) {
        BN_set_word(dv,0);
      }
      return 1;
    }
  }
  BN_CTX_start(ctx);
  pBVar3 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  if (dv == (BIGNUM *)0x0) {
    dv = BN_CTX_get(ctx);
  }
  if ((dv == (BIGNUM *)0x0 || r_00 == (BIGNUM *)0x0) ||
     (uVar13 = (uint)(r == (BIGNUM *)0x0 || pBVar3 == (BIGNUM *)0x0),
     r == (BIGNUM *)0x0 || pBVar3 == (BIGNUM *)0x0)) goto LAB_00102ba2;
  iVar4 = BN_num_bits(d);
  iVar5 = BN_lshift(r_00,d,0x20 - iVar4 % 0x20);
  if (iVar5 == 0) goto LAB_00102ba2;
  iVar5 = 0x40 - iVar4 % 0x20;
  r_00->neg = uVar13;
  iVar4 = BN_lshift(r,m,iVar5);
  if (iVar4 == 0) goto LAB_00102ba2;
  r->neg = uVar13;
  if (local_a4 == 0) {
    local_a0 = r->top;
    local_3c.d = r->d;
  }
  else {
    iVar11 = r->top;
    iVar4 = r_00->top + 1;
    if (iVar4 < iVar11) {
      if (r->dmax <= iVar11) {
        pBVar7 = bn_expand2(r,iVar11 + 1);
        if (pBVar7 == (BIGNUM *)0x0) goto LAB_00102ba2;
        iVar11 = r->top;
      }
      local_3c.d = r->d;
      local_3c.d[iVar11] = 0;
      local_a0 = r->top + 1;
      r->top = local_a0;
    }
    else {
      if (iVar4 < r->dmax) {
LAB_00102ef4:
        local_3c.d = r->d;
        puVar6 = local_3c.d + iVar11 + 0x3fffffff;
        do {
          puVar6 = puVar6 + 1;
          *puVar6 = 0;
          iVar11 = iVar11 + 1;
          local_a0 = r_00->top;
        } while (iVar11 <= local_a0 + 1);
      }
      else {
        pBVar7 = bn_expand2(r,r_00->top + 2);
        if (pBVar7 == (BIGNUM *)0x0) goto LAB_00102ba2;
        local_a0 = r_00->top;
        iVar11 = r->top;
        if (iVar11 <= local_a0 + 1) goto LAB_00102ef4;
        local_3c.d = r->d;
      }
      local_a0 = local_a0 + 2;
      r->top = local_a0;
    }
  }
  iVar4 = r_00->top;
  iVar11 = local_a0 - iVar4;
  local_3c.dmax = r->dmax - iVar11;
  local_3c.d = local_3c.d + iVar11;
  puVar6 = r_00->d;
  local_3c.neg = 0;
  bVar15 = iVar4 == 1;
  uVar13 = puVar6[iVar4 + 0x3fffffff];
  if (!bVar15) {
    puVar6 = puVar6 + iVar4 + 0x3fffffff;
  }
  if (bVar15) {
    local_78 = (ulong *)0x0;
  }
  else {
    puVar6 = (ulong *)puVar6[-1];
  }
  if (!bVar15) {
    local_78 = puVar6;
  }
  puVar6 = r->d;
  dv->neg = m->neg ^ d->neg;
  local_3c.top = iVar4;
  if ((iVar11 < dv->dmax) || (pBVar7 = bn_expand2(dv,iVar11 + 1), pBVar7 != (BIGNUM *)0x0)) {
    puVar8 = dv->d;
    iVar10 = pBVar3->dmax;
    dv->top = iVar11 - local_a4;
    if ((iVar4 < iVar10) || (pBVar7 = bn_expand2(pBVar3,iVar4 + 1), pBVar7 != (BIGNUM *)0x0)) {
      local_90 = puVar8 + iVar11 + -1;
      if (local_a4 == 0) {
        iVar10 = BN_ucmp(&local_3c,r_00);
        if (iVar10 < 0) {
          iVar10 = dv->top + -1;
          dv->top = iVar10;
        }
        else {
          bn_sub_words(local_3c.d,local_3c.d,r_00->d,iVar4);
          puVar8[iVar11 + -1] = 1;
          iVar10 = dv->top;
        }
      }
      else {
        iVar10 = dv->top;
      }
      if (iVar10 == 0) {
        dv->neg = 0;
      }
      else {
        local_90 = local_90 + -1;
      }
      if (1 < iVar11) {
        iVar10 = local_a0 + 0x3fffffff;
        local_a0 = 0;
        puVar6 = puVar6 + iVar10;
        do {
          uVar12 = puVar6[-1];
          if (*puVar6 == uVar13) {
            w = 0xffffffff;
          }
          else {
            w = __aeabi_uldivmod(uVar12,*puVar6,uVar13,0);
            uVar14 = uVar12 - uVar13 * w;
            lVar1 = (ulonglong)w * ZEXT48(local_78);
            uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
            bVar15 = uVar9 <= uVar14;
            if (uVar14 == uVar9) {
              bVar15 = (uint)lVar1 <= puVar6[-2];
            }
            if ((!bVar15) && (w = w - 1, CARRY4(uVar14,uVar13) == false)) {
              do {
                uVar14 = uVar14 + uVar13;
                lVar2 = lVar1 - ZEXT48(local_78);
                uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
                lVar1 = lVar1 - ZEXT48(local_78);
                bVar15 = uVar9 <= uVar14;
                if (uVar14 == uVar9) {
                  bVar15 = (uint)lVar2 <= puVar6[-2];
                }
              } while ((!bVar15) && (w = w - 1, CARRY4(uVar14,uVar13) == false));
            }
          }
          uVar12 = bn_mul_words(pBVar3->d,r_00->d,iVar4,w);
          local_3c.d = local_3c.d + -1;
          pBVar3->d[iVar4 + 0x40000000] = uVar12;
          uVar12 = bn_sub_words(local_3c.d,local_3c.d,pBVar3->d,iVar4 + 1);
          if (uVar12 != 0) {
            w = w - 1;
            uVar12 = bn_add_words(local_3c.d,local_3c.d,r_00->d,iVar4);
            if (uVar12 != 0) {
              *puVar6 = *puVar6 + 1;
            }
          }
          local_a0 = local_a0 + 1;
          *local_90 = w;
          puVar6 = puVar6 + -1;
          local_90 = local_90 + -1;
        } while (local_a0 != iVar11 + -1);
      }
      iVar4 = r->top;
      if (0 < iVar4) {
        puVar6 = r->d + iVar4 + 0x3fffffff;
        do {
          if (*puVar6 != 0) break;
          iVar4 = iVar4 + -1;
          puVar6 = puVar6 + -1;
        } while (iVar4 != 0);
        r->top = iVar4;
      }
      if (rem != (BIGNUM *)0x0) {
        iVar4 = m->neg;
        BN_rshift(rem,r,iVar5);
        if (rem->top != 0) {
          rem->neg = iVar4;
        }
      }
      if ((local_a4 != 0) && (iVar4 = dv->top, 0 < iVar4)) {
        puVar6 = dv->d + iVar4 + 0x3fffffff;
        do {
          if (*puVar6 != 0) break;
          iVar4 = iVar4 + -1;
          puVar6 = puVar6 + -1;
        } while (iVar4 != 0);
        dv->top = iVar4;
      }
      BN_CTX_end(ctx);
      return 1;
    }
  }
LAB_00102ba2:
  BN_CTX_end(ctx);
  return 0;
}

