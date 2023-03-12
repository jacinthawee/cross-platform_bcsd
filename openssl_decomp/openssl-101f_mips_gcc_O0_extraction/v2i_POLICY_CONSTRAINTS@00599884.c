
ASN1_INTEGER ** v2i_POLICY_CONSTRAINTS(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ASN1_INTEGER **aint;
  int iVar1;
  CONF_VALUE *value;
  int iVar2;
  char *pcVar3;
  
  aint = (ASN1_INTEGER **)(*(code *)PTR_ASN1_item_new_006a9778)(POLICY_CONSTRAINTS_it);
  if (aint == (ASN1_INTEGER **)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x92,0x41,"v3_pcons.c",0x71);
  }
  else {
    iVar2 = 0;
    do {
      while( true ) {
        iVar1 = (*(code *)PTR_sk_num_006a7f2c)(param_3);
        if (iVar1 <= iVar2) {
          if (aint[1] != (ASN1_INTEGER *)0x0) {
            return aint;
          }
          if (*aint != (ASN1_INTEGER *)0x0) {
            return aint;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x92,0x97,"v3_pcons.c",0x83);
          goto LAB_00599984;
        }
        value = (CONF_VALUE *)(*(code *)PTR_sk_value_006a7f24)(param_3,iVar2);
        pcVar3 = value->name;
        iVar1 = (*(code *)PTR_strcmp_006aac20)(pcVar3,"requireExplicitPolicy");
        if (iVar1 == 0) break;
        iVar1 = (*(code *)PTR_strcmp_006aac20)(pcVar3,"inhibitPolicyMapping");
        if (iVar1 != 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x92,0x6a,"v3_pcons.c",0x7d);
          (*(code *)PTR_ERR_add_error_data_006a9264)
                    (6,"section:",value->section,",name:",value->name,",value:",value->value);
          goto LAB_00599984;
        }
        iVar1 = X509V3_get_value_int(value,aint + 1);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_00599984;
      }
      iVar1 = X509V3_get_value_int(value,aint);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
LAB_00599984:
    (*(code *)PTR_ASN1_item_free_006a977c)(aint,POLICY_CONSTRAINTS_it);
  }
  return (ASN1_INTEGER **)0x0;
}

