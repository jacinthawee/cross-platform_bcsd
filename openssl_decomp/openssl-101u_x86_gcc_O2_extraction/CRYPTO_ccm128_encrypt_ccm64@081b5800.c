
/* WARNING: Could not reconcile some variable overlaps */

undefined4
CRYPTO_ccm128_encrypt_ccm64(byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  code *pcVar5;
  ushort uVar6;
  uint3 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int in_GS_OFFSET;
  uint *local_64;
  undefined4 *local_4c;
  uint *local_44;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  pcVar5 = *(code **)(param_1 + 0x28);
  local_64 = param_3;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar2 = *param_1;
  uVar12 = *(undefined4 *)(param_1 + 0x2c);
  if ((bVar2 & 0x40) == 0) {
    (*pcVar5)(param_1,param_1 + 0x10,uVar12);
    puVar1 = (uint *)(param_1 + 0x20);
    uVar16 = *puVar1;
    *puVar1 = *puVar1 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar16);
  }
  uVar16 = (uint)(bVar2 & 7);
  *param_1 = bVar2 & 7;
  iVar8 = 0xf - uVar16;
  if (iVar8 == 0xf) {
    uVar9 = 0;
  }
  else {
    bVar3 = param_1[iVar8];
    param_1[iVar8] = 0;
    iVar14 = 0x10 - uVar16;
    uVar9 = (uint)bVar3 << 8;
    if (iVar14 != 0xf) {
      bVar4 = param_1[iVar14];
      param_1[iVar14] = 0;
      iVar14 = 0x11 - uVar16;
      uVar6 = CONCAT11(bVar3,bVar4);
      uVar9 = (uint)uVar6 << 8;
      if (iVar14 != 0xf) {
        bVar3 = param_1[iVar14];
        param_1[iVar14] = 0;
        iVar14 = 0x12 - uVar16;
        uVar7 = CONCAT21(uVar6,bVar3);
        uVar9 = (uint)uVar7 << 8;
        if (iVar14 != 0xf) {
          bVar3 = param_1[iVar14];
          param_1[iVar14] = 0;
          iVar14 = 0x13 - uVar16;
          uVar9 = CONCAT31(uVar7,bVar3) << 8;
          if (iVar14 != 0xf) {
            bVar3 = param_1[iVar14];
            param_1[iVar14] = 0;
            iVar14 = 0x14 - uVar16;
            uVar9 = (bVar3 | uVar9) << 8;
            if (iVar14 != 0xf) {
              bVar3 = param_1[iVar14];
              param_1[iVar14] = 0;
              uVar9 = (bVar3 | uVar9) << 8;
              if (uVar16 != 6) {
                bVar3 = param_1[0xe];
                param_1[0xe] = 0;
                uVar9 = (bVar3 | uVar9) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar3 = param_1[0xf];
  param_1[0xf] = 1;
  uVar17 = bVar3 | uVar9;
  if (uVar17 != param_4) {
    uVar12 = 0xffffffff;
    goto LAB_081b5b91;
  }
  uVar10 = param_4 + 0xf >> 3 | 1;
  iVar14 = uVar10 + *(uint *)(param_1 + 0x20);
  uVar10 = *(int *)(param_1 + 0x24) + (uint)CARRY4(uVar10,*(uint *)(param_1 + 0x20));
  *(int *)(param_1 + 0x20) = iVar14;
  *(uint *)(param_1 + 0x24) = uVar10;
  if ((0x20000000 < uVar10) || ((0x1fffffff < uVar10 && (iVar14 != 0)))) {
    uVar12 = 0xfffffffe;
    goto LAB_081b5b91;
  }
  uVar10 = uVar17 >> 4;
  if (uVar10 == 0) {
    if (uVar17 != 0) {
LAB_081b597f:
      local_44 = (uint *)(param_1 + 0x10);
      if ((uVar17 < 6 || local_44 < param_2 + 1 && param_2 < param_1 + 0x14) ||
         (((uint)param_2 & 3) != 0)) {
        param_1[0x10] = param_1[0x10] ^ *(byte *)param_2;
        if (((((uVar17 != 1) &&
              (((param_1[0x11] = param_1[0x11] ^ *(byte *)((int)param_2 + 1), uVar17 != 2 &&
                (param_1[0x12] = param_1[0x12] ^ *(byte *)((int)param_2 + 2), uVar17 != 3)) &&
               (param_1[0x13] = param_1[0x13] ^ *(byte *)((int)param_2 + 3), uVar17 != 4)))) &&
             (((param_1[0x14] = param_1[0x14] ^ *(byte *)(param_2 + 1), 5 < uVar17 &&
               (param_1[0x15] = param_1[0x15] ^ *(byte *)((int)param_2 + 5), 6 < uVar17)) &&
              (param_1[0x16] = param_1[0x16] ^ *(byte *)((int)param_2 + 6), uVar17 != 7)))) &&
            ((param_1[0x17] = param_1[0x17] ^ *(byte *)((int)param_2 + 7), uVar17 != 8 &&
             (param_1[0x18] = param_1[0x18] ^ *(byte *)(param_2 + 2), uVar17 != 9)))) &&
           ((param_1[0x19] = param_1[0x19] ^ *(byte *)((int)param_2 + 9), uVar17 != 10 &&
            ((((param_1[0x1a] = param_1[0x1a] ^ *(byte *)((int)param_2 + 10), uVar17 != 0xb &&
               (param_1[0x1b] = param_1[0x1b] ^ *(byte *)((int)param_2 + 0xb), uVar17 != 0xc)) &&
              (param_1[0x1c] = param_1[0x1c] ^ *(byte *)(param_2 + 3), uVar17 != 0xd)) &&
             ((param_1[0x1d] = param_1[0x1d] ^ *(byte *)((int)param_2 + 0xd), uVar17 != 0xe &&
              (param_1[0x1e] = param_1[0x1e] ^ *(byte *)((int)param_2 + 0xe), uVar17 != 0xf))))))))
        {
          param_1[0x1f] = param_1[0x1f] ^ *(byte *)((int)param_2 + 0xf);
        }
      }
      else {
        uVar9 = 1;
        if (uVar17 != 0) {
          uVar9 = uVar17;
        }
        iVar14 = (uVar9 - 4 >> 2) + 1;
        uVar10 = iVar14 * 4;
        if (uVar17 < 4) {
          uVar10 = 0;
        }
        else {
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ *param_2;
          if (((iVar14 != 1) &&
              (*(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ param_2[1], iVar14 != 2)) &&
             (*(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ param_2[2], iVar14 != 3)) {
            *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ param_2[3];
          }
          if (uVar9 == uVar10) goto LAB_081b5a2f;
        }
        param_1[uVar10 + 0x10] = param_1[uVar10 + 0x10] ^ *(byte *)((int)param_2 + uVar10);
        if (uVar10 + 1 < uVar17) {
          param_1[uVar10 + 0x11] = param_1[uVar10 + 0x11] ^ *(byte *)((int)param_2 + uVar10 + 1);
          if (uVar10 + 2 < uVar17) {
            param_1[uVar10 + 0x12] = param_1[uVar10 + 0x12] ^ *(byte *)((int)param_2 + uVar10 + 2);
          }
        }
      }
LAB_081b5a2f:
      (*pcVar5)(local_44,local_44,uVar12);
      (*pcVar5)(param_1,&local_30,uVar12);
      if ((uVar17 < 6 || local_64 < param_2 + 1 && param_2 < local_64 + 1) ||
         ((((uint)local_64 | (uint)param_2) & 3) != 0)) {
        *(byte *)local_64 = (byte)local_30 ^ *(byte *)param_2;
        if (uVar17 != 1) {
          *(byte *)((int)local_64 + 1) = local_30._1_1_ ^ *(byte *)((int)param_2 + 1);
          if (uVar17 != 2) {
            *(byte *)((int)local_64 + 2) = local_30._2_1_ ^ *(byte *)((int)param_2 + 2);
            if (uVar17 != 3) {
              *(byte *)((int)local_64 + 3) = local_30._3_1_ ^ *(byte *)((int)param_2 + 3);
              if (uVar17 != 4) {
                *(byte *)(local_64 + 1) = (byte)local_2c ^ *(byte *)(param_2 + 1);
                if (5 < uVar17) {
                  *(byte *)((int)local_64 + 5) = local_2c._1_1_ ^ *(byte *)((int)param_2 + 5);
                  if (6 < uVar17) {
                    *(byte *)((int)local_64 + 6) = local_2c._2_1_ ^ *(byte *)((int)param_2 + 6);
                    if (uVar17 != 7) {
                      *(byte *)((int)local_64 + 7) = local_2c._3_1_ ^ *(byte *)((int)param_2 + 7);
                      if (uVar17 != 8) {
                        *(byte *)(local_64 + 2) = (byte)local_28 ^ *(byte *)(param_2 + 2);
                        if (uVar17 != 9) {
                          *(byte *)((int)local_64 + 9) =
                               local_28._1_1_ ^ *(byte *)((int)param_2 + 9);
                          if (uVar17 != 10) {
                            *(byte *)((int)local_64 + 10) =
                                 local_28._2_1_ ^ *(byte *)((int)param_2 + 10);
                            if (uVar17 != 0xb) {
                              *(byte *)((int)local_64 + 0xb) =
                                   local_28._3_1_ ^ *(byte *)((int)param_2 + 0xb);
                              if (uVar17 != 0xc) {
                                *(byte *)(local_64 + 3) = (byte)local_24 ^ *(byte *)(param_2 + 3);
                                if (uVar17 != 0xd) {
                                  *(byte *)((int)local_64 + 0xd) =
                                       local_24._1_1_ ^ *(byte *)((int)param_2 + 0xd);
                                  if (uVar17 != 0xe) {
                                    *(byte *)((int)local_64 + 0xe) =
                                         local_24._2_1_ ^ *(byte *)((int)param_2 + 0xe);
                                    if (uVar17 != 0xf) {
                                      *(byte *)((int)local_64 + 0xf) =
                                           *(byte *)((int)param_2 + 0xf) ^ local_24._3_1_;
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
        uVar9 = 1;
        if (uVar17 != 0) {
          uVar9 = uVar17;
        }
        iVar15 = (uVar9 - 4 >> 2) + 1;
        iVar14 = iVar15 * 4;
        if (uVar17 < 4) {
          iVar14 = 0;
        }
        else {
          *local_64 = *param_2 ^ local_30;
          if (((iVar15 != 1) && (local_64[1] = param_2[1] ^ local_2c, iVar15 != 2)) &&
             (local_64[2] = param_2[2] ^ local_28, iVar15 != 3)) {
            local_64[3] = param_2[3] ^ local_24;
          }
          if (iVar14 - uVar9 == 0) goto LAB_081b5b30;
        }
        *(byte *)((int)local_64 + iVar14) =
             *(byte *)((int)param_2 + iVar14) ^ *(byte *)((int)&local_30 + iVar14);
        if (iVar14 + 1U < uVar17) {
          *(byte *)((int)local_64 + iVar14 + 1) =
               *(byte *)((int)param_2 + iVar14 + 1) ^ *(byte *)((int)&local_30 + iVar14 + 1);
          if (iVar14 + 2U < uVar17) {
            *(byte *)((int)local_64 + iVar14 + 2) =
                 *(byte *)((int)param_2 + iVar14 + 2) ^ *(byte *)((int)&local_30 + iVar14 + 2);
          }
        }
      }
    }
  }
  else {
    (*param_5)(param_2,param_3,uVar10,uVar12,param_1,param_1 + 0x10);
    uVar13 = bVar3 & 0xfffffff0 | uVar9;
    local_64 = (uint *)((int)param_3 + uVar13);
    param_2 = (uint *)((int)param_2 + uVar13);
    uVar17 = uVar17 + uVar10 * -0x10;
    if (uVar17 != 0) {
      uVar10 = (uVar10 & 0xff) + (uint)param_1[0xf];
      param_1[0xf] = (byte)uVar10;
      uVar10 = uVar10 >> 8;
      if ((uVar10 | uVar9 >> 0xc) != 0) {
        uVar10 = uVar10 + (uVar9 >> 0xc & 0xff) + (uint)param_1[0xe];
        param_1[0xe] = (byte)uVar10;
        uVar10 = uVar10 >> 8;
        if ((uVar10 | uVar9 >> 0x14) != 0) {
          uVar10 = uVar10 + (uVar9 >> 0x14 & 0xff) + (uint)param_1[0xd];
          param_1[0xd] = (byte)uVar10;
          uVar10 = uVar10 >> 8;
          if ((uVar10 | uVar9 >> 0x1c) != 0) {
            uVar10 = uVar10 + (uVar9 >> 0x1c) + (uint)param_1[0xc];
            param_1[0xc] = (byte)uVar10;
            uVar10 = uVar10 >> 8;
            if (uVar10 != 0) {
              uVar10 = uVar10 + param_1[0xb];
              param_1[0xb] = (byte)uVar10;
              uVar10 = uVar10 >> 8;
              if (uVar10 != 0) {
                uVar10 = param_1[10] + uVar10;
                param_1[10] = (byte)uVar10;
                uVar10 = uVar10 >> 8;
                if (uVar10 != 0) {
                  uVar10 = uVar10 + param_1[9];
                  param_1[9] = (byte)uVar10;
                  if (uVar10 >> 8 != 0) {
                    param_1[8] = param_1[8] + (char)(uVar10 >> 8);
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_081b597f;
    }
  }
LAB_081b5b30:
  local_4c = &local_30;
  uVar9 = 0x10 - iVar8;
  puVar11 = (undefined4 *)(param_1 + (0xf - uVar16));
  if (uVar9 < 4) {
    if ((uVar9 != 0) && (*(undefined *)puVar11 = 0, (uVar9 & 2) != 0)) {
      *(undefined2 *)(param_1 + uVar9 + (0xd - uVar16)) = 0;
    }
  }
  else {
    *puVar11 = 0;
    *(undefined4 *)(param_1 + uVar9 + (0xb - uVar16)) = 0;
    uVar9 = (uint)((int)puVar11 + (uVar9 - ((uint)(param_1 + (0x13 - uVar16)) & 0xfffffffc))) &
            0xfffffffc;
    if (3 < uVar9) {
      uVar17 = 0;
      do {
        *(undefined4 *)(((uint)(param_1 + (0x13 - uVar16)) & 0xfffffffc) + uVar17) = 0;
        uVar17 = uVar17 + 4;
      } while (uVar17 < uVar9);
    }
  }
  (*pcVar5)(param_1,local_4c,uVar12);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_30;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_2c;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_28;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_24;
  *param_1 = bVar2;
  uVar12 = 0;
LAB_081b5b91:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}

