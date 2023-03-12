
int SHA1_Final(uchar *md,SHA_CTX *c)

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
    sha1_block_data_order(c,puVar5,1);
    iVar4 = 0x38;
    uVar2 = 0;
  }
  (*(code *)PTR_memset_006aab00)((int)puVar5 + uVar2,0,iVar4);
  uVar3 = c->Nh;
  uVar2 = c->Nl;
  *(char *)((int)c->data + 0x3b) = (char)uVar3;
  *(char *)((int)c->data + 0x3f) = (char)uVar2;
  *(char *)(c->data + 0xe) = (char)(uVar3 >> 0x18);
  *(char *)((int)c->data + 0x39) = (char)(uVar3 >> 0x10);
  *(char *)(c->data + 0xf) = (char)(uVar2 >> 0x18);
  *(char *)((int)c->data + 0x3a) = (char)(uVar3 >> 8);
  *(char *)((int)c->data + 0x3d) = (char)(uVar2 >> 0x10);
  *(char *)((int)c->data + 0x3e) = (char)(uVar2 >> 8);
  sha1_block_data_order(c,puVar5,1);
  puVar1 = PTR_memset_006aab00;
  c->num = 0;
  (*(code *)puVar1)(puVar5,0,0x40);
  uVar2 = c->h0;
  md[3] = (uchar)uVar2;
  *md = (uchar)(uVar2 >> 0x18);
  md[1] = (uchar)(uVar2 >> 0x10);
  md[2] = (uchar)(uVar2 >> 8);
  uVar2 = c->h1;
  md[7] = (uchar)uVar2;
  md[4] = (uchar)(uVar2 >> 0x18);
  md[5] = (uchar)(uVar2 >> 0x10);
  md[6] = (uchar)(uVar2 >> 8);
  uVar2 = c->h2;
  md[0xb] = (uchar)uVar2;
  md[8] = (uchar)(uVar2 >> 0x18);
  md[9] = (uchar)(uVar2 >> 0x10);
  md[10] = (uchar)(uVar2 >> 8);
  uVar2 = c->h3;
  md[0xf] = (uchar)uVar2;
  md[0xc] = (uchar)(uVar2 >> 0x18);
  md[0xd] = (uchar)(uVar2 >> 0x10);
  md[0xe] = (uchar)(uVar2 >> 8);
  uVar2 = c->h4;
  md[0x13] = (uchar)uVar2;
  md[0x10] = (uchar)(uVar2 >> 0x18);
  md[0x11] = (uchar)(uVar2 >> 0x10);
  md[0x12] = (uchar)(uVar2 >> 8);
  return 1;
}

