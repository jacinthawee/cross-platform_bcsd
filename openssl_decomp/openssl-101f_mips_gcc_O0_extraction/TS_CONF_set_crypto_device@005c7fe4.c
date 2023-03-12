
undefined4 TS_CONF_set_crypto_device(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (((param_3 == 0) &&
      (param_3 = (*(code *)PTR_NCONF_get_string_006a7fa8)(param_1,param_2,"crypto_device"),
      param_3 == 0)) || (iVar1 = (*(code *)PTR_strcmp_006aac20)(param_3,"builtin"), iVar1 == 0)) {
    return 1;
  }
  iVar1 = (*(code *)PTR_ENGINE_by_id_006a7f9c)(param_3);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"engine:",param_3);
  }
  else {
    iVar2 = (*(code *)PTR_strcmp_006aac20)(param_3,&DAT_006738f0);
    if (iVar2 == 0) {
      (*(code *)PTR_ENGINE_ctrl_006a8cb4)(iVar1,100,1,0,0);
    }
    iVar2 = (*(code *)PTR_ENGINE_set_default_006a8cbc)(iVar1,0xffff);
    if (iVar2 != 0) {
      (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"engine:",param_3);
    (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
  }
  (*(code *)PTR___fprintf_chk_006aaa8c)
            (*(undefined4 *)PTR_stderr_006aac00,1,"invalid variable value for %s::%s\n",param_2,
             "crypto_device");
  return 0;
}

