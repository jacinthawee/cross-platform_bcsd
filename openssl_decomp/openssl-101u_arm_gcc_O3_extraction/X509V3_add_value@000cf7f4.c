
int X509V3_add_value(char *name,char *value,stack_st_CONF_VALUE **extlist)

{
  char *ptr;
  undefined4 *data;
  int iVar1;
  _STACK *p_Var2;
  
  if ((((name != (char *)0x0) && (ptr = BUF_strdup(name), name = ptr, ptr == (char *)0x0)) ||
      ((ptr = value, value != (char *)0x0 && (ptr = BUF_strdup(value), ptr == (char *)0x0)))) ||
     (data = (undefined4 *)CRYPTO_malloc(0xc,"v3_utl.c",0x5b), data == (undefined4 *)0x0)) {
    ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
    goto LAB_000cf85c;
  }
  if (*extlist == (stack_st_CONF_VALUE *)0x0) {
    p_Var2 = sk_new_null();
    *extlist = (stack_st_CONF_VALUE *)p_Var2;
    if (p_Var2 != (_STACK *)0x0) goto LAB_000cf82e;
  }
  else {
LAB_000cf82e:
    data[1] = name;
    data[2] = ptr;
    *data = 0;
    iVar1 = sk_push((_STACK *)*extlist,data);
    if (iVar1 != 0) {
      return 1;
    }
  }
  ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
  CRYPTO_free(data);
LAB_000cf85c:
  if (name != (char *)0x0) {
    CRYPTO_free(name);
  }
  if (ptr != (char *)0x0) {
    CRYPTO_free(ptr);
    ptr = (char *)0x0;
  }
  return (int)ptr;
}

