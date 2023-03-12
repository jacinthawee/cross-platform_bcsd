
undefined4 add_oid_section(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_2,0,"oid_section");
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
    return 1;
  }
  iVar2 = (*(code *)PTR_NCONF_get_section_006a6ed4)(param_2,iVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"problem loading oid section %s\n",iVar1);
    uVar5 = 0;
  }
  else {
    iVar1 = 0;
    while( true ) {
      iVar4 = (*(code *)PTR_sk_num_006a6e2c)(iVar2);
      if (iVar4 <= iVar1) break;
      iVar4 = (*(code *)PTR_sk_value_006a6e24)(iVar2,iVar1);
      iVar3 = (*(code *)PTR_OBJ_create_006a76b0)
                        (*(undefined4 *)(iVar4 + 8),*(undefined4 *)(iVar4 + 4));
      iVar1 = iVar1 + 1;
      if (iVar3 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (param_1,"problem creating object %s=%s\n",*(undefined4 *)(iVar4 + 4),
                   *(undefined4 *)(iVar4 + 8));
        return 0;
      }
    }
    uVar5 = 1;
  }
  return uVar5;
}

