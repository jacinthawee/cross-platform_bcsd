
undefined4 chopup_args(void **param_1,char *param_2,int *param_3,void **param_4)

{
  char cVar1;
  void *addr;
  char cVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int local_24;
  
  *param_3 = 0;
  pvVar4 = param_1[1];
  *param_4 = (void *)0x0;
  if (pvVar4 == (void *)0x0) {
    param_1[1] = &DAT_00000014;
    addr = CRYPTO_malloc(0x50,"apps.c",0x188);
    pvVar4 = param_1[1];
    *param_1 = addr;
  }
  else {
    addr = *param_1;
  }
  if (0 < (int)pvVar4) {
    pvVar3 = (void *)0x0;
    do {
      *(undefined4 *)((int)addr + (int)pvVar3 * 4) = 0;
      pvVar3 = (void *)((int)pvVar3 + 1);
      addr = *param_1;
    } while (pvVar3 != pvVar4);
  }
  cVar2 = *param_2;
  if (cVar2 == '\0') {
    local_24 = 0;
  }
  else {
    iVar7 = 0;
    local_24 = 0;
LAB_08079d9a:
    do {
      if ((1 < (byte)(cVar2 - 9U)) && (cVar2 != ' ')) {
        if ((int)param_1[1] <= local_24) {
          pvVar4 = (void *)((int)param_1[1] + 0x14);
          addr = CRYPTO_realloc(addr,(int)pvVar4 * 4,"apps.c",0x19d);
          if (addr == (void *)0x0) {
            return 0;
          }
          *param_1 = addr;
          param_1[1] = pvVar4;
          iVar5 = iVar7;
          if (local_24 < (int)pvVar4) {
            do {
              *(undefined4 *)((int)addr + iVar5) = 0;
              iVar5 = iVar5 + 4;
              addr = *param_1;
            } while (iVar5 != (int)pvVar4 * 4);
          }
        }
        *(char **)((int)addr + iVar7) = param_2;
        cVar2 = *param_2;
        local_24 = local_24 + 1;
        if ((cVar2 == '\'') || (cVar2 == '\"')) {
          pcVar6 = param_2 + 1;
          *(int *)((int)*param_1 + iVar7) = *(int *)((int)*param_1 + iVar7) + 1;
          cVar1 = param_2[1];
          while ((cVar1 != '\0' && (cVar2 != cVar1))) {
            pcVar6 = pcVar6 + 1;
            cVar1 = *pcVar6;
          }
          cVar2 = pcVar6[1];
          *pcVar6 = '\0';
LAB_08079e55:
          param_2 = pcVar6 + 1;
          if (cVar2 != '\0') {
            iVar7 = iVar7 + 4;
            addr = *param_1;
            goto LAB_08079d9a;
          }
        }
        else {
          pcVar6 = param_2;
          if (cVar2 != '\0') {
            while ((1 < (byte)(cVar2 - 9U) && (cVar2 != ' '))) {
              pcVar6 = pcVar6 + 1;
              cVar2 = *pcVar6;
              if (cVar2 == '\0') goto LAB_08079e06;
            }
            *pcVar6 = '\0';
            cVar2 = pcVar6[1];
            goto LAB_08079e55;
          }
        }
LAB_08079e06:
        addr = *param_1;
        break;
      }
      param_2 = param_2 + 1;
      cVar2 = *param_2;
    } while (cVar2 != '\0');
  }
  *param_3 = local_24;
  *param_4 = addr;
  return 1;
}

