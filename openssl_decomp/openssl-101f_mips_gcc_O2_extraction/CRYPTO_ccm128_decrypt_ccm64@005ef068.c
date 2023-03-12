
/* WARNING: Could not reconcile some variable overlaps */

uint * CRYPTO_ccm128_decrypt_ccm64
                 (byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  undefined *puVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  code *pcVar18;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  byte *local_2c;
  
  puVar5 = PTR___stack_chk_guard_006aabf0;
  bVar1 = *param_1;
  pcVar18 = *(code **)(param_1 + 0x28);
  local_2c = *(byte **)PTR___stack_chk_guard_006aabf0;
  puVar17 = *(uint **)(param_1 + 0x2c);
  pbVar12 = param_1 + 0x10;
  puVar13 = param_3;
  if ((bVar1 & 0x40) == 0) {
    puVar13 = puVar17;
    (*pcVar18)(param_1,pbVar12);
  }
  uVar16 = bVar1 & 7;
  iVar14 = 0xf - uVar16;
  *param_1 = (byte)uVar16;
  if (iVar14 == 0xf) {
    uVar6 = 0;
  }
  else {
    pbVar12 = param_1 + iVar14;
    bVar7 = *pbVar12;
    *pbVar12 = 0;
    uVar6 = (uint)bVar7 << 8;
    if (0x10 - uVar16 != 0xf) {
      bVar2 = param_1[0x10 - uVar16];
      puVar13 = (uint *)(uint)bVar2;
      pbVar12 = (byte *)(0x11 - uVar16);
      param_1[0x10 - uVar16] = 0;
      uVar3 = CONCAT11(bVar7,bVar2);
      uVar6 = (uint)uVar3 << 8;
      if (pbVar12 != &DAT_0000000f) {
        pbVar12 = param_1 + (int)pbVar12;
        bVar7 = *pbVar12;
        puVar13 = (uint *)(uint)bVar7;
        *pbVar12 = 0;
        uVar4 = CONCAT21(uVar3,bVar7);
        uVar6 = (uint)uVar4 << 8;
        if (0x12 - uVar16 != 0xf) {
          bVar7 = param_1[0x12 - uVar16];
          puVar13 = (uint *)(uint)bVar7;
          pbVar12 = (byte *)(0x13 - uVar16);
          param_1[0x12 - uVar16] = 0;
          uVar6 = CONCAT31(uVar4,bVar7) << 8;
          if (pbVar12 != &DAT_0000000f) {
            pbVar12 = param_1 + (int)pbVar12;
            puVar13 = (uint *)(uint)*pbVar12;
            *pbVar12 = 0;
            uVar6 = ((uint)puVar13 | uVar6) << 8;
            if (0x14 - uVar16 != 0xf) {
              puVar13 = (uint *)(uint)param_1[0x14 - uVar16];
              pbVar12 = (byte *)(0x15 - uVar16);
              param_1[0x14 - uVar16] = 0;
              uVar6 = ((uint)puVar13 | uVar6) << 8;
              if (pbVar12 != &DAT_0000000f) {
                bVar7 = param_1[0xe];
                param_1[0xe] = 0;
                uVar6 = (bVar7 | uVar6) << 8;
              }
            }
          }
        }
      }
    }
  }
  uVar6 = param_1[0xf] | uVar6;
  param_1[0xf] = 1;
  if (uVar6 != param_4) {
    puVar17 = (uint *)0xffffffff;
    goto LAB_005ef260;
  }
  uVar8 = param_4 >> 4;
  puVar13 = (uint *)(param_1 + 0x10);
  if (uVar8 == 0) {
    if (param_4 != 0) goto LAB_005ef3c4;
  }
  else {
    (*param_5)(param_2,param_3,uVar8,puVar17,param_1,puVar13);
    uVar6 = param_4 + uVar8 * -0x10;
    param_2 = (uint *)((int)param_2 + (param_4 & 0xfffffff0));
    param_3 = (uint *)((int)param_3 + (param_4 & 0xfffffff0));
    if (uVar6 == 0) goto LAB_005ef1e4;
    uVar8 = (uVar8 & 0xff) + (uint)param_1[0xf];
    uVar9 = uVar8 >> 8;
    param_1[0xf] = (byte)uVar8;
    if (param_4 >> 0xc == 0) {
      if (uVar9 == 0) goto LAB_005ef3c4;
      uVar9 = param_1[0xe] + 1 >> 8;
      param_1[0xe] = (byte)(param_1[0xe] + 1);
LAB_005ef33c:
      if (uVar9 == 0) goto LAB_005ef3c4;
      uVar9 = param_1[0xd] + 1 >> 8;
      param_1[0xd] = (byte)(param_1[0xd] + 1);
LAB_005ef354:
      if (uVar9 == 0) goto LAB_005ef3c4;
      uVar8 = param_1[0xc] + 1;
      param_1[0xc] = (byte)uVar8;
    }
    else {
      uVar8 = (uint)param_1[0xe] + (param_4 >> 0xc & 0xff) + uVar9;
      uVar9 = uVar8 >> 8;
      param_1[0xe] = (byte)uVar8;
      if (param_4 >> 0x14 == 0) goto LAB_005ef33c;
      uVar8 = (uint)param_1[0xd] + (param_4 >> 0x14 & 0xff) + uVar9;
      uVar9 = uVar8 >> 8;
      param_1[0xd] = (byte)uVar8;
      if (param_4 >> 0x1c == 0) goto LAB_005ef354;
      uVar8 = (uint)param_1[0xc] + (param_4 >> 0x1c) + uVar9;
      param_1[0xc] = (byte)uVar8;
    }
    if ((((uVar8 >> 8 != 0) &&
         (bVar7 = param_1[0xb], param_1[0xb] = (byte)(bVar7 + 1), bVar7 + 1 >> 8 != 0)) &&
        (bVar7 = param_1[10], param_1[10] = (byte)(bVar7 + 1), bVar7 + 1 >> 8 != 0)) &&
       (bVar7 = param_1[9], param_1[9] = (byte)(bVar7 + 1), bVar7 + 1 >> 8 != 0)) {
      param_1[8] = param_1[8] + 1;
    }
LAB_005ef3c4:
    (*pcVar18)(param_1,&local_40,puVar17);
    if (((uVar6 < 5 ||
         (puVar13 < param_3 + 1 && param_3 < param_1 + 0x14 ||
         puVar13 < param_2 + 1 && param_2 < param_1 + 0x14)) ||
         param_2 < param_3 + 1 && param_3 < param_2 + 1) ||
       ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
      bVar7 = *(byte *)param_2;
      *(byte *)param_3 = bVar7 ^ local_40._0_1_;
      param_1[0x10] = bVar7 ^ local_40._0_1_ ^ param_1[0x10];
      if (uVar6 != 1) {
        local_40._1_1_ = local_40._1_1_ ^ *(byte *)((int)param_2 + 1);
        *(byte *)((int)param_3 + 1) = local_40._1_1_;
        param_1[0x11] = local_40._1_1_ ^ param_1[0x11];
        if (uVar6 != 2) {
          local_40._2_1_ = local_40._2_1_ ^ *(byte *)((int)param_2 + 2);
          *(byte *)((int)param_3 + 2) = local_40._2_1_;
          param_1[0x12] = local_40._2_1_ ^ param_1[0x12];
          if (uVar6 != 3) {
            local_40._3_1_ = (byte)local_40 ^ *(byte *)((int)param_2 + 3);
            *(byte *)((int)param_3 + 3) = (byte)local_40;
            param_1[0x13] = (byte)local_40 ^ param_1[0x13];
            if (uVar6 >= 5) {
              bVar7 = *(byte *)(param_2 + 1);
              *(byte *)(param_3 + 1) = local_3c._0_1_ ^ bVar7;
              param_1[0x14] = local_3c._0_1_ ^ bVar7 ^ param_1[0x14];
              if (5 < uVar6) {
                local_3c._1_1_ = local_3c._1_1_ ^ *(byte *)((int)param_2 + 5);
                *(byte *)((int)param_3 + 5) = local_3c._1_1_;
                param_1[0x15] = local_3c._1_1_ ^ param_1[0x15];
                if (uVar6 != 6) {
                  local_3c._2_1_ = local_3c._2_1_ ^ *(byte *)((int)param_2 + 6);
                  *(byte *)((int)param_3 + 6) = local_3c._2_1_;
                  param_1[0x16] = local_3c._2_1_ ^ param_1[0x16];
                  if (uVar6 != 7) {
                    local_3c._3_1_ = (byte)local_3c ^ *(byte *)((int)param_2 + 7);
                    *(byte *)((int)param_3 + 7) = (byte)local_3c;
                    param_1[0x17] = (byte)local_3c ^ param_1[0x17];
                    if (uVar6 != 8) {
                      bVar7 = *(byte *)(param_2 + 2);
                      *(byte *)(param_3 + 2) = local_38._0_1_ ^ bVar7;
                      param_1[0x18] = local_38._0_1_ ^ bVar7 ^ param_1[0x18];
                      if (uVar6 != 9) {
                        local_38._1_1_ = local_38._1_1_ ^ *(byte *)((int)param_2 + 9);
                        *(byte *)((int)param_3 + 9) = local_38._1_1_;
                        param_1[0x19] = local_38._1_1_ ^ param_1[0x19];
                        if (uVar6 != 10) {
                          local_38._2_1_ = local_38._2_1_ ^ *(byte *)((int)param_2 + 10);
                          *(byte *)((int)param_3 + 10) = local_38._2_1_;
                          param_1[0x1a] = local_38._2_1_ ^ param_1[0x1a];
                          if (uVar6 != 0xb) {
                            local_38._3_1_ = (byte)local_38 ^ *(byte *)((int)param_2 + 0xb);
                            *(byte *)((int)param_3 + 0xb) = (byte)local_38;
                            param_1[0x1b] = (byte)local_38 ^ param_1[0x1b];
                            if (uVar6 != 0xc) {
                              bVar7 = *(byte *)(param_2 + 3);
                              *(byte *)(param_3 + 3) = local_34._0_1_ ^ bVar7;
                              param_1[0x1c] = local_34._0_1_ ^ bVar7 ^ param_1[0x1c];
                              if (uVar6 != 0xd) {
                                local_34._1_1_ = local_34._1_1_ ^ *(byte *)((int)param_2 + 0xd);
                                *(byte *)((int)param_3 + 0xd) = local_34._1_1_;
                                param_1[0x1d] = local_34._1_1_ ^ param_1[0x1d];
                                if (uVar6 != 0xe) {
                                  local_34._2_1_ = local_34._2_1_ ^ *(byte *)((int)param_2 + 0xe);
                                  *(byte *)((int)param_3 + 0xe) = local_34._2_1_;
                                  param_1[0x1e] = local_34._2_1_ ^ param_1[0x1e];
                                  if (uVar6 != 0xf) {
                                    local_34._3_1_ = *(byte *)((int)param_2 + 0xf) ^ (byte)local_34;
                                    *(byte *)((int)param_3 + 0xf) = (byte)local_34;
                                    param_1[0x1f] = (byte)local_34 ^ param_1[0x1f];
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
      if (uVar6 != 0) {
        uVar8 = uVar6;
      }
      iVar10 = (uVar8 - 4 >> 2) + 1;
      uVar9 = iVar10 * 4;
      if (uVar6 < 4) {
        uVar9 = 0;
      }
      else {
        uVar15 = *param_2;
        *param_3 = local_40 ^ uVar15;
        *(uint *)(param_1 + 0x10) = local_40 ^ uVar15 ^ *(uint *)(param_1 + 0x10);
        if (iVar10 != 1) {
          uVar15 = param_2[1];
          param_3[1] = uVar15 ^ local_3c;
          *(uint *)(param_1 + 0x14) = uVar15 ^ local_3c ^ *(uint *)(param_1 + 0x14);
          if (iVar10 != 2) {
            uVar15 = param_2[2];
            param_3[2] = uVar15 ^ local_38;
            *(uint *)(param_1 + 0x18) = uVar15 ^ local_38 ^ *(uint *)(param_1 + 0x18);
            if (iVar10 != 3) {
              uVar15 = param_2[3];
              param_3[3] = uVar15 ^ (uint)local_34;
              *(uint *)(param_1 + 0x1c) = uVar15 ^ (uint)local_34 ^ *(uint *)(param_1 + 0x1c);
            }
          }
        }
        if (uVar9 == uVar8) goto LAB_005ef5c4;
      }
      uVar8 = uVar9 + 1;
      bVar7 = *(byte *)((int)param_2 + uVar9) ^ *(byte *)((int)&local_40 + uVar9);
      *(byte *)((int)param_3 + uVar9) = bVar7;
      param_1[uVar9 + 0x10] = bVar7 ^ param_1[uVar9 + 0x10];
      if (uVar8 < uVar6) {
        uVar15 = uVar9 + 2;
        bVar7 = *(byte *)((int)param_2 + uVar8) ^ *(byte *)((int)&local_40 + uVar9 + 1);
        *(byte *)((int)param_3 + uVar8) = bVar7;
        param_1[uVar9 + 0x11] = bVar7 ^ param_1[uVar9 + 0x11];
        if (uVar15 < uVar6) {
          bVar7 = *(byte *)((int)param_2 + uVar15) ^ *(byte *)((int)&local_40 + uVar9 + 2);
          *(byte *)((int)param_3 + uVar15) = bVar7;
          param_1[uVar9 + 0x12] = bVar7 ^ param_1[uVar9 + 0x12];
        }
      }
    }
LAB_005ef5c4:
    (*pcVar18)(puVar13,puVar13,puVar17);
  }
LAB_005ef1e4:
  (*(code *)PTR_memset_006aab00)(param_1 + (0xf - uVar16),0,0x10 - iVar14);
  (*pcVar18)(param_1,&local_40,puVar17);
  puVar17 = (uint *)0x0;
  pbVar12 = (byte *)(*(uint *)(param_1 + 0x14) ^ local_3c);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_40;
  *param_1 = bVar1;
  *(byte **)(param_1 + 0x14) = pbVar12;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ (uint)local_34;
  puVar13 = local_34;
LAB_005ef260:
  if (local_2c == *(byte **)puVar5) {
    return puVar17;
  }
  pbVar11 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar17 = (uint *)((((uint)*pbVar11 << 0x1a) >> 0x1d) * 2 + 2);
  if (puVar17 <= puVar13) {
    (*(code *)PTR_memcpy_006aabf4)(pbVar12,pbVar11 + 0x10,puVar17);
    return puVar17;
  }
  return (uint *)0x0;
}

