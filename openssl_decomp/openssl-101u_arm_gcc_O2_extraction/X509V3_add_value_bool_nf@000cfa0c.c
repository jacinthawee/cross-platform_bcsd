
int X509V3_add_value_bool_nf(char *name,int asn1_bool,stack_st_CONF_VALUE **extlist)

{
  char *ptr;
  undefined4 *data;
  int iVar1;
  _STACK *p_Var2;
  
  if (asn1_bool == 0) {
    return 1;
  }
  if ((((name != (char *)0x0) && (ptr = BUF_strdup(name), name = ptr, ptr == (char *)0x0)) ||
      (ptr = BUF_strdup("TRUE"), ptr == (char *)0x0)) ||
     (data = (undefined4 *)CRYPTO_malloc(0xc,"v3_utl.c",0x5b), data == (undefined4 *)0x0)) {
    ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
    goto LAB_000cfa7a;
  }
  if (*extlist == (stack_st_CONF_VALUE *)0x0) {
    p_Var2 = sk_new_null();
    *extlist = (stack_st_CONF_VALUE *)p_Var2;
    if (p_Var2 != (_STACK *)0x0) goto LAB_000cfa4c;
  }
  else {
LAB_000cfa4c:
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
LAB_000cfa7a:
  if (name != (char *)0x0) {
    CRYPTO_free(name);
  }
  if (ptr != (char *)0x0) {
    CRYPTO_free(ptr);
    ptr = (char *)0x0;
  }
  return (int)ptr;
}

