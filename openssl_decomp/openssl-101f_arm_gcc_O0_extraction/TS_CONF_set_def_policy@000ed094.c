
ASN1_OBJECT * TS_CONF_set_def_policy(CONF *param_1,char *param_2,char *param_3,undefined4 param_4)

{
  ASN1_OBJECT *a;
  ASN1_OBJECT *pAVar1;
  
  if ((param_3 == (char *)0x0) &&
     (param_3 = NCONF_get_string(param_1,param_2,"default_policy"), param_3 == (char *)0x0)) {
    __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n",param_2,"default_policy");
    ASN1_OBJECT_free((ASN1_OBJECT *)0x0);
    return (ASN1_OBJECT *)0x0;
  }
  a = OBJ_txt2obj(param_3,0);
  if (a == (ASN1_OBJECT *)0x0) {
    __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"default_policy");
    pAVar1 = a;
  }
  else {
    pAVar1 = (ASN1_OBJECT *)TS_RESP_CTX_set_def_policy(param_4,a);
    if (pAVar1 != (ASN1_OBJECT *)0x0) {
      pAVar1 = (ASN1_OBJECT *)0x1;
    }
  }
  ASN1_OBJECT_free(a);
  return pAVar1;
}

