
ASN1_OCTET_STRING * SXNET_get_id_ulong(SXNET *sx,ulong lzone)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  ASN1_OCTET_STRING *pAVar5;
  
  iVar1 = (*(code *)PTR_ASN1_STRING_type_new_006a8680)(2);
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar1,lzone);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(sx->ids);
        if (iVar4 <= iVar2) {
          pAVar5 = (ASN1_OCTET_STRING *)0x0;
          goto LAB_00590e44;
        }
        puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(sx->ids,iVar2);
        iVar4 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)(*puVar3,iVar1);
        iVar2 = iVar2 + 1;
      } while (iVar4 != 0);
      pAVar5 = (ASN1_OCTET_STRING *)puVar3[1];
LAB_00590e44:
      (*(code *)PTR_ASN1_STRING_free_006a879c)(iVar1);
      return pAVar5;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x81,0x41,"v3_sxnet.c",0xfa);
  (*(code *)PTR_ASN1_STRING_free_006a879c)(iVar1);
  return (ASN1_OCTET_STRING *)0x0;
}

