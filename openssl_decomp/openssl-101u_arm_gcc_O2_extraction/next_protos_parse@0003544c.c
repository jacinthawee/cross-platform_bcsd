
void * next_protos_parse(undefined2 *param_1,char *param_2)

{
  bool bVar1;
  size_t sVar2;
  void *ptr;
  uint uVar3;
  uint uVar4;
  size_t sVar5;
  
  sVar2 = strlen(param_2);
  if (sVar2 < 0xffff) {
    ptr = CRYPTO_malloc(sVar2 + 1,"apps.c",0xa39);
    if (ptr != (void *)0x0) {
      sVar5 = 0;
      uVar4 = 1;
      uVar3 = 0;
      do {
        if (sVar2 == sVar5) {
LAB_000354a2:
          if (0xff < sVar5 - uVar3) {
            CRYPTO_free(ptr);
            return (void *)0x0;
          }
          *(char *)((int)ptr + uVar3) = (char)(sVar5 - uVar3);
          uVar3 = uVar4;
        }
        else {
          if (param_2[sVar5] == ',') goto LAB_000354a2;
          *(char *)((int)ptr + uVar4) = param_2[sVar5];
        }
        sVar5 = sVar5 + 1;
        bVar1 = sVar2 < uVar4;
        uVar4 = uVar4 + 1;
        if (bVar1) {
          *param_1 = (short)(sVar2 + 1);
          return ptr;
        }
      } while( true );
    }
  }
  return (void *)0x0;
}

