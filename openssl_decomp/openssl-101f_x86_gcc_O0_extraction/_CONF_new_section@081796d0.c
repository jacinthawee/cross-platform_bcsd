
CONF_VALUE * _CONF_new_section(CONF *conf,char *section)

{
  _STACK *p_Var1;
  size_t sVar2;
  char *__dest;
  void *pvVar3;
  CONF_VALUE *ptr;
  
  ptr = (CONF_VALUE *)0x0;
  p_Var1 = sk_new_null();
  if (p_Var1 != (_STACK *)0x0) {
    ptr = (CONF_VALUE *)CRYPTO_malloc(0xc,"conf_api.c",0x116);
    if (ptr != (CONF_VALUE *)0x0) {
      sVar2 = strlen(section);
      __dest = (char *)CRYPTO_malloc(sVar2 + 1,"conf_api.c",0x119);
      ptr->section = __dest;
      if (__dest != (char *)0x0) {
        memcpy(__dest,section,sVar2 + 1);
        ptr->name = (char *)0x0;
        ptr->value = (char *)p_Var1;
        pvVar3 = lh_insert((_LHASH *)conf->data,ptr);
        if (pvVar3 == (void *)0x0) {
          return ptr;
        }
        OpenSSLDie("conf_api.c",0x121,"vv == NULL");
        return ptr;
      }
    }
    sk_free(p_Var1);
    if (ptr != (CONF_VALUE *)0x0) {
      CRYPTO_free(ptr);
      return (CONF_VALUE *)0x0;
    }
  }
  return ptr;
}

