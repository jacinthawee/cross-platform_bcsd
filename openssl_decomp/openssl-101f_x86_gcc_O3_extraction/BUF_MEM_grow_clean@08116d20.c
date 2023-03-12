
int BUF_MEM_grow_clean(BUF_MEM *str,size_t len)

{
  uint uVar1;
  char *pcVar2;
  size_t sVar3;
  int line;
  
  uVar1 = str->length;
  if (len <= uVar1) {
    sVar3 = uVar1 - len;
    pcVar2 = str->data + len;
LAB_08116d96:
    memset(pcVar2,0,sVar3);
    str->length = len;
    return len;
  }
  if (len <= str->max) {
    memset(str->data + uVar1,0,len - uVar1);
    str->length = len;
    return len;
  }
  if (len < 0x5ffffffd) {
    sVar3 = ((len + 3) / 3) * 4;
    if (str->data == (char *)0x0) {
      pcVar2 = (char *)CRYPTO_malloc(sVar3,"buffer.c",0xa4);
    }
    else {
      pcVar2 = (char *)CRYPTO_realloc_clean(str->data,str->max,sVar3,"buffer.c",0xa6);
    }
    if (pcVar2 != (char *)0x0) {
      str->data = pcVar2;
      str->max = sVar3;
      sVar3 = len - str->length;
      pcVar2 = pcVar2 + str->length;
      goto LAB_08116d96;
    }
    line = 0xa9;
  }
  else {
    line = 0x9f;
  }
  ERR_put_error(7,0x69,0x41,"buffer.c",line);
  return 0;
}

