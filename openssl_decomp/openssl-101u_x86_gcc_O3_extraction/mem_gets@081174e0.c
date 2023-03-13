
size_t mem_gets(BIO *param_1,undefined *param_2,int param_3)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint __n;
  
  puVar2 = (uint *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  __n = *puVar2;
  if (param_3 <= (int)__n) {
    __n = param_3 - 1;
  }
  if ((int)__n < 1) {
    *param_2 = 0;
    return 0;
  }
  uVar3 = 0;
  do {
    if (*(char *)(puVar2[1] + uVar3) == '\n') {
      __n = uVar3 + 1;
      break;
    }
    uVar3 = uVar3 + 1;
  } while (__n != uVar3);
  puVar2 = (uint *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  uVar3 = *puVar2;
  if (uVar3 < __n) {
    __n = uVar3;
  }
  if ((param_2 == (undefined *)0x0) || ((int)__n < 1)) {
    if (uVar3 == 0) {
      __n = param_1->num;
      if (__n == 0) {
        return 0;
      }
      BIO_set_flags(param_1,9);
    }
    if ((int)__n < 1) {
      return __n;
    }
  }
  else {
    memcpy(param_2,(void *)puVar2[1],__n);
    uVar3 = *puVar2;
    bVar1 = *(byte *)((int)&param_1->flags + 1);
    *puVar2 = uVar3 - __n;
    if ((bVar1 & 2) == 0) {
      memmove((void *)puVar2[1],(void *)((int)(void *)puVar2[1] + __n),uVar3 - __n);
    }
    else {
      puVar2[1] = puVar2[1] + __n;
    }
  }
  param_2[__n] = 0;
  return __n;
}

