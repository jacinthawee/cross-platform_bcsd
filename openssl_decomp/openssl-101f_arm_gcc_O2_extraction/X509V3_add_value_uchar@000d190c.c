
int X509V3_add_value_uchar(char *name,uchar *value,stack_st_CONF_VALUE **extlist)

{
  uchar *ptr;
  undefined4 *data;
  int iVar1;
  _STACK *p_Var2;
  
  if ((((name != (char *)0x0) &&
       (ptr = (uchar *)BUF_strdup(name), name = (char *)ptr, ptr == (uchar *)0x0)) ||
      ((ptr = value, value != (uchar *)0x0 &&
       (ptr = (uchar *)BUF_strdup((char *)value), ptr == (uchar *)0x0)))) ||
     (data = (undefined4 *)CRYPTO_malloc(0xc,"v3_utl.c",0x58), data == (undefined4 *)0x0)) {
    ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x60);
    goto LAB_000d1974;
  }
  if (*extlist == (stack_st_CONF_VALUE *)0x0) {
    p_Var2 = sk_new_null();
    *extlist = (stack_st_CONF_VALUE *)p_Var2;
    if (p_Var2 != (_STACK *)0x0) goto LAB_000d1946;
  }
  else {
LAB_000d1946:
    data[1] = name;
    data[2] = ptr;
    *data = 0;
    iVar1 = sk_push((_STACK *)*extlist,data);
    if (iVar1 != 0) {
      return 1;
    }
  }
  ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x60);
  CRYPTO_free(data);
LAB_000d1974:
  if ((uchar *)name != (uchar *)0x0) {
    CRYPTO_free(name);
  }
  if (ptr != (uchar *)0x0) {
    CRYPTO_free(ptr);
    ptr = (uchar *)0x0;
  }
  return (int)ptr;
}

