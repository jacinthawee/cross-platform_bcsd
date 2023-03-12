
/* WARNING: Could not reconcile some variable overlaps */

void CRYPTO_xts128_encrypt
               (undefined4 *param_1,uint *param_2,uint *param_3,uint *param_4,uint param_5,
               int param_6)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  uint *local_5c;
  uint *local_58;
  uint local_50;
  uint uStack_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_2c;
  
  local_2c = __TMC_END__;
  if (param_5 < 0x10) {
    param_5 = 0xffffffff;
  }
  else {
    local_50 = *param_2;
    local_48 = param_2[2];
    uStack_4c = param_2[1];
    local_44 = param_2[3];
    (*(code *)param_1[3])(&local_50,&local_50,param_1[1]);
    if (((param_6 != 0) || ((param_5 & 0xf) == 0)) ||
       (param_5 = param_5 - 0x10, local_5c = param_3, local_58 = param_4, 0xf < param_5)) {
      puVar5 = param_3 + 4;
      do {
        puVar7 = param_4;
        local_5c = puVar5;
        local_58 = puVar7 + 4;
        local_40 = local_5c[-4] ^ local_50;
        local_3c = local_5c[-3] ^ uStack_4c;
        local_34 = local_5c[-1] ^ local_44;
        local_38 = local_5c[-2] ^ local_48;
        (*(code *)param_1[2])(&local_40,&local_40,*param_1);
        param_5 = param_5 - 0x10;
        uVar4 = local_40 ^ local_50;
        uVar6 = local_3c ^ uStack_4c;
        local_3c = uVar6;
        uVar9 = local_38 ^ local_48;
        uVar10 = local_34 ^ local_44;
        local_38 = uVar9;
        local_34 = uVar10;
        *puVar7 = uVar4;
        puVar7[1] = uVar6;
        puVar7[2] = uVar9;
        puVar7[3] = uVar10;
        local_40 = uVar4;
        if (param_5 == 0) goto LAB_001021c4;
        uVar1 = uStack_4c * 2 + (uint)CARRY4(local_50,local_50);
        local_50 = local_50 * 2 ^ (int)local_44 >> 0x1f & 0x87U;
        local_44 = local_44 * 2 + (uint)CARRY4(local_48,local_48);
        local_48 = uStack_4c >> 0x1f | local_48 * 2;
        puVar5 = local_5c + 4;
        param_4 = local_58;
        uStack_4c = uVar1;
      } while (0xf < param_5);
      if (param_6 != 0) {
        puVar5 = local_5c + 1;
        bVar14 = local_5c <= &local_3c;
        bVar11 = &local_3c == local_5c;
        if (bVar14 && !bVar11) {
          bVar14 = &local_40 <= puVar5;
          bVar11 = puVar5 == &local_40;
        }
        puVar8 = puVar7 + 5;
        bVar15 = local_58 <= &local_3c;
        bVar12 = &local_3c == local_58;
        if (bVar15 && !bVar12) {
          bVar15 = &local_40 <= puVar8;
          bVar12 = puVar8 == &local_40;
        }
        bVar16 = local_5c <= puVar8;
        bVar13 = puVar8 == local_5c;
        if (bVar16 && !bVar13) {
          bVar16 = local_58 <= puVar5;
          bVar13 = puVar5 == local_58;
        }
        if ((((uint)local_58 | (uint)local_5c) & 3) != 0 ||
            (bVar16 && !bVar13 || ((bVar15 && !bVar12 || bVar14 && !bVar11) || 6 >= param_5))) {
          bVar3 = *(byte *)local_5c;
          local_40._0_1_ = (byte)uVar4;
          *(byte *)local_58 = (byte)local_40;
          local_40 = uVar4 & 0xffffff00 | (uint)bVar3;
          if (1 < param_5) {
            bVar2 = *(byte *)((int)local_5c + 1);
            local_40._1_1_ = (byte)((uVar4 & 0xffffff00) >> 8);
            *(byte *)((int)puVar7 + 0x11) = local_40._1_1_;
            local_40._0_2_ = CONCAT11(bVar2,bVar3);
            local_40 = uVar4 & 0xffff0000 | (uint)(ushort)local_40;
            if (2 < param_5) {
              bVar3 = *(byte *)((int)local_5c + 2);
              local_40._2_1_ = (byte)((uVar4 & 0xffff0000) >> 0x10);
              *(byte *)((int)puVar7 + 0x12) = local_40._2_1_;
              local_40._0_3_ = CONCAT12(bVar3,(ushort)local_40);
              local_40 = uVar4 & 0xff000000 | (uint)(uint3)local_40;
              if (3 < param_5) {
                bVar3 = *(byte *)((int)local_5c + 3);
                local_40._3_1_ = (byte)((uVar4 & 0xff000000) >> 0x18);
                *(byte *)((int)puVar7 + 0x13) = local_40._3_1_;
                local_40 = CONCAT13(bVar3,(uint3)local_40);
                if (4 < param_5) {
                  bVar3 = *(byte *)(local_5c + 1);
                  local_3c._0_1_ = (byte)uVar6;
                  *(byte *)(puVar7 + 5) = (byte)local_3c;
                  local_3c = uVar6 & 0xffffff00 | (uint)bVar3;
                  if (5 < param_5) {
                    bVar2 = *(byte *)((int)local_5c + 5);
                    local_3c._1_1_ = (byte)((uVar6 & 0xffffff00) >> 8);
                    *(byte *)((int)puVar7 + 0x15) = local_3c._1_1_;
                    local_3c._0_2_ = CONCAT11(bVar2,bVar3);
                    local_3c = uVar6 & 0xffff0000 | (uint)(ushort)local_3c;
                    if (6 < param_5) {
                      bVar3 = *(byte *)((int)local_5c + 6);
                      local_3c._2_1_ = (byte)((uVar6 & 0xffff0000) >> 0x10);
                      *(byte *)((int)puVar7 + 0x16) = local_3c._2_1_;
                      local_3c._0_3_ = CONCAT12(bVar3,(ushort)local_3c);
                      local_3c = uVar6 & 0xff000000 | (uint)(uint3)local_3c;
                      if (7 < param_5) {
                        bVar3 = *(byte *)((int)local_5c + 7);
                        local_3c._3_1_ = (byte)((uVar6 & 0xff000000) >> 0x18);
                        *(byte *)((int)puVar7 + 0x17) = local_3c._3_1_;
                        local_3c = CONCAT13(bVar3,(uint3)local_3c);
                        if (8 < param_5) {
                          bVar3 = *(byte *)(local_5c + 2);
                          local_38._0_1_ = (byte)uVar9;
                          *(byte *)(puVar7 + 6) = (byte)local_38;
                          local_38 = uVar9 & 0xffffff00 | (uint)bVar3;
                          if (9 < param_5) {
                            bVar2 = *(byte *)((int)local_5c + 9);
                            local_38._1_1_ = (byte)((uVar9 & 0xffffff00) >> 8);
                            *(byte *)((int)puVar7 + 0x19) = local_38._1_1_;
                            local_38._0_2_ = CONCAT11(bVar2,bVar3);
                            local_38 = uVar9 & 0xffff0000 | (uint)(ushort)local_38;
                            if (10 < param_5) {
                              bVar3 = *(byte *)((int)local_5c + 10);
                              local_38._2_1_ = (byte)((uVar9 & 0xffff0000) >> 0x10);
                              *(byte *)((int)puVar7 + 0x1a) = local_38._2_1_;
                              local_38._0_3_ = CONCAT12(bVar3,(ushort)local_38);
                              local_38 = uVar9 & 0xff000000 | (uint)(uint3)local_38;
                              if (0xb < param_5) {
                                bVar3 = *(byte *)((int)local_5c + 0xb);
                                local_38._3_1_ = (byte)((uVar9 & 0xff000000) >> 0x18);
                                *(byte *)((int)puVar7 + 0x1b) = local_38._3_1_;
                                local_38 = CONCAT13(bVar3,(uint3)local_38);
                                if (0xc < param_5) {
                                  bVar3 = *(byte *)(local_5c + 3);
                                  local_34._0_1_ = (byte)uVar10;
                                  *(byte *)(puVar7 + 7) = (byte)local_34;
                                  local_34 = uVar10 & 0xffffff00 | (uint)bVar3;
                                  if (0xd < param_5) {
                                    bVar2 = *(byte *)((int)local_5c + 0xd);
                                    local_34._1_1_ = (byte)((uVar10 & 0xffffff00) >> 8);
                                    *(byte *)((int)puVar7 + 0x1d) = local_34._1_1_;
                                    local_34._0_2_ = CONCAT11(bVar2,bVar3);
                                    local_34 = uVar10 & 0xffff0000 | (uint)(ushort)local_34;
                                    if (0xe < param_5) {
                                      bVar3 = *(byte *)((int)local_5c + 0xe);
                                      local_34._2_1_ = (byte)((uVar10 & 0xffff0000) >> 0x10);
                                      *(byte *)((int)puVar7 + 0x1e) = local_34._2_1_;
                                      local_34._0_3_ = CONCAT12(bVar3,(ushort)local_34);
                                      local_34 = uVar10 & 0xff000000 | (uint)(uint3)local_34;
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
          local_40 = *local_5c;
          uVar10 = param_5 & 0xfffffffc;
          *local_58 = uVar4;
          if (1 < param_5 >> 2) {
            local_3c = local_5c[1];
            puVar7[5] = uVar6;
            if (2 < param_5 >> 2) {
              local_38 = local_5c[2];
              puVar7[6] = uVar9;
            }
          }
          if (uVar10 != param_5) {
            bVar3 = *(byte *)((int)local_5c + (param_5 & 0xfffffffc));
            uVar4 = uVar10 + 1;
            *(byte *)((int)local_58 + (param_5 & 0xfffffffc)) = *(byte *)((int)&local_40 + uVar10);
            *(byte *)((int)&local_40 + uVar10) = bVar3;
            if (uVar4 < param_5) {
              bVar3 = *(byte *)((int)local_5c + uVar4);
              uVar6 = uVar10 + 2;
              *(byte *)((int)local_58 + uVar4) = *(byte *)((int)&local_40 + uVar10 + 1);
              *(byte *)((int)&local_40 + uVar10 + 1) = bVar3;
              if (uVar6 < param_5) {
                bVar3 = *(byte *)((int)local_5c + uVar6);
                *(byte *)((int)local_58 + uVar6) = *(byte *)((int)&local_40 + uVar10 + 2);
                *(byte *)((int)&local_40 + uVar10 + 2) = bVar3;
              }
            }
          }
        }
        local_40 = local_40 ^ local_50;
        local_3c = local_3c ^ uVar1;
        local_38 = local_38 ^ local_48;
        local_34 = local_34 ^ local_44;
        (*(code *)param_1[2])(&local_40,&local_40,*param_1);
        param_5 = 0;
        local_3c = local_3c ^ uStack_4c;
        local_38 = local_38 ^ local_48;
        local_34 = local_34 ^ local_44;
        *puVar7 = local_40 ^ local_50;
        puVar7[1] = local_3c;
        puVar7[2] = local_38;
        puVar7[3] = local_34;
        local_40 = local_40 ^ local_50;
        goto LAB_001021c4;
      }
    }
    uVar6 = local_44 * 2 + (uint)CARRY4(local_48,local_48);
    uVar10 = uStack_4c * 2 + (uint)CARRY4(local_50,local_50);
    uVar9 = local_50 * 2 ^ (int)local_44 >> 0x1f & 0x87U;
    uVar4 = uStack_4c >> 0x1f | local_48 * 2;
    local_40 = *local_5c ^ uVar9;
    local_3c = local_5c[1] ^ uVar10;
    local_38 = local_5c[2] ^ uVar4;
    local_34 = local_5c[3] ^ uVar6;
    (*(code *)param_1[2])(&local_40,&local_40,*param_1);
    uVar9 = uVar9 ^ local_40;
    uVar10 = uVar10 ^ local_3c;
    uVar4 = uVar4 ^ local_38;
    uVar6 = uVar6 ^ local_34;
    local_3c = uVar10;
    local_38 = uVar4;
    local_34 = uVar6;
    local_40 = uVar9;
    if (param_5 != 0) {
      puVar7 = local_5c + 4;
      puVar5 = local_58 + 4;
      if ((((uint)puVar5 | (uint)puVar7) & 3) == 0 &&
          ((6 < param_5 &&
           ((local_5c + 5 <= &local_40 || &local_3c <= puVar7) &&
           (local_5c + 5 <= puVar5 || local_58 + 5 <= puVar7))) &&
          (local_58 + 5 <= &local_40 || &local_3c <= puVar5))) {
        uVar6 = param_5 & 0xfffffffc;
        local_40 = local_5c[4];
        local_58[4] = uVar9;
        if (1 < param_5 >> 2) {
          local_3c = local_5c[5];
          local_58[5] = uVar10;
          if (2 < param_5 >> 2) {
            local_38 = local_5c[6];
            local_58[6] = uVar4;
          }
        }
        if (param_5 != uVar6) {
          bVar3 = *(byte *)((int)local_5c + uVar6 + 0x10);
          *(byte *)((int)local_58 + uVar6 + 0x10) = *(byte *)((int)&local_40 + uVar6);
          *(byte *)((int)&local_40 + uVar6) = bVar3;
          if (uVar6 + 1 < param_5) {
            bVar3 = *(byte *)((int)local_5c + uVar6 + 0x11);
            *(byte *)((int)local_58 + uVar6 + 0x11) = *(byte *)((int)&local_40 + uVar6 + 1);
            *(byte *)((int)&local_40 + uVar6 + 1) = bVar3;
            if (uVar6 + 2 < param_5) {
              bVar3 = *(byte *)((int)local_5c + uVar6 + 0x12);
              *(byte *)((int)local_58 + uVar6 + 0x12) = *(byte *)((int)&local_40 + uVar6 + 2);
              *(byte *)((int)&local_40 + uVar6 + 2) = bVar3;
            }
          }
        }
      }
      else {
        local_40._0_1_ = (byte)uVar9;
        bVar3 = *(byte *)(local_5c + 4);
        *(byte *)(local_58 + 4) = (byte)local_40;
        local_40 = uVar9 & 0xffffff00 | (uint)bVar3;
        if (1 < param_5) {
          local_40._1_1_ = (byte)((uVar9 & 0xffffff00) >> 8);
          local_40._0_2_ = CONCAT11(*(byte *)((int)local_5c + 0x11),bVar3);
          local_40 = uVar9 & 0xffff0000 | (uint)(ushort)local_40;
          *(byte *)((int)local_58 + 0x11) = local_40._1_1_;
          if (2 < param_5) {
            local_40._2_1_ = (byte)((uVar9 & 0xffff0000) >> 0x10);
            local_40._0_3_ = CONCAT12(*(byte *)((int)local_5c + 0x12),(ushort)local_40);
            local_40 = uVar9 & 0xff000000 | (uint)(uint3)local_40;
            *(byte *)((int)local_58 + 0x12) = local_40._2_1_;
            if (3 < param_5) {
              local_40._3_1_ = (byte)((uVar9 & 0xff000000) >> 0x18);
              local_40 = CONCAT13(*(byte *)((int)local_5c + 0x13),(uint3)local_40);
              *(byte *)((int)local_58 + 0x13) = local_40._3_1_;
              if (4 < param_5) {
                bVar3 = *(byte *)(local_5c + 5);
                local_3c._0_1_ = (byte)uVar10;
                local_3c = uVar10 & 0xffffff00 | (uint)bVar3;
                *(byte *)(local_58 + 5) = (byte)local_3c;
                if (5 < param_5) {
                  local_3c._1_1_ = (byte)((uVar10 & 0xffffff00) >> 8);
                  local_3c._0_2_ = CONCAT11(*(byte *)((int)local_5c + 0x15),bVar3);
                  local_3c = uVar10 & 0xffff0000 | (uint)(ushort)local_3c;
                  *(byte *)((int)local_58 + 0x15) = local_3c._1_1_;
                  if (6 < param_5) {
                    local_3c._2_1_ = (byte)((uVar10 & 0xffff0000) >> 0x10);
                    local_3c._0_3_ = CONCAT12(*(byte *)((int)local_5c + 0x16),(ushort)local_3c);
                    local_3c = uVar10 & 0xff000000 | (uint)(uint3)local_3c;
                    *(byte *)((int)local_58 + 0x16) = local_3c._2_1_;
                    if (7 < param_5) {
                      local_3c._3_1_ = (byte)((uVar10 & 0xff000000) >> 0x18);
                      local_3c = CONCAT13(*(byte *)((int)local_5c + 0x17),(uint3)local_3c);
                      *(byte *)((int)local_58 + 0x17) = local_3c._3_1_;
                      if (8 < param_5) {
                        bVar3 = *(byte *)(local_5c + 6);
                        local_38._0_1_ = (byte)uVar4;
                        local_38 = uVar4 & 0xffffff00 | (uint)bVar3;
                        *(byte *)(local_58 + 6) = (byte)local_38;
                        if (9 < param_5) {
                          local_38._1_1_ = (byte)((uVar4 & 0xffffff00) >> 8);
                          local_38._0_2_ = CONCAT11(*(byte *)((int)local_5c + 0x19),bVar3);
                          local_38 = uVar4 & 0xffff0000 | (uint)(ushort)local_38;
                          *(byte *)((int)local_58 + 0x19) = local_38._1_1_;
                          if (10 < param_5) {
                            local_38._2_1_ = (byte)((uVar4 & 0xffff0000) >> 0x10);
                            local_38._0_3_ =
                                 CONCAT12(*(byte *)((int)local_5c + 0x1a),(ushort)local_38);
                            local_38 = uVar4 & 0xff000000 | (uint)(uint3)local_38;
                            *(byte *)((int)local_58 + 0x1a) = local_38._2_1_;
                            if (0xb < param_5) {
                              local_38._3_1_ = (byte)((uVar4 & 0xff000000) >> 0x18);
                              local_38 = CONCAT13(*(byte *)((int)local_5c + 0x1b),(uint3)local_38);
                              *(byte *)((int)local_58 + 0x1b) = local_38._3_1_;
                              if (0xc < param_5) {
                                bVar3 = *(byte *)(local_5c + 7);
                                local_34._0_1_ = (byte)uVar6;
                                local_34 = uVar6 & 0xffffff00 | (uint)bVar3;
                                *(byte *)(local_58 + 7) = (byte)local_34;
                                if (0xd < param_5) {
                                  local_34._1_1_ = (byte)((uVar6 & 0xffffff00) >> 8);
                                  local_34._0_2_ = CONCAT11(*(byte *)((int)local_5c + 0x1d),bVar3);
                                  local_34 = uVar6 & 0xffff0000 | (uint)(ushort)local_34;
                                  *(byte *)((int)local_58 + 0x1d) = local_34._1_1_;
                                  if (0xe < param_5) {
                                    local_34._2_1_ = (byte)((uVar6 & 0xffff0000) >> 0x10);
                                    local_34._0_3_ =
                                         CONCAT12(*(byte *)((int)local_5c + 0x1e),(ushort)local_34);
                                    local_34 = uVar6 & 0xff000000 | (uint)(uint3)local_34;
                                    local_34._1_1_ = local_34._2_1_;
                                  }
                                  if (0xe < param_5) {
                                    *(byte *)((int)local_58 + 0x1e) = local_34._1_1_;
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
    local_3c = local_3c ^ uStack_4c;
    local_40 = local_40 ^ local_50;
    local_34 = local_44 ^ local_34;
    local_38 = local_48 ^ local_38;
    (*(code *)param_1[2])(&local_40,&local_40,*param_1);
    param_5 = 0;
    local_3c = local_3c ^ uStack_4c;
    local_38 = local_38 ^ local_48;
    local_34 = local_34 ^ local_44;
    *local_58 = local_40 ^ local_50;
    local_58[1] = local_3c;
    local_58[2] = local_38;
    local_58[3] = local_34;
    local_40 = local_40 ^ local_50;
  }
LAB_001021c4:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_5);
  }
  return;
}

