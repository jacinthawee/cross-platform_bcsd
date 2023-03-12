
void CRYPTO_gcm128_setiv(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  param_1[0x5b] = 0;
  param_1[0x5a] = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xf] = 0;
  param_1[0xe] = 0;
  if (param_3 == 0xc) {
    uVar2 = 2;
    uVar3 = param_2[1];
    uVar6 = param_2[2];
    *param_1 = *param_2;
    param_1[1] = uVar3;
    param_1[2] = uVar6;
    *(undefined *)((int)param_1 + 0xf) = 1;
    goto LAB_004f0160;
  }
  puVar5 = param_1 + 0x18;
  puVar4 = param_2;
  uVar6 = param_3;
  if (0xf < param_3) {
    do {
      uVar6 = uVar6 - 0x10;
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
      gcm_gmult_4bit(param_1,puVar5);
      puVar4 = puVar4 + 4;
    } while (0xf < uVar6);
    uVar6 = param_3 & 0xf;
    param_2 = param_2 + ((param_3 - 0x10 >> 4) + 1) * 4;
  }
  if (uVar6 != 0) {
    if ((uVar6 < 6 || param_1 < param_2 + 1 && param_2 < param_1 + 1) || (((uint)param_2 & 3) != 0))
    {
      *(byte *)param_1 = *(byte *)param_2 ^ *(byte *)param_1;
      if (((((uVar6 != 1) &&
            (((*(byte *)((int)param_1 + 1) =
                    *(byte *)((int)param_2 + 1) ^ *(byte *)((int)param_1 + 1), uVar6 != 2 &&
              (*(byte *)((int)param_1 + 2) =
                    *(byte *)((int)param_2 + 2) ^ *(byte *)((int)param_1 + 2), uVar6 != 3)) &&
             (*(byte *)((int)param_1 + 3) =
                   *(byte *)((int)param_1 + 3) ^ *(byte *)((int)param_2 + 3), uVar6 != 4)))) &&
           (((*(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) ^ *(byte *)(param_2 + 1), uVar6 >= 6
             && (*(byte *)((int)param_1 + 5) =
                      *(byte *)((int)param_1 + 5) ^ *(byte *)((int)param_2 + 5), 6 < uVar6)) &&
            (*(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) ^ *(byte *)((int)param_2 + 6)
            , uVar6 != 7)))) &&
          ((*(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) ^ *(byte *)((int)param_2 + 7),
           uVar6 != 8 &&
           (*(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) ^ *(byte *)(param_2 + 2), uVar6 != 9))))
         && ((*(byte *)((int)param_1 + 9) =
                   *(byte *)((int)param_1 + 9) ^ *(byte *)((int)param_2 + 9), uVar6 != 10 &&
             ((((*(byte *)((int)param_1 + 10) =
                      *(byte *)((int)param_1 + 10) ^ *(byte *)((int)param_2 + 10), uVar6 != 0xb &&
                (*(byte *)((int)param_1 + 0xb) =
                      *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)param_2 + 0xb), uVar6 != 0xc))
               && (*(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) ^ *(byte *)(param_2 + 3),
                  uVar6 != 0xd)) &&
              (*(byte *)((int)param_1 + 0xd) =
                    *(byte *)((int)param_1 + 0xd) ^ *(byte *)((int)param_2 + 0xd), uVar6 == 0xf)))))
         ) {
        *(byte *)((int)param_1 + 0xe) =
             *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)param_2 + 0xe);
      }
    }
    else {
      iVar1 = (uVar6 - 4 >> 2) + 1;
      uVar3 = iVar1 * 4;
      if (uVar6 - 1 < 3) {
        uVar3 = 0;
      }
      else {
        *param_1 = *param_2 ^ *param_1;
        if (((iVar1 != 1) && (param_1[1] = param_2[1] ^ param_1[1], iVar1 != 2)) &&
           (param_1[2] = param_1[2] ^ param_2[2], iVar1 != 3)) {
          param_1[3] = param_1[3] ^ param_2[3];
        }
        if (uVar3 == uVar6) goto LAB_004f0124;
      }
      uVar2 = uVar3 + 1;
      *(byte *)((int)param_1 + uVar3) =
           *(byte *)((int)param_2 + uVar3) ^ *(byte *)((int)param_1 + uVar3);
      if (uVar2 < uVar6) {
        uVar3 = uVar3 + 2;
        *(byte *)((int)param_1 + uVar2) =
             *(byte *)((int)param_2 + uVar2) ^ *(byte *)((int)param_1 + uVar2);
        if (uVar3 < uVar6) {
          *(byte *)((int)param_1 + uVar3) =
               *(byte *)((int)param_2 + uVar3) ^ *(byte *)((int)param_1 + uVar3);
        }
      }
    }
LAB_004f0124:
    gcm_gmult_4bit(param_1,puVar5);
  }
  param_1[2] = param_1[2] ^ param_3 >> 0x1d;
  param_1[3] = param_1[3] ^ param_3 << 3;
  gcm_gmult_4bit(param_1,puVar5);
  uVar2 = param_1[3] + 1;
LAB_004f0160:
  (*(code *)param_1[0x5c])(param_1,param_1 + 8,param_1[0x5d]);
  param_1[3] = uVar2;
  return;
}

