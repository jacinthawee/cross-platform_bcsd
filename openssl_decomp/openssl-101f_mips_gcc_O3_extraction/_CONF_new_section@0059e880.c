
CONF_VALUE * _CONF_new_section(CONF *conf,char *section)

{
  undefined *puVar1;
  char *pcVar2;
  CONF_VALUE *pCVar3;
  int iVar4;
  char *pcVar5;
  lhash_st_CONF_VALUE *plVar6;
  
  pcVar2 = (char *)(*(code *)PTR_sk_new_null_006a80a4)();
  if (pcVar2 == (char *)0x0) {
    return (CONF_VALUE *)0x0;
  }
  pCVar3 = (CONF_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xc,"conf_api.c",0x116);
  if (pCVar3 != (CONF_VALUE *)0x0) {
    iVar4 = (*(code *)PTR_strlen_006aab30)(section);
    pcVar5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4 + 1,"conf_api.c",0x119);
    pCVar3->section = pcVar5;
    if (pcVar5 != (char *)0x0) {
      (*(code *)PTR_memcpy_006aabf4)(pcVar5,section,iVar4 + 1);
      plVar6 = conf->data;
      pCVar3->name = (char *)0x0;
      puVar1 = PTR_lh_insert_006a8514;
      pCVar3->value = pcVar2;
      iVar4 = (*(code *)puVar1)(plVar6,pCVar3);
      if (iVar4 == 0) {
        return pCVar3;
      }
      (*(code *)PTR_OpenSSLDie_006a8d4c)("conf_api.c",0x121,"vv == NULL");
      return pCVar3;
    }
  }
  (*(code *)PTR_sk_free_006a7f80)(pcVar2);
  if (pCVar3 == (CONF_VALUE *)0x0) {
    return (CONF_VALUE *)0x0;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(pCVar3);
  return (CONF_VALUE *)0x0;
}

