
undefined4 CRYPTO_gcm128_decrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  uint local_38;
  uint *local_28;
  
  pcVar3 = *(code **)(param_1 + 0x170);
  uVar4 = *(undefined4 *)(param_1 + 0x174);
  uVar6 = param_4 + *(uint *)(param_1 + 0x38);
  uVar10 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(param_4,*(uint *)(param_1 + 0x38));
  if ((0xf < uVar10) || ((0xe < uVar10 && (0xffffffe0 < uVar6)))) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar6;
  *(uint *)(param_1 + 0x3c) = uVar10;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit();
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  uVar6 = *(uint *)(param_1 + 0x168);
  uVar10 = *(uint *)(param_1 + 0xc);
  uVar10 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
  if (uVar6 != 0) {
    if (param_4 == 0) {
LAB_080f0409:
      *(uint *)(param_1 + 0x168) = uVar6;
      return 0;
    }
    do {
      puVar7 = (uint *)((int)param_2 + 1);
      puVar11 = (uint *)((int)param_3 + 1);
      param_4 = param_4 - 1;
      bVar2 = *(byte *)param_2;
      *(byte *)param_3 = bVar2 ^ *(byte *)(param_1 + 0x10 + uVar6);
      pbVar1 = (byte *)(param_1 + 0x40 + uVar6);
      *pbVar1 = *pbVar1 ^ bVar2;
      uVar6 = uVar6 + 1 & 0xf;
      param_3 = puVar11;
      param_2 = puVar7;
      if (uVar6 == 0) break;
    } while (param_4 != 0);
    if (uVar6 != 0) goto LAB_080f0409;
    gcm_gmult_4bit();
  }
  local_38 = uVar10;
  if (0xbff < param_4) {
    do {
      gcm_ghash_4bit(0xc00);
      local_38 = uVar10 + 0xc0;
      puVar7 = param_3;
      puVar11 = param_2;
      do {
        uVar10 = uVar10 + 1;
        (*pcVar3)(param_1,param_1 + 0x10,uVar4);
        *(uint *)(param_1 + 0xc) =
             uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 * 0x1000000
        ;
        *puVar7 = *puVar11 ^ *(uint *)(param_1 + 0x10);
        puVar7[1] = puVar11[1] ^ *(uint *)(param_1 + 0x14);
        puVar7[2] = puVar11[2] ^ *(uint *)(param_1 + 0x18);
        puVar7[3] = puVar11[3] ^ *(uint *)(param_1 + 0x1c);
        puVar7 = puVar7 + 4;
        puVar11 = puVar11 + 4;
      } while (uVar10 != local_38);
      param_4 = param_4 - 0xc00;
      param_3 = param_3 + 0x300;
      param_2 = param_2 + 0x300;
    } while (0xbff < param_4);
  }
  if ((param_4 & 0xfffffff0) == 0) {
    if (param_4 != 0) {
      (*pcVar3)(param_1,param_1 + 0x10,uVar4);
      local_38 = local_38 + 1;
      *(uint *)(param_1 + 0xc) =
           local_38 >> 0x18 | (local_38 & 0xff0000) >> 8 | (local_38 & 0xff00) << 8 |
           local_38 * 0x1000000;
      iVar8 = param_4 - 1;
LAB_080f0619:
      local_28 = (uint *)(param_1 + 0x40);
      uVar6 = iVar8 + 1;
      if (((((uint *)(param_1 + 0x10) < param_3 + 1 && param_3 < (uint *)(param_1 + 0x44U) ||
            param_2 < (uint *)(param_1 + 0x44U) && local_28 < param_2 + 1) || uVar6 < 5) ||
           param_2 < param_3 + 1 && param_3 < param_2 + 1) ||
         ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
        bVar2 = *(byte *)param_2;
        *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) ^ bVar2;
        *(byte *)param_3 = bVar2 ^ *(byte *)(param_1 + 0x10);
        if (iVar8 != 0) {
          bVar2 = *(byte *)((int)param_2 + 1);
          *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) ^ bVar2;
          *(byte *)((int)param_3 + 1) = bVar2 ^ *(byte *)(param_1 + 0x11);
          if (iVar8 != 1) {
            bVar2 = *(byte *)((int)param_2 + 2);
            *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) ^ bVar2;
            *(byte *)((int)param_3 + 2) = bVar2 ^ *(byte *)(param_1 + 0x12);
            if (iVar8 != 2) {
              bVar2 = *(byte *)((int)param_2 + 3);
              *(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) ^ bVar2;
              *(byte *)((int)param_3 + 3) = bVar2 ^ *(byte *)(param_1 + 0x13);
              if (iVar8 != 3) {
                bVar2 = *(byte *)(param_2 + 1);
                *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) ^ bVar2;
                *(byte *)(param_3 + 1) = bVar2 ^ *(byte *)(param_1 + 0x14);
                if (iVar8 != 4) {
                  bVar2 = *(byte *)((int)param_2 + 5);
                  *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) ^ bVar2;
                  *(byte *)((int)param_3 + 5) = bVar2 ^ *(byte *)(param_1 + 0x15);
                  if (iVar8 != 5) {
                    bVar2 = *(byte *)((int)param_2 + 6);
                    *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) ^ bVar2;
                    *(byte *)((int)param_3 + 6) = bVar2 ^ *(byte *)(param_1 + 0x16);
                    if (iVar8 != 6) {
                      bVar2 = *(byte *)((int)param_2 + 7);
                      *(byte *)(param_1 + 0x47) = *(byte *)(param_1 + 0x47) ^ bVar2;
                      *(byte *)((int)param_3 + 7) = bVar2 ^ *(byte *)(param_1 + 0x17);
                      if (iVar8 != 7) {
                        bVar2 = *(byte *)(param_2 + 2);
                        *(byte *)(param_1 + 0x48) = *(byte *)(param_1 + 0x48) ^ bVar2;
                        *(byte *)(param_3 + 2) = bVar2 ^ *(byte *)(param_1 + 0x18);
                        if (iVar8 != 8) {
                          bVar2 = *(byte *)((int)param_2 + 9);
                          *(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) ^ bVar2;
                          *(byte *)((int)param_3 + 9) = bVar2 ^ *(byte *)(param_1 + 0x19);
                          if (iVar8 != 9) {
                            bVar2 = *(byte *)((int)param_2 + 10);
                            *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) ^ bVar2;
                            *(byte *)((int)param_3 + 10) = bVar2 ^ *(byte *)(param_1 + 0x1a);
                            if (iVar8 != 10) {
                              bVar2 = *(byte *)((int)param_2 + 0xb);
                              *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) ^ bVar2;
                              *(byte *)((int)param_3 + 0xb) = bVar2 ^ *(byte *)(param_1 + 0x1b);
                              if (iVar8 != 0xb) {
                                bVar2 = *(byte *)(param_2 + 3);
                                *(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) ^ bVar2;
                                *(byte *)(param_3 + 3) = bVar2 ^ *(byte *)(param_1 + 0x1c);
                                if (iVar8 != 0xc) {
                                  bVar2 = *(byte *)((int)param_2 + 0xd);
                                  *(byte *)(param_1 + 0x4d) = *(byte *)(param_1 + 0x4d) ^ bVar2;
                                  *(byte *)((int)param_3 + 0xd) = bVar2 ^ *(byte *)(param_1 + 0x1d);
                                  if (iVar8 != 0xd) {
                                    bVar2 = *(byte *)((int)param_2 + 0xe);
                                    *(byte *)(param_1 + 0x4e) = *(byte *)(param_1 + 0x4e) ^ bVar2;
                                    *(byte *)((int)param_3 + 0xe) =
                                         bVar2 ^ *(byte *)(param_1 + 0x1e);
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
        uVar5 = *param_2;
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ uVar5;
        iVar9 = (iVar8 - 3U >> 2) + 1;
        uVar10 = iVar9 * 4;
        *param_3 = uVar5 ^ *(uint *)(param_1 + 0x10);
        if (iVar9 != 1) {
          uVar5 = param_2[1];
          *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ uVar5;
          param_3[1] = uVar5 ^ *(uint *)(param_1 + 0x14);
          if (iVar9 == 3) {
            uVar5 = param_2[2];
            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ uVar5;
            param_3[2] = uVar5 ^ *(uint *)(param_1 + 0x18);
          }
        }
        iVar8 = iVar8 + iVar9 * -4;
        if (uVar6 != uVar10) {
          bVar2 = *(byte *)(param_2 + iVar9);
          pbVar1 = (byte *)(param_1 + 0x40 + uVar10);
          *pbVar1 = *pbVar1 ^ bVar2;
          *(byte *)(param_3 + iVar9) = bVar2 ^ *(byte *)(param_1 + 0x10 + uVar10);
          if (iVar8 != 0) {
            bVar2 = *(byte *)((int)param_2 + uVar10 + 1);
            pbVar1 = (byte *)(param_1 + 0x40 + uVar10 + 1);
            *pbVar1 = *pbVar1 ^ bVar2;
            *(byte *)((int)param_3 + uVar10 + 1) = bVar2 ^ *(byte *)(param_1 + 0x10 + uVar10 + 1);
            if (iVar8 != 1) {
              bVar2 = *(byte *)((int)param_2 + uVar10 + 2);
              pbVar1 = (byte *)(param_1 + 0x40 + uVar10 + 2);
              *pbVar1 = *pbVar1 ^ bVar2;
              *(byte *)((int)param_3 + uVar10 + 2) = bVar2 ^ *(byte *)(param_1 + 0x10 + uVar10 + 2);
            }
          }
        }
      }
      goto LAB_080f0516;
    }
  }
  else {
    gcm_ghash_4bit(param_4 & 0xfffffff0);
    uVar10 = param_4 - 0x10 >> 4;
    puVar7 = param_3;
    uVar6 = local_38;
    puVar11 = param_2;
    do {
      (*pcVar3)(param_1,param_1 + 0x10,uVar4);
      uVar6 = uVar6 + 1;
      *(uint *)(param_1 + 0xc) =
           uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 * 0x1000000;
      *puVar7 = *puVar11 ^ *(uint *)(param_1 + 0x10);
      puVar7[1] = puVar11[1] ^ *(uint *)(param_1 + 0x14);
      puVar7[2] = puVar11[2] ^ *(uint *)(param_1 + 0x18);
      puVar7[3] = puVar11[3] ^ *(uint *)(param_1 + 0x1c);
      puVar7 = puVar7 + 4;
      puVar11 = puVar11 + 4;
    } while (uVar6 != local_38 + 1 + uVar10);
    param_3 = param_3 + (uVar10 + 1) * 4;
    param_2 = param_2 + (uVar10 + 1) * 4;
    if ((param_4 & 0xf) != 0) {
      (*pcVar3)(param_1,param_1 + 0x10,uVar4);
      uVar10 = local_38 + 2 + uVar10;
      *(uint *)(param_1 + 0xc) =
           uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 * 0x1000000;
      iVar8 = (param_4 - 0x11) - (param_4 - 0x10 & 0xfffffff0);
      goto LAB_080f0619;
    }
  }
  uVar6 = 0;
LAB_080f0516:
  *(uint *)(param_1 + 0x168) = uVar6;
  return 0;
}

