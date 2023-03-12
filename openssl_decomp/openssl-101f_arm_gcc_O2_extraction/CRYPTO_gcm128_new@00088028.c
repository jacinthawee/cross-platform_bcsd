
void * CRYPTO_gcm128_new(undefined4 param_1,code *param_2)

{
  byte bVar1;
  void *__s;
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
  
  __s = CRYPTO_malloc(0x178,"gcm128.c",0x5af);
  if (__s != (void *)0x0) {
    memset(__s,0,0x178);
    *(code **)((int)__s + 0x170) = param_2;
    *(undefined4 *)((int)__s + 0x174) = param_1;
    (*param_2)((int)__s + 0x50,(int)__s + 0x50,param_1);
    bVar1 = *(byte *)((int)__s + 0x5b);
    uVar21 = (uint)*(byte *)((int)__s + 0x5f);
    uVar11 = (uint)*(byte *)((int)__s + 0x51) << 0x10 | (uint)*(byte *)((int)__s + 0x50) << 0x18 |
             (uint)*(byte *)((int)__s + 0x53) | (uint)*(byte *)((int)__s + 0x52) << 8;
    uVar5 = (uint)*(byte *)((int)__s + 0x59) << 0x10 | (uint)*(byte *)((int)__s + 0x58) << 0x18 |
            (uint)bVar1 | (uint)*(byte *)((int)__s + 0x5a) << 8;
    uVar20 = OPENSSL_armcap_P & 1;
    uVar14 = (uint)*(byte *)((int)__s + 0x5d) << 0x10 | (uint)*(byte *)((int)__s + 0x5c) << 0x18 |
             uVar21 | (uint)*(byte *)((int)__s + 0x5e) << 8;
    uVar17 = (uint)*(byte *)((int)__s + 0x55) << 0x10 | (uint)*(byte *)((int)__s + 0x54) << 0x18 |
             (uint)*(byte *)((int)__s + 0x57) | (uint)*(byte *)((int)__s + 0x56) << 8;
    *(uint *)((int)__s + 0x50) = uVar17;
    *(uint *)((int)__s + 0x54) = uVar11;
    *(uint *)((int)__s + 0x58) = uVar14;
    *(uint *)((int)__s + 0x5c) = uVar5;
    if (uVar20 == 0) {
      uVar20 = (uint)((*(byte *)((int)__s + 0x53) & 1) != 0) << 0x1f | uVar17 >> 1;
      uVar2 = (uint)((bVar1 & 1) != 0) << 0x1f | uVar14 >> 1;
      uVar6 = uVar11 >> 1 ^ -(uVar21 & 1) & 0xe1000000;
      uVar18 = uVar5 >> 1 | (uint)*(byte *)((int)__s + 0x57) << 0x1f;
      uVar3 = (uint)((bVar1 & 2) != 0) << 0x1f | uVar2 >> 1;
      uVar4 = (uint)((uVar6 & 1) != 0) << 0x1f | uVar20 >> 1;
      uVar7 = uVar18 >> 1 | (uVar17 >> 1) << 0x1f;
      uVar8 = uVar6 >> 1 ^ -((uVar21 & 2) >> 1) & 0xe1000000;
      uVar15 = (uint)((uVar8 & 1) != 0) << 0x1f | uVar4 >> 1;
      uVar16 = (uint)((bVar1 & 4) != 0) << 0x1f | uVar3 >> 1;
      uVar21 = -((uVar21 & 4) >> 2) & 0xe1000000 ^ uVar8 >> 1;
      uVar19 = uVar7 >> 1 | (uVar20 >> 1) << 0x1f;
      uVar9 = uVar4 ^ uVar15;
      uVar12 = uVar8 ^ uVar21;
      uVar10 = uVar3 ^ uVar16;
      uVar13 = uVar7 ^ uVar19;
      *(uint *)((int)__s + 0x78) = uVar15;
      *(uint *)((int)__s + 0x7c) = uVar21;
      *(uint *)((int)__s + 0xa8) = uVar20;
      *(uint *)((int)__s + 0xac) = uVar6;
      *(uint *)((int)__s + 0xa0) = uVar2;
      *(uint *)((int)__s + 0xa4) = uVar18;
      *(uint *)((int)__s + 0x80) = uVar3;
      *(uint *)((int)__s + 0x84) = uVar7;
      *(uint *)((int)__s + 0x88) = uVar4;
      *(uint *)((int)__s + 0x8c) = uVar8;
      *(uint *)((int)__s + 0x98) = uVar9;
      *(uint *)((int)__s + 0x9c) = uVar12;
      *(uint *)((int)__s + 0xd8) = uVar9 ^ uVar20;
      *(uint *)((int)__s + 0xdc) = uVar12 ^ uVar6;
      *(uint *)((int)__s + 0xf8) = uVar15 ^ uVar17;
      *(uint *)((int)__s + 0xfc) = uVar21 ^ uVar11;
      *(uint *)((int)__s + 0xb8) = uVar20 ^ uVar15;
      *(uint *)((int)__s + 0xbc) = uVar6 ^ uVar21;
      *(uint *)((int)__s + 0x90) = uVar10;
      *(uint *)((int)__s + 0x94) = uVar13;
      *(uint *)((int)__s + 0x70) = uVar16;
      *(uint *)((int)__s + 0x74) = uVar19;
      *(uint *)((int)__s + 0xb0) = uVar2 ^ uVar16;
      *(uint *)((int)__s + 0xb4) = uVar18 ^ uVar19;
      *(uint *)((int)__s + 0xd0) = uVar2 ^ uVar10;
      *(uint *)((int)__s + 0xd4) = uVar18 ^ uVar13;
      *(uint *)((int)__s + 0xf0) = uVar16 ^ uVar14;
      *(uint *)((int)__s + 0xf4) = uVar19 ^ uVar5;
      *(uint *)((int)__s + 0xe8) = uVar17;
      *(uint *)((int)__s + 0xec) = uVar11;
      *(uint *)((int)__s + 0xe0) = uVar14;
      *(uint *)((int)__s + 0xe4) = uVar5;
      *(uint *)((int)__s + 200) = uVar4 ^ uVar20;
      *(uint *)((int)__s + 0xcc) = uVar8 ^ uVar6;
      *(uint *)((int)__s + 0xc0) = uVar3 ^ uVar2;
      *(uint *)((int)__s + 0xc4) = uVar7 ^ uVar18;
      *(undefined4 *)((int)__s + 0x68) = 0;
      *(undefined4 *)((int)__s + 0x6c) = 0;
      *(undefined4 *)((int)__s + 0x60) = 0;
      *(undefined4 *)((int)__s + 100) = 0;
      *(uint *)((int)__s + 0x100) = uVar3 ^ uVar14;
      *(uint *)((int)__s + 0x104) = uVar7 ^ uVar5;
      *(uint *)((int)__s + 0x108) = uVar4 ^ uVar17;
      *(uint *)((int)__s + 0x10c) = uVar8 ^ uVar11;
      *(uint *)((int)__s + 0x110) = uVar10 ^ uVar14;
      *(uint *)((int)__s + 0x114) = uVar13 ^ uVar5;
      *(uint *)((int)__s + 0x118) = uVar9 ^ uVar17;
      *(uint *)((int)__s + 0x11c) = uVar12 ^ uVar11;
      *(uint *)((int)__s + 0x120) = uVar2 ^ uVar14;
      *(uint *)((int)__s + 0x124) = uVar18 ^ uVar5;
      *(uint *)((int)__s + 0x128) = uVar20 ^ uVar17;
      *(uint *)((int)__s + 300) = uVar6 ^ uVar11;
      *(uint *)((int)__s + 0x130) = uVar2 ^ uVar16 ^ uVar14;
      *(uint *)((int)__s + 0x134) = uVar18 ^ uVar19 ^ uVar5;
      *(uint *)((int)__s + 0x138) = uVar20 ^ uVar15 ^ uVar17;
      *(uint *)((int)__s + 0x13c) = uVar6 ^ uVar21 ^ uVar11;
      *(uint *)((int)__s + 0x140) = uVar3 ^ uVar2 ^ uVar14;
      *(uint *)((int)__s + 0x144) = uVar7 ^ uVar18 ^ uVar5;
      *(uint *)((int)__s + 0x148) = uVar4 ^ uVar20 ^ uVar17;
      *(uint *)((int)__s + 0x14c) = uVar8 ^ uVar6 ^ uVar11;
      *(uint *)((int)__s + 0x150) = uVar2 ^ uVar10 ^ uVar14;
      *(uint *)((int)__s + 0x154) = uVar18 ^ uVar13 ^ uVar5;
      *(uint *)((int)__s + 0x158) = uVar9 ^ uVar20 ^ uVar17;
      *(uint *)((int)__s + 0x15c) = uVar12 ^ uVar6 ^ uVar11;
      *(code **)((int)__s + 0x160) = gcm_gmult_4bit;
      *(code **)((int)__s + 0x164) = gcm_ghash_4bit;
      return __s;
    }
    *(code **)((int)__s + 0x160) = gcm_gmult_neon;
    *(code **)((int)__s + 0x164) = gcm_ghash_neon;
  }
  return __s;
}

