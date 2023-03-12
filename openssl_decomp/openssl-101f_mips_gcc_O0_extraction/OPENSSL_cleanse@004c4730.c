
void OPENSSL_cleanse(void *ptr,size_t len)

{
  undefined *puVar1;
  int iVar3;
  uint uVar4;
  char cVar5;
  undefined *puVar2;
  
  uVar4 = (uint)cleanse_ctr;
  if (len != 0) {
    puVar2 = (undefined *)ptr;
    do {
      puVar1 = puVar2 + 1;
      *puVar2 = (char)uVar4;
      uVar4 = uVar4 + ((uint)puVar1 & 0xf) + 0x11;
      puVar2 = puVar1;
    } while (puVar1 != (undefined *)((int)ptr + len));
  }
  cVar5 = (char)uVar4;
  iVar3 = (*(code *)PTR_memchr_006aaaf0)(ptr,uVar4 & 0xff,len);
  if (iVar3 != 0) {
    cVar5 = (char)iVar3 + cVar5 + '?';
  }
  cleanse_ctr = cVar5;
  return;
}

