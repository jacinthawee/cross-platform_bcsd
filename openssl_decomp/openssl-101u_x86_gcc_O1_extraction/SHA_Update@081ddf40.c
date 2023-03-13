
int SHA_Update(SHA_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  size_t __n;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  if (len == 0) {
    return 1;
  }
  uVar2 = c->Nl + len * 8;
  uVar1 = c->Nh;
  if (uVar2 < c->Nl) {
    uVar1 = uVar1 + 1;
  }
  c->Nl = uVar2;
  c->Nh = uVar1 + (len >> 0x1d);
  uVar2 = c->num;
  if (uVar2 == 0) {
    uVar2 = len >> 6;
    if (uVar2 == 0) goto LAB_081de011;
LAB_081de038:
    len = len + uVar2 * -0x40;
    sha_block_data_order();
    data = (void *)((int)data + uVar2 * 0x40);
  }
  else {
    if ((len < 0x40) && (len + uVar2 < 0x40)) {
      memcpy((void *)((int)c->data + uVar2),data,len);
      c->num = c->num + len;
      return 1;
    }
    __n = 0x40 - uVar2;
    len = len - __n;
    memcpy((void *)((int)c->data + uVar2),data,__n);
    sha_block_data_order();
    data = (void *)((int)data + __n);
    c->num = 0;
    c->data[0] = 0;
    c->data[0xf] = 0;
    puVar3 = (undefined4 *)((uint)(c->data + 1) & 0xfffffffc);
    uVar2 = (uint)((int)c + (0x5c - (int)puVar3)) >> 2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    uVar2 = len >> 6;
    if (uVar2 != 0) goto LAB_081de038;
  }
  if (len == 0) {
    return 1;
  }
LAB_081de011:
  c->num = len;
  memcpy(c->data,data,len);
  return 1;
}

