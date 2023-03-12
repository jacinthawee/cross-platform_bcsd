
int BUF_MEM_grow(BUF_MEM *str,size_t len)

{
  undefined *puVar1;
  char *pcVar2;
  uint uVar3;
  size_t sVar4;
  
  uVar3 = str->length;
  if (len <= uVar3) {
    str->length = len;
    return len;
  }
  if (str->max < len) {
    if (len < 0x5ffffffd) {
      sVar4 = (len + 3) / 3 << 2;
      if (str->data == (char *)0x0) {
        pcVar2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(sVar4,"buffer.c",0x79);
      }
      else {
        pcVar2 = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(str->data,sVar4,"buffer.c",0x7b);
      }
      puVar1 = PTR_memset_006aab00;
      if (pcVar2 == (char *)0x0) {
        ERR_put_error(7,100,0x41,"buffer.c",0x7e);
        len = 0;
      }
      else {
        str->data = pcVar2;
        str->max = sVar4;
        (*(code *)puVar1)(pcVar2 + str->length,0,len - str->length);
        str->length = len;
      }
      return len;
    }
    ERR_put_error(7,100,0x41,"buffer.c",0x74);
    return 0;
  }
  (*(code *)PTR_memset_006aab00)(str->data + uVar3,0,len - uVar3);
  str->length = len;
  return len;
}
