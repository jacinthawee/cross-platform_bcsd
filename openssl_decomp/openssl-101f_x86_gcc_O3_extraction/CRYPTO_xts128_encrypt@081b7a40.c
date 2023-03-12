
/* WARNING: Could not reconcile some variable overlaps */

undefined4
CRYPTO_xts128_encrypt
          (undefined4 *param_1,uint *param_2,uint *param_3,uint *param_4,uint param_5,int param_6)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int in_GS_OFFSET;
  uint local_84;
  uint local_7c;
  uint local_74;
  undefined4 *local_5c;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_5 < 0x10) {
    uVar4 = 0xffffffff;
    goto LAB_081b7c25;
  }
  local_40 = *param_2;
  local_3c = param_2[1];
  local_38 = param_2[2];
  local_34 = param_2[3];
  (*(code *)param_1[3])(&local_40,&local_40,param_1[1]);
  if (((param_6 != 0) || ((param_5 & 0xf) == 0)) || (param_5 = param_5 - 0x10, 0xf < param_5)) {
    do {
      puVar12 = param_4;
      puVar11 = param_3;
      param_3 = puVar11 + 4;
      param_4 = puVar12 + 4;
      local_30 = *puVar11 ^ local_40;
      local_2c = puVar11[1] ^ local_3c;
      local_28 = puVar11[2] ^ local_38;
      local_24 = puVar11[3] ^ local_34;
      (*(code *)param_1[2])(&local_30,&local_30,*param_1);
      uVar9 = local_2c ^ local_3c;
      uVar3 = local_30 ^ local_40;
      puVar12[1] = uVar9;
      local_2c = uVar9;
      local_30 = uVar3;
      uVar13 = local_28 ^ local_38;
      local_28 = uVar13;
      uVar10 = local_24 ^ local_34;
      *puVar12 = uVar3;
      puVar12[2] = uVar13;
      local_24 = uVar10;
      puVar12[3] = uVar10;
      param_5 = param_5 - 0x10;
      if (param_5 == 0) {
        uVar4 = 0;
        goto LAB_081b7c25;
      }
      uVar7 = local_3c << 1 | local_40 >> 0x1f;
      local_40 = (int)local_34 >> 0x1f & 0x87U ^ local_40 * 2;
      local_34 = local_34 << 1 | local_38 >> 0x1f;
      local_38 = local_3c >> 0x1f | local_38 * 2;
      local_3c = uVar7;
    } while (0xf < param_5);
    if (param_6 != 0) {
      if ((param_4 < puVar11 + 5 && param_3 < puVar12 + 5 || param_5 < 6) ||
         ((((uint)param_4 | (uint)param_3) & 3) != 0)) {
        bVar1 = *(byte *)param_3;
        local_30._0_1_ = (byte)uVar3;
        *(byte *)param_4 = (byte)local_30;
        local_30 = uVar3 & 0xffffff00 | (uint)bVar1;
        if (param_5 != 1) {
          bVar2 = *(byte *)((int)puVar11 + 0x11);
          local_30._1_1_ = (byte)((uVar3 & 0xffffff00) >> 8);
          *(byte *)((int)puVar12 + 0x11) = local_30._1_1_;
          local_30._0_2_ = CONCAT11(bVar2,bVar1);
          local_30 = uVar3 & 0xffff0000 | (uint)(ushort)local_30;
          if (param_5 != 2) {
            bVar1 = *(byte *)((int)puVar11 + 0x12);
            local_30._2_1_ = (byte)((uVar3 & 0xffff0000) >> 0x10);
            *(byte *)((int)puVar12 + 0x12) = local_30._2_1_;
            local_30._0_3_ = CONCAT12(bVar1,(ushort)local_30);
            local_30 = uVar3 & 0xff000000 | (uint)(uint3)local_30;
            if (param_5 != 3) {
              bVar1 = *(byte *)((int)puVar11 + 0x13);
              local_30._3_1_ = (byte)((uVar3 & 0xff000000) >> 0x18);
              *(byte *)((int)puVar12 + 0x13) = local_30._3_1_;
              local_30 = CONCAT13(bVar1,(uint3)local_30);
              if (param_5 != 4) {
                bVar1 = *(byte *)(puVar11 + 5);
                local_2c._0_1_ = (byte)uVar9;
                *(byte *)(puVar12 + 5) = (byte)local_2c;
                local_2c = uVar9 & 0xffffff00 | (uint)bVar1;
                if (5 < param_5) {
                  bVar2 = *(byte *)((int)puVar11 + 0x15);
                  local_2c._1_1_ = (byte)((uVar9 & 0xffffff00) >> 8);
                  *(byte *)((int)puVar12 + 0x15) = local_2c._1_1_;
                  local_2c._0_2_ = CONCAT11(bVar2,bVar1);
                  local_2c = uVar9 & 0xffff0000 | (uint)(ushort)local_2c;
                  if (6 < param_5) {
                    bVar1 = *(byte *)((int)puVar11 + 0x16);
                    local_2c._2_1_ = (byte)((uVar9 & 0xffff0000) >> 0x10);
                    *(byte *)((int)puVar12 + 0x16) = local_2c._2_1_;
                    local_2c._0_3_ = CONCAT12(bVar1,(ushort)local_2c);
                    local_2c = uVar9 & 0xff000000 | (uint)(uint3)local_2c;
                    if (param_5 != 7) {
                      bVar1 = *(byte *)((int)puVar11 + 0x17);
                      local_2c._3_1_ = (byte)((uVar9 & 0xff000000) >> 0x18);
                      *(byte *)((int)puVar12 + 0x17) = local_2c._3_1_;
                      local_2c = CONCAT13(bVar1,(uint3)local_2c);
                      if (param_5 != 8) {
                        bVar1 = *(byte *)(puVar11 + 6);
                        local_28._0_1_ = (byte)uVar13;
                        *(byte *)(puVar12 + 6) = (byte)local_28;
                        local_28 = uVar13 & 0xffffff00 | (uint)bVar1;
                        if (param_5 != 9) {
                          bVar2 = *(byte *)((int)puVar11 + 0x19);
                          local_28._1_1_ = (byte)((uVar13 & 0xffffff00) >> 8);
                          *(byte *)((int)puVar12 + 0x19) = local_28._1_1_;
                          local_28._0_2_ = CONCAT11(bVar2,bVar1);
                          local_28 = uVar13 & 0xffff0000 | (uint)(ushort)local_28;
                          if (param_5 != 10) {
                            bVar1 = *(byte *)((int)puVar11 + 0x1a);
                            local_28._2_1_ = (byte)((uVar13 & 0xffff0000) >> 0x10);
                            *(byte *)((int)puVar12 + 0x1a) = local_28._2_1_;
                            local_28._0_3_ = CONCAT12(bVar1,(ushort)local_28);
                            local_28 = uVar13 & 0xff000000 | (uint)(uint3)local_28;
                            if (param_5 != 0xb) {
                              bVar1 = *(byte *)((int)puVar11 + 0x1b);
                              local_28._3_1_ = (byte)((uVar13 & 0xff000000) >> 0x18);
                              *(byte *)((int)puVar12 + 0x1b) = local_28._3_1_;
                              local_28 = CONCAT13(bVar1,(uint3)local_28);
                              if (param_5 != 0xc) {
                                bVar1 = *(byte *)(puVar11 + 7);
                                local_24._0_1_ = (byte)uVar10;
                                *(byte *)(puVar12 + 7) = (byte)local_24;
                                local_24 = uVar10 & 0xffffff00 | (uint)bVar1;
                                if (param_5 != 0xd) {
                                  bVar2 = *(byte *)((int)puVar11 + 0x1d);
                                  local_24._1_1_ = (byte)((uVar10 & 0xffffff00) >> 8);
                                  *(byte *)((int)puVar12 + 0x1d) = local_24._1_1_;
                                  local_24._0_2_ = CONCAT11(bVar2,bVar1);
                                  local_24 = uVar10 & 0xffff0000 | (uint)(ushort)local_24;
                                  if (param_5 == 0xf) {
                                    local_24._2_1_ = (byte)((uVar10 & 0xffff0000) >> 0x10);
                                    local_24._0_3_ =
                                         CONCAT12(*(byte *)((int)puVar11 + 0x1e),(ushort)local_24);
                                    local_24 = uVar10 & 0xff000000 | (uint)(uint3)local_24;
                                    *(byte *)((int)puVar12 + 0x1e) = local_24._2_1_;
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
        uVar5 = 1;
        if (param_5 != 0) {
          uVar5 = param_5;
        }
        iVar6 = (uVar5 - 4 >> 2) + 1;
        iVar8 = iVar6 * 4;
        if (param_5 < 4) {
          iVar8 = 0;
        }
        else {
          local_30 = *param_3;
          *param_4 = uVar3;
          if (iVar6 != 1) {
            local_2c = puVar11[5];
            puVar12[5] = uVar9;
            if (iVar6 != 2) {
              local_28 = puVar11[6];
              puVar12[6] = uVar13;
              if (iVar6 != 3) {
                local_24 = puVar11[7];
                puVar12[7] = uVar10;
              }
            }
          }
          if (iVar8 - uVar5 == 0) goto LAB_081b7fe3;
        }
        bVar1 = *(byte *)((int)&local_30 + iVar8);
        *(byte *)((int)&local_30 + iVar8) = *(byte *)((int)param_3 + iVar8);
        *(byte *)((int)param_4 + iVar8) = bVar1;
        if (iVar8 + 1U < param_5) {
          bVar1 = *(byte *)((int)puVar11 + iVar8 + 0x11);
          *(byte *)((int)puVar12 + iVar8 + 0x11) = *(byte *)((int)&local_30 + iVar8 + 1);
          *(byte *)((int)&local_30 + iVar8 + 1) = bVar1;
          if (iVar8 + 2U < param_5) {
            bVar1 = *(byte *)((int)&local_30 + iVar8 + 2);
            *(byte *)((int)&local_30 + iVar8 + 2) = *(byte *)((int)puVar11 + iVar8 + 0x12);
            *(byte *)((int)puVar12 + iVar8 + 0x12) = bVar1;
          }
        }
      }
LAB_081b7fe3:
      local_30 = local_30 ^ local_40;
      local_2c = local_2c ^ uVar7;
      local_28 = local_28 ^ local_38;
      local_24 = local_24 ^ local_34;
      (*(code *)param_1[2])(&local_30,&local_30,*param_1);
      local_30 = local_30 ^ local_40;
      local_2c = local_2c ^ local_3c;
      local_28 = local_28 ^ local_38;
      local_24 = local_24 ^ local_34;
      *puVar12 = local_30;
      puVar12[1] = local_2c;
      puVar12[2] = local_28;
      puVar12[3] = local_24;
      uVar4 = 0;
      goto LAB_081b7c25;
    }
  }
  local_5c = &local_30;
  local_7c = local_3c << 1 | local_40 >> 0x1f;
  local_84 = (int)local_34 >> 0x1f & 0x87U ^ local_40 * 2;
  local_30 = local_84 ^ *param_3;
  uVar3 = local_34 << 1 | local_38 >> 0x1f;
  local_74 = local_3c >> 0x1f | local_38 * 2;
  local_2c = local_7c ^ param_3[1];
  local_28 = param_3[2] ^ local_74;
  local_24 = param_3[3] ^ uVar3;
  (*(code *)param_1[2])(local_5c,local_5c,*param_1);
  local_74 = local_74 ^ local_28;
  local_84 = local_84 ^ local_30;
  local_7c = local_7c ^ local_2c;
  local_30 = local_84;
  local_2c = local_7c;
  uVar3 = local_24 ^ uVar3;
  local_28 = local_74;
  local_24 = uVar3;
  if (param_5 != 0) {
    if ((param_3 + 4 < param_4 + 5 && param_4 + 4 < param_3 + 5 || param_5 < 6) ||
       ((((uint)(param_3 + 4) | (uint)(param_4 + 4)) & 3) != 0)) {
      bVar1 = *(byte *)(param_3 + 4);
      local_30._0_1_ = (byte)local_84;
      *(byte *)(param_4 + 4) = (byte)local_30;
      local_30 = local_84 & 0xffffff00 | (uint)bVar1;
      if (param_5 != 1) {
        bVar2 = *(byte *)((int)param_3 + 0x11);
        local_30._1_1_ = (byte)((local_84 & 0xffffff00) >> 8);
        *(byte *)((int)param_4 + 0x11) = local_30._1_1_;
        local_30._0_2_ = CONCAT11(bVar2,bVar1);
        local_30 = local_84 & 0xffff0000 | (uint)(ushort)local_30;
        if (param_5 != 2) {
          bVar1 = *(byte *)((int)param_3 + 0x12);
          local_30._2_1_ = (byte)((local_84 & 0xffff0000) >> 0x10);
          *(byte *)((int)param_4 + 0x12) = local_30._2_1_;
          local_30._0_3_ = CONCAT12(bVar1,(ushort)local_30);
          local_30 = local_84 & 0xff000000 | (uint)(uint3)local_30;
          if (param_5 != 3) {
            bVar1 = *(byte *)((int)param_3 + 0x13);
            local_30._3_1_ = (byte)((local_84 & 0xff000000) >> 0x18);
            *(byte *)((int)param_4 + 0x13) = local_30._3_1_;
            local_30 = CONCAT13(bVar1,(uint3)local_30);
            if (param_5 != 4) {
              bVar1 = *(byte *)(param_3 + 5);
              local_2c._0_1_ = (byte)local_7c;
              *(byte *)(param_4 + 5) = (byte)local_2c;
              local_2c = local_7c & 0xffffff00 | (uint)bVar1;
              if (5 < param_5) {
                bVar2 = *(byte *)((int)param_3 + 0x15);
                local_2c._1_1_ = (byte)((local_7c & 0xffffff00) >> 8);
                *(byte *)((int)param_4 + 0x15) = local_2c._1_1_;
                local_2c._0_2_ = CONCAT11(bVar2,bVar1);
                local_2c = local_7c & 0xffff0000 | (uint)(ushort)local_2c;
                if (6 < param_5) {
                  bVar1 = *(byte *)((int)param_3 + 0x16);
                  local_2c._2_1_ = (byte)((local_7c & 0xffff0000) >> 0x10);
                  *(byte *)((int)param_4 + 0x16) = local_2c._2_1_;
                  local_2c._0_3_ = CONCAT12(bVar1,(ushort)local_2c);
                  local_2c = local_7c & 0xff000000 | (uint)(uint3)local_2c;
                  if (param_5 != 7) {
                    bVar1 = *(byte *)((int)param_3 + 0x17);
                    local_2c._3_1_ = (byte)((local_7c & 0xff000000) >> 0x18);
                    *(byte *)((int)param_4 + 0x17) = local_2c._3_1_;
                    local_2c = CONCAT13(bVar1,(uint3)local_2c);
                    if (param_5 != 8) {
                      bVar1 = *(byte *)(param_3 + 6);
                      local_28._0_1_ = (byte)local_74;
                      *(byte *)(param_4 + 6) = (byte)local_28;
                      local_28 = local_74 & 0xffffff00 | (uint)bVar1;
                      if (param_5 != 9) {
                        bVar2 = *(byte *)((int)param_3 + 0x19);
                        local_28._1_1_ = (byte)((local_74 & 0xffffff00) >> 8);
                        *(byte *)((int)param_4 + 0x19) = local_28._1_1_;
                        local_28._0_2_ = CONCAT11(bVar2,bVar1);
                        local_28 = local_74 & 0xffff0000 | (uint)(ushort)local_28;
                        if (param_5 != 10) {
                          bVar1 = *(byte *)((int)param_3 + 0x1a);
                          local_28._2_1_ = (byte)((local_74 & 0xffff0000) >> 0x10);
                          *(byte *)((int)param_4 + 0x1a) = local_28._2_1_;
                          local_28._0_3_ = CONCAT12(bVar1,(ushort)local_28);
                          local_28 = local_74 & 0xff000000 | (uint)(uint3)local_28;
                          if (param_5 != 0xb) {
                            bVar1 = *(byte *)((int)param_3 + 0x1b);
                            local_28._3_1_ = (byte)((local_74 & 0xff000000) >> 0x18);
                            *(byte *)((int)param_4 + 0x1b) = local_28._3_1_;
                            local_28 = CONCAT13(bVar1,(uint3)local_28);
                            if (param_5 != 0xc) {
                              bVar1 = *(byte *)(param_3 + 7);
                              local_24._0_1_ = (byte)uVar3;
                              *(byte *)(param_4 + 7) = (byte)local_24;
                              local_24 = uVar3 & 0xffffff00 | (uint)bVar1;
                              if (param_5 != 0xd) {
                                bVar2 = *(byte *)((int)param_3 + 0x1d);
                                local_24._1_1_ = (byte)((uVar3 & 0xffffff00) >> 8);
                                *(byte *)((int)param_4 + 0x1d) = local_24._1_1_;
                                local_24._0_2_ = CONCAT11(bVar2,bVar1);
                                local_24 = uVar3 & 0xffff0000 | (uint)(ushort)local_24;
                                if (param_5 == 0xf) {
                                  local_24._2_1_ = (byte)((uVar3 & 0xffff0000) >> 0x10);
                                  local_24._0_3_ =
                                       CONCAT12(*(byte *)((int)param_3 + 0x1e),(ushort)local_24);
                                  local_24 = uVar3 & 0xff000000 | (uint)(uint3)local_24;
                                  *(byte *)((int)param_4 + 0x1e) = local_24._2_1_;
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
      iVar8 = (param_5 - 4 >> 2) + 1;
      uVar9 = iVar8 * 4;
      if (param_5 - 1 < 3) {
        uVar9 = 0;
      }
      else {
        local_30 = param_3[4];
        param_4[4] = local_84;
        if (iVar8 != 1) {
          local_2c = param_3[5];
          param_4[5] = local_7c;
          if (iVar8 != 2) {
            local_28 = param_3[6];
            param_4[6] = local_74;
            if (iVar8 != 3) {
              local_24 = param_3[7];
              param_4[7] = uVar3;
            }
          }
        }
        if (param_5 == uVar9) goto LAB_081b7e42;
      }
      bVar1 = *(byte *)((int)&local_30 + uVar9);
      *(byte *)((int)&local_30 + uVar9) = *(byte *)((int)param_3 + uVar9 + 0x10);
      *(byte *)((int)param_4 + uVar9 + 0x10) = bVar1;
      if (uVar9 + 1 < param_5) {
        bVar1 = *(byte *)((int)param_3 + uVar9 + 0x11);
        *(byte *)((int)param_4 + uVar9 + 0x11) = *(byte *)((int)&local_30 + uVar9 + 1);
        *(byte *)((int)&local_30 + uVar9 + 1) = bVar1;
        if (uVar9 + 2 < param_5) {
          bVar1 = *(byte *)((int)&local_30 + uVar9 + 2);
          *(byte *)((int)&local_30 + uVar9 + 2) = *(byte *)((int)param_3 + uVar9 + 0x12);
          *(byte *)((int)param_4 + uVar9 + 0x12) = bVar1;
        }
      }
    }
LAB_081b7e42:
    local_84 = local_30;
    local_7c = local_2c;
    local_74 = local_28;
  }
  local_30 = local_84 ^ local_40;
  local_28 = local_74 ^ local_38;
  local_24 = local_34 ^ local_24;
  local_2c = local_7c ^ local_3c;
  (*(code *)param_1[2])(local_5c,local_5c,*param_1);
  *param_4 = local_30 ^ local_40;
  param_4[1] = local_2c ^ local_3c;
  param_4[2] = local_28 ^ local_38;
  param_4[3] = local_24 ^ local_34;
  uVar4 = 0;
LAB_081b7c25:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

