
void TS_X509_ALGOR_print_bio(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*param_2);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x005c7aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Hash Algorithm: %s\n","UNKNOWN");
    return;
  }
  uVar2 = (*(code *)PTR_OBJ_nid2ln_006a821c)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005c7adc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Hash Algorithm: %s\n",uVar2);
  return;
}

