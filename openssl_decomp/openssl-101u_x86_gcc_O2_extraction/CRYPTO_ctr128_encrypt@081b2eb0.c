
void CRYPTO_ctr128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,char *param_5,
               uint *param_6,uint *param_7,code *param_8)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint local_24;
  
  uVar9 = *param_7;
  if ((uVar9 != 0) && (param_3 != 0)) {
    do {
      pbVar3 = (byte *)((int)param_6 + uVar9);
      puVar6 = (uint *)((int)param_1 + 1);
      puVar8 = (uint *)((int)param_2 + 1);
      param_3 = param_3 - 1;
      uVar9 = uVar9 + 1 & 0xf;
      *(byte *)param_2 = *pbVar3 ^ *(byte *)param_1;
      param_1 = puVar6;
      param_2 = puVar8;
      if (uVar9 == 0) break;
    } while (param_3 != 0);
  }
  uVar7 = param_3;
  puVar6 = param_2;
  puVar8 = param_1;
  if (0xf < param_3) {
    do {
      (*param_8)(param_5,param_6,param_4);
      bVar1 = param_5[0xf];
      param_5[0xf] = (char)(bVar1 + 1);
      uVar9 = (bVar1 + 1 >> 8) + (uint)(byte)param_5[0xe];
      param_5[0xe] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[0xd];
      param_5[0xd] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[0xc];
      param_5[0xc] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[0xb];
      param_5[0xb] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[10];
      param_5[10] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[9];
      param_5[9] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[8];
      param_5[8] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[7];
      param_5[7] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[6];
      param_5[6] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[5];
      param_5[5] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[4];
      param_5[4] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[3];
      param_5[3] = (char)uVar9;
      uVar9 = (uVar9 >> 8) + (uint)(byte)param_5[2];
      param_5[2] = (char)uVar9;
      iVar2 = (uVar9 >> 8) + (uint)(byte)param_5[1];
      param_5[1] = (char)iVar2;
      *param_5 = *param_5 + (char)((uint)iVar2 >> 8);
      *puVar6 = *puVar8 ^ *param_6;
      uVar7 = uVar7 - 0x10;
      puVar6[1] = puVar8[1] ^ param_6[1];
      puVar6[2] = puVar8[2] ^ param_6[2];
      puVar6[3] = puVar8[3] ^ param_6[3];
      puVar6 = puVar6 + 4;
      puVar8 = puVar8 + 4;
    } while (0xf < uVar7);
    uVar9 = 0;
    uVar7 = param_3 - 0x10;
    param_3 = param_3 & 0xf;
    iVar2 = (uVar7 & 0xfffffff0) + 0x10;
    param_2 = (uint *)((int)param_2 + iVar2);
    param_1 = (uint *)((int)param_1 + iVar2);
  }
  if (param_3 == 0) {
    *param_7 = uVar9;
    return;
  }
  (*param_8)(param_5,param_6,param_4);
  bVar1 = param_5[0xf];
  param_5[0xf] = (char)(bVar1 + 1);
  uVar7 = (bVar1 + 1 >> 8) + (uint)(byte)param_5[0xe];
  param_5[0xe] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[0xd];
  param_5[0xd] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[0xc];
  param_5[0xc] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[0xb];
  param_5[0xb] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[10];
  param_5[10] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[9];
  param_5[9] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[8];
  param_5[8] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[7];
  param_5[7] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[6];
  param_5[6] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[5];
  param_5[5] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[4];
  param_5[4] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[3];
  param_5[3] = (char)uVar7;
  uVar7 = (uVar7 >> 8) + (uint)(byte)param_5[2];
  param_5[2] = (char)uVar7;
  iVar2 = (uVar7 >> 8) + (uint)(byte)param_5[1];
  param_5[1] = (char)iVar2;
  *param_5 = *param_5 + (char)((uint)iVar2 >> 8);
  local_24 = param_3 - 1;
  pbVar3 = (byte *)((int)param_1 + uVar9);
  pbVar5 = (byte *)((int)param_2 + uVar9);
  iVar2 = uVar9 + 4;
  if ((param_3 < 7 ||
       (pbVar5 < (byte *)(iVar2 + (int)param_6) &&
        (byte *)((int)param_6 + uVar9) < (byte *)((int)param_2 + iVar2) ||
       pbVar5 < (byte *)((int)param_1 + iVar2) && pbVar3 < (byte *)((int)param_2 + iVar2))) ||
     ((((uint)pbVar3 | (int)param_6 + uVar9 | (uint)pbVar5) & 3) != 0)) {
    uVar7 = 0;
    do {
      pbVar5[uVar7] = ((byte *)((int)param_6 + uVar9))[uVar7] ^ pbVar3[uVar7];
      uVar7 = uVar7 + 1;
    } while (uVar7 != param_3);
  }
  else {
    uVar7 = (param_3 - 4 >> 2) + 1;
    uVar4 = uVar9;
    if (2 < local_24) {
      uVar4 = 0;
      do {
        *(uint *)(pbVar5 + uVar4 * 4) =
             *(uint *)((int)param_6 + uVar9 + uVar4 * 4) ^ *(uint *)(pbVar3 + uVar4 * 4);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar7);
      local_24 = local_24 + uVar7 * -4;
      uVar4 = uVar7 * 4 + uVar9;
      if (uVar7 * 4 == param_3) goto LAB_081b3230;
    }
    *(byte *)((int)param_2 + uVar4) =
         *(byte *)((int)param_1 + uVar4) ^ *(byte *)((int)param_6 + uVar4);
    if ((local_24 != 0) &&
       (*(byte *)((int)param_2 + uVar4 + 1) =
             *(byte *)((int)param_6 + uVar4 + 1) ^ *(byte *)((int)param_1 + uVar4 + 1),
       local_24 != 1)) {
      *(byte *)((int)param_2 + uVar4 + 2) =
           *(byte *)((int)param_6 + uVar4 + 2) ^ *(byte *)((int)param_1 + uVar4 + 2);
    }
  }
LAB_081b3230:
  *param_7 = uVar9 + param_3;
  return;
}

