
int i2s_ASN1_IA5STRING(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a8108)(*param_2 + 1,"v3_ia5.c",0x55);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x95,0x41,"v3_ia5.c",0x56);
      iVar1 = 0;
    }
    else {
      iVar1 = (*(code *)PTR_memcpy_006aabf4)(iVar1,param_2[2],*param_2);
      *(undefined *)(iVar1 + *param_2) = 0;
    }
    return iVar1;
  }
  return 0;
}

