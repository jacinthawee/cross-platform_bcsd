
int NCONF_get_number_e(CONF *conf,char *group,char *name,long *result)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  if (result == (long *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x70,0x43,"conf_lib.c",0x15b);
    return 0;
  }
  pcVar1 = _CONF_get_string(conf,group,name);
  if (pcVar1 != (char *)0x0) {
    *result = 0;
    while (iVar2 = (*conf->meth->is_number)(conf,*pcVar1), iVar2 != 0) {
      iVar3 = *result;
      iVar2 = (*conf->meth->to_int)(conf,*pcVar1);
      *result = iVar3 * 10 + iVar2;
      pcVar1 = pcVar1 + 1;
    }
    return 1;
  }
  if (conf == (CONF *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6d,0x6a,"conf_lib.c",0x14b);
  }
  else {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6d,0x6c,"conf_lib.c",0x14f);
    (*(code *)PTR_ERR_add_error_data_006a9264)(4,"group=",group," name=",name);
  }
  return 0;
}

