
int i2d_ECParameters(EC_KEY *key,uchar **out)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  EC_GROUP *group;
  
  if (key == (EC_KEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbe,0x43,"ec_asn1.c",0x4cb);
    return 0;
  }
  group = *(EC_GROUP **)(key + 4);
  puVar2 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(ECPKPARAMETERS_it);
  if (puVar2 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9c,0x41,"ec_asn1.c",0x28d);
    goto LAB_005086f4;
  }
  iVar3 = EC_GROUP_get_asn1_flag(group);
  if (iVar3 == 0) {
    *puVar2 = 1;
    iVar3 = ec_asn1_group2parameters_constprop_3(group);
    puVar2[1] = iVar3;
joined_r0x0050878c:
    if (iVar3 != 0) {
      iVar3 = (*(code *)PTR_ASN1_item_i2d_006a8678)(puVar2,out,ECPKPARAMETERS_it);
      if (iVar3 != 0) {
        (*(code *)PTR_ASN1_item_free_006a8658)(puVar2,ECPKPARAMETERS_it);
        return iVar3;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbf,0x79,"ec_asn1.c",0x3ee);
      (*(code *)PTR_ASN1_item_free_006a8658)(puVar2,ECPKPARAMETERS_it);
      return 0;
    }
  }
  else {
    iVar3 = EC_GROUP_get_curve_name(group);
    puVar1 = PTR_OBJ_nid2obj_006a7140;
    if (iVar3 != 0) {
      *puVar2 = 0;
      iVar3 = (*(code *)puVar1)(iVar3);
      puVar2[1] = iVar3;
      goto joined_r0x0050878c;
    }
  }
  (*(code *)PTR_ASN1_item_free_006a8658)(puVar2,ECPKPARAMETERS_it);
LAB_005086f4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbf,0x78,"ec_asn1.c",0x3ea);
  return 0;
}

