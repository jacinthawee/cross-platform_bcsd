
void OPENSSL_cleanse(void *ptr,size_t len)

{
  undefined *puVar1;
  int iVar3;
  uint uVar4;
  undefined *puVar2;
  
  uVar4 = (uint)cleanse_ctr;
  if (ptr != (void *)0x0) {
    puVar2 = (undefined *)ptr;
    if (len != 0) {
      do {
        puVar1 = puVar2 + 1;
        *puVar2 = (char)uVar4;
        uVar4 = uVar4 + ((uint)puVar1 & 0xf) + 0x11;
        puVar2 = puVar1;
      } while (puVar1 != (undefined *)((int)ptr + len));
    }
    iVar3 = (*(code *)PTR_memchr_006a99e4)(ptr,uVar4 & 0xff,len,(undefined *)((int)ptr + len),&_gp);
    cleanse_ctr = (byte)uVar4;
    if (iVar3 != 0) {
      cleanse_ctr = (char)iVar3 + (byte)uVar4 + 0x3f;
    }
  }
  return;
}

