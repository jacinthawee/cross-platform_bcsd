
undefined4 CRYPTO_gcm128_encrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte *pbVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  uint local_30;
  uint local_2c;
  uint *local_28;
  
  pcVar2 = *(code **)(param_1 + 0x170);
  uVar3 = *(undefined4 *)(param_1 + 0x174);
  uVar4 = param_4 + *(uint *)(param_1 + 0x38);
  uVar9 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(param_4,*(uint *)(param_1 + 0x38));
  if ((0xf < uVar9) || ((0xe < uVar9 && (0xffffffe0 < uVar4)))) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar4;
  *(uint *)(param_1 + 0x3c) = uVar9;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit();
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  uVar4 = *(uint *)(param_1 + 0xc);
  local_2c = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
  uVar4 = *(uint *)(param_1 + 0x168);
  if (uVar4 != 0) {
    if (param_4 == 0) {
LAB_080f2269:
      *(uint *)(param_1 + 0x168) = uVar4;
      return 0;
    }
    do {
      puVar6 = (uint *)((int)param_2 + 1);
      puVar10 = (uint *)((int)param_3 + 1);
      bVar8 = *(byte *)param_2 ^ *(byte *)(param_1 + 0x10 + uVar4);
      param_4 = param_4 - 1;
      *(byte *)param_3 = bVar8;
      pbVar1 = (byte *)(param_1 + 0x40 + uVar4);
      *pbVar1 = *pbVar1 ^ bVar8;
      uVar4 = uVar4 + 1 & 0xf;
      param_2 = puVar6;
      param_3 = puVar10;
      if (uVar4 == 0) break;
    } while (param_4 != 0);
    if (uVar4 != 0) goto LAB_080f2269;
    gcm_gmult_4bit();
  }
  puVar6 = param_2;
  if (0xbff < param_4) {
    do {
      puVar6 = param_2 + 0x300;
      puVar10 = param_2;
      uVar4 = local_2c;
      puVar12 = param_3;
      do {
        uVar4 = uVar4 + 1;
        param_2 = puVar10 + 4;
        (*pcVar2)(param_1,param_1 + 0x10,uVar3);
        *(uint *)(param_1 + 0xc) =
             uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 * 0x1000000;
        *puVar12 = *puVar10 ^ *(uint *)(param_1 + 0x10);
        puVar12[1] = puVar10[1] ^ *(uint *)(param_1 + 0x14);
        puVar12[2] = puVar10[2] ^ *(uint *)(param_1 + 0x18);
        puVar12[3] = puVar10[3] ^ *(uint *)(param_1 + 0x1c);
        puVar10 = param_2;
        puVar12 = puVar12 + 4;
      } while (param_2 != puVar6);
      param_3 = param_3 + 0x300;
      local_2c = local_2c + 0xc0;
      gcm_ghash_4bit(0xc00);
      param_4 = param_4 - 0xc00;
    } while (0xbff < param_4);
  }
  param_2 = puVar6;
  if ((param_4 & 0xfffffff0) == 0) {
    if (param_4 != 0) {
      (*pcVar2)(param_1,param_1 + 0x10,uVar3);
      local_2c = local_2c + 1;
      *(uint *)(param_1 + 0xc) =
           local_2c >> 0x18 | (local_2c & 0xff0000) >> 8 | (local_2c & 0xff00) << 8 |
           local_2c * 0x1000000;
      iVar5 = param_4 - 1;
      goto LAB_080f2490;
    }
  }
  else {
    uVar4 = param_4 - 0x10 >> 4;
    local_30 = local_2c;
    puVar6 = param_2;
    puVar10 = param_3;
    do {
      (*pcVar2)(param_1,param_1 + 0x10,uVar3);
      local_30 = local_30 + 1;
      *(uint *)(param_1 + 0xc) =
           local_30 >> 0x18 | (local_30 & 0xff0000) >> 8 | (local_30 & 0xff00) << 8 |
           local_30 * 0x1000000;
      *puVar10 = *puVar6 ^ *(uint *)(param_1 + 0x10);
      puVar10[1] = puVar6[1] ^ *(uint *)(param_1 + 0x14);
      puVar10[2] = puVar6[2] ^ *(uint *)(param_1 + 0x18);
      puVar10[3] = puVar6[3] ^ *(uint *)(param_1 + 0x1c);
      puVar6 = puVar6 + 4;
      puVar10 = puVar10 + 4;
    } while (local_30 != local_2c + 1 + uVar4);
    param_3 = param_3 + (uVar4 + 1) * 4;
    param_2 = param_2 + (uVar4 + 1) * 4;
    gcm_ghash_4bit(param_4 & 0xfffffff0);
    if ((param_4 & 0xf) != 0) {
      (*pcVar2)(param_1,param_1 + 0x10,uVar3);
      uVar9 = local_2c + 2 + uVar4;
      *(uint *)(param_1 + 0xc) =
           uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 * 0x1000000;
      iVar5 = (param_4 - 0x11) + uVar4 * -0x10;
LAB_080f2490:
      local_28 = (uint *)(param_1 + 0x40);
      uVar4 = iVar5 + 1;
      if (((((uint *)(param_1 + 0x10) < param_3 + 1 && param_3 < (uint *)(param_1 + 0x44U) ||
            param_2 < (uint *)(param_1 + 0x44U) && local_28 < param_2 + 1) || uVar4 < 5) ||
           param_3 < param_2 + 1 && param_2 < param_3 + 1) ||
         ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
        bVar8 = *(byte *)param_2 ^ *(byte *)(param_1 + 0x10);
        *(byte *)param_3 = bVar8;
        *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) ^ bVar8;
        if (iVar5 != 0) {
          bVar8 = *(byte *)((int)param_2 + 1) ^ *(byte *)(param_1 + 0x11);
          *(byte *)((int)param_3 + 1) = bVar8;
          *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) ^ bVar8;
          if (iVar5 != 1) {
            bVar8 = *(byte *)((int)param_2 + 2) ^ *(byte *)(param_1 + 0x12);
            *(byte *)((int)param_3 + 2) = bVar8;
            *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) ^ bVar8;
            if (iVar5 != 2) {
              bVar8 = *(byte *)((int)param_2 + 3) ^ *(byte *)(param_1 + 0x13);
              *(byte *)((int)param_3 + 3) = bVar8;
              *(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) ^ bVar8;
              if (iVar5 != 3) {
                bVar8 = *(byte *)(param_2 + 1) ^ *(byte *)(param_1 + 0x14);
                *(byte *)(param_3 + 1) = bVar8;
                *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) ^ bVar8;
                if (iVar5 != 4) {
                  bVar8 = *(byte *)((int)param_2 + 5) ^ *(byte *)(param_1 + 0x15);
                  *(byte *)((int)param_3 + 5) = bVar8;
                  *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) ^ bVar8;
                  if (iVar5 != 5) {
                    bVar8 = *(byte *)((int)param_2 + 6) ^ *(byte *)(param_1 + 0x16);
                    *(byte *)((int)param_3 + 6) = bVar8;
                    *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) ^ bVar8;
                    if (iVar5 != 6) {
                      bVar8 = *(byte *)((int)param_2 + 7) ^ *(byte *)(param_1 + 0x17);
                      *(byte *)((int)param_3 + 7) = bVar8;
                      *(byte *)(param_1 + 0x47) = *(byte *)(param_1 + 0x47) ^ bVar8;
                      if (iVar5 != 7) {
                        bVar8 = *(byte *)(param_2 + 2) ^ *(byte *)(param_1 + 0x18);
                        *(byte *)(param_3 + 2) = bVar8;
                        *(byte *)(param_1 + 0x48) = *(byte *)(param_1 + 0x48) ^ bVar8;
                        if (iVar5 != 8) {
                          bVar8 = *(byte *)((int)param_2 + 9) ^ *(byte *)(param_1 + 0x19);
                          *(byte *)((int)param_3 + 9) = bVar8;
                          *(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) ^ bVar8;
                          if (iVar5 != 9) {
                            bVar8 = *(byte *)((int)param_2 + 10) ^ *(byte *)(param_1 + 0x1a);
                            *(byte *)((int)param_3 + 10) = bVar8;
                            *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) ^ bVar8;
                            if (iVar5 != 10) {
                              bVar8 = *(byte *)((int)param_2 + 0xb) ^ *(byte *)(param_1 + 0x1b);
                              *(byte *)((int)param_3 + 0xb) = bVar8;
                              *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) ^ bVar8;
                              if (iVar5 != 0xb) {
                                bVar8 = *(byte *)(param_2 + 3) ^ *(byte *)(param_1 + 0x1c);
                                *(byte *)(param_3 + 3) = bVar8;
                                *(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) ^ bVar8;
                                if (iVar5 != 0xc) {
                                  bVar8 = *(byte *)((int)param_2 + 0xd) ^ *(byte *)(param_1 + 0x1d);
                                  *(byte *)((int)param_3 + 0xd) = bVar8;
                                  *(byte *)(param_1 + 0x4d) = *(byte *)(param_1 + 0x4d) ^ bVar8;
                                  if (iVar5 != 0xd) {
                                    bVar8 = *(byte *)((int)param_2 + 0xe) ^
                                            *(byte *)(param_1 + 0x1e);
                                    *(byte *)((int)param_3 + 0xe) = bVar8;
                                    *(byte *)(param_1 + 0x4e) = *(byte *)(param_1 + 0x4e) ^ bVar8;
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
        uVar11 = *param_2 ^ *(uint *)(param_1 + 0x10);
        iVar7 = (iVar5 - 3U >> 2) + 1;
        uVar9 = iVar7 * 4;
        *param_3 = uVar11;
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ uVar11;
        if (iVar7 != 1) {
          uVar11 = param_2[1] ^ *(uint *)(param_1 + 0x14);
          param_3[1] = uVar11;
          *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ uVar11;
          if (iVar7 == 3) {
            uVar11 = param_2[2] ^ *(uint *)(param_1 + 0x18);
            param_3[2] = uVar11;
            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ uVar11;
          }
        }
        iVar5 = iVar5 + iVar7 * -4;
        if (uVar4 != uVar9) {
          bVar8 = *(byte *)(param_2 + iVar7) ^ *(byte *)(param_1 + 0x10 + uVar9);
          *(byte *)(param_3 + iVar7) = bVar8;
          pbVar1 = (byte *)(param_1 + 0x40 + uVar9);
          *pbVar1 = *pbVar1 ^ bVar8;
          if (iVar5 != 0) {
            bVar8 = *(byte *)((int)param_2 + uVar9 + 1) ^ *(byte *)(param_1 + 0x11 + uVar9);
            *(byte *)((int)param_3 + uVar9 + 1) = bVar8;
            pbVar1 = (byte *)(param_1 + uVar9 + 0x41);
            *pbVar1 = *pbVar1 ^ bVar8;
            if (iVar5 != 1) {
              bVar8 = *(byte *)((int)param_2 + uVar9 + 2) ^ *(byte *)(param_1 + 0x10 + uVar9 + 2);
              *(byte *)((int)param_3 + uVar9 + 2) = bVar8;
              pbVar1 = (byte *)(param_1 + 0x40 + uVar9 + 2);
              *pbVar1 = *pbVar1 ^ bVar8;
            }
          }
        }
      }
      goto LAB_080f245b;
    }
  }
  uVar4 = 0;
LAB_080f245b:
  *(uint *)(param_1 + 0x168) = uVar4;
  return 0;
}

