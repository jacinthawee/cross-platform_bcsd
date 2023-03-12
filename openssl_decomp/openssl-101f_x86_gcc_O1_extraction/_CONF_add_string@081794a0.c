
int _CONF_add_string(CONF *conf,CONF_VALUE *section,CONF_VALUE *value)

{
  _STACK *st;
  int iVar1;
  void *p;
  
  st = (_STACK *)section->value;
  value->section = section->section;
  iVar1 = sk_push(st,value);
  if (iVar1 != 0) {
    iVar1 = 1;
    p = lh_insert((_LHASH *)conf->data,value);
    if (p != (void *)0x0) {
      sk_delete_ptr(st,p);
      CRYPTO_free(*(void **)((int)p + 4));
      CRYPTO_free(*(void **)((int)p + 8));
      CRYPTO_free(p);
      return 1;
    }
  }
  return iVar1;
}
