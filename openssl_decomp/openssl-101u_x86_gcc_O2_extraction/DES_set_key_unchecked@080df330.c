
void DES_set_key_unchecked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (*(uint *)(*key + 4) >> 4 ^ *(uint *)*key) & 0xf0f0f0f;
  uVar1 = *(uint *)*key ^ uVar5;
  uVar3 = *(uint *)(*key + 4) ^ uVar5 << 4;
  uVar5 = (uVar1 << 0x12 ^ uVar1) & 0xcccc0000;
  uVar5 = uVar1 ^ uVar5 ^ uVar5 >> 0x12;
  uVar1 = (uVar3 << 0x12 ^ uVar3) & 0xcccc0000;
  uVar3 = uVar3 ^ uVar1 ^ uVar1 >> 0x12;
  uVar1 = (uVar3 >> 1 ^ uVar5) & 0x55555555;
  uVar5 = uVar5 ^ uVar1;
  uVar3 = uVar3 ^ uVar1 * 2;
  uVar1 = (uVar5 >> 8 ^ uVar3) & 0xff00ff;
  uVar3 = uVar3 ^ uVar1;
  uVar5 = uVar1 << 8 ^ uVar5;
  uVar1 = (uVar3 >> 1 ^ uVar5) & 0x55555555;
  uVar5 = uVar5 ^ uVar1;
  uVar3 = uVar3 ^ uVar1 * 2;
  uVar1 = uVar5 & 0xfffffff;
  uVar5 = (uVar3 & 0xff) << 0x10 | (uVar5 & 0xf0000000) >> 4 | uVar3 & 0xff00 |
          (uVar3 & 0xff0000) >> 0x10;
  iVar4 = 0;
  do {
    if (*(int *)(shifts2_6398 + iVar4) == 0) {
      uVar2 = uVar1 >> 1 | uVar1 << 0x1b;
      uVar3 = uVar5 >> 1 | uVar5 << 0x1b;
    }
    else {
      uVar2 = uVar1 >> 2 | uVar1 << 0x1a;
      uVar3 = uVar5 >> 2 | uVar5 << 0x1a;
    }
    uVar5 = uVar3 & 0xfffffff;
    uVar1 = uVar2 & 0xfffffff;
    uVar2 = *(uint *)(des_skb + (uVar1 >> 6 & 3 | uVar1 >> 7 & 0x3c) * 4 + 0x100) |
            *(uint *)(des_skb + (uVar1 >> 0xd & 0xf | uVar1 >> 0xe & 0x30) * 4 + 0x200) |
            *(uint *)(des_skb + (uVar2 & 0x3f) * 4) |
            *(uint *)(des_skb +
                     (uVar1 >> 0x16 & 0x38 | uVar1 >> 0x15 & 6 | uVar1 >> 0x14 & 1) * 4 + 0x300);
    uVar3 = *(uint *)(des_skb + (uVar5 >> 0xf & 0x3f) * 4 + 0x600) |
            *(uint *)(des_skb + (uVar3 & 0x3f) * 4 + 0x400) |
            *(uint *)(des_skb + (uVar5 >> 8 & 0x3c | uVar5 >> 7 & 3) * 4 + 0x500) |
            *(uint *)(des_skb + (uVar5 >> 0x16 & 0x30 | uVar5 >> 0x15 & 0xf) * 4 + 0x700);
    *(uint *)((int)schedule->ks + iVar4 * 2) =
         (uVar3 << 0x10) >> 0x1e | (uVar2 & 0xffff | uVar3 << 0x10) << 2;
    *(uint *)((int)schedule->ks + iVar4 * 2 + 4) =
         uVar3 >> 0x1a | (uVar3 & 0xffff0000 | uVar2 >> 0x10) << 6;
    iVar4 = iVar4 + 4;
  } while (iVar4 != 0x40);
  return;
}

