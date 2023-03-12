
int old_hmac_encode(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x14);
  if (param_2 != (int *)0x0) {
    if (*param_2 != 0) {
      (*(code *)PTR_memcpy_006a9aec)(*param_2,piVar3[2],*piVar3);
      iVar1 = *piVar3;
      *param_2 = *param_2 + iVar1;
      return iVar1;
    }
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(*piVar3,"hm_ameth.c",0x7f);
    iVar2 = *piVar3;
    *param_2 = iVar1;
    (*(code *)PTR_memcpy_006a9aec)(iVar1,piVar3[2],iVar2);
  }
  return *piVar3;
}

