
int SHA384_Final(uchar *md,SHA512_CTX *c)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte bVar7;
  
  bVar7 = 0;
  uVar5 = c->num;
  *(undefined *)((int)c->h + uVar5 + 0x50) = 0x80;
  uVar4 = uVar5 + 1;
  if (uVar4 < 0x71) {
    uVar5 = 0x70 - uVar4;
  }
  else {
    memset((void *)((int)c->h + uVar5 + 0x51),0,0x80 - uVar4);
    sha512_block_data_order_constprop_1();
    uVar5 = 0x70;
    uVar4 = 0;
  }
  puVar6 = (undefined4 *)((int)c->h + uVar4 + 0x50);
  if (uVar5 < 4) {
    if ((uVar5 != 0) && (*(undefined *)puVar6 = 0, (uVar5 & 2) != 0)) {
      *(undefined2 *)((int)puVar6 + (uVar5 - 2)) = 0;
    }
  }
  else {
    *puVar6 = 0;
    *(undefined4 *)((int)puVar6 + (uVar5 - 4)) = 0;
    uVar5 = (uint)((int)puVar6 + (uVar5 - (int)(undefined4 *)((uint)(puVar6 + 1) & 0xfffffffc))) >>
            2;
    puVar6 = (undefined4 *)((uint)(puVar6 + 1) & 0xfffffffc);
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
    }
  }
  uVar1 = *(undefined4 *)&c->Nl;
  uVar2 = *(undefined4 *)((int)&c->Nl + 4);
  (c->u).p[0x7f] = (uchar)uVar1;
  (c->u).p[0x7b] = (uchar)uVar2;
  (c->u).p[0x7e] = (uchar)((uint)uVar1 >> 8);
  (c->u).p[0x7d] = (uchar)((uint)uVar1 >> 0x10);
  uVar3 = *(undefined4 *)&c->Nh;
  (c->u).p[0x7c] = (uchar)((uint)uVar1 >> 0x18);
  (c->u).p[0x7a] = (uchar)((uint)uVar2 >> 8);
  (c->u).p[0x79] = (uchar)((uint)uVar2 >> 0x10);
  uVar1 = *(undefined4 *)((int)&c->Nh + 4);
  (c->u).p[0x78] = (uchar)((uint)uVar2 >> 0x18);
  (c->u).p[0x77] = (uchar)uVar3;
  (c->u).p[0x73] = (uchar)uVar1;
  (c->u).p[0x76] = (uchar)((uint)uVar3 >> 8);
  (c->u).p[0x75] = (uchar)((uint)uVar3 >> 0x10);
  (c->u).p[0x74] = (uchar)((uint)uVar3 >> 0x18);
  (c->u).p[0x72] = (uchar)((uint)uVar1 >> 8);
  (c->u).p[0x71] = (uchar)((uint)uVar1 >> 0x10);
  (c->u).p[0x70] = (uchar)((uint)uVar1 >> 0x18);
  sha512_block_data_order_constprop_1();
  if (md != (uchar *)0x0) {
    if (c->md_len == 0x30) {
      uVar1 = *(undefined4 *)((int)c->h + 4);
      uVar2 = *(undefined4 *)c->h;
      *md = (uchar)((uint)uVar1 >> 0x18);
      md[1] = (uchar)((uint)uVar1 >> 0x10);
      md[2] = (uchar)((uint)uVar1 >> 8);
      md[3] = (uchar)uVar1;
      md[4] = (uchar)((uint)uVar2 >> 0x18);
      md[5] = (uchar)((uint)uVar2 >> 0x10);
      md[6] = (uchar)((uint)uVar2 >> 8);
      md[7] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0xc);
      uVar2 = *(undefined4 *)(c->h + 1);
      md[8] = (uchar)((uint)uVar1 >> 0x18);
      md[9] = (uchar)((uint)uVar1 >> 0x10);
      md[10] = (uchar)((uint)uVar1 >> 8);
      md[0xb] = (uchar)uVar1;
      md[0xc] = (uchar)((uint)uVar2 >> 0x18);
      md[0xd] = (uchar)((uint)uVar2 >> 0x10);
      md[0xe] = (uchar)((uint)uVar2 >> 8);
      md[0xf] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x14);
      uVar2 = *(undefined4 *)(c->h + 2);
      md[0x10] = (uchar)((uint)uVar1 >> 0x18);
      md[0x11] = (uchar)((uint)uVar1 >> 0x10);
      md[0x12] = (uchar)((uint)uVar1 >> 8);
      md[0x13] = (uchar)uVar1;
      md[0x14] = (uchar)((uint)uVar2 >> 0x18);
      md[0x15] = (uchar)((uint)uVar2 >> 0x10);
      md[0x16] = (uchar)((uint)uVar2 >> 8);
      md[0x17] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x1c);
      uVar2 = *(undefined4 *)(c->h + 3);
      md[0x18] = (uchar)((uint)uVar1 >> 0x18);
      md[0x19] = (uchar)((uint)uVar1 >> 0x10);
      md[0x1a] = (uchar)((uint)uVar1 >> 8);
      md[0x1b] = (uchar)uVar1;
      md[0x1c] = (uchar)((uint)uVar2 >> 0x18);
      md[0x1d] = (uchar)((uint)uVar2 >> 0x10);
      md[0x1e] = (uchar)((uint)uVar2 >> 8);
      md[0x1f] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x24);
      uVar2 = *(undefined4 *)(c->h + 4);
      md[0x20] = (uchar)((uint)uVar1 >> 0x18);
      md[0x21] = (uchar)((uint)uVar1 >> 0x10);
      md[0x22] = (uchar)((uint)uVar1 >> 8);
      md[0x23] = (uchar)uVar1;
      md[0x24] = (uchar)((uint)uVar2 >> 0x18);
      md[0x25] = (uchar)((uint)uVar2 >> 0x10);
      md[0x26] = (uchar)((uint)uVar2 >> 8);
      md[0x27] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x2c);
      uVar2 = *(undefined4 *)(c->h + 5);
      md[0x2b] = (uchar)uVar1;
      md[0x2f] = (uchar)uVar2;
      md[0x28] = (uchar)((uint)uVar1 >> 0x18);
      md[0x29] = (uchar)((uint)uVar1 >> 0x10);
      md[0x2a] = (uchar)((uint)uVar1 >> 8);
      md[0x2c] = (uchar)((uint)uVar2 >> 0x18);
      md[0x2d] = (uchar)((uint)uVar2 >> 0x10);
      md[0x2e] = (uchar)((uint)uVar2 >> 8);
    }
    else {
      if (c->md_len != 0x40) {
        return 0;
      }
      uVar1 = *(undefined4 *)((int)c->h + 4);
      uVar2 = *(undefined4 *)c->h;
      *md = (uchar)((uint)uVar1 >> 0x18);
      md[1] = (uchar)((uint)uVar1 >> 0x10);
      md[2] = (uchar)((uint)uVar1 >> 8);
      md[3] = (uchar)uVar1;
      md[4] = (uchar)((uint)uVar2 >> 0x18);
      md[5] = (uchar)((uint)uVar2 >> 0x10);
      md[6] = (uchar)((uint)uVar2 >> 8);
      md[7] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0xc);
      uVar2 = *(undefined4 *)(c->h + 1);
      md[8] = (uchar)((uint)uVar1 >> 0x18);
      md[9] = (uchar)((uint)uVar1 >> 0x10);
      md[10] = (uchar)((uint)uVar1 >> 8);
      md[0xb] = (uchar)uVar1;
      md[0xc] = (uchar)((uint)uVar2 >> 0x18);
      md[0xd] = (uchar)((uint)uVar2 >> 0x10);
      md[0xe] = (uchar)((uint)uVar2 >> 8);
      md[0xf] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x14);
      uVar2 = *(undefined4 *)(c->h + 2);
      md[0x10] = (uchar)((uint)uVar1 >> 0x18);
      md[0x11] = (uchar)((uint)uVar1 >> 0x10);
      md[0x12] = (uchar)((uint)uVar1 >> 8);
      md[0x13] = (uchar)uVar1;
      md[0x14] = (uchar)((uint)uVar2 >> 0x18);
      md[0x15] = (uchar)((uint)uVar2 >> 0x10);
      md[0x16] = (uchar)((uint)uVar2 >> 8);
      md[0x17] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x1c);
      uVar2 = *(undefined4 *)(c->h + 3);
      md[0x18] = (uchar)((uint)uVar1 >> 0x18);
      md[0x19] = (uchar)((uint)uVar1 >> 0x10);
      md[0x1a] = (uchar)((uint)uVar1 >> 8);
      md[0x1b] = (uchar)uVar1;
      md[0x1c] = (uchar)((uint)uVar2 >> 0x18);
      md[0x1d] = (uchar)((uint)uVar2 >> 0x10);
      md[0x1e] = (uchar)((uint)uVar2 >> 8);
      md[0x1f] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x24);
      uVar2 = *(undefined4 *)(c->h + 4);
      md[0x20] = (uchar)((uint)uVar1 >> 0x18);
      md[0x21] = (uchar)((uint)uVar1 >> 0x10);
      md[0x22] = (uchar)((uint)uVar1 >> 8);
      md[0x23] = (uchar)uVar1;
      md[0x24] = (uchar)((uint)uVar2 >> 0x18);
      md[0x25] = (uchar)((uint)uVar2 >> 0x10);
      md[0x26] = (uchar)((uint)uVar2 >> 8);
      md[0x27] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x2c);
      uVar2 = *(undefined4 *)(c->h + 5);
      md[0x28] = (uchar)((uint)uVar1 >> 0x18);
      md[0x29] = (uchar)((uint)uVar1 >> 0x10);
      md[0x2a] = (uchar)((uint)uVar1 >> 8);
      md[0x2b] = (uchar)uVar1;
      md[0x2c] = (uchar)((uint)uVar2 >> 0x18);
      md[0x2d] = (uchar)((uint)uVar2 >> 0x10);
      md[0x2e] = (uchar)((uint)uVar2 >> 8);
      md[0x2f] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x34);
      uVar2 = *(undefined4 *)(c->h + 6);
      md[0x30] = (uchar)((uint)uVar1 >> 0x18);
      md[0x31] = (uchar)((uint)uVar1 >> 0x10);
      md[0x32] = (uchar)((uint)uVar1 >> 8);
      md[0x33] = (uchar)uVar1;
      md[0x34] = (uchar)((uint)uVar2 >> 0x18);
      md[0x35] = (uchar)((uint)uVar2 >> 0x10);
      md[0x36] = (uchar)((uint)uVar2 >> 8);
      md[0x37] = (uchar)uVar2;
      uVar1 = *(undefined4 *)((int)c->h + 0x3c);
      uVar2 = *(undefined4 *)(c->h + 7);
      md[0x3b] = (uchar)uVar1;
      md[0x3f] = (uchar)uVar2;
      md[0x38] = (uchar)((uint)uVar1 >> 0x18);
      md[0x39] = (uchar)((uint)uVar1 >> 0x10);
      md[0x3a] = (uchar)((uint)uVar1 >> 8);
      md[0x3c] = (uchar)((uint)uVar2 >> 0x18);
      md[0x3d] = (uchar)((uint)uVar2 >> 0x10);
      md[0x3e] = (uchar)((uint)uVar2 >> 8);
    }
    return 1;
  }
  return 0;
}

