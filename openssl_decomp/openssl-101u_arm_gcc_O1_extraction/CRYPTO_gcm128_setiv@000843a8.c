
void CRYPTO_gcm128_setiv(uint *param_1,uint *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  uint *puVar10;
  
  pcVar9 = (code *)param_1[0x58];
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x5b] = 0;
  param_1[0x5a] = 0;
  if (param_3 == 0xc) {
    iVar7 = 2;
    uVar8 = param_2[1];
    uVar4 = param_2[2];
    *param_1 = *param_2;
    param_1[1] = uVar8;
    param_1[2] = uVar4;
    *(undefined *)((int)param_1 + 0xf) = 1;
    goto LAB_000845e2;
  }
  puVar10 = param_1 + 0x18;
  puVar6 = param_2;
  uVar8 = param_3;
  if (0xf < param_3) {
    do {
      uVar8 = uVar8 - 0x10;
      *(byte *)param_1 = *(byte *)puVar6 ^ *(byte *)param_1;
      *(byte *)((int)param_1 + 1) = *(byte *)((int)puVar6 + 1) ^ *(byte *)((int)param_1 + 1);
      *(byte *)((int)param_1 + 2) = *(byte *)((int)puVar6 + 2) ^ *(byte *)((int)param_1 + 2);
      *(byte *)((int)param_1 + 3) = *(byte *)((int)puVar6 + 3) ^ *(byte *)((int)param_1 + 3);
      *(byte *)(param_1 + 1) = *(byte *)(puVar6 + 1) ^ *(byte *)(param_1 + 1);
      *(byte *)((int)param_1 + 5) = *(byte *)((int)puVar6 + 5) ^ *(byte *)((int)param_1 + 5);
      *(byte *)((int)param_1 + 6) = *(byte *)((int)puVar6 + 6) ^ *(byte *)((int)param_1 + 6);
      *(byte *)((int)param_1 + 7) = *(byte *)((int)puVar6 + 7) ^ *(byte *)((int)param_1 + 7);
      *(byte *)(param_1 + 2) = *(byte *)(puVar6 + 2) ^ *(byte *)(param_1 + 2);
      *(byte *)((int)param_1 + 9) = *(byte *)((int)puVar6 + 9) ^ *(byte *)((int)param_1 + 9);
      *(byte *)((int)param_1 + 10) = *(byte *)((int)puVar6 + 10) ^ *(byte *)((int)param_1 + 10);
      *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)puVar6 + 0xb);
      *(byte *)(param_1 + 3) = *(byte *)(puVar6 + 3) ^ *(byte *)(param_1 + 3);
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)puVar6 + 0xd) ^ *(byte *)((int)param_1 + 0xd);
      *(byte *)((int)param_1 + 0xe) = *(byte *)((int)puVar6 + 0xe) ^ *(byte *)((int)param_1 + 0xe);
      bVar1 = *(byte *)((int)puVar6 + 0xf);
      bVar2 = *(byte *)((int)param_1 + 0xf) ^ bVar1;
      *(byte *)((int)param_1 + 0xf) = bVar2;
      (*pcVar9)(param_1,puVar10,bVar1,bVar2,param_4);
      puVar6 = puVar6 + 4;
    } while (0xf < uVar8);
    uVar8 = param_3 & 0xf;
    param_2 = (uint *)((int)param_2 + (param_3 - 0x10 & 0xfffffff0) + 0x10);
  }
  if (uVar8 != 0) {
    uVar4 = (uint)(param_1 + 1 <= param_2 || param_2 + 1 <= param_1);
    uVar5 = (uint)(5 < uVar8);
    if (((uint)param_2 & 3) != 0) {
      uVar4 = 0;
    }
    if ((uVar5 & uVar4) == 0) {
      uVar4 = (uint)(*(byte *)param_1 ^ *(byte *)param_2);
      *(byte *)param_1 = *(byte *)param_1 ^ *(byte *)param_2;
      if (1 < uVar8) {
        bVar1 = *(byte *)((int)param_1 + 1) ^ *(byte *)((int)param_2 + 1);
        uVar4 = (uint)bVar1;
        *(byte *)((int)param_1 + 1) = bVar1;
        if (2 < uVar8) {
          bVar1 = *(byte *)((int)param_1 + 2) ^ *(byte *)((int)param_2 + 2);
          uVar4 = (uint)bVar1;
          *(byte *)((int)param_1 + 2) = bVar1;
          if (3 < uVar8) {
            bVar1 = *(byte *)((int)param_1 + 3) ^ *(byte *)((int)param_2 + 3);
            uVar4 = (uint)bVar1;
            *(byte *)((int)param_1 + 3) = bVar1;
            if (4 < uVar8) {
              uVar4 = (uint)(*(byte *)(param_1 + 1) ^ *(byte *)(param_2 + 1));
              *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) ^ *(byte *)(param_2 + 1);
              if (uVar5 != 0) {
                uVar4 = (uint)*(byte *)((int)param_2 + 5);
                bVar1 = *(byte *)((int)param_1 + 5) ^ *(byte *)((int)param_2 + 5);
                uVar5 = (uint)bVar1;
                *(byte *)((int)param_1 + 5) = bVar1;
                if (6 < uVar8) {
                  uVar4 = (uint)*(byte *)((int)param_2 + 6);
                  bVar1 = *(byte *)((int)param_1 + 6) ^ *(byte *)((int)param_2 + 6);
                  uVar5 = (uint)bVar1;
                  *(byte *)((int)param_1 + 6) = bVar1;
                  if (7 < uVar8) {
                    uVar4 = (uint)*(byte *)((int)param_2 + 7);
                    bVar1 = *(byte *)((int)param_1 + 7) ^ *(byte *)((int)param_2 + 7);
                    uVar5 = (uint)bVar1;
                    *(byte *)((int)param_1 + 7) = bVar1;
                    if (8 < uVar8) {
                      uVar4 = (uint)*(byte *)(param_2 + 2);
                      bVar1 = *(byte *)(param_1 + 2) ^ *(byte *)(param_2 + 2);
                      uVar5 = (uint)bVar1;
                      *(byte *)(param_1 + 2) = bVar1;
                      if (9 < uVar8) {
                        uVar4 = (uint)*(byte *)((int)param_2 + 9);
                        bVar1 = *(byte *)((int)param_1 + 9) ^ *(byte *)((int)param_2 + 9);
                        uVar5 = (uint)bVar1;
                        *(byte *)((int)param_1 + 9) = bVar1;
                        if (10 < uVar8) {
                          uVar4 = (uint)*(byte *)((int)param_2 + 10);
                          bVar1 = *(byte *)((int)param_1 + 10) ^ *(byte *)((int)param_2 + 10);
                          uVar5 = (uint)bVar1;
                          *(byte *)((int)param_1 + 10) = bVar1;
                          if (0xb < uVar8) {
                            uVar4 = (uint)*(byte *)((int)param_2 + 0xb);
                            bVar1 = *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)param_2 + 0xb);
                            uVar5 = (uint)bVar1;
                            *(byte *)((int)param_1 + 0xb) = bVar1;
                            if (0xc < uVar8) {
                              uVar4 = (uint)*(byte *)(param_2 + 3);
                              bVar1 = *(byte *)(param_1 + 3) ^ *(byte *)(param_2 + 3);
                              uVar5 = (uint)bVar1;
                              *(byte *)(param_1 + 3) = bVar1;
                              if (0xd < uVar8) {
                                bVar1 = *(byte *)((int)param_2 + 0xd);
                                bVar2 = *(byte *)((int)param_1 + 0xd) ^ bVar1;
                                *(byte *)((int)param_1 + 0xd) = bVar2;
                                if (0xe < uVar8) {
                                  bVar1 = *(byte *)((int)param_2 + 0xe);
                                  bVar2 = *(byte *)((int)param_1 + 0xe) ^ bVar1;
                                }
                                if (0xe < uVar8) {
                                  *(byte *)((int)param_1 + 0xe) = bVar2;
                                }
                                (*pcVar9)(param_1,puVar10,bVar1,bVar2,param_4);
                                goto LAB_0008457c;
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
      uVar5 = uVar8 >> 2;
      uVar3 = uVar8 & 0xfffffffc;
      uVar4 = *param_1 ^ *param_2;
      *param_1 = uVar4;
      if (1 < uVar5) {
        uVar4 = param_1[1] ^ param_2[1];
        param_1[1] = uVar4;
        if (2 < uVar5) {
          uVar4 = param_2[2] ^ param_1[2];
          param_1[2] = uVar4;
        }
      }
      if (uVar3 != uVar8) {
        uVar4 = uVar3 + 1;
        *(byte *)((int)param_1 + (uVar8 & 0xfffffffc)) =
             *(byte *)((int)param_1 + (uVar8 & 0xfffffffc)) ^
             *(byte *)((int)param_2 + (uVar8 & 0xfffffffc));
        if (uVar4 < uVar8) {
          uVar5 = uVar3 + 2;
          *(byte *)((int)param_1 + uVar4) =
               *(byte *)((int)param_1 + uVar4) ^ *(byte *)((int)param_2 + uVar4);
          if (uVar5 < uVar8) {
            bVar1 = *(byte *)((int)param_1 + uVar5) ^ *(byte *)((int)param_2 + uVar5);
            uVar4 = (uint)bVar1;
            *(byte *)((int)param_1 + uVar5) = bVar1;
          }
        }
      }
    }
    (*pcVar9)(param_1,puVar10,uVar4,uVar5,param_4);
  }
LAB_0008457c:
  uVar4 = param_3 << 3;
  uVar8 = (uVar4 >> 8 | (param_3 >> 0x1d) << 0x18) ^ (uint)*(byte *)((int)param_1 + 0xe);
  uVar5 = uVar4 ^ *(byte *)((int)param_1 + 0xf);
  *(byte *)(param_1 + 3) = (byte)(uVar4 >> 0x18) ^ *(byte *)(param_1 + 3);
  *(byte *)((int)param_1 + 0xd) = (byte)(uVar4 >> 0x10) ^ *(byte *)((int)param_1 + 0xd);
  *(char *)((int)param_1 + 0xe) = (char)uVar8;
  *(char *)((int)param_1 + 0xf) = (char)uVar5;
  *(byte *)((int)param_1 + 0xb) = (byte)(param_3 >> 0x1d) ^ *(byte *)((int)param_1 + 0xb);
  (*pcVar9)(param_1,puVar10,uVar8,uVar5,param_4);
  iVar7 = ((uint)*(byte *)((int)param_1 + 0xf) |
           (uint)*(byte *)((int)param_1 + 0xd) << 0x10 | (uint)*(byte *)(param_1 + 3) << 0x18 |
          (uint)*(byte *)((int)param_1 + 0xe) << 8) + 1;
LAB_000845e2:
  (*(code *)param_1[0x5c])(param_1,param_1 + 8,param_1[0x5d]);
  *(char *)((int)param_1 + 0xf) = (char)iVar7;
  *(char *)(param_1 + 3) = (char)((uint)iVar7 >> 0x18);
  *(char *)((int)param_1 + 0xd) = (char)((uint)iVar7 >> 0x10);
  *(char *)((int)param_1 + 0xe) = (char)((uint)iVar7 >> 8);
  return;
}

