
int SHA224_Update(SHA256_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  void *__src;
  uint *__s;
  size_t __n;
  
  if (len != 0) {
    uVar4 = c->Nl;
    uVar2 = c->Nh;
    uVar3 = uVar4 + len * 8;
    uVar1 = c->num;
    c->Nl = uVar3;
    if (uVar3 < uVar4) {
      uVar2 = uVar2 + 1;
    }
    c->Nh = uVar2 + (len >> 0x1d);
    __src = data;
    if (uVar1 != 0) {
      __s = c->data;
      if ((len < 0x40) && (len + uVar1 < 0x40)) {
        memcpy((void *)(uVar1 + (int)__s),data,len);
        c->num = c->num + len;
        return 1;
      }
      __n = 0x40 - uVar1;
      len = len - __n;
      __src = (void *)((int)data + __n);
      memcpy((void *)(uVar1 + (int)__s),data,__n);
      sha256_block_data_order(c,__s,1);
      c->num = 0;
      memset(__s,0,0x40);
    }
    uVar1 = len >> 6;
    if (uVar1 != 0) {
      uVar2 = len & 0xffffffc0;
      len = len - uVar2;
      sha256_block_data_order(c,__src,uVar1);
      __src = (void *)((int)__src + uVar2);
    }
    if (len != 0) {
      c->num = len;
      memcpy(c->data,__src,len);
      return 1;
    }
  }
  return 1;
}

