
undefined4 doapr_outch(int *param_1,int *param_2,uint *param_3,uint *param_4,undefined param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *param_4;
  uVar3 = *param_3;
  if ((param_2 != (int *)0x0) && (uVar3 == uVar1)) {
    uVar1 = uVar3 + 0x400;
    if (0x7ffffbff < uVar3) {
      return 0;
    }
    iVar2 = *param_2;
    *param_4 = uVar1;
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar1,"b_print.c",0x2f3);
      *param_2 = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
      uVar3 = *param_3;
      if (uVar3 != 0) {
        (*(code *)PTR_memcpy_006a9aec)(iVar2,*param_1);
        uVar3 = *param_3;
      }
      uVar1 = *param_4;
      *param_1 = 0;
      if (uVar1 <= uVar3) {
        return 1;
      }
      goto LAB_005246fc;
    }
    iVar2 = (*(code *)PTR_CRYPTO_realloc_006a7b58)(iVar2,uVar1,"b_print.c",0x2fd);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = *param_3;
    uVar1 = *param_4;
    *param_2 = iVar2;
  }
  if (uVar1 <= uVar3) {
    return 1;
  }
  iVar2 = *param_1;
  if (iVar2 != 0) {
    *param_3 = uVar3 + 1;
    *(undefined *)(iVar2 + uVar3) = param_5;
    return 1;
  }
LAB_005246fc:
  iVar2 = *param_2;
  *param_3 = uVar3 + 1;
  *(undefined *)(iVar2 + uVar3) = param_5;
  return 1;
}

