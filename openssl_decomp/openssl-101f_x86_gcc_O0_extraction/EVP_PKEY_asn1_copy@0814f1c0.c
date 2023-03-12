
void EVP_PKEY_asn1_copy(EVP_PKEY_ASN1_METHOD *dst,EVP_PKEY_ASN1_METHOD *src)

{
  undefined4 uVar1;
  
  *(undefined4 *)(dst + 0x14) = *(undefined4 *)(src + 0x14);
  *(undefined4 *)(dst + 0x18) = *(undefined4 *)(src + 0x18);
  *(undefined4 *)(dst + 0x1c) = *(undefined4 *)(src + 0x1c);
  *(undefined4 *)(dst + 0x20) = *(undefined4 *)(src + 0x20);
  *(undefined4 *)(dst + 0x24) = *(undefined4 *)(src + 0x24);
  *(undefined4 *)(dst + 0x28) = *(undefined4 *)(src + 0x28);
  *(undefined4 *)(dst + 0x2c) = *(undefined4 *)(src + 0x2c);
  *(undefined4 *)(dst + 0x60) = *(undefined4 *)(src + 0x60);
  *(undefined4 *)(dst + 0x5c) = *(undefined4 *)(src + 0x5c);
  *(undefined4 *)(dst + 0x30) = *(undefined4 *)(src + 0x30);
  *(undefined4 *)(dst + 0x34) = *(undefined4 *)(src + 0x34);
  *(undefined4 *)(dst + 0x38) = *(undefined4 *)(src + 0x38);
  *(undefined4 *)(dst + 0x3c) = *(undefined4 *)(src + 0x3c);
  *(undefined4 *)(dst + 0x40) = *(undefined4 *)(src + 0x40);
  *(undefined4 *)(dst + 0x44) = *(undefined4 *)(src + 0x44);
  *(undefined4 *)(dst + 0x48) = *(undefined4 *)(src + 0x48);
  *(undefined4 *)(dst + 0x4c) = *(undefined4 *)(src + 0x4c);
  *(undefined4 *)(dst + 0x54) = *(undefined4 *)(src + 0x54);
  *(undefined4 *)(dst + 0x58) = *(undefined4 *)(src + 0x58);
  uVar1 = *(undefined4 *)(src + 100);
  *(undefined4 *)(dst + 0x68) = *(undefined4 *)(src + 0x68);
  *(undefined4 *)(dst + 100) = uVar1;
  return;
}

