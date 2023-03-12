
void CRYPTO_cfb128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,int param_5,
               uint *param_6,int param_7,code *param_8)

{
  uint uVar1;
  byte bVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint local_34;
  int local_30;
  
  uVar11 = *param_6;
  if (param_7 == 0) {
    if ((uVar11 != 0) && (param_3 != 0)) {
      do {
        pbVar14 = param_1 + 1;
        pbVar13 = (byte *)(param_5 + uVar11);
        pbVar9 = param_2 + 1;
        param_3 = param_3 - 1;
        bVar2 = *param_1;
        uVar11 = uVar11 + 1 & 0xf;
        *param_2 = bVar2 ^ *pbVar13;
        *pbVar13 = bVar2;
        param_1 = pbVar14;
        param_2 = pbVar9;
        if (uVar11 == 0) break;
      } while (param_3 != 0);
    }
    if (param_3 < 0x10) {
      if (param_3 != 0) {
        (*param_8)(param_5,param_5,param_4);
        local_30 = param_3 - 1;
LAB_081b4c81:
        puVar3 = (uint *)(param_5 + uVar11);
        puVar4 = (uint *)(param_1 + uVar11);
        puVar5 = (uint *)(param_2 + uVar11);
        iVar10 = uVar11 + 4;
        if ((((puVar4 < param_2 + iVar10 && puVar5 < param_1 + iVar10 ||
              puVar4 < (uint *)(iVar10 + param_5) && puVar3 < param_1 + iVar10) || local_30 + 1U < 7
             ) || puVar5 < (uint *)(iVar10 + param_5) && puVar3 < param_2 + iVar10) ||
           ((((uint)puVar5 | (uint)puVar3 | (uint)puVar4) & 3) != 0)) {
          bVar2 = *(byte *)puVar4;
          *(byte *)puVar5 = bVar2 ^ *(byte *)puVar3;
          *(byte *)puVar3 = bVar2;
          if (local_30 != 0) {
            pbVar13 = (byte *)(uVar11 + 1 + param_5);
            bVar2 = param_1[uVar11 + 1];
            param_2[uVar11 + 1] = bVar2 ^ *pbVar13;
            *pbVar13 = bVar2;
            if (local_30 != 1) {
              pbVar13 = (byte *)(uVar11 + 2 + param_5);
              bVar2 = param_1[uVar11 + 2];
              param_2[uVar11 + 2] = bVar2 ^ *pbVar13;
              *pbVar13 = bVar2;
              if (local_30 != 2) {
                pbVar13 = (byte *)(uVar11 + 3 + param_5);
                bVar2 = param_1[uVar11 + 3];
                param_2[uVar11 + 3] = bVar2 ^ *pbVar13;
                *pbVar13 = bVar2;
                if (local_30 != 3) {
                  bVar2 = param_1[uVar11 + 4];
                  param_2[uVar11 + 4] = bVar2 ^ *(byte *)(iVar10 + param_5);
                  *(byte *)(iVar10 + param_5) = bVar2;
                  if (local_30 != 4) {
                    pbVar13 = (byte *)(uVar11 + 5 + param_5);
                    bVar2 = param_1[uVar11 + 5];
                    param_2[uVar11 + 5] = bVar2 ^ *pbVar13;
                    *pbVar13 = bVar2;
                    if (local_30 != 5) {
                      pbVar13 = (byte *)(uVar11 + 6 + param_5);
                      bVar2 = param_1[uVar11 + 6];
                      param_2[uVar11 + 6] = bVar2 ^ *pbVar13;
                      *pbVar13 = bVar2;
                      if (local_30 != 6) {
                        pbVar13 = (byte *)(uVar11 + 7 + param_5);
                        bVar2 = param_1[uVar11 + 7];
                        param_2[uVar11 + 7] = bVar2 ^ *pbVar13;
                        *pbVar13 = bVar2;
                        if (local_30 != 7) {
                          pbVar13 = (byte *)(uVar11 + 8 + param_5);
                          bVar2 = param_1[uVar11 + 8];
                          param_2[uVar11 + 8] = bVar2 ^ *pbVar13;
                          *pbVar13 = bVar2;
                          if (local_30 != 8) {
                            pbVar13 = (byte *)(uVar11 + 9 + param_5);
                            bVar2 = param_1[uVar11 + 9];
                            param_2[uVar11 + 9] = bVar2 ^ *pbVar13;
                            *pbVar13 = bVar2;
                            if (local_30 != 9) {
                              pbVar13 = (byte *)(uVar11 + 10 + param_5);
                              bVar2 = param_1[uVar11 + 10];
                              param_2[uVar11 + 10] = bVar2 ^ *pbVar13;
                              *pbVar13 = bVar2;
                              if (local_30 != 10) {
                                pbVar13 = (byte *)(uVar11 + 0xb + param_5);
                                bVar2 = param_1[uVar11 + 0xb];
                                param_2[uVar11 + 0xb] = bVar2 ^ *pbVar13;
                                *pbVar13 = bVar2;
                                if (local_30 != 0xb) {
                                  pbVar13 = (byte *)(uVar11 + 0xc + param_5);
                                  bVar2 = param_1[uVar11 + 0xc];
                                  param_2[uVar11 + 0xc] = bVar2 ^ *pbVar13;
                                  *pbVar13 = bVar2;
                                  if (local_30 != 0xc) {
                                    pbVar13 = (byte *)(uVar11 + 0xd + param_5);
                                    bVar2 = param_1[uVar11 + 0xd];
                                    param_2[uVar11 + 0xd] = bVar2 ^ *pbVar13;
                                    *pbVar13 = bVar2;
                                    if (local_30 != 0xd) {
                                      pbVar13 = (byte *)(uVar11 + 0xe + param_5);
                                      bVar2 = param_1[uVar11 + 0xe];
                                      param_2[uVar11 + 0xe] = bVar2 ^ *pbVar13;
                                      *pbVar13 = bVar2;
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
          iVar10 = (local_30 - 3U >> 2) + 1;
          uVar12 = *puVar4;
          *puVar5 = *puVar3 ^ uVar12;
          *puVar3 = uVar12;
          if (iVar10 != 1) {
            uVar12 = puVar4[1];
            puVar5[1] = puVar3[1] ^ uVar12;
            puVar3[1] = uVar12;
            if (iVar10 == 3) {
              uVar12 = puVar4[2];
              puVar5[2] = puVar3[2] ^ uVar12;
              puVar3[2] = uVar12;
            }
          }
          iVar8 = local_30 + iVar10 * -4;
          iVar7 = uVar11 + iVar10 * 4;
          if (local_30 + 1U != iVar10 * 4) {
            bVar2 = param_1[iVar7];
            param_2[iVar7] = bVar2 ^ *(byte *)(param_5 + iVar7);
            *(byte *)(param_5 + iVar7) = bVar2;
            if (iVar8 != 0) {
              pbVar13 = (byte *)(iVar7 + 1 + param_5);
              bVar2 = param_1[iVar7 + 1];
              param_2[iVar7 + 1] = bVar2 ^ *pbVar13;
              *pbVar13 = bVar2;
              if (iVar8 != 1) {
                pbVar13 = (byte *)(iVar7 + 2 + param_5);
                bVar2 = param_1[iVar7 + 2];
                param_2[iVar7 + 2] = bVar2 ^ *pbVar13;
                *pbVar13 = bVar2;
              }
            }
          }
        }
        *param_6 = local_30 + 1 + uVar11;
        return;
      }
    }
    else {
      local_34 = param_3;
      uVar12 = uVar11;
      pbVar13 = param_1;
      pbVar14 = param_2;
      do {
        (*param_8)(param_5,param_5,param_4);
        if (uVar12 < 0x10) {
          uVar11 = *(uint *)(pbVar13 + uVar12);
          *(uint *)(pbVar14 + uVar12) = *(uint *)(param_5 + uVar12) ^ uVar11;
          *(uint *)(param_5 + uVar12) = uVar11;
          if (uVar12 + 4 < 0x10) {
            puVar3 = (uint *)(uVar12 + 4 + param_5);
            uVar11 = *(uint *)(pbVar13 + uVar12 + 4);
            *(uint *)(pbVar14 + uVar12 + 4) = *puVar3 ^ uVar11;
            *puVar3 = uVar11;
            if (uVar12 + 8 < 0x10) {
              puVar3 = (uint *)(uVar12 + 8 + param_5);
              uVar11 = *(uint *)(pbVar13 + uVar12 + 8);
              *(uint *)(pbVar14 + uVar12 + 8) = *puVar3 ^ uVar11;
              *puVar3 = uVar11;
              if (uVar12 + 0xc < 0x10) {
                puVar3 = (uint *)(uVar12 + 0xc + param_5);
                uVar11 = *(uint *)(pbVar13 + uVar12 + 0xc);
                *(uint *)(pbVar14 + uVar12 + 0xc) = *puVar3 ^ uVar11;
                *puVar3 = uVar11;
              }
            }
          }
        }
        local_34 = local_34 - 0x10;
        pbVar14 = pbVar14 + 0x10;
        pbVar13 = pbVar13 + 0x10;
        uVar12 = 0;
      } while (0xf < local_34);
      iVar10 = ((param_3 - 0x10 >> 4) + 1) * 0x10;
      param_2 = param_2 + iVar10;
      param_1 = param_1 + iVar10;
      uVar11 = 0;
      if ((param_3 & 0xf) != 0) {
        (*param_8)(param_5,param_5,param_4);
        local_30 = (param_3 - 0x11) - (param_3 - 0x10 & 0xfffffff0);
        uVar11 = uVar12;
        goto LAB_081b4c81;
      }
    }
  }
  else {
    pbVar13 = param_2;
    pbVar14 = param_1;
    uVar12 = uVar11;
    if (param_3 != 0) {
      do {
        param_1 = pbVar14;
        param_2 = pbVar13;
        if (uVar12 == 0) break;
        pbVar9 = (byte *)(param_5 + uVar11);
        param_1 = pbVar14 + 1;
        param_2 = pbVar13 + 1;
        param_3 = param_3 - 1;
        bVar2 = *pbVar14 ^ *pbVar9;
        uVar11 = uVar11 + 1 & 0xf;
        *pbVar9 = bVar2;
        *pbVar13 = bVar2;
        pbVar13 = param_2;
        pbVar14 = param_1;
        uVar12 = param_3;
      } while (uVar11 != 0);
    }
    uVar12 = param_3;
    pbVar13 = param_1;
    pbVar14 = param_2;
    if (param_3 < 0x10) {
      if (param_3 != 0) {
        (*param_8)(param_5,param_5,param_4);
        local_34 = param_3 - 1;
LAB_081b4f7f:
        puVar4 = (uint *)(param_1 + uVar11);
        puVar5 = (uint *)(param_2 + uVar11);
        iVar10 = uVar11 + 4;
        puVar3 = (uint *)(param_5 + uVar11);
        if (((((uint *)(param_5 + uVar11) < param_1 + iVar10 && puVar4 < (uint *)(iVar10 + param_5)
              || puVar5 < param_1 + iVar10 && puVar4 < param_2 + iVar10) || local_34 + 1 < 7) ||
             puVar3 < param_2 + iVar10 && puVar5 < (uint *)(iVar10 + param_5)) ||
           ((((uint)puVar4 | (uint)puVar3 | (uint)puVar5) & 3) != 0)) {
          bVar2 = *(byte *)(param_5 + uVar11) ^ *(byte *)puVar4;
          *(byte *)(param_5 + uVar11) = bVar2;
          *(byte *)puVar5 = bVar2;
          if (local_34 != 0) {
            pbVar13 = (byte *)(uVar11 + 1 + param_5);
            bVar2 = param_1[uVar11 + 1] ^ *pbVar13;
            *pbVar13 = bVar2;
            param_2[uVar11 + 1] = bVar2;
            if (local_34 != 1) {
              pbVar13 = (byte *)(uVar11 + 2 + param_5);
              bVar2 = param_1[uVar11 + 2] ^ *pbVar13;
              *pbVar13 = bVar2;
              param_2[uVar11 + 2] = bVar2;
              if (local_34 != 2) {
                pbVar13 = (byte *)(uVar11 + 3 + param_5);
                bVar2 = param_1[uVar11 + 3] ^ *pbVar13;
                *pbVar13 = bVar2;
                param_2[uVar11 + 3] = bVar2;
                if (local_34 != 3) {
                  bVar2 = param_1[uVar11 + 4] ^ *(byte *)(iVar10 + param_5);
                  *(byte *)(iVar10 + param_5) = bVar2;
                  param_2[uVar11 + 4] = bVar2;
                  if (local_34 != 4) {
                    pbVar13 = (byte *)(uVar11 + 5 + param_5);
                    bVar2 = param_1[uVar11 + 5] ^ *pbVar13;
                    *pbVar13 = bVar2;
                    param_2[uVar11 + 5] = bVar2;
                    if (local_34 != 5) {
                      pbVar13 = (byte *)(uVar11 + 6 + param_5);
                      bVar2 = param_1[uVar11 + 6] ^ *pbVar13;
                      *pbVar13 = bVar2;
                      param_2[uVar11 + 6] = bVar2;
                      if (local_34 != 6) {
                        pbVar13 = (byte *)(uVar11 + 7 + param_5);
                        bVar2 = param_1[uVar11 + 7] ^ *pbVar13;
                        *pbVar13 = bVar2;
                        param_2[uVar11 + 7] = bVar2;
                        if (local_34 != 7) {
                          pbVar13 = (byte *)(uVar11 + 8 + param_5);
                          bVar2 = param_1[uVar11 + 8] ^ *pbVar13;
                          *pbVar13 = bVar2;
                          param_2[uVar11 + 8] = bVar2;
                          if (local_34 != 8) {
                            pbVar13 = (byte *)(uVar11 + 9 + param_5);
                            bVar2 = param_1[uVar11 + 9] ^ *pbVar13;
                            *pbVar13 = bVar2;
                            param_2[uVar11 + 9] = bVar2;
                            if (local_34 != 9) {
                              pbVar13 = (byte *)(uVar11 + 10 + param_5);
                              bVar2 = param_1[uVar11 + 10] ^ *pbVar13;
                              *pbVar13 = bVar2;
                              param_2[uVar11 + 10] = bVar2;
                              if (local_34 != 10) {
                                pbVar13 = (byte *)(uVar11 + 0xb + param_5);
                                bVar2 = param_1[uVar11 + 0xb] ^ *pbVar13;
                                *pbVar13 = bVar2;
                                param_2[uVar11 + 0xb] = bVar2;
                                if (local_34 != 0xb) {
                                  pbVar13 = (byte *)(uVar11 + 0xc + param_5);
                                  bVar2 = param_1[uVar11 + 0xc] ^ *pbVar13;
                                  *pbVar13 = bVar2;
                                  param_2[uVar11 + 0xc] = bVar2;
                                  if (local_34 != 0xc) {
                                    pbVar13 = (byte *)(uVar11 + 0xd + param_5);
                                    bVar2 = param_1[uVar11 + 0xd] ^ *pbVar13;
                                    *pbVar13 = bVar2;
                                    param_2[uVar11 + 0xd] = bVar2;
                                    if (local_34 != 0xd) {
                                      pbVar13 = (byte *)(uVar11 + 0xe + param_5);
                                      bVar2 = param_1[uVar11 + 0xe] ^ *pbVar13;
                                      *pbVar13 = bVar2;
                                      param_2[uVar11 + 0xe] = bVar2;
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
          iVar10 = (local_34 - 3 >> 2) + 1;
          uVar12 = iVar10 * 4;
          uVar6 = *puVar4;
          uVar1 = *puVar3;
          *puVar3 = uVar6 ^ uVar1;
          *puVar5 = uVar6 ^ uVar1;
          if (iVar10 != 1) {
            uVar6 = puVar4[1];
            uVar1 = puVar3[1];
            puVar3[1] = uVar6 ^ uVar1;
            puVar5[1] = uVar6 ^ uVar1;
            if (iVar10 == 3) {
              uVar6 = puVar4[2];
              uVar1 = puVar3[2];
              puVar3[2] = uVar6 ^ uVar1;
              puVar5[2] = uVar6 ^ uVar1;
            }
          }
          iVar7 = uVar12 + uVar11;
          if (local_34 + 1 != uVar12) {
            bVar2 = param_1[iVar7] ^ *(byte *)(param_5 + iVar7);
            *(byte *)(param_5 + iVar7) = bVar2;
            param_2[iVar7] = bVar2;
            if (local_34 != uVar12) {
              pbVar13 = (byte *)(iVar7 + 1 + param_5);
              bVar2 = param_1[iVar7 + 1] ^ *pbVar13;
              *pbVar13 = bVar2;
              param_2[iVar7 + 1] = bVar2;
              if (local_34 + iVar10 * -4 != 1) {
                pbVar13 = (byte *)(iVar7 + 2 + param_5);
                bVar2 = param_1[iVar7 + 2] ^ *pbVar13;
                *pbVar13 = bVar2;
                param_2[iVar7 + 2] = bVar2;
              }
            }
          }
        }
        *param_6 = local_34 + 1 + uVar11;
        return;
      }
    }
    else {
      do {
        (*param_8)(param_5,param_5,param_4);
        if (uVar11 < 0x10) {
          uVar6 = *(uint *)(pbVar13 + uVar11) ^ *(uint *)(param_5 + uVar11);
          *(uint *)(param_5 + uVar11) = uVar6;
          *(uint *)(pbVar14 + uVar11) = uVar6;
          if (uVar11 + 4 < 0x10) {
            puVar3 = (uint *)(uVar11 + 4 + param_5);
            uVar6 = *(uint *)(pbVar13 + uVar11 + 4) ^ *puVar3;
            *puVar3 = uVar6;
            *(uint *)(pbVar14 + uVar11 + 4) = uVar6;
            if (uVar11 + 8 < 0x10) {
              puVar3 = (uint *)(uVar11 + 8 + param_5);
              uVar6 = *(uint *)(pbVar13 + uVar11 + 8) ^ *puVar3;
              *puVar3 = uVar6;
              *(uint *)(pbVar14 + uVar11 + 8) = uVar6;
              if (uVar11 + 0xc < 0x10) {
                puVar3 = (uint *)(uVar11 + 0xc + param_5);
                uVar6 = *(uint *)(pbVar13 + uVar11 + 0xc) ^ *puVar3;
                *puVar3 = uVar6;
                *(uint *)(pbVar14 + uVar11 + 0xc) = uVar6;
              }
            }
          }
        }
        uVar12 = uVar12 - 0x10;
        uVar11 = 0;
        pbVar13 = pbVar13 + 0x10;
        pbVar14 = pbVar14 + 0x10;
      } while (0xf < uVar12);
      iVar10 = ((param_3 - 0x10 >> 4) + 1) * 0x10;
      param_2 = param_2 + iVar10;
      param_1 = param_1 + iVar10;
      uVar11 = 0;
      if ((param_3 & 0xf) != 0) {
        (*param_8)(param_5,param_5,param_4);
        local_34 = (param_3 - 0x11) - (param_3 - 0x10 & 0xfffffff0);
        uVar11 = 0;
        goto LAB_081b4f7f;
      }
    }
  }
  *param_6 = uVar11;
  return;
}

