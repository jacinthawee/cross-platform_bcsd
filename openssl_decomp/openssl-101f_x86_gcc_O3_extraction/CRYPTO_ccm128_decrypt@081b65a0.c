
/* WARNING: Could not reconcile some variable overlaps */

undefined4 CRYPTO_ccm128_decrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  code *pcVar3;
  ushort uVar4;
  uint3 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint *puVar15;
  int in_GS_OFFSET;
  undefined4 *local_5c;
  uint local_54;
  uint *local_50;
  uint *local_4c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_4c = param_2;
  pcVar3 = *(code **)(param_1 + 0x28);
  local_50 = param_3;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar1 = *param_1;
  uVar8 = *(undefined4 *)(param_1 + 0x2c);
  if ((bVar1 & 0x40) == 0) {
    (*pcVar3)(param_1,param_1 + 0x10,uVar8);
  }
  uVar14 = (uint)(bVar1 & 7);
  *param_1 = bVar1 & 7;
  iVar6 = 0xf - uVar14;
  if (iVar6 == 0xf) {
    local_54 = 0;
  }
  else {
    bVar9 = param_1[iVar6];
    param_1[iVar6] = 0;
    iVar10 = 0x10 - uVar14;
    local_54 = (uint)bVar9 << 8;
    if (iVar10 != 0xf) {
      bVar2 = param_1[iVar10];
      param_1[iVar10] = 0;
      iVar10 = 0x11 - uVar14;
      uVar4 = CONCAT11(bVar9,bVar2);
      local_54 = (uint)uVar4 << 8;
      if (iVar10 != 0xf) {
        bVar9 = param_1[iVar10];
        param_1[iVar10] = 0;
        iVar10 = 0x12 - uVar14;
        uVar5 = CONCAT21(uVar4,bVar9);
        local_54 = (uint)uVar5 << 8;
        if (iVar10 != 0xf) {
          bVar9 = param_1[iVar10];
          param_1[iVar10] = 0;
          iVar10 = 0x13 - uVar14;
          local_54 = CONCAT31(uVar5,bVar9) << 8;
          if (iVar10 != 0xf) {
            bVar9 = param_1[iVar10];
            param_1[iVar10] = 0;
            iVar10 = 0x14 - uVar14;
            local_54 = (local_54 | bVar9) << 8;
            if (iVar10 != 0xf) {
              bVar9 = param_1[iVar10];
              param_1[iVar10] = 0;
              local_54 = (local_54 | bVar9) << 8;
              if (uVar14 != 6) {
                bVar9 = param_1[0xe];
                param_1[0xe] = 0;
                local_54 = (local_54 | bVar9) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar9 = param_1[0xf];
  param_1[0xf] = 1;
  local_54 = bVar9 | local_54;
  if (local_54 != param_4) {
    uVar8 = 0xffffffff;
    goto LAB_081b6843;
  }
  if (0xf < param_4) {
    puVar13 = param_3;
    puVar15 = param_2;
    do {
      (*pcVar3)(param_1,&local_30,uVar8);
      bVar2 = param_1[0xf];
      param_1[0xf] = bVar2 + 1;
      if ((((((byte)(bVar2 + 1) == 0) &&
            (bVar2 = param_1[0xe], param_1[0xe] = bVar2 + 1, (byte)(bVar2 + 1) == 0)) &&
           (bVar2 = param_1[0xd], param_1[0xd] = bVar2 + 1, (byte)(bVar2 + 1) == 0)) &&
          ((bVar2 = param_1[0xc], param_1[0xc] = bVar2 + 1, (byte)(bVar2 + 1) == 0 &&
           (bVar2 = param_1[0xb], param_1[0xb] = bVar2 + 1, (byte)(bVar2 + 1) == 0)))) &&
         ((bVar2 = param_1[10], param_1[10] = bVar2 + 1, (byte)(bVar2 + 1) == 0 &&
          (bVar2 = param_1[9], param_1[9] = bVar2 + 1, (byte)(bVar2 + 1) == 0)))) {
        param_1[8] = param_1[8] + 1;
      }
      uVar11 = *puVar15;
      uVar12 = puVar15[1];
      param_4 = param_4 - 0x10;
      *puVar13 = local_30 ^ uVar11;
      puVar13[1] = local_2c ^ uVar12;
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_30 ^ uVar11;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_2c ^ uVar12;
      uVar11 = puVar15[2];
      uVar12 = puVar15[3];
      puVar13[2] = local_28 ^ uVar11;
      puVar13[3] = local_24 ^ uVar12;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_28 ^ uVar11;
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_24 ^ uVar12;
      (*pcVar3)(param_1 + 0x10,param_1 + 0x10,uVar8);
      puVar13 = puVar13 + 4;
      puVar15 = puVar15 + 4;
    } while (0xf < param_4);
    iVar10 = (local_54 - 0x10 & 0xfffffff0) + 0x10;
    local_4c = (uint *)((int)param_2 + iVar10);
    local_50 = (uint *)((int)param_3 + iVar10);
    local_54 = bVar9 & 0xf;
  }
  local_5c = &local_30;
  if (local_54 != 0) {
    puVar13 = (uint *)(param_1 + 0x10);
    (*pcVar3)(param_1,local_5c,uVar8);
    if ((((puVar13 < local_4c + 1 && local_4c < param_1 + 0x14 ||
          puVar13 < local_50 + 1 && local_50 < param_1 + 0x14) || local_54 < 5) ||
         local_50 < local_4c + 1 && local_4c < local_50 + 1) ||
       ((((uint)local_50 | (uint)local_4c) & 3) != 0)) {
      bVar9 = *(byte *)local_4c;
      *(byte *)local_50 = bVar9 ^ (byte)local_30;
      param_1[0x10] = param_1[0x10] ^ bVar9 ^ (byte)local_30;
      if (local_54 != 1) {
        local_30._1_1_ = local_30._1_1_ ^ *(byte *)((int)local_4c + 1);
        *(byte *)((int)local_50 + 1) = local_30._1_1_;
        param_1[0x11] = param_1[0x11] ^ local_30._1_1_;
        if (local_54 != 2) {
          local_30._2_1_ = local_30._2_1_ ^ *(byte *)((int)local_4c + 2);
          *(byte *)((int)local_50 + 2) = local_30._2_1_;
          param_1[0x12] = param_1[0x12] ^ local_30._2_1_;
          if (local_54 != 3) {
            local_30._3_1_ = local_30._3_1_ ^ *(byte *)((int)local_4c + 3);
            *(byte *)((int)local_50 + 3) = local_30._3_1_;
            param_1[0x13] = param_1[0x13] ^ local_30._3_1_;
            if (4 < local_54) {
              bVar9 = *(byte *)(local_4c + 1);
              *(byte *)(local_50 + 1) = (byte)local_2c ^ bVar9;
              param_1[0x14] = param_1[0x14] ^ (byte)local_2c ^ bVar9;
              if (5 < local_54) {
                local_2c._1_1_ = local_2c._1_1_ ^ *(byte *)((int)local_4c + 5);
                *(byte *)((int)local_50 + 5) = local_2c._1_1_;
                param_1[0x15] = param_1[0x15] ^ local_2c._1_1_;
                if (local_54 != 6) {
                  local_2c._2_1_ = local_2c._2_1_ ^ *(byte *)((int)local_4c + 6);
                  *(byte *)((int)local_50 + 6) = local_2c._2_1_;
                  param_1[0x16] = param_1[0x16] ^ local_2c._2_1_;
                  if (local_54 != 7) {
                    local_2c._3_1_ = local_2c._3_1_ ^ *(byte *)((int)local_4c + 7);
                    *(byte *)((int)local_50 + 7) = local_2c._3_1_;
                    param_1[0x17] = param_1[0x17] ^ local_2c._3_1_;
                    if (local_54 != 8) {
                      bVar9 = *(byte *)(local_4c + 2);
                      *(byte *)(local_50 + 2) = (byte)local_28 ^ bVar9;
                      param_1[0x18] = param_1[0x18] ^ (byte)local_28 ^ bVar9;
                      if (local_54 != 9) {
                        local_28._1_1_ = local_28._1_1_ ^ *(byte *)((int)local_4c + 9);
                        *(byte *)((int)local_50 + 9) = local_28._1_1_;
                        param_1[0x19] = param_1[0x19] ^ local_28._1_1_;
                        if (local_54 != 10) {
                          local_28._2_1_ = local_28._2_1_ ^ *(byte *)((int)local_4c + 10);
                          *(byte *)((int)local_50 + 10) = local_28._2_1_;
                          param_1[0x1a] = param_1[0x1a] ^ local_28._2_1_;
                          if (local_54 != 0xb) {
                            local_28._3_1_ = local_28._3_1_ ^ *(byte *)((int)local_4c + 0xb);
                            *(byte *)((int)local_50 + 0xb) = local_28._3_1_;
                            param_1[0x1b] = param_1[0x1b] ^ local_28._3_1_;
                            if (local_54 != 0xc) {
                              bVar9 = *(byte *)(local_4c + 3);
                              *(byte *)(local_50 + 3) = (byte)local_24 ^ bVar9;
                              param_1[0x1c] = param_1[0x1c] ^ (byte)local_24 ^ bVar9;
                              if (local_54 != 0xd) {
                                local_24._1_1_ = local_24._1_1_ ^ *(byte *)((int)local_4c + 0xd);
                                *(byte *)((int)local_50 + 0xd) = local_24._1_1_;
                                param_1[0x1d] = param_1[0x1d] ^ local_24._1_1_;
                                if (local_54 == 0xf) {
                                  local_24._2_1_ = local_24._2_1_ ^ *(byte *)((int)local_4c + 0xe);
                                  *(byte *)((int)local_50 + 0xe) = local_24._2_1_;
                                  param_1[0x1e] = param_1[0x1e] ^ local_24._2_1_;
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
      iVar10 = (local_54 - 4 >> 2) + 1;
      uVar11 = iVar10 * 4;
      if (local_54 - 1 < 3) {
        uVar11 = 0;
      }
      else {
        uVar12 = *local_4c;
        *local_50 = uVar12 ^ local_30;
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ uVar12 ^ local_30;
        if (iVar10 != 1) {
          uVar12 = local_4c[1];
          local_50[1] = local_2c ^ uVar12;
          *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_2c ^ uVar12;
          if (iVar10 != 2) {
            uVar12 = local_4c[2];
            local_50[2] = local_28 ^ uVar12;
            *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_28 ^ uVar12;
            if (iVar10 != 3) {
              uVar12 = local_4c[3];
              local_50[3] = local_24 ^ uVar12;
              *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_24 ^ uVar12;
            }
          }
        }
        if (local_54 == uVar11) goto LAB_081b69f9;
      }
      bVar9 = *(byte *)((int)local_4c + uVar11) ^ *(byte *)((int)&local_30 + uVar11);
      *(byte *)((int)local_50 + uVar11) = bVar9;
      param_1[uVar11 + 0x10] = param_1[uVar11 + 0x10] ^ bVar9;
      if (uVar11 + 1 < local_54) {
        bVar9 = *(byte *)((int)local_4c + uVar11 + 1) ^ *(byte *)((int)&local_30 + uVar11 + 1);
        *(byte *)((int)local_50 + uVar11 + 1) = bVar9;
        param_1[uVar11 + 0x11] = param_1[uVar11 + 0x11] ^ bVar9;
        if (uVar11 + 2 < local_54) {
          bVar9 = *(byte *)((int)local_4c + uVar11 + 2) ^ *(byte *)((int)&local_30 + uVar11 + 2);
          *(byte *)((int)local_50 + uVar11 + 2) = bVar9;
          param_1[uVar11 + 0x12] = param_1[uVar11 + 0x12] ^ bVar9;
        }
      }
    }
LAB_081b69f9:
    (*pcVar3)(puVar13,puVar13,uVar8);
  }
  uVar11 = 0x10 - iVar6;
  puVar7 = (undefined4 *)(param_1 + (0xf - uVar14));
  if (uVar11 < 4) {
    if ((uVar11 != 0) && (*(undefined *)puVar7 = 0, (uVar11 & 2) != 0)) {
      *(undefined2 *)(param_1 + uVar11 + (0xd - uVar14)) = 0;
    }
  }
  else {
    *puVar7 = 0;
    *(undefined4 *)(param_1 + uVar11 + (0xb - uVar14)) = 0;
    uVar11 = (uint)((int)puVar7 + (uVar11 - ((uint)(param_1 + (0x13 - uVar14)) & 0xfffffffc))) &
             0xfffffffc;
    if (3 < uVar11) {
      uVar12 = 0;
      do {
        *(undefined4 *)(((uint)(param_1 + (0x13 - uVar14)) & 0xfffffffc) + uVar12) = 0;
        uVar12 = uVar12 + 4;
      } while (uVar12 < uVar11);
    }
  }
  (*pcVar3)(param_1,local_5c,uVar8);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_30;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_2c;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_28;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_24;
  *param_1 = bVar1;
  uVar8 = 0;
LAB_081b6843:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}

