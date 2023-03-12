
char * next_protos_parse(undefined2 *param_1,char *param_2)

{
  bool bVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  
  uVar2 = (*(code *)PTR_strlen_006aab30)(param_2);
  if (uVar2 < 0xffff) {
    pcVar3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2 + 1,"apps.c",0xab9);
    if (pcVar3 != (char *)0x0) {
      uVar4 = 1;
      uVar5 = 0;
      uVar7 = 0;
      pcVar6 = pcVar3;
      do {
        pcVar6 = pcVar6 + 1;
        if ((uVar5 == uVar2) || (*param_2 == ',')) {
          if (0xff < uVar5 - uVar7) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar3);
            return (char *)0x0;
          }
          pcVar3[uVar7] = (char)(uVar5 - uVar7);
          uVar7 = uVar4;
        }
        else {
          *pcVar6 = *param_2;
        }
        bVar1 = uVar4 <= uVar2;
        param_2 = param_2 + 1;
        uVar5 = uVar5 + 1;
        uVar4 = uVar4 + 1;
      } while (bVar1);
      *param_1 = (short)(uVar2 + 1);
      return pcVar3;
    }
  }
  return (char *)0x0;
}

