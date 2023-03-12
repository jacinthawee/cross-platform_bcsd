
int SHA1_Final(uchar *md,SHA_CTX *c)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *ptr;
  
  ptr = c->data;
  uVar1 = c->num + 1;
  *(undefined *)((int)ptr + c->num) = 0x80;
  if (uVar1 < 0x39) {
    iVar3 = 0x38 - uVar1;
  }
  else {
    (*(code *)PTR_memset_006a99f4)((int)ptr + uVar1,0,0x40 - uVar1);
    sha1_block_data_order(c,ptr,1);
    iVar3 = 0x38;
    uVar1 = 0;
  }
  (*(code *)PTR_memset_006a99f4)((int)ptr + uVar1,0,iVar3);
  uVar2 = c->Nh;
  uVar1 = c->Nl;
  *(char *)((int)c->data + 0x3b) = (char)uVar2;
  *(char *)((int)c->data + 0x3f) = (char)uVar1;
  *(char *)(c->data + 0xe) = (char)(uVar2 >> 0x18);
  *(char *)((int)c->data + 0x39) = (char)(uVar2 >> 0x10);
  *(char *)(c->data + 0xf) = (char)(uVar1 >> 0x18);
  *(char *)((int)c->data + 0x3a) = (char)(uVar2 >> 8);
  *(char *)((int)c->data + 0x3d) = (char)(uVar1 >> 0x10);
  *(char *)((int)c->data + 0x3e) = (char)(uVar1 >> 8);
  sha1_block_data_order(c,ptr,1);
  c->num = 0;
  OPENSSL_cleanse(ptr,0x40);
  uVar1 = c->h0;
  md[3] = (uchar)uVar1;
  *md = (uchar)(uVar1 >> 0x18);
  md[1] = (uchar)(uVar1 >> 0x10);
  md[2] = (uchar)(uVar1 >> 8);
  uVar1 = c->h1;
  md[7] = (uchar)uVar1;
  md[4] = (uchar)(uVar1 >> 0x18);
  md[5] = (uchar)(uVar1 >> 0x10);
  md[6] = (uchar)(uVar1 >> 8);
  uVar1 = c->h2;
  md[0xb] = (uchar)uVar1;
  md[8] = (uchar)(uVar1 >> 0x18);
  md[9] = (uchar)(uVar1 >> 0x10);
  md[10] = (uchar)(uVar1 >> 8);
  uVar1 = c->h3;
  md[0xf] = (uchar)uVar1;
  md[0xc] = (uchar)(uVar1 >> 0x18);
  md[0xd] = (uchar)(uVar1 >> 0x10);
  md[0xe] = (uchar)(uVar1 >> 8);
  uVar1 = c->h4;
  md[0x13] = (uchar)uVar1;
  md[0x10] = (uchar)(uVar1 >> 0x18);
  md[0x11] = (uchar)(uVar1 >> 0x10);
  md[0x12] = (uchar)(uVar1 >> 8);
  return 1;
}

