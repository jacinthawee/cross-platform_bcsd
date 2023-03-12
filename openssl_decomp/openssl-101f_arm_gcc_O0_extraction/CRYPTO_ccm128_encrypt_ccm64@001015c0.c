
/* WARNING: Could not reconcile some variable overlaps */

void CRYPTO_ccm128_encrypt_ccm64
               (byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint3 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  code *pcVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_2c;
  
  bVar1 = *param_1;
  pcVar12 = *(code **)(param_1 + 0x28);
  local_2c = __TMC_END__;
  uVar10 = *(undefined4 *)(param_1 + 0x2c);
  if (-1 < (int)((uint)bVar1 << 0x19)) {
    (*pcVar12)(param_1,param_1 + 0x10,uVar10);
    uVar11 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar11 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar11);
  }
  uVar11 = bVar1 & 7;
  *param_1 = (byte)uVar11;
  iVar17 = 0xf - uVar11;
  if ((bVar1 & 7) == 0) {
    uVar15 = 0;
  }
  else {
    bVar3 = param_1[iVar17];
    iVar8 = 0x10 - uVar11;
    param_1[iVar17] = 0;
    uVar15 = (uint)bVar3 << 8;
    if (iVar8 != 0xf) {
      bVar2 = param_1[iVar8];
      iVar6 = 0x11 - uVar11;
      param_1[iVar8] = 0;
      uVar4 = CONCAT11(bVar3,bVar2);
      uVar15 = (uint)uVar4 << 8;
      if (iVar6 != 0xf) {
        bVar3 = param_1[iVar6];
        iVar8 = 0x12 - uVar11;
        param_1[iVar6] = 0;
        uVar5 = CONCAT21(uVar4,bVar3);
        uVar15 = (uint)uVar5 << 8;
        if (iVar8 != 0xf) {
          bVar3 = param_1[iVar8];
          iVar6 = 0x13 - uVar11;
          param_1[iVar8] = 0;
          uVar15 = CONCAT31(uVar5,bVar3) << 8;
          if (iVar6 != 0xf) {
            bVar3 = param_1[iVar6];
            iVar8 = 0x14 - uVar11;
            param_1[iVar6] = 0;
            uVar15 = (uVar15 | bVar3) << 8;
            if (iVar8 != 0xf) {
              bVar3 = param_1[iVar8];
              param_1[iVar8] = 0;
              uVar15 = (uVar15 | bVar3) << 8;
              if (uVar11 != 6) {
                bVar3 = param_1[0xe];
                param_1[0xe] = 0;
                uVar15 = (uVar15 | bVar3) << 8;
              }
            }
          }
        }
      }
    }
  }
  uVar15 = uVar15 | param_1[0xf];
  param_1[0xf] = 1;
  if (uVar15 != param_4) {
    uVar10 = 0xffffffff;
    goto LAB_001018f6;
  }
  uVar7 = param_4 + 0xf >> 3 | 1;
  iVar8 = *(uint *)(param_1 + 0x20) + uVar7;
  uVar7 = *(int *)(param_1 + 0x24) + (uint)CARRY4(*(uint *)(param_1 + 0x20),uVar7);
  *(int *)(param_1 + 0x20) = iVar8;
  *(uint *)(param_1 + 0x24) = uVar7;
  bVar19 = 0x1fffffff < uVar7;
  if (uVar7 == 0x20000000) {
    bVar19 = iVar8 != 0;
  }
  if (bVar19) {
    uVar10 = 0xfffffffe;
    goto LAB_001018f6;
  }
  if (param_4 >> 4 == 0) {
    if (param_4 != 0) {
LAB_001016d6:
      puVar13 = (uint *)(param_1 + 0x10);
      puVar16 = param_2 + 1;
      bVar19 = 5 < uVar15;
      bVar20 = param_2 <= param_1 + 0x14;
      bVar18 = (uint *)(param_1 + 0x14) == param_2;
      if (bVar20 && !bVar18) {
        bVar20 = puVar13 <= puVar16;
        bVar18 = puVar16 == puVar13;
      }
      if (!bVar19 || (bVar20 && !bVar18 || ((uint)param_2 & 3) != 0)) {
        param_1[0x10] = param_1[0x10] ^ *(byte *)param_2;
        if (((((1 < uVar15) &&
              (param_1[0x11] = param_1[0x11] ^ *(byte *)((int)param_2 + 1), 2 < uVar15)) &&
             (param_1[0x12] = param_1[0x12] ^ *(byte *)((int)param_2 + 2), 3 < uVar15)) &&
            (((((param_1[0x13] = param_1[0x13] ^ *(byte *)((int)param_2 + 3), 4 < uVar15 &&
                (param_1[0x14] = param_1[0x14] ^ *(byte *)(param_2 + 1), bVar19)) &&
               ((param_1[0x15] = param_1[0x15] ^ *(byte *)((int)param_2 + 5), 6 < uVar15 &&
                ((param_1[0x16] = param_1[0x16] ^ *(byte *)((int)param_2 + 6), 7 < uVar15 &&
                 (param_1[0x17] = param_1[0x17] ^ *(byte *)((int)param_2 + 7), 8 < uVar15)))))) &&
              (param_1[0x18] = param_1[0x18] ^ *(byte *)(param_2 + 2), 9 < uVar15)) &&
             (((param_1[0x19] = param_1[0x19] ^ *(byte *)((int)param_2 + 9), 10 < uVar15 &&
               (param_1[0x1a] = param_1[0x1a] ^ *(byte *)((int)param_2 + 10), 0xb < uVar15)) &&
              (param_1[0x1b] = param_1[0x1b] ^ *(byte *)((int)param_2 + 0xb), 0xc < uVar15)))))) &&
           (((param_1[0x1c] = param_1[0x1c] ^ *(byte *)(param_2 + 3), 0xd < uVar15 &&
             (param_1[0x1d] = param_1[0x1d] ^ *(byte *)((int)param_2 + 0xd), 0xe < uVar15)) &&
            (param_1[0x1e] = param_1[0x1e] ^ *(byte *)((int)param_2 + 0xe), 0xf < uVar15)))) {
          param_1[0x1f] = param_1[0x1f] ^ *(byte *)((int)param_2 + 0xf);
        }
      }
      else {
        uVar7 = uVar15;
        if (uVar15 == 0) {
          uVar7 = 1;
        }
        uVar9 = uVar7 >> 2;
        uVar14 = uVar7 & 0xfffffffc;
        if (uVar9 == 0) {
          uVar9 = 1;
          param_1[0x10] = param_1[0x10] ^ *(byte *)param_2;
LAB_00101768:
          param_1[uVar9 + 0x10] = *(byte *)((int)param_2 + uVar9) ^ param_1[uVar9 + 0x10];
          if (uVar9 + 1 < uVar15) {
            param_1[uVar9 + 0x11] = param_1[uVar9 + 0x11] ^ *(byte *)((int)param_2 + uVar9 + 1);
          }
        }
        else {
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ *param_2;
          if (((1 < uVar9) &&
              (*(uint *)(param_1 + 0x14) = param_2[1] ^ *(uint *)(param_1 + 0x14), 2 < uVar9)) &&
             (*(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ param_2[2], 3 < uVar9)) {
            *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ param_2[3];
          }
          if (uVar7 != uVar14) {
            uVar9 = uVar14 + 1;
            param_1[uVar14 + 0x10] =
                 *(byte *)((int)param_2 + (uVar7 & 0xfffffffc)) ^ param_1[uVar14 + 0x10];
            if (uVar9 < uVar15) goto LAB_00101768;
          }
        }
      }
      (*pcVar12)(puVar13,puVar13,uVar10);
      (*pcVar12)(param_1,&local_40,uVar10);
      puVar13 = param_3 + 1;
      bVar20 = param_3 <= &local_3c;
      bVar18 = &local_3c == param_3;
      if (bVar20 && !bVar18) {
        bVar20 = &local_40 <= puVar13;
        bVar18 = puVar13 == &local_40;
      }
      if ((((uint)param_3 | (uint)param_2) & 3) != 0 ||
          ((param_2 < puVar13 && param_3 < puVar16 || bVar20 && !bVar18) || 6 >= uVar15)) {
        *(byte *)param_3 = (byte)local_40 ^ *(byte *)param_2;
        if (1 < uVar15) {
          *(byte *)((int)param_3 + 1) = local_40._1_1_ ^ *(byte *)((int)param_2 + 1);
          if (2 < uVar15) {
            *(byte *)((int)param_3 + 2) = local_40._2_1_ ^ *(byte *)((int)param_2 + 2);
            if (3 < uVar15) {
              *(byte *)((int)param_3 + 3) = local_40._3_1_ ^ *(byte *)((int)param_2 + 3);
              if (4 < uVar15) {
                *(byte *)(param_3 + 1) = (byte)local_3c ^ *(byte *)(param_2 + 1);
                if (bVar19) {
                  *(byte *)((int)param_3 + 5) = local_3c._1_1_ ^ *(byte *)((int)param_2 + 5);
                  if (6 < uVar15) {
                    *(byte *)((int)param_3 + 6) = local_3c._2_1_ ^ *(byte *)((int)param_2 + 6);
                    if (7 < uVar15) {
                      *(byte *)((int)param_3 + 7) = local_3c._3_1_ ^ *(byte *)((int)param_2 + 7);
                      if (8 < uVar15) {
                        *(byte *)(param_3 + 2) = (byte)local_38 ^ *(byte *)(param_2 + 2);
                        if (9 < uVar15) {
                          *(byte *)((int)param_3 + 9) = local_38._1_1_ ^ *(byte *)((int)param_2 + 9)
                          ;
                          if (10 < uVar15) {
                            *(byte *)((int)param_3 + 10) =
                                 local_38._2_1_ ^ *(byte *)((int)param_2 + 10);
                            if (0xb < uVar15) {
                              *(byte *)((int)param_3 + 0xb) =
                                   local_38._3_1_ ^ *(byte *)((int)param_2 + 0xb);
                              if (0xc < uVar15) {
                                *(byte *)(param_3 + 3) = (byte)local_34 ^ *(byte *)(param_2 + 3);
                                if (0xd < uVar15) {
                                  *(byte *)((int)param_3 + 0xd) =
                                       local_34._1_1_ ^ *(byte *)((int)param_2 + 0xd);
                                  if (0xe < uVar15) {
                                    *(byte *)((int)param_3 + 0xe) =
                                         local_34._2_1_ ^ *(byte *)((int)param_2 + 0xe);
                                    if (0xf < uVar15) {
                                      *(byte *)((int)param_3 + 0xf) =
                                           local_34._3_1_ ^ *(byte *)((int)param_2 + 0xf);
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
        uVar7 = uVar15;
        if (uVar15 == 0) {
          uVar7 = 1;
        }
        uVar9 = uVar7 >> 2;
        uVar14 = uVar7 & 0xfffffffc;
        if (uVar9 == 0) {
          uVar9 = 1;
          *(byte *)param_3 = (byte)local_40 ^ *(byte *)param_2;
LAB_0010185c:
          uVar7 = uVar9 + 1;
          *(byte *)((int)param_3 + uVar9) =
               *(byte *)((int)&local_40 + uVar9) ^ *(byte *)((int)param_2 + uVar9);
          if (uVar7 < uVar15) {
            *(byte *)((int)param_3 + uVar7) =
                 *(byte *)((int)&local_40 + uVar9 + 1) ^ *(byte *)((int)param_2 + uVar7);
          }
        }
        else {
          *param_3 = local_40 ^ *param_2;
          if (((1 < uVar9) && (param_3[1] = local_3c ^ param_2[1], 2 < uVar9)) &&
             (param_3[2] = local_38 ^ param_2[2], 3 < uVar9)) {
            param_3[3] = local_34 ^ param_2[3];
          }
          if (uVar14 != uVar7) {
            uVar9 = uVar14 + 1;
            *(byte *)((int)param_3 + (uVar7 & 0xfffffffc)) =
                 *(byte *)((int)param_2 + (uVar7 & 0xfffffffc)) ^ *(byte *)((int)&local_40 + uVar14)
            ;
            if (uVar9 < uVar15) goto LAB_0010185c;
          }
        }
      }
    }
  }
  else {
    uVar7 = param_4 & 0xfffffff0;
    (*param_5)(param_2,param_3,param_4 >> 4,uVar10,param_1,param_1 + 0x10);
    uVar15 = param_4 - uVar7;
    if (uVar15 != 0) {
      uVar9 = ((uVar7 << 0x14) >> 0x18) + (uint)param_1[0xf];
      param_1[0xf] = (byte)uVar9;
      uVar9 = uVar9 >> 8;
      if ((uVar9 | param_4 >> 0xc) != 0) {
        uVar9 = uVar9 + (uint)param_1[0xe] + (param_4 >> 0xc & 0xff);
        param_1[0xe] = (byte)uVar9;
        uVar9 = uVar9 >> 8;
        if ((uVar9 | param_4 >> 0x14) != 0) {
          uVar9 = uVar9 + (uint)param_1[0xd] + (param_4 >> 0x14 & 0xff);
          param_1[0xd] = (byte)uVar9;
          uVar9 = uVar9 >> 8;
          if ((uVar9 | param_4 >> 0x1c) != 0) {
            uVar9 = (param_4 >> 0x1c) + (uint)param_1[0xc] + uVar9;
            param_1[0xc] = (byte)uVar9;
            uVar9 = uVar9 >> 8;
            if (uVar9 != 0) {
              uVar9 = uVar9 + param_1[0xb];
              param_1[0xb] = (byte)uVar9;
              uVar9 = uVar9 >> 8;
              if (uVar9 != 0) {
                uVar9 = uVar9 + param_1[10];
                param_1[10] = (byte)uVar9;
                uVar9 = uVar9 >> 8;
                if (uVar9 != 0) {
                  uVar9 = uVar9 + param_1[9];
                  param_1[9] = (byte)uVar9;
                  if (uVar9 >> 8 != 0) {
                    param_1[8] = (char)(uVar9 >> 8) + param_1[8];
                  }
                }
              }
            }
          }
        }
      }
      param_2 = (uint *)((int)param_2 + uVar7);
      param_3 = (uint *)((int)param_3 + uVar7);
      goto LAB_001016d6;
    }
  }
  memset(param_1 + iVar17,0,uVar11 + 1);
  (*pcVar12)(param_1,&local_40,uVar10);
  uVar10 = 0;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_40;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_3c;
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_34;
LAB_001018f6:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}

