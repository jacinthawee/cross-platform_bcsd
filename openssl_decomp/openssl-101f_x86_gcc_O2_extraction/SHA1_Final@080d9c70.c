
int SHA1_Final(uchar *md,SHA_CTX *c)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  uVar2 = c->num;
  *(undefined *)((int)c->data + uVar2) = 0x80;
  uVar1 = uVar2 + 1;
  if (uVar1 < 0x39) {
    uVar2 = 0x38 - uVar1;
  }
  else {
    memset((void *)((int)c->data + uVar2 + 1),0,0x40 - uVar1);
    sha1_block_data_order();
    uVar2 = 0x38;
    uVar1 = 0;
  }
  puVar3 = (undefined4 *)((int)c->data + uVar1);
  if (uVar2 < 4) {
    if ((uVar2 != 0) && (*(undefined *)puVar3 = 0, (uVar2 & 2) != 0)) {
      *(undefined2 *)((int)puVar3 + (uVar2 - 2)) = 0;
    }
  }
  else {
    *puVar3 = 0;
    *(undefined4 *)((int)puVar3 + (uVar2 - 4)) = 0;
    uVar2 = (uint)((int)puVar3 + (uVar2 - ((uint)(puVar3 + 1) & 0xfffffffc))) & 0xfffffffc;
    if (3 < uVar2) {
      uVar1 = 0;
      do {
        *(undefined4 *)(((uint)(puVar3 + 1) & 0xfffffffc) + uVar1) = 0;
        uVar1 = uVar1 + 4;
      } while (uVar1 < uVar2);
    }
  }
  uVar2 = c->Nh;
  c->data[0xe] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  puVar3 = (undefined4 *)((uint)(c->data + 1) & 0xfffffffc);
  uVar2 = c->Nl;
  c->data[0xf] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  sha1_block_data_order();
  c->num = 0;
  c->data[0] = 0;
  c->data[0xf] = 0;
  uVar2 = (uint)((int)c + (0x5c - (int)puVar3)) >> 2;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  uVar2 = c->h0;
  *(uint *)md = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = c->h1;
  *(uint *)(md + 4) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = c->h2;
  *(uint *)(md + 8) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = c->h3;
  *(uint *)(md + 0xc) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = c->h4;
  *(uint *)(md + 0x10) =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  return 1;
}

