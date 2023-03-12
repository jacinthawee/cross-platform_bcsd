
ASN1_BIT_STRING *
v2i_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  ASN1_BIT_STRING *pAVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  
  pAVar1 = (ASN1_BIT_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(3);
  if (pAVar1 == (ASN1_BIT_STRING *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x65,0x41,"v3_bitst.c",0x71);
    return (ASN1_BIT_STRING *)0x0;
  }
  iVar7 = 0;
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)(nval);
  if (0 < iVar2) {
    do {
      puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(nval,iVar7);
      iVar2 = *(int *)((int)method->usr_data + 4);
      if (iVar2 == 0) {
LAB_00611328:
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x65,0x6f,"v3_bitst.c",0x84);
        (*(code *)PTR_ERR_add_error_data_006a9264)
                  (6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
LAB_0061138c:
        (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar1);
        return (ASN1_BIT_STRING *)0x0;
      }
      uVar6 = puVar3[1];
      puVar5 = (undefined4 *)method->usr_data;
      while ((iVar4 = (*(code *)PTR_strcmp_006aac20)(puVar5[2],uVar6), iVar4 != 0 &&
             (iVar2 = (*(code *)PTR_strcmp_006aac20)(iVar2,uVar6), iVar2 != 0))) {
        iVar2 = puVar5[4];
        puVar5 = puVar5 + 3;
        if (iVar2 == 0) goto LAB_00611328;
      }
      iVar2 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a9ee8)(pAVar1,*puVar5,1);
      if (iVar2 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x65,0x41,"v3_bitst.c",0x7b);
        goto LAB_0061138c;
      }
      if (puVar5[1] == 0) goto LAB_00611328;
      iVar7 = iVar7 + 1;
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(nval);
    } while (iVar7 < iVar2);
  }
  return pAVar1;
}

