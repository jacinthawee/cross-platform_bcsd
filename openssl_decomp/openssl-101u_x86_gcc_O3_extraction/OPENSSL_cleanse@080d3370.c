
void OPENSSL_cleanse(void *ptr,size_t len)

{
  undefined *puVar1;
  void *pvVar3;
  uint uVar4;
  undefined *puVar2;
  
  uVar4 = (uint)cleanse_ctr;
  if (ptr != (void *)0x0) {
    if (len != 0) {
      puVar2 = (undefined *)ptr;
      do {
        puVar1 = puVar2 + 1;
        *puVar2 = (char)uVar4;
        uVar4 = uVar4 + 0x11 + ((uint)puVar1 & 0xf);
        puVar2 = puVar1;
      } while (puVar1 != (undefined *)((int)ptr + len));
    }
    pvVar3 = memchr(ptr,uVar4 & 0xff,len);
    cleanse_ctr = (byte)uVar4;
    if (pvVar3 != (void *)0x0) {
      cleanse_ctr = (char)pvVar3 + '?' + (byte)uVar4;
    }
  }
  return;
}

