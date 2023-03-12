
int SXNET_add_id_INTEGER(SXNET **psx,ASN1_INTEGER *izone,char *user,int userlen)

{
  undefined4 *puVar1;
  int iVar2;
  ASN1_INTEGER **ppAVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  SXNET *pSVar7;
  
  if (((psx == (SXNET **)0x0) || (izone == (ASN1_INTEGER *)0x0)) || (user == (char *)0x0)) {
    uVar6 = 0x6b;
    uVar5 = 0xbe;
    goto LAB_005908e4;
  }
  if (userlen == -1) {
    userlen = (*(code *)PTR_strlen_006a9a24)(user);
    if (0x40 < userlen) goto LAB_00590944;
  }
  else if (0x40 < userlen) {
LAB_00590944:
    uVar6 = 0x84;
    uVar5 = 0xc4;
LAB_005908e4:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7e,uVar6,"v3_sxnet.c",uVar5);
    return 0;
  }
  pSVar7 = *psx;
  if (pSVar7 == (SXNET *)0x0) {
    pSVar7 = (SXNET *)(*(code *)PTR_ASN1_item_new_006a8654)(SXNET_it);
    if ((pSVar7 == (SXNET *)0x0) ||
       (iVar4 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(pSVar7->version,0), iVar4 == 0)) {
      ppAVar3 = (ASN1_INTEGER **)0x0;
      goto LAB_005907f0;
    }
    *psx = pSVar7;
  }
  iVar4 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(pSVar7->ids);
    if (iVar2 <= iVar4) goto LAB_005907a8;
    puVar1 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(pSVar7->ids,iVar4);
    iVar2 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)(*puVar1,izone);
    iVar4 = iVar4 + 1;
  } while (iVar2 != 0);
  if (puVar1[1] != 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7e,0x85,"v3_sxnet.c",0xd0);
    return 0;
  }
LAB_005907a8:
  ppAVar3 = (ASN1_INTEGER **)(*(code *)PTR_ASN1_item_new_006a8654)(SXNETID_it);
  if (ppAVar3 != (ASN1_INTEGER **)0x0) {
    if (userlen == -1) {
      userlen = (*(code *)PTR_strlen_006a9a24)(user);
    }
    iVar4 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(ppAVar3[1],user,userlen);
    if ((iVar4 != 0) && (iVar4 = (*(code *)PTR_sk_push_006a6fa8)(pSVar7->ids,ppAVar3), iVar4 != 0))
    {
      *ppAVar3 = izone;
      return 1;
    }
  }
LAB_005907f0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x7e,0x41,"v3_sxnet.c",0xe1);
  (*(code *)PTR_ASN1_item_free_006a8658)(ppAVar3,SXNETID_it);
  (*(code *)PTR_ASN1_item_free_006a8658)(pSVar7,SXNET_it);
  *psx = (SXNET *)0x0;
  return 0;
}
