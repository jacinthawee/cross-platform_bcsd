
int SHA512_Update(SHA512_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  _union_314 *__dest;
  int iVar5;
  bool bVar6;
  
  if (len != 0) {
    uVar1 = *(uint *)&c->Nl;
    uVar2 = *(uint *)((int)&c->Nl + 4);
    uVar3 = len * 8 + uVar1;
    uVar4 = (len >> 0x1d) + uVar2 + (uint)CARRY4(len * 8,uVar1);
    bVar6 = uVar2 <= uVar4;
    if (uVar4 == uVar2) {
      bVar6 = uVar1 <= uVar3;
    }
    if (!bVar6) {
      uVar1 = *(uint *)&c->Nh;
      iVar5 = *(int *)((int)&c->Nh + 4);
      *(uint *)&c->Nh = uVar1 + 1;
      *(uint *)((int)&c->Nh + 4) = iVar5 + (uint)(0xfffffffe < uVar1);
    }
    uVar1 = c->num;
    __dest = &c->u;
    *(uint *)&c->Nl = uVar3;
    *(uint *)((int)&c->Nl + 4) = uVar4;
    if (uVar1 != 0) {
      uVar2 = 0x80 - uVar1;
      if (len < uVar2) {
        memcpy((void *)(uVar1 + (int)__dest),data,len);
        c->num = c->num + len;
        return 1;
      }
      len = len - uVar2;
      memcpy((void *)(uVar1 + (int)__dest),data,uVar2);
      c->num = 0;
      data = (void *)((int)data + uVar2);
      sha512_block_data_order(c,__dest,1);
    }
    if (0x7f < len) {
      sha512_block_data_order(c,data,len >> 7);
      data = (void *)((int)data + (len - (len & 0x7f)));
      len = len & 0x7f;
    }
    if (len != 0) {
      memcpy(__dest,data,len);
      c->num = len;
      return 1;
    }
  }
  return 1;
}

