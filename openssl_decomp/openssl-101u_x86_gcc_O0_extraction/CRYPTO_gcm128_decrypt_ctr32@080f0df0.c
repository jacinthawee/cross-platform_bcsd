
undefined4
CRYPTO_gcm128_decrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  int local_30;
  uint *local_28;
  
  uVar3 = *(undefined4 *)(param_1 + 0x174);
  uVar5 = param_4 + *(uint *)(param_1 + 0x38);
  uVar7 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(param_4,*(uint *)(param_1 + 0x38));
  if (0xf < uVar7) {
    return 0xffffffff;
  }
  if (uVar7 < 0xf) {
    *(uint *)(param_1 + 0x3c) = uVar7;
    iVar4 = *(int *)(param_1 + 0x16c);
    *(uint *)(param_1 + 0x38) = uVar5;
  }
  else {
    if (0xffffffe0 < uVar5) {
      return 0xffffffff;
    }
    *(uint *)(param_1 + 0x3c) = uVar7;
    iVar4 = *(int *)(param_1 + 0x16c);
    *(uint *)(param_1 + 0x38) = uVar5;
  }
  if (iVar4 != 0) {
    gcm_gmult_4bit();
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  uVar5 = *(uint *)(param_1 + 0xc);
  uVar7 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  uVar5 = *(uint *)(param_1 + 0x168);
  if (uVar5 != 0) {
    puVar8 = param_2;
    puVar9 = param_3;
    if (param_4 == 0) {
LAB_080f0e92:
      *(uint *)(param_1 + 0x168) = uVar5;
      return 0;
    }
    do {
      param_2 = (uint *)((int)puVar8 + 1);
      bVar2 = *(byte *)puVar8;
      param_3 = (uint *)((int)puVar9 + 1);
      param_4 = param_4 - 1;
      *(byte *)puVar9 = bVar2 ^ *(byte *)(param_1 + 0x10 + uVar5);
      pbVar1 = (byte *)(param_1 + 0x40 + uVar5);
      *pbVar1 = *pbVar1 ^ bVar2;
      uVar5 = uVar5 + 1 & 0xf;
      if (uVar5 == 0) break;
      puVar8 = param_2;
      puVar9 = param_3;
    } while (param_4 != 0);
    if (uVar5 != 0) goto LAB_080f0e92;
    gcm_gmult_4bit();
  }
  for (; 0xbff < param_4; param_4 = param_4 - 0xc00) {
    gcm_ghash_4bit(0xc00);
    (*param_5)(param_2,param_3,0xc0,uVar3,param_1);
    uVar7 = uVar7 + 0xc0;
    *(uint *)(param_1 + 0xc) =
         uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
    param_2 = param_2 + 0x300;
    param_3 = param_3 + 0x300;
  }
  uVar5 = param_4 & 0xfffffff0;
  if (uVar5 == 0) {
    if (param_4 != 0) {
      (**(code **)(param_1 + 0x170))(param_1,param_1 + 0x10,uVar3);
      uVar7 = uVar7 + 1;
      *(uint *)(param_1 + 0xc) =
           uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
LAB_080f101b:
      local_28 = (uint *)(param_1 + 0x40);
      local_30 = param_4 - 1;
      if (((param_4 < 5 ||
           (param_3 < (uint *)(param_1 + 0x44U) && (uint *)(param_1 + 0x10) < param_3 + 1 ||
           local_28 < param_2 + 1 && param_2 < (uint *)(param_1 + 0x44U))) ||
           param_3 < param_2 + 1 && param_2 < param_3 + 1) ||
         ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
        bVar2 = *(byte *)param_2;
        *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) ^ bVar2;
        *(byte *)param_3 = bVar2 ^ *(byte *)(param_1 + 0x10);
        if (local_30 != 0) {
          bVar2 = *(byte *)((int)param_2 + 1);
          *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) ^ bVar2;
          *(byte *)((int)param_3 + 1) = bVar2 ^ *(byte *)(param_1 + 0x11);
          if (local_30 != 1) {
            bVar2 = *(byte *)((int)param_2 + 2);
            *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) ^ bVar2;
            *(byte *)((int)param_3 + 2) = bVar2 ^ *(byte *)(param_1 + 0x12);
            if (local_30 != 2) {
              bVar2 = *(byte *)((int)param_2 + 3);
              *(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) ^ bVar2;
              *(byte *)((int)param_3 + 3) = bVar2 ^ *(byte *)(param_1 + 0x13);
              if (local_30 != 3) {
                bVar2 = *(byte *)(param_2 + 1);
                *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) ^ bVar2;
                *(byte *)(param_3 + 1) = bVar2 ^ *(byte *)(param_1 + 0x14);
                if (local_30 != 4) {
                  bVar2 = *(byte *)((int)param_2 + 5);
                  *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) ^ bVar2;
                  *(byte *)((int)param_3 + 5) = bVar2 ^ *(byte *)(param_1 + 0x15);
                  if (local_30 != 5) {
                    bVar2 = *(byte *)((int)param_2 + 6);
                    *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) ^ bVar2;
                    *(byte *)((int)param_3 + 6) = bVar2 ^ *(byte *)(param_1 + 0x16);
                    if (local_30 != 6) {
                      bVar2 = *(byte *)((int)param_2 + 7);
                      *(byte *)(param_1 + 0x47) = *(byte *)(param_1 + 0x47) ^ bVar2;
                      *(byte *)((int)param_3 + 7) = bVar2 ^ *(byte *)(param_1 + 0x17);
                      if (local_30 != 7) {
                        bVar2 = *(byte *)(param_2 + 2);
                        *(byte *)(param_1 + 0x48) = *(byte *)(param_1 + 0x48) ^ bVar2;
                        *(byte *)(param_3 + 2) = bVar2 ^ *(byte *)(param_1 + 0x18);
                        if (local_30 != 8) {
                          bVar2 = *(byte *)((int)param_2 + 9);
                          *(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) ^ bVar2;
                          *(byte *)((int)param_3 + 9) = bVar2 ^ *(byte *)(param_1 + 0x19);
                          if (local_30 != 9) {
                            bVar2 = *(byte *)((int)param_2 + 10);
                            *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) ^ bVar2;
                            *(byte *)((int)param_3 + 10) = bVar2 ^ *(byte *)(param_1 + 0x1a);
                            if (local_30 != 10) {
                              bVar2 = *(byte *)((int)param_2 + 0xb);
                              *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) ^ bVar2;
                              *(byte *)((int)param_3 + 0xb) = bVar2 ^ *(byte *)(param_1 + 0x1b);
                              if (local_30 != 0xb) {
                                bVar2 = *(byte *)(param_2 + 3);
                                *(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) ^ bVar2;
                                *(byte *)(param_3 + 3) = bVar2 ^ *(byte *)(param_1 + 0x1c);
                                if (local_30 != 0xc) {
                                  bVar2 = *(byte *)((int)param_2 + 0xd);
                                  *(byte *)(param_1 + 0x4d) = *(byte *)(param_1 + 0x4d) ^ bVar2;
                                  *(byte *)((int)param_3 + 0xd) = bVar2 ^ *(byte *)(param_1 + 0x1d);
                                  if (local_30 != 0xd) {
                                    bVar2 = *(byte *)((int)param_2 + 0xe);
                                    *(byte *)(param_1 + 0x4e) = *(byte *)(param_1 + 0x4e) ^ bVar2;
                                    *(byte *)((int)param_3 + 0xe) =
                                         bVar2 ^ *(byte *)(param_1 + 0x1e);
                                    if (local_30 != 0xe) {
                                      bVar2 = *(byte *)((int)param_2 + 0xf);
                                      *(byte *)(param_1 + 0x4f) = *(byte *)(param_1 + 0x4f) ^ bVar2;
                                      *(byte *)((int)param_3 + 0xf) =
                                           bVar2 ^ *(byte *)(param_1 + 0x1f);
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
        uVar5 = *param_2;
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ uVar5;
        *param_3 = uVar5 ^ *(uint *)(param_1 + 0x10);
        iVar6 = (param_4 - 4 >> 2) + 1;
        iVar4 = iVar6 * 4;
        if (iVar6 != 1) {
          uVar5 = param_2[1];
          *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ uVar5;
          param_3[1] = uVar5 ^ *(uint *)(param_1 + 0x14);
          if (iVar6 != 2) {
            uVar5 = param_2[2];
            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ uVar5;
            param_3[2] = uVar5 ^ *(uint *)(param_1 + 0x18);
            if (iVar6 != 3) {
              uVar5 = param_2[3];
              *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ uVar5;
              param_3[3] = uVar5 ^ *(uint *)(param_1 + 0x1c);
            }
          }
        }
        local_30 = local_30 + iVar6 * -4;
        if (iVar4 - param_4 != 0) {
          bVar2 = *(byte *)(param_2 + iVar6);
          pbVar1 = (byte *)(param_1 + 0x40 + iVar4);
          *pbVar1 = *pbVar1 ^ bVar2;
          *(byte *)(param_3 + iVar6) = bVar2 ^ *(byte *)(param_1 + 0x10 + iVar4);
          if (local_30 != 0) {
            bVar2 = *(byte *)((int)param_2 + iVar4 + 1);
            pbVar1 = (byte *)(param_1 + 0x40 + iVar4 + 1);
            *pbVar1 = *pbVar1 ^ bVar2;
            *(byte *)((int)param_3 + iVar4 + 1) = bVar2 ^ *(byte *)(param_1 + 0x10 + iVar4 + 1);
            if (local_30 != 1) {
              bVar2 = *(byte *)((int)param_2 + iVar4 + 2);
              pbVar1 = (byte *)(param_1 + 0x40 + iVar4 + 2);
              *pbVar1 = *pbVar1 ^ bVar2;
              *(byte *)((int)param_3 + iVar4 + 2) = bVar2 ^ *(byte *)(param_1 + 0x10 + iVar4 + 2);
            }
          }
        }
      }
      goto LAB_080f0f3d;
    }
  }
  else {
    gcm_ghash_4bit(uVar5);
    (*param_5)(param_2,param_3,param_4 >> 4,uVar3,param_1);
    uVar7 = (param_4 >> 4) + uVar7;
    param_4 = param_4 - uVar5;
    *(uint *)(param_1 + 0xc) =
         uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
    if (param_4 != 0) {
      param_3 = (uint *)((int)param_3 + uVar5);
      param_2 = (uint *)((int)param_2 + uVar5);
      (**(code **)(param_1 + 0x170))(param_1,param_1 + 0x10,uVar3);
      uVar7 = uVar7 + 1;
      *(uint *)(param_1 + 0xc) =
           uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
      goto LAB_080f101b;
    }
  }
  param_4 = 0;
LAB_080f0f3d:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}

