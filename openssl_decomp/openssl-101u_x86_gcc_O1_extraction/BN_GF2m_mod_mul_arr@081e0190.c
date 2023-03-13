
bool BN_GF2m_mod_mul_arr(BIGNUM *param_1,int *param_2,int *param_3,int *param_4,BN_CTX *param_5)

{
  uint uVar1;
  ulong *puVar2;
  ulong *puVar3;
  int iVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  int iVar7;
  BIGNUM *pBVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int in_GS_OFFSET;
  bool bVar17;
  int local_164;
  uint local_160;
  uint local_15c;
  byte local_158;
  uint local_140;
  ulong local_13c;
  ulong local_138;
  uint *local_134;
  uint local_130;
  int local_68;
  uint local_40 [4];
  int local_30;
  
  iVar4 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 == param_3) {
    if (iVar4 != *(int *)(in_GS_OFFSET + 0x14)) goto LAB_081e0db1;
    local_30 = 0x81dff90;
    BN_CTX_start(param_5);
    local_30 = 0x81dff9a;
    pBVar5 = BN_CTX_get(param_5);
    if (pBVar5 == (BIGNUM *)0x0) {
LAB_081e0139:
      bVar17 = false;
    }
    else {
      iVar4 = param_2[1];
      if (pBVar5->dmax < iVar4 * 2) {
        local_30 = 0x81e0132;
        pBVar8 = bn_expand2(pBVar5,iVar4 * 2);
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_081e0139;
        iVar4 = param_2[1];
      }
      iVar12 = iVar4 + -1;
      if (-1 < iVar12) {
        puVar2 = pBVar5->d;
        iVar4 = *param_2;
        do {
          uVar1 = *(uint *)(iVar4 + iVar12 * 4);
          puVar2[iVar12 * 2 + 1] =
               *(int *)(SQR_tb + (uVar1 >> 0x18 & 0xf) * 4) << 0x10 |
               *(int *)(SQR_tb + (uVar1 >> 0x1c) * 4) << 0x18 |
               *(uint *)(SQR_tb + (uVar1 >> 0x10 & 0xf) * 4) |
               *(int *)(SQR_tb + (uVar1 >> 0x14 & 0xf) * 4) << 8;
          uVar1 = *(uint *)(iVar4 + iVar12 * 4);
          puVar2[iVar12 * 2] =
               *(int *)(SQR_tb + (uVar1 >> 8 & 0xf) * 4) << 0x10 |
               *(int *)(SQR_tb + (uVar1 >> 0xc & 0xf) * 4) << 0x18 |
               *(uint *)(SQR_tb + (uVar1 & 0xf) * 4) |
               *(int *)(SQR_tb + (uVar1 >> 4 & 0xf) * 4) << 8;
          iVar12 = iVar12 + -1;
        } while (iVar12 != -1);
        iVar4 = param_2[1];
      }
      iVar4 = iVar4 * 2;
      pBVar5->top = iVar4;
      if (0 < iVar4) {
        do {
          if (pBVar5->d[iVar4 + -1] != 0) break;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        pBVar5->top = iVar4;
      }
      if (*param_4 == 0) {
        bVar17 = true;
        local_30 = 0x81e0153;
        BN_set_word(param_1,0);
        goto LAB_081e010b;
      }
      if (pBVar5 != param_1) {
        if (param_1->dmax < iVar4) {
          local_30 = 0x81e016d;
          pBVar8 = bn_expand2(param_1,iVar4);
          if (pBVar8 == (BIGNUM *)0x0) goto LAB_081e0139;
          iVar4 = pBVar5->top;
        }
        if (0 < iVar4) {
          puVar2 = pBVar5->d;
          iVar12 = 0;
          puVar3 = param_1->d;
          do {
            puVar3[iVar12] = puVar2[iVar12];
            iVar4 = pBVar5->top;
            iVar12 = iVar12 + 1;
          } while (iVar12 < iVar4);
        }
        param_1->top = iVar4;
      }
      iVar4 = BN_GF2m_mod_arr_part_0();
      bVar17 = iVar4 != 0;
    }
LAB_081e010b:
    local_30 = 0x81e0117;
    BN_CTX_end(param_5);
    return bVar17;
  }
  BN_CTX_start(param_5);
  pBVar5 = BN_CTX_get(param_5);
  if ((pBVar5 == (BIGNUM *)0x0) ||
     ((iVar12 = param_3[1] + param_2[1] + 4, pBVar5->dmax < iVar12 &&
      (pBVar8 = bn_expand2(pBVar5,iVar12), pBVar8 == (BIGNUM *)0x0)))) {
LAB_081e0cba:
    bVar17 = false;
  }
  else {
    pBVar5->top = iVar12;
    if (iVar12 < 1) {
      iVar7 = param_3[1];
      if (0 < iVar7) goto LAB_081e027a;
    }
    else {
      memset(pBVar5->d,0,iVar12 * 4);
      iVar7 = param_3[1];
      if (0 < iVar7) {
LAB_081e027a:
        local_68 = 0;
        iVar12 = *param_3;
        iVar16 = param_2[1];
        do {
          uVar1 = *(uint *)(iVar12 + local_68 * 4);
          uVar6 = 0;
          if (iVar7 != local_68 + 1) {
            uVar6 = *(uint *)(iVar12 + 4 + local_68 * 4);
          }
          if (0 < iVar16) {
            iVar7 = *param_2;
            uVar9 = uVar6 ^ uVar1;
            local_164 = 0;
            puVar2 = pBVar5->d + local_68;
            local_134 = pBVar5->d + local_68 + 2;
            local_13c = puVar2[1];
            local_138 = *puVar2;
            do {
              uVar11 = *(uint *)(iVar7 + local_164 * 4);
              if (iVar16 == local_164 + 1) {
                uVar15 = 0;
                local_140 = 0;
                local_40[3] = 0;
                local_30 = 0;
                local_40[2] = 0;
                local_40[1] = 0;
                local_130 = 0;
              }
              else {
                local_130 = *(uint *)(iVar7 + 4 + local_164 * 4);
                local_40[1] = local_130 & 0x3fffffff;
                local_30 = local_40[1] * 4;
                local_40[2] = local_40[1] * 2;
                local_40[3] = local_40[1] ^ local_40[2];
                local_140 = local_130 >> 0x1e & 1;
                uVar15 = local_130 >> 0x1e & 2;
              }
              local_40[0] = 0;
              local_160 = local_40[uVar6 >> 0x1b & 7] << 0x1b ^
                          local_40[uVar6 >> 3 & 7] << 3 ^
                          local_40[uVar6 >> 0x1e] << 0x1e ^ local_40[uVar6 & 7] ^
                          local_40[uVar6 >> 6 & 7] << 6 ^ local_40[uVar6 >> 9 & 7] << 9 ^
                          local_40[uVar6 >> 0xc & 7] << 0xc ^ local_40[uVar6 >> 0xf & 7] << 0xf ^
                          local_40[uVar6 >> 0x12 & 7] << 0x12 ^ local_40[uVar6 >> 0x15 & 7] << 0x15
                          ^ local_40[uVar6 >> 0x18 & 7] << 0x18;
              local_15c = local_40[uVar6 >> 0x1b & 7] >> 5 ^
                          local_40[uVar6 >> 0x1e] >> 2 ^
                          local_40[uVar6 >> 3 & 7] >> 0x1d ^ local_40[uVar6 >> 6 & 7] >> 0x1a ^
                          local_40[uVar6 >> 9 & 7] >> 0x17 ^ local_40[uVar6 >> 0xc & 7] >> 0x14 ^
                          local_40[uVar6 >> 0xf & 7] >> 0x11 ^ local_40[uVar6 >> 0x12 & 7] >> 0xe ^
                          local_40[uVar6 >> 0x15 & 7] >> 0xb ^ local_40[uVar6 >> 0x18 & 7] >> 8;
              if (local_140 != 0) {
                local_160 = local_160 ^ uVar6 << 0x1e;
                local_15c = local_15c ^ uVar6 >> 2;
              }
              if (uVar15 != 0) {
                local_160 = local_160 ^ uVar6 << 0x1f;
                local_15c = local_15c ^ uVar6 >> 1;
              }
              local_40[0] = 0;
              local_40[1] = uVar11 & 0x3fffffff;
              local_40[2] = local_40[1] * 2;
              local_40[3] = local_40[1] ^ local_40[1] * 2;
              local_30 = local_40[1] * 4;
              uVar10 = local_40[uVar1 >> 6 & 7] << 6 ^
                       local_40[uVar1 >> 3 & 7] << 3 ^
                       local_40[uVar1 >> 0x1e] << 0x1e ^ local_40[uVar1 & 7] ^
                       local_40[uVar1 >> 9 & 7] << 9 ^ local_40[uVar1 >> 0xc & 7] << 0xc ^
                       local_40[uVar1 >> 0xf & 7] << 0xf ^ local_40[uVar1 >> 0x12 & 7] << 0x12 ^
                       local_40[uVar1 >> 0x15 & 7] << 0x15 ^ local_40[uVar1 >> 0x18 & 7] << 0x18 ^
                       local_40[uVar1 >> 0x1b & 7] << 0x1b;
              uVar15 = local_40[uVar1 >> 0x1e] >> 2 ^
                       local_40[uVar1 >> 6 & 7] >> 0x1a ^ local_40[uVar1 >> 3 & 7] >> 0x1d ^
                       local_40[uVar1 >> 9 & 7] >> 0x17 ^ local_40[uVar1 >> 0xc & 7] >> 0x14 ^
                       local_40[uVar1 >> 0xf & 7] >> 0x11 ^ local_40[uVar1 >> 0x12 & 7] >> 0xe ^
                       local_40[uVar1 >> 0x15 & 7] >> 0xb ^ local_40[uVar1 >> 0x18 & 7] >> 8 ^
                       local_40[uVar1 >> 0x1b & 7] >> 5;
              if ((uVar11 >> 0x1e & 1) != 0) {
                uVar10 = uVar10 ^ uVar1 << 0x1e;
                uVar15 = uVar15 ^ uVar1 >> 2;
              }
              if ((uVar11 >> 0x1e & 2) != 0) {
                uVar10 = uVar10 ^ uVar1 << 0x1f;
                uVar15 = uVar15 ^ uVar1 >> 1;
              }
              local_130 = local_130 ^ uVar11;
              local_40[0] = 0;
              local_40[1] = local_130 & 0x3fffffff;
              local_40[2] = local_40[1] * 2;
              local_40[3] = local_40[1] ^ local_40[1] * 2;
              local_30 = local_40[1] * 4;
              uVar13 = local_40[uVar9 >> 6 & 7] << 6 ^
                       local_40[uVar9 >> 3 & 7] << 3 ^
                       local_40[uVar9 >> 0x1e] << 0x1e ^ local_40[uVar9 & 7] ^
                       local_40[uVar9 >> 9 & 7] << 9 ^ local_40[uVar9 >> 0xc & 7] << 0xc ^
                       local_40[uVar9 >> 0xf & 7] << 0xf ^ local_40[uVar9 >> 0x12 & 7] << 0x12 ^
                       local_40[uVar9 >> 0x15 & 7] << 0x15 ^ local_40[uVar9 >> 0x18 & 7] << 0x18 ^
                       local_40[uVar9 >> 0x1b & 7] << 0x1b;
              uVar11 = local_40[uVar9 >> 0x1b & 7] >> 5 ^
                       local_40[uVar9 >> 3 & 7] >> 0x1d ^ local_40[uVar9 >> 6 & 7] >> 0x1a ^
                       local_40[uVar9 >> 0x1e] >> 2 ^ local_40[uVar9 >> 9 & 7] >> 0x17 ^
                       local_40[uVar9 >> 0xc & 7] >> 0x14 ^ local_40[uVar9 >> 0xf & 7] >> 0x11 ^
                       local_40[uVar9 >> 0x12 & 7] >> 0xe ^ local_40[uVar9 >> 0x15 & 7] >> 0xb ^
                       local_40[uVar9 >> 0x18 & 7] >> 8;
              local_158 = (byte)(local_130 >> 0x1e);
              if ((local_130 >> 0x1e & 1) != 0) {
                uVar13 = uVar13 ^ uVar9 << 0x1e;
                uVar11 = uVar11 ^ uVar9 >> 2;
              }
              if ((local_158 & 2) != 0) {
                uVar13 = uVar13 ^ uVar9 << 0x1f;
                uVar11 = uVar11 ^ uVar9 >> 1;
              }
              local_164 = local_164 + 2;
              uVar15 = uVar15 ^ local_160 ^ local_15c ^ uVar11;
              local_134[-2] = local_138 ^ uVar10;
              uVar14 = local_13c ^ local_15c;
              local_13c = local_15c ^ local_134[1];
              local_138 = uVar15 ^ *local_134;
              local_134[-1] = uVar14 ^ uVar10 ^ uVar11 ^ uVar13 ^ uVar15;
              local_134[1] = local_13c;
              *local_134 = local_138;
              iVar16 = param_2[1];
              local_134 = local_134 + 2;
            } while (local_164 < iVar16);
            iVar7 = param_3[1];
          }
          local_68 = local_68 + 2;
        } while (local_68 < iVar7);
      }
      iVar12 = pBVar5->top;
      if (0 < iVar12) {
        do {
          if (pBVar5->d[iVar12 + -1] != 0) break;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        pBVar5->top = iVar12;
      }
    }
    if (*param_4 == 0) {
      bVar17 = true;
      BN_set_word(param_1,0);
    }
    else {
      if (param_1 != pBVar5) {
        if (param_1->dmax < iVar12) {
          pBVar8 = bn_expand2(param_1,iVar12);
          if (pBVar8 == (BIGNUM *)0x0) goto LAB_081e0cba;
          iVar12 = pBVar5->top;
        }
        if (0 < iVar12) {
          puVar2 = pBVar5->d;
          puVar3 = param_1->d;
          iVar7 = 0;
          do {
            puVar3[iVar7] = puVar2[iVar7];
            iVar12 = pBVar5->top;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar12);
        }
        param_1->top = iVar12;
      }
      iVar12 = BN_GF2m_mod_arr_part_0();
      bVar17 = iVar12 != 0;
    }
  }
  BN_CTX_end(param_5);
  if (iVar4 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar17;
  }
LAB_081e0db1:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

