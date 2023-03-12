
void CRYPTO_cfb128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               uint *param_6,int param_7,code *param_8)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar6;
  byte *pbVar4;
  int iVar5;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  
  uVar2 = *param_6;
  if (param_7 == 0) {
    for (; uVar2 != 0; uVar2 = uVar2 + 1 & 0xf) {
      if (param_3 == 0) goto LAB_005e9d0c;
      bVar6 = *(byte *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      param_3 = param_3 - 1;
      *(byte *)param_2 = bVar6 ^ *(byte *)((int)param_5 + uVar2);
      *(byte *)((int)param_5 + uVar2) = bVar6;
      param_2 = (uint *)((int)param_2 + 1);
    }
    if ((((uint)param_5 | (uint)param_1 | (uint)param_2) & 3) != 0) {
      puVar12 = (uint *)((int)param_1 + param_3);
      if (param_3 != 0) {
        param_3 = 0;
        do {
          (*param_8)(param_5,param_5,param_4);
          puVar11 = param_2;
          do {
            pbVar4 = (byte *)((int)param_5 + param_3);
            bVar6 = *(byte *)param_1;
            param_2 = (uint *)((int)puVar11 + 1);
            param_1 = (uint *)((int)param_1 + 1);
            param_3 = param_3 + 1 & 0xf;
            *(byte *)puVar11 = bVar6 ^ *pbVar4;
            *pbVar4 = bVar6;
            if (param_1 == puVar12) goto LAB_005e9c0c;
            puVar11 = param_2;
          } while (param_3 != 0);
        } while( true );
      }
      goto LAB_005e9c0c;
    }
    uVar2 = param_3;
    puVar12 = param_1;
    puVar11 = param_2;
    if (param_3 < 0x10) {
      if (param_3 == 0) goto LAB_005e9e10;
      (*param_8)(param_5,param_5,param_4);
      iVar5 = param_3 - 1;
    }
    else {
      do {
        (*param_8)(param_5,param_5,param_4);
        uVar3 = *puVar12;
        uVar2 = uVar2 - 0x10;
        *puVar11 = *param_5 ^ uVar3;
        *param_5 = uVar3;
        uVar3 = puVar12[1];
        puVar11[1] = param_5[1] ^ uVar3;
        param_5[1] = uVar3;
        uVar3 = puVar12[2];
        puVar11[2] = param_5[2] ^ uVar3;
        param_5[2] = uVar3;
        uVar3 = puVar12[3];
        puVar11[3] = param_5[3] ^ uVar3;
        param_5[3] = uVar3;
        puVar12 = puVar12 + 4;
        puVar11 = puVar11 + 4;
      } while (0xf < uVar2);
      iVar5 = (param_3 - 0x10 >> 4) + 1;
      param_2 = param_2 + iVar5 * 4;
      param_1 = param_1 + iVar5 * 4;
      if ((param_3 & 0xf) == 0) goto LAB_005e9e10;
      iVar5 = (param_3 - 0x11) - (param_3 - 0x10 & 0xfffffff0);
      (*param_8)(param_5,param_5,param_4);
    }
    uVar2 = iVar5 + 1;
    if (((uVar2 < 7 ||
         (param_2 < param_1 + 1 && param_1 < param_2 + 1 ||
         param_5 < param_1 + 1 && param_1 < param_5 + 1)) ||
         param_5 < param_2 + 1 && param_2 < param_5 + 1) ||
       ((((uint)param_2 | (uint)param_5 | (uint)param_1) & 3) != 0)) {
      bVar6 = *(byte *)param_1;
      *(byte *)param_2 = bVar6 ^ *(byte *)param_5;
      *(byte *)param_5 = bVar6;
      if (iVar5 != 0) {
        bVar6 = *(byte *)((int)param_1 + 1);
        *(byte *)((int)param_2 + 1) = bVar6 ^ *(byte *)((int)param_5 + 1);
        *(byte *)((int)param_5 + 1) = bVar6;
        if (iVar5 != 1) {
          bVar6 = *(byte *)((int)param_1 + 2);
          *(byte *)((int)param_2 + 2) = bVar6 ^ *(byte *)((int)param_5 + 2);
          *(byte *)((int)param_5 + 2) = bVar6;
          if (iVar5 != 2) {
            bVar6 = *(byte *)((int)param_1 + 3);
            *(byte *)((int)param_2 + 3) = bVar6 ^ *(byte *)((int)param_5 + 3);
            *(byte *)((int)param_5 + 3) = bVar6;
            if (iVar5 != 3) {
              bVar6 = *(byte *)(param_1 + 1);
              *(byte *)(param_2 + 1) = bVar6 ^ *(byte *)(param_5 + 1);
              *(byte *)(param_5 + 1) = bVar6;
              if (iVar5 != 4) {
                bVar6 = *(byte *)((int)param_1 + 5);
                *(byte *)((int)param_2 + 5) = bVar6 ^ *(byte *)((int)param_5 + 5);
                *(byte *)((int)param_5 + 5) = bVar6;
                if (iVar5 != 5) {
                  bVar6 = *(byte *)((int)param_1 + 6);
                  *(byte *)((int)param_2 + 6) = bVar6 ^ *(byte *)((int)param_5 + 6);
                  *(byte *)((int)param_5 + 6) = bVar6;
                  if (iVar5 != 6) {
                    bVar6 = *(byte *)((int)param_1 + 7);
                    *(byte *)((int)param_2 + 7) = bVar6 ^ *(byte *)((int)param_5 + 7);
                    *(byte *)((int)param_5 + 7) = bVar6;
                    if (iVar5 != 7) {
                      bVar6 = *(byte *)(param_1 + 2);
                      *(byte *)(param_2 + 2) = bVar6 ^ *(byte *)(param_5 + 2);
                      *(byte *)(param_5 + 2) = bVar6;
                      if (iVar5 != 8) {
                        bVar6 = *(byte *)((int)param_1 + 9);
                        *(byte *)((int)param_2 + 9) = bVar6 ^ *(byte *)((int)param_5 + 9);
                        *(byte *)((int)param_5 + 9) = bVar6;
                        if (iVar5 != 9) {
                          bVar6 = *(byte *)((int)param_1 + 10);
                          *(byte *)((int)param_2 + 10) = bVar6 ^ *(byte *)((int)param_5 + 10);
                          *(byte *)((int)param_5 + 10) = bVar6;
                          if (iVar5 != 10) {
                            bVar6 = *(byte *)((int)param_1 + 0xb);
                            *(byte *)((int)param_2 + 0xb) = bVar6 ^ *(byte *)((int)param_5 + 0xb);
                            *(byte *)((int)param_5 + 0xb) = bVar6;
                            if (iVar5 != 0xb) {
                              bVar6 = *(byte *)(param_1 + 3);
                              *(byte *)(param_2 + 3) = bVar6 ^ *(byte *)(param_5 + 3);
                              *(byte *)(param_5 + 3) = bVar6;
                              if (iVar5 != 0xc) {
                                bVar6 = *(byte *)((int)param_1 + 0xd);
                                *(byte *)((int)param_2 + 0xd) =
                                     bVar6 ^ *(byte *)((int)param_5 + 0xd);
                                *(byte *)((int)param_5 + 0xd) = bVar6;
                                if (iVar5 != 0xd) {
                                  bVar6 = *(byte *)((int)param_1 + 0xe);
                                  *(byte *)((int)param_2 + 0xe) =
                                       bVar6 ^ *(byte *)((int)param_5 + 0xe);
                                  *(byte *)((int)param_5 + 0xe) = bVar6;
                                  *param_6 = uVar2;
                                  return;
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
      uVar8 = *param_1;
      iVar7 = (iVar5 - 3U >> 2) + 1;
      *param_2 = uVar8 ^ *param_5;
      uVar3 = iVar7 * 4;
      *param_5 = uVar8;
      if (iVar7 != 1) {
        uVar8 = param_1[1];
        param_2[1] = uVar8 ^ param_5[1];
        param_5[1] = uVar8;
        if (iVar7 == 3) {
          uVar8 = param_1[2];
          param_2[2] = uVar8 ^ param_5[2];
          param_5[2] = uVar8;
        }
      }
      iVar5 = iVar5 + iVar7 * -4;
      if (uVar2 != uVar3) {
        iVar10 = uVar3 + 1;
        bVar6 = *(byte *)(param_1 + iVar7);
        *(byte *)(param_2 + iVar7) = bVar6 ^ *(byte *)(param_5 + iVar7);
        *(byte *)(param_5 + iVar7) = bVar6;
        if (iVar5 != 0) {
          bVar6 = *(byte *)((int)param_1 + iVar10);
          iVar7 = uVar3 + 2;
          *(byte *)((int)param_2 + iVar10) = bVar6 ^ *(byte *)((int)param_5 + iVar10);
          *(byte *)((int)param_5 + iVar10) = bVar6;
          if (iVar5 != 1) {
            bVar6 = *(byte *)((int)param_1 + iVar7);
            *(byte *)((int)param_2 + iVar7) = bVar6 ^ *(byte *)((int)param_5 + iVar7);
            *(byte *)((int)param_5 + iVar7) = bVar6;
            *param_6 = uVar2;
            return;
          }
        }
      }
    }
  }
  else {
    for (; uVar2 != 0; uVar2 = uVar2 + 1 & 0xf) {
      if (param_3 == 0) goto LAB_005e9d0c;
      bVar6 = *(byte *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      param_3 = param_3 - 1;
      bVar6 = bVar6 ^ *(byte *)((int)param_5 + uVar2);
      *(byte *)((int)param_5 + uVar2) = bVar6;
      *(byte *)param_2 = bVar6;
      param_2 = (uint *)((int)param_2 + 1);
    }
    if ((((uint)param_5 | (uint)param_1 | (uint)param_2) & 3) != 0) {
      puVar12 = (uint *)((int)param_1 + param_3);
      if (param_3 != 0) {
        param_3 = 0;
        do {
          if (param_3 == 0) {
            (*param_8)(param_5,param_5,param_4);
          }
          pbVar4 = (byte *)((int)param_5 + param_3);
          bVar6 = *(byte *)param_1;
          param_1 = (uint *)((int)param_1 + 1);
          param_3 = param_3 + 1 & 0xf;
          bVar6 = *pbVar4 ^ bVar6;
          *pbVar4 = bVar6;
          *(byte *)param_2 = bVar6;
          param_2 = (uint *)((int)param_2 + 1);
        } while (puVar12 != param_1);
      }
LAB_005e9c0c:
      *param_6 = param_3;
      return;
    }
    uVar2 = param_3;
    puVar12 = param_1;
    puVar11 = param_2;
    if (param_3 < 0x10) {
      if (param_3 == 0) goto LAB_005e9e10;
      (*param_8)(param_5,param_5,param_4);
      iVar5 = param_3 - 1;
    }
    else {
      do {
        (*param_8)(param_5,param_5,param_4);
        uVar8 = *puVar12;
        uVar3 = *param_5;
        uVar2 = uVar2 - 0x10;
        *param_5 = uVar3 ^ uVar8;
        *puVar11 = uVar3 ^ uVar8;
        uVar8 = puVar12[1];
        uVar3 = param_5[1];
        param_5[1] = uVar3 ^ uVar8;
        puVar11[1] = uVar3 ^ uVar8;
        uVar8 = puVar12[2];
        uVar3 = param_5[2];
        param_5[2] = uVar3 ^ uVar8;
        puVar11[2] = uVar3 ^ uVar8;
        uVar8 = puVar12[3];
        uVar3 = param_5[3];
        param_5[3] = uVar3 ^ uVar8;
        puVar11[3] = uVar3 ^ uVar8;
        puVar12 = puVar12 + 4;
        puVar11 = puVar11 + 4;
      } while (0xf < uVar2);
      iVar5 = (param_3 - 0x10 >> 4) + 1;
      param_2 = param_2 + iVar5 * 4;
      param_1 = param_1 + iVar5 * 4;
      if ((param_3 & 0xf) == 0) {
LAB_005e9e10:
        *param_6 = 0;
        return;
      }
      iVar5 = (param_3 - 0x11) - (param_3 - 0x10 & 0xfffffff0);
      (*param_8)(param_5,param_5,param_4);
    }
    uVar2 = iVar5 + 1;
    if (((uVar2 < 7 ||
         (param_1 < param_5 + 1 && param_5 < param_1 + 1 ||
         param_1 < param_2 + 1 && param_2 < param_1 + 1)) ||
         param_2 < param_5 + 1 && param_5 < param_2 + 1) ||
       ((((uint)param_2 | (uint)param_1 | (uint)param_5) & 3) != 0)) {
      bVar6 = *(byte *)param_5;
      bVar1 = *(byte *)param_1;
      *(byte *)param_5 = bVar6 ^ bVar1;
      *(byte *)param_2 = bVar6 ^ bVar1;
      if (iVar5 != 0) {
        bVar6 = *(byte *)((int)param_5 + 1) ^ *(byte *)((int)param_1 + 1);
        *(byte *)((int)param_5 + 1) = bVar6;
        *(byte *)((int)param_2 + 1) = bVar6;
        if (iVar5 != 1) {
          bVar6 = *(byte *)((int)param_5 + 2) ^ *(byte *)((int)param_1 + 2);
          *(byte *)((int)param_5 + 2) = bVar6;
          *(byte *)((int)param_2 + 2) = bVar6;
          if (iVar5 != 2) {
            bVar6 = *(byte *)((int)param_5 + 3) ^ *(byte *)((int)param_1 + 3);
            *(byte *)((int)param_5 + 3) = bVar6;
            *(byte *)((int)param_2 + 3) = bVar6;
            if (iVar5 != 3) {
              bVar6 = *(byte *)(param_5 + 1);
              bVar1 = *(byte *)(param_1 + 1);
              *(byte *)(param_5 + 1) = bVar6 ^ bVar1;
              *(byte *)(param_2 + 1) = bVar6 ^ bVar1;
              if (iVar5 != 4) {
                bVar6 = *(byte *)((int)param_5 + 5) ^ *(byte *)((int)param_1 + 5);
                *(byte *)((int)param_5 + 5) = bVar6;
                *(byte *)((int)param_2 + 5) = bVar6;
                if (iVar5 != 5) {
                  bVar6 = *(byte *)((int)param_5 + 6) ^ *(byte *)((int)param_1 + 6);
                  *(byte *)((int)param_5 + 6) = bVar6;
                  *(byte *)((int)param_2 + 6) = bVar6;
                  if (iVar5 != 6) {
                    bVar6 = *(byte *)((int)param_5 + 7) ^ *(byte *)((int)param_1 + 7);
                    *(byte *)((int)param_5 + 7) = bVar6;
                    *(byte *)((int)param_2 + 7) = bVar6;
                    if (iVar5 != 7) {
                      bVar6 = *(byte *)(param_5 + 2);
                      bVar1 = *(byte *)(param_1 + 2);
                      *(byte *)(param_5 + 2) = bVar6 ^ bVar1;
                      *(byte *)(param_2 + 2) = bVar6 ^ bVar1;
                      if (iVar5 != 8) {
                        bVar6 = *(byte *)((int)param_5 + 9) ^ *(byte *)((int)param_1 + 9);
                        *(byte *)((int)param_5 + 9) = bVar6;
                        *(byte *)((int)param_2 + 9) = bVar6;
                        if (iVar5 != 9) {
                          bVar6 = *(byte *)((int)param_5 + 10) ^ *(byte *)((int)param_1 + 10);
                          *(byte *)((int)param_5 + 10) = bVar6;
                          *(byte *)((int)param_2 + 10) = bVar6;
                          if (iVar5 != 10) {
                            bVar6 = *(byte *)((int)param_5 + 0xb) ^ *(byte *)((int)param_1 + 0xb);
                            *(byte *)((int)param_5 + 0xb) = bVar6;
                            *(byte *)((int)param_2 + 0xb) = bVar6;
                            if (iVar5 != 0xb) {
                              bVar6 = *(byte *)(param_5 + 3);
                              bVar1 = *(byte *)(param_1 + 3);
                              *(byte *)(param_5 + 3) = bVar6 ^ bVar1;
                              *(byte *)(param_2 + 3) = bVar6 ^ bVar1;
                              if (iVar5 != 0xc) {
                                bVar6 = *(byte *)((int)param_5 + 0xd) ^
                                        *(byte *)((int)param_1 + 0xd);
                                *(byte *)((int)param_5 + 0xd) = bVar6;
                                *(byte *)((int)param_2 + 0xd) = bVar6;
                                if (iVar5 != 0xd) {
                                  bVar6 = *(byte *)((int)param_5 + 0xe) ^
                                          *(byte *)((int)param_1 + 0xe);
                                  *(byte *)((int)param_5 + 0xe) = bVar6;
                                  *(byte *)((int)param_2 + 0xe) = bVar6;
                                  *param_6 = uVar2;
                                  return;
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
      uVar3 = *param_1;
      uVar9 = *param_5;
      iVar7 = (iVar5 - 3U >> 2) + 1;
      *param_5 = uVar3 ^ uVar9;
      uVar8 = iVar7 * 4;
      *param_2 = uVar3 ^ uVar9;
      if (iVar7 != 1) {
        uVar3 = param_1[1];
        uVar9 = param_5[1];
        param_5[1] = uVar3 ^ uVar9;
        param_2[1] = uVar3 ^ uVar9;
        if (iVar7 == 3) {
          uVar3 = param_5[2];
          uVar9 = param_1[2];
          param_5[2] = uVar3 ^ uVar9;
          param_2[2] = uVar3 ^ uVar9;
        }
      }
      iVar5 = iVar5 + iVar7 * -4;
      if (uVar8 != uVar2) {
        iVar10 = uVar8 + 1;
        bVar6 = *(byte *)(param_1 + iVar7) ^ *(byte *)(param_5 + iVar7);
        *(byte *)(param_5 + iVar7) = bVar6;
        *(byte *)(param_2 + iVar7) = bVar6;
        if (iVar5 != 0) {
          iVar7 = uVar8 + 2;
          bVar6 = *(byte *)((int)param_1 + iVar10) ^ *(byte *)((int)param_5 + iVar10);
          *(byte *)((int)param_5 + iVar10) = bVar6;
          *(byte *)((int)param_2 + iVar10) = bVar6;
          if (iVar5 != 1) {
            bVar6 = *(byte *)((int)param_1 + iVar7) ^ *(byte *)((int)param_5 + iVar7);
            *(byte *)((int)param_5 + iVar7) = bVar6;
            *(byte *)((int)param_2 + iVar7) = bVar6;
            *param_6 = uVar2;
            return;
          }
        }
      }
    }
  }
  goto LAB_005e9d20;
LAB_005e9d0c:
  param_3 = uVar2;
  if ((((uint)param_5 | (uint)param_1 | (uint)param_2) & 3) != 0) goto LAB_005e9c0c;
LAB_005e9d20:
  *param_6 = uVar2;
  return;
}

