
_STACK * add_oid_section(BIO *param_1,CONF *param_2)

{
  char *section;
  _STACK *p_Var1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  section = NCONF_get_string(param_2,(char *)0x0,"oid_section");
  if (section == (char *)0x0) {
    ERR_clear_error();
    return (_STACK *)0x1;
  }
  p_Var1 = (_STACK *)NCONF_get_section(param_2,section);
  if (p_Var1 == (_STACK *)0x0) {
    BIO_printf(param_1,"problem loading oid section %s\n",section);
  }
  else {
    iVar4 = 0;
    while( true ) {
      iVar3 = sk_num(p_Var1);
      if (iVar3 <= iVar4) break;
      pvVar2 = sk_value(p_Var1,iVar4);
      iVar3 = OBJ_create(*(char **)((int)pvVar2 + 8),*(char **)((int)pvVar2 + 4),
                         *(char **)((int)pvVar2 + 4));
      iVar4 = iVar4 + 1;
      if (iVar3 == 0) {
        BIO_printf(param_1,"problem creating object %s=%s\n",*(undefined4 *)((int)pvVar2 + 4),
                   *(undefined4 *)((int)pvVar2 + 8));
        return (_STACK *)0x0;
      }
    }
    p_Var1 = (_STACK *)0x1;
  }
  return p_Var1;
}

