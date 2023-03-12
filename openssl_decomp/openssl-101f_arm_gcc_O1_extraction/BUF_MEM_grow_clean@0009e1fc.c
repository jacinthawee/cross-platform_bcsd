
int BUF_MEM_grow_clean(BUF_MEM *str,size_t len)

{
  char *pcVar1;
  uint uVar2;
  size_t num;
  
  uVar2 = str->length;
  if (len <= uVar2) {
    memset(str->data + len,0,uVar2 - len);
    str->length = len;
    return len;
  }
  if (str->max < len) {
    if (len < 0x5ffffffd) {
      num = (len + 3) / 3 << 2;
      if (str->data == (char *)0x0) {
        pcVar1 = (char *)CRYPTO_malloc(num,"buffer.c",0xa4);
      }
      else {
        pcVar1 = (char *)CRYPTO_realloc_clean(str->data,str->max,num,"buffer.c",0xa6);
      }
      if (pcVar1 == (char *)0x0) {
        ERR_put_error(7,0x69,0x41,"buffer.c",0xa9);
      }
      else {
        str->data = pcVar1;
        str->max = num;
        memset(pcVar1 + str->length,0,len - str->length);
        str->length = len;
        pcVar1 = (char *)len;
      }
      return (int)pcVar1;
    }
    ERR_put_error(7,0x69,0x41,"buffer.c",0x9f);
    return 0;
  }
  memset(str->data + uVar2,0,len - uVar2);
  str->length = len;
  return len;
}

