
/* WARNING: Could not reconcile some variable overlaps */

void CRYPTO_cbc128_decrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  byte *pbVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar5 = param_2;
  if (param_1 == param_2) {
    if ((((uint)param_2 | (uint)param_5) & 3) == 0) {
      if (0xf < param_3) {
        puVar5 = param_1;
        uVar18 = param_3;
        do {
          (*param_6)(puVar5,&local_3c,param_4);
          uVar18 = uVar18 - 0x10;
          uVar6 = *puVar5;
          *puVar5 = local_3c ^ *param_5;
          *param_5 = uVar6;
          uVar6 = puVar5[1];
          puVar5[1] = local_38 ^ param_5[1];
          param_5[1] = uVar6;
          uVar6 = puVar5[2];
          puVar5[2] = local_34 ^ param_5[2];
          param_5[2] = uVar6;
          puVar11 = (uint *)puVar5[3];
          puVar5[3] = local_30 ^ param_5[3];
          param_5[3] = (uint)puVar11;
          puVar5 = puVar5 + 4;
        } while (0xf < uVar18);
LAB_004ec5cc:
        uVar18 = param_3 - 0x10;
        param_3 = param_3 & 0xf;
        param_2 = param_1 + ((uVar18 >> 4) + 1) * 4;
        param_1 = puVar11;
        puVar5 = param_2;
      }
    }
    else if (0xf < param_3) {
      uVar18 = param_3;
      puVar5 = param_1;
      do {
        (*param_6)(puVar5,&local_3c,param_4);
        uVar18 = uVar18 - 0x10;
        bVar1 = *(byte *)puVar5;
        *(byte *)puVar5 = local_3c._0_1_ ^ *(byte *)param_5;
        *(byte *)param_5 = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 1);
        *(byte *)((int)puVar5 + 1) = local_3c._1_1_ ^ *(byte *)((int)param_5 + 1);
        *(byte *)((int)param_5 + 1) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 2);
        *(byte *)((int)puVar5 + 2) = local_3c._2_1_ ^ *(byte *)((int)param_5 + 2);
        *(byte *)((int)param_5 + 2) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 3);
        *(byte *)((int)puVar5 + 3) = (byte)local_3c ^ *(byte *)((int)param_5 + 3);
        *(byte *)((int)param_5 + 3) = bVar1;
        bVar1 = *(byte *)(puVar5 + 1);
        *(byte *)(puVar5 + 1) = local_38._0_1_ ^ *(byte *)(param_5 + 1);
        *(byte *)(param_5 + 1) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 5);
        *(byte *)((int)puVar5 + 5) = local_38._1_1_ ^ *(byte *)((int)param_5 + 5);
        *(byte *)((int)param_5 + 5) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 6);
        *(byte *)((int)puVar5 + 6) = local_38._2_1_ ^ *(byte *)((int)param_5 + 6);
        *(byte *)((int)param_5 + 6) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 7);
        *(byte *)((int)puVar5 + 7) = (byte)local_38 ^ *(byte *)((int)param_5 + 7);
        *(byte *)((int)param_5 + 7) = bVar1;
        bVar1 = *(byte *)(puVar5 + 2);
        *(byte *)(puVar5 + 2) = local_34._0_1_ ^ *(byte *)(param_5 + 2);
        *(byte *)(param_5 + 2) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 9);
        *(byte *)((int)puVar5 + 9) = local_34._1_1_ ^ *(byte *)((int)param_5 + 9);
        *(byte *)((int)param_5 + 9) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 10);
        *(byte *)((int)puVar5 + 10) = local_34._2_1_ ^ *(byte *)((int)param_5 + 10);
        *(byte *)((int)param_5 + 10) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 0xb);
        *(byte *)((int)puVar5 + 0xb) = (byte)local_34 ^ *(byte *)((int)param_5 + 0xb);
        *(byte *)((int)param_5 + 0xb) = bVar1;
        bVar1 = *(byte *)(puVar5 + 3);
        *(byte *)(puVar5 + 3) = local_30._0_1_ ^ *(byte *)(param_5 + 3);
        *(byte *)(param_5 + 3) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 0xd);
        *(byte *)((int)puVar5 + 0xd) = local_30._1_1_ ^ *(byte *)((int)param_5 + 0xd);
        *(byte *)((int)param_5 + 0xd) = bVar1;
        bVar1 = *(byte *)((int)puVar5 + 0xe);
        *(byte *)((int)puVar5 + 0xe) = local_30._2_1_ ^ *(byte *)((int)param_5 + 0xe);
        *(byte *)((int)param_5 + 0xe) = bVar1;
        puVar11 = (uint *)(uint)*(byte *)((int)param_5 + 0xf);
        bVar1 = *(byte *)((int)puVar5 + 0xf);
        *(byte *)((int)puVar5 + 0xf) = (byte)local_30 ^ *(byte *)((int)param_5 + 0xf);
        *(byte *)((int)param_5 + 0xf) = bVar1;
        puVar5 = puVar5 + 4;
      } while (0xf < uVar18);
      goto LAB_004ec5cc;
    }
  }
  else {
    puVar11 = param_5;
    if ((((uint)param_1 | (uint)param_2 | (uint)param_5) & 3) == 0) {
      puVar17 = param_1;
      uVar18 = param_3;
      if (0xf < param_3) {
        do {
          (*param_6)(puVar17,puVar5,param_4);
          uVar18 = uVar18 - 0x10;
          *puVar5 = *puVar5 ^ *puVar11;
          puVar5[1] = puVar5[1] ^ puVar11[1];
          puVar5[2] = puVar5[2] ^ puVar11[2];
          puVar5[3] = puVar5[3] ^ puVar11[3];
          puVar11 = puVar17;
          puVar5 = puVar5 + 4;
          puVar17 = puVar17 + 4;
        } while (0xf < uVar18);
        goto LAB_004ebf48;
      }
    }
    else {
      puVar17 = param_1;
      uVar18 = param_3;
      if (0xf < param_3) {
        do {
          (*param_6)(puVar17,puVar5,param_4);
          uVar18 = uVar18 - 0x10;
          *(byte *)puVar5 = *(byte *)puVar5 ^ *(byte *)puVar11;
          *(byte *)((int)puVar5 + 1) = *(byte *)((int)puVar5 + 1) ^ *(byte *)((int)puVar11 + 1);
          *(byte *)((int)puVar5 + 2) = *(byte *)((int)puVar5 + 2) ^ *(byte *)((int)puVar11 + 2);
          *(byte *)((int)puVar5 + 3) = *(byte *)((int)puVar5 + 3) ^ *(byte *)((int)puVar11 + 3);
          *(byte *)(puVar5 + 1) = *(byte *)(puVar5 + 1) ^ *(byte *)(puVar11 + 1);
          *(byte *)((int)puVar5 + 5) = *(byte *)((int)puVar5 + 5) ^ *(byte *)((int)puVar11 + 5);
          *(byte *)((int)puVar5 + 6) = *(byte *)((int)puVar5 + 6) ^ *(byte *)((int)puVar11 + 6);
          *(byte *)((int)puVar5 + 7) = *(byte *)((int)puVar5 + 7) ^ *(byte *)((int)puVar11 + 7);
          *(byte *)(puVar5 + 2) = *(byte *)(puVar5 + 2) ^ *(byte *)(puVar11 + 2);
          *(byte *)((int)puVar5 + 9) = *(byte *)((int)puVar5 + 9) ^ *(byte *)((int)puVar11 + 9);
          *(byte *)((int)puVar5 + 10) = *(byte *)((int)puVar5 + 10) ^ *(byte *)((int)puVar11 + 10);
          *(byte *)((int)puVar5 + 0xb) =
               *(byte *)((int)puVar5 + 0xb) ^ *(byte *)((int)puVar11 + 0xb);
          *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) ^ *(byte *)(puVar11 + 3);
          *(byte *)((int)puVar5 + 0xd) =
               *(byte *)((int)puVar5 + 0xd) ^ *(byte *)((int)puVar11 + 0xd);
          *(byte *)((int)puVar5 + 0xe) =
               *(byte *)((int)puVar5 + 0xe) ^ *(byte *)((int)puVar11 + 0xe);
          *(byte *)((int)puVar5 + 0xf) =
               *(byte *)((int)puVar5 + 0xf) ^ *(byte *)((int)puVar11 + 0xf);
          puVar5 = puVar5 + 4;
          puVar11 = puVar17;
          puVar17 = puVar17 + 4;
        } while (0xf < uVar18);
LAB_004ebf48:
        uVar18 = param_3 - 0x10;
        param_3 = param_3 & 0xf;
        iVar3 = (uVar18 >> 4) + 1;
        puVar11 = (uint *)((int)param_1 + (uVar18 & 0xfffffff0));
        param_1 = param_1 + iVar3 * 4;
        puVar5 = param_2 + iVar3 * 4;
      }
    }
    param_2 = param_1;
    uVar6 = puVar11[1];
    param_1 = (uint *)puVar11[2];
    uVar18 = puVar11[3];
    *param_5 = *puVar11;
    param_5[1] = uVar6;
    param_5[2] = (uint)param_1;
    param_5[3] = uVar18;
  }
  puVar7 = &local_3c;
  if (param_3 != 0) {
    (*param_6)(param_2,puVar7,param_4);
    bVar1 = *(byte *)param_2;
    *(byte *)puVar5 = local_3c._0_1_ ^ *(byte *)param_5;
    *(byte *)param_5 = bVar1;
    if (param_3 == 1) {
      iVar3 = 1;
    }
    else {
      bVar1 = *(byte *)((int)param_2 + 1);
      *(byte *)((int)puVar5 + 1) = local_3c._1_1_ ^ *(byte *)((int)param_5 + 1);
      *(byte *)((int)param_5 + 1) = bVar1;
      if (param_3 == 2) {
        iVar3 = 2;
      }
      else {
        bVar1 = *(byte *)((int)param_2 + 2);
        *(byte *)((int)puVar5 + 2) = local_3c._2_1_ ^ *(byte *)((int)param_5 + 2);
        *(byte *)((int)param_5 + 2) = bVar1;
        if (param_3 == 3) {
          iVar3 = 3;
        }
        else {
          bVar1 = *(byte *)((int)param_2 + 3);
          *(byte *)((int)puVar5 + 3) = (byte)local_3c ^ *(byte *)((int)param_5 + 3);
          *(byte *)((int)param_5 + 3) = bVar1;
          if (param_3 == 4) {
            iVar3 = 4;
          }
          else {
            bVar1 = *(byte *)(param_2 + 1);
            *(byte *)(puVar5 + 1) = local_38._0_1_ ^ *(byte *)(param_5 + 1);
            *(byte *)(param_5 + 1) = bVar1;
            if (param_3 == 5) {
              iVar3 = 5;
            }
            else {
              bVar1 = *(byte *)((int)param_2 + 5);
              *(byte *)((int)puVar5 + 5) = local_38._1_1_ ^ *(byte *)((int)param_5 + 5);
              *(byte *)((int)param_5 + 5) = bVar1;
              if (param_3 == 6) {
                iVar3 = 6;
              }
              else {
                bVar1 = *(byte *)((int)param_2 + 6);
                *(byte *)((int)puVar5 + 6) = local_38._2_1_ ^ *(byte *)((int)param_5 + 6);
                *(byte *)((int)param_5 + 6) = bVar1;
                if (param_3 == 7) {
                  iVar3 = 7;
                }
                else {
                  bVar1 = *(byte *)((int)param_2 + 7);
                  *(byte *)((int)puVar5 + 7) = (byte)local_38 ^ *(byte *)((int)param_5 + 7);
                  *(byte *)((int)param_5 + 7) = bVar1;
                  if (param_3 == 8) {
                    iVar3 = 8;
                  }
                  else {
                    bVar1 = *(byte *)(param_2 + 2);
                    *(byte *)(puVar5 + 2) = local_34._0_1_ ^ *(byte *)(param_5 + 2);
                    *(byte *)(param_5 + 2) = bVar1;
                    if (param_3 == 9) {
                      iVar3 = 9;
                    }
                    else {
                      bVar1 = *(byte *)((int)param_2 + 9);
                      *(byte *)((int)puVar5 + 9) = local_34._1_1_ ^ *(byte *)((int)param_5 + 9);
                      *(byte *)((int)param_5 + 9) = bVar1;
                      if (param_3 == 10) {
                        iVar3 = 10;
                      }
                      else {
                        bVar1 = *(byte *)((int)param_2 + 10);
                        *(byte *)((int)puVar5 + 10) = local_34._2_1_ ^ *(byte *)((int)param_5 + 10);
                        *(byte *)((int)param_5 + 10) = bVar1;
                        if (param_3 == 0xb) {
                          iVar3 = 0xb;
                        }
                        else {
                          bVar1 = *(byte *)((int)param_2 + 0xb);
                          *(byte *)((int)puVar5 + 0xb) =
                               (byte)local_34 ^ *(byte *)((int)param_5 + 0xb);
                          *(byte *)((int)param_5 + 0xb) = bVar1;
                          if (param_3 == 0xc) {
                            iVar3 = 0xc;
                          }
                          else {
                            bVar1 = *(byte *)(param_2 + 3);
                            *(byte *)(puVar5 + 3) = local_30._0_1_ ^ *(byte *)(param_5 + 3);
                            *(byte *)(param_5 + 3) = bVar1;
                            if (param_3 == 0xd) {
                              iVar3 = 0xd;
                            }
                            else {
                              puVar7 = (undefined4 *)(uint)*(byte *)((int)param_5 + 0xd);
                              bVar1 = *(byte *)((int)param_2 + 0xd);
                              *(byte *)((int)puVar5 + 0xd) =
                                   local_30._1_1_ ^ *(byte *)((int)param_5 + 0xd);
                              *(byte *)((int)param_5 + 0xd) = bVar1;
                              if (param_3 == 0xf) {
                                param_1 = (uint *)(uint)*(byte *)((int)param_5 + 0xe);
                                bVar1 = *(byte *)((int)param_2 + 0xe);
                                *(byte *)((int)puVar5 + 0xe) =
                                     local_30._2_1_ ^ *(byte *)((int)param_5 + 0xe);
                                *(byte *)((int)param_5 + 0xe) = bVar1;
                                *(byte *)((int)param_5 + 0xf) = *(byte *)((int)param_2 + 0xf);
                                goto LAB_004ec1ac;
                              }
                              iVar3 = 0xe;
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
    iVar13 = iVar3 + 4;
    puVar10 = (undefined4 *)((int)param_2 + iVar3);
    puVar8 = (undefined4 *)((int)param_5 + iVar3);
    uVar18 = 0x10 - iVar3;
    if ((uVar18 < 10 ||
         puVar8 < (undefined4 *)((int)param_2 + iVar13) &&
         puVar10 < (undefined4 *)((int)param_5 + iVar13)) ||
       ((((uint)puVar10 | (uint)puVar8) & 3) != 0)) {
      puVar7 = (undefined4 *)(iVar3 + 2);
      param_1 = (uint *)((int)param_5 + iVar3 + 1);
      *(byte *)puVar8 = *(byte *)puVar10;
      *(byte *)param_1 = *(byte *)((int)param_2 + iVar3 + 1);
      if (puVar7 != (undefined4 *)&SUB_00000010) {
        pbVar15 = (byte *)((int)param_2 + (int)puVar7);
        param_1 = (uint *)(iVar3 + 3);
        puVar7 = (undefined4 *)((int)param_5 + (int)puVar7);
        *(byte *)puVar7 = *pbVar15;
        if (param_1 != (uint *)&SUB_00000010) {
          pbVar15 = (byte *)((int)param_2 + (int)param_1);
          param_1 = (uint *)((int)param_5 + (int)param_1);
          puVar7 = (undefined4 *)(uint)*pbVar15;
          *(byte *)param_1 = *pbVar15;
          if (iVar13 != 0x10) {
            param_1 = (uint *)(iVar3 + 5);
            puVar7 = (undefined4 *)(uint)*(byte *)((int)param_2 + iVar13);
            *(byte *)((int)param_5 + iVar13) = *(byte *)((int)param_2 + iVar13);
            if (param_1 != (uint *)&SUB_00000010) {
              pbVar15 = (byte *)((int)param_2 + (int)param_1);
              puVar7 = (undefined4 *)((int)param_5 + (int)param_1);
              param_1 = (uint *)(iVar3 + 6);
              *(byte *)puVar7 = *pbVar15;
              if (param_1 != (uint *)&SUB_00000010) {
                pbVar15 = (byte *)((int)param_2 + (int)param_1);
                puVar7 = (undefined4 *)((int)param_5 + (int)param_1);
                param_1 = (uint *)(iVar3 + 7);
                *(byte *)puVar7 = *pbVar15;
                if (param_1 != (uint *)&SUB_00000010) {
                  pbVar15 = (byte *)((int)param_2 + (int)param_1);
                  puVar7 = (undefined4 *)((int)param_5 + (int)param_1);
                  param_1 = (uint *)(iVar3 + 8);
                  *(byte *)puVar7 = *pbVar15;
                  if (param_1 != (uint *)&SUB_00000010) {
                    pbVar15 = (byte *)((int)param_2 + (int)param_1);
                    puVar7 = (undefined4 *)((int)param_5 + (int)param_1);
                    param_1 = (uint *)(iVar3 + 9);
                    *(byte *)puVar7 = *pbVar15;
                    if (param_1 != (uint *)&SUB_00000010) {
                      pbVar15 = (byte *)((int)param_2 + (int)param_1);
                      puVar7 = (undefined4 *)((int)param_5 + (int)param_1);
                      param_1 = (uint *)(iVar3 + 10);
                      *(byte *)puVar7 = *pbVar15;
                      if (param_1 != (uint *)&SUB_00000010) {
                        pbVar15 = (byte *)((int)param_2 + (int)param_1);
                        puVar7 = (undefined4 *)((int)param_5 + (int)param_1);
                        param_1 = (uint *)(iVar3 + 0xb);
                        *(byte *)puVar7 = *pbVar15;
                        if (param_1 != (uint *)&SUB_00000010) {
                          pbVar15 = (byte *)((int)param_2 + (int)param_1);
                          iVar13 = iVar3 + 0xc;
                          param_1 = (uint *)((int)param_5 + (int)param_1);
                          puVar7 = (undefined4 *)&SUB_00000010;
                          *(byte *)param_1 = *pbVar15;
                          if (iVar13 != 0x10) {
                            param_1 = (uint *)((int)param_5 + iVar13);
                            iVar4 = iVar3 + 0xd;
                            *(byte *)param_1 = *(byte *)((int)param_2 + iVar13);
                            if (iVar4 != 0x10) {
                              param_1 = (uint *)&SUB_00000002;
                              puVar7 = (undefined4 *)(uint)*(byte *)((int)param_2 + iVar4);
                              *(byte *)((int)param_5 + iVar4) = *(byte *)((int)param_2 + iVar4);
                              if (iVar3 != 2) {
                                *(byte *)((int)param_5 + 0xf) = *(byte *)((int)param_2 + 0xf);
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
      iVar13 = (0xcU - iVar3 >> 2) + 1;
      uVar6 = iVar13 * 4;
      if (2 < 0xfU - iVar3) {
        param_1 = (uint *)0x3;
        *puVar8 = *puVar10;
        puVar7 = (undefined4 *)puVar10[1];
        puVar8[1] = puVar7;
        if (iVar13 == 3) {
          puVar8[2] = puVar10[2];
        }
        iVar3 = iVar3 + uVar6;
        if (uVar6 == uVar18) goto LAB_004ec1ac;
        puVar10 = (undefined4 *)((int)param_2 + iVar3);
        puVar8 = (undefined4 *)((int)param_5 + iVar3);
      }
      puVar7 = (undefined4 *)(uint)*(byte *)puVar10;
      iVar13 = iVar3 + 1;
      param_1 = (uint *)&SUB_00000010;
      *(byte *)puVar8 = *(byte *)puVar10;
      if (iVar13 != 0x10) {
        iVar3 = iVar3 + 2;
        puVar7 = (undefined4 *)(uint)*(byte *)((int)param_2 + iVar13);
        *(byte *)((int)param_5 + iVar13) = *(byte *)((int)param_2 + iVar13);
        if (iVar3 != 0x10) {
          *(byte *)((int)param_5 + iVar3) = *(byte *)((int)param_2 + iVar3);
        }
      }
    }
  }
LAB_004ec1ac:
  if (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar5 = puVar7 + (*(byte *)((int)param_1 + 0xf) & 0xf) * 4;
    puVar11 = (uint *)((int)puVar7 + (*(byte *)((int)param_1 + 0xf) & 0xf0));
    pbVar15 = (byte *)((int)param_1 + 0xe);
    uVar16 = *puVar11 ^ *puVar5 >> 4 ^ *(uint *)(rem_4bit + (puVar5[3] & 0xf) * 4);
    uVar18 = puVar11[1] ^ (*puVar5 << 0x1c | puVar5[1] >> 4);
    uVar19 = puVar11[2] ^ (puVar5[1] << 0x1c | puVar5[2] >> 4);
    uVar6 = puVar11[3] ^ (puVar5[2] << 0x1c | puVar5[3] >> 4);
    do {
      puVar11 = puVar7 + (*pbVar15 & 0xf) * 4;
      puVar5 = (uint *)((int)puVar7 + (*pbVar15 & 0xf0));
      uVar9 = puVar11[3] ^ (uVar19 << 0x1c | uVar6 >> 4);
      uVar12 = *puVar11 ^ uVar16 >> 4 ^ *(uint *)(rem_4bit + (uVar6 & 0xf) * 4);
      uVar6 = puVar11[1] ^ (uVar16 << 0x1c | uVar18 >> 4);
      uVar14 = puVar11[2] ^ (uVar18 << 0x1c | uVar19 >> 4);
      pbVar15 = pbVar15 + -1;
      uVar16 = *puVar5 ^ uVar12 >> 4 ^ *(uint *)(rem_4bit + (uVar9 & 0xf) * 4);
      uVar18 = puVar5[1] ^ (uVar12 << 0x1c | uVar6 >> 4);
      uVar19 = puVar5[2] ^ (uVar6 << 0x1c | uVar14 >> 4);
      uVar6 = puVar5[3] ^ (uVar14 << 0x1c | uVar9 >> 4);
    } while ((byte *)((int)param_1 + -1) != pbVar15);
    *param_1 = uVar16;
    param_1[1] = uVar18;
    param_1[2] = uVar19;
    param_1[3] = uVar6;
    return;
  }
  return;
}

