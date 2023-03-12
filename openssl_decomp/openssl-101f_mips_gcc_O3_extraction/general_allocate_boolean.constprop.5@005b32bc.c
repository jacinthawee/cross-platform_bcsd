
int general_allocate_boolean_constprop_5
              (int param_1,int param_2,int param_3,char *param_4,int param_5,int param_6,int param_7
              ,int param_8)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  if (param_4 == (char *)0x0) {
    uVar5 = 0xca;
  }
  else {
    if (param_5 != 0) {
      cVar1 = *param_4;
      pcVar6 = param_4;
      while (cVar1 != '\0') {
        while( true ) {
          pcVar6 = pcVar6 + 1;
          iVar3 = (*(code *)PTR_strchr_006aab34)(param_5);
          if (iVar3 == 0) break;
          (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6c,0x68,"ui_lib.c",0xd7);
          if (*pcVar6 == '\0') goto LAB_005b3378;
        }
        cVar1 = *pcVar6;
      }
LAB_005b3378:
      if (param_2 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6d,0x43,"ui_lib.c",0x93);
        return -1;
      }
      if (param_8 != 0) {
        piVar4 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x20,"ui_lib.c",0x9a);
        if (piVar4 == (int *)0x0) {
          return -1;
        }
        piVar4[1] = param_2;
        *piVar4 = 3;
        piVar4[3] = param_8;
        iVar3 = *(int *)(param_1 + 4);
        piVar4[2] = param_7;
        piVar4[7] = (uint)(param_6 != 0);
        if (iVar3 == 0) {
          iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
          *(int *)(param_1 + 4) = iVar3;
          if (iVar3 == 0) {
            if (((piVar4[7] & 1U) != 0) &&
               ((*(code *)PTR_CRYPTO_free_006a7f88)(piVar4[1]), *piVar4 == 3)) {
              (*(code *)PTR_CRYPTO_free_006a7f88)(piVar4[4]);
              (*(code *)PTR_CRYPTO_free_006a7f88)(piVar4[5]);
              (*(code *)PTR_CRYPTO_free_006a7f88)(piVar4[6]);
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(piVar4);
            return -1;
          }
        }
        puVar2 = PTR_sk_push_006a80a8;
        piVar4[4] = param_3;
        piVar4[5] = (int)param_4;
        piVar4[6] = param_5;
        iVar3 = (*(code *)puVar2)(iVar3,piVar4);
        return iVar3 - (uint)(iVar3 < 1);
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6d,0x69,"ui_lib.c",0x98);
      return -1;
    }
    uVar5 = 0xce;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6c,0x43,"ui_lib.c",uVar5);
  return -1;
}

