
void CRYPTO_ctr128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               int param_6,uint *param_7,code *param_8)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  uint local_28;
  
  uVar9 = *param_7;
  if ((uVar9 != 0) && (param_3 != 0)) {
    do {
      pbVar8 = (byte *)(param_6 + uVar9);
      pbVar5 = param_1 + 1;
      pbVar7 = param_2 + 1;
      param_3 = param_3 - 1;
      uVar9 = uVar9 + 1 & 0xf;
      *param_2 = *pbVar8 ^ *param_1;
      param_1 = pbVar5;
      param_2 = pbVar7;
      if (uVar9 == 0) break;
    } while (param_3 != 0);
  }
  uVar4 = param_3;
  pbVar8 = param_2;
  pbVar5 = param_1;
  if (0xf < param_3) {
    do {
      (*param_8)(param_5,param_6,param_4);
      cVar3 = param_5[0xf];
      param_5[0xf] = cVar3 + '\x01';
      if ((char)(cVar3 + '\x01') == '\0') {
        pcVar1 = param_5 + 0xe;
        *pcVar1 = *pcVar1 + '\x01';
        if (*pcVar1 == '\0') {
          pcVar1 = param_5 + 0xd;
          *pcVar1 = *pcVar1 + '\x01';
          if (*pcVar1 == '\0') {
            pcVar1 = param_5 + 0xc;
            *pcVar1 = *pcVar1 + '\x01';
            if (*pcVar1 == '\0') {
              pcVar1 = param_5 + 0xb;
              *pcVar1 = *pcVar1 + '\x01';
              if (*pcVar1 == '\0') {
                pcVar1 = param_5 + 10;
                *pcVar1 = *pcVar1 + '\x01';
                if (*pcVar1 == '\0') {
                  pcVar1 = param_5 + 9;
                  *pcVar1 = *pcVar1 + '\x01';
                  if (*pcVar1 == '\0') {
                    pcVar1 = param_5 + 8;
                    *pcVar1 = *pcVar1 + '\x01';
                    if (*pcVar1 == '\0') {
                      pcVar1 = param_5 + 7;
                      *pcVar1 = *pcVar1 + '\x01';
                      if (*pcVar1 == '\0') {
                        pcVar1 = param_5 + 6;
                        *pcVar1 = *pcVar1 + '\x01';
                        if (*pcVar1 == '\0') {
                          pcVar1 = param_5 + 5;
                          *pcVar1 = *pcVar1 + '\x01';
                          if (*pcVar1 == '\0') {
                            pcVar1 = param_5 + 4;
                            *pcVar1 = *pcVar1 + '\x01';
                            if (*pcVar1 == '\0') {
                              pcVar1 = param_5 + 3;
                              *pcVar1 = *pcVar1 + '\x01';
                              if (*pcVar1 == '\0') {
                                pcVar1 = param_5 + 2;
                                *pcVar1 = *pcVar1 + '\x01';
                                if (*pcVar1 == '\0') {
                                  pcVar1 = param_5 + 1;
                                  *pcVar1 = *pcVar1 + '\x01';
                                  if (*pcVar1 == '\0') {
                                    *param_5 = *param_5 + '\x01';
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
      if ((((uVar9 < 0x10) &&
           (*(uint *)(pbVar8 + uVar9) = *(uint *)(pbVar5 + uVar9) ^ *(uint *)(param_6 + uVar9),
           uVar9 + 4 < 0x10)) &&
          (*(uint *)(pbVar8 + uVar9 + 4) =
                *(uint *)(pbVar5 + uVar9 + 4) ^ *(uint *)(param_6 + 4 + uVar9), uVar9 + 8 < 0x10))
         && (*(uint *)(pbVar8 + uVar9 + 8) =
                  *(uint *)(pbVar5 + uVar9 + 8) ^ *(uint *)(param_6 + 8 + uVar9), uVar9 + 0xc < 0x10
            )) {
        *(uint *)(pbVar8 + uVar9 + 0xc) =
             *(uint *)(pbVar5 + uVar9 + 0xc) ^ *(uint *)(param_6 + 0xc + uVar9);
      }
      uVar4 = uVar4 - 0x10;
      uVar9 = 0;
      pbVar8 = pbVar8 + 0x10;
      pbVar5 = pbVar5 + 0x10;
    } while (0xf < uVar4);
    uVar4 = param_3 - 0x10;
    param_3 = param_3 & 0xf;
    iVar2 = (uVar4 & 0xfffffff0) + 0x10;
    param_2 = param_2 + iVar2;
    param_1 = param_1 + iVar2;
  }
  if (param_3 == 0) {
    *param_7 = uVar9;
    return;
  }
  (*param_8)(param_5,param_6,param_4);
  cVar3 = param_5[0xf];
  param_5[0xf] = cVar3 + '\x01';
  if ((char)(cVar3 + '\x01') == '\0') {
    pcVar1 = param_5 + 0xe;
    *pcVar1 = *pcVar1 + '\x01';
    if (*pcVar1 == '\0') {
      pcVar1 = param_5 + 0xd;
      *pcVar1 = *pcVar1 + '\x01';
      if (*pcVar1 == '\0') {
        pcVar1 = param_5 + 0xc;
        *pcVar1 = *pcVar1 + '\x01';
        if (*pcVar1 == '\0') {
          pcVar1 = param_5 + 0xb;
          *pcVar1 = *pcVar1 + '\x01';
          if (*pcVar1 == '\0') {
            pcVar1 = param_5 + 10;
            *pcVar1 = *pcVar1 + '\x01';
            if (*pcVar1 == '\0') {
              pcVar1 = param_5 + 9;
              *pcVar1 = *pcVar1 + '\x01';
              if (*pcVar1 == '\0') {
                pcVar1 = param_5 + 8;
                *pcVar1 = *pcVar1 + '\x01';
                if (*pcVar1 == '\0') {
                  pcVar1 = param_5 + 7;
                  *pcVar1 = *pcVar1 + '\x01';
                  if (*pcVar1 == '\0') {
                    pcVar1 = param_5 + 6;
                    *pcVar1 = *pcVar1 + '\x01';
                    if (*pcVar1 == '\0') {
                      pcVar1 = param_5 + 5;
                      *pcVar1 = *pcVar1 + '\x01';
                      if (*pcVar1 == '\0') {
                        pcVar1 = param_5 + 4;
                        *pcVar1 = *pcVar1 + '\x01';
                        if (*pcVar1 == '\0') {
                          pcVar1 = param_5 + 3;
                          *pcVar1 = *pcVar1 + '\x01';
                          if (*pcVar1 == '\0') {
                            pcVar1 = param_5 + 2;
                            *pcVar1 = *pcVar1 + '\x01';
                            if (*pcVar1 == '\0') {
                              pcVar1 = param_5 + 1;
                              *pcVar1 = *pcVar1 + '\x01';
                              if (*pcVar1 == '\0') {
                                *param_5 = *param_5 + '\x01';
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
  local_28 = param_3 - 1;
  iVar2 = uVar9 + 4;
  pbVar8 = (byte *)(param_6 + uVar9);
  pbVar7 = param_2 + uVar9;
  pbVar5 = param_1 + uVar9;
  if ((param_3 < 7 ||
       (pbVar7 < param_1 + iVar2 && pbVar5 < param_2 + iVar2 ||
       pbVar8 < param_2 + iVar2 && pbVar7 < (byte *)(param_6 + iVar2))) ||
     ((((uint)pbVar8 | (uint)pbVar5 | (uint)pbVar7) & 3) != 0)) {
    uVar4 = 0;
    do {
      pbVar7[uVar4] = pbVar5[uVar4] ^ pbVar8[uVar4];
      uVar4 = uVar4 + 1;
    } while (param_3 != uVar4);
  }
  else {
    uVar6 = (param_3 - 4 >> 2) + 1;
    uVar4 = uVar9;
    if (2 < local_28) {
      uVar4 = 0;
      do {
        *(uint *)(pbVar7 + uVar4 * 4) =
             *(uint *)(pbVar8 + uVar4 * 4) ^ *(uint *)(pbVar5 + uVar4 * 4);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar6);
      local_28 = local_28 + uVar6 * -4;
      uVar4 = uVar6 * 4 + uVar9;
      if (param_3 == uVar6 * 4) goto LAB_081b44c0;
    }
    param_2[uVar4] = *(byte *)(param_6 + uVar4) ^ param_1[uVar4];
    if ((local_28 != 0) &&
       (param_2[uVar4 + 1] = param_1[uVar4 + 1] ^ *(byte *)(param_6 + 1 + uVar4), local_28 != 1)) {
      param_2[uVar4 + 2] = param_1[uVar4 + 2] ^ *(byte *)(param_6 + 2 + uVar4);
    }
  }
LAB_081b44c0:
  *param_7 = uVar9 + param_3;
  return;
}

