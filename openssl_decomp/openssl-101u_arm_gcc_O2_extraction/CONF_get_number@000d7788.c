
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long CONF_get_number(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  CONF local_24;
  
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    pcVar1 = _CONF_get_string((CONF *)0x0,group,name);
    if (pcVar1 != (char *)0x0) {
      while( true ) {
        iVar3 = (**(code **)(_shift + 0x1c))(0,*pcVar1);
        if (iVar3 == 0) break;
        iVar3 = (**(code **)(_shift + 0x20))(0,*pcVar1);
        conf = (lhash_st_CONF_VALUE *)((int)conf * 10 + iVar3);
        pcVar1 = pcVar1 + 1;
      }
      return (long)conf;
    }
    ERR_put_error(0xe,0x6d,0x6a,"conf_lib.c",0x141);
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_24);
    local_24.data = conf;
    pcVar1 = _CONF_get_string(&local_24,group,name);
    iVar3 = 0;
    if (pcVar1 != (char *)0x0) {
      while( true ) {
        iVar2 = (*(local_24.meth)->is_number)(&local_24,*pcVar1);
        if (iVar2 == 0) break;
        iVar2 = (*(local_24.meth)->to_int)(&local_24,*pcVar1);
        iVar3 = iVar3 * 10 + iVar2;
        pcVar1 = pcVar1 + 1;
      }
      return iVar3;
    }
    ERR_put_error(0xe,0x6d,0x6c,"conf_lib.c",0x144);
    ERR_add_error_data(4,"group=",group," name=",name);
  }
  ERR_clear_error();
  return (long)pcVar1;
}

