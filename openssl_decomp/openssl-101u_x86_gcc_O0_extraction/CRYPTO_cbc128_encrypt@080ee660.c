
void CRYPTO_cbc128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  
  puVar2 = param_5;
  puVar5 = param_1;
  puVar6 = param_2;
  uVar7 = param_3;
  if (param_3 < 0x10) {
    if (param_3 == 0) goto LAB_080ee826;
  }
  else {
    do {
      uVar7 = uVar7 - 0x10;
      *puVar6 = *puVar5 ^ *puVar2;
      puVar6[1] = puVar5[1] ^ puVar2[1];
      puVar6[2] = puVar5[2] ^ puVar2[2];
      puVar6[3] = puVar5[3] ^ puVar2[3];
      (*param_6)(puVar6,puVar6,param_4);
      puVar2 = puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
    } while (0xf < uVar7);
    iVar4 = (param_3 - 0x10 >> 4) + 1;
    puVar2 = (uint *)((param_3 - 0x10 & 0xfffffff0) + (int)param_2);
    param_1 = param_1 + iVar4 * 4;
    param_2 = param_2 + iVar4 * 4;
    param_3 = param_3 & 0xf;
    if (param_3 == 0) goto LAB_080ee826;
  }
  uVar7 = 0;
  do {
    uVar3 = uVar7;
    *(byte *)((int)param_2 + uVar3) =
         *(byte *)((int)param_1 + uVar3) ^ *(byte *)((int)puVar2 + uVar3);
    uVar7 = uVar3 + 1;
  } while (uVar7 < param_3);
  *(undefined *)((int)param_2 + uVar7) = *(undefined *)((int)puVar2 + uVar7);
  if (((((uVar3 != 0xe) &&
        (*(undefined *)((int)param_2 + uVar3 + 2) = *(undefined *)((int)puVar2 + uVar3 + 2),
        uVar3 != 0xd)) &&
       (*(undefined *)((int)param_2 + uVar3 + 3) = *(undefined *)((int)puVar2 + uVar3 + 3),
       uVar3 != 0xc)) &&
      ((((*(undefined *)((int)param_2 + uVar3 + 4) = *(undefined *)((int)puVar2 + uVar3 + 4),
         uVar3 != 0xb &&
         (*(undefined *)((int)param_2 + uVar3 + 5) = *(undefined *)((int)puVar2 + uVar3 + 5),
         uVar3 != 10)) &&
        ((*(undefined *)((int)param_2 + uVar3 + 6) = *(undefined *)((int)puVar2 + uVar3 + 6),
         uVar3 != 9 &&
         ((*(undefined *)((int)param_2 + uVar3 + 7) = *(undefined *)((int)puVar2 + uVar3 + 7),
          uVar3 != 8 &&
          (*(undefined *)((int)param_2 + uVar3 + 8) = *(undefined *)((int)puVar2 + uVar3 + 8),
          uVar3 != 7)))))) &&
       (*(undefined *)((int)param_2 + uVar3 + 9) = *(undefined *)((int)puVar2 + uVar3 + 9),
       uVar3 != 6)))) &&
     ((((*(undefined *)((int)param_2 + uVar3 + 10) = *(undefined *)((int)puVar2 + uVar3 + 10),
        uVar3 != 5 &&
        (*(undefined *)((int)param_2 + uVar3 + 0xb) = *(undefined *)((int)puVar2 + uVar3 + 0xb),
        uVar3 != 4)) &&
       (*(undefined *)((int)param_2 + uVar3 + 0xc) = *(undefined *)((int)puVar2 + uVar3 + 0xc),
       uVar3 != 3)) &&
      ((*(undefined *)((int)param_2 + uVar3 + 0xd) = *(undefined *)((int)puVar2 + uVar3 + 0xd),
       uVar3 != 2 &&
       (*(undefined *)((int)param_2 + uVar3 + 0xe) = *(undefined *)((int)puVar2 + uVar3 + 0xe),
       uVar3 != 1)))))) {
    *(undefined *)((int)param_2 + 0xf) = *(undefined *)((int)puVar2 + 0xf);
  }
  (*param_6)(param_2,param_2,param_4);
  puVar2 = param_2;
LAB_080ee826:
  uVar7 = puVar2[1];
  uVar3 = puVar2[2];
  uVar1 = puVar2[3];
  *param_5 = *puVar2;
  param_5[1] = uVar7;
  param_5[2] = uVar3;
  param_5[3] = uVar1;
  return;
}

