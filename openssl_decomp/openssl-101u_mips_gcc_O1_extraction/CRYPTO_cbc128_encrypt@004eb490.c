
void CRYPTO_cbc128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint *puVar18;
  uint *puVar19;
  uint uVar20;
  
  puVar1 = param_5;
  if ((((uint)param_5 | (uint)param_1 | (uint)param_2) & 3) == 0) {
    puVar18 = param_2;
    puVar19 = param_1;
    uVar20 = param_3;
    if (0xf < param_3) {
      do {
        uVar20 = uVar20 - 0x10;
        *puVar18 = *puVar19 ^ *puVar1;
        puVar18[1] = puVar19[1] ^ puVar1[1];
        puVar18[2] = puVar19[2] ^ puVar1[2];
        puVar18[3] = puVar19[3] ^ puVar1[3];
        (*param_6)(puVar18,puVar18,param_4);
        puVar1 = puVar18;
        puVar18 = puVar18 + 4;
        puVar19 = puVar19 + 4;
      } while (0xf < uVar20);
      uVar20 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar2 = (uVar20 >> 4) + 1;
      puVar1 = (uint *)((int)param_2 + (uVar20 & 0xfffffff0));
      param_1 = param_1 + iVar2 * 4;
      param_2 = param_2 + iVar2 * 4;
    }
  }
  else {
    puVar18 = param_2;
    puVar19 = param_1;
    uVar20 = param_3;
    if (0xf < param_3) {
      do {
        uVar20 = uVar20 - 0x10;
        *(byte *)puVar18 = *(byte *)puVar19 ^ *(byte *)puVar1;
        *(byte *)((int)puVar18 + 1) = *(byte *)((int)puVar19 + 1) ^ *(byte *)((int)puVar1 + 1);
        *(byte *)((int)puVar18 + 2) = *(byte *)((int)puVar19 + 2) ^ *(byte *)((int)puVar1 + 2);
        *(byte *)((int)puVar18 + 3) = *(byte *)((int)puVar19 + 3) ^ *(byte *)((int)puVar1 + 3);
        *(byte *)(puVar18 + 1) = *(byte *)(puVar19 + 1) ^ *(byte *)(puVar1 + 1);
        *(byte *)((int)puVar18 + 5) = *(byte *)((int)puVar19 + 5) ^ *(byte *)((int)puVar1 + 5);
        *(byte *)((int)puVar18 + 6) = *(byte *)((int)puVar19 + 6) ^ *(byte *)((int)puVar1 + 6);
        *(byte *)((int)puVar18 + 7) = *(byte *)((int)puVar19 + 7) ^ *(byte *)((int)puVar1 + 7);
        *(byte *)(puVar18 + 2) = *(byte *)(puVar19 + 2) ^ *(byte *)(puVar1 + 2);
        *(byte *)((int)puVar18 + 9) = *(byte *)((int)puVar19 + 9) ^ *(byte *)((int)puVar1 + 9);
        *(byte *)((int)puVar18 + 10) = *(byte *)((int)puVar19 + 10) ^ *(byte *)((int)puVar1 + 10);
        *(byte *)((int)puVar18 + 0xb) = *(byte *)((int)puVar19 + 0xb) ^ *(byte *)((int)puVar1 + 0xb)
        ;
        *(byte *)(puVar18 + 3) = *(byte *)(puVar19 + 3) ^ *(byte *)(puVar1 + 3);
        *(byte *)((int)puVar18 + 0xd) = *(byte *)((int)puVar19 + 0xd) ^ *(byte *)((int)puVar1 + 0xd)
        ;
        *(byte *)((int)puVar18 + 0xe) = *(byte *)((int)puVar19 + 0xe) ^ *(byte *)((int)puVar1 + 0xe)
        ;
        *(byte *)((int)puVar18 + 0xf) = *(byte *)((int)puVar19 + 0xf) ^ *(byte *)((int)puVar1 + 0xf)
        ;
        (*param_6)(puVar18,puVar18,param_4);
        puVar1 = puVar18;
        puVar18 = puVar18 + 4;
        puVar19 = puVar19 + 4;
      } while (0xf < uVar20);
      uVar20 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar2 = (uVar20 >> 4) + 1;
      puVar1 = (uint *)((int)param_2 + (uVar20 & 0xfffffff0));
      param_1 = param_1 + iVar2 * 4;
      param_2 = param_2 + iVar2 * 4;
    }
  }
  if (param_3 == 0) goto LAB_004eb718;
  *(byte *)param_2 = *(byte *)param_1 ^ *(byte *)puVar1;
  if (param_3 == 1) {
    iVar8 = 0xe;
    iVar16 = 0xd;
    iVar7 = 0xc;
    iVar9 = 0xb;
    iVar11 = 10;
    iVar12 = 9;
    iVar13 = 8;
    iVar14 = 7;
    iVar15 = 6;
    iVar6 = 5;
    iVar10 = 4;
    iVar5 = 3;
    iVar2 = 2;
    iVar17 = 1;
LAB_004eb938:
    *(byte *)((int)param_2 + iVar17) = *(byte *)((int)puVar1 + iVar17);
    *(byte *)((int)param_2 + iVar2) = *(byte *)((int)puVar1 + iVar2);
    if (((((iVar5 != 0x10) &&
          (*(byte *)((int)param_2 + iVar5) = *(byte *)((int)puVar1 + iVar5), iVar10 != 0x10)) &&
         (*(byte *)((int)param_2 + iVar10) = *(byte *)((int)puVar1 + iVar10), iVar6 != 0x10)) &&
        (((*(byte *)((int)param_2 + iVar6) = *(byte *)((int)puVar1 + iVar6), iVar15 != 0x10 &&
          (*(byte *)((int)param_2 + iVar15) = *(byte *)((int)puVar1 + iVar15), iVar14 != 0x10)) &&
         ((*(byte *)((int)param_2 + iVar14) = *(byte *)((int)puVar1 + iVar14), iVar13 != 0x10 &&
          ((*(byte *)((int)param_2 + iVar13) = *(byte *)((int)puVar1 + iVar13), iVar12 != 0x10 &&
           (*(byte *)((int)param_2 + iVar12) = *(byte *)((int)puVar1 + iVar12), iVar11 != 0x10))))))
        )) && ((*(byte *)((int)param_2 + iVar11) = *(byte *)((int)puVar1 + iVar11), iVar9 != 0x10 &&
               ((((*(byte *)((int)param_2 + iVar9) = *(byte *)((int)puVar1 + iVar9), iVar7 != 0x10
                  && (*(byte *)((int)param_2 + iVar7) = *(byte *)((int)puVar1 + iVar7),
                     iVar16 != 0x10)) &&
                 (*(byte *)((int)param_2 + iVar16) = *(byte *)((int)puVar1 + iVar16), iVar8 != 0x10)
                 ) && (*(byte *)((int)param_2 + iVar8) = *(byte *)((int)puVar1 + iVar8), iVar17 == 1
                      )))))) {
      *(byte *)((int)param_2 + 0xf) = *(byte *)((int)puVar1 + 0xf);
    }
  }
  else {
    *(byte *)((int)param_2 + 1) = *(byte *)((int)param_1 + 1) ^ *(byte *)((int)puVar1 + 1);
    if (param_3 == 2) {
      iVar8 = 0xf;
      iVar16 = 0xe;
      iVar7 = 0xd;
      iVar9 = 0xc;
      iVar11 = 0xb;
      iVar12 = 10;
      iVar13 = 9;
      iVar14 = 8;
      iVar15 = 7;
      iVar6 = 6;
      iVar10 = 5;
      iVar5 = 4;
      iVar2 = 3;
      iVar17 = 2;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 2) = *(byte *)((int)param_1 + 2) ^ *(byte *)((int)puVar1 + 2);
    if (param_3 == 3) {
      iVar8 = 0x10;
      iVar16 = 0xf;
      iVar7 = 0xe;
      iVar9 = 0xd;
      iVar11 = 0xc;
      iVar12 = 0xb;
      iVar13 = 10;
      iVar14 = 9;
      iVar15 = 8;
      iVar6 = 7;
      iVar10 = 6;
      iVar5 = 5;
      iVar2 = 4;
      iVar17 = 3;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 3) = *(byte *)((int)param_1 + 3) ^ *(byte *)((int)puVar1 + 3);
    if (param_3 == 4) {
      iVar8 = 0x11;
      iVar16 = 0x10;
      iVar7 = 0xf;
      iVar9 = 0xe;
      iVar11 = 0xd;
      iVar12 = 0xc;
      iVar13 = 0xb;
      iVar14 = 10;
      iVar15 = 9;
      iVar6 = 8;
      iVar10 = 7;
      iVar5 = 6;
      iVar2 = 5;
      iVar17 = 4;
      goto LAB_004eb938;
    }
    *(byte *)(param_2 + 1) = *(byte *)(param_1 + 1) ^ *(byte *)(puVar1 + 1);
    if (param_3 == 5) {
      iVar8 = 0x12;
      iVar16 = 0x11;
      iVar7 = 0x10;
      iVar9 = 0xf;
      iVar11 = 0xe;
      iVar12 = 0xd;
      iVar13 = 0xc;
      iVar14 = 0xb;
      iVar15 = 10;
      iVar6 = 9;
      iVar10 = 8;
      iVar5 = 7;
      iVar2 = 6;
      iVar17 = 5;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 5) = *(byte *)((int)param_1 + 5) ^ *(byte *)((int)puVar1 + 5);
    if (param_3 == 6) {
      iVar8 = 0x13;
      iVar16 = 0x12;
      iVar7 = 0x11;
      iVar9 = 0x10;
      iVar11 = 0xf;
      iVar12 = 0xe;
      iVar13 = 0xd;
      iVar14 = 0xc;
      iVar15 = 0xb;
      iVar6 = 10;
      iVar10 = 9;
      iVar5 = 8;
      iVar2 = 7;
      iVar17 = 6;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 6) = *(byte *)((int)param_1 + 6) ^ *(byte *)((int)puVar1 + 6);
    if (param_3 == 7) {
      iVar8 = 0x14;
      iVar16 = 0x13;
      iVar7 = 0x12;
      iVar9 = 0x11;
      iVar11 = 0x10;
      iVar12 = 0xf;
      iVar13 = 0xe;
      iVar14 = 0xd;
      iVar15 = 0xc;
      iVar6 = 0xb;
      iVar10 = 10;
      iVar5 = 9;
      iVar2 = 8;
      iVar17 = 7;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 7) = *(byte *)((int)param_1 + 7) ^ *(byte *)((int)puVar1 + 7);
    if (param_3 == 8) {
      iVar8 = 0x15;
      iVar16 = 0x14;
      iVar7 = 0x13;
      iVar9 = 0x12;
      iVar11 = 0x11;
      iVar12 = 0x10;
      iVar13 = 0xf;
      iVar14 = 0xe;
      iVar15 = 0xd;
      iVar6 = 0xc;
      iVar10 = 0xb;
      iVar5 = 10;
      iVar2 = 9;
      iVar17 = 8;
      goto LAB_004eb938;
    }
    *(byte *)(param_2 + 2) = *(byte *)(param_1 + 2) ^ *(byte *)(puVar1 + 2);
    if (param_3 == 9) {
      iVar8 = 0x16;
      iVar16 = 0x15;
      iVar7 = 0x14;
      iVar9 = 0x13;
      iVar11 = 0x12;
      iVar12 = 0x11;
      iVar13 = 0x10;
      iVar14 = 0xf;
      iVar15 = 0xe;
      iVar6 = 0xd;
      iVar10 = 0xc;
      iVar5 = 0xb;
      iVar2 = 10;
      iVar17 = 9;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 9) = *(byte *)((int)param_1 + 9) ^ *(byte *)((int)puVar1 + 9);
    if (param_3 == 10) {
      iVar8 = 0x17;
      iVar16 = 0x16;
      iVar7 = 0x15;
      iVar9 = 0x14;
      iVar11 = 0x13;
      iVar12 = 0x12;
      iVar13 = 0x11;
      iVar14 = 0x10;
      iVar15 = 0xf;
      iVar6 = 0xe;
      iVar10 = 0xd;
      iVar5 = 0xc;
      iVar2 = 0xb;
      iVar17 = 10;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 10) = *(byte *)((int)param_1 + 10) ^ *(byte *)((int)puVar1 + 10);
    if (param_3 == 0xb) {
      iVar8 = 0x18;
      iVar16 = 0x17;
      iVar7 = 0x16;
      iVar9 = 0x15;
      iVar11 = 0x14;
      iVar12 = 0x13;
      iVar13 = 0x12;
      iVar14 = 0x11;
      iVar15 = 0x10;
      iVar6 = 0xf;
      iVar10 = 0xe;
      iVar5 = 0xd;
      iVar2 = 0xc;
      iVar17 = 0xb;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 0xb) = *(byte *)((int)param_1 + 0xb) ^ *(byte *)((int)puVar1 + 0xb);
    if (param_3 == 0xc) {
      iVar8 = 0x19;
      iVar16 = 0x18;
      iVar7 = 0x17;
      iVar9 = 0x16;
      iVar11 = 0x15;
      iVar12 = 0x14;
      iVar13 = 0x13;
      iVar14 = 0x12;
      iVar15 = 0x11;
      iVar6 = 0x10;
      iVar10 = 0xf;
      iVar5 = 0xe;
      iVar2 = 0xd;
      iVar17 = 0xc;
      goto LAB_004eb938;
    }
    *(byte *)(param_2 + 3) = *(byte *)(param_1 + 3) ^ *(byte *)(puVar1 + 3);
    if (param_3 == 0xd) {
      iVar8 = 0x1a;
      iVar16 = 0x19;
      iVar7 = 0x18;
      iVar9 = 0x17;
      iVar11 = 0x16;
      iVar12 = 0x15;
      iVar13 = 0x14;
      iVar14 = 0x13;
      iVar15 = 0x12;
      iVar6 = 0x11;
      iVar10 = 0x10;
      iVar5 = 0xf;
      iVar2 = 0xe;
      iVar17 = 0xd;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_1 + 0xd) ^ *(byte *)((int)puVar1 + 0xd);
    if (param_3 != 0xf) {
      iVar8 = 0x1b;
      iVar16 = 0x1a;
      iVar7 = 0x19;
      iVar9 = 0x18;
      iVar11 = 0x17;
      iVar12 = 0x16;
      iVar13 = 0x15;
      iVar14 = 0x14;
      iVar15 = 0x13;
      iVar6 = 0x12;
      iVar10 = 0x11;
      iVar5 = 0x10;
      iVar2 = 0xf;
      iVar17 = 0xe;
      goto LAB_004eb938;
    }
    *(byte *)((int)param_2 + 0xe) = *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)puVar1 + 0xe);
    *(byte *)((int)param_2 + 0xf) = *(byte *)((int)puVar1 + 0xf);
  }
  (*param_6)(param_2,param_2,param_4);
  puVar1 = param_2;
LAB_004eb718:
  uVar4 = puVar1[1];
  uVar3 = puVar1[2];
  uVar20 = puVar1[3];
  *param_5 = *puVar1;
  param_5[1] = uVar4;
  param_5[2] = uVar3;
  param_5[3] = uVar20;
  return;
}

