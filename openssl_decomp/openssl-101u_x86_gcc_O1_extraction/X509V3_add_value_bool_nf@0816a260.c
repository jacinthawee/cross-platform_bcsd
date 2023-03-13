
int X509V3_add_value_bool_nf(char *name,int asn1_bool,stack_st_CONF_VALUE **extlist)

{
  int iVar1;
  char *ptr;
  char *ptr_00;
  undefined4 *data;
  _STACK *p_Var2;
  
  if (asn1_bool == 0) {
LAB_0816a26b:
    iVar1 = 1;
  }
  else {
    if (name == (char *)0x0) {
      ptr = (char *)0x0;
LAB_0816a29d:
      ptr_00 = BUF_strdup("TRUE");
      if (ptr_00 == (char *)0x0) {
        ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
        if (ptr == (char *)0x0) goto LAB_0816a368;
      }
      else {
        data = (undefined4 *)CRYPTO_malloc(0xc,"v3_utl.c",0x5b);
        if (data == (undefined4 *)0x0) {
          ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
        }
        else {
          if (*extlist == (stack_st_CONF_VALUE *)0x0) {
            p_Var2 = sk_new_null();
            *extlist = (stack_st_CONF_VALUE *)p_Var2;
            if (p_Var2 != (_STACK *)0x0) goto LAB_0816a2e3;
          }
          else {
LAB_0816a2e3:
            *data = 0;
            data[1] = ptr;
            data[2] = ptr_00;
            iVar1 = sk_push((_STACK *)*extlist,data);
            if (iVar1 != 0) goto LAB_0816a26b;
          }
          ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
          CRYPTO_free(data);
        }
        if (ptr == (char *)0x0) goto LAB_0816a33e;
      }
      CRYPTO_free(ptr);
      if (ptr_00 != (char *)0x0) {
LAB_0816a33e:
        CRYPTO_free(ptr_00);
        return 0;
      }
    }
    else {
      ptr = BUF_strdup(name);
      if (ptr != (char *)0x0) goto LAB_0816a29d;
      ERR_put_error(0x22,0x69,0x41,"v3_utl.c",0x66);
    }
LAB_0816a368:
    iVar1 = 0;
  }
  return iVar1;
}

