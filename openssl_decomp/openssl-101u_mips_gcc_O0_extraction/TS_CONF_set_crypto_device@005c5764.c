
undefined4 TS_CONF_set_crypto_device(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (((param_3 == 0) &&
      (param_3 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_1,param_2,"crypto_device"),
      param_3 == 0)) || (iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_3,"builtin"), iVar1 == 0)) {
    return 1;
  }
  iVar1 = (*(code *)PTR_ENGINE_by_id_006a6e9c)(param_3);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"engine:",param_3);
  }
  else {
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(param_3,&DAT_00673000);
    if (iVar2 == 0) {
      (*(code *)PTR_ENGINE_ctrl_006a7bc8)(iVar1,100,1,0,0);
    }
    iVar2 = (*(code *)PTR_ENGINE_set_default_006a7bd0)(iVar1,0xffff);
    if (iVar2 != 0) {
      (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"engine:",param_3);
    (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
  }
  (*(code *)PTR___fprintf_chk_006a9980)
            (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid variable value for %s::%s\n",param_2,
             "crypto_device");
  return 0;
}

