
void CRYPTO_ofb128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,uint param_5,
               uint *param_6,code *param_7)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  
  uVar7 = *param_6;
  pbVar2 = param_2;
  pbVar8 = param_1;
  if (uVar7 != 0 && param_3 != 0) {
    do {
      pbVar10 = (byte *)(param_5 + uVar7);
      uVar3 = uVar7 + 1 & 0xf;
      param_1 = pbVar8 + 1;
      uVar7 = uVar7 + 1 & 0xf;
      if (uVar3 != 0) {
        uVar3 = 1;
      }
      param_3 = param_3 - 1;
      uVar3 = uVar3 & 1;
      if (param_3 == 0) {
        uVar3 = 0;
      }
      param_2 = pbVar2 + 1;
      *pbVar2 = *pbVar8 ^ *pbVar10;
      pbVar2 = param_2;
      pbVar8 = param_1;
    } while (uVar3 != 0);
  }
  if ((((uint)param_1 | (uint)param_2 | param_5) & 3) != 0) {
    if (param_3 != 0) {
      uVar3 = 0;
      do {
        if (uVar7 == 0) {
          (*param_7)(param_5,param_5,param_4);
        }
        pbVar2 = (byte *)(param_5 + uVar7);
        uVar7 = uVar7 + 1 & 0xf;
        param_2[uVar3] = param_1[uVar3] ^ *pbVar2;
        uVar3 = uVar3 + 1;
      } while (uVar3 != param_3);
    }
    *param_6 = uVar7;
    return;
  }
  pbVar2 = param_1;
  pbVar8 = param_2;
  uVar3 = param_3;
  if (0xf < param_3) {
    do {
      (*param_7)(param_5,param_5,param_4);
      uVar9 = uVar7 + 4;
      uVar1 = uVar7 + 8;
      uVar4 = uVar7 + 0xc;
      if ((((uVar7 < 0x10) &&
           (*(uint *)(pbVar8 + uVar7) = *(uint *)(pbVar2 + uVar7) ^ *(uint *)(param_5 + uVar7),
           uVar9 < 0x10)) &&
          (*(uint *)(pbVar8 + uVar9) = *(uint *)(pbVar2 + uVar9) ^ *(uint *)(param_5 + uVar9),
          uVar1 < 0x10)) &&
         (*(uint *)(pbVar8 + uVar1) = *(uint *)(pbVar2 + uVar1) ^ *(uint *)(param_5 + uVar1),
         uVar4 < 0x10)) {
        *(uint *)(pbVar8 + uVar4) = *(uint *)(pbVar2 + uVar4) ^ *(uint *)(param_5 + uVar4);
      }
      uVar3 = uVar3 - 0x10;
      uVar7 = 0;
      pbVar2 = pbVar2 + 0x10;
      pbVar8 = pbVar8 + 0x10;
    } while (0xf < uVar3);
    iVar5 = (param_3 - 0x10 & 0xfffffff0) + 0x10;
    param_3 = param_3 & 0xf;
    param_2 = param_2 + iVar5;
    param_1 = param_1 + iVar5;
    uVar7 = 0;
  }
  uVar3 = uVar7;
  if (param_3 != 0) {
    (*param_7)(param_5,param_5,param_4);
    pbVar2 = param_2 + uVar7;
    pbVar10 = (byte *)(param_5 + uVar7);
    pbVar8 = param_1 + uVar7;
    if ((((uint)pbVar8 | (uint)pbVar10 | (uint)pbVar2) & 3) == 0 &&
        (6 < param_3 &&
        ((pbVar8 + 4 <= pbVar2 || pbVar2 + 4 <= pbVar8) &&
        (pbVar10 + 4 <= pbVar2 || pbVar2 + 4 <= pbVar10)))) {
      iVar5 = 0;
      uVar3 = 0;
      uVar1 = param_3 & 0xfffffffc;
      do {
        uVar3 = uVar3 + 1;
        *(uint *)(pbVar2 + iVar5) = *(uint *)(pbVar8 + iVar5) ^ *(uint *)(pbVar10 + iVar5);
        iVar5 = iVar5 + 4;
      } while (uVar3 < param_3 >> 2);
      uVar3 = uVar1 + uVar7;
      if (uVar1 != param_3) {
        iVar5 = uVar3 + 1;
        param_2[uVar3] = param_1[uVar3] ^ *(byte *)(param_5 + uVar3);
        if (param_3 - 1 != uVar1) {
          iVar6 = uVar3 + 2;
          param_2[iVar5] = *(byte *)(param_5 + iVar5) ^ param_1[iVar5];
          if ((param_3 - 1) - uVar1 != 1) {
            uVar3 = param_3 + uVar7;
            param_2[iVar6] = param_1[iVar6] ^ *(byte *)(param_5 + iVar6);
            goto LAB_000fea2c;
          }
        }
        uVar3 = param_3 + uVar7;
      }
    }
    else {
      uVar3 = param_3 + uVar7;
      do {
        param_2[uVar7] = *(byte *)(param_5 + uVar7) ^ param_1[uVar7];
        uVar7 = uVar7 + 1;
      } while (uVar7 != uVar3);
    }
  }
LAB_000fea2c:
  *param_6 = uVar3;
  return;
}

