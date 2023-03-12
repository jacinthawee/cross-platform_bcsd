
void i2v_POLICY_MAPPINGS(undefined4 param_1,_STACK *param_2,stack_st_CONF_VALUE *param_3)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  int iVar3;
  stack_st_CONF_VALUE *local_c4 [2];
  char acStack_bc [80];
  char acStack_6c [80];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_c4[0] = param_3;
  for (iVar3 = 0; iVar2 = sk_num(param_2), iVar3 < iVar2; iVar3 = iVar3 + 1) {
    ppAVar1 = (ASN1_OBJECT **)sk_value(param_2,iVar3);
    i2t_ASN1_OBJECT(acStack_bc,0x50,*ppAVar1);
    i2t_ASN1_OBJECT(acStack_6c,0x50,ppAVar1[1]);
    X509V3_add_value(acStack_bc,acStack_6c,local_c4);
  }
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_c4[0]);
}

