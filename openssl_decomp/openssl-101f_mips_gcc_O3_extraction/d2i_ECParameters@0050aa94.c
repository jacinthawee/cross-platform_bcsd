
EC_KEY * d2i_ECParameters(EC_KEY **key,uchar **in,long len)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  EC_GROUP *group;
  undefined4 uVar5;
  EC_KEY *pEVar6;
  
  if ((in == (uchar **)0x0) || (*in == (uchar *)0x0)) {
    uVar5 = 0x43;
    uVar4 = 0x548;
    goto LAB_0050accc;
  }
  if (key == (EC_KEY **)0x0) {
    pEVar6 = EC_KEY_new();
    if (pEVar6 == (EC_KEY *)0x0) {
LAB_0050acb8:
      uVar5 = 0x41;
      uVar4 = 0x550;
LAB_0050accc:
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x90,uVar5,"ec_asn1.c",uVar4);
      return (EC_KEY *)0x0;
    }
  }
  else {
    pEVar6 = *key;
    if (pEVar6 == (EC_KEY *)0x0) {
      pEVar6 = EC_KEY_new();
      if (pEVar6 == (EC_KEY *)0x0) goto LAB_0050acb8;
      *key = pEVar6;
    }
  }
  piVar2 = (int *)(*(code *)PTR_ASN1_item_d2i_006a9798)(0,in,len,ECPKPARAMETERS_it);
  if (piVar2 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x91,0x75,"ec_asn1.c",0x433);
    (*(code *)PTR_ASN1_item_free_006a977c)(0,ECPKPARAMETERS_it);
    goto LAB_0050ab74;
  }
  iVar3 = *piVar2;
  if (iVar3 == 0) {
    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(piVar2[1]);
    group = EC_GROUP_new_by_curve_name(iVar3);
    if (group != (EC_GROUP *)0x0) {
      EC_GROUP_set_asn1_flag(group,1);
LAB_0050abf8:
      if (*(EC_GROUP **)(pEVar6 + 4) != (EC_GROUP *)0x0) {
        EC_GROUP_clear_free(*(EC_GROUP **)(pEVar6 + 4));
      }
      puVar1 = PTR_ASN1_item_free_006a977c;
      *(EC_GROUP **)(pEVar6 + 4) = group;
      (*(code *)puVar1)(piVar2,ECPKPARAMETERS_it);
      return pEVar6;
    }
    uVar5 = 0x77;
    uVar4 = 0x40d;
LAB_0050ab28:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9e,uVar5,"ec_asn1.c",uVar4);
  }
  else {
    if (iVar3 == 1) {
      group = (EC_GROUP *)ec_asn1_parameters2group(piVar2[1]);
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,0);
        goto LAB_0050abf8;
      }
      uVar5 = 0x10;
      uVar4 = 0x418;
      goto LAB_0050ab28;
    }
    if (iVar3 != 2) {
      uVar5 = 0x73;
      uVar4 = 0x423;
      goto LAB_0050ab28;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x91,0x7f,"ec_asn1.c",0x43a);
  (*(code *)PTR_ASN1_item_free_006a977c)(piVar2,ECPKPARAMETERS_it);
LAB_0050ab74:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x90,0x10,"ec_asn1.c",0x55b);
  return (EC_KEY *)0x0;
}

