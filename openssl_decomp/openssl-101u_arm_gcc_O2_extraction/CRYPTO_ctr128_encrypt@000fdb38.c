
void CRYPTO_ctr128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,char *param_5,
               uint *param_6,uint *param_7,code *param_8)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  byte *pbVar11;
  
  uVar8 = *param_7;
  puVar9 = param_1;
  puVar10 = param_2;
  if (uVar8 != 0 && param_3 != 0) {
    do {
      pbVar1 = (byte *)((int)param_6 + uVar8);
      uVar3 = uVar8 + 1 & 0xf;
      param_1 = (uint *)((int)puVar9 + 1);
      uVar8 = uVar8 + 1 & 0xf;
      if (uVar3 != 0) {
        uVar3 = 1;
      }
      param_3 = param_3 - 1;
      uVar3 = uVar3 & 1;
      if (param_3 == 0) {
        uVar3 = 0;
      }
      param_2 = (uint *)((int)puVar10 + 1);
      *(byte *)puVar10 = *(byte *)puVar9 ^ *pbVar1;
      puVar9 = param_1;
      puVar10 = param_2;
    } while (uVar3 != 0);
  }
  if ((((uint)param_1 | (uint)param_2 | (uint)param_6) & 3) == 0) {
    uVar3 = param_3;
    puVar9 = param_1;
    puVar10 = param_2;
    if (0xf < param_3) {
      do {
        uVar3 = uVar3 - 0x10;
        (*param_8)(param_5,param_6,param_4);
        uVar8 = (uint)(byte)param_5[0xe] + ((byte)param_5[0xf] + 1 >> 8);
        param_5[0xf] = (char)((byte)param_5[0xf] + 1);
        uVar2 = (uint)(byte)param_5[0xd] + (uVar8 >> 8);
        param_5[0xd] = (char)uVar2;
        param_5[0xe] = (char)uVar8;
        uVar8 = (uint)(byte)param_5[0xc] + (uVar2 >> 8);
        uVar2 = (uint)(byte)param_5[0xb] + (uVar8 >> 8);
        param_5[0xb] = (char)uVar2;
        param_5[0xc] = (char)uVar8;
        uVar2 = (uint)(byte)param_5[10] + (uVar2 >> 8);
        uVar8 = (uint)(byte)param_5[9] + (uVar2 >> 8);
        param_5[10] = (char)uVar2;
        uVar2 = (uint)(byte)param_5[8] + (uVar8 >> 8);
        param_5[8] = (char)uVar2;
        param_5[9] = (char)uVar8;
        uVar8 = (uint)(byte)param_5[7] + (uVar2 >> 8);
        uVar2 = (uint)(byte)param_5[6] + (uVar8 >> 8);
        param_5[6] = (char)uVar2;
        param_5[7] = (char)uVar8;
        uVar2 = (uint)(byte)param_5[5] + (uVar2 >> 8);
        uVar8 = (uint)(byte)param_5[4] + (uVar2 >> 8);
        param_5[5] = (char)uVar2;
        uVar2 = (uint)(byte)param_5[3] + (uVar8 >> 8);
        param_5[3] = (char)uVar2;
        param_5[4] = (char)uVar8;
        uVar8 = (uint)(byte)param_5[2] + (uVar2 >> 8);
        param_5[2] = (char)uVar8;
        iVar4 = (uint)(byte)param_5[1] + (uVar8 >> 8);
        param_5[1] = (char)iVar4;
        *param_5 = *param_5 + (char)((uint)iVar4 >> 8);
        *puVar10 = *param_6 ^ *puVar9;
        puVar10[1] = param_6[1] ^ puVar9[1];
        puVar10[2] = param_6[2] ^ puVar9[2];
        puVar10[3] = param_6[3] ^ puVar9[3];
        puVar9 = puVar9 + 4;
        puVar10 = puVar10 + 4;
      } while (0xf < uVar3);
      uVar8 = 0;
      uVar3 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar4 = (uVar3 & 0xfffffff0) + 0x10;
      param_2 = (uint *)((int)param_2 + iVar4);
      param_1 = (uint *)((int)param_1 + iVar4);
    }
    if (param_3 != 0) {
      (*param_8)(param_5,param_6,param_4);
      pbVar6 = (byte *)((int)param_2 + uVar8);
      uVar2 = (uint)(byte)param_5[0xe] + ((byte)param_5[0xf] + 1 >> 8);
      param_5[0xf] = (char)((byte)param_5[0xf] + 1);
      pbVar1 = (byte *)((int)param_6 + uVar8);
      uVar3 = (uint)(byte)param_5[0xd] + (uVar2 >> 8);
      param_5[0xd] = (char)uVar3;
      param_5[0xe] = (char)uVar2;
      uVar3 = (uint)(byte)param_5[0xc] + (uVar3 >> 8);
      param_5[0xc] = (char)uVar3;
      pbVar11 = (byte *)((int)param_1 + uVar8);
      uVar3 = (uint)(byte)param_5[0xb] + (uVar3 >> 8);
      param_5[0xb] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[10] + (uVar3 >> 8);
      param_5[10] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[9] + (uVar3 >> 8);
      param_5[9] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[8] + (uVar3 >> 8);
      param_5[8] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[7] + (uVar3 >> 8);
      param_5[7] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[6] + (uVar3 >> 8);
      param_5[6] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[5] + (uVar3 >> 8);
      param_5[5] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[4] + (uVar3 >> 8);
      param_5[4] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[3] + (uVar3 >> 8);
      uVar2 = (uint)(byte)param_5[2] + (uVar3 >> 8);
      param_5[3] = (char)uVar3;
      iVar4 = (uint)(byte)param_5[1] + (uVar2 >> 8);
      param_5[2] = (char)uVar2;
      param_5[1] = (char)iVar4;
      *param_5 = *param_5 + (char)((uint)iVar4 >> 8);
      if ((((uint)pbVar11 | (uint)pbVar1 | (uint)pbVar6) & 3) == 0 &&
          (6 < param_3 &&
          ((pbVar1 + 4 <= pbVar6 || pbVar6 + 4 <= pbVar1) &&
          (pbVar11 + 4 <= pbVar6 || pbVar6 + 4 <= pbVar11)))) {
        iVar4 = 0;
        uVar3 = 0;
        uVar2 = param_3 & 0xfffffffc;
        do {
          uVar3 = uVar3 + 1;
          *(uint *)(pbVar6 + iVar4) = *(uint *)(pbVar11 + iVar4) ^ *(uint *)(pbVar1 + iVar4);
          iVar4 = iVar4 + 4;
        } while (uVar3 < param_3 >> 2);
        uVar3 = uVar2 + uVar8;
        if (uVar2 != param_3) {
          iVar4 = uVar3 + 1;
          *(byte *)((int)param_2 + uVar3) =
               *(byte *)((int)param_6 + uVar3) ^ *(byte *)((int)param_1 + uVar3);
          if (param_3 - 1 != uVar2) {
            iVar7 = uVar3 + 2;
            *(byte *)((int)param_2 + iVar4) =
                 *(byte *)((int)param_1 + iVar4) ^ *(byte *)((int)param_6 + iVar4);
            if ((param_3 - 1) - uVar2 != 1) {
              uVar3 = param_3 + uVar8;
              *(byte *)((int)param_2 + iVar7) =
                   *(byte *)((int)param_1 + iVar7) ^ *(byte *)((int)param_6 + iVar7);
              goto LAB_000fdeda;
            }
          }
          uVar3 = param_3 + uVar8;
        }
      }
      else {
        uVar3 = param_3 + uVar8;
        do {
          *(byte *)((int)param_2 + uVar8) =
               *(byte *)((int)param_6 + uVar8) ^ *(byte *)((int)param_1 + uVar8);
          uVar8 = uVar8 + 1;
        } while (uVar8 != uVar3);
      }
LAB_000fdeda:
      *param_7 = uVar3;
      return;
    }
  }
  else {
    uVar3 = 0;
    if (param_3 != 0) {
      do {
        if (uVar8 == 0) {
          (*param_8)(param_5,param_6,param_4);
          uVar2 = (uint)(byte)param_5[0xe] + ((byte)param_5[0xf] + 1 >> 8);
          param_5[0xf] = (char)((byte)param_5[0xf] + 1);
          uVar5 = (uint)(byte)param_5[0xd] + (uVar2 >> 8);
          param_5[0xd] = (char)uVar5;
          param_5[0xe] = (char)uVar2;
          uVar2 = (uint)(byte)param_5[0xc] + (uVar5 >> 8);
          uVar5 = (uint)(byte)param_5[0xb] + (uVar2 >> 8);
          param_5[0xb] = (char)uVar5;
          param_5[0xc] = (char)uVar2;
          uVar5 = (uint)(byte)param_5[10] + (uVar5 >> 8);
          uVar2 = (uint)(byte)param_5[9] + (uVar5 >> 8);
          param_5[10] = (char)uVar5;
          uVar5 = (uint)(byte)param_5[8] + (uVar2 >> 8);
          param_5[8] = (char)uVar5;
          param_5[9] = (char)uVar2;
          uVar2 = (uint)(byte)param_5[7] + (uVar5 >> 8);
          uVar5 = (uint)(byte)param_5[6] + (uVar2 >> 8);
          param_5[6] = (char)uVar5;
          param_5[7] = (char)uVar2;
          uVar5 = (uint)(byte)param_5[5] + (uVar5 >> 8);
          uVar2 = (uint)(byte)param_5[4] + (uVar5 >> 8);
          param_5[5] = (char)uVar5;
          uVar5 = (uint)(byte)param_5[3] + (uVar2 >> 8);
          param_5[3] = (char)uVar5;
          param_5[4] = (char)uVar2;
          uVar2 = (uint)(byte)param_5[2] + (uVar5 >> 8);
          param_5[2] = (char)uVar2;
          iVar4 = (uint)(byte)param_5[1] + (uVar2 >> 8);
          param_5[1] = (char)iVar4;
          *param_5 = *param_5 + (char)((uint)iVar4 >> 8);
        }
        pbVar1 = (byte *)((int)param_6 + uVar8);
        uVar8 = uVar8 + 1 & 0xf;
        *(byte *)((int)param_2 + uVar3) = *(byte *)((int)param_1 + uVar3) ^ *pbVar1;
        uVar3 = uVar3 + 1;
      } while (uVar3 != param_3);
    }
  }
  *param_7 = uVar8;
  return;
}

