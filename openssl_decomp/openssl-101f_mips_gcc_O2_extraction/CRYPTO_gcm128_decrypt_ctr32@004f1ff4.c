
undefined4
CRYPTO_gcm128_decrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar3 = param_4 + *(int *)(param_1 + 0x3c);
  uVar2 = (uint)(uVar3 < param_4) + *(int *)(param_1 + 0x38);
  uVar8 = *(undefined4 *)(param_1 + 0x174);
  if ((0xf < uVar2) || ((uVar2 == 0xf && (0xffffffe0 < uVar3)))) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar2;
  *(uint *)(param_1 + 0x3c) = uVar3;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  uVar2 = *(uint *)(param_1 + 0x168);
  iVar7 = *(int *)(param_1 + 0xc);
  if (uVar2 != 0) {
    iVar4 = param_1 + uVar2;
    if (param_4 == 0) {
LAB_004f21ac:
      *(uint *)(param_1 + 0x168) = uVar2;
      return 0;
    }
    bVar1 = *(byte *)param_2;
    param_4 = param_4 - 1;
    *(byte *)param_3 = bVar1 ^ *(byte *)(iVar4 + 0x10);
    *(byte *)(iVar4 + 0x40) = bVar1 ^ *(byte *)(iVar4 + 0x40);
    param_2 = (uint *)((int)param_2 + 1);
    param_3 = (uint *)((int)param_3 + 1);
    while (uVar2 = uVar2 + 1 & 0xf, uVar2 != 0) {
      iVar4 = param_1 + uVar2;
      if (param_4 == 0) goto LAB_004f21ac;
      bVar1 = *(byte *)param_2;
      param_4 = param_4 - 1;
      *(byte *)param_3 = bVar1 ^ *(byte *)(iVar4 + 0x10);
      *(byte *)(iVar4 + 0x40) = bVar1 ^ *(byte *)(iVar4 + 0x40);
      param_2 = (uint *)((int)param_2 + 1);
      param_3 = (uint *)((int)param_3 + 1);
    }
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  if (0xbff < param_4) {
    do {
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2,0xc00);
      iVar7 = iVar7 + 0xc0;
      param_4 = param_4 - 0xc00;
      (*param_5)(param_2,param_3,0xc0,uVar8,param_1);
      *(int *)(param_1 + 0xc) = iVar7;
      param_3 = param_3 + 0x300;
      param_2 = param_2 + 0x300;
    } while (0xbff < param_4);
  }
  uVar2 = param_4 & 0xfffffff0;
  if (uVar2 != 0) {
    uVar3 = param_4 >> 4;
    iVar7 = iVar7 + uVar3;
    param_4 = param_4 - uVar2;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2,uVar2);
    (*param_5)(param_2,param_3,uVar3,uVar8,param_1);
    param_3 = (uint *)((int)param_3 + uVar2);
    param_2 = (uint *)((int)param_2 + uVar2);
    *(int *)(param_1 + 0xc) = iVar7;
  }
  if (param_4 != 0) {
    (**(code **)(param_1 + 0x170))(param_1,(uint *)(param_1 + 0x10),uVar8);
    *(int *)(param_1 + 0xc) = iVar7 + 1;
    uVar2 = param_4 - 1;
    if (((param_4 < 5 ||
         ((uint *)(param_1 + 0x10) < param_3 + 1 && param_3 < (uint *)(param_1 + 0x44) ||
         (uint *)(param_1 + 0x40) < param_2 + 1 && param_2 < (uint *)(param_1 + 0x44))) ||
         param_2 < param_3 + 1 && param_3 < param_2 + 1) ||
       ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
      bVar1 = *(byte *)param_2;
      *(byte *)(param_1 + 0x40) = bVar1 ^ *(byte *)(param_1 + 0x40);
      *(byte *)param_3 = bVar1 ^ *(byte *)(param_1 + 0x10);
      if (uVar2 != 0) {
        bVar1 = *(byte *)((int)param_2 + 1);
        *(byte *)(param_1 + 0x41) = bVar1 ^ *(byte *)(param_1 + 0x41);
        *(byte *)((int)param_3 + 1) = bVar1 ^ *(byte *)(param_1 + 0x11);
        if (param_4 != 2) {
          bVar1 = *(byte *)((int)param_2 + 2);
          *(byte *)(param_1 + 0x42) = bVar1 ^ *(byte *)(param_1 + 0x42);
          *(byte *)((int)param_3 + 2) = bVar1 ^ *(byte *)(param_1 + 0x12);
          if (param_4 != 3) {
            bVar1 = *(byte *)((int)param_2 + 3);
            *(byte *)(param_1 + 0x43) = bVar1 ^ *(byte *)(param_1 + 0x43);
            *(byte *)((int)param_3 + 3) = bVar1 ^ *(byte *)(param_1 + 0x13);
            if (param_4 != 4) {
              bVar1 = *(byte *)(param_2 + 1);
              *(byte *)(param_1 + 0x44) = bVar1 ^ *(byte *)(param_1 + 0x44);
              *(byte *)(param_3 + 1) = bVar1 ^ *(byte *)(param_1 + 0x14);
              if (param_4 != 5) {
                bVar1 = *(byte *)((int)param_2 + 5);
                *(byte *)(param_1 + 0x45) = bVar1 ^ *(byte *)(param_1 + 0x45);
                *(byte *)((int)param_3 + 5) = bVar1 ^ *(byte *)(param_1 + 0x15);
                if (param_4 != 6) {
                  bVar1 = *(byte *)((int)param_2 + 6);
                  *(byte *)(param_1 + 0x46) = bVar1 ^ *(byte *)(param_1 + 0x46);
                  *(byte *)((int)param_3 + 6) = bVar1 ^ *(byte *)(param_1 + 0x16);
                  if (param_4 != 7) {
                    bVar1 = *(byte *)((int)param_2 + 7);
                    *(byte *)(param_1 + 0x47) = bVar1 ^ *(byte *)(param_1 + 0x47);
                    *(byte *)((int)param_3 + 7) = bVar1 ^ *(byte *)(param_1 + 0x17);
                    if (param_4 != 8) {
                      bVar1 = *(byte *)(param_2 + 2);
                      *(byte *)(param_1 + 0x48) = bVar1 ^ *(byte *)(param_1 + 0x48);
                      *(byte *)(param_3 + 2) = bVar1 ^ *(byte *)(param_1 + 0x18);
                      if (param_4 != 9) {
                        bVar1 = *(byte *)((int)param_2 + 9);
                        *(byte *)(param_1 + 0x49) = bVar1 ^ *(byte *)(param_1 + 0x49);
                        *(byte *)((int)param_3 + 9) = bVar1 ^ *(byte *)(param_1 + 0x19);
                        if (param_4 != 10) {
                          bVar1 = *(byte *)((int)param_2 + 10);
                          *(byte *)(param_1 + 0x4a) = bVar1 ^ *(byte *)(param_1 + 0x4a);
                          *(byte *)((int)param_3 + 10) = bVar1 ^ *(byte *)(param_1 + 0x1a);
                          if (param_4 != 0xb) {
                            bVar1 = *(byte *)((int)param_2 + 0xb);
                            *(byte *)(param_1 + 0x4b) = bVar1 ^ *(byte *)(param_1 + 0x4b);
                            *(byte *)((int)param_3 + 0xb) = bVar1 ^ *(byte *)(param_1 + 0x1b);
                            if (param_4 != 0xc) {
                              bVar1 = *(byte *)(param_2 + 3);
                              *(byte *)(param_1 + 0x4c) = bVar1 ^ *(byte *)(param_1 + 0x4c);
                              *(byte *)(param_3 + 3) = bVar1 ^ *(byte *)(param_1 + 0x1c);
                              if (param_4 != 0xd) {
                                bVar1 = *(byte *)((int)param_2 + 0xd);
                                *(byte *)(param_1 + 0x4d) = bVar1 ^ *(byte *)(param_1 + 0x4d);
                                *(byte *)((int)param_3 + 0xd) = bVar1 ^ *(byte *)(param_1 + 0x1d);
                                if (param_4 != 0xe) {
                                  bVar1 = *(byte *)((int)param_2 + 0xe);
                                  *(byte *)(param_1 + 0x4e) = bVar1 ^ *(byte *)(param_1 + 0x4e);
                                  *(byte *)((int)param_3 + 0xe) = bVar1 ^ *(byte *)(param_1 + 0x1e);
                                  if (param_4 != 0xf) {
                                    bVar1 = *(byte *)((int)param_2 + 0xf);
                                    *(byte *)(param_1 + 0x4f) = bVar1 ^ *(byte *)(param_1 + 0x4f);
                                    *(byte *)((int)param_3 + 0xf) =
                                         bVar1 ^ *(byte *)(param_1 + 0x1f);
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
      iVar7 = (param_4 - 4 >> 2) + 1;
      uVar3 = iVar7 * 4;
      if (uVar2 < 3) {
        uVar3 = 0;
      }
      else {
        uVar5 = *param_2;
        *(uint *)(param_1 + 0x40) = uVar5 ^ *(uint *)(param_1 + 0x40);
        *param_3 = uVar5 ^ *(uint *)(param_1 + 0x10);
        if (iVar7 != 1) {
          uVar5 = param_2[1];
          *(uint *)(param_1 + 0x44) = uVar5 ^ *(uint *)(param_1 + 0x44);
          param_3[1] = uVar5 ^ *(uint *)(param_1 + 0x14);
          if (iVar7 != 2) {
            uVar5 = param_2[2];
            *(uint *)(param_1 + 0x48) = uVar5 ^ *(uint *)(param_1 + 0x48);
            param_3[2] = uVar5 ^ *(uint *)(param_1 + 0x18);
            if (iVar7 != 3) {
              uVar5 = param_2[3];
              *(uint *)(param_1 + 0x4c) = uVar5 ^ *(uint *)(param_1 + 0x4c);
              param_3[3] = uVar5 ^ *(uint *)(param_1 + 0x1c);
            }
          }
        }
        uVar2 = uVar2 + iVar7 * -4;
        if (param_4 == uVar3) goto LAB_004f2174;
      }
      iVar4 = param_1 + uVar3;
      iVar7 = uVar3 + 1;
      bVar1 = *(byte *)((int)param_2 + uVar3);
      *(byte *)(iVar4 + 0x40) = bVar1 ^ *(byte *)(iVar4 + 0x40);
      *(byte *)((int)param_3 + uVar3) = bVar1 ^ *(byte *)(iVar4 + 0x10);
      if (uVar2 != 0) {
        iVar6 = param_1 + iVar7;
        bVar1 = *(byte *)((int)param_2 + iVar7);
        iVar4 = uVar3 + 2;
        *(byte *)(iVar6 + 0x40) = bVar1 ^ *(byte *)(iVar6 + 0x40);
        *(byte *)((int)param_3 + iVar7) = bVar1 ^ *(byte *)(iVar6 + 0x10);
        if (uVar2 != 1) {
          iVar7 = param_1 + iVar4;
          bVar1 = *(byte *)((int)param_2 + iVar4);
          *(byte *)(iVar7 + 0x40) = bVar1 ^ *(byte *)(iVar7 + 0x40);
          *(byte *)((int)param_3 + iVar4) = bVar1 ^ *(byte *)(iVar7 + 0x10);
        }
      }
    }
  }
LAB_004f2174:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}

