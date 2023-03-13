
void * next_protos_parse(short *param_1,char *param_2)

{
  char *pcVar1;
  uint uVar2;
  size_t sVar3;
  void *ptr;
  uint uVar4;
  size_t sVar5;
  uint uVar6;
  
  sVar3 = strlen(param_2);
  if ((0xfffe < sVar3) || (ptr = CRYPTO_malloc(sVar3 + 1,"apps.c",0xa39), ptr == (void *)0x0)) {
    return (void *)0x0;
  }
  uVar2 = 1;
  sVar5 = 0;
  uVar6 = 0;
  do {
    while ((uVar4 = uVar2, sVar5 != sVar3 && (pcVar1 = param_2 + sVar5, *pcVar1 != ','))) {
      sVar5 = sVar5 + 1;
      *(char *)((int)ptr + uVar4) = *pcVar1;
      uVar2 = uVar4 + 1;
      if (sVar3 < uVar4) goto LAB_0807de07;
    }
    if (0xff < sVar5 - uVar6) {
      CRYPTO_free(ptr);
      return (void *)0x0;
    }
    *(char *)((int)ptr + uVar6) = (char)sVar5 - (char)uVar6;
    uVar2 = uVar4 + 1;
    sVar5 = sVar5 + 1;
    uVar6 = uVar4;
  } while (uVar4 <= sVar3);
LAB_0807de07:
  *param_1 = (short)sVar3 + 1;
  return ptr;
}

