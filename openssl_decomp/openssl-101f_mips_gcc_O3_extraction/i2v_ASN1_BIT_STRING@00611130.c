
stack_st_CONF_VALUE *
i2v_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,ASN1_BIT_STRING *bits,stack_st_CONF_VALUE *extlist)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  stack_st_CONF_VALUE *local_res8 [2];
  
  local_res8[0] = extlist;
  if (*(int *)((int)method->usr_data + 4) != 0) {
    puVar3 = (undefined4 *)method->usr_data;
    do {
      while (iVar2 = (*(code *)PTR_ASN1_BIT_STRING_get_bit_006aa184)(bits,*puVar3), iVar2 != 0) {
        (*(code *)PTR_X509V3_add_value_006a8ea4)(puVar3[1],0,local_res8);
        piVar1 = puVar3 + 4;
        puVar3 = puVar3 + 3;
        if (*piVar1 == 0) {
          return local_res8[0];
        }
      }
      piVar1 = puVar3 + 4;
      puVar3 = puVar3 + 3;
    } while (*piVar1 != 0);
  }
  return local_res8[0];
}

