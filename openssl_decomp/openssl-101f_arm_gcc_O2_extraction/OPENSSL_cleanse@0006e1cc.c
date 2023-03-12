
void OPENSSL_cleanse(void *ptr,size_t len)

{
  undefined4 *puVar1;
  uint uVar2;
  uint in_lr;
  bool bVar3;
  
  if (len < 7) {
    puVar1 = (undefined4 *)ptr;
    if (len == 0) goto LAB_0006e21c;
  }
  else {
    uVar2 = len - 4;
    for (; ((uint)ptr & 3) != 0; ptr = (void *)((int)ptr + 1)) {
      *(undefined *)ptr = 0;
      uVar2 = uVar2 - 1;
    }
    do {
      len = uVar2;
      puVar1 = (undefined4 *)((int)ptr + 4);
      *(undefined4 *)ptr = 0;
      ptr = puVar1;
      uVar2 = len - 4;
    } while (3 < len);
    if (len == 0) goto LAB_0006e21c;
  }
  do {
    *(undefined *)puVar1 = 0;
    bVar3 = len != 0;
    len = len - 1;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  } while (bVar3 && len != 0);
LAB_0006e21c:
  if ((in_lr & 1) == 0) {
    return;
  }
  return;
}

