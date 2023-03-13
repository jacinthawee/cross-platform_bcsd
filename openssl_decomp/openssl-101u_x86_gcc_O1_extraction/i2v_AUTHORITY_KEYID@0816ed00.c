
stack_st_CONF_VALUE *
i2v_AUTHORITY_KEYID(undefined4 param_1,long **param_2,stack_st_CONF_VALUE *param_3)

{
  long *plVar1;
  char *pcVar2;
  
  plVar1 = *param_2;
  if (plVar1 != (long *)0x0) {
    pcVar2 = hex_to_string((uchar *)plVar1[2],*plVar1);
    X509V3_add_value("keyid",pcVar2,&param_3);
    CRYPTO_free(pcVar2);
  }
  if ((GENERAL_NAMES *)param_2[1] != (GENERAL_NAMES *)0x0) {
    param_3 = i2v_GENERAL_NAMES((X509V3_EXT_METHOD *)0x0,(GENERAL_NAMES *)param_2[1],param_3);
  }
  plVar1 = param_2[2];
  if (plVar1 != (long *)0x0) {
    pcVar2 = hex_to_string((uchar *)plVar1[2],*plVar1);
    X509V3_add_value("serial",pcVar2,&param_3);
    CRYPTO_free(pcVar2);
  }
  return param_3;
}

