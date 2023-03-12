
undefined8 _armv4_AES_encrypt(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int unaff_r10;
  uint *unaff_r11;
  uint *puVar12;
  int iVar13;
  
  param_1 = param_1 ^ *unaff_r11;
  param_2 = param_2 ^ unaff_r11[1];
  param_3 = param_3 ^ unaff_r11[2];
  param_4 = param_4 ^ unaff_r11[3];
  iVar13 = unaff_r11[0x3c] - 1;
  uVar4 = param_1 & 0xff;
  uVar2 = param_1 >> 0x18;
  puVar1 = unaff_r11 + 4;
  do {
    puVar12 = puVar1;
    uVar3 = *(uint *)(unaff_r10 + uVar4 * 4);
    uVar4 = *(uint *)(unaff_r10 + (param_2 >> 0x10 & 0xff) * 4);
    uVar6 = *(uint *)(unaff_r10 + (param_2 & 0xff) * 4);
    uVar9 = *(uint *)(unaff_r10 + (param_2 >> 8 & 0xff) * 4);
    uVar6 = *(uint *)(unaff_r10 + (param_1 >> 8 & 0xff) * 4) ^ (uVar6 >> 8 | uVar6 << 0x18);
    uVar5 = *(uint *)(unaff_r10 + (param_3 >> 8 & 0xff) * 4);
    uVar7 = *(uint *)(unaff_r10 + (param_3 >> 0x10 & 0xff) * 4);
    uVar10 = *(uint *)(unaff_r10 + (param_3 & 0xff) * 4);
    uVar9 = *(uint *)(unaff_r10 + (param_1 >> 0x10 & 0xff) * 4) ^ (uVar9 >> 8 | uVar9 << 0x18) ^
            (uVar10 >> 0x10 | uVar10 << 0x10);
    uVar10 = *(uint *)(unaff_r10 + (param_4 & 0xff) * 4);
    uVar8 = *(uint *)(unaff_r10 + (param_4 >> 8 & 0xff) * 4);
    uVar11 = *(uint *)(unaff_r10 + (param_4 >> 0x10 & 0xff) * 4);
    param_1 = *(uint *)(unaff_r10 + uVar2 * 4) ^ (uVar4 >> 8 | uVar4 << 0x18) ^
              (uVar5 >> 0x10 | uVar5 << 0x10) ^ (uVar10 >> 0x18 | uVar10 << 8) ^ *puVar12;
    uVar4 = param_1 & 0xff;
    param_2 = *(uint *)(unaff_r10 + (param_2 >> 0x18) * 4) ^ (uVar3 >> 0x18 | uVar3 << 8) ^
              (uVar7 >> 8 | uVar7 << 0x18) ^ (uVar8 >> 0x10 | uVar8 << 0x10) ^ puVar12[1];
    param_3 = *(uint *)(unaff_r10 + (param_3 >> 0x18) * 4) ^ (uVar6 >> 0x10 | uVar6 << 0x10) ^
              (uVar11 >> 8 | uVar11 << 0x18) ^ puVar12[2];
    param_4 = *(uint *)(unaff_r10 + (param_4 >> 0x18) * 4) ^ (uVar9 >> 8 | uVar9 << 0x18) ^
              puVar12[3];
    uVar2 = param_1 >> 0x18;
    iVar13 = iVar13 + -1;
    puVar1 = puVar12 + 4;
  } while (iVar13 != 0);
  iVar13 = unaff_r10 + 2;
  return CONCAT44((uint)*(byte *)(iVar13 + uVar4 * 4) ^
                  (uint)*(byte *)(iVar13 + (param_2 >> 0x18) * 4) << 0x18 ^
                  (uint)*(byte *)(iVar13 + (param_3 >> 0x10 & 0xff) * 4) << 0x10 ^
                  (uint)*(byte *)(iVar13 + (param_4 >> 8 & 0xff) * 4) << 8 ^ puVar12[5],
                  CONCAT31(CONCAT21(CONCAT11(*(undefined *)(iVar13 + uVar2 * 4),
                                             *(undefined *)(iVar13 + (param_2 >> 0x10 & 0xff) * 4)),
                                    *(undefined *)(iVar13 + (param_3 >> 8 & 0xff) * 4)),
                           *(undefined *)(iVar13 + (param_4 & 0xff) * 4)) ^ puVar12[4]);
}

