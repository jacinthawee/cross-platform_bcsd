
int RIPEMD160_Final(uchar *md,RIPEMD160_CTX *c)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = c->data;
  uVar2 = c->num + 1;
  *(undefined *)((int)puVar5 + c->num) = 0x80;
  if (uVar2 < 0x39) {
    iVar4 = 0x38 - uVar2;
  }
  else {
    (*(code *)PTR_memset_006aab00)((int)puVar5 + uVar2,0,0x40 - uVar2);
    ripemd160_block_data_order(c,puVar5,1);
    iVar4 = 0x38;
    uVar2 = 0;
  }
  (*(code *)PTR_memset_006aab00)((int)puVar5 + uVar2,0,iVar4);
  uVar3 = c->Nl;
  uVar2 = c->Nh;
  *(char *)(c->data + 0xe) = (char)uVar3;
  *(char *)(c->data + 0xf) = (char)uVar2;
  *(char *)((int)c->data + 0x39) = (char)(uVar3 >> 8);
  *(char *)((int)c->data + 0x3a) = (char)(uVar3 >> 0x10);
  *(char *)((int)c->data + 0x3d) = (char)(uVar2 >> 8);
  *(char *)((int)c->data + 0x3b) = (char)(uVar3 >> 0x18);
  *(char *)((int)c->data + 0x3e) = (char)(uVar2 >> 0x10);
  *(char *)((int)c->data + 0x3f) = (char)(uVar2 >> 0x18);
  ripemd160_block_data_order(c,puVar5,1);
  puVar1 = PTR_memset_006aab00;
  c->num = 0;
  (*(code *)puVar1)(puVar5,0,0x40);
  uVar2 = c->A;
  *md = (uchar)uVar2;
  md[1] = (uchar)(uVar2 >> 8);
  md[2] = (uchar)(uVar2 >> 0x10);
  md[3] = (uchar)(uVar2 >> 0x18);
  uVar2 = c->B;
  md[4] = (uchar)uVar2;
  md[5] = (uchar)(uVar2 >> 8);
  md[6] = (uchar)(uVar2 >> 0x10);
  md[7] = (uchar)(uVar2 >> 0x18);
  uVar2 = c->C;
  md[8] = (uchar)uVar2;
  md[9] = (uchar)(uVar2 >> 8);
  md[10] = (uchar)(uVar2 >> 0x10);
  md[0xb] = (uchar)(uVar2 >> 0x18);
  uVar2 = c->D;
  md[0xc] = (uchar)uVar2;
  md[0xd] = (uchar)(uVar2 >> 8);
  md[0xe] = (uchar)(uVar2 >> 0x10);
  md[0xf] = (uchar)(uVar2 >> 0x18);
  uVar2 = c->E;
  md[0x10] = (uchar)uVar2;
  md[0x11] = (uchar)(uVar2 >> 8);
  md[0x12] = (uchar)(uVar2 >> 0x10);
  md[0x13] = (uchar)(uVar2 >> 0x18);
  return 1;
}

