
int i2d_ECPKParameters(EC_GROUP *param_1,uchar **out)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(ECPKPARAMETERS_it);
  if (puVar2 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9c,0x41,"ec_asn1.c",0x2c0);
    goto LAB_00509dd0;
  }
  iVar3 = EC_GROUP_get_asn1_flag(param_1);
  if (iVar3 == 0) {
    *puVar2 = 1;
    iVar3 = ec_asn1_group2parameters_constprop_3(param_1);
    puVar2[1] = iVar3;
joined_r0x00509e80:
    if (iVar3 != 0) {
      iVar3 = (*(code *)PTR_ASN1_item_i2d_006a979c)(puVar2,out,ECPKPARAMETERS_it);
      if (iVar3 != 0) {
        (*(code *)PTR_ASN1_item_free_006a977c)(puVar2,ECPKPARAMETERS_it);
        return iVar3;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbf,0x79,"ec_asn1.c",0x454);
      (*(code *)PTR_ASN1_item_free_006a977c)(puVar2,ECPKPARAMETERS_it);
      return 0;
    }
  }
  else {
    iVar3 = EC_GROUP_get_curve_name(param_1);
    puVar1 = PTR_OBJ_nid2obj_006a8240;
    if (iVar3 != 0) {
      *puVar2 = 0;
      iVar3 = (*(code *)puVar1)(iVar3);
      puVar2[1] = iVar3;
      goto joined_r0x00509e80;
    }
  }
  (*(code *)PTR_ASN1_item_free_006a977c)(puVar2,ECPKPARAMETERS_it);
LAB_00509dd0:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbf,0x78,"ec_asn1.c",0x44f);
  return 0;
}

