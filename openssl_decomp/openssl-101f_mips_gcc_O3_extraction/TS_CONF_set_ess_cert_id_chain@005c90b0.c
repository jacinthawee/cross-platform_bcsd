
undefined4 TS_CONF_set_ess_cert_id_chain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)(param_1,param_2,"ess_cert_id_chain");
  if (pcVar1 == (char *)0x0) {
    return 1;
  }
  if (*pcVar1 == 'y') {
    if (((pcVar1[1] == 'e') && (pcVar1[2] == 's')) && (pcVar1[3] == '\0')) {
      TS_RESP_CTX_add_flags(param_3,4);
      return 1;
    }
  }
  else if (((*pcVar1 == 'n') && (pcVar1[1] == 'o')) && (pcVar1[2] == '\0')) {
    return 1;
  }
  (*(code *)PTR___fprintf_chk_006aaa8c)
            (*(undefined4 *)PTR_stderr_006aac00,1,"invalid variable value for %s::%s\n",param_2,
             "ess_cert_id_chain");
  return 0;
}

