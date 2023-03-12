
undefined4 CRYPTO_gcm128_decrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint *local_res8;
  int local_34;
  
  pcVar8 = *(code **)(param_1 + 0x170);
  uVar2 = param_4 + *(int *)(param_1 + 0x3c);
  uVar9 = *(undefined4 *)(param_1 + 0x174);
  uVar3 = (uint)(uVar2 < param_4) + *(int *)(param_1 + 0x38);
  if ((0xf < uVar3) || ((uVar3 == 0xf && (0xffffffe0 < uVar2)))) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar3;
  *(uint *)(param_1 + 0x3c) = uVar2;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  local_34 = *(int *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x168);
  local_res8 = param_3;
  if (uVar2 != 0) {
    iVar4 = param_1 + uVar2;
    if (param_4 == 0) {
LAB_004ee390:
      *(uint *)(param_1 + 0x168) = uVar2;
      return 0;
    }
    bVar1 = *(byte *)param_2;
    param_4 = param_4 - 1;
    *(byte *)param_3 = bVar1 ^ *(byte *)(iVar4 + 0x10);
    *(byte *)(iVar4 + 0x40) = bVar1 ^ *(byte *)(iVar4 + 0x40);
    param_2 = (uint *)((int)param_2 + 1);
    local_res8 = (uint *)((int)param_3 + 1);
    while (uVar2 = uVar2 + 1 & 0xf, uVar2 != 0) {
      iVar4 = param_1 + uVar2;
      if (param_4 == 0) goto LAB_004ee390;
      bVar1 = *(byte *)param_2;
      param_4 = param_4 - 1;
      *(byte *)local_res8 = bVar1 ^ *(byte *)(iVar4 + 0x10);
      *(byte *)(iVar4 + 0x40) = bVar1 ^ *(byte *)(iVar4 + 0x40);
      param_2 = (uint *)((int)param_2 + 1);
      local_res8 = (uint *)((int)local_res8 + 1);
    }
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  if ((((uint)param_2 | (uint)local_res8) & 3) != 0) {
    uVar2 = 0;
    if (param_4 != 0) {
      uVar2 = 0;
      puVar10 = param_2;
      do {
        while (iVar4 = param_1 + uVar2, uVar2 != 0) {
          bVar1 = *(byte *)puVar10;
          uVar2 = uVar2 + 1 & 0xf;
          *(byte *)local_res8 = bVar1 ^ *(byte *)(iVar4 + 0x10);
          *(byte *)(iVar4 + 0x40) = bVar1 ^ *(byte *)(iVar4 + 0x40);
          if (uVar2 == 0) {
            gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
          }
          puVar10 = (uint *)((int)puVar10 + 1);
          local_res8 = (uint *)((int)local_res8 + 1);
          if (puVar10 == (uint *)((int)param_2 + param_4)) goto LAB_004ee2d4;
        }
        local_34 = local_34 + 1;
        puVar11 = (uint *)((int)puVar10 + 1);
        uVar2 = 1;
        (*pcVar8)(param_1,param_1 + 0x10,uVar9);
        *(int *)(param_1 + 0xc) = local_34;
        bVar1 = *(byte *)puVar10;
        *(byte *)local_res8 = bVar1 ^ *(byte *)(param_1 + 0x10);
        *(byte *)(param_1 + 0x40) = bVar1 ^ *(byte *)(param_1 + 0x40);
        local_res8 = (uint *)((int)local_res8 + 1);
        puVar10 = puVar11;
      } while (puVar11 != (uint *)((int)param_2 + param_4));
    }
LAB_004ee2d4:
    *(uint *)(param_1 + 0x168) = uVar2;
    return 0;
  }
  if (0xbff < param_4) {
    puVar10 = param_2;
    do {
      param_2 = puVar10 + 0x300;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar10,0xc00);
      iVar4 = local_34;
      puVar11 = local_res8;
      do {
        iVar4 = iVar4 + 1;
        puVar12 = puVar10 + 4;
        (*pcVar8)(param_1,param_1 + 0x10,uVar9);
        *(int *)(param_1 + 0xc) = iVar4;
        *puVar11 = *puVar10 ^ *(uint *)(param_1 + 0x10);
        puVar11[1] = puVar10[1] ^ *(uint *)(param_1 + 0x14);
        puVar11[2] = puVar10[2] ^ *(uint *)(param_1 + 0x18);
        puVar11[3] = puVar10[3] ^ *(uint *)(param_1 + 0x1c);
        puVar10 = puVar12;
        puVar11 = puVar11 + 4;
      } while (param_2 != puVar12);
      param_4 = param_4 - 0xc00;
      local_34 = local_34 + 0xc0;
      local_res8 = local_res8 + 0x300;
      puVar10 = param_2;
    } while (0xbff < param_4);
  }
  if ((param_4 & 0xfffffff0) != 0) {
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2);
    uVar2 = param_4 - 0x10 >> 4;
    iVar4 = local_34 + 1;
    local_34 = uVar2 + iVar4;
    puVar10 = param_2;
    puVar11 = local_res8;
    while( true ) {
      (*pcVar8)(param_1,param_1 + 0x10,uVar9);
      *(int *)(param_1 + 0xc) = iVar4;
      *puVar11 = *(uint *)(param_1 + 0x10) ^ *puVar10;
      puVar11[1] = *(uint *)(param_1 + 0x14) ^ puVar10[1];
      puVar11[2] = *(uint *)(param_1 + 0x18) ^ puVar10[2];
      puVar11[3] = *(uint *)(param_1 + 0x1c) ^ puVar10[3];
      if (local_34 == iVar4) break;
      iVar4 = iVar4 + 1;
      puVar10 = puVar10 + 4;
      puVar11 = puVar11 + 4;
    }
    iVar4 = uVar2 + 1;
    param_4 = param_4 & 0xf;
    local_res8 = local_res8 + iVar4 * 4;
    param_2 = param_2 + iVar4 * 4;
  }
  if (param_4 != 0) {
    (*pcVar8)(param_1,(uint *)(param_1 + 0x10),uVar9);
    *(int *)(param_1 + 0xc) = local_34 + 1;
    uVar2 = param_4 - 1;
    if (((param_4 < 5 ||
         ((uint *)(param_1 + 0x10) < local_res8 + 1 && local_res8 < (uint *)(param_1 + 0x44) ||
         (uint *)(param_1 + 0x40) < param_2 + 1 && param_2 < (uint *)(param_1 + 0x44))) ||
         local_res8 < param_2 + 1 && param_2 < local_res8 + 1) ||
       ((((uint)local_res8 | (uint)param_2) & 3) != 0)) {
      bVar1 = *(byte *)param_2;
      *(byte *)(param_1 + 0x40) = bVar1 ^ *(byte *)(param_1 + 0x40);
      *(byte *)local_res8 = bVar1 ^ *(byte *)(param_1 + 0x10);
      if (uVar2 != 0) {
        bVar1 = *(byte *)((int)param_2 + 1);
        *(byte *)(param_1 + 0x41) = bVar1 ^ *(byte *)(param_1 + 0x41);
        *(byte *)((int)local_res8 + 1) = bVar1 ^ *(byte *)(param_1 + 0x11);
        if (param_4 != 2) {
          bVar1 = *(byte *)((int)param_2 + 2);
          *(byte *)(param_1 + 0x42) = bVar1 ^ *(byte *)(param_1 + 0x42);
          *(byte *)((int)local_res8 + 2) = bVar1 ^ *(byte *)(param_1 + 0x12);
          if (param_4 != 3) {
            bVar1 = *(byte *)((int)param_2 + 3);
            *(byte *)(param_1 + 0x43) = bVar1 ^ *(byte *)(param_1 + 0x43);
            *(byte *)((int)local_res8 + 3) = bVar1 ^ *(byte *)(param_1 + 0x13);
            if (param_4 != 4) {
              bVar1 = *(byte *)(param_2 + 1);
              *(byte *)(param_1 + 0x44) = bVar1 ^ *(byte *)(param_1 + 0x44);
              *(byte *)(local_res8 + 1) = bVar1 ^ *(byte *)(param_1 + 0x14);
              if (param_4 != 5) {
                bVar1 = *(byte *)((int)param_2 + 5);
                *(byte *)(param_1 + 0x45) = bVar1 ^ *(byte *)(param_1 + 0x45);
                *(byte *)((int)local_res8 + 5) = bVar1 ^ *(byte *)(param_1 + 0x15);
                if (param_4 != 6) {
                  bVar1 = *(byte *)((int)param_2 + 6);
                  *(byte *)(param_1 + 0x46) = bVar1 ^ *(byte *)(param_1 + 0x46);
                  *(byte *)((int)local_res8 + 6) = bVar1 ^ *(byte *)(param_1 + 0x16);
                  if (param_4 != 7) {
                    bVar1 = *(byte *)((int)param_2 + 7);
                    *(byte *)(param_1 + 0x47) = bVar1 ^ *(byte *)(param_1 + 0x47);
                    *(byte *)((int)local_res8 + 7) = bVar1 ^ *(byte *)(param_1 + 0x17);
                    if (param_4 != 8) {
                      bVar1 = *(byte *)(param_2 + 2);
                      *(byte *)(param_1 + 0x48) = bVar1 ^ *(byte *)(param_1 + 0x48);
                      *(byte *)(local_res8 + 2) = bVar1 ^ *(byte *)(param_1 + 0x18);
                      if (param_4 != 9) {
                        bVar1 = *(byte *)((int)param_2 + 9);
                        *(byte *)(param_1 + 0x49) = bVar1 ^ *(byte *)(param_1 + 0x49);
                        *(byte *)((int)local_res8 + 9) = bVar1 ^ *(byte *)(param_1 + 0x19);
                        if (param_4 != 10) {
                          bVar1 = *(byte *)((int)param_2 + 10);
                          *(byte *)(param_1 + 0x4a) = bVar1 ^ *(byte *)(param_1 + 0x4a);
                          *(byte *)((int)local_res8 + 10) = bVar1 ^ *(byte *)(param_1 + 0x1a);
                          if (param_4 != 0xb) {
                            bVar1 = *(byte *)((int)param_2 + 0xb);
                            *(byte *)(param_1 + 0x4b) = bVar1 ^ *(byte *)(param_1 + 0x4b);
                            *(byte *)((int)local_res8 + 0xb) = bVar1 ^ *(byte *)(param_1 + 0x1b);
                            if (param_4 != 0xc) {
                              bVar1 = *(byte *)(param_2 + 3);
                              *(byte *)(param_1 + 0x4c) = bVar1 ^ *(byte *)(param_1 + 0x4c);
                              *(byte *)(local_res8 + 3) = bVar1 ^ *(byte *)(param_1 + 0x1c);
                              if (param_4 != 0xd) {
                                bVar1 = *(byte *)((int)param_2 + 0xd);
                                *(byte *)(param_1 + 0x4d) = bVar1 ^ *(byte *)(param_1 + 0x4d);
                                *(byte *)((int)local_res8 + 0xd) = bVar1 ^ *(byte *)(param_1 + 0x1d)
                                ;
                                if (param_4 != 0xe) {
                                  bVar1 = *(byte *)((int)param_2 + 0xe);
                                  *(byte *)(param_1 + 0x4e) = bVar1 ^ *(byte *)(param_1 + 0x4e);
                                  *(byte *)((int)local_res8 + 0xe) =
                                       bVar1 ^ *(byte *)(param_1 + 0x1e);
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
      iVar4 = (param_4 - 4 >> 2) + 1;
      uVar3 = iVar4 * 4;
      if (uVar2 < 3) {
        uVar3 = 0;
      }
      else {
        uVar5 = *param_2;
        *(uint *)(param_1 + 0x40) = uVar5 ^ *(uint *)(param_1 + 0x40);
        *local_res8 = uVar5 ^ *(uint *)(param_1 + 0x10);
        if (iVar4 != 1) {
          uVar5 = param_2[1];
          *(uint *)(param_1 + 0x44) = uVar5 ^ *(uint *)(param_1 + 0x44);
          local_res8[1] = uVar5 ^ *(uint *)(param_1 + 0x14);
          if (iVar4 == 3) {
            uVar5 = param_2[2];
            *(uint *)(param_1 + 0x48) = uVar5 ^ *(uint *)(param_1 + 0x48);
            local_res8[2] = uVar5 ^ *(uint *)(param_1 + 0x18);
          }
        }
        uVar2 = uVar2 + iVar4 * -4;
        if (param_4 == uVar3) goto LAB_004ee4b0;
      }
      iVar6 = param_1 + uVar3;
      iVar4 = uVar3 + 1;
      bVar1 = *(byte *)((int)param_2 + uVar3);
      *(byte *)(iVar6 + 0x40) = bVar1 ^ *(byte *)(iVar6 + 0x40);
      *(byte *)((int)local_res8 + uVar3) = bVar1 ^ *(byte *)(iVar6 + 0x10);
      if (uVar2 != 0) {
        iVar7 = param_1 + iVar4;
        bVar1 = *(byte *)((int)param_2 + iVar4);
        iVar6 = uVar3 + 2;
        *(byte *)(iVar7 + 0x40) = bVar1 ^ *(byte *)(iVar7 + 0x40);
        *(byte *)((int)local_res8 + iVar4) = bVar1 ^ *(byte *)(iVar7 + 0x10);
        if (uVar2 != 1) {
          iVar4 = param_1 + iVar6;
          bVar1 = *(byte *)((int)param_2 + iVar6);
          *(byte *)(iVar4 + 0x40) = bVar1 ^ *(byte *)(iVar4 + 0x40);
          *(byte *)((int)local_res8 + iVar6) = bVar1 ^ *(byte *)(iVar4 + 0x10);
        }
      }
    }
  }
LAB_004ee4b0:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}

