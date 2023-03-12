
stack_st_CONF_VALUE *
i2v_AUTHORITY_KEYID(undefined4 param_1,long **param_2,stack_st_CONF_VALUE *param_3)

{
  long *plVar1;
  char *pcVar2;
  stack_st_CONF_VALUE *local_res8 [2];
  
  plVar1 = *param_2;
  local_res8[0] = param_3;
  if (plVar1 != (long *)0x0) {
    pcVar2 = hex_to_string((uchar *)plVar1[2],*plVar1);
    X509V3_add_value("keyid",pcVar2,local_res8);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar2);
  }
  if ((GENERAL_NAMES *)param_2[1] != (GENERAL_NAMES *)0x0) {
    local_res8[0] =
         i2v_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,(GENERAL_NAMES *)param_2[1],local_res8[0]);
  }
  plVar1 = param_2[2];
  if (plVar1 != (long *)0x0) {
    pcVar2 = hex_to_string((uchar *)plVar1[2],*plVar1);
    X509V3_add_value("serial",pcVar2,local_res8);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar2);
  }
  return local_res8[0];
}

