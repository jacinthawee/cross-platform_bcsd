
/* WARNING: Could not reconcile some variable overlaps */

void CRYPTO_ccm128_encrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint3 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint *puVar13;
  code *pcVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  uint *local_60;
  uint *local_58;
  uint local_54;
  uint *local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_2c;
  
  bVar1 = *param_1;
  pcVar14 = *(code **)(param_1 + 0x28);
  uVar11 = *(undefined4 *)(param_1 + 0x2c);
  local_2c = __stack_chk_guard;
  if (-1 < (int)((uint)bVar1 << 0x19)) {
    (*pcVar14)(param_1,param_1 + 0x10,uVar11);
    uVar15 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar15 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar15);
  }
  uVar15 = bVar1 & 7;
  iVar16 = 0xf - uVar15;
  *param_1 = (byte)uVar15;
  if ((bVar1 & 7) == 0) {
    local_54 = 0;
  }
  else {
    bVar2 = param_1[iVar16];
    iVar7 = 0x10 - uVar15;
    param_1[iVar16] = 0;
    local_54 = (uint)bVar2 << 8;
    if (iVar7 != 0xf) {
      bVar3 = param_1[iVar7];
      iVar6 = 0x11 - uVar15;
      param_1[iVar7] = 0;
      uVar4 = CONCAT11(bVar2,bVar3);
      local_54 = (uint)uVar4 << 8;
      if (iVar6 != 0xf) {
        bVar2 = param_1[iVar6];
        iVar7 = 0x12 - uVar15;
        param_1[iVar6] = 0;
        uVar5 = CONCAT21(uVar4,bVar2);
        local_54 = (uint)uVar5 << 8;
        if (iVar7 != 0xf) {
          bVar2 = param_1[iVar7];
          iVar6 = 0x13 - uVar15;
          param_1[iVar7] = 0;
          local_54 = CONCAT31(uVar5,bVar2) << 8;
          if (iVar6 != 0xf) {
            bVar2 = param_1[iVar6];
            iVar7 = 0x14 - uVar15;
            param_1[iVar6] = 0;
            local_54 = (local_54 | bVar2) << 8;
            if (iVar7 != 0xf) {
              bVar2 = param_1[iVar7];
              param_1[iVar7] = 0;
              local_54 = (local_54 | bVar2) << 8;
              if (uVar15 != 6) {
                bVar2 = param_1[0xe];
                param_1[0xe] = 0;
                local_54 = (local_54 | bVar2) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar2 = param_1[0xf];
  param_1[0xf] = 1;
  local_54 = bVar2 | local_54;
  if (local_54 != param_4) {
    uVar11 = 0xffffffff;
    goto LAB_000ff0fe;
  }
  uVar8 = param_4 + 0xf >> 3 | 1;
  iVar7 = *(uint *)(param_1 + 0x20) + uVar8;
  uVar8 = *(int *)(param_1 + 0x24) + (uint)CARRY4(*(uint *)(param_1 + 0x20),uVar8);
  *(int *)(param_1 + 0x20) = iVar7;
  *(uint *)(param_1 + 0x24) = uVar8;
  bVar19 = 0x1fffffff < uVar8;
  if (uVar8 == 0x20000000) {
    bVar19 = iVar7 != 0;
  }
  if (bVar19) {
    uVar11 = 0xfffffffe;
    goto LAB_000ff0fe;
  }
  if (param_4 < 0x10) {
    local_58 = param_2;
    local_50 = param_3;
    if (local_54 != 0) goto LAB_000fef08;
  }
  else {
    puVar13 = param_2;
    puVar17 = param_3;
    do {
      uVar8 = *puVar13;
      uVar10 = puVar13[1];
      uVar9 = puVar13[2];
      uVar12 = puVar13[3];
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ uVar8;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ uVar10;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ uVar9;
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ uVar12;
      (*pcVar14)(param_1 + 0x10,param_1 + 0x10,uVar11);
      (*pcVar14)(param_1,&local_40,uVar11);
      bVar3 = param_1[0xf];
      param_1[0xf] = bVar3 + 1;
      if ((((((byte)(bVar3 + 1) == 0) &&
            (bVar3 = param_1[0xe], param_1[0xe] = bVar3 + 1, (byte)(bVar3 + 1) == 0)) &&
           (bVar3 = param_1[0xd], param_1[0xd] = bVar3 + 1, (byte)(bVar3 + 1) == 0)) &&
          ((bVar3 = param_1[0xc], param_1[0xc] = bVar3 + 1, (byte)(bVar3 + 1) == 0 &&
           (bVar3 = param_1[0xb], param_1[0xb] = bVar3 + 1, (byte)(bVar3 + 1) == 0)))) &&
         ((bVar3 = param_1[10], param_1[10] = bVar3 + 1, (byte)(bVar3 + 1) == 0 &&
          (bVar3 = param_1[9], param_1[9] = bVar3 + 1, (byte)(bVar3 + 1) == 0)))) {
        param_1[8] = param_1[8] + 1;
      }
      param_4 = param_4 - 0x10;
      puVar13 = puVar13 + 4;
      puVar17[2] = uVar9 ^ local_38;
      puVar17[3] = uVar12 ^ local_34;
      *puVar17 = uVar8 ^ local_40;
      puVar17[1] = uVar10 ^ local_3c;
      puVar17 = puVar17 + 4;
    } while (0xf < param_4);
    uVar8 = local_54 - 0x10;
    local_54 = bVar2 & 0xf;
    iVar7 = (uVar8 & 0xfffffff0) + 0x10;
    local_58 = (uint *)((int)param_2 + iVar7);
    local_50 = (uint *)((int)param_3 + iVar7);
    if ((bVar2 & 0xf) != 0) {
LAB_000fef08:
      local_60 = &local_40;
      bVar19 = 5 < local_54;
      puVar17 = local_58 + 1;
      puVar13 = (uint *)(param_1 + 0x10);
      bVar20 = local_58 <= param_1 + 0x14;
      bVar18 = (uint *)(param_1 + 0x14) == local_58;
      if (bVar20 && !bVar18) {
        bVar20 = puVar13 <= puVar17;
        bVar18 = puVar17 == puVar13;
      }
      if (!bVar19 || (bVar20 && !bVar18 || ((uint)local_58 & 3) != 0)) {
        param_1[0x10] = param_1[0x10] ^ *(byte *)local_58;
        if ((((1 < local_54) &&
             (param_1[0x11] = param_1[0x11] ^ *(byte *)((int)local_58 + 1), 2 < local_54)) &&
            ((param_1[0x12] = param_1[0x12] ^ *(byte *)((int)local_58 + 2), 3 < local_54 &&
             (((param_1[0x13] = param_1[0x13] ^ *(byte *)((int)local_58 + 3), 4 < local_54 &&
               (param_1[0x14] = param_1[0x14] ^ *(byte *)(local_58 + 1), bVar19)) &&
              (param_1[0x15] = param_1[0x15] ^ *(byte *)((int)local_58 + 5), 6 < local_54)))))) &&
           (((param_1[0x16] = param_1[0x16] ^ *(byte *)((int)local_58 + 6), 7 < local_54 &&
             (param_1[0x17] = param_1[0x17] ^ *(byte *)((int)local_58 + 7), 8 < local_54)) &&
            ((param_1[0x18] = param_1[0x18] ^ *(byte *)(local_58 + 2), 9 < local_54 &&
             (((param_1[0x19] = param_1[0x19] ^ *(byte *)((int)local_58 + 9), 10 < local_54 &&
               (param_1[0x1a] = param_1[0x1a] ^ *(byte *)((int)local_58 + 10), 0xb < local_54)) &&
              ((param_1[0x1b] = param_1[0x1b] ^ *(byte *)((int)local_58 + 0xb), 0xc < local_54 &&
               ((param_1[0x1c] = param_1[0x1c] ^ *(byte *)(local_58 + 3), 0xd < local_54 &&
                (param_1[0x1d] = param_1[0x1d] ^ *(byte *)((int)local_58 + 0xd), 0xe < local_54)))))
              ))))))) {
          param_1[0x1e] = param_1[0x1e] ^ *(byte *)((int)local_58 + 0xe);
        }
      }
      else {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ *local_58;
        uVar8 = local_54 & 0xfffffffc;
        if ((1 < local_54 >> 2) &&
           (*(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_58[1], 2 < local_54 >> 2))
        {
          *(uint *)(param_1 + 0x18) = local_58[2] ^ *(uint *)(param_1 + 0x18);
        }
        if (local_54 != uVar8) {
          param_1[uVar8 + 0x10] =
               param_1[uVar8 + 0x10] ^ *(byte *)((int)local_58 + (local_54 & 0xfffffffc));
          if (uVar8 + 1 < local_54) {
            param_1[uVar8 + 0x11] = *(byte *)((int)local_58 + uVar8 + 1) ^ param_1[uVar8 + 0x11];
            if (uVar8 + 2 < local_54) {
              param_1[uVar8 + 0x12] = param_1[uVar8 + 0x12] ^ *(byte *)((int)local_58 + uVar8 + 2);
            }
          }
        }
      }
      (*pcVar14)(puVar13,puVar13,uVar11);
      (*pcVar14)(param_1,local_60);
      puVar13 = local_50 + 1;
      bVar20 = local_50 <= &local_3c;
      bVar18 = &local_3c == local_50;
      if (bVar20 && !bVar18) {
        bVar20 = local_60 <= puVar13;
        bVar18 = puVar13 == local_60;
      }
      if ((((uint)local_50 | (uint)local_58) & 3) != 0 ||
          ((local_50 < puVar17 && local_58 < puVar13 || bVar20 && !bVar18) || 6 >= local_54)) {
        *(byte *)local_50 = (byte)local_40 ^ *(byte *)local_58;
        if (1 < local_54) {
          *(byte *)((int)local_50 + 1) = local_40._1_1_ ^ *(byte *)((int)local_58 + 1);
          if (2 < local_54) {
            *(byte *)((int)local_50 + 2) = local_40._2_1_ ^ *(byte *)((int)local_58 + 2);
            if (3 < local_54) {
              *(byte *)((int)local_50 + 3) = local_40._3_1_ ^ *(byte *)((int)local_58 + 3);
              if (4 < local_54) {
                *(byte *)(local_50 + 1) = (byte)local_3c ^ *(byte *)(local_58 + 1);
                if (bVar19) {
                  *(byte *)((int)local_50 + 5) = local_3c._1_1_ ^ *(byte *)((int)local_58 + 5);
                  if (6 < local_54) {
                    *(byte *)((int)local_50 + 6) = local_3c._2_1_ ^ *(byte *)((int)local_58 + 6);
                    if (7 < local_54) {
                      *(byte *)((int)local_50 + 7) = local_3c._3_1_ ^ *(byte *)((int)local_58 + 7);
                      if (8 < local_54) {
                        *(byte *)(local_50 + 2) = (byte)local_38 ^ *(byte *)(local_58 + 2);
                        if (9 < local_54) {
                          *(byte *)((int)local_50 + 9) =
                               local_38._1_1_ ^ *(byte *)((int)local_58 + 9);
                          if (10 < local_54) {
                            *(byte *)((int)local_50 + 10) =
                                 local_38._2_1_ ^ *(byte *)((int)local_58 + 10);
                            if (0xb < local_54) {
                              *(byte *)((int)local_50 + 0xb) =
                                   local_38._3_1_ ^ *(byte *)((int)local_58 + 0xb);
                              if (0xc < local_54) {
                                *(byte *)(local_50 + 3) = (byte)local_34 ^ *(byte *)(local_58 + 3);
                                if (0xd < local_54) {
                                  *(byte *)((int)local_50 + 0xd) =
                                       local_34._1_1_ ^ *(byte *)((int)local_58 + 0xd);
                                  if (0xe < local_54) {
                                    *(byte *)((int)local_50 + 0xe) =
                                         local_34._2_1_ ^ *(byte *)((int)local_58 + 0xe);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        uVar8 = local_54 & 0xfffffffc;
        *local_50 = local_40 ^ *local_58;
        if ((1 < local_54 >> 2) && (local_50[1] = local_58[1] ^ local_3c, 2 < local_54 >> 2)) {
          local_50[2] = local_58[2] ^ local_38;
        }
        if (local_54 != uVar8) {
          uVar9 = uVar8 + 1;
          *(byte *)((int)local_50 + (local_54 & 0xfffffffc)) =
               *(byte *)((int)&local_40 + uVar8) ^
               *(byte *)((int)local_58 + (local_54 & 0xfffffffc));
          if (uVar9 < local_54) {
            uVar10 = uVar8 + 2;
            *(byte *)((int)local_50 + uVar9) =
                 *(byte *)((int)&local_40 + uVar8 + 1) ^ *(byte *)((int)local_58 + uVar9);
            if (uVar10 < local_54) {
              *(byte *)((int)local_50 + uVar10) =
                   *(byte *)((int)&local_40 + uVar8 + 2) ^ *(byte *)((int)local_58 + uVar10);
            }
          }
        }
      }
    }
  }
  local_60 = &local_40;
  memset(param_1 + iVar16,0,uVar15 + 1);
  (*pcVar14)(param_1,local_60,uVar11);
  uVar11 = 0;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_40;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_3c;
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_34;
LAB_000ff0fe:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar11);
}

