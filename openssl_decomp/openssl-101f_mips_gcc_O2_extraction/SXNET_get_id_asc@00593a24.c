
ASN1_OCTET_STRING * SXNET_get_id_asc(SXNET *sx,char *zone)

{
  ASN1_INTEGER *pAVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  ASN1_OCTET_STRING *pAVar5;
  
  pAVar1 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,zone);
  if (pAVar1 == (ASN1_INTEGER *)0x0) {
    pAVar5 = (ASN1_OCTET_STRING *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x80,0x83,"v3_sxnet.c",0xe4);
  }
  else {
    iVar4 = 0;
    do {
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(sx->ids);
      if (iVar3 <= iVar4) {
        pAVar5 = (ASN1_OCTET_STRING *)0x0;
        goto LAB_00593abc;
      }
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(sx->ids,iVar4);
      iVar3 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)(*puVar2,pAVar1);
      iVar4 = iVar4 + 1;
    } while (iVar3 != 0);
    pAVar5 = (ASN1_OCTET_STRING *)puVar2[1];
LAB_00593abc:
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar1);
  }
  return pAVar5;
}

