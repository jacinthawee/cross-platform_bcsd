
void list_md_fn(int param_1,char *param_2,char *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)();
    uVar1 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00422184. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_BIO_printf_006a7f38)(param_4,"%s\n",uVar1);
    return;
  }
  if (param_2 == (char *)0x0) {
    param_2 = "<undefined>";
  }
  if (param_3 == (char *)0x0) {
    param_3 = "<undefined>";
  }
                    /* WARNING: Could not recover jumptable at 0x004221bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_printf_006a7f38)(param_4,"%s => %s\n",param_2,param_3);
  return;
}

