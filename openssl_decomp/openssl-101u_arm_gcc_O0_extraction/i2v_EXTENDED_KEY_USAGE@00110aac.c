
void i2v_EXTENDED_KEY_USAGE(undefined4 param_1,_STACK *param_2,stack_st_CONF_VALUE *param_3)

{
  ASN1_OBJECT *a;
  int iVar1;
  int iVar2;
  stack_st_CONF_VALUE *local_6c [2];
  char acStack_64 [80];
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_6c[0] = param_3;
  for (iVar2 = 0; iVar1 = sk_num(param_2), iVar2 < iVar1; iVar2 = iVar2 + 1) {
    a = (ASN1_OBJECT *)sk_value(param_2,iVar2);
    i2t_ASN1_OBJECT(acStack_64,0x50,a);
    X509V3_add_value((char *)0x0,acStack_64,local_6c);
  }
  if (local_14 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_6c[0]);
}

