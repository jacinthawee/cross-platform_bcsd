
stack_st_CONF_VALUE *
i2v_GENERAL_NAMES(X509V3_EXT_METHOD *method,GENERAL_NAMES *gen,stack_st_CONF_VALUE *extlist)

{
  GENERAL_NAME *gen_00;
  int iVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(gen);
    if (iVar1 <= iVar3) break;
    gen_00 = (GENERAL_NAME *)(*(code *)PTR_sk_value_006a7f24)(gen,iVar3);
    extlist = i2v_GENERAL_NAME(method,gen_00,extlist);
    iVar3 = iVar3 + 1;
  }
  if (extlist != (stack_st_CONF_VALUE *)0x0) {
    return extlist;
  }
                    /* WARNING: Could not recover jumptable at 0x00590b9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  psVar2 = (stack_st_CONF_VALUE *)(*(code *)PTR_sk_new_null_006a80a4)();
  return psVar2;
}

