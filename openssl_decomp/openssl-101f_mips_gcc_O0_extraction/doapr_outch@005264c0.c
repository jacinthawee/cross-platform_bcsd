
void doapr_outch(int *param_1,int *param_2,uint *param_3,uint *param_4,undefined param_5)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *param_3;
  if (param_2 == (int *)0x0) {
    if (*param_4 <= uVar3) {
      return;
    }
  }
  else {
    while (uVar2 = *param_4, uVar2 <= uVar3) {
      while( true ) {
        puVar1 = PTR_CRYPTO_realloc_006a8c44;
        iVar4 = *param_2;
        if (iVar4 == 0) break;
        *param_4 = uVar2 + 0x400;
        iVar4 = (*(code *)puVar1)(iVar4,uVar2 + 0x400,"b_print.c");
        uVar3 = *param_3;
        *param_2 = iVar4;
        uVar2 = *param_4;
        if (uVar3 < uVar2) goto LAB_00526570;
      }
      if (uVar2 == 0) {
        *param_4 = 0x400;
        uVar2 = 0x400;
      }
      iVar4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2,"b_print.c",0x2e5,0x2ed);
      uVar3 = *param_3;
      *param_2 = iVar4;
      if (uVar3 == 0) {
        *param_1 = 0;
      }
      else {
        (*(code *)PTR_memcpy_006aabf4)(iVar4,*param_1,uVar3);
        uVar3 = *param_3;
        *param_1 = 0;
      }
    }
  }
LAB_00526570:
  iVar4 = *param_1;
  if (iVar4 == 0) {
    iVar4 = *param_2;
  }
  *param_3 = uVar3 + 1;
  *(undefined *)(iVar4 + uVar3) = param_5;
  return;
}

