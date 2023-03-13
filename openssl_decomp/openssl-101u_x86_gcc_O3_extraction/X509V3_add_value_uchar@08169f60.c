
int X509V3_add_value_uchar(char *name,uchar *value,stack_st_CONF_VALUE **extlist)

{
  char *ptr;
  char *ptr_00;
  undefined4 *data;
  int iVar1;
  _STACK *p_Var2;
  
  if (name == (char *)0x0) {
    ptr = (char *)0x0;
    if (value != (uchar *)0x0) goto LAB_08169f99;
LAB_0816a08a:
    ptr_00 = (char *)0x0;
LAB_08169faf:
    data = (undefined4 *)CRYPTO_malloc(0xc,"v3_utl.c",0x5b);
    if (data != (undefined4 *)0x0) {
      if (*extlist == (stack_st_CONF_VALUE *)0x0) {
        p_Var2 = sk_new_null();
        *extlist = (stack_st_CONF_VALUE *)p_Var2;
        if (p_Var2 != (_STACK *)0x0) goto LAB_08169fd8;
      }
      else {
LAB_08169fd8:
        *data = 0;
        data[1] = ptr;
        data[2] = ptr_00;
        iVar1 = sk_push((_STACK *)*extlist,data);
        if (iVar1 != 0) {
          return 1;
        }
      }
      ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
      CRYPTO_free(data);
      goto LAB_0816a018;
    }
  }
  else {
    ptr = BUF_strdup(name);
    if (ptr == (char *)0x0) {
      ptr_00 = (char *)0x0;
    }
    else {
      if (value == (uchar *)0x0) goto LAB_0816a08a;
LAB_08169f99:
      ptr_00 = BUF_strdup((char *)value);
      if (ptr_00 != (char *)0x0) goto LAB_08169faf;
    }
  }
  ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
LAB_0816a018:
  if (ptr != (char *)0x0) {
    CRYPTO_free(ptr);
  }
  if (ptr_00 != (char *)0x0) {
    CRYPTO_free(ptr_00);
  }
  return 0;
}

