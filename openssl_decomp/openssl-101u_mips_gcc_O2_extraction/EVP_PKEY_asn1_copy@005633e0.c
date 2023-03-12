
void EVP_PKEY_asn1_copy(EVP_PKEY_ASN1_METHOD *dst,EVP_PKEY_ASN1_METHOD *src)

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
  
  uVar5 = *(undefined4 *)(src + 0x38);
  uVar4 = *(undefined4 *)(src + 0x3c);
  uVar3 = *(undefined4 *)(src + 0x40);
  uVar2 = *(undefined4 *)(src + 0x44);
  uVar15 = *(undefined4 *)(src + 0x1c);
  uVar14 = *(undefined4 *)(src + 0x20);
  uVar12 = *(undefined4 *)(src + 0x24);
  uVar11 = *(undefined4 *)(src + 0x28);
  uVar10 = *(undefined4 *)(src + 0x2c);
  uVar9 = *(undefined4 *)(src + 0x60);
  uVar8 = *(undefined4 *)(src + 0x5c);
  uVar7 = *(undefined4 *)(src + 0x30);
  uVar6 = *(undefined4 *)(src + 0x34);
  *(undefined4 *)(dst + 0x18) = *(undefined4 *)(src + 0x18);
  uVar13 = *(undefined4 *)(src + 0x14);
  uVar1 = *(undefined4 *)(src + 0x48);
  *(undefined4 *)(dst + 0x38) = uVar5;
  *(undefined4 *)(dst + 0x3c) = uVar4;
  *(undefined4 *)(dst + 0x14) = uVar13;
  *(undefined4 *)(dst + 0x40) = uVar3;
  *(undefined4 *)(dst + 0x1c) = uVar15;
  *(undefined4 *)(dst + 0x20) = uVar14;
  *(undefined4 *)(dst + 0x24) = uVar12;
  *(undefined4 *)(dst + 0x28) = uVar11;
  *(undefined4 *)(dst + 0x2c) = uVar10;
  *(undefined4 *)(dst + 0x60) = uVar9;
  *(undefined4 *)(dst + 0x5c) = uVar8;
  *(undefined4 *)(dst + 0x30) = uVar7;
  *(undefined4 *)(dst + 0x34) = uVar6;
  *(undefined4 *)(dst + 0x44) = uVar2;
  *(undefined4 *)(dst + 0x48) = uVar1;
  uVar4 = *(undefined4 *)(src + 0x54);
  uVar3 = *(undefined4 *)(src + 0x58);
  uVar2 = *(undefined4 *)(src + 0x68);
  uVar1 = *(undefined4 *)(src + 100);
  *(undefined4 *)(dst + 0x4c) = *(undefined4 *)(src + 0x4c);
  *(undefined4 *)(dst + 0x54) = uVar4;
  *(undefined4 *)(dst + 0x58) = uVar3;
  *(undefined4 *)(dst + 0x68) = uVar2;
  *(undefined4 *)(dst + 100) = uVar1;
  return;
}

