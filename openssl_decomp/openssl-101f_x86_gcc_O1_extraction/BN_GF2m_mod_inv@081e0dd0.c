
bool BN_GF2m_mod_inv(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int *piVar5;
  BIGNUM *pBVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  uint *__s;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  ulong *puVar14;
  ulong *puVar15;
  int iVar16;
  uint *puVar17;
  int iVar18;
  ulong *puVar19;
  int in_GS_OFFSET;
  bool bVar20;
  int local_7c;
  int local_6c;
  BIGNUM *local_68;
  BIGNUM *local_64;
  BIGNUM *local_58;
  uint local_50;
  BIGNUM *local_4c;
  int local_38 [6];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_CTX_start(param_4);
  local_64 = BN_CTX_get(param_4);
  if ((((local_64 != (BIGNUM *)0x0) && (local_58 = BN_CTX_get(param_4), local_58 != (BIGNUM *)0x0))
      && (local_68 = BN_CTX_get(param_4), local_68 != (BIGNUM *)0x0)) &&
     (local_4c = BN_CTX_get(param_4), local_4c != (BIGNUM *)0x0)) {
    if (param_3->top == 0) {
LAB_081e11d4:
      ERR_put_error(3,0x83,0x6a,"bn_gf2m.c",0x176);
    }
    else {
      iVar16 = param_3->top + -1;
      if (iVar16 < 0) {
        piVar5 = local_38;
LAB_081e0eed:
        *piVar5 = -1;
      }
      else {
        puVar19 = param_3->d;
        iVar13 = 0;
        iVar18 = iVar16 * 0x20 + -1;
        do {
          uVar9 = puVar19[iVar16];
          if (uVar9 != 0) {
            iVar4 = iVar18 + 0x20;
            uVar12 = 0x80000000;
            while( true ) {
              if ((uVar12 & uVar9) != 0) {
                if (iVar13 < 6) {
                  local_38[iVar13] = iVar4;
                }
                iVar13 = iVar13 + 1;
              }
              iVar4 = iVar4 + -1;
              uVar12 = uVar12 >> 1;
              if (iVar4 == iVar18) break;
              uVar9 = puVar19[iVar16];
            }
          }
          iVar16 = iVar16 + -1;
          iVar18 = iVar18 + -0x20;
        } while (iVar16 != -1);
        piVar5 = local_38 + iVar13;
        if (iVar13 < 6) goto LAB_081e0eed;
        if (6 < iVar13) goto LAB_081e11d4;
      }
      if (local_38[0] == 0) {
        BN_set_word(local_68,0);
      }
      else {
        if (local_68 != param_2) {
          iVar16 = param_2->top;
          if (local_68->dmax < iVar16) {
            pBVar6 = bn_expand2(local_68,iVar16);
            if (pBVar6 == (BIGNUM *)0x0) goto LAB_081e11f8;
            iVar16 = param_2->top;
          }
          if (0 < iVar16) {
            puVar19 = param_2->d;
            puVar14 = local_68->d;
            iVar13 = 0;
            do {
              puVar14[iVar13] = puVar19[iVar13];
              iVar16 = param_2->top;
              iVar13 = iVar13 + 1;
            } while (iVar13 < iVar16);
          }
          local_68->top = iVar16;
        }
        iVar16 = BN_GF2m_mod_arr_part_0();
        if (iVar16 == 0) goto LAB_081e11f8;
      }
      if ((local_68->top != 0) && (pBVar6 = BN_copy(local_4c,param_3), pBVar6 != (BIGNUM *)0x0)) {
        local_7c = BN_num_bits(local_68);
        local_6c = BN_num_bits(local_4c);
        iVar16 = param_3->top;
        if (local_68->dmax < iVar16) {
          bn_expand2(local_68,iVar16);
        }
        iVar13 = local_68->top;
        puVar19 = local_68->d;
        if (iVar13 < iVar16) {
          memset(puVar19 + iVar13,0,(iVar16 - iVar13) * 4);
        }
        local_68->top = iVar16;
        if (local_64->dmax < iVar16) {
          bn_expand2(local_64,iVar16);
        }
        puVar17 = local_64->d;
        *puVar17 = 1;
        if (1 < iVar16) {
          memset(puVar17 + 1,0,iVar16 * 4 - 4);
        }
        local_64->top = iVar16;
        if (local_58->dmax < iVar16) {
          bn_expand2(local_58,iVar16);
        }
        __s = local_58->d;
        if (0 < iVar16) {
          memset(__s,0,iVar16 << 2);
        }
        local_58->top = iVar16;
        iVar13 = iVar16 + -1;
        puVar14 = local_4c->d;
LAB_081e1088:
        uVar8 = *puVar19;
        if (local_7c != 0) goto LAB_081e1194;
LAB_081e1095:
        if (uVar8 != 1) {
          puVar10 = __s;
          iVar18 = local_6c;
          puVar15 = puVar14;
          if (local_6c <= local_7c) goto LAB_081e11ba;
LAB_081e10ab:
          pBVar3 = local_64;
          pBVar1 = local_68;
          puVar14 = local_68->d;
          __s = local_64->d;
          local_6c = local_7c;
          pBVar6 = local_4c;
          local_68 = local_4c;
          pBVar2 = local_58;
          local_4c = pBVar1;
          local_64 = local_58;
          local_58 = pBVar3;
          puVar17 = puVar10;
          puVar19 = puVar15;
          local_7c = iVar18;
          if (0 < iVar16) {
LAB_081e10f1:
            iVar18 = 0;
            do {
              puVar19[iVar18] = puVar19[iVar18] ^ puVar14[iVar18];
              puVar17[iVar18] = puVar17[iVar18] ^ __s[iVar18];
              iVar18 = iVar18 + 1;
            } while (iVar16 != iVar18);
LAB_081e1118:
            if (local_7c != local_6c) goto LAB_081e1088;
            iVar18 = local_7c + 0x1e;
            if (-1 < local_7c + -1) {
              iVar18 = local_7c + -1;
            }
            iVar18 = iVar18 >> 5;
            uVar8 = puVar19[iVar18];
            if (uVar8 == 0) {
              do {
                if (iVar18 == 0) {
                  iVar18 = 0;
                  goto LAB_081e1167;
                }
                iVar18 = iVar18 + -1;
                uVar8 = puVar19[iVar18];
              } while (uVar8 == 0);
              iVar18 = iVar18 * 0x20;
            }
            else {
              iVar18 = iVar18 << 5;
            }
LAB_081e1167:
            iVar4 = BN_num_bits_word(uVar8);
            iVar4 = iVar4 + iVar18;
            local_6c = local_7c;
            uVar8 = *puVar19;
            local_7c = iVar4;
            if (iVar4 == 0) goto LAB_081e1095;
LAB_081e1194:
            if ((uVar8 & 1) != 0) {
              if (local_7c < 0x21) goto LAB_081e1095;
              puVar10 = __s;
              iVar18 = local_6c;
              puVar15 = puVar14;
              if (local_7c < local_6c) goto LAB_081e10ab;
LAB_081e11ba:
              if (0 < iVar16) goto LAB_081e10f1;
              goto LAB_081e1118;
            }
            uVar9 = *puVar17;
            puVar10 = param_3->d;
            uVar12 = -(uVar9 & 1) & *puVar10 ^ *puVar17;
            local_50 = uVar8 & 1;
            if (0 < iVar13) {
              iVar18 = 0;
              uVar7 = uVar8;
              do {
                uVar8 = puVar19[iVar18 + 1];
                uVar11 = uVar12 >> 1;
                puVar19[iVar18] = uVar7 >> 1 | uVar8 << 0x1f;
                uVar12 = -(uVar9 & 1) & puVar10[iVar18 + 1] ^ puVar17[iVar18 + 1];
                puVar17[iVar18] = uVar11 | uVar12 << 0x1f;
                iVar18 = iVar18 + 1;
                uVar7 = uVar8;
                local_50 = iVar13 * 4;
              } while (iVar18 != iVar13);
            }
            local_7c = local_7c + -1;
            *(ulong *)((int)puVar19 + local_50) = uVar8 >> 1;
            *(uint *)((int)puVar17 + local_50) = uVar12 >> 1;
          }
          goto LAB_081e1088;
        }
        iVar16 = local_64->top;
        if (0 < iVar16) {
          do {
            if (local_64->d[iVar16 + -1] != 0) break;
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
          local_64->top = iVar16;
        }
        pBVar6 = BN_copy(param_1,local_64);
        bVar20 = pBVar6 != (BIGNUM *)0x0;
        goto LAB_081e11fa;
      }
    }
  }
LAB_081e11f8:
  bVar20 = false;
LAB_081e11fa:
  BN_CTX_end(param_4);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar20;
}

