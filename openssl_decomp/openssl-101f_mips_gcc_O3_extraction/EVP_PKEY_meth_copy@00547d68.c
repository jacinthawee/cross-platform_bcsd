
void EVP_PKEY_meth_copy(EVP_PKEY_METHOD *dst,EVP_PKEY_METHOD *src)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  uVar9 = *(undefined4 *)(src + 0x24);
  uVar8 = *(undefined4 *)(src + 0x28);
  uVar7 = *(undefined4 *)(src + 0x2c);
  uVar6 = *(undefined4 *)(src + 0x30);
  uVar5 = *(undefined4 *)(src + 0x34);
  uVar4 = *(undefined4 *)(src + 0x38);
  uVar3 = *(undefined4 *)(src + 0x3c);
  uVar2 = *(undefined4 *)(src + 0x40);
  uVar15 = *(undefined4 *)(src + 0x10);
  uVar14 = *(undefined4 *)(src + 0x14);
  uVar12 = *(undefined4 *)(src + 0x18);
  uVar11 = *(undefined4 *)(src + 0x1c);
  uVar10 = *(undefined4 *)(src + 0x20);
  *(undefined4 *)(dst + 0xc) = *(undefined4 *)(src + 0xc);
  uVar13 = *(undefined4 *)(src + 8);
  uVar1 = *(undefined4 *)(src + 0x44);
  *(undefined4 *)(dst + 0x24) = uVar9;
  *(undefined4 *)(dst + 0x28) = uVar8;
  *(undefined4 *)(dst + 8) = uVar13;
  *(undefined4 *)(dst + 0x2c) = uVar7;
  *(undefined4 *)(dst + 0x30) = uVar6;
  *(undefined4 *)(dst + 0x34) = uVar5;
  *(undefined4 *)(dst + 0x38) = uVar4;
  *(undefined4 *)(dst + 0x3c) = uVar3;
  *(undefined4 *)(dst + 0x10) = uVar15;
  *(undefined4 *)(dst + 0x14) = uVar14;
  *(undefined4 *)(dst + 0x18) = uVar12;
  *(undefined4 *)(dst + 0x1c) = uVar11;
  *(undefined4 *)(dst + 0x20) = uVar10;
  *(undefined4 *)(dst + 0x40) = uVar2;
  *(undefined4 *)(dst + 0x44) = uVar1;
  uVar8 = *(undefined4 *)(src + 0x4c);
  uVar7 = *(undefined4 *)(src + 0x50);
  uVar6 = *(undefined4 *)(src + 0x54);
  uVar5 = *(undefined4 *)(src + 0x58);
  uVar4 = *(undefined4 *)(src + 0x5c);
  uVar3 = *(undefined4 *)(src + 0x60);
  uVar2 = *(undefined4 *)(src + 100);
  uVar1 = *(undefined4 *)(src + 0x68);
  *(undefined4 *)(dst + 0x48) = *(undefined4 *)(src + 0x48);
  *(undefined4 *)(dst + 0x4c) = uVar8;
  *(undefined4 *)(dst + 0x50) = uVar7;
  *(undefined4 *)(dst + 0x54) = uVar6;
  *(undefined4 *)(dst + 0x58) = uVar5;
  *(undefined4 *)(dst + 0x5c) = uVar4;
  *(undefined4 *)(dst + 0x60) = uVar3;
  *(undefined4 *)(dst + 100) = uVar2;
  *(undefined4 *)(dst + 0x68) = uVar1;
  return;
}

