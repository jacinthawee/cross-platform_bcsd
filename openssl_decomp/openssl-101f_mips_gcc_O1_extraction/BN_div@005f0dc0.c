
/* WARNING: Removing unreachable block (ram,0x005f156c) */

int BN_div(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  ulonglong uVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  BIGNUM **ppBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  undefined4 uVar8;
  BIGNUM *pBVar9;
  BIGNUM *pBVar10;
  BIGNUM *pBVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  uint extraout_v1;
  uint uVar15;
  uint uVar16;
  BIGNUM *pBVar17;
  BIGNUM *pBVar18;
  ulong *puVar19;
  uint uVar20;
  ulong uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  ulong *puVar25;
  int local_6c;
  uint *local_68;
  int local_60;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  int local_38;
  undefined4 local_34;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((m->top < 1) || (m->d[m->top + -1] != 0)) {
    pBVar18 = m;
    if (((m->flags & 4U) == 0) && (uVar23 = d->flags & 4, uVar23 == 0)) {
      if (d->top == 0) {
LAB_005f0f88:
        pBVar18 = (BIGNUM *)0x67;
        uVar8 = 0xd6;
        goto LAB_005f0f9c;
      }
      pBVar17 = d;
      iVar4 = (*(code *)PTR_BN_ucmp_006a9678)(m);
      if (-1 < iVar4) {
        local_6c = 0;
        goto LAB_005f0e7c;
      }
      if ((rem == (BIGNUM *)0x0) ||
         (iVar4 = (*(code *)PTR_BN_copy_006a9570)(rem), pBVar17 = m, iVar4 != 0)) {
        if (dv == (BIGNUM *)0x0) {
LAB_005f12ec:
          uVar23 = 1;
          m = pBVar17;
        }
        else {
          m = (BIGNUM *)0x0;
          uVar23 = 1;
          (*(code *)PTR_BN_set_word_006a8820)(dv);
        }
      }
    }
    else {
      if (d->top == 0) goto LAB_005f0f88;
      local_6c = 1;
      pBVar17 = rem;
LAB_005f0e7c:
      (*(code *)PTR_BN_CTX_start_006a9644)(ctx);
      ppBVar5 = (BIGNUM **)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
      pBVar6 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
      pBVar7 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
      pBVar9 = pBVar7;
      if ((((dv != (BIGNUM *)0x0) ||
           (dv = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx), pBVar9 = dv,
           pBVar7 != (BIGNUM *)0x0)) && (pBVar9 != (BIGNUM *)0x0)) &&
         ((ppBVar5 != (BIGNUM **)0x0 && (pBVar6 != (BIGNUM *)0x0)))) {
        uVar23 = (*(code *)PTR_BN_num_bits_006a82f4)(d);
        uVar23 = uVar23 & 0x8000001f;
        if ((int)uVar23 < 0) {
          uVar23 = (uVar23 - 1 | 0xffffffe0) + 1;
        }
        pBVar18 = (BIGNUM *)(0x20 - uVar23);
        pBVar17 = d;
        iVar4 = (*(code *)PTR_BN_lshift_006a95b8)(pBVar7);
        puVar3 = PTR_BN_lshift_006a95b8;
        if (iVar4 != 0) {
          pBVar7->neg = 0;
          pBVar9 = (BIGNUM *)(0x40 - uVar23);
          pBVar17 = m;
          pBVar18 = pBVar9;
          iVar4 = (*(code *)puVar3)(pBVar6);
          if (iVar4 != 0) {
            pBVar6->neg = 0;
            if (local_6c == 0) {
              iVar14 = pBVar6->top;
              puVar19 = pBVar6->d;
            }
            else {
              iVar4 = pBVar6->top;
              iVar14 = pBVar7->top + 1;
              if (iVar14 < iVar4) {
                if (pBVar6->dmax <= iVar4) {
                  pBVar17 = (BIGNUM *)(iVar4 + 1);
                  iVar4 = (*(code *)PTR_bn_expand2_006a9680)(pBVar6);
                  if (iVar4 == 0) goto LAB_005f0f24;
                  iVar4 = pBVar6->top;
                }
                puVar19 = pBVar6->d;
                puVar19[iVar4] = 0;
                iVar14 = pBVar6->top + 1;
                pBVar6->top = iVar14;
              }
              else {
                if (pBVar6->dmax <= iVar14) {
                  pBVar17 = (BIGNUM *)(pBVar7->top + 2);
                  iVar4 = (*(code *)PTR_bn_expand2_006a9680)(pBVar6);
                  if (iVar4 == 0) goto LAB_005f0f24;
                  iVar4 = pBVar6->top;
                  iVar14 = pBVar7->top + 2;
                  if (pBVar7->top + 1 < iVar4) {
                    puVar19 = pBVar6->d;
                    pBVar6->top = iVar14;
                    goto LAB_005f0ff8;
                  }
                }
                puVar19 = pBVar6->d;
                puVar25 = puVar19 + iVar4;
                do {
                  *puVar25 = 0;
                  iVar4 = iVar4 + 1;
                  puVar25 = puVar25 + 1;
                } while (iVar4 <= pBVar7->top + 1);
                iVar14 = pBVar7->top + 2;
                pBVar6->top = iVar14;
              }
            }
LAB_005f0ff8:
            pBVar10 = (BIGNUM *)pBVar7->top;
            local_34 = 0;
            iVar4 = iVar14 - (int)pBVar10;
            pBVar18 = (BIGNUM *)(puVar19 + iVar4);
            local_38 = pBVar6->dmax - iVar4;
            uVar23 = pBVar7->d[(int)((int)&pBVar10[-1].flags + 3)];
            if (pBVar10 == (BIGNUM *)0x1) {
              uVar24 = 0;
            }
            else {
              uVar24 = (pBVar7->d + (int)((int)&pBVar10[-1].flags + 3))[-1];
            }
            puVar19 = pBVar6->d;
            dv->neg = m->neg ^ d->neg;
            local_40 = pBVar18;
            local_3c = pBVar10;
            if (dv->dmax <= iVar4) {
              pBVar17 = (BIGNUM *)(iVar4 + 1);
              iVar12 = (*(code *)PTR_bn_expand2_006a9680)(dv);
              if (iVar12 == 0) goto LAB_005f0f24;
            }
            pBVar11 = ppBVar5[2];
            puVar25 = dv->d;
            dv->top = iVar4 - local_6c;
            pBVar17 = pBVar10;
            if ((int)pBVar11 <= (int)pBVar10) {
              pBVar17 = (BIGNUM *)((int)&pBVar10->d + 1);
              iVar12 = (*(code *)PTR_bn_expand2_006a9680)(ppBVar5);
              if (iVar12 == 0) goto LAB_005f0f24;
            }
            local_68 = puVar25 + iVar4 + -1;
            if (local_6c == 0) {
              pBVar17 = pBVar7;
              iVar12 = (*(code *)PTR_BN_ucmp_006a9678)(&local_40);
              if (iVar12 < 0) {
                iVar12 = dv->top + -1;
                dv->top = iVar12;
              }
              else {
                pBVar18 = (BIGNUM *)pBVar7->d;
                pBVar17 = local_40;
                (*(code *)PTR_bn_sub_words_006a96a4)(local_40,local_40,pBVar18,pBVar10);
                *local_68 = 1;
                iVar12 = dv->top;
              }
            }
            else {
              iVar12 = dv->top;
            }
            if (iVar12 == 0) {
              dv->neg = 0;
            }
            else {
              local_68 = local_68 + -1;
            }
            if (1 < iVar4) {
              local_60 = 0;
              puVar19 = puVar19 + iVar14 + -1;
              do {
                if (uVar23 == *puVar19) {
                  uVar22 = 0xffffffff;
                }
                else {
                  uVar21 = puVar19[-1];
                  (*(code *)PTR___udivdi3_006a970c)(*puVar19,uVar21,0,uVar23);
                  uVar1 = (ulonglong)extraout_v1 * (ulonglong)uVar24;
                  uVar15 = uVar21 - uVar23 * extraout_v1;
                  uVar22 = extraout_v1;
                  if (CONCAT44(uVar15,puVar19[-2]) < uVar1) {
                    while( true ) {
                      uVar15 = uVar23 + uVar15;
                      uVar22 = uVar22 - 1;
                      if (uVar15 < uVar23) break;
                      uVar20 = (uint)uVar1 - uVar24;
                      uVar16 = (int)(uVar1 >> 0x20) - (uint)((uint)uVar1 < uVar20);
                      uVar1 = CONCAT44(uVar16,uVar20);
                      if ((uVar16 <= uVar15) && ((uVar15 != uVar16 || (uVar20 <= puVar19[-2]))))
                      break;
                    }
                  }
                }
                puVar25 = (ulong *)(*(code *)PTR_bn_mul_words_006a96ac)
                                             (*ppBVar5,pBVar7->d,pBVar10,uVar22);
                puVar3 = PTR_bn_sub_words_006a96a4;
                pBVar17 = (BIGNUM *)&local_40[-1].flags;
                (&(*ppBVar5)->d)[(int)pBVar10] = puVar25;
                pBVar18 = *ppBVar5;
                local_40 = pBVar17;
                iVar14 = (*(code *)puVar3)(pBVar17,pBVar17,pBVar18,
                                           (undefined *)((int)&pBVar10->d + 1));
                if (iVar14 != 0) {
                  uVar22 = uVar22 - 1;
                  pBVar18 = (BIGNUM *)pBVar7->d;
                  pBVar17 = local_40;
                  iVar14 = (*(code *)PTR_bn_add_words_006a96a8)(local_40,local_40,pBVar18,pBVar10);
                  if (iVar14 != 0) {
                    *puVar19 = *puVar19 + 1;
                  }
                }
                *local_68 = uVar22;
                local_68 = local_68 + -1;
                local_60 = local_60 + 1;
                puVar19 = puVar19 + -1;
              } while (local_60 != iVar4 + -1);
            }
            iVar4 = pBVar6->top;
            if (0 < iVar4) {
              puVar19 = pBVar6->d + iVar4 + -2;
              do {
                if (puVar19[1] != 0) break;
                iVar4 = iVar4 + -1;
                puVar19 = puVar19 + -1;
              } while (iVar4 != 0);
              pBVar6->top = iVar4;
            }
            if (rem != (BIGNUM *)0x0) {
              iVar4 = m->neg;
              (*(code *)PTR_BN_rshift_006a96f8)(rem);
              pBVar17 = pBVar6;
              pBVar18 = pBVar9;
              if (rem->top != 0) {
                rem->neg = iVar4;
              }
            }
            if ((local_6c != 0) && (iVar4 = dv->top, 0 < iVar4)) {
              puVar19 = dv->d + iVar4 + -2;
              do {
                if (puVar19[1] != 0) break;
                iVar4 = iVar4 + -1;
                puVar19 = puVar19 + -1;
              } while (iVar4 != 0);
              dv->top = iVar4;
            }
            (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
            goto LAB_005f12ec;
          }
        }
      }
LAB_005f0f24:
      uVar23 = 0;
      (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
      m = pBVar17;
    }
  }
  else {
    pBVar18 = (BIGNUM *)&DAT_0000006b;
    uVar8 = 0xc4;
LAB_005f0f9c:
    m = (BIGNUM *)&DAT_0000006b;
    uVar23 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x6b,pBVar18,"bn_div.c",uVar8);
  }
  if (local_2c == *(int *)puVar2) {
    return uVar23;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar13 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x2c,"bn_blind.c",0x8f);
  if (piVar13 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x66,0x41,"bn_blind.c",0x91);
    return 0;
  }
  (*(code *)PTR_memset_006aab00)(piVar13,0,0x2c);
  if (iVar4 != 0) {
    iVar4 = (*(code *)PTR_BN_dup_006a9100)(iVar4);
    *piVar13 = iVar4;
    if (iVar4 == 0) goto LAB_005f174c;
  }
  if (m == (BIGNUM *)0x0) {
LAB_005f16c8:
    iVar4 = (*(code *)PTR_BN_dup_006a9100)(pBVar18);
    piVar13[3] = iVar4;
    if (iVar4 != 0) {
      if ((pBVar18->flags & 4U) != 0) {
        *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) | 4;
      }
      puVar2 = PTR_CRYPTO_THREADID_current_006a95ac;
      piVar13[7] = -1;
      (*(code *)puVar2)(piVar13 + 5);
      return (int)piVar13;
    }
  }
  else {
    iVar4 = (*(code *)PTR_BN_dup_006a9100)(m);
    piVar13[1] = iVar4;
    if (iVar4 != 0) goto LAB_005f16c8;
  }
  if (*piVar13 != 0) {
    (*(code *)PTR_BN_free_006a811c)(*piVar13);
  }
LAB_005f174c:
  if (piVar13[1] != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  if (piVar13[2] != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  if (piVar13[3] != 0) {
    (*(code *)PTR_BN_free_006a811c)();
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(piVar13);
  return 0;
}

