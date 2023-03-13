
ASN1_OCTET_STRING * SXNET_get_id_INTEGER(SXNET *sx,ASN1_INTEGER *zone)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(sx->ids);
    if (iVar2 <= iVar3) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    puVar1 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(sx->ids,iVar3);
    iVar2 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)(*puVar1,zone);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  return (ASN1_OCTET_STRING *)puVar1[1];
}

