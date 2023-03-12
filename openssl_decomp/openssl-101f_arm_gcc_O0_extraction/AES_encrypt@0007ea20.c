
void AES_encrypt(uchar *in,uchar *out,AES_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  uVar1 = *(uint *)in;
  uVar2 = *(uint *)(in + 4);
  uVar3 = *(uint *)(in + 8);
  uVar4 = *(uint *)(in + 0xc);
  uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
  uVar4 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
  uVar5 = _armv4_AES_encrypt(uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 |
                             (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18,
                             uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 |
                             (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18);
  uVar2 = (uint)((ulonglong)uVar5 >> 0x20);
  uVar1 = (uint)uVar5;
  *(uint *)out = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
                 uVar1 >> 0x18;
  *(uint *)(out + 4) =
       uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  *(uint *)(out + 8) =
       uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
  *(uint *)(out + 0xc) =
       uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
  return;
}

