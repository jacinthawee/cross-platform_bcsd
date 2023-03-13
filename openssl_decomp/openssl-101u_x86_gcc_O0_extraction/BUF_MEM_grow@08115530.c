
int BUF_MEM_grow(BUF_MEM *str,size_t len)

{
  size_t num;
  uint uVar1;
  char *pcVar2;
  int line;
  
  uVar1 = str->length;
  if (len <= uVar1) {
    str->length = len;
    return len;
  }
  if (str->max <= len && len != str->max) {
    if (len < 0x5ffffffd) {
      num = ((len + 3) / 3) * 4;
      if (str->data == (char *)0x0) {
        pcVar2 = (char *)CRYPTO_malloc(num,"buffer.c",0x76);
      }
      else {
        pcVar2 = (char *)CRYPTO_realloc(str->data,num,"buffer.c",0x78);
      }
      if (pcVar2 != (char *)0x0) {
        str->max = num;
        str->data = pcVar2;
        memset(pcVar2 + str->length,0,len - str->length);
        str->length = len;
        return len;
      }
      line = 0x7a;
    }
    else {
      line = 0x71;
    }
    ERR_put_error(7,100,0x41,"buffer.c",line);
    return 0;
  }
  memset(str->data + uVar1,0,len - uVar1);
  str->length = len;
  return len;
}

