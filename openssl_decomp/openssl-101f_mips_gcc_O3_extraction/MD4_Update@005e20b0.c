
int MD4_Update(MD4_CTX *c,void *data,size_t len)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  if (len == 0) {
    return 1;
  }
  uVar2 = len * 8 + c->Nl;
  if (uVar2 < c->Nl) {
    uVar3 = c->num;
    c->Nl = uVar2;
    c->Nh = (len >> 0x1d) + c->Nh + 1;
    if (uVar3 != 0) goto LAB_005e211c;
LAB_005e21e4:
    uVar2 = len >> 6;
    if (uVar2 == 0) goto LAB_005e21f0;
LAB_005e2234:
    md4_block_data_order(c,data,uVar2);
    data = (void *)((int)data + uVar2 * 0x40);
    len = len + uVar2 * -0x40;
  }
  else {
    uVar3 = c->num;
    c->Nl = uVar2;
    c->Nh = (len >> 0x1d) + c->Nh;
    if (uVar3 == 0) goto LAB_005e21e4;
LAB_005e211c:
    puVar5 = c->data;
    if ((len < 0x40) && (len + uVar3 < 0x40)) {
      (*(code *)PTR_memcpy_006aabf4)((int)puVar5 + uVar3,data,len);
      c->num = c->num + len;
      return 1;
    }
    iVar4 = 0x40 - uVar3;
    (*(code *)PTR_memcpy_006aabf4)((int)puVar5 + uVar3,data,iVar4);
    md4_block_data_order(c,puVar5,1);
    len = len - iVar4;
    c->num = 0;
    uVar2 = len >> 6;
    data = (void *)((int)data + iVar4);
    (*(code *)PTR_memset_006aab00)(puVar5,0,0x40);
    if (uVar2 != 0) goto LAB_005e2234;
  }
  if (len == 0) {
    return 1;
  }
LAB_005e21f0:
  puVar1 = PTR_memcpy_006aabf4;
  c->num = len;
  (*(code *)puVar1)(c->data,data,len);
  return 1;
}

