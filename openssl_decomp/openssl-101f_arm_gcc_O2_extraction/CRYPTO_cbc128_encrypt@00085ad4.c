
void CRYPTO_cbc128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  
  puVar2 = param_5;
  if ((((uint)param_5 | (uint)param_2 | (uint)param_1) & 3) == 0) {
    puVar7 = param_2;
    puVar8 = param_1;
    uVar9 = param_3;
    if (param_3 < 0x10) goto LAB_00085b6c;
    do {
      puVar5 = puVar7;
      uVar9 = uVar9 - 0x10;
      *puVar5 = *puVar8 ^ *puVar2;
      puVar5[1] = puVar8[1] ^ puVar2[1];
      puVar5[2] = puVar8[2] ^ puVar2[2];
      puVar5[3] = puVar8[3] ^ puVar2[3];
      (*param_6)(puVar5,puVar5,param_4);
      puVar7 = puVar5 + 4;
      puVar8 = puVar8 + 4;
      puVar2 = puVar5;
    } while (0xf < uVar9);
  }
  else {
    puVar7 = param_2;
    puVar8 = param_1;
    uVar9 = param_3;
    if (param_3 < 0x10) goto LAB_00085b6c;
    do {
      uVar9 = uVar9 - 0x10;
      *(byte *)puVar7 = *(byte *)puVar2 ^ *(byte *)puVar8;
      *(byte *)((int)puVar7 + 1) = *(byte *)((int)puVar2 + 1) ^ *(byte *)((int)puVar8 + 1);
      *(byte *)((int)puVar7 + 2) = *(byte *)((int)puVar2 + 2) ^ *(byte *)((int)puVar8 + 2);
      *(byte *)((int)puVar7 + 3) = *(byte *)((int)puVar2 + 3) ^ *(byte *)((int)puVar8 + 3);
      *(byte *)(puVar7 + 1) = *(byte *)(puVar2 + 1) ^ *(byte *)(puVar8 + 1);
      *(byte *)((int)puVar7 + 5) = *(byte *)((int)puVar2 + 5) ^ *(byte *)((int)puVar8 + 5);
      *(byte *)((int)puVar7 + 6) = *(byte *)((int)puVar2 + 6) ^ *(byte *)((int)puVar8 + 6);
      *(byte *)((int)puVar7 + 7) = *(byte *)((int)puVar2 + 7) ^ *(byte *)((int)puVar8 + 7);
      *(byte *)(puVar7 + 2) = *(byte *)(puVar2 + 2) ^ *(byte *)(puVar8 + 2);
      *(byte *)((int)puVar7 + 9) = *(byte *)((int)puVar2 + 9) ^ *(byte *)((int)puVar8 + 9);
      *(byte *)((int)puVar7 + 10) = *(byte *)((int)puVar2 + 10) ^ *(byte *)((int)puVar8 + 10);
      *(byte *)((int)puVar7 + 0xb) = *(byte *)((int)puVar2 + 0xb) ^ *(byte *)((int)puVar8 + 0xb);
      *(byte *)(puVar7 + 3) = *(byte *)(puVar2 + 3) ^ *(byte *)(puVar8 + 3);
      *(byte *)((int)puVar7 + 0xd) = *(byte *)((int)puVar2 + 0xd) ^ *(byte *)((int)puVar8 + 0xd);
      *(byte *)((int)puVar7 + 0xe) = *(byte *)((int)puVar2 + 0xe) ^ *(byte *)((int)puVar8 + 0xe);
      *(byte *)((int)puVar7 + 0xf) = *(byte *)((int)puVar2 + 0xf) ^ *(byte *)((int)puVar8 + 0xf);
      (*param_6)(puVar7,puVar7,param_4);
      puVar2 = puVar7;
      puVar7 = puVar7 + 4;
      puVar8 = puVar8 + 4;
    } while (0xf < uVar9);
  }
  uVar9 = param_3 - 0x10;
  param_3 = param_3 & 0xf;
  iVar6 = (uVar9 >> 4) + 1;
  puVar2 = (uint *)((int)param_2 + (uVar9 & 0xfffffff0));
  param_1 = param_1 + iVar6 * 4;
  param_2 = param_2 + iVar6 * 4;
LAB_00085b6c:
  uVar9 = 0;
  if (param_3 != 0) {
    do {
      uVar3 = uVar9;
      uVar9 = uVar3 + 1;
      *(byte *)((int)param_2 + uVar3) =
           *(byte *)((int)param_1 + uVar3) ^ *(byte *)((int)puVar2 + uVar3);
    } while (uVar9 < 0x10 && uVar9 < param_3);
    if (uVar9 < 0x10) {
      iVar6 = uVar3 + 2;
      *(byte *)((int)param_2 + uVar9) = *(byte *)((int)puVar2 + uVar9);
      if (iVar6 != 0x10) {
        iVar1 = uVar3 + 3;
        *(byte *)((int)param_2 + iVar6) = *(byte *)((int)puVar2 + iVar6);
        if (iVar1 != 0x10) {
          iVar6 = uVar3 + 4;
          *(byte *)((int)param_2 + iVar1) = *(byte *)((int)puVar2 + iVar1);
          if (iVar6 != 0x10) {
            iVar1 = uVar3 + 5;
            *(byte *)((int)param_2 + iVar6) = *(byte *)((int)puVar2 + iVar6);
            if (iVar1 != 0x10) {
              iVar6 = uVar3 + 6;
              *(byte *)((int)param_2 + iVar1) = *(byte *)((int)puVar2 + iVar1);
              if (iVar6 != 0x10) {
                iVar1 = uVar3 + 7;
                *(byte *)((int)param_2 + iVar6) = *(byte *)((int)puVar2 + iVar6);
                if (iVar1 != 0x10) {
                  iVar6 = uVar3 + 8;
                  *(byte *)((int)param_2 + iVar1) = *(byte *)((int)puVar2 + iVar1);
                  if (iVar6 != 0x10) {
                    iVar1 = uVar3 + 9;
                    *(byte *)((int)param_2 + iVar6) = *(byte *)((int)puVar2 + iVar6);
                    if (iVar1 != 0x10) {
                      iVar6 = uVar3 + 10;
                      *(byte *)((int)param_2 + iVar1) = *(byte *)((int)puVar2 + iVar1);
                      if (iVar6 != 0x10) {
                        iVar1 = uVar3 + 0xb;
                        *(byte *)((int)param_2 + iVar6) = *(byte *)((int)puVar2 + iVar6);
                        if (iVar1 != 0x10) {
                          iVar6 = uVar3 + 0xc;
                          *(byte *)((int)param_2 + iVar1) = *(byte *)((int)puVar2 + iVar1);
                          if (iVar6 != 0x10) {
                            iVar1 = uVar3 + 0xd;
                            *(byte *)((int)param_2 + iVar6) = *(byte *)((int)puVar2 + iVar6);
                            if (iVar1 != 0x10) {
                              iVar6 = uVar3 + 0xe;
                              *(byte *)((int)param_2 + iVar1) = *(byte *)((int)puVar2 + iVar1);
                              if (iVar6 != 0x10) {
                                iVar1 = uVar3 + 0xf;
                                *(byte *)((int)param_2 + iVar6) = *(byte *)((int)puVar2 + iVar6);
                                if (iVar1 != 0x10) {
                                  *(byte *)((int)param_2 + iVar1) = *(byte *)((int)puVar2 + iVar1);
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
    (*param_6)(param_2,param_2,param_4);
    puVar2 = param_2;
  }
  uVar9 = puVar2[1];
  uVar3 = puVar2[2];
  uVar4 = puVar2[3];
  *param_5 = *puVar2;
  param_5[1] = uVar9;
  param_5[2] = uVar3;
  param_5[3] = uVar4;
  return;
}

