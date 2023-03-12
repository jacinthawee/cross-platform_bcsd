
stack_st_CONF_VALUE *
i2v_EXTENDED_KEY_USAGE(undefined4 param_1,_STACK *param_2,stack_st_CONF_VALUE *param_3)

{
  ASN1_OBJECT *a;
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  stack_st_CONF_VALUE *local_80 [4];
  char local_70 [80];
  int local_20;
  
  local_80[0] = param_3;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = 0;
  while( true ) {
    iVar1 = sk_num(param_2);
    if (iVar1 <= iVar2) break;
    a = (ASN1_OBJECT *)sk_value(param_2,iVar2);
    i2t_ASN1_OBJECT(local_70,0x50,a);
    X509V3_add_value((char *)0x0,local_70,local_80);
    iVar2 = iVar2 + 1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_80[0];
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

