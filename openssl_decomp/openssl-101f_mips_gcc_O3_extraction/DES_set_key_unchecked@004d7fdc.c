
void DES_set_key_unchecked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  uVar5 = (uint)(*key)[7] << 0x18 | (uint)(*key)[5] << 8 | (uint)(*key)[6] << 0x10 | (uint)(*key)[4]
  ;
  uVar3 = (uint)(*key)[3] << 0x18 | (uint)(*key)[1] << 8 | (uint)(*key)[2] << 0x10 | (uint)(*key)[0]
  ;
  uVar2 = (uVar5 >> 4 ^ uVar3) & 0xf0f0f0f;
  uVar3 = uVar3 ^ uVar2;
  uVar5 = uVar2 << 4 ^ uVar5;
  uVar2 = (uVar5 << 0x12 ^ uVar5) & 0xcccc0000;
  uVar4 = (uVar3 << 0x12 ^ uVar3) & 0xcccc0000;
  uVar5 = uVar2 >> 0x12 ^ uVar5 ^ uVar2;
  uVar3 = uVar4 >> 0x12 ^ uVar3 ^ uVar4;
  uVar2 = (uVar5 >> 1 ^ uVar3) & 0x55555555;
  uVar3 = uVar3 ^ uVar2;
  uVar5 = uVar2 << 1 ^ uVar5;
  uVar2 = (uVar3 >> 8 ^ uVar5) & 0xff00ff;
  uVar5 = uVar5 ^ uVar2;
  uVar3 = uVar2 << 8 ^ uVar3;
  uVar2 = (uVar5 >> 1 ^ uVar3) & 0x55555555;
  uVar3 = uVar3 ^ uVar2;
  uVar5 = uVar2 << 1 ^ uVar5;
  uVar2 = uVar3 & 0xfffffff;
  puVar6 = shifts2_6299;
  uVar3 = (uVar3 & 0xf0000000) >> 4 | uVar5 & 0xff00 | (uVar5 & 0xff) << 0x10 | (uVar5 << 8) >> 0x18
  ;
  do {
    uVar5 = uVar2 >> 1 | uVar2 << 0x1b;
    if (*(int *)puVar6 != 0) {
      uVar5 = uVar2 >> 2 | uVar2 << 0x1a;
    }
    uVar4 = uVar3 >> 1 | uVar3 << 0x1b;
    if (*(int *)puVar6 != 0) {
      uVar4 = uVar3 >> 2 | uVar3 << 0x1a;
    }
    puVar6 = (undefined1 *)((int)puVar6 + 4);
    uVar1 = uVar5 << 4;
    uVar2 = uVar5 & 0xfffffff;
    uVar3 = uVar4 & 0xfffffff;
    uVar4 = *(uint *)(des_skb + (((uVar3 << 0xb) >> 0x1a) + 0x180) * 4) |
            *(uint *)(des_skb + ((uVar4 & 0x3f) + 0x100) * 4) |
            *(uint *)(des_skb + (((uVar3 << 0x17) >> 0x1e | (uVar4 << 4) >> 0xc & 0x3c) + 0x140) * 4
                     ) |
            *(uint *)(des_skb + (((uVar3 << 7) >> 0x1c | (uVar4 << 4) >> 0x1a & 0x30) + 0x1c0) * 4);
    uVar5 = *(uint *)(des_skb + (((uVar2 << 0x18) >> 0x1e | uVar1 >> 0xb & 0x3c) + 0x40) * 4) |
            *(uint *)(des_skb + (((uVar2 << 0xf) >> 0x1c | uVar1 >> 0x12 & 0x30) + 0x80) * 4) |
            *(uint *)(des_skb + (uVar5 & 0x3f) * 4) |
            *(uint *)(des_skb +
                     (((uVar2 << 0xb) >> 0x1f | uVar1 >> 0x19 & 6 | uVar1 >> 0x1a & 0x38) + 0xc0) *
                     4);
    *(uint *)schedule = ((uVar4 << 0x10) >> 0x1e) + (uVar4 << 0x10 | uVar5 & 0xffff) * 4;
    *(uint *)((int)schedule + 4) = (uVar4 >> 0x1a) + (uVar5 >> 0x10 | uVar4 & 0xffff0000) * 0x40;
    schedule = (DES_key_schedule *)((int)schedule + 8);
  } while (puVar6 != des_skb);
  return;
}

