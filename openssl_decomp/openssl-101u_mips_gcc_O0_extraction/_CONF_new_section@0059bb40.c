
CONF_VALUE * _CONF_new_section(CONF *conf,char *section)

{
  undefined *puVar1;
  char *pcVar2;
  CONF_VALUE *pCVar3;
  int iVar4;
  char *pcVar5;
  lhash_st_CONF_VALUE *plVar6;
  
  pcVar2 = (char *)(*(code *)PTR_sk_new_null_006a6fa4)();
  if (pcVar2 == (char *)0x0) {
    return (CONF_VALUE *)0x0;
  }
  pCVar3 = (CONF_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xc,"conf_api.c",0x119);
  if (pCVar3 != (CONF_VALUE *)0x0) {
    iVar4 = (*(code *)PTR_strlen_006a9a24)(section);
    pcVar5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4 + 1,"conf_api.c",0x11c);
    pCVar3->section = pcVar5;
    if (pcVar5 != (char *)0x0) {
      (*(code *)PTR_memcpy_006a9aec)(pcVar5,section,iVar4 + 1);
      plVar6 = conf->data;
      pCVar3->name = (char *)0x0;
      puVar1 = PTR_lh_insert_006a7414;
      pCVar3->value = pcVar2;
      iVar4 = (*(code *)puVar1)(plVar6,pCVar3);
      if (iVar4 == 0) {
        return pCVar3;
      }
      (*(code *)PTR_OpenSSLDie_006a7c5c)("conf_api.c",0x124,"vv == NULL");
      return pCVar3;
    }
  }
  (*(code *)PTR_sk_free_006a6e80)(pcVar2);
  if (pCVar3 == (CONF_VALUE *)0x0) {
    return (CONF_VALUE *)0x0;
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(pCVar3);
  return (CONF_VALUE *)0x0;
}

