
int MD4_Update(MD4_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  size_t __n;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  byte bVar8;
  
  bVar8 = 0;
  if (len == 0) {
    return 1;
  }
  uVar4 = c->Nl + len * 8;
  uVar1 = c->Nh;
  if (uVar4 < c->Nl) {
    uVar1 = uVar1 + 1;
  }
  c->Nl = uVar4;
  c->Nh = uVar1 + (len >> 0x1d);
  uVar4 = c->num;
  if (uVar4 == 0) {
    uVar4 = len >> 6;
    if (uVar4 == 0) goto LAB_081aca93;
LAB_081acac0:
    md4_block_data_order(c,data,uVar4);
    data = (void *)((int)data + uVar4 * 0x40);
    len = len + uVar4 * -0x40;
  }
  else {
    if ((len < 0x40) && (len + uVar4 < 0x40)) {
      memcpy((void *)((int)c->data + uVar4),data,len);
      c->num = c->num + len;
      return 1;
    }
    __n = 0x40 - uVar4;
    memcpy((void *)((int)c->data + uVar4),data,__n);
    uVar4 = ((c->C ^ c->D) & c->B ^ c->D) + c->A + c->data[0];
    uVar5 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = ((c->B ^ c->C) & uVar5 ^ c->C) + c->D + c->data[1];
    uVar2 = uVar4 * 0x80 | uVar4 >> 0x19;
    uVar4 = ((c->B ^ uVar5) & uVar2 ^ c->B) + c->C + c->data[2];
    uVar3 = uVar4 * 0x800 | uVar4 >> 0x15;
    uVar4 = ((uVar5 ^ uVar2) & uVar3 ^ uVar5) + c->B + c->data[3];
    uVar1 = uVar4 * 0x80000 | uVar4 >> 0xd;
    uVar4 = ((uVar2 ^ uVar3) & uVar1 ^ uVar2) + c->data[4] + uVar5;
    uVar5 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = ((uVar3 ^ uVar1) & uVar5 ^ uVar3) + c->data[5] + uVar2;
    uVar2 = uVar4 * 0x80 | uVar4 >> 0x19;
    uVar4 = ((uVar1 ^ uVar5) & uVar2 ^ uVar1) + c->data[6] + uVar3;
    uVar3 = uVar4 * 0x800 | uVar4 >> 0x15;
    uVar4 = ((uVar5 ^ uVar2) & uVar3 ^ uVar5) + c->data[7] + uVar1;
    uVar1 = uVar4 * 0x80000 | uVar4 >> 0xd;
    uVar4 = ((uVar2 ^ uVar3) & uVar1 ^ uVar2) + c->data[8] + uVar5;
    uVar5 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = ((uVar3 ^ uVar1) & uVar5 ^ uVar3) + c->data[9] + uVar2;
    uVar2 = uVar4 * 0x80 | uVar4 >> 0x19;
    uVar4 = ((uVar1 ^ uVar5) & uVar2 ^ uVar1) + c->data[10] + uVar3;
    uVar3 = uVar4 * 0x800 | uVar4 >> 0x15;
    uVar4 = ((uVar5 ^ uVar2) & uVar3 ^ uVar5) + c->data[0xb] + uVar1;
    uVar1 = uVar4 * 0x80000 | uVar4 >> 0xd;
    uVar4 = ((uVar2 ^ uVar3) & uVar1 ^ uVar2) + c->data[0xc] + uVar5;
    uVar5 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = ((uVar3 ^ uVar1) & uVar5 ^ uVar3) + c->data[0xd] + uVar2;
    uVar2 = uVar4 * 0x80 | uVar4 >> 0x19;
    uVar4 = ((uVar1 ^ uVar5) & uVar2 ^ uVar1) + c->data[0xe] + uVar3;
    uVar3 = uVar4 * 0x800 | uVar4 >> 0x15;
    uVar4 = ((uVar5 ^ uVar2) & uVar3 ^ uVar5) + c->data[0xf] + uVar1;
    uVar1 = uVar4 * 0x80000 | uVar4 >> 0xd;
    uVar4 = (uVar2 & uVar3 | (uVar2 | uVar3) & uVar1) + c->data[0] + 0x5a827999 + uVar5;
    uVar5 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = (uVar3 & uVar1 | (uVar3 | uVar1) & uVar5) + c->data[4] + 0x5a827999 + uVar2;
    uVar2 = uVar4 * 0x20 | uVar4 >> 0x1b;
    uVar4 = (uVar1 & uVar5 | (uVar1 | uVar5) & uVar2) + c->data[8] + 0x5a827999 + uVar3;
    uVar3 = uVar4 * 0x200 | uVar4 >> 0x17;
    uVar4 = (uVar5 & uVar2 | (uVar5 | uVar2) & uVar3) + c->data[0xc] + 0x5a827999 + uVar1;
    uVar1 = uVar4 * 0x2000 | uVar4 >> 0x13;
    uVar4 = (uVar2 & uVar3 | (uVar2 | uVar3) & uVar1) + c->data[1] + 0x5a827999 + uVar5;
    uVar5 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = (uVar3 & uVar1 | (uVar3 | uVar1) & uVar5) + c->data[5] + 0x5a827999 + uVar2;
    uVar2 = uVar4 * 0x20 | uVar4 >> 0x1b;
    uVar4 = (uVar1 & uVar5 | (uVar1 | uVar5) & uVar2) + c->data[9] + 0x5a827999 + uVar3;
    uVar3 = uVar4 * 0x200 | uVar4 >> 0x17;
    uVar4 = (uVar5 & uVar2 | (uVar5 | uVar2) & uVar3) + c->data[0xd] + 0x5a827999 + uVar1;
    uVar6 = uVar4 * 0x2000 | uVar4 >> 0x13;
    uVar4 = (uVar2 & uVar3 | (uVar2 | uVar3) & uVar6) + c->data[2] + 0x5a827999 + uVar5;
    uVar1 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = (uVar3 & uVar6 | (uVar3 | uVar6) & uVar1) + c->data[6] + 0x5a827999 + uVar2;
    uVar2 = uVar4 * 0x20 | uVar4 >> 0x1b;
    uVar4 = (uVar6 & uVar1 | (uVar6 | uVar1) & uVar2) + c->data[10] + 0x5a827999 + uVar3;
    uVar5 = uVar4 * 0x200 | uVar4 >> 0x17;
    uVar4 = (uVar1 & uVar2 | (uVar1 | uVar2) & uVar5) + c->data[0xe] + 0x5a827999 + uVar6;
    uVar3 = uVar4 * 0x2000 | uVar4 >> 0x13;
    uVar4 = (uVar2 & uVar5 | (uVar2 | uVar5) & uVar3) + c->data[3] + 0x5a827999 + uVar1;
    uVar1 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = (uVar5 & uVar3 | (uVar5 | uVar3) & uVar1) + c->data[7] + 0x5a827999 + uVar2;
    uVar2 = uVar4 * 0x20 | uVar4 >> 0x1b;
    uVar4 = (uVar3 & uVar1 | (uVar3 | uVar1) & uVar2) + c->data[0xb] + 0x5a827999 + uVar5;
    uVar5 = uVar4 * 0x200 | uVar4 >> 0x17;
    uVar4 = c->data[0xf] + 0x5a827999 + uVar3 + (uVar1 & uVar2 | (uVar1 | uVar2) & uVar5);
    uVar3 = uVar4 * 0x2000 | uVar4 >> 0x13;
    uVar4 = (uVar2 ^ uVar5 ^ uVar3) + c->data[0] + 0x6ed9eba1 + uVar1;
    uVar4 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar1 = (uVar5 ^ uVar3 ^ uVar4) + c->data[8] + 0x6ed9eba1 + uVar2;
    uVar1 = uVar1 * 0x200 | uVar1 >> 0x17;
    uVar2 = (uVar3 ^ uVar4 ^ uVar1) + c->data[4] + 0x6ed9eba1 + uVar5;
    uVar5 = uVar2 * 0x800 | uVar2 >> 0x15;
    uVar2 = (uVar4 ^ uVar1 ^ uVar5) + c->data[0xc] + 0x6ed9eba1 + uVar3;
    uVar2 = uVar2 * 0x8000 | uVar2 >> 0x11;
    uVar4 = (uVar1 ^ uVar5 ^ uVar2) + c->data[2] + 0x6ed9eba1 + uVar4;
    uVar6 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar4 = (uVar5 ^ uVar2 ^ uVar6) + c->data[10] + 0x6ed9eba1 + uVar1;
    uVar1 = uVar4 * 0x200 | uVar4 >> 0x17;
    uVar4 = (uVar2 ^ uVar6 ^ uVar1) + c->data[6] + 0x6ed9eba1 + uVar5;
    uVar4 = uVar4 * 0x800 | uVar4 >> 0x15;
    uVar2 = (uVar6 ^ uVar1 ^ uVar4) + c->data[0xe] + 0x6ed9eba1 + uVar2;
    uVar3 = uVar2 * 0x8000 | uVar2 >> 0x11;
    uVar2 = (uVar1 ^ uVar4 ^ uVar3) + c->data[1] + 0x6ed9eba1 + uVar6;
    uVar6 = uVar2 * 8 | uVar2 >> 0x1d;
    uVar1 = (uVar4 ^ uVar3 ^ uVar6) + c->data[9] + 0x6ed9eba1 + uVar1;
    uVar2 = uVar1 * 0x200 | uVar1 >> 0x17;
    uVar4 = (uVar3 ^ uVar6 ^ uVar2) + c->data[5] + 0x6ed9eba1 + uVar4;
    uVar1 = uVar4 * 0x800 | uVar4 >> 0x15;
    uVar4 = (uVar6 ^ uVar2 ^ uVar1) + c->data[0xd] + 0x6ed9eba1 + uVar3;
    uVar5 = uVar4 * 0x8000 | uVar4 >> 0x11;
    uVar4 = (uVar2 ^ uVar1 ^ uVar5) + c->data[3] + 0x6ed9eba1 + uVar6;
    uVar4 = uVar4 * 8 | uVar4 >> 0x1d;
    uVar2 = (uVar1 ^ uVar5 ^ uVar4) + c->data[0xb] + 0x6ed9eba1 + uVar2;
    uVar3 = uVar2 * 0x200 | uVar2 >> 0x17;
    uVar1 = (uVar5 ^ uVar4 ^ uVar3) + c->data[7] + 0x6ed9eba1 + uVar1;
    uVar2 = uVar1 * 0x800 | uVar1 >> 0x15;
    uVar1 = c->data[0xf] + 0x6ed9eba1 + uVar5 + (uVar4 ^ uVar3 ^ uVar2);
    c->A = uVar4 + c->A;
    puVar7 = (undefined4 *)((uint)(c->data + 1) & 0xfffffffc);
    c->B = (uVar1 * 0x8000 | uVar1 >> 0x11) + c->B;
    uVar4 = c->D;
    uVar1 = c->C;
    len = len - __n;
    data = (void *)((int)data + __n);
    c->data[0] = 0;
    c->data[0xf] = 0;
    c->D = uVar3 + uVar4;
    c->num = 0;
    c->C = uVar2 + uVar1;
    uVar4 = (uint)((int)c + (0x58 - (int)puVar7)) >> 2;
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
    }
    uVar4 = len >> 6;
    if (uVar4 != 0) goto LAB_081acac0;
  }
  if (len == 0) {
    return 1;
  }
LAB_081aca93:
  c->num = len;
  memcpy(c->data,data,len);
  return 1;
}

