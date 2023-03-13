
void CRYPTO_ctr128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,int *param_5,
               uint *param_6,uint *param_7,code *param_8)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  
  for (uVar8 = *param_7; uVar8 != 0; uVar8 = uVar8 + 1 & 0xf) {
    if (param_3 == 0) goto LAB_005e8d24;
    bVar1 = *(byte *)param_1;
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    *(byte *)param_2 = *(byte *)((int)param_6 + uVar8) ^ bVar1;
    param_2 = (uint *)((int)param_2 + 1);
  }
  if ((((uint)param_6 | (uint)param_1 | (uint)param_2) & 3) == 0) {
    puVar7 = param_1;
    puVar9 = param_2;
    uVar8 = param_3;
    if (0xf < param_3) {
      do {
        (*param_8)(param_5,param_6,param_4);
        if (((uint)param_5 & 3) == 0) {
          uVar6 = param_5[3];
          uVar11 = param_5[2];
          uVar10 = param_5[1];
          uVar5 = uVar6 + 1;
          param_5[3] = uVar5;
          uVar6 = uVar11 - ((int)(uVar6 ^ uVar5) >> 0x1f);
          param_5[2] = uVar6;
          uVar11 = uVar10 - ((int)(uVar11 ^ uVar6) >> 0x1f);
          param_5[1] = uVar11;
          *param_5 = *param_5 - ((int)(uVar10 ^ uVar11) >> 0x1f);
        }
        else {
          uVar11 = *(byte *)((int)param_5 + 0xf) + 1;
          *(char *)((int)param_5 + 0xf) = (char)uVar11;
          uVar10 = (uint)*(byte *)((int)param_5 + 0xe) + (uVar11 >> 8);
          uVar6 = (uint)*(byte *)((int)param_5 + 0xd) + (uVar10 >> 8);
          uVar11 = (uint)*(byte *)(param_5 + 3) + (uVar6 >> 8);
          *(char *)((int)param_5 + 0xe) = (char)uVar10;
          *(char *)(param_5 + 3) = (char)uVar11;
          uVar11 = (uint)*(byte *)((int)param_5 + 0xb) + (uVar11 >> 8);
          *(char *)((int)param_5 + 0xd) = (char)uVar6;
          *(char *)((int)param_5 + 0xb) = (char)uVar11;
          uVar11 = (uint)*(byte *)((int)param_5 + 10) + (uVar11 >> 8);
          *(char *)((int)param_5 + 10) = (char)uVar11;
          uVar11 = (uint)*(byte *)((int)param_5 + 9) + (uVar11 >> 8);
          *(char *)((int)param_5 + 9) = (char)uVar11;
          uVar11 = (uint)*(byte *)(param_5 + 2) + (uVar11 >> 8);
          *(char *)(param_5 + 2) = (char)uVar11;
          uVar11 = (uint)*(byte *)((int)param_5 + 7) + (uVar11 >> 8);
          *(char *)((int)param_5 + 7) = (char)uVar11;
          uVar11 = (uint)*(byte *)((int)param_5 + 6) + (uVar11 >> 8);
          *(char *)((int)param_5 + 6) = (char)uVar11;
          uVar11 = (uint)*(byte *)((int)param_5 + 5) + (uVar11 >> 8);
          *(char *)((int)param_5 + 5) = (char)uVar11;
          uVar11 = (uint)*(byte *)(param_5 + 1) + (uVar11 >> 8);
          *(char *)(param_5 + 1) = (char)uVar11;
          uVar11 = (uint)*(byte *)((int)param_5 + 3) + (uVar11 >> 8);
          *(char *)((int)param_5 + 3) = (char)uVar11;
          uVar11 = (uint)*(byte *)((int)param_5 + 2) + (uVar11 >> 8);
          *(char *)((int)param_5 + 2) = (char)uVar11;
          iVar3 = (uint)*(byte *)((int)param_5 + 1) + (uVar11 >> 8);
          *(char *)((int)param_5 + 1) = (char)iVar3;
          *(char *)param_5 = *(char *)param_5 + (char)((uint)iVar3 >> 8);
        }
        uVar8 = uVar8 - 0x10;
        *puVar9 = *puVar7 ^ *param_6;
        puVar9[1] = puVar7[1] ^ param_6[1];
        puVar9[2] = puVar7[2] ^ param_6[2];
        puVar9[3] = puVar7[3] ^ param_6[3];
        puVar7 = puVar7 + 4;
        puVar9 = puVar9 + 4;
      } while (0xf < uVar8);
      uVar8 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar3 = (uVar8 >> 4) + 1;
      param_2 = param_2 + iVar3 * 4;
      param_1 = param_1 + iVar3 * 4;
    }
    uVar8 = param_3;
    if (param_3 != 0) {
      (*param_8)(param_5,param_6,param_4);
      if (((uint)param_5 & 3) == 0) {
        uVar6 = param_5[3];
        uVar11 = param_5[2];
        uVar10 = param_5[1];
        uVar5 = uVar6 + 1;
        param_5[3] = uVar5;
        uVar6 = uVar11 - ((int)(uVar6 ^ uVar5) >> 0x1f);
        param_5[2] = uVar6;
        uVar11 = uVar10 - ((int)(uVar11 ^ uVar6) >> 0x1f);
        param_5[1] = uVar11;
        *param_5 = *param_5 - ((int)(uVar10 ^ uVar11) >> 0x1f);
      }
      else {
        uVar11 = *(byte *)((int)param_5 + 0xf) + 1;
        *(char *)((int)param_5 + 0xf) = (char)uVar11;
        uVar10 = (uint)*(byte *)((int)param_5 + 0xe) + (uVar11 >> 8);
        uVar6 = (uint)*(byte *)((int)param_5 + 0xd) + (uVar10 >> 8);
        uVar11 = (uint)*(byte *)(param_5 + 3) + (uVar6 >> 8);
        *(char *)((int)param_5 + 0xe) = (char)uVar10;
        *(char *)(param_5 + 3) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 0xb) + (uVar11 >> 8);
        *(char *)((int)param_5 + 0xd) = (char)uVar6;
        *(char *)((int)param_5 + 0xb) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 10) + (uVar11 >> 8);
        *(char *)((int)param_5 + 10) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 9) + (uVar11 >> 8);
        *(char *)((int)param_5 + 9) = (char)uVar11;
        uVar11 = (uint)*(byte *)(param_5 + 2) + (uVar11 >> 8);
        *(char *)(param_5 + 2) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 7) + (uVar11 >> 8);
        *(char *)((int)param_5 + 7) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 6) + (uVar11 >> 8);
        *(char *)((int)param_5 + 6) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 5) + (uVar11 >> 8);
        *(char *)((int)param_5 + 5) = (char)uVar11;
        uVar11 = (uint)*(byte *)(param_5 + 1) + (uVar11 >> 8);
        *(char *)(param_5 + 1) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 3) + (uVar11 >> 8);
        *(char *)((int)param_5 + 3) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 2) + (uVar11 >> 8);
        *(char *)((int)param_5 + 2) = (char)uVar11;
        iVar3 = (uint)*(byte *)((int)param_5 + 1) + (uVar11 >> 8);
        *(char *)((int)param_5 + 1) = (char)iVar3;
        *(char *)param_5 = *(char *)param_5 + (char)((uint)iVar3 >> 8);
      }
      uVar11 = param_3 - 1;
      if ((param_3 < 7 ||
           (param_2 < param_6 + 1 && param_6 < param_2 + 1 ||
           param_2 < param_1 + 1 && param_1 < param_2 + 1)) ||
         ((((uint)param_2 | (uint)param_6 | (uint)param_1) & 3) != 0)) {
        *(byte *)param_2 = *(byte *)param_1 ^ *(byte *)param_6;
        if (((((uVar11 != 0) &&
              (((*(byte *)((int)param_2 + 1) =
                      *(byte *)((int)param_6 + 1) ^ *(byte *)((int)param_1 + 1), param_3 != 2 &&
                (*(byte *)((int)param_2 + 2) =
                      *(byte *)((int)param_1 + 2) ^ *(byte *)((int)param_6 + 2), param_3 != 3)) &&
               (*(byte *)((int)param_2 + 3) =
                     *(byte *)((int)param_1 + 3) ^ *(byte *)((int)param_6 + 3), param_3 != 4)))) &&
             (((*(byte *)(param_2 + 1) = *(byte *)(param_6 + 1) ^ *(byte *)(param_1 + 1),
               param_3 != 5 &&
               (*(byte *)((int)param_2 + 5) =
                     *(byte *)((int)param_6 + 5) ^ *(byte *)((int)param_1 + 5), param_3 != 6)) &&
              (*(byte *)((int)param_2 + 6) =
                    *(byte *)((int)param_1 + 6) ^ *(byte *)((int)param_6 + 6), param_3 != 7)))) &&
            ((*(byte *)((int)param_2 + 7) =
                   *(byte *)((int)param_6 + 7) ^ *(byte *)((int)param_1 + 7), param_3 != 8 &&
             (*(byte *)(param_2 + 2) = *(byte *)(param_6 + 2) ^ *(byte *)(param_1 + 2), param_3 != 9
             )))) && ((*(byte *)((int)param_2 + 9) =
                            *(byte *)((int)param_6 + 9) ^ *(byte *)((int)param_1 + 9), param_3 != 10
                      && ((((*(byte *)((int)param_2 + 10) =
                                  *(byte *)((int)param_1 + 10) ^ *(byte *)((int)param_6 + 10),
                            param_3 != 0xb &&
                            (*(byte *)((int)param_2 + 0xb) =
                                  *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)param_6 + 0xb),
                            param_3 != 0xc)) &&
                           (*(byte *)(param_2 + 3) = *(byte *)(param_1 + 3) ^ *(byte *)(param_6 + 3)
                           , param_3 != 0xd)) &&
                          (*(byte *)((int)param_2 + 0xd) =
                                *(byte *)((int)param_1 + 0xd) ^ *(byte *)((int)param_6 + 0xd),
                          param_3 != 0xe)))))) {
          *(byte *)((int)param_2 + 0xe) =
               *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)param_6 + 0xe);
        }
      }
      else {
        iVar3 = (param_3 - 4 >> 2) + 1;
        uVar6 = iVar3 * 4;
        if (uVar11 < 3) {
          uVar6 = 0;
        }
        else {
          *param_2 = *param_6 ^ *param_1;
          if ((iVar3 != 1) && (param_2[1] = param_6[1] ^ param_1[1], iVar3 == 3)) {
            param_2[2] = param_6[2] ^ param_1[2];
          }
          uVar11 = uVar11 + iVar3 * -4;
          if (uVar6 == param_3) goto LAB_005e8d24;
        }
        iVar3 = uVar6 + 1;
        *(byte *)((int)param_2 + uVar6) =
             *(byte *)((int)param_1 + uVar6) ^ *(byte *)((int)param_6 + uVar6);
        if (uVar11 != 0) {
          iVar4 = uVar6 + 2;
          *(byte *)((int)param_2 + iVar3) =
               *(byte *)((int)param_1 + iVar3) ^ *(byte *)((int)param_6 + iVar3);
          if (uVar11 != 1) {
            *(byte *)((int)param_2 + iVar4) =
                 *(byte *)((int)param_6 + iVar4) ^ *(byte *)((int)param_1 + iVar4);
            *param_7 = param_3;
            return;
          }
        }
      }
    }
  }
  else if (param_3 == 0) {
    uVar8 = 0;
  }
  else {
    puVar7 = (uint *)((int)param_1 + param_3);
    uVar8 = 0;
    do {
      if (uVar8 == 0) {
        (*param_8)(param_5,param_6,param_4);
        uVar11 = *(byte *)((int)param_5 + 0xf) + 1;
        *(char *)((int)param_5 + 0xf) = (char)uVar11;
        uVar10 = (uint)*(byte *)((int)param_5 + 0xe) + (uVar11 >> 8);
        uVar6 = (uint)*(byte *)((int)param_5 + 0xd) + (uVar10 >> 8);
        uVar11 = (uint)*(byte *)(param_5 + 3) + (uVar6 >> 8);
        *(char *)((int)param_5 + 0xe) = (char)uVar10;
        *(char *)(param_5 + 3) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 0xb) + (uVar11 >> 8);
        *(char *)((int)param_5 + 0xd) = (char)uVar6;
        *(char *)((int)param_5 + 0xb) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 10) + (uVar11 >> 8);
        *(char *)((int)param_5 + 10) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 9) + (uVar11 >> 8);
        *(char *)((int)param_5 + 9) = (char)uVar11;
        uVar11 = (uint)*(byte *)(param_5 + 2) + (uVar11 >> 8);
        *(char *)(param_5 + 2) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 7) + (uVar11 >> 8);
        *(char *)((int)param_5 + 7) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 6) + (uVar11 >> 8);
        *(char *)((int)param_5 + 6) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 5) + (uVar11 >> 8);
        *(char *)((int)param_5 + 5) = (char)uVar11;
        uVar11 = (uint)*(byte *)(param_5 + 1) + (uVar11 >> 8);
        *(char *)(param_5 + 1) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 3) + (uVar11 >> 8);
        *(char *)((int)param_5 + 3) = (char)uVar11;
        uVar11 = (uint)*(byte *)((int)param_5 + 2) + (uVar11 >> 8);
        *(char *)((int)param_5 + 2) = (char)uVar11;
        iVar3 = (uint)*(byte *)((int)param_5 + 1) + (uVar11 >> 8);
        *(char *)((int)param_5 + 1) = (char)iVar3;
        *(char *)param_5 = *(char *)param_5 + (char)((uint)iVar3 >> 8);
      }
      pbVar2 = (byte *)((int)param_6 + uVar8);
      bVar1 = *(byte *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      uVar8 = uVar8 + 1 & 0xf;
      *(byte *)param_2 = *pbVar2 ^ bVar1;
      param_2 = (uint *)((int)param_2 + 1);
    } while (param_1 != puVar7);
  }
LAB_005e8d24:
  *param_7 = uVar8;
  return;
}

