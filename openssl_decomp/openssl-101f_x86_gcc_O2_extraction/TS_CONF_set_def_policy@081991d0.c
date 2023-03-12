
bool TS_CONF_set_def_policy(CONF *param_1,char *param_2,char *param_3,undefined4 param_4)

{
  ASN1_OBJECT *a;
  int iVar1;
  bool bVar2;
  
  if (param_3 == (char *)0x0) {
    param_3 = NCONF_get_string(param_1,param_2,"default_policy");
    if (param_3 == (char *)0x0) {
      a = (ASN1_OBJECT *)0x0;
      bVar2 = false;
      __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n",param_2,"default_policy");
      goto LAB_0819920b;
    }
  }
  a = OBJ_txt2obj(param_3,0);
  if (a == (ASN1_OBJECT *)0x0) {
    bVar2 = false;
    __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"default_policy");
  }
  else {
    iVar1 = TS_RESP_CTX_set_def_policy(param_4,a);
    bVar2 = iVar1 != 0;
  }
LAB_0819920b:
  ASN1_OBJECT_free(a);
  return bVar2;
}

