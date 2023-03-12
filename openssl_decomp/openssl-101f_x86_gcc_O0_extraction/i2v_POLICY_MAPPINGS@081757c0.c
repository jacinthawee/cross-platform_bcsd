
stack_st_CONF_VALUE *
i2v_POLICY_MAPPINGS(undefined4 param_1,_STACK *param_2,stack_st_CONF_VALUE *param_3)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  stack_st_CONF_VALUE *local_d0 [4];
  char local_c0 [80];
  char local_70 [80];
  int local_20;
  
  local_d0[0] = param_3;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = 0;
  while( true ) {
    iVar2 = sk_num(param_2);
    if (iVar2 <= iVar3) break;
    ppAVar1 = (ASN1_OBJECT **)sk_value(param_2,iVar3);
    i2t_ASN1_OBJECT(local_c0,0x50,*ppAVar1);
    i2t_ASN1_OBJECT(local_70,0x50,ppAVar1[1]);
    X509V3_add_value(local_c0,local_70,local_d0);
    iVar3 = iVar3 + 1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_d0[0];
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

