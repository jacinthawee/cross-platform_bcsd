
int BUF_MEM_grow_clean(BUF_MEM *str,size_t len)

{
  undefined *puVar1;
  uint uVar2;
  char *pcVar3;
  size_t sVar4;
  
  uVar2 = str->length;
  if (len <= uVar2) {
    (*(code *)PTR_memset_006aab00)(str->data + len,0,uVar2 - len);
    str->length = len;
    return len;
  }
  if (str->max < len) {
    if (len < 0x5ffffffd) {
      sVar4 = (len + 3) / 3 << 2;
      if (str->data == (char *)0x0) {
        pcVar3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(sVar4,"buffer.c",0xa4);
      }
      else {
        pcVar3 = (char *)(*(code *)PTR_CRYPTO_realloc_clean_006a9a00)
                                   (str->data,str->max,sVar4,"buffer.c",0xa6);
      }
      puVar1 = PTR_memset_006aab00;
      if (pcVar3 == (char *)0x0) {
        ERR_put_error(7,0x69,0x41,"buffer.c",0xa9);
        len = 0;
      }
      else {
        str->data = pcVar3;
        str->max = sVar4;
        (*(code *)puVar1)(pcVar3 + str->length,0,len - str->length);
        str->length = len;
      }
      return len;
    }
    ERR_put_error(7,0x69,0x41,"buffer.c",0x9f);
    return 0;
  }
  (*(code *)PTR_memset_006aab00)(str->data + uVar2,0,len - uVar2);
  str->length = len;
  return len;
}

