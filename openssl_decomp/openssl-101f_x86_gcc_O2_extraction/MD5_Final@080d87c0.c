
int MD5_Final(uchar *md,MD5_CTX *c)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  byte bVar5;
  
  bVar5 = 0;
  uVar2 = c->num;
  puVar1 = c->data;
  *(undefined *)((int)c->data + uVar2) = 0x80;
  uVar2 = uVar2 + 1;
  if (uVar2 < 0x39) {
    uVar4 = 0x38 - uVar2;
  }
  else {
    memset((void *)(uVar2 + (int)puVar1),0,0x40 - uVar2);
    md5_block_data_order(c,puVar1,1);
    uVar4 = 0x38;
    uVar2 = 0;
  }
  puVar3 = (undefined4 *)(uVar2 + (int)puVar1);
  if (uVar4 < 4) {
    if ((uVar4 != 0) && (*(undefined *)puVar3 = 0, (uVar4 & 2) != 0)) {
      *(undefined2 *)((int)puVar3 + (uVar4 - 2)) = 0;
    }
  }
  else {
    *puVar3 = 0;
    *(undefined4 *)((int)puVar3 + (uVar4 - 4)) = 0;
    uVar2 = (uint)((int)puVar3 + (uVar4 - ((uint)(puVar3 + 1) & 0xfffffffc))) & 0xfffffffc;
    if (3 < uVar2) {
      uVar4 = 0;
      do {
        *(undefined4 *)(((uint)(puVar3 + 1) & 0xfffffffc) + uVar4) = 0;
        uVar4 = uVar4 + 4;
      } while (uVar4 < uVar2);
    }
  }
  puVar3 = (undefined4 *)((uint)(c->data + 1) & 0xfffffffc);
  c->data[0xe] = c->Nl;
  c->data[0xf] = c->Nh;
  md5_block_data_order(c,puVar1,1);
  c->num = 0;
  c->data[0] = 0;
  c->data[0xf] = 0;
  uVar2 = (uint)((int)puVar1 + (0x40 - (int)puVar3)) >> 2;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
  }
  *(uint *)md = c->A;
  *(uint *)(md + 4) = c->B;
  *(uint *)(md + 8) = c->C;
  *(uint *)(md + 0xc) = c->D;
  return 1;
}

