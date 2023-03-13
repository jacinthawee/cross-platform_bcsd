
void CRYPTO_gcm128_setiv(uint *param_1,uint *param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = param_3;
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
    uVar5 = 2;
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    uVar3 = param_2[2];
    *(undefined *)((int)param_1 + 0xf) = 1;
    param_1[2] = uVar3;
    goto LAB_080ef90e;
  }
  uVar3 = param_3;
  puVar4 = param_2;
  if (0xf < param_3) {
    do {
      uVar3 = uVar3 - 0x10;
      *(byte *)param_1 = *(byte *)param_1 ^ *(byte *)puVar4;
      *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) ^ *(byte *)((int)puVar4 + 1);
      *(byte *)((int)param_1 + 2) = *(byte *)((int)param_1 + 2) ^ *(byte *)((int)puVar4 + 2);
      *(byte *)((int)param_1 + 3) = *(byte *)((int)param_1 + 3) ^ *(byte *)((int)puVar4 + 3);
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) ^ *(byte *)(puVar4 + 1);
      *(byte *)((int)param_1 + 5) = *(byte *)((int)param_1 + 5) ^ *(byte *)((int)puVar4 + 5);
      *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) ^ *(byte *)((int)puVar4 + 6);
      *(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) ^ *(byte *)((int)puVar4 + 7);
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) ^ *(byte *)(puVar4 + 2);
      *(byte *)((int)param_1 + 9) = *(byte *)((int)param_1 + 9) ^ *(byte *)((int)puVar4 + 9);
      *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) ^ *(byte *)((int)puVar4 + 10);
      *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)puVar4 + 0xb);
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) ^ *(byte *)(puVar4 + 3);
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) ^ *(byte *)((int)puVar4 + 0xd);
      *(byte *)((int)param_1 + 0xe) = *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)puVar4 + 0xe);
      *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) ^ *(byte *)((int)puVar4 + 0xf);
      gcm_gmult_4bit();
      puVar4 = puVar4 + 4;
    } while (0xf < uVar3);
    param_2 = (uint *)((int)param_2 + (param_3 - 0x10 & 0xfffffff0) + 0x10);
    param_3 = param_3 & 0xf;
  }
  if (param_3 != 0) {
    if ((param_2 < param_1 + 1 && param_1 < param_2 + 1 || param_3 < 6) ||
       (((uint)param_2 & 3) != 0)) {
      *(byte *)param_1 = *(byte *)param_1 ^ *(byte *)param_2;
      if (((((param_3 != 1) &&
            (((*(byte *)((int)param_1 + 1) =
                    *(byte *)((int)param_1 + 1) ^ *(byte *)((int)param_2 + 1), param_3 != 2 &&
              (*(byte *)((int)param_1 + 2) =
                    *(byte *)((int)param_1 + 2) ^ *(byte *)((int)param_2 + 2), param_3 != 3)) &&
             (*(byte *)((int)param_1 + 3) =
                   *(byte *)((int)param_1 + 3) ^ *(byte *)((int)param_2 + 3), param_3 != 4)))) &&
           (((*(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) ^ *(byte *)(param_2 + 1), 5 < param_3
             && (*(byte *)((int)param_1 + 5) =
                      *(byte *)((int)param_1 + 5) ^ *(byte *)((int)param_2 + 5), 6 < param_3)) &&
            (*(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) ^ *(byte *)((int)param_2 + 6)
            , param_3 != 7)))) &&
          ((*(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) ^ *(byte *)((int)param_2 + 7),
           param_3 != 8 &&
           (*(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) ^ *(byte *)(param_2 + 2), param_3 != 9))
          )) && ((*(byte *)((int)param_1 + 9) =
                       *(byte *)((int)param_1 + 9) ^ *(byte *)((int)param_2 + 9), param_3 != 10 &&
                 ((((*(byte *)((int)param_1 + 10) =
                          *(byte *)((int)param_1 + 10) ^ *(byte *)((int)param_2 + 10),
                    param_3 != 0xb &&
                    (*(byte *)((int)param_1 + 0xb) =
                          *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)param_2 + 0xb),
                    param_3 != 0xc)) &&
                   (*(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) ^ *(byte *)(param_2 + 3),
                   param_3 != 0xd)) &&
                  (*(byte *)((int)param_1 + 0xd) =
                        *(byte *)((int)param_1 + 0xd) ^ *(byte *)((int)param_2 + 0xd),
                  param_3 == 0xf)))))) {
        *(byte *)((int)param_1 + 0xe) =
             *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)param_2 + 0xe);
      }
    }
    else {
      iVar2 = (param_3 - 4 >> 2) + 1;
      uVar3 = iVar2 * 4;
      if (param_3 - 1 < 3) {
        uVar3 = 0;
      }
      else {
        *param_1 = *param_1 ^ *param_2;
        if (((iVar2 != 1) && (param_1[1] = param_1[1] ^ param_2[1], iVar2 != 2)) &&
           (param_1[2] = param_1[2] ^ param_2[2], iVar2 != 3)) {
          param_1[3] = param_1[3] ^ param_2[3];
        }
        if (param_3 == uVar3) goto LAB_080ef8d7;
      }
      *(byte *)((int)param_1 + uVar3) =
           *(byte *)((int)param_1 + uVar3) ^ *(byte *)((int)param_2 + uVar3);
      if (uVar3 + 1 < param_3) {
        pbVar1 = (byte *)((int)param_1 + uVar3 + 1);
        *pbVar1 = *pbVar1 ^ *(byte *)((int)param_2 + uVar3 + 1);
        if (uVar3 + 2 < param_3) {
          pbVar1 = (byte *)((int)param_1 + uVar3 + 2);
          *pbVar1 = *pbVar1 ^ *(byte *)((int)param_2 + uVar3 + 2);
        }
      }
    }
LAB_080ef8d7:
    gcm_gmult_4bit();
  }
  uVar3 = uVar5 << 3;
  param_1[2] = param_1[2] ^ (uVar5 >> 0x1d) << 0x18;
  param_1[3] = param_1[3] ^
               (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar5 << 0x1b);
  gcm_gmult_4bit();
  uVar5 = param_1[3];
  uVar5 = (uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18) + 1;
LAB_080ef90e:
  (*(code *)param_1[0x5c])(param_1,param_1 + 8,param_1[0x5d]);
  param_1[3] = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  return;
}

