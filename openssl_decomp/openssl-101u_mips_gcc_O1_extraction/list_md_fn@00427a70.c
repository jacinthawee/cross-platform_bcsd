
void list_md_fn(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    uVar1 = (*(code *)PTR_EVP_MD_type_006a73cc)();
    uVar1 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar1);
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(param_2,uVar1);
    if ((iVar2 == 0) && (uVar3 = (*(code *)PTR_EVP_MD_flags_006a74c8)(param_1), (uVar3 & 2) == 0)) {
      iVar2 = (*(code *)PTR_strchr_006a9a28)(uVar1,0x20);
      if (iVar2 != 0) {
        uVar1 = (*(code *)PTR_EVP_MD_type_006a73cc)(param_1);
        uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar1);
      }
                    /* WARNING: Could not recover jumptable at 0x00427b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_printf_006a6e38)
                (param_4,"-%-14s to use the %s message digest algorithm\n",uVar1,uVar1);
      return;
    }
  }
  return;
}

