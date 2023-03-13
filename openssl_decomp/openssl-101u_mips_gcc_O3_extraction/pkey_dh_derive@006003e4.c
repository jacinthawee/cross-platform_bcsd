
int pkey_dh_derive(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    iVar1 = (*(code *)PTR_DH_compute_key_006a7fa4)
                      (param_2,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x14) + 0x14),
                       *(undefined4 *)(*(int *)(param_1 + 8) + 0x14));
    if (-1 < iVar1) {
      *param_3 = iVar1;
      iVar1 = 1;
    }
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(5,0x70,0x6c,"dh_pmeth.c",0xca);
  return 0;
}

