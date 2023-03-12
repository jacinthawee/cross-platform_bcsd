
/* WARNING: Could not reconcile some variable overlaps */

undefined4 CRYPTO_ccm128_encrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  code *pcVar5;
  ushort uVar6;
  uint3 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  uint uVar16;
  uint *puVar17;
  int in_GS_OFFSET;
  undefined4 *local_58;
  uint local_54;
  uint *local_50;
  uint *local_4c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_50 = param_2;
  pcVar5 = *(code **)(param_1 + 0x28);
  uVar11 = *(undefined4 *)(param_1 + 0x2c);
  local_4c = param_3;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar2 = *param_1;
  if ((bVar2 & 0x40) == 0) {
    (*pcVar5)(param_1,param_1 + 0x10,uVar11);
    puVar15 = (uint *)(param_1 + 0x20);
    uVar16 = *puVar15;
    *puVar15 = *puVar15 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar16);
  }
  uVar16 = (uint)(bVar2 & 7);
  *param_1 = bVar2 & 7;
  iVar8 = 0xf - uVar16;
  if (iVar8 == 0xf) {
    local_54 = 0;
  }
  else {
    bVar3 = param_1[iVar8];
    param_1[iVar8] = 0;
    iVar12 = 0x10 - uVar16;
    local_54 = (uint)bVar3 << 8;
    if (iVar12 != 0xf) {
      bVar4 = param_1[iVar12];
      param_1[iVar12] = 0;
      iVar12 = 0x11 - uVar16;
      uVar6 = CONCAT11(bVar3,bVar4);
      local_54 = (uint)uVar6 << 8;
      if (iVar12 != 0xf) {
        bVar3 = param_1[iVar12];
        param_1[iVar12] = 0;
        iVar12 = 0x12 - uVar16;
        uVar7 = CONCAT21(uVar6,bVar3);
        local_54 = (uint)uVar7 << 8;
        if (iVar12 != 0xf) {
          bVar3 = param_1[iVar12];
          param_1[iVar12] = 0;
          iVar12 = 0x13 - uVar16;
          local_54 = CONCAT31(uVar7,bVar3) << 8;
          if (iVar12 != 0xf) {
            bVar3 = param_1[iVar12];
            param_1[iVar12] = 0;
            iVar12 = 0x14 - uVar16;
            local_54 = (local_54 | bVar3) << 8;
            if (iVar12 != 0xf) {
              bVar3 = param_1[iVar12];
              param_1[iVar12] = 0;
              local_54 = (local_54 | bVar3) << 8;
              if (uVar16 != 6) {
                bVar3 = param_1[0xe];
                param_1[0xe] = 0;
                local_54 = (local_54 | bVar3) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar3 = param_1[0xf];
  param_1[0xf] = 1;
  local_54 = bVar3 | local_54;
  if (local_54 != param_4) {
    uVar11 = 0xffffffff;
    goto LAB_081b6290;
  }
  uVar9 = param_4 + 0xf >> 3 | 1;
  iVar12 = uVar9 + *(uint *)(param_1 + 0x20);
  uVar9 = *(int *)(param_1 + 0x24) + (uint)CARRY4(uVar9,*(uint *)(param_1 + 0x20));
  *(int *)(param_1 + 0x20) = iVar12;
  *(uint *)(param_1 + 0x24) = uVar9;
  if ((0x20000000 < uVar9) || ((0x1fffffff < uVar9 && (iVar12 != 0)))) {
    uVar11 = 0xfffffffe;
    goto LAB_081b6290;
  }
  if (0xf < local_54) {
    uVar9 = local_54;
    puVar15 = param_2;
    puVar17 = param_3;
    do {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ *puVar15;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ puVar15[1];
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ puVar15[2];
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ puVar15[3];
      (*pcVar5)(param_1 + 0x10,param_1 + 0x10,uVar11);
      (*pcVar5)(param_1,&local_30,uVar11);
      bVar4 = param_1[0xf];
      param_1[0xf] = bVar4 + 1;
      if ((byte)(bVar4 + 1) == 0) {
        pbVar1 = param_1 + 0xe;
        *pbVar1 = *pbVar1 + 1;
        if (*pbVar1 == 0) {
          pbVar1 = param_1 + 0xd;
          *pbVar1 = *pbVar1 + 1;
          if (*pbVar1 == 0) {
            pbVar1 = param_1 + 0xc;
            *pbVar1 = *pbVar1 + 1;
            if (*pbVar1 == 0) {
              pbVar1 = param_1 + 0xb;
              *pbVar1 = *pbVar1 + 1;
              if (*pbVar1 == 0) {
                pbVar1 = param_1 + 10;
                *pbVar1 = *pbVar1 + 1;
                if (*pbVar1 == 0) {
                  pbVar1 = param_1 + 9;
                  *pbVar1 = *pbVar1 + 1;
                  if (*pbVar1 == 0) {
                    param_1[8] = param_1[8] + 1;
                  }
                }
              }
            }
          }
        }
      }
      uVar9 = uVar9 - 0x10;
      *puVar17 = local_30 ^ *puVar15;
      puVar17[1] = local_2c ^ puVar15[1];
      puVar17[2] = local_28 ^ puVar15[2];
      puVar17[3] = local_24 ^ puVar15[3];
      puVar15 = puVar15 + 4;
      puVar17 = puVar17 + 4;
    } while (0xf < uVar9);
    iVar12 = (local_54 - 0x10 & 0xfffffff0) + 0x10;
    local_50 = (uint *)((int)param_2 + iVar12);
    local_4c = (uint *)((int)param_3 + iVar12);
    local_54 = bVar3 & 0xf;
  }
  local_58 = &local_30;
  if (local_54 != 0) {
    puVar15 = (uint *)(param_1 + 0x10);
    if ((local_54 < 6 || puVar15 < local_50 + 1 && local_50 < param_1 + 0x14) ||
       (((uint)local_50 & 3) != 0)) {
      param_1[0x10] = param_1[0x10] ^ *(byte *)local_50;
      if (((((local_54 != 1) &&
            (((param_1[0x11] = param_1[0x11] ^ *(byte *)((int)local_50 + 1), local_54 != 2 &&
              (param_1[0x12] = param_1[0x12] ^ *(byte *)((int)local_50 + 2), local_54 != 3)) &&
             (param_1[0x13] = param_1[0x13] ^ *(byte *)((int)local_50 + 3), local_54 != 4)))) &&
           (((param_1[0x14] = param_1[0x14] ^ *(byte *)(local_50 + 1), 5 < local_54 &&
             (param_1[0x15] = param_1[0x15] ^ *(byte *)((int)local_50 + 5), 6 < local_54)) &&
            (param_1[0x16] = param_1[0x16] ^ *(byte *)((int)local_50 + 6), local_54 != 7)))) &&
          ((param_1[0x17] = param_1[0x17] ^ *(byte *)((int)local_50 + 7), local_54 != 8 &&
           (param_1[0x18] = param_1[0x18] ^ *(byte *)(local_50 + 2), local_54 != 9)))) &&
         ((param_1[0x19] = param_1[0x19] ^ *(byte *)((int)local_50 + 9), local_54 != 10 &&
          ((((param_1[0x1a] = param_1[0x1a] ^ *(byte *)((int)local_50 + 10), local_54 != 0xb &&
             (param_1[0x1b] = param_1[0x1b] ^ *(byte *)((int)local_50 + 0xb), local_54 != 0xc)) &&
            (param_1[0x1c] = param_1[0x1c] ^ *(byte *)(local_50 + 3), local_54 != 0xd)) &&
           (param_1[0x1d] = param_1[0x1d] ^ *(byte *)((int)local_50 + 0xd), local_54 == 0xf)))))) {
        param_1[0x1e] = param_1[0x1e] ^ *(byte *)((int)local_50 + 0xe);
      }
    }
    else {
      iVar12 = (local_54 - 4 >> 2) + 1;
      uVar9 = iVar12 * 4;
      if (local_54 - 1 < 3) {
        uVar9 = 0;
      }
      else {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ *local_50;
        if (((iVar12 != 1) &&
            (*(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_50[1], iVar12 != 2)) &&
           (*(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_50[2], iVar12 != 3)) {
          *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_50[3];
        }
        if (local_54 == uVar9) goto LAB_081b6143;
      }
      param_1[uVar9 + 0x10] = param_1[uVar9 + 0x10] ^ *(byte *)((int)local_50 + uVar9);
      if (uVar9 + 1 < local_54) {
        param_1[uVar9 + 0x11] = param_1[uVar9 + 0x11] ^ *(byte *)((int)local_50 + uVar9 + 1);
        if (uVar9 + 2 < local_54) {
          param_1[uVar9 + 0x12] = param_1[uVar9 + 0x12] ^ *(byte *)((int)local_50 + uVar9 + 2);
        }
      }
    }
LAB_081b6143:
    (*pcVar5)(puVar15,puVar15,uVar11);
    (*pcVar5)(param_1,local_58,uVar11);
    if ((local_54 < 6 || local_50 < local_4c + 1 && local_4c < local_50 + 1) ||
       ((((uint)local_4c | (uint)local_50) & 3) != 0)) {
      *(byte *)local_4c = (byte)local_30 ^ *(byte *)local_50;
      if (local_54 != 1) {
        *(byte *)((int)local_4c + 1) = local_30._1_1_ ^ *(byte *)((int)local_50 + 1);
        if (local_54 != 2) {
          *(byte *)((int)local_4c + 2) = local_30._2_1_ ^ *(byte *)((int)local_50 + 2);
          if (local_54 != 3) {
            *(byte *)((int)local_4c + 3) = local_30._3_1_ ^ *(byte *)((int)local_50 + 3);
            if (local_54 != 4) {
              *(byte *)(local_4c + 1) = (byte)local_2c ^ *(byte *)(local_50 + 1);
              if (5 < local_54) {
                *(byte *)((int)local_4c + 5) = local_2c._1_1_ ^ *(byte *)((int)local_50 + 5);
                if (6 < local_54) {
                  *(byte *)((int)local_4c + 6) = local_2c._2_1_ ^ *(byte *)((int)local_50 + 6);
                  if (local_54 != 7) {
                    *(byte *)((int)local_4c + 7) = local_2c._3_1_ ^ *(byte *)((int)local_50 + 7);
                    if (local_54 != 8) {
                      *(byte *)(local_4c + 2) = (byte)local_28 ^ *(byte *)(local_50 + 2);
                      if (local_54 != 9) {
                        *(byte *)((int)local_4c + 9) = local_28._1_1_ ^ *(byte *)((int)local_50 + 9)
                        ;
                        if (local_54 != 10) {
                          *(byte *)((int)local_4c + 10) =
                               local_28._2_1_ ^ *(byte *)((int)local_50 + 10);
                          if (local_54 != 0xb) {
                            *(byte *)((int)local_4c + 0xb) =
                                 local_28._3_1_ ^ *(byte *)((int)local_50 + 0xb);
                            if (local_54 != 0xc) {
                              *(byte *)(local_4c + 3) = (byte)local_24 ^ *(byte *)(local_50 + 3);
                              if (local_54 != 0xd) {
                                *(byte *)((int)local_4c + 0xd) =
                                     local_24._1_1_ ^ *(byte *)((int)local_50 + 0xd);
                                if (local_54 == 0xf) {
                                  *(byte *)((int)local_4c + 0xe) =
                                       local_24._2_1_ ^ *(byte *)((int)local_50 + 0xe);
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
      iVar13 = (local_54 - 4 >> 2) + 1;
      iVar12 = iVar13 * 4;
      if (local_54 - 1 < 3) {
        iVar12 = 0;
      }
      else {
        *local_4c = local_30 ^ *local_50;
        if (((iVar13 != 1) && (local_4c[1] = local_2c ^ local_50[1], iVar13 != 2)) &&
           (local_4c[2] = local_28 ^ local_50[2], iVar13 != 3)) {
          local_4c[3] = local_24 ^ local_50[3];
        }
        if (iVar12 - local_54 == 0) goto LAB_081b6232;
      }
      *(byte *)((int)local_4c + iVar12) =
           *(byte *)((int)local_50 + iVar12) ^ *(byte *)((int)&local_30 + iVar12);
      if (iVar12 + 1U < local_54) {
        *(byte *)((int)local_4c + iVar12 + 1) =
             *(byte *)((int)local_50 + iVar12 + 1) ^ *(byte *)((int)&local_30 + iVar12 + 1);
        if (iVar12 + 2U < local_54) {
          *(byte *)((int)local_4c + iVar12 + 2) =
               *(byte *)((int)local_50 + iVar12 + 2) ^ *(byte *)((int)&local_30 + iVar12 + 2);
        }
      }
    }
  }
LAB_081b6232:
  uVar9 = 0x10 - iVar8;
  puVar10 = (undefined4 *)(param_1 + (0xf - uVar16));
  if (uVar9 < 4) {
    if ((uVar9 != 0) && (*(undefined *)puVar10 = 0, (uVar9 & 2) != 0)) {
      *(undefined2 *)(param_1 + uVar9 + (0xd - uVar16)) = 0;
    }
  }
  else {
    *puVar10 = 0;
    *(undefined4 *)(param_1 + uVar9 + (0xb - uVar16)) = 0;
    uVar9 = (uint)((int)puVar10 + (uVar9 - ((uint)(param_1 + (0x13 - uVar16)) & 0xfffffffc))) &
            0xfffffffc;
    if (3 < uVar9) {
      uVar14 = 0;
      do {
        *(undefined4 *)(((uint)(param_1 + (0x13 - uVar16)) & 0xfffffffc) + uVar14) = 0;
        uVar14 = uVar14 + 4;
      } while (uVar14 < uVar9);
    }
  }
  (*pcVar5)(param_1,local_58,uVar11);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_30;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_2c;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_28;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_24;
  *param_1 = bVar2;
  uVar11 = 0;
LAB_081b6290:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}

