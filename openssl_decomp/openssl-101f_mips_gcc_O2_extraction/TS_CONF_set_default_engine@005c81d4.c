
bool TS_CONF_set_default_engine(undefined4 param_1)

{
  int iVar1;
  bool bVar3;
  int iVar2;
  
  iVar1 = (*(code *)PTR_strcmp_006aac20)(param_1,"builtin");
  if (iVar1 == 0) {
    bVar3 = true;
  }
  else {
    iVar1 = (*(code *)PTR_ENGINE_by_id_006a7f9c)(param_1);
    if (iVar1 != 0) {
      iVar2 = (*(code *)PTR_strcmp_006aac20)(param_1,&DAT_00673910);
      if (iVar2 == 0) {
        (*(code *)PTR_ENGINE_ctrl_006a8cb4)(iVar1,100,1,0,0);
      }
      iVar2 = (*(code *)PTR_ENGINE_set_default_006a8cbc)(iVar1,0xffff);
      if (iVar2 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"engine:",param_1);
      }
      (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
      return iVar2 != 0;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x92,0x7f,"ts_conf.c",0xe6);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"engine:",param_1);
    bVar3 = false;
  }
  return bVar3;
}

