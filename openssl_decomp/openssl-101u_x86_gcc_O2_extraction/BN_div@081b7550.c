
/* WARNING: Removing unreachable block (ram,0x081b7992) */

int BN_div(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  ulong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  BIGNUM *pBVar4;
  BIGNUM *r;
  BIGNUM *r_00;
  int iVar5;
  int iVar6;
  ulong uVar7;
  BIGNUM *pBVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  ulong w;
  uint uVar13;
  uint uVar14;
  int in_GS_OFFSET;
  BIGNUM *local_98;
  int local_88;
  int local_7c;
  uint *local_74;
  int local_70;
  ulong *local_68;
  ulong local_60;
  BIGNUM local_34;
  int local_20;
  
  local_98 = dv;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((m->top < 1) || (m->d[m->top + -1] != 0)) &&
     ((iVar5 = d->top, iVar5 < 1 || (d->d[iVar5 + -1] != 0)))) {
    if (((*(byte *)&m->flags & 4) == 0) && (uVar12 = d->flags & 4, uVar12 == 0)) {
      if (iVar5 != 0) {
        iVar5 = BN_ucmp(m,d);
        local_88 = 0;
        if (-1 < iVar5) goto LAB_081b75d5;
        if ((rem != (BIGNUM *)0x0) && (pBVar4 = BN_copy(rem,m), pBVar4 == (BIGNUM *)0x0))
        goto LAB_081b769d;
        if (dv != (BIGNUM *)0x0) {
          uVar12 = 1;
          BN_set_word(dv,0);
          goto LAB_081b769d;
        }
LAB_081b7a78:
        uVar12 = 1;
        goto LAB_081b769d;
      }
    }
    else if (iVar5 != 0) {
      local_88 = 1;
LAB_081b75d5:
      BN_CTX_start(ctx);
      pBVar4 = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      r_00 = BN_CTX_get(ctx);
      if (dv == (BIGNUM *)0x0) {
        local_98 = BN_CTX_get(ctx);
      }
      if ((((r_00 != (BIGNUM *)0x0) && (local_98 != (BIGNUM *)0x0)) && (pBVar4 != (BIGNUM *)0x0)) &&
         (r != (BIGNUM *)0x0)) {
        iVar5 = BN_num_bits(d);
        iVar6 = BN_lshift(r_00,d,0x20 - iVar5 % 0x20);
        if (iVar6 != 0) {
          iVar5 = 0x40 - iVar5 % 0x20;
          r_00->neg = 0;
          iVar6 = BN_lshift(r,m,iVar5);
          if (iVar6 != 0) {
            r->neg = 0;
            if (local_88 == 0) {
              local_7c = r->top;
              local_74 = r->d;
            }
            else {
              iVar6 = r->top;
              iVar10 = r_00->top + 1;
              if (iVar10 < iVar6) {
                if (r->dmax <= iVar6) {
                  pBVar8 = bn_expand2(r,iVar6 + 1);
                  if (pBVar8 == (BIGNUM *)0x0) goto LAB_081b7668;
                  iVar6 = r->top;
                }
                local_74 = r->d;
                local_74[iVar6] = 0;
                local_7c = r->top + 1;
                r->top = local_7c;
              }
              else {
                if (iVar10 < r->dmax) {
LAB_081b7af8:
                  local_74 = r->d;
                  do {
                    local_74[iVar6] = 0;
                    local_7c = r_00->top;
                    iVar6 = iVar6 + 1;
                  } while (iVar6 <= local_7c + 1);
                }
                else {
                  pBVar8 = bn_expand2(r,r_00->top + 2);
                  if (pBVar8 == (BIGNUM *)0x0) goto LAB_081b7668;
                  local_7c = r_00->top;
                  iVar6 = r->top;
                  if (iVar6 <= local_7c + 1) goto LAB_081b7af8;
                  local_74 = r->d;
                }
                local_7c = local_7c + 2;
                r->top = local_7c;
              }
            }
            iVar6 = r_00->top;
            local_34.neg = 0;
            local_60 = 0;
            iVar10 = local_7c - iVar6;
            local_34.d = local_74 + iVar10;
            local_34.dmax = r->dmax - iVar10;
            uVar12 = r_00->d[iVar6 + 0x3fffffff];
            if (iVar6 != 1) {
              local_60 = r_00->d[iVar6 + 0x3ffffffe];
            }
            puVar1 = r->d;
            local_98->neg = m->neg ^ d->neg;
            local_34.top = iVar6;
            if ((iVar10 < local_98->dmax) ||
               (pBVar8 = bn_expand2(local_98,iVar10 + 1), pBVar8 != (BIGNUM *)0x0)) {
              local_98->top = iVar10 - local_88;
              local_68 = local_98->d;
              if ((iVar6 < pBVar4->dmax) ||
                 (pBVar8 = bn_expand2(pBVar4,iVar6 + 1), pBVar8 != (BIGNUM *)0x0)) {
                local_68 = local_68 + iVar10 + -1;
                if (local_88 == 0) {
                  iVar9 = BN_ucmp(&local_34,r_00);
                  if (iVar9 < 0) {
                    local_98->top = local_98->top + -1;
                  }
                  else {
                    bn_sub_words(local_34.d,local_34.d,r_00->d,iVar6);
                    *local_68 = 1;
                  }
                }
                if (local_98->top == 0) {
                  local_98->neg = 0;
                }
                else {
                  local_68 = local_68 + -1;
                }
                if (1 < iVar10) {
                  local_70 = 0;
                  local_74 = puVar1 + local_7c + -1;
                  do {
                    w = 0xffffffff;
                    if (uVar12 != *local_74) {
                      uVar2 = CONCAT44(*local_74,local_74[-1]);
                      uVar3 = uVar2 / uVar12;
                      w = (ulong)uVar3;
                      uVar11 = (uint)(uVar2 % (ulonglong)uVar12);
                      uVar2 = (ulonglong)local_60 * (uVar3 & 0xffffffff);
                      if (CONCAT44(uVar11,local_74[-2]) < uVar2) {
                        while (w = w - 1, !CARRY4(uVar11,uVar12)) {
                          uVar11 = uVar11 + uVar12;
                          uVar13 = (uint)uVar2 - local_60;
                          uVar14 = (int)(uVar2 >> 0x20) - (uint)((uint)uVar2 < local_60);
                          uVar2 = CONCAT44(uVar14,uVar13);
                          if ((uVar14 <= uVar11) && ((uVar14 < uVar11 || (uVar13 <= local_74[-2]))))
                          break;
                        }
                      }
                    }
                    uVar7 = bn_mul_words(pBVar4->d,r_00->d,iVar6,w);
                    pBVar4->d[iVar6 + 0x40000000] = uVar7;
                    local_34.d = local_34.d + -1;
                    uVar7 = bn_sub_words(local_34.d,local_34.d,pBVar4->d,iVar6 + 1);
                    if (uVar7 != 0) {
                      w = w - 1;
                      uVar7 = bn_add_words(local_34.d,local_34.d,r_00->d,iVar6);
                      if (uVar7 != 0) {
                        *local_74 = *local_74 + 1;
                      }
                    }
                    local_70 = local_70 + 1;
                    local_74 = local_74 + -1;
                    *local_68 = w;
                    local_68 = local_68 + -1;
                  } while (local_70 != iVar10 + -1);
                }
                iVar6 = r->top;
                if (0 < iVar6) {
                  do {
                    if (r->d[iVar6 + -1] != 0) break;
                    iVar6 = iVar6 + -1;
                  } while (iVar6 != 0);
                  r->top = iVar6;
                }
                if (rem != (BIGNUM *)0x0) {
                  iVar6 = m->neg;
                  BN_rshift(rem,r,iVar5);
                  if (rem->top != 0) {
                    rem->neg = iVar6;
                  }
                }
                if ((local_88 != 0) && (iVar5 = local_98->top, 0 < iVar5)) {
                  do {
                    if (local_98->d[iVar5 + -1] != 0) break;
                    iVar5 = iVar5 + -1;
                  } while (iVar5 != 0);
                  local_98->top = iVar5;
                }
                BN_CTX_end(ctx);
                goto LAB_081b7a78;
              }
            }
          }
        }
      }
LAB_081b7668:
      uVar12 = 0;
      BN_CTX_end(ctx);
      goto LAB_081b769d;
    }
    iVar6 = 0xe5;
    iVar5 = 0x67;
  }
  else {
    iVar6 = 0xcf;
    iVar5 = 0x6b;
  }
  uVar12 = 0;
  ERR_put_error(3,0x6b,iVar5,"bn_div.c",iVar6);
LAB_081b769d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

