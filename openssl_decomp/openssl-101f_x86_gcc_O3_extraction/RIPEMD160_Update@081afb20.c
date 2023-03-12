
int RIPEMD160_Update(RIPEMD160_CTX *c,void *data,size_t len)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  size_t __n;
  undefined4 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  if (len == 0) {
    return 1;
  }
  uVar3 = c->Nl + len * 8;
  uVar2 = c->Nh;
  if (uVar3 < c->Nl) {
    uVar2 = uVar2 + 1;
  }
  c->Nl = uVar3;
  c->Nh = uVar2 + (len >> 0x1d);
  uVar3 = c->num;
  if (uVar3 == 0) {
    uVar3 = len >> 6;
    if (uVar3 == 0) goto LAB_081afbf1;
LAB_081afc18:
    len = len + uVar3 * -0x40;
    ripemd160_block_data_order(c,data,uVar3);
    data = (void *)((int)data + uVar3 * 0x40);
  }
  else {
    puVar1 = c->data;
    if ((len < 0x40) && (len + uVar3 < 0x40)) {
      memcpy((void *)((int)puVar1 + uVar3),data,len);
      c->num = c->num + len;
      return 1;
    }
    __n = 0x40 - uVar3;
    len = len - __n;
    memcpy((void *)(uVar3 + (int)puVar1),data,__n);
    ripemd160_block_data_order(c,puVar1,1);
    data = (void *)((int)data + __n);
    c->num = 0;
    c->data[0] = 0;
    c->data[0xf] = 0;
    puVar4 = (undefined4 *)((uint)(c->data + 1) & 0xfffffffc);
    uVar3 = (uint)((int)puVar1 + (0x40 - (int)puVar4)) >> 2;
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
    uVar3 = len >> 6;
    if (uVar3 != 0) goto LAB_081afc18;
  }
  if (len == 0) {
    return 1;
  }
LAB_081afbf1:
  c->num = len;
  memcpy(c->data,data,len);
  return 1;
}

