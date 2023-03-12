
EC_GROUP * d2i_ECPKParameters(EC_GROUP **param_1,uchar **in,long len)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  EC_GROUP *group;
  undefined4 uVar4;
  
  piVar1 = (int *)(*(code *)PTR_ASN1_item_d2i_006a9798)(0,in,len,ECPKPARAMETERS_it);
  if (piVar1 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x91,0x75,"ec_asn1.c",0x433);
    (*(code *)PTR_ASN1_item_free_006a977c)(0,ECPKPARAMETERS_it);
    return (EC_GROUP *)0x0;
  }
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(piVar1[1]);
    group = EC_GROUP_new_by_curve_name(iVar2);
    if (group != (EC_GROUP *)0x0) {
      EC_GROUP_set_asn1_flag(group,1);
LAB_00509be4:
      if (param_1 != (EC_GROUP **)0x0) {
        if (*param_1 != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*param_1);
        }
        *param_1 = group;
      }
      (*(code *)PTR_ASN1_item_free_006a977c)(piVar1,ECPKPARAMETERS_it);
      return group;
    }
    uVar4 = 0x77;
    uVar3 = 0x40d;
  }
  else if (iVar2 == 1) {
    group = (EC_GROUP *)ec_asn1_parameters2group(piVar1[1]);
    if (group != (EC_GROUP *)0x0) {
      EC_GROUP_set_asn1_flag(group,0);
      goto LAB_00509be4;
    }
    uVar4 = 0x10;
    uVar3 = 0x418;
  }
  else {
    if (iVar2 == 2) goto LAB_00509b48;
    uVar4 = 0x73;
    uVar3 = 0x423;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9e,uVar4,"ec_asn1.c",uVar3);
LAB_00509b48:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x91,0x7f,"ec_asn1.c",0x43a);
  (*(code *)PTR_ASN1_item_free_006a977c)(piVar1,ECPKPARAMETERS_it);
  return (EC_GROUP *)0x0;
}

