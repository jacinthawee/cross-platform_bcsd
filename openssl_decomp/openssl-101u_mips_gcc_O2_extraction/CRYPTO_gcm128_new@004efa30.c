
int CRYPTO_gcm128_new(undefined4 param_1,code *param_2)

{
  int iVar1;
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
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x178,"gcm128.c",0x669);
  if (iVar1 != 0) {
    (*(code *)PTR_memset_006a99f4)(iVar1,0,0x178);
    *(code **)(iVar1 + 0x170) = param_2;
    *(undefined4 *)(iVar1 + 0x174) = param_1;
    (*param_2)(iVar1 + 0x50,iVar1 + 0x50,param_1);
    uVar14 = 0xe1000000;
    uVar3 = *(uint *)(iVar1 + 0x58);
    uVar2 = *(uint *)(iVar1 + 0x5c);
    uVar10 = 0xe1000000;
    uVar4 = *(uint *)(iVar1 + 0x54);
    uVar18 = 0xe1000000;
    uVar5 = *(uint *)(iVar1 + 0x50);
    uVar6 = uVar2 >> 1;
    *(uint *)(iVar1 + 0xe8) = uVar3;
    *(uint *)(iVar1 + 0xec) = uVar2;
    uVar7 = uVar3 << 0x1f | uVar6;
    if ((uVar2 & 1) == 0) {
      uVar10 = 0;
    }
    if ((uVar6 & 1) == 0) {
      uVar18 = 0;
    }
    uVar8 = uVar4 << 0x1f | uVar3 >> 1;
    *(uint *)(iVar1 + 0xe4) = uVar4;
    *(uint *)(iVar1 + 0xe0) = uVar5;
    *(uint *)(iVar1 + 0xac) = uVar7;
    *(uint *)(iVar1 + 0xa8) = uVar8;
    uVar9 = uVar5 << 0x1f | uVar4 >> 1;
    uVar10 = uVar10 ^ uVar5 >> 1;
    uVar11 = (uVar3 >> 1) << 0x1f | uVar7 >> 1;
    *(uint *)(iVar1 + 0xa4) = uVar9;
    *(uint *)(iVar1 + 0xa0) = uVar10;
    *(uint *)(iVar1 + 0x8c) = uVar11;
    uVar12 = (uVar4 >> 1) << 0x1f | uVar8 >> 1;
    uVar13 = (uVar5 >> 1) << 0x1f | uVar9 >> 1;
    *(uint *)(iVar1 + 0x88) = uVar12;
    *(uint *)(iVar1 + 0x84) = uVar13;
    uVar18 = uVar18 ^ uVar10 >> 1;
    uVar19 = (uVar9 >> 1) << 0x1f | uVar12 >> 1;
    *(uint *)(iVar1 + 0x80) = uVar18;
    *(uint *)(iVar1 + 0x78) = uVar19;
    uVar15 = (uVar8 >> 1) << 0x1f | uVar11 >> 1;
    if ((uVar6 & 2) == 0) {
      uVar14 = 0;
    }
    *(uint *)(iVar1 + 0x7c) = uVar15;
    *(uint *)(iVar1 + 0xbc) = uVar7 ^ uVar15;
    uVar20 = (uVar10 >> 1) << 0x1f | uVar13 >> 1;
    uVar14 = uVar14 ^ uVar18 >> 1;
    *(uint *)(iVar1 + 200) = uVar8 ^ uVar12;
    uVar21 = uVar18 ^ uVar14;
    *(uint *)(iVar1 + 0x74) = uVar20;
    uVar17 = uVar13 ^ uVar20;
    *(uint *)(iVar1 + 0x70) = uVar14;
    uVar16 = uVar12 ^ uVar19;
    *(uint *)(iVar1 + 0x90) = uVar21;
    uVar6 = uVar11 ^ uVar15;
    *(uint *)(iVar1 + 0x94) = uVar17;
    *(uint *)(iVar1 + 0x98) = uVar16;
    *(uint *)(iVar1 + 0x9c) = uVar6;
    *(uint *)(iVar1 + 0xb0) = uVar10 ^ uVar14;
    *(uint *)(iVar1 + 0xb4) = uVar9 ^ uVar20;
    *(uint *)(iVar1 + 0xb8) = uVar8 ^ uVar19;
    *(uint *)(iVar1 + 0xc0) = uVar10 ^ uVar18;
    *(uint *)(iVar1 + 0xcc) = uVar7 ^ uVar11;
    *(uint *)(iVar1 + 0xf0) = uVar5 ^ uVar14;
    *(uint *)(iVar1 + 0xd0) = uVar10 ^ uVar21;
    *(uint *)(iVar1 + 0xf4) = uVar4 ^ uVar20;
    *(uint *)(iVar1 + 0xd4) = uVar9 ^ uVar17;
    *(uint *)(iVar1 + 0xf8) = uVar3 ^ uVar19;
    *(uint *)(iVar1 + 0xd8) = uVar8 ^ uVar16;
    *(uint *)(iVar1 + 0xc4) = uVar9 ^ uVar13;
    *(uint *)(iVar1 + 0xdc) = uVar7 ^ uVar6;
    *(uint *)(iVar1 + 0x100) = uVar5 ^ uVar18;
    *(uint *)(iVar1 + 0x104) = uVar4 ^ uVar13;
    *(uint *)(iVar1 + 0xfc) = uVar2 ^ uVar15;
    *(uint *)(iVar1 + 0x10c) = uVar2 ^ uVar11;
    *(uint *)(iVar1 + 0x108) = uVar3 ^ uVar12;
    *(uint *)(iVar1 + 0x110) = uVar5 ^ uVar21;
    *(uint *)(iVar1 + 0x114) = uVar4 ^ uVar17;
    *(undefined4 *)(iVar1 + 100) = 0;
    *(undefined4 *)(iVar1 + 0x6c) = 0;
    *(undefined4 *)(iVar1 + 0x60) = 0;
    *(undefined4 *)(iVar1 + 0x68) = 0;
    *(uint *)(iVar1 + 0x118) = uVar3 ^ uVar16;
    *(uint *)(iVar1 + 0x120) = uVar5 ^ uVar10;
    *(uint *)(iVar1 + 0x11c) = uVar2 ^ uVar6;
    *(uint *)(iVar1 + 0x124) = uVar4 ^ uVar9;
    *(uint *)(iVar1 + 0x128) = uVar3 ^ uVar8;
    *(uint *)(iVar1 + 300) = uVar2 ^ uVar7;
    *(uint *)(iVar1 + 0x130) = uVar5 ^ uVar10 ^ uVar14;
    *(uint *)(iVar1 + 0x134) = uVar4 ^ uVar9 ^ uVar20;
    *(uint *)(iVar1 + 0x138) = uVar3 ^ uVar8 ^ uVar19;
    *(uint *)(iVar1 + 0x140) = uVar5 ^ uVar10 ^ uVar18;
    *(uint *)(iVar1 + 0x144) = uVar4 ^ uVar9 ^ uVar13;
    *(uint *)(iVar1 + 0x148) = uVar3 ^ *(uint *)(iVar1 + 200);
    *(uint *)(iVar1 + 0x14c) = uVar2 ^ *(uint *)(iVar1 + 0xcc);
    *(uint *)(iVar1 + 0x150) = uVar5 ^ *(uint *)(iVar1 + 0xd0);
    *(uint *)(iVar1 + 0x154) = uVar4 ^ *(uint *)(iVar1 + 0xd4);
    *(uint *)(iVar1 + 0x158) = uVar3 ^ *(uint *)(iVar1 + 0xd8);
    *(uint *)(iVar1 + 0x15c) = uVar2 ^ *(uint *)(iVar1 + 0xdc);
    *(uint *)(iVar1 + 0x13c) = uVar2 ^ uVar7 ^ uVar15;
  }
  return iVar1;
}

