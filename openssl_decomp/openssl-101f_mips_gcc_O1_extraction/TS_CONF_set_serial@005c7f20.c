
undefined4
TS_CONF_set_serial(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_NCONF_get_string_006a7fa8)(param_1,param_2,"serial");
  if (iVar1 != 0) {
    TS_RESP_CTX_set_serial_cb(param_4,param_3,iVar1);
    return 1;
  }
  (*(code *)PTR___fprintf_chk_006aaa8c)
            (*(undefined4 *)PTR_stderr_006aac00,1,"variable lookup failed for %s::%s\n",param_2,
             "serial");
  return 0;
}

