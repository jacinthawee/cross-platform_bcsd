
/* WARNING: Removing unreachable block (ram,0x081b8cd2) */

int BN_div(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  ulong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  BIGNUM *pBVar5;
  BIGNUM *r;
  BIGNUM *r_00;
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
  BIGNUM *local_94;
  int local_74;
  uint *local_70;
  int local_6c;
  ulong *local_64;
  ulong local_5c;
  BIGNUM local_34;
  int local_20;
  
  local_94 = dv;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((m->top < 1) || (m->d[m->top + -1] != 0)) {
    if (((*(byte *)&m->flags & 4) == 0) && (uVar12 = d->flags & 4, uVar12 == 0)) {
      if (d->top != 0) {
        iVar4 = BN_ucmp(m,d);
        local_74 = 0;
        if (-1 < iVar4) goto LAB_081b8985;
        if ((rem != (BIGNUM *)0x0) && (pBVar5 = BN_copy(rem,m), pBVar5 == (BIGNUM *)0x0))
        goto LAB_081b89e9;
        if (dv != (BIGNUM *)0x0) {
          uVar12 = 1;
          BN_set_word(dv,0);
          goto LAB_081b89e9;
        }
LAB_081b8e50:
        uVar12 = 1;
        goto LAB_081b89e9;
      }
    }
    else if (d->top != 0) {
      local_74 = 1;
LAB_081b8985:
      BN_CTX_start(ctx);
      pBVar5 = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      r_00 = BN_CTX_get(ctx);
      if (dv == (BIGNUM *)0x0) {
        local_94 = BN_CTX_get(ctx);
      }
      if ((((r_00 != (BIGNUM *)0x0) && (local_94 != (BIGNUM *)0x0)) && (pBVar5 != (BIGNUM *)0x0)) &&
         (r != (BIGNUM *)0x0)) {
        iVar4 = BN_num_bits(d);
        iVar6 = BN_lshift(r_00,d,0x20 - iVar4 % 0x20);
        if (iVar6 != 0) {
          iVar4 = 0x40 - iVar4 % 0x20;
          r_00->neg = 0;
          iVar6 = BN_lshift(r,m,iVar4);
          if (iVar6 != 0) {
            r->neg = 0;
            if (local_74 == 0) {
              local_70 = (uint *)r->top;
              local_34.d = r->d;
            }
            else {
              iVar6 = r->top;
              iVar10 = r_00->top + 1;
              if (iVar10 < iVar6) {
                if (r->dmax <= iVar6) {
                  pBVar8 = bn_expand2(r,iVar6 + 1);
                  if (pBVar8 == (BIGNUM *)0x0) goto LAB_081b89db;
                  iVar6 = r->top;
                }
                local_34.d = r->d;
                local_34.d[iVar6] = 0;
                local_70 = (uint *)(r->top + 1);
                r->top = (int)local_70;
              }
              else {
                if (iVar10 < r->dmax) {
LAB_081b8ea5:
                  local_34.d = r->d;
                  do {
                    local_34.d[iVar6] = 0;
                    iVar10 = r_00->top;
                    iVar6 = iVar6 + 1;
                  } while (iVar6 <= iVar10 + 1);
                }
                else {
                  pBVar8 = bn_expand2(r,r_00->top + 2);
                  if (pBVar8 == (BIGNUM *)0x0) goto LAB_081b89db;
                  iVar6 = r->top;
                  iVar10 = r_00->top;
                  if (iVar6 <= iVar10 + 1) goto LAB_081b8ea5;
                  local_34.d = r->d;
                }
                local_70 = (uint *)(iVar10 + 2);
                r->top = (int)local_70;
              }
            }
            iVar6 = r_00->top;
            local_34.neg = 0;
            local_5c = 0;
            iVar10 = (int)local_70 - iVar6;
            local_34.d = local_34.d + iVar10;
            local_34.dmax = r->dmax - iVar10;
            uVar12 = r_00->d[iVar6 + 0x3fffffff];
            if (iVar6 != 1) {
              local_5c = r_00->d[iVar6 + 0x3ffffffe];
            }
            puVar1 = r->d;
            local_94->neg = m->neg ^ d->neg;
            local_34.top = iVar6;
            if ((iVar10 < local_94->dmax) ||
               (pBVar8 = bn_expand2(local_94,iVar10 + 1), pBVar8 != (BIGNUM *)0x0)) {
              local_94->top = iVar10 - local_74;
              local_64 = local_94->d;
              if ((iVar6 < pBVar5->dmax) ||
                 (pBVar8 = bn_expand2(pBVar5,iVar6 + 1), pBVar8 != (BIGNUM *)0x0)) {
                local_64 = local_64 + iVar10 + -1;
                if (local_74 == 0) {
                  iVar9 = BN_ucmp(&local_34,r_00);
                  if (iVar9 < 0) {
                    local_94->top = local_94->top + -1;
                  }
                  else {
                    bn_sub_words(local_34.d,local_34.d,r_00->d,iVar6);
                    *local_64 = 1;
                  }
                }
                if (local_94->top == 0) {
                  local_94->neg = 0;
                }
                else {
                  local_64 = local_64 + -1;
                }
                if (1 < iVar10) {
                  local_6c = 0;
                  local_70 = puVar1 + (int)local_70 + -1;
                  do {
                    w = 0xffffffff;
                    if (uVar12 != *local_70) {
                      uVar2 = CONCAT44(*local_70,local_70[-1]);
                      uVar3 = uVar2 / uVar12;
                      w = (ulong)uVar3;
                      uVar11 = (uint)(uVar2 % (ulonglong)uVar12);
                      uVar2 = (ulonglong)local_5c * (uVar3 & 0xffffffff);
                      if (CONCAT44(uVar11,local_70[-2]) < uVar2) {
                        while (w = w - 1, !CARRY4(uVar11,uVar12)) {
                          uVar11 = uVar11 + uVar12;
                          uVar13 = (uint)uVar2 - local_5c;
                          uVar14 = (int)(uVar2 >> 0x20) - (uint)((uint)uVar2 < local_5c);
                          uVar2 = CONCAT44(uVar14,uVar13);
                          if ((uVar14 <= uVar11) && ((uVar14 < uVar11 || (uVar13 <= local_70[-2]))))
                          break;
                        }
                      }
                    }
                    uVar7 = bn_mul_words(pBVar5->d,r_00->d,iVar6,w);
                    pBVar5->d[iVar6 + 0x40000000] = uVar7;
                    local_34.d = local_34.d + -1;
                    uVar7 = bn_sub_words(local_34.d,local_34.d,pBVar5->d,iVar6 + 1);
                    if (uVar7 != 0) {
                      w = w - 1;
                      uVar7 = bn_add_words(local_34.d,local_34.d,r_00->d,iVar6);
                      if (uVar7 != 0) {
                        *local_70 = *local_70 + 1;
                      }
                    }
                    local_6c = local_6c + 1;
                    local_70 = local_70 + -1;
                    *local_64 = w;
                    local_64 = local_64 + -1;
                  } while (local_6c != iVar10 + -1);
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
                  BN_rshift(rem,r,iVar4);
                  if (rem->top != 0) {
                    rem->neg = iVar6;
                  }
                }
                if ((local_74 != 0) && (iVar4 = local_94->top, 0 < iVar4)) {
                  do {
                    if (local_94->d[iVar4 + -1] != 0) break;
                    iVar4 = iVar4 + -1;
                  } while (iVar4 != 0);
                  local_94->top = iVar4;
                }
                BN_CTX_end(ctx);
                goto LAB_081b8e50;
              }
            }
          }
        }
      }
LAB_081b89db:
      uVar12 = 0;
      BN_CTX_end(ctx);
      goto LAB_081b89e9;
    }
    iVar6 = 0xd6;
    iVar4 = 0x67;
  }
  else {
    iVar6 = 0xc4;
    iVar4 = 0x6b;
  }
  uVar12 = 0;
  ERR_put_error(3,0x6b,iVar4,"bn_div.c",iVar6);
LAB_081b89e9:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

