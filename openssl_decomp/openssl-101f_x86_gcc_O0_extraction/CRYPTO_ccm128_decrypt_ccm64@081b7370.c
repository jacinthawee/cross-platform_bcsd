
/* WARNING: Could not reconcile some variable overlaps */

undefined4
CRYPTO_ccm128_decrypt_ccm64(byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  code *pcVar3;
  uint uVar4;
  ushort uVar5;
  uint3 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  byte bVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int in_GS_OFFSET;
  uint local_54;
  undefined4 *local_4c;
  uint *local_48;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  pcVar3 = *(code **)(param_1 + 0x28);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar1 = *param_1;
  uVar10 = *(undefined4 *)(param_1 + 0x2c);
  if ((bVar1 & 0x40) == 0) {
    (*pcVar3)(param_1,param_1 + 0x10,uVar10);
  }
  uVar14 = (uint)(bVar1 & 7);
  *param_1 = bVar1 & 7;
  iVar7 = 0xf - uVar14;
  if (iVar7 == 0xf) {
    local_54 = 0;
  }
  else {
    bVar11 = param_1[iVar7];
    param_1[iVar7] = 0;
    iVar12 = 0x10 - uVar14;
    local_54 = (uint)bVar11 << 8;
    if (iVar12 != 0xf) {
      bVar2 = param_1[iVar12];
      param_1[iVar12] = 0;
      iVar12 = 0x11 - uVar14;
      uVar5 = CONCAT11(bVar11,bVar2);
      local_54 = (uint)uVar5 << 8;
      if (iVar12 != 0xf) {
        bVar11 = param_1[iVar12];
        param_1[iVar12] = 0;
        iVar12 = 0x12 - uVar14;
        uVar6 = CONCAT21(uVar5,bVar11);
        local_54 = (uint)uVar6 << 8;
        if (iVar12 != 0xf) {
          bVar11 = param_1[iVar12];
          param_1[iVar12] = 0;
          iVar12 = 0x13 - uVar14;
          local_54 = CONCAT31(uVar6,bVar11) << 8;
          if (iVar12 != 0xf) {
            bVar11 = param_1[iVar12];
            param_1[iVar12] = 0;
            iVar12 = 0x14 - uVar14;
            local_54 = (local_54 | bVar11) << 8;
            if (iVar12 != 0xf) {
              bVar11 = param_1[iVar12];
              param_1[iVar12] = 0;
              local_54 = (local_54 | bVar11) << 8;
              if (uVar14 != 6) {
                bVar11 = param_1[0xe];
                param_1[0xe] = 0;
                local_54 = (local_54 | bVar11) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar11 = param_1[0xf];
  param_1[0xf] = 1;
  local_54 = bVar11 | local_54;
  if (local_54 != param_4) {
    uVar10 = 0xffffffff;
    goto LAB_081b7509;
  }
  uVar8 = param_4 >> 4;
  if (uVar8 == 0) {
    if (param_4 != 0) {
LAB_081b766b:
      local_48 = (uint *)(param_1 + 0x10);
      (*pcVar3)(param_1,&local_30,uVar10);
      if ((((param_3 < param_1 + 0x14 && local_48 < param_3 + 1 ||
            param_2 < param_1 + 0x14 && local_48 < param_2 + 1) || local_54 < 5) ||
           param_2 < param_3 + 1 && param_3 < param_2 + 1) ||
         ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
        bVar11 = *(byte *)param_2;
        *(byte *)param_3 = (byte)local_30 ^ bVar11;
        param_1[0x10] = param_1[0x10] ^ (byte)local_30 ^ bVar11;
        if (local_54 != 1) {
          local_30._1_1_ = local_30._1_1_ ^ *(byte *)((int)param_2 + 1);
          *(byte *)((int)param_3 + 1) = local_30._1_1_;
          param_1[0x11] = param_1[0x11] ^ local_30._1_1_;
          if (local_54 != 2) {
            local_30._2_1_ = local_30._2_1_ ^ *(byte *)((int)param_2 + 2);
            *(byte *)((int)param_3 + 2) = local_30._2_1_;
            param_1[0x12] = param_1[0x12] ^ local_30._2_1_;
            if (local_54 != 3) {
              local_30._3_1_ = local_30._3_1_ ^ *(byte *)((int)param_2 + 3);
              *(byte *)((int)param_3 + 3) = local_30._3_1_;
              param_1[0x13] = param_1[0x13] ^ local_30._3_1_;
              if (4 < local_54) {
                bVar11 = *(byte *)(param_2 + 1);
                *(byte *)(param_3 + 1) = (byte)local_2c ^ bVar11;
                param_1[0x14] = param_1[0x14] ^ (byte)local_2c ^ bVar11;
                if (5 < local_54) {
                  local_2c._1_1_ = local_2c._1_1_ ^ *(byte *)((int)param_2 + 5);
                  *(byte *)((int)param_3 + 5) = local_2c._1_1_;
                  param_1[0x15] = param_1[0x15] ^ local_2c._1_1_;
                  if (local_54 != 6) {
                    local_2c._2_1_ = local_2c._2_1_ ^ *(byte *)((int)param_2 + 6);
                    *(byte *)((int)param_3 + 6) = local_2c._2_1_;
                    param_1[0x16] = param_1[0x16] ^ local_2c._2_1_;
                    if (local_54 != 7) {
                      local_2c._3_1_ = local_2c._3_1_ ^ *(byte *)((int)param_2 + 7);
                      *(byte *)((int)param_3 + 7) = local_2c._3_1_;
                      param_1[0x17] = param_1[0x17] ^ local_2c._3_1_;
                      if (local_54 != 8) {
                        bVar11 = *(byte *)(param_2 + 2);
                        *(byte *)(param_3 + 2) = (byte)local_28 ^ bVar11;
                        param_1[0x18] = param_1[0x18] ^ (byte)local_28 ^ bVar11;
                        if (local_54 != 9) {
                          local_28._1_1_ = local_28._1_1_ ^ *(byte *)((int)param_2 + 9);
                          *(byte *)((int)param_3 + 9) = local_28._1_1_;
                          param_1[0x19] = param_1[0x19] ^ local_28._1_1_;
                          if (local_54 != 10) {
                            local_28._2_1_ = local_28._2_1_ ^ *(byte *)((int)param_2 + 10);
                            *(byte *)((int)param_3 + 10) = local_28._2_1_;
                            param_1[0x1a] = param_1[0x1a] ^ local_28._2_1_;
                            if (local_54 != 0xb) {
                              local_28._3_1_ = local_28._3_1_ ^ *(byte *)((int)param_2 + 0xb);
                              *(byte *)((int)param_3 + 0xb) = local_28._3_1_;
                              param_1[0x1b] = param_1[0x1b] ^ local_28._3_1_;
                              if (local_54 != 0xc) {
                                bVar11 = *(byte *)(param_2 + 3);
                                *(byte *)(param_3 + 3) = (byte)local_24 ^ bVar11;
                                param_1[0x1c] = param_1[0x1c] ^ (byte)local_24 ^ bVar11;
                                if (local_54 != 0xd) {
                                  local_24._1_1_ = local_24._1_1_ ^ *(byte *)((int)param_2 + 0xd);
                                  *(byte *)((int)param_3 + 0xd) = local_24._1_1_;
                                  param_1[0x1d] = param_1[0x1d] ^ local_24._1_1_;
                                  if (local_54 != 0xe) {
                                    local_24._2_1_ = local_24._2_1_ ^ *(byte *)((int)param_2 + 0xe);
                                    *(byte *)((int)param_3 + 0xe) = local_24._2_1_;
                                    param_1[0x1e] = param_1[0x1e] ^ local_24._2_1_;
                                    if (local_54 != 0xf) {
                                      local_24._3_1_ =
                                           local_24._3_1_ ^ *(byte *)((int)param_2 + 0xf);
                                      *(byte *)((int)param_3 + 0xf) = local_24._3_1_;
                                      param_1[0x1f] = param_1[0x1f] ^ local_24._3_1_;
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
      }
      else {
        uVar8 = 1;
        if (local_54 != 0) {
          uVar8 = local_54;
        }
        iVar12 = (uVar8 - 4 >> 2) + 1;
        uVar13 = iVar12 * 4;
        if (local_54 < 4) {
          uVar13 = 0;
        }
        else {
          uVar4 = *param_2;
          *param_3 = local_30 ^ uVar4;
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_30 ^ uVar4;
          if (iVar12 != 1) {
            uVar4 = param_2[1];
            param_3[1] = uVar4 ^ local_2c;
            *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ uVar4 ^ local_2c;
            if (iVar12 != 2) {
              uVar4 = param_2[2];
              param_3[2] = uVar4 ^ local_28;
              *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ uVar4 ^ local_28;
              if (iVar12 != 3) {
                uVar4 = param_2[3];
                param_3[3] = uVar4 ^ local_24;
                *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ uVar4 ^ local_24;
              }
            }
          }
          if (uVar8 == uVar13) goto LAB_081b779b;
        }
        bVar11 = *(byte *)((int)param_2 + uVar13) ^ *(byte *)((int)&local_30 + uVar13);
        *(byte *)((int)param_3 + uVar13) = bVar11;
        param_1[uVar13 + 0x10] = param_1[uVar13 + 0x10] ^ bVar11;
        if (uVar13 + 1 < local_54) {
          bVar11 = *(byte *)((int)param_2 + uVar13 + 1) ^ *(byte *)((int)&local_30 + uVar13 + 1);
          *(byte *)((int)param_3 + uVar13 + 1) = bVar11;
          param_1[uVar13 + 0x11] = param_1[uVar13 + 0x11] ^ bVar11;
          if (uVar13 + 2 < local_54) {
            bVar11 = *(byte *)((int)param_2 + uVar13 + 2) ^ *(byte *)((int)&local_30 + uVar13 + 2);
            *(byte *)((int)param_3 + uVar13 + 2) = bVar11;
            param_1[uVar13 + 0x12] = param_1[uVar13 + 0x12] ^ bVar11;
          }
        }
      }
LAB_081b779b:
      (*pcVar3)(local_48,local_48,uVar10);
    }
  }
  else {
    (*param_5)(param_2,param_3,uVar8,uVar10,param_1,param_1 + 0x10);
    param_2 = (uint *)((int)param_2 + (param_4 & 0xfffffff0));
    param_3 = (uint *)((int)param_3 + (param_4 & 0xfffffff0));
    local_54 = param_4 + uVar8 * -0x10;
    if (local_54 != 0) {
      uVar8 = (uVar8 & 0xff) + (uint)param_1[0xf];
      param_1[0xf] = (byte)uVar8;
      uVar8 = uVar8 >> 8;
      if ((uVar8 | param_4 >> 0xc) != 0) {
        uVar8 = uVar8 + (param_4 >> 0xc & 0xff) + (uint)param_1[0xe];
        param_1[0xe] = (byte)uVar8;
        uVar8 = uVar8 >> 8;
        if ((uVar8 | param_4 >> 0x14) != 0) {
          uVar8 = uVar8 + (param_4 >> 0x14 & 0xff) + (uint)param_1[0xd];
          param_1[0xd] = (byte)uVar8;
          uVar8 = uVar8 >> 8;
          if ((uVar8 | param_4 >> 0x1c) != 0) {
            uVar8 = uVar8 + (param_4 >> 0x1c) + (uint)param_1[0xc];
            param_1[0xc] = (byte)uVar8;
            uVar8 = uVar8 >> 8;
            if (uVar8 != 0) {
              uVar8 = uVar8 + param_1[0xb];
              param_1[0xb] = (byte)uVar8;
              uVar8 = uVar8 >> 8;
              if (uVar8 != 0) {
                uVar8 = param_1[10] + uVar8;
                param_1[10] = (byte)uVar8;
                uVar8 = uVar8 >> 8;
                if (uVar8 != 0) {
                  uVar8 = uVar8 + param_1[9];
                  param_1[9] = (byte)uVar8;
                  if (uVar8 >> 8 != 0) {
                    param_1[8] = param_1[8] + (char)(uVar8 >> 8);
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_081b766b;
    }
  }
  local_4c = &local_30;
  uVar8 = 0x10 - iVar7;
  puVar9 = (undefined4 *)(param_1 + (0xf - uVar14));
  if (uVar8 < 4) {
    if ((uVar8 != 0) && (*(undefined *)puVar9 = 0, (uVar8 & 2) != 0)) {
      *(undefined2 *)(param_1 + uVar8 + (0xd - uVar14)) = 0;
    }
  }
  else {
    *puVar9 = 0;
    *(undefined4 *)(param_1 + uVar8 + (0xb - uVar14)) = 0;
    uVar8 = (uint)((int)puVar9 + (uVar8 - ((uint)(param_1 + (0x13 - uVar14)) & 0xfffffffc))) &
            0xfffffffc;
    if (3 < uVar8) {
      uVar13 = 0;
      do {
        *(undefined4 *)(((uint)(param_1 + (0x13 - uVar14)) & 0xfffffffc) + uVar13) = 0;
        uVar13 = uVar13 + 4;
      } while (uVar13 < uVar8);
    }
  }
  (*pcVar3)(param_1,local_4c,uVar10);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_30;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_2c;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_28;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_24;
  *param_1 = bVar1;
  uVar10 = 0;
LAB_081b7509:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}

