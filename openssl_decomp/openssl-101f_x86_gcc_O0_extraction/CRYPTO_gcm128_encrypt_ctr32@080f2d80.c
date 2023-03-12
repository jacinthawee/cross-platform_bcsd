
undefined4
CRYPTO_gcm128_encrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  int local_2c;
  uint *local_24;
  
  uVar2 = *(undefined4 *)(param_1 + 0x174);
  uVar4 = param_4 + *(uint *)(param_1 + 0x38);
  uVar7 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(param_4,*(uint *)(param_1 + 0x38));
  if (0xf < uVar7) {
    return 0xffffffff;
  }
  if (uVar7 < 0xf) {
    *(uint *)(param_1 + 0x3c) = uVar7;
    iVar3 = *(int *)(param_1 + 0x16c);
    *(uint *)(param_1 + 0x38) = uVar4;
  }
  else {
    if (0xffffffe0 < uVar4) {
      return 0xffffffff;
    }
    *(uint *)(param_1 + 0x3c) = uVar7;
    iVar3 = *(int *)(param_1 + 0x16c);
    *(uint *)(param_1 + 0x38) = uVar4;
  }
  if (iVar3 != 0) {
    gcm_gmult_4bit();
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  uVar4 = *(uint *)(param_1 + 0xc);
  uVar7 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
  uVar4 = *(uint *)(param_1 + 0x168);
  if (uVar4 != 0) {
    puVar8 = param_3;
    puVar9 = param_2;
    if (param_4 == 0) {
LAB_080f2e20:
      *(uint *)(param_1 + 0x168) = uVar4;
      return 0;
    }
    do {
      param_2 = (uint *)((int)puVar9 + 1);
      param_3 = (uint *)((int)puVar8 + 1);
      bVar6 = *(byte *)puVar9 ^ *(byte *)(param_1 + 0x10 + uVar4);
      param_4 = param_4 - 1;
      *(byte *)puVar8 = bVar6;
      pbVar1 = (byte *)(param_1 + 0x40 + uVar4);
      *pbVar1 = *pbVar1 ^ bVar6;
      uVar4 = uVar4 + 1 & 0xf;
      if (uVar4 == 0) break;
      puVar8 = param_3;
      puVar9 = param_2;
    } while (param_4 != 0);
    if (uVar4 != 0) goto LAB_080f2e20;
    gcm_gmult_4bit();
  }
  for (; 0xbff < param_4; param_4 = param_4 - 0xc00) {
    (*param_5)(param_2,param_3,0xc0,uVar2,param_1);
    uVar7 = uVar7 + 0xc0;
    param_3 = param_3 + 0x300;
    *(uint *)(param_1 + 0xc) =
         uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
    gcm_ghash_4bit(0xc00);
    param_2 = param_2 + 0x300;
  }
  uVar4 = param_4 & 0xfffffff0;
  if (uVar4 == 0) {
    if (param_4 != 0) {
      (**(code **)(param_1 + 0x170))(param_1,param_1 + 0x10,uVar2);
      uVar7 = uVar7 + 1;
      *(uint *)(param_1 + 0xc) =
           uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
LAB_080f2fa5:
      local_24 = (uint *)(param_1 + 0x40);
      local_2c = param_4 - 1;
      if (((param_4 < 5 ||
           (param_3 < (uint *)(param_1 + 0x44U) && (uint *)(param_1 + 0x10) < param_3 + 1 ||
           local_24 < param_2 + 1 && param_2 < (uint *)(param_1 + 0x44U))) ||
           param_3 < param_2 + 1 && param_2 < param_3 + 1) ||
         ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
        bVar6 = *(byte *)(param_1 + 0x10) ^ *(byte *)param_2;
        *(byte *)param_3 = bVar6;
        *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) ^ bVar6;
        if (local_2c != 0) {
          bVar6 = *(byte *)((int)param_2 + 1) ^ *(byte *)(param_1 + 0x11);
          *(byte *)((int)param_3 + 1) = bVar6;
          *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) ^ bVar6;
          if (local_2c != 1) {
            bVar6 = *(byte *)((int)param_2 + 2) ^ *(byte *)(param_1 + 0x12);
            *(byte *)((int)param_3 + 2) = bVar6;
            *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) ^ bVar6;
            if (local_2c != 2) {
              bVar6 = *(byte *)((int)param_2 + 3) ^ *(byte *)(param_1 + 0x13);
              *(byte *)((int)param_3 + 3) = bVar6;
              *(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) ^ bVar6;
              if (local_2c != 3) {
                bVar6 = *(byte *)(param_2 + 1) ^ *(byte *)(param_1 + 0x14);
                *(byte *)(param_3 + 1) = bVar6;
                *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) ^ bVar6;
                if (local_2c != 4) {
                  bVar6 = *(byte *)((int)param_2 + 5) ^ *(byte *)(param_1 + 0x15);
                  *(byte *)((int)param_3 + 5) = bVar6;
                  *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) ^ bVar6;
                  if (local_2c != 5) {
                    bVar6 = *(byte *)((int)param_2 + 6) ^ *(byte *)(param_1 + 0x16);
                    *(byte *)((int)param_3 + 6) = bVar6;
                    *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) ^ bVar6;
                    if (local_2c != 6) {
                      bVar6 = *(byte *)((int)param_2 + 7) ^ *(byte *)(param_1 + 0x17);
                      *(byte *)((int)param_3 + 7) = bVar6;
                      *(byte *)(param_1 + 0x47) = *(byte *)(param_1 + 0x47) ^ bVar6;
                      if (local_2c != 7) {
                        bVar6 = *(byte *)(param_2 + 2) ^ *(byte *)(param_1 + 0x18);
                        *(byte *)(param_3 + 2) = bVar6;
                        *(byte *)(param_1 + 0x48) = *(byte *)(param_1 + 0x48) ^ bVar6;
                        if (local_2c != 8) {
                          bVar6 = *(byte *)((int)param_2 + 9) ^ *(byte *)(param_1 + 0x19);
                          *(byte *)((int)param_3 + 9) = bVar6;
                          *(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) ^ bVar6;
                          if (local_2c != 9) {
                            bVar6 = *(byte *)((int)param_2 + 10) ^ *(byte *)(param_1 + 0x1a);
                            *(byte *)((int)param_3 + 10) = bVar6;
                            *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) ^ bVar6;
                            if (local_2c != 10) {
                              bVar6 = *(byte *)((int)param_2 + 0xb) ^ *(byte *)(param_1 + 0x1b);
                              *(byte *)((int)param_3 + 0xb) = bVar6;
                              *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) ^ bVar6;
                              if (local_2c != 0xb) {
                                bVar6 = *(byte *)(param_2 + 3) ^ *(byte *)(param_1 + 0x1c);
                                *(byte *)(param_3 + 3) = bVar6;
                                *(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) ^ bVar6;
                                if (local_2c != 0xc) {
                                  bVar6 = *(byte *)((int)param_2 + 0xd) ^ *(byte *)(param_1 + 0x1d);
                                  *(byte *)((int)param_3 + 0xd) = bVar6;
                                  *(byte *)(param_1 + 0x4d) = *(byte *)(param_1 + 0x4d) ^ bVar6;
                                  if (local_2c != 0xd) {
                                    bVar6 = *(byte *)((int)param_2 + 0xe) ^
                                            *(byte *)(param_1 + 0x1e);
                                    *(byte *)((int)param_3 + 0xe) = bVar6;
                                    *(byte *)(param_1 + 0x4e) = *(byte *)(param_1 + 0x4e) ^ bVar6;
                                    if (local_2c != 0xe) {
                                      bVar6 = *(byte *)(param_1 + 0x1f) ^
                                              *(byte *)((int)param_2 + 0xf);
                                      *(byte *)((int)param_3 + 0xf) = bVar6;
                                      *(byte *)(param_1 + 0x4f) = *(byte *)(param_1 + 0x4f) ^ bVar6;
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
        uVar4 = *(uint *)(param_1 + 0x10) ^ *param_2;
        iVar5 = (param_4 - 4 >> 2) + 1;
        *param_3 = uVar4;
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ uVar4;
        iVar3 = iVar5 * 4;
        if (iVar5 != 1) {
          uVar4 = *(uint *)(param_1 + 0x14) ^ param_2[1];
          param_3[1] = uVar4;
          *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ uVar4;
          if (iVar5 != 2) {
            uVar4 = param_2[2] ^ *(uint *)(param_1 + 0x18);
            param_3[2] = uVar4;
            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ uVar4;
            if (iVar5 != 3) {
              uVar4 = param_2[3] ^ *(uint *)(param_1 + 0x1c);
              param_3[3] = uVar4;
              *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ uVar4;
            }
          }
        }
        local_2c = local_2c + iVar5 * -4;
        if (iVar3 - param_4 != 0) {
          bVar6 = *(byte *)(param_2 + iVar5) ^ *(byte *)(param_1 + 0x10 + iVar3);
          *(byte *)(param_3 + iVar5) = bVar6;
          pbVar1 = (byte *)(param_1 + 0x40 + iVar3);
          *pbVar1 = *pbVar1 ^ bVar6;
          if (local_2c != 0) {
            bVar6 = *(byte *)((int)param_2 + iVar3 + 1) ^ *(byte *)(param_1 + 0x11 + iVar3);
            *(byte *)((int)param_3 + iVar3 + 1) = bVar6;
            pbVar1 = (byte *)(param_1 + iVar3 + 0x41);
            *pbVar1 = *pbVar1 ^ bVar6;
            if (local_2c != 1) {
              bVar6 = *(byte *)((int)param_2 + iVar3 + 2) ^ *(byte *)(param_1 + 0x10 + iVar3 + 2);
              *(byte *)((int)param_3 + iVar3 + 2) = bVar6;
              pbVar1 = (byte *)(param_1 + 0x40 + iVar3 + 2);
              *pbVar1 = *pbVar1 ^ bVar6;
            }
          }
        }
      }
      goto LAB_080f2ec5;
    }
  }
  else {
    (*param_5)(param_2,param_3,param_4 >> 4,uVar2,param_1);
    uVar7 = uVar7 + (param_4 >> 4);
    *(uint *)(param_1 + 0xc) =
         uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
    param_4 = param_4 - uVar4;
    gcm_ghash_4bit(uVar4);
    if (param_4 != 0) {
      param_2 = (uint *)((int)param_2 + uVar4);
      param_3 = (uint *)((int)param_3 + uVar4);
      (**(code **)(param_1 + 0x170))(param_1,param_1 + 0x10,uVar2);
      uVar7 = uVar7 + 1;
      *(uint *)(param_1 + 0xc) =
           uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
      goto LAB_080f2fa5;
    }
  }
  param_4 = 0;
LAB_080f2ec5:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}

