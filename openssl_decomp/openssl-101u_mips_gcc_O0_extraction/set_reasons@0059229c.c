
undefined4 set_reasons(int *param_1,char *param_2)

{
  int *piVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  psVar2 = X509V3_parse_list(param_2);
  if ((psVar2 == (stack_st_CONF_VALUE *)0x0) || (iVar6 = 0, *param_1 != 0)) {
    return 0;
  }
  do {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar2);
    if (iVar3 <= iVar6) {
      uVar5 = 1;
      goto LAB_005923dc;
    }
    iVar3 = (*(code *)PTR_sk_value_006a6e24)(psVar2,iVar6);
    iVar7 = *param_1;
    uVar5 = *(undefined4 *)(iVar3 + 4);
    if (iVar7 == 0) {
      iVar7 = (*(code *)PTR_ASN1_BIT_STRING_new_006a8660)();
      *param_1 = iVar7;
      if (iVar7 == 0) {
LAB_005923d8:
        uVar5 = 0;
LAB_005923dc:
        (*(code *)PTR_sk_pop_free_006a7058)(psVar2,PTR_X509V3_conf_free_006a7b4c);
        return uVar5;
      }
    }
    puVar4 = (undefined4 *)reason_flags;
    while (iVar3 = (*(code *)PTR_strcmp_006a9b18)(puVar4[2],uVar5), iVar3 != 0) {
      piVar1 = puVar4 + 4;
      puVar4 = puVar4 + 3;
      if (*piVar1 == 0) goto LAB_005923d8;
    }
    iVar3 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a8de0)(iVar7,*puVar4,1);
    if ((iVar3 == 0) || (iVar6 = iVar6 + 1, puVar4[1] == 0)) goto LAB_005923d8;
  } while( true );
}

