
bool BN_GF2m_mod_inv(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  ulong *puVar1;
  ulong *puVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  ulong **ppuVar6;
  ulong **ppuVar7;
  int iVar8;
  int *piVar9;
  BIGNUM *pBVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint *puVar19;
  uint *puVar20;
  int iVar21;
  uint *puVar22;
  int iVar23;
  uint *puVar24;
  int in_GS_OFFSET;
  bool bVar25;
  BIGNUM *local_78;
  int local_74;
  BIGNUM *local_70;
  BIGNUM *local_64;
  int local_58;
  BIGNUM *local_4c;
  uint local_48;
  int local_38 [6];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_CTX_start(param_4);
  local_70 = BN_CTX_get(param_4);
  if ((((local_70 != (BIGNUM *)0x0) && (local_64 = BN_CTX_get(param_4), local_64 != (BIGNUM *)0x0))
      && (local_78 = BN_CTX_get(param_4), local_78 != (BIGNUM *)0x0)) &&
     (local_4c = BN_CTX_get(param_4), local_4c != (BIGNUM *)0x0)) {
    if (param_3->top == 0) {
LAB_081e1427:
      ERR_put_error(3,0x83,0x6a,"bn_gf2m.c",0x1de);
    }
    else {
      iVar21 = param_3->top + -1;
      if (iVar21 < 0) {
        piVar9 = local_38;
LAB_081e116d:
        *piVar9 = -1;
      }
      else {
        puVar1 = param_3->d;
        iVar18 = 0;
        iVar23 = iVar21 * 0x20 + -1;
        do {
          uVar12 = puVar1[iVar21];
          if (uVar12 != 0) {
            iVar8 = iVar23 + 0x20;
            uVar16 = 0x80000000;
            while( true ) {
              if ((uVar16 & uVar12) != 0) {
                if (iVar18 < 6) {
                  local_38[iVar18] = iVar8;
                }
                iVar18 = iVar18 + 1;
              }
              iVar8 = iVar8 + -1;
              uVar16 = uVar16 >> 1;
              if (iVar8 == iVar23) break;
              uVar12 = puVar1[iVar21];
            }
          }
          iVar21 = iVar21 + -1;
          iVar23 = iVar23 + -0x20;
        } while (iVar21 != -1);
        piVar9 = local_38 + iVar18;
        if (iVar18 < 6) goto LAB_081e116d;
        if (6 < iVar18) goto LAB_081e1427;
      }
      if (local_38[0] == 0) {
        BN_set_word(local_78,0);
      }
      else {
        if (local_78 != param_2) {
          iVar21 = param_2->top;
          if (local_78->dmax < iVar21) {
            pBVar10 = bn_expand2(local_78,iVar21);
            if (pBVar10 == (BIGNUM *)0x0) goto LAB_081e1448;
            iVar21 = param_2->top;
          }
          if (0 < iVar21) {
            puVar1 = param_2->d;
            puVar2 = local_78->d;
            iVar18 = 0;
            do {
              puVar2[iVar18] = puVar1[iVar18];
              iVar21 = param_2->top;
              iVar18 = iVar18 + 1;
            } while (iVar18 < iVar21);
          }
          local_78->top = iVar21;
        }
        iVar21 = BN_GF2m_mod_arr_part_0();
        if (iVar21 == 0) goto LAB_081e1448;
      }
      if ((local_78->top != 0) && (pBVar10 = BN_copy(local_4c,param_3), pBVar10 != (BIGNUM *)0x0)) {
        local_74 = BN_num_bits(local_78);
        local_58 = BN_num_bits(local_4c);
        iVar21 = param_3->top;
        if ((iVar21 <= local_78->dmax) ||
           (pBVar10 = bn_expand2(local_78,iVar21), pBVar10 != (BIGNUM *)0x0)) {
          iVar18 = local_78->top;
          puVar22 = local_78->d;
          if (iVar18 < iVar21) {
            memset(puVar22 + iVar18,0,(iVar21 - iVar18) * 4);
          }
          local_78->top = iVar21;
          if ((iVar21 <= local_70->dmax) ||
             (pBVar10 = bn_expand2(local_70,iVar21), pBVar10 != (BIGNUM *)0x0)) {
            puVar24 = local_70->d;
            *puVar24 = 1;
            if (1 < iVar21) {
              memset(puVar24 + 1,0,iVar21 * 4 - 4);
            }
            local_70->top = iVar21;
            if ((iVar21 <= local_64->dmax) ||
               (pBVar10 = bn_expand2(local_64,iVar21), pBVar10 != (BIGNUM *)0x0)) {
              puVar14 = local_64->d;
              if (0 < iVar21) {
                memset(puVar14,0,iVar21 << 2);
              }
              local_64->top = iVar21;
              iVar18 = iVar21 + -1;
              puVar20 = local_4c->d;
LAB_081e1310:
              while (puVar19 = puVar20, puVar13 = puVar14, pBVar5 = local_70, iVar23 = local_74,
                    pBVar10 = local_78, uVar12 = *puVar22, puVar14 = puVar13, puVar20 = puVar19,
                    local_74 != 0) {
                if ((uVar12 & 1) != 0) {
                  if (local_74 < 0x21) goto LAB_081e1326;
                  goto joined_r0x081e1492;
                }
                uVar16 = *puVar24;
                puVar13 = param_3->d;
                uVar17 = -(uVar16 & 1) & *puVar13 ^ *puVar24;
                local_48 = uVar12 & 1;
                if (0 < iVar18) {
                  iVar23 = 0;
                  uVar11 = uVar12;
                  do {
                    uVar12 = puVar22[iVar23 + 1];
                    uVar15 = uVar17 >> 1;
                    puVar22[iVar23] = uVar11 >> 1 | uVar12 << 0x1f;
                    uVar17 = -(uVar16 & 1) & puVar13[iVar23 + 1] ^ puVar24[iVar23 + 1];
                    puVar24[iVar23] = uVar15 | uVar17 << 0x1f;
                    iVar23 = iVar23 + 1;
                    uVar11 = uVar12;
                    local_48 = iVar18 * 4;
                  } while (iVar23 != iVar18);
                }
                local_74 = local_74 + -1;
                *(uint *)((int)puVar22 + local_48) = uVar12 >> 1;
                *(uint *)((int)puVar24 + local_48) = uVar17 >> 1;
              }
              if (uVar12 == 0) goto LAB_081e1448;
LAB_081e1326:
              if (uVar12 != 1) {
joined_r0x081e1492:
                if (local_74 < local_58) {
                  iVar8 = local_58;
                  ppuVar6 = &local_78->d;
                  ppuVar7 = &local_70->d;
                  local_74 = local_58;
                  pBVar3 = local_4c;
                  local_58 = iVar23;
                  local_78 = local_4c;
                  pBVar4 = local_64;
                  local_4c = pBVar10;
                  local_70 = local_64;
                  local_64 = pBVar5;
                  puVar14 = *ppuVar7;
                  puVar20 = *ppuVar6;
                  puVar22 = puVar19;
                  puVar24 = puVar13;
                  if (iVar21 < 1) goto LAB_081e1310;
LAB_081e1385:
                  iVar23 = 0;
                  do {
                    puVar22[iVar23] = puVar22[iVar23] ^ puVar20[iVar23];
                    puVar24[iVar23] = puVar24[iVar23] ^ puVar14[iVar23];
                    iVar23 = iVar23 + 1;
                  } while (iVar21 != iVar23);
                }
                else if (0 < iVar21) goto LAB_081e1385;
                if (local_74 == local_58) {
                  iVar23 = local_74 + 0x1e;
                  if (-1 < local_74 + -1) {
                    iVar23 = local_74 + -1;
                  }
                  iVar23 = iVar23 >> 5;
                  uVar12 = puVar22[iVar23];
                  if (uVar12 == 0) {
                    do {
                      if (iVar23 == 0) {
                        iVar23 = 0;
                        goto LAB_081e13f7;
                      }
                      iVar23 = iVar23 + -1;
                      uVar12 = puVar22[iVar23];
                    } while (uVar12 == 0);
                    iVar23 = iVar23 * 0x20;
                  }
                  else {
                    iVar23 = iVar23 << 5;
                  }
LAB_081e13f7:
                  iVar8 = BN_num_bits_word(uVar12);
                  local_58 = local_74;
                  local_74 = iVar8 + iVar23;
                }
                goto LAB_081e1310;
              }
              iVar21 = local_70->top;
              if (0 < iVar21) {
                do {
                  if (local_70->d[iVar21 + -1] != 0) break;
                  iVar21 = iVar21 + -1;
                } while (iVar21 != 0);
                local_70->top = iVar21;
              }
              pBVar10 = BN_copy(param_1,local_70);
              bVar25 = pBVar10 != (BIGNUM *)0x0;
              goto LAB_081e144a;
            }
          }
        }
      }
    }
  }
LAB_081e1448:
  bVar25 = false;
LAB_081e144a:
  BN_CTX_end(param_4);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar25;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

