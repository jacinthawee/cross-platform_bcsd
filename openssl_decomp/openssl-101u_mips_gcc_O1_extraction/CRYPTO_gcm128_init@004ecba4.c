
void CRYPTO_gcm128_init(int param_1,undefined4 param_2,code *param_3,undefined4 param_4)

{
  uint uVar1;
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
  
  (*(code *)PTR_memset_006a99f4)(param_1,0,0x178,param_4,&_gp);
  *(code **)(param_1 + 0x170) = param_3;
  *(undefined4 *)(param_1 + 0x174) = param_2;
  (*param_3)(param_1 + 0x50,param_1 + 0x50,param_2);
  uVar13 = 0xe1000000;
  uVar2 = *(uint *)(param_1 + 0x58);
  uVar1 = *(uint *)(param_1 + 0x5c);
  uVar9 = 0xe1000000;
  uVar3 = *(uint *)(param_1 + 0x54);
  uVar17 = 0xe1000000;
  uVar4 = *(uint *)(param_1 + 0x50);
  uVar5 = uVar1 >> 1;
  *(uint *)(param_1 + 0xe8) = uVar2;
  *(uint *)(param_1 + 0xec) = uVar1;
  uVar6 = uVar2 << 0x1f | uVar5;
  if ((uVar1 & 1) == 0) {
    uVar9 = 0;
  }
  if ((uVar5 & 1) == 0) {
    uVar17 = 0;
  }
  uVar7 = uVar3 << 0x1f | uVar2 >> 1;
  *(uint *)(param_1 + 0xe4) = uVar3;
  *(uint *)(param_1 + 0xe0) = uVar4;
  *(uint *)(param_1 + 0xac) = uVar6;
  *(uint *)(param_1 + 0xa8) = uVar7;
  uVar8 = uVar4 << 0x1f | uVar3 >> 1;
  uVar9 = uVar9 ^ uVar4 >> 1;
  uVar10 = (uVar2 >> 1) << 0x1f | uVar6 >> 1;
  *(uint *)(param_1 + 0xa4) = uVar8;
  *(uint *)(param_1 + 0xa0) = uVar9;
  *(uint *)(param_1 + 0x8c) = uVar10;
  uVar11 = (uVar3 >> 1) << 0x1f | uVar7 >> 1;
  uVar12 = (uVar4 >> 1) << 0x1f | uVar8 >> 1;
  *(uint *)(param_1 + 0x88) = uVar11;
  *(uint *)(param_1 + 0x84) = uVar12;
  uVar17 = uVar17 ^ uVar9 >> 1;
  uVar18 = (uVar8 >> 1) << 0x1f | uVar11 >> 1;
  *(uint *)(param_1 + 0x80) = uVar17;
  *(uint *)(param_1 + 0x78) = uVar18;
  uVar14 = (uVar7 >> 1) << 0x1f | uVar10 >> 1;
  if ((uVar5 & 2) == 0) {
    uVar13 = 0;
  }
  *(uint *)(param_1 + 0x7c) = uVar14;
  *(uint *)(param_1 + 0xbc) = uVar6 ^ uVar14;
  uVar19 = (uVar9 >> 1) << 0x1f | uVar12 >> 1;
  uVar13 = uVar13 ^ uVar17 >> 1;
  *(uint *)(param_1 + 200) = uVar7 ^ uVar11;
  uVar20 = uVar17 ^ uVar13;
  *(uint *)(param_1 + 0x74) = uVar19;
  uVar16 = uVar12 ^ uVar19;
  *(uint *)(param_1 + 0x70) = uVar13;
  uVar15 = uVar11 ^ uVar18;
  *(uint *)(param_1 + 0x90) = uVar20;
  uVar5 = uVar10 ^ uVar14;
  *(uint *)(param_1 + 0x94) = uVar16;
  *(uint *)(param_1 + 0x98) = uVar15;
  *(uint *)(param_1 + 0x9c) = uVar5;
  *(uint *)(param_1 + 0xb0) = uVar9 ^ uVar13;
  *(uint *)(param_1 + 0xb4) = uVar8 ^ uVar19;
  *(uint *)(param_1 + 0xb8) = uVar7 ^ uVar18;
  *(uint *)(param_1 + 0xc0) = uVar9 ^ uVar17;
  *(uint *)(param_1 + 0xcc) = uVar6 ^ uVar10;
  *(uint *)(param_1 + 0xf0) = uVar4 ^ uVar13;
  *(uint *)(param_1 + 0xd0) = uVar9 ^ uVar20;
  *(uint *)(param_1 + 0xf4) = uVar3 ^ uVar19;
  *(uint *)(param_1 + 0xd4) = uVar8 ^ uVar16;
  *(uint *)(param_1 + 0xf8) = uVar2 ^ uVar18;
  *(uint *)(param_1 + 0xd8) = uVar7 ^ uVar15;
  *(uint *)(param_1 + 0xc4) = uVar8 ^ uVar12;
  *(uint *)(param_1 + 0xdc) = uVar6 ^ uVar5;
  *(uint *)(param_1 + 0x100) = uVar4 ^ uVar17;
  *(uint *)(param_1 + 0x104) = uVar3 ^ uVar12;
  *(uint *)(param_1 + 0xfc) = uVar1 ^ uVar14;
  *(uint *)(param_1 + 0x10c) = uVar1 ^ uVar10;
  *(uint *)(param_1 + 0x108) = uVar2 ^ uVar11;
  *(uint *)(param_1 + 0x110) = uVar4 ^ uVar20;
  *(uint *)(param_1 + 0x114) = uVar3 ^ uVar16;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(uint *)(param_1 + 0x118) = uVar2 ^ uVar15;
  *(uint *)(param_1 + 0x120) = uVar4 ^ uVar9;
  *(uint *)(param_1 + 0x11c) = uVar1 ^ uVar5;
  *(uint *)(param_1 + 0x130) = uVar4 ^ uVar9 ^ uVar13;
  *(uint *)(param_1 + 0x134) = uVar3 ^ uVar8 ^ uVar19;
  *(uint *)(param_1 + 0x138) = uVar2 ^ uVar7 ^ uVar18;
  *(uint *)(param_1 + 0x124) = uVar3 ^ uVar8;
  *(uint *)(param_1 + 0x128) = uVar2 ^ uVar7;
  *(uint *)(param_1 + 300) = uVar1 ^ uVar6;
  *(uint *)(param_1 + 0x140) = uVar4 ^ uVar9 ^ uVar17;
  *(uint *)(param_1 + 0x144) = uVar3 ^ uVar8 ^ uVar12;
  *(uint *)(param_1 + 0x148) = uVar2 ^ *(uint *)(param_1 + 200);
  *(uint *)(param_1 + 0x14c) = uVar1 ^ *(uint *)(param_1 + 0xcc);
  *(uint *)(param_1 + 0x150) = uVar4 ^ *(uint *)(param_1 + 0xd0);
  *(uint *)(param_1 + 0x154) = uVar3 ^ *(uint *)(param_1 + 0xd4);
  *(uint *)(param_1 + 0x158) = uVar2 ^ *(uint *)(param_1 + 0xd8);
  *(uint *)(param_1 + 0x15c) = uVar1 ^ *(uint *)(param_1 + 0xdc);
  *(uint *)(param_1 + 0x13c) = uVar1 ^ uVar6 ^ uVar14;
  return;
}

