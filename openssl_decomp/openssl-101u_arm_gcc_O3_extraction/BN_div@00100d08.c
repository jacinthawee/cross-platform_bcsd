
int BN_div(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  longlong lVar1;
  longlong lVar2;
  BIGNUM *pBVar3;
  BIGNUM *r;
  BIGNUM *r_00;
  int iVar4;
  ulong *puVar5;
  BIGNUM *pBVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  ulong *puVar11;
  int iVar12;
  ulong *puVar13;
  ulong uVar14;
  uint uVar15;
  bool bVar16;
  uint local_a4;
  int local_98;
  ulong **local_8c;
  ulong *local_78;
  BIGNUM local_3c;
  
  if (((0 < m->top) && (m->d[m->top + 0x3fffffff] == 0)) ||
     ((iVar8 = d->top, 0 < iVar8 && (d->d[iVar8 + 0x3fffffff] == 0)))) {
    ERR_put_error(3,0x6b,0x6b,"bn_div.c",0xcf);
    return 0;
  }
  if ((m->flags << 0x1d < 0) || (local_a4 = d->flags & 4, local_a4 != 0)) {
    if (iVar8 == 0) goto LAB_00100e02;
    local_a4 = 1;
  }
  else {
    if (iVar8 == 0) {
LAB_00100e02:
      ERR_put_error(3,0x6b,0x67,"bn_div.c",0xe5);
      return 0;
    }
    iVar8 = BN_ucmp(m,d);
    if (iVar8 < 0) {
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
     (uVar9 = (uint)(r == (BIGNUM *)0x0 || pBVar3 == (BIGNUM *)0x0),
     r == (BIGNUM *)0x0 || pBVar3 == (BIGNUM *)0x0)) goto LAB_00100d98;
  iVar8 = BN_num_bits(d);
  iVar4 = BN_lshift(r_00,d,0x20 - iVar8 % 0x20);
  if (iVar4 == 0) goto LAB_00100d98;
  iVar4 = 0x40 - iVar8 % 0x20;
  r_00->neg = uVar9;
  iVar8 = BN_lshift(r,m,iVar4);
  if (iVar8 == 0) goto LAB_00100d98;
  r->neg = uVar9;
  if (local_a4 == 0) {
    local_98 = r->top;
    local_3c.d = r->d;
  }
  else {
    iVar12 = r->top;
    iVar8 = r_00->top + 1;
    if (iVar8 < iVar12) {
      if (r->dmax <= iVar12) {
        pBVar6 = bn_expand2(r,iVar12 + 1);
        if (pBVar6 == (BIGNUM *)0x0) goto LAB_00100d98;
        iVar12 = r->top;
      }
      local_3c.d = r->d;
      local_3c.d[iVar12] = 0;
      local_98 = r->top + 1;
      r->top = local_98;
    }
    else {
      if (iVar8 < r->dmax) {
LAB_0010112c:
        local_3c.d = r->d;
        puVar5 = local_3c.d + iVar12 + 0x3fffffff;
        do {
          puVar5 = puVar5 + 1;
          *puVar5 = 0;
          iVar12 = iVar12 + 1;
          local_98 = r_00->top;
        } while (iVar12 <= local_98 + 1);
      }
      else {
        pBVar6 = bn_expand2(r,r_00->top + 2);
        if (pBVar6 == (BIGNUM *)0x0) goto LAB_00100d98;
        local_98 = r_00->top;
        iVar12 = r->top;
        if (iVar12 <= local_98 + 1) goto LAB_0010112c;
        local_3c.d = r->d;
      }
      local_98 = local_98 + 2;
      r->top = local_98;
    }
  }
  iVar8 = r_00->top;
  iVar12 = local_98 - iVar8;
  local_3c.dmax = r->dmax - iVar12;
  local_3c.d = local_3c.d + iVar12;
  puVar5 = r_00->d;
  local_3c.neg = 0;
  bVar16 = iVar8 != 1;
  uVar9 = puVar5[iVar8 + 0x3fffffff];
  if (bVar16) {
    puVar5 = puVar5 + iVar8 + 0x3fffffff;
  }
  else {
    local_78 = (ulong *)0x0;
  }
  if (bVar16) {
    puVar5 = (ulong *)puVar5[-1];
  }
  puVar11 = r->d;
  if (bVar16) {
    local_78 = puVar5;
  }
  dv->neg = m->neg ^ d->neg;
  local_3c.top = iVar8;
  if ((dv->dmax <= iVar12) && (pBVar6 = bn_expand2(dv,iVar12 + 1), pBVar6 == (BIGNUM *)0x0)) {
LAB_00100d98:
    BN_CTX_end(ctx);
    return 0;
  }
  iVar10 = pBVar3->dmax;
  puVar5 = dv->d;
  dv->top = iVar12 - local_a4;
  if ((iVar10 <= iVar8) && (pBVar6 = bn_expand2(pBVar3,iVar8 + 1), pBVar6 == (BIGNUM *)0x0))
  goto LAB_00100d98;
  local_8c = (ulong **)(puVar5 + iVar12 + -1);
  if (local_a4 == 0) {
    iVar10 = BN_ucmp(&local_3c,r_00);
    if (iVar10 < 0) {
      iVar10 = dv->top + -1;
      dv->top = iVar10;
      goto LAB_00100f16;
    }
    bn_sub_words(local_3c.d,local_3c.d,r_00->d,iVar8);
    puVar5[iVar12 + -1] = 1;
  }
  iVar10 = dv->top;
LAB_00100f16:
  if (iVar10 == 0) {
    dv->neg = 0;
  }
  else {
    local_8c = local_8c + -1;
  }
  if (1 < iVar12) {
    iVar10 = local_98 + 0x3fffffff;
    local_98 = 0;
    puVar5 = puVar11 + iVar10;
    do {
      uVar14 = puVar5[-1];
      if (*puVar5 == uVar9) {
        puVar11 = (ulong *)0xffffffff;
      }
      else {
        puVar11 = (ulong *)__aeabi_uldivmod(uVar14,*puVar5,uVar9,0);
        uVar15 = uVar14 - uVar9 * (int)puVar11;
        lVar1 = ZEXT48(puVar11) * ZEXT48(local_78);
        uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
        bVar16 = uVar7 <= uVar15;
        if (uVar15 == uVar7) {
          bVar16 = (uint)lVar1 <= puVar5[-2];
        }
        if (!bVar16) {
          bVar16 = CARRY4(uVar15,uVar9);
          puVar13 = puVar11;
          if (bVar16 == false) {
            puVar13 = local_78;
          }
          while (puVar11 = (ulong *)((int)puVar11 + -1), bVar16 == false) {
            uVar15 = uVar15 + uVar9;
            lVar2 = lVar1 - ZEXT48(puVar13);
            uVar7 = (uint)((ulonglong)lVar2 >> 0x20);
            lVar1 = lVar1 - ZEXT48(puVar13);
            bVar16 = uVar7 <= uVar15;
            if (uVar15 == uVar7) {
              bVar16 = (uint)lVar2 <= puVar5[-2];
            }
            if (bVar16) break;
            bVar16 = CARRY4(uVar15,uVar9);
          }
        }
      }
      uVar14 = bn_mul_words(pBVar3->d,r_00->d,iVar8,(ulong)puVar11);
      local_3c.d = local_3c.d + -1;
      pBVar3->d[iVar8 + 0x40000000] = uVar14;
      uVar14 = bn_sub_words(local_3c.d,local_3c.d,pBVar3->d,iVar8 + 1);
      if (uVar14 != 0) {
        puVar11 = (ulong *)((int)puVar11 + -1);
        uVar14 = bn_add_words(local_3c.d,local_3c.d,r_00->d,iVar8);
        if (uVar14 != 0) {
          *puVar5 = *puVar5 + 1;
        }
      }
      *local_8c = puVar11;
      local_98 = local_98 + 1;
      puVar5 = puVar5 + -1;
      local_8c = local_8c + -1;
    } while (local_98 != iVar12 + -1);
  }
  iVar8 = r->top;
  if (0 < iVar8) {
    puVar5 = r->d + iVar8 + 0x3fffffff;
    do {
      if (*puVar5 != 0) break;
      iVar8 = iVar8 + -1;
      puVar5 = puVar5 + -1;
    } while (iVar8 != 0);
    r->top = iVar8;
  }
  if (rem != (BIGNUM *)0x0) {
    iVar8 = m->neg;
    BN_rshift(rem,r,iVar4);
    if (rem->top != 0) {
      rem->neg = iVar8;
    }
  }
  if ((local_a4 != 0) && (iVar8 = dv->top, 0 < iVar8)) {
    puVar5 = dv->d + iVar8 + 0x3fffffff;
    do {
      if (*puVar5 != 0) break;
      iVar8 = iVar8 + -1;
      puVar5 = puVar5 + -1;
    } while (iVar8 != 0);
    dv->top = iVar8;
  }
  BN_CTX_end(ctx);
  return 1;
}

