
bool TS_CONF_set_default_engine(undefined4 param_1)

{
  int iVar1;
  bool bVar3;
  int iVar2;
  
  iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_1,"builtin");
  if (iVar1 == 0) {
    bVar3 = true;
  }
  else {
    iVar1 = (*(code *)PTR_ENGINE_by_id_006a6e9c)(param_1);
    if (iVar1 != 0) {
      iVar2 = (*(code *)PTR_strcmp_006a9b18)(param_1,&DAT_00673000);
      if (iVar2 == 0) {
        (*(code *)PTR_ENGINE_ctrl_006a7bc8)(iVar1,100,1,0,0);
      }
      iVar2 = (*(code *)PTR_ENGINE_set_default_006a7bd0)(iVar1,0xffff);
      if (iVar2 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"engine:",param_1);
      }
      (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
      return iVar2 != 0;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"engine:",param_1);
    bVar3 = false;
  }
  return bVar3;
}

