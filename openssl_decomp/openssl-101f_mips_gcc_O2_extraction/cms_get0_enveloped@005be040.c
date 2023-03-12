
undefined4 cms_get0_enveloped(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*param_1);
  if (iVar1 == 0x17) {
    return param_1[1];
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x83,0x6b,"cms_env.c",0x4f);
  return 0;
}

