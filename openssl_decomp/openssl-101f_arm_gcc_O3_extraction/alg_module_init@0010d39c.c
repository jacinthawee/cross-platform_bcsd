
_STACK * alg_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  char *section;
  _STACK *p_Var1;
  int iVar2;
  CONF_VALUE *value;
  int iVar3;
  int local_1c [2];
  
  section = CONF_imodule_get_value(param_1);
  p_Var1 = (_STACK *)NCONF_get_section(param_2,section);
  if (p_Var1 == (_STACK *)0x0) {
    ERR_put_error(6,0xb1,0xa5,"evp_cnf.c",0x53);
  }
  else {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = sk_num(p_Var1);
        if (iVar2 <= iVar3) {
          return (_STACK *)0x1;
        }
        value = (CONF_VALUE *)sk_value(p_Var1,iVar3);
        iVar2 = strcmp(value->name,"fips_mode");
        if (iVar2 == 0) break;
        ERR_put_error(6,0xb1,0xa9,"evp_cnf.c",0x71);
        ERR_add_error_data(4,"name=",value->name,", value=",value->value);
        iVar3 = iVar3 + 1;
      }
      iVar2 = X509V3_get_value_bool(value,local_1c);
      if (iVar2 == 0) {
        ERR_put_error(6,0xb1,0xa8,"evp_cnf.c",0x5e);
        goto LAB_0010d412;
      }
      iVar3 = iVar3 + 1;
    } while (local_1c[0] < 1);
    ERR_put_error(6,0xb1,0xa7,"evp_cnf.c",0x6a);
LAB_0010d412:
    p_Var1 = (_STACK *)0x0;
  }
  return p_Var1;
}

