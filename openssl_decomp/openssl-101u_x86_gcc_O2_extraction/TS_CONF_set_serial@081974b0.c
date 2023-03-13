
undefined4 TS_CONF_set_serial(CONF *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  
  pcVar1 = NCONF_get_string(param_1,param_2,"serial");
  if (pcVar1 != (char *)0x0) {
    TS_RESP_CTX_set_serial_cb(param_4,param_3,pcVar1);
    return 1;
  }
  __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n",param_2,"serial");
  return 0;
}

