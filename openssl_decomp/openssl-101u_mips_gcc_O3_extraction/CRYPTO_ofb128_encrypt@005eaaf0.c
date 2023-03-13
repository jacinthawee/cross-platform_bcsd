
void CRYPTO_ofb128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               uint *param_6,code *param_7)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  
  for (uVar2 = *param_6; uVar2 != 0; uVar2 = uVar2 + 1 & 0xf) {
    if (param_3 == 0) {
      if ((((uint)param_5 | (uint)param_2 | (uint)param_1) & 3) != 0) goto LAB_005eabc0;
      goto LAB_005eac24;
    }
    bVar1 = *(byte *)param_1;
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    *(byte *)param_2 = *(byte *)((int)param_5 + uVar2) ^ bVar1;
    param_2 = (uint *)((int)param_2 + 1);
  }
  if ((((uint)param_5 | (uint)param_1 | (uint)param_2) & 3) != 0) {
    puVar8 = (uint *)((int)param_1 + param_3);
    uVar2 = param_3;
    if (param_3 != 0) {
      uVar2 = 0;
      do {
        if (uVar2 == 0) {
          (*param_7)(param_5,param_5,param_4);
        }
        pbVar3 = (byte *)((int)param_5 + uVar2);
        bVar1 = *(byte *)param_1;
        param_1 = (uint *)((int)param_1 + 1);
        uVar2 = uVar2 + 1 & 0xf;
        *(byte *)param_2 = *pbVar3 ^ bVar1;
        param_2 = (uint *)((int)param_2 + 1);
      } while (param_1 != puVar8);
    }
LAB_005eabc0:
    *param_6 = uVar2;
    return;
  }
  uVar2 = param_3;
  puVar8 = param_1;
  puVar9 = param_2;
  if (param_3 < 0x10) {
    if (param_3 != 0) {
      (*param_7)(param_5,param_5,param_4);
      iVar4 = param_3 - 1;
      goto LAB_005ead2c;
    }
  }
  else {
    do {
      (*param_7)(param_5,param_5,param_4);
      uVar2 = uVar2 - 0x10;
      *puVar9 = *puVar8 ^ *param_5;
      puVar9[1] = puVar8[1] ^ param_5[1];
      puVar9[2] = puVar8[2] ^ param_5[2];
      puVar9[3] = puVar8[3] ^ param_5[3];
      puVar8 = puVar8 + 4;
      puVar9 = puVar9 + 4;
    } while (0xf < uVar2);
    iVar4 = (param_3 - 0x10 >> 4) + 1;
    param_2 = param_2 + iVar4 * 4;
    param_1 = param_1 + iVar4 * 4;
    if ((param_3 & 0xf) != 0) {
      iVar4 = (param_3 - 0x11) - (param_3 - 0x10 & 0xfffffff0);
      (*param_7)(param_5,param_5,param_4);
LAB_005ead2c:
      uVar2 = iVar4 + 1;
      if ((uVar2 < 7 ||
           (param_2 < param_5 + 1 && param_5 < param_2 + 1 ||
           param_2 < param_1 + 1 && param_1 < param_2 + 1)) ||
         ((((uint)param_2 | (uint)param_5 | (uint)param_1) & 3) != 0)) {
        *(byte *)param_2 = *(byte *)param_5 ^ *(byte *)param_1;
        if (((((iVar4 != 0) &&
              (((*(byte *)((int)param_2 + 1) =
                      *(byte *)((int)param_1 + 1) ^ *(byte *)((int)param_5 + 1), iVar4 != 1 &&
                (*(byte *)((int)param_2 + 2) =
                      *(byte *)((int)param_1 + 2) ^ *(byte *)((int)param_5 + 2), iVar4 != 2)) &&
               (*(byte *)((int)param_2 + 3) =
                     *(byte *)((int)param_1 + 3) ^ *(byte *)((int)param_5 + 3), iVar4 != 3)))) &&
             (((*(byte *)(param_2 + 1) = *(byte *)(param_1 + 1) ^ *(byte *)(param_5 + 1), iVar4 != 4
               && (*(byte *)((int)param_2 + 5) =
                        *(byte *)((int)param_1 + 5) ^ *(byte *)((int)param_5 + 5), iVar4 != 5)) &&
              (*(byte *)((int)param_2 + 6) =
                    *(byte *)((int)param_1 + 6) ^ *(byte *)((int)param_5 + 6), iVar4 != 6)))) &&
            ((*(byte *)((int)param_2 + 7) =
                   *(byte *)((int)param_1 + 7) ^ *(byte *)((int)param_5 + 7), iVar4 != 7 &&
             (*(byte *)(param_2 + 2) = *(byte *)(param_1 + 2) ^ *(byte *)(param_5 + 2), iVar4 != 8))
            )) && ((*(byte *)((int)param_2 + 9) =
                         *(byte *)((int)param_1 + 9) ^ *(byte *)((int)param_5 + 9), iVar4 != 9 &&
                   ((((*(byte *)((int)param_2 + 10) =
                            *(byte *)((int)param_1 + 10) ^ *(byte *)((int)param_5 + 10), iVar4 != 10
                      && (*(byte *)((int)param_2 + 0xb) =
                               *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)param_5 + 0xb),
                         iVar4 != 0xb)) &&
                     (*(byte *)(param_2 + 3) = *(byte *)(param_1 + 3) ^ *(byte *)(param_5 + 3),
                     iVar4 != 0xc)) &&
                    (*(byte *)((int)param_2 + 0xd) =
                          *(byte *)((int)param_1 + 0xd) ^ *(byte *)((int)param_5 + 0xd),
                    iVar4 != 0xd)))))) {
          *(byte *)((int)param_2 + 0xe) =
               *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)param_5 + 0xe);
          *param_6 = uVar2;
          return;
        }
      }
      else {
        iVar6 = (iVar4 - 3U >> 2) + 1;
        *param_2 = *param_5 ^ *param_1;
        uVar5 = iVar6 * 4;
        if ((iVar6 != 1) && (param_2[1] = param_1[1] ^ param_5[1], iVar6 == 3)) {
          param_2[2] = param_1[2] ^ param_5[2];
        }
        iVar4 = iVar4 + iVar6 * -4;
        if (uVar2 != uVar5) {
          iVar7 = uVar5 + 1;
          *(byte *)(param_2 + iVar6) = *(byte *)(param_1 + iVar6) ^ *(byte *)(param_5 + iVar6);
          if (iVar4 != 0) {
            iVar6 = uVar5 + 2;
            *(byte *)((int)param_2 + iVar7) =
                 *(byte *)((int)param_1 + iVar7) ^ *(byte *)((int)param_5 + iVar7);
            if (iVar4 != 1) {
              *(byte *)((int)param_2 + iVar6) =
                   *(byte *)((int)param_1 + iVar6) ^ *(byte *)((int)param_5 + iVar6);
              *param_6 = uVar2;
              return;
            }
          }
        }
      }
LAB_005eac24:
      *param_6 = uVar2;
      return;
    }
  }
  *param_6 = 0;
  return;
}

