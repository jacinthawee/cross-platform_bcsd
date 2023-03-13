
int RIPEMD160_Final(uchar *md,RIPEMD160_CTX *c)

{
  uint *ptr;
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar1 = c->num;
  ptr = c->data;
  *(undefined *)((int)c->data + uVar1) = 0x80;
  uVar1 = uVar1 + 1;
  if (uVar1 < 0x39) {
    uVar3 = 0x38 - uVar1;
  }
  else {
    memset((void *)(uVar1 + (int)ptr),0,0x40 - uVar1);
    ripemd160_block_data_order(c,ptr,1);
    uVar3 = 0x38;
    uVar1 = 0;
  }
  puVar2 = (undefined4 *)(uVar1 + (int)ptr);
  if (uVar3 < 4) {
    if ((uVar3 != 0) && (*(undefined *)puVar2 = 0, (uVar3 & 2) != 0)) {
      *(undefined2 *)((int)puVar2 + (uVar3 - 2)) = 0;
    }
  }
  else {
    *puVar2 = 0;
    *(undefined4 *)((int)puVar2 + (uVar3 - 4)) = 0;
    uVar1 = (uint)((int)puVar2 + (uVar3 - ((uint)(puVar2 + 1) & 0xfffffffc))) & 0xfffffffc;
    if (3 < uVar1) {
      uVar3 = 0;
      do {
        *(undefined4 *)(((uint)(puVar2 + 1) & 0xfffffffc) + uVar3) = 0;
        uVar3 = uVar3 + 4;
      } while (uVar3 < uVar1);
    }
  }
  c->data[0xe] = c->Nl;
  c->data[0xf] = c->Nh;
  ripemd160_block_data_order(c,ptr,1);
  c->num = 0;
  OPENSSL_cleanse(ptr,0x40);
  *(uint *)md = c->A;
  *(uint *)(md + 4) = c->B;
  *(uint *)(md + 8) = c->C;
  *(uint *)(md + 0xc) = c->D;
  *(uint *)(md + 0x10) = c->E;
  return 1;
}

