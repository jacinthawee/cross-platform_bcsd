
undefined4 TS_CONF_set_tsa_name(CONF *param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  
  pcVar1 = NCONF_get_string(param_1,param_2,"tsa_name");
  if (pcVar1 == (char *)0x0) {
    return 1;
  }
  if (*pcVar1 == 'y') {
    if (((pcVar1[1] == 'e') && (pcVar1[2] == 's')) && (pcVar1[3] == '\0')) {
      TS_RESP_CTX_add_flags(param_3,1);
      return 1;
    }
  }
  else if (((*pcVar1 == 'n') && (pcVar1[1] == 'o')) && (pcVar1[2] == '\0')) {
    return 1;
  }
  __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"tsa_name");
  return 0;
}

