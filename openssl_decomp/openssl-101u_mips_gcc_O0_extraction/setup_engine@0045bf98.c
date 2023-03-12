
int setup_engine(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_0063fb9c);
  if (iVar1 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"enabling auto ENGINE support\n");
    (*(code *)PTR_ENGINE_register_all_complete_006a7bdc)();
    return 0;
  }
  iVar1 = (*(code *)PTR_ENGINE_by_id_006a6e9c)(param_2);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_ENGINE_by_id_006a6e9c)("dynamic");
    if (iVar1 != 0) {
      iVar2 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a7bd8)(iVar1,"SO_PATH",param_2,0);
      if ((iVar2 != 0) &&
         (iVar2 = (*(code *)PTR_ENGINE_ctrl_cmd_string_006a7bd8)(iVar1,"LOAD",0,0), iVar2 != 0))
      goto LAB_0045c004;
      (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
    }
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"invalid engine \"%s\"\n",param_2);
    (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
    iVar1 = 0;
  }
  else {
LAB_0045c004:
    if (param_3 != 0) {
      (*(code *)PTR_ENGINE_ctrl_006a7bc8)(iVar1,1,0,param_1,0);
    }
    (*(code *)PTR_ENGINE_ctrl_cmd_006a7bcc)(iVar1,"SET_USER_INTERFACE",0,ui_method,0,1);
    iVar2 = (*(code *)PTR_ENGINE_set_default_006a7bd0)(iVar1,0xffff);
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"can\'t use that engine\n");
      (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
      (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
      iVar1 = 0;
    }
    else {
      uVar3 = (*(code *)PTR_ENGINE_get_id_006a7bd4)(iVar1);
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"engine \"%s\" set.\n",uVar3);
      (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
    }
  }
  return iVar1;
}

