
undefined4 CRYPTO_gcm128_encrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint *local_res4;
  int local_34;
  
  pcVar8 = *(code **)(param_1 + 0x170);
  uVar1 = param_4 + *(int *)(param_1 + 0x3c);
  uVar9 = *(undefined4 *)(param_1 + 0x174);
  uVar3 = (uint)(uVar1 < param_4) + *(int *)(param_1 + 0x38);
  if ((0xf < uVar3) || ((uVar3 == 0xf && (0xffffffe0 < uVar1)))) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar3;
  *(uint *)(param_1 + 0x3c) = uVar1;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  local_34 = *(int *)(param_1 + 0xc);
  uVar1 = *(uint *)(param_1 + 0x168);
  local_res4 = param_2;
  if (uVar1 != 0) {
    if (param_4 == 0) {
LAB_004f09a4:
      *(uint *)(param_1 + 0x168) = uVar1;
      return 0;
    }
    iVar5 = param_1 + uVar1;
    param_4 = param_4 - 1;
    bVar2 = *(byte *)(iVar5 + 0x10) ^ *(byte *)param_2;
    *(byte *)param_3 = bVar2;
    *(byte *)(iVar5 + 0x40) = bVar2 ^ *(byte *)(iVar5 + 0x40);
    param_3 = (uint *)((int)param_3 + 1);
    local_res4 = (uint *)((int)param_2 + 1);
    while (uVar1 = uVar1 + 1 & 0xf, uVar1 != 0) {
      iVar5 = param_1 + uVar1;
      if (param_4 == 0) goto LAB_004f09a4;
      param_4 = param_4 - 1;
      bVar2 = *(byte *)local_res4 ^ *(byte *)(iVar5 + 0x10);
      *(byte *)param_3 = bVar2;
      *(byte *)(iVar5 + 0x40) = bVar2 ^ *(byte *)(iVar5 + 0x40);
      param_3 = (uint *)((int)param_3 + 1);
      local_res4 = (uint *)((int)local_res4 + 1);
    }
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  if ((((uint)local_res4 | (uint)param_3) & 3) != 0) {
    uVar1 = 0;
    if (param_4 != 0) {
      uVar1 = 0;
      puVar10 = local_res4;
      do {
        while (iVar5 = param_1 + uVar1, uVar1 != 0) {
          uVar1 = uVar1 + 1 & 0xf;
          bVar2 = *(byte *)puVar10 ^ *(byte *)(iVar5 + 0x10);
          *(byte *)param_3 = bVar2;
          *(byte *)(iVar5 + 0x40) = bVar2 ^ *(byte *)(iVar5 + 0x40);
          if (uVar1 == 0) {
            gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
          }
          puVar10 = (uint *)((int)puVar10 + 1);
          param_3 = (uint *)((int)param_3 + 1);
          if (puVar10 == (uint *)((int)local_res4 + param_4)) goto LAB_004f08e0;
        }
        local_34 = local_34 + 1;
        puVar11 = (uint *)((int)puVar10 + 1);
        uVar1 = 1;
        (*pcVar8)(param_1,param_1 + 0x10,uVar9);
        *(int *)(param_1 + 0xc) = local_34;
        bVar2 = *(byte *)(param_1 + 0x10) ^ *(byte *)puVar10;
        *(byte *)param_3 = bVar2;
        *(byte *)(param_1 + 0x40) = bVar2 ^ *(byte *)(param_1 + 0x40);
        puVar10 = puVar11;
        param_3 = (uint *)((int)param_3 + 1);
      } while (puVar11 != (uint *)((int)local_res4 + param_4));
    }
LAB_004f08e0:
    *(uint *)(param_1 + 0x168) = uVar1;
    return 0;
  }
  if (0xbff < param_4) {
    puVar10 = param_3;
    do {
      param_3 = puVar10 + 0x300;
      iVar5 = local_34;
      puVar11 = puVar10;
      puVar13 = local_res4;
      do {
        iVar5 = iVar5 + 1;
        (*pcVar8)(param_1,param_1 + 0x10,uVar9);
        puVar12 = puVar11 + 4;
        *(int *)(param_1 + 0xc) = iVar5;
        *puVar11 = *puVar13 ^ *(uint *)(param_1 + 0x10);
        puVar11[1] = puVar13[1] ^ *(uint *)(param_1 + 0x14);
        puVar11[2] = puVar13[2] ^ *(uint *)(param_1 + 0x18);
        puVar11[3] = puVar13[3] ^ *(uint *)(param_1 + 0x1c);
        puVar11 = puVar12;
        puVar13 = puVar13 + 4;
      } while (param_3 != puVar12);
      param_4 = param_4 - 0xc00;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar10,0xc00);
      local_34 = local_34 + 0xc0;
      local_res4 = local_res4 + 0x300;
      puVar10 = param_3;
    } while (0xbff < param_4);
  }
  uVar1 = param_4 & 0xfffffff0;
  if (uVar1 != 0) {
    uVar3 = param_4 - 0x10 >> 4;
    iVar5 = local_34 + 1;
    local_34 = uVar3 + iVar5;
    puVar10 = local_res4;
    puVar11 = param_3;
    while( true ) {
      (*pcVar8)(param_1,param_1 + 0x10,uVar9);
      *(int *)(param_1 + 0xc) = iVar5;
      *puVar11 = *(uint *)(param_1 + 0x10) ^ *puVar10;
      puVar11[1] = *(uint *)(param_1 + 0x14) ^ puVar10[1];
      puVar11[2] = *(uint *)(param_1 + 0x18) ^ puVar10[2];
      puVar11[3] = *(uint *)(param_1 + 0x1c) ^ puVar10[3];
      if (local_34 == iVar5) break;
      iVar5 = iVar5 + 1;
      puVar10 = puVar10 + 4;
      puVar11 = puVar11 + 4;
    }
    iVar5 = uVar3 + 1;
    param_3 = param_3 + iVar5 * 4;
    local_res4 = local_res4 + iVar5 * 4;
    param_4 = param_4 & 0xf;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,(int)param_3 - uVar1);
  }
  if (param_4 != 0) {
    (*pcVar8)(param_1,(uint *)(param_1 + 0x10),uVar9);
    *(int *)(param_1 + 0xc) = local_34 + 1;
    uVar1 = param_4 - 1;
    if (((param_4 < 5 ||
         ((uint *)(param_1 + 0x40) < local_res4 + 1 && local_res4 < (uint *)(param_1 + 0x44) ||
         (uint *)(param_1 + 0x10) < param_3 + 1 && param_3 < (uint *)(param_1 + 0x44))) ||
         param_3 < local_res4 + 1 && local_res4 < param_3 + 1) ||
       ((((uint)param_3 | (uint)local_res4) & 3) != 0)) {
      bVar2 = *(byte *)local_res4 ^ *(byte *)(param_1 + 0x10);
      *(byte *)param_3 = bVar2;
      *(byte *)(param_1 + 0x40) = bVar2 ^ *(byte *)(param_1 + 0x40);
      if (uVar1 != 0) {
        bVar2 = *(byte *)(param_1 + 0x11) ^ *(byte *)((int)local_res4 + 1);
        *(byte *)((int)param_3 + 1) = bVar2;
        *(byte *)(param_1 + 0x41) = bVar2 ^ *(byte *)(param_1 + 0x41);
        if (param_4 != 2) {
          bVar2 = *(byte *)((int)local_res4 + 2) ^ *(byte *)(param_1 + 0x12);
          *(byte *)((int)param_3 + 2) = bVar2;
          *(byte *)(param_1 + 0x42) = bVar2 ^ *(byte *)(param_1 + 0x42);
          if (param_4 != 3) {
            bVar2 = *(byte *)((int)local_res4 + 3) ^ *(byte *)(param_1 + 0x13);
            *(byte *)((int)param_3 + 3) = bVar2;
            *(byte *)(param_1 + 0x43) = bVar2 ^ *(byte *)(param_1 + 0x43);
            if (param_4 != 4) {
              bVar2 = *(byte *)(local_res4 + 1) ^ *(byte *)(param_1 + 0x14);
              *(byte *)(param_3 + 1) = bVar2;
              *(byte *)(param_1 + 0x44) = bVar2 ^ *(byte *)(param_1 + 0x44);
              if (param_4 != 5) {
                bVar2 = *(byte *)((int)local_res4 + 5) ^ *(byte *)(param_1 + 0x15);
                *(byte *)((int)param_3 + 5) = bVar2;
                *(byte *)(param_1 + 0x45) = bVar2 ^ *(byte *)(param_1 + 0x45);
                if (param_4 != 6) {
                  bVar2 = *(byte *)((int)local_res4 + 6) ^ *(byte *)(param_1 + 0x16);
                  *(byte *)((int)param_3 + 6) = bVar2;
                  *(byte *)(param_1 + 0x46) = bVar2 ^ *(byte *)(param_1 + 0x46);
                  if (param_4 != 7) {
                    bVar2 = *(byte *)((int)local_res4 + 7) ^ *(byte *)(param_1 + 0x17);
                    *(byte *)((int)param_3 + 7) = bVar2;
                    *(byte *)(param_1 + 0x47) = bVar2 ^ *(byte *)(param_1 + 0x47);
                    if (param_4 != 8) {
                      bVar2 = *(byte *)(local_res4 + 2) ^ *(byte *)(param_1 + 0x18);
                      *(byte *)(param_3 + 2) = bVar2;
                      *(byte *)(param_1 + 0x48) = bVar2 ^ *(byte *)(param_1 + 0x48);
                      if (param_4 != 9) {
                        bVar2 = *(byte *)((int)local_res4 + 9) ^ *(byte *)(param_1 + 0x19);
                        *(byte *)((int)param_3 + 9) = bVar2;
                        *(byte *)(param_1 + 0x49) = bVar2 ^ *(byte *)(param_1 + 0x49);
                        if (param_4 != 10) {
                          bVar2 = *(byte *)((int)local_res4 + 10) ^ *(byte *)(param_1 + 0x1a);
                          *(byte *)((int)param_3 + 10) = bVar2;
                          *(byte *)(param_1 + 0x4a) = bVar2 ^ *(byte *)(param_1 + 0x4a);
                          if (param_4 != 0xb) {
                            bVar2 = *(byte *)((int)local_res4 + 0xb) ^ *(byte *)(param_1 + 0x1b);
                            *(byte *)((int)param_3 + 0xb) = bVar2;
                            *(byte *)(param_1 + 0x4b) = bVar2 ^ *(byte *)(param_1 + 0x4b);
                            if (param_4 != 0xc) {
                              bVar2 = *(byte *)(local_res4 + 3) ^ *(byte *)(param_1 + 0x1c);
                              *(byte *)(param_3 + 3) = bVar2;
                              *(byte *)(param_1 + 0x4c) = bVar2 ^ *(byte *)(param_1 + 0x4c);
                              if (param_4 != 0xd) {
                                bVar2 = *(byte *)((int)local_res4 + 0xd) ^ *(byte *)(param_1 + 0x1d)
                                ;
                                *(byte *)((int)param_3 + 0xd) = bVar2;
                                *(byte *)(param_1 + 0x4d) = bVar2 ^ *(byte *)(param_1 + 0x4d);
                                if (param_4 != 0xe) {
                                  bVar2 = *(byte *)((int)local_res4 + 0xe) ^
                                          *(byte *)(param_1 + 0x1e);
                                  *(byte *)((int)param_3 + 0xe) = bVar2;
                                  *(uint *)(param_1 + 0x168) = param_4;
                                  *(byte *)(param_1 + 0x4e) = bVar2 ^ *(byte *)(param_1 + 0x4e);
                                  return 0;
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
      iVar5 = (param_4 - 4 >> 2) + 1;
      uVar3 = iVar5 * 4;
      if (uVar1 < 3) {
        uVar3 = 0;
      }
      else {
        uVar4 = *(uint *)(param_1 + 0x10) ^ *local_res4;
        *param_3 = uVar4;
        *(uint *)(param_1 + 0x40) = uVar4 ^ *(uint *)(param_1 + 0x40);
        if (iVar5 != 1) {
          uVar4 = local_res4[1] ^ *(uint *)(param_1 + 0x14);
          param_3[1] = uVar4;
          *(uint *)(param_1 + 0x44) = uVar4 ^ *(uint *)(param_1 + 0x44);
          if (iVar5 == 3) {
            uVar4 = local_res4[2] ^ *(uint *)(param_1 + 0x18);
            param_3[2] = uVar4;
            *(uint *)(param_1 + 0x48) = uVar4 ^ *(uint *)(param_1 + 0x48);
          }
        }
        uVar1 = uVar1 + iVar5 * -4;
        if (param_4 == uVar3) goto LAB_004f0b94;
      }
      iVar6 = param_1 + uVar3;
      iVar5 = uVar3 + 1;
      bVar2 = *(byte *)((int)local_res4 + uVar3) ^ *(byte *)(iVar6 + 0x10);
      *(byte *)((int)param_3 + uVar3) = bVar2;
      *(byte *)(iVar6 + 0x40) = bVar2 ^ *(byte *)(iVar6 + 0x40);
      if (uVar1 != 0) {
        iVar7 = param_1 + iVar5;
        iVar6 = uVar3 + 2;
        bVar2 = *(byte *)((int)local_res4 + iVar5) ^ *(byte *)(iVar7 + 0x10);
        *(byte *)((int)param_3 + iVar5) = bVar2;
        *(byte *)(iVar7 + 0x40) = bVar2 ^ *(byte *)(iVar7 + 0x40);
        if (uVar1 != 1) {
          iVar5 = param_1 + iVar6;
          bVar2 = *(byte *)((int)local_res4 + iVar6) ^ *(byte *)(iVar5 + 0x10);
          *(byte *)((int)param_3 + iVar6) = bVar2;
          *(byte *)(iVar5 + 0x40) = bVar2 ^ *(byte *)(iVar5 + 0x40);
          *(uint *)(param_1 + 0x168) = param_4;
          return 0;
        }
      }
    }
  }
LAB_004f0b94:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}

