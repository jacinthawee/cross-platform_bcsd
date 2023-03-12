
int i2d_ECParameters(EC_KEY *key,uchar **out)

{
  undefined4 *val;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  EC_GROUP *group;
  
  if (key == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0xbe,0x43,"ec_asn1.c",0x4cb);
    return 0;
  }
  group = *(EC_GROUP **)(key + 4);
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092980);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x9c,0x41,"ec_asn1.c",0x28d);
    goto LAB_000928f4;
  }
  iVar1 = EC_GROUP_get_asn1_flag(group);
  if (iVar1 == 0) {
    *val = 1;
    pAVar2 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_0(group);
    val[1] = pAVar2;
joined_r0x00092942:
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      iVar1 = ASN1_item_i2d((ASN1_VALUE *)val,out,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092980);
      if (iVar1 != 0) {
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092980);
        return iVar1;
      }
      ERR_put_error(0x10,0xbf,0x79,"ec_asn1.c",0x3ee);
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092980);
      return 0;
    }
  }
  else {
    iVar1 = EC_GROUP_get_curve_name(group);
    if (iVar1 != 0) {
      *val = 0;
      pAVar2 = OBJ_nid2obj(iVar1);
      val[1] = pAVar2;
      goto joined_r0x00092942;
    }
  }
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092980);
LAB_000928f4:
  ERR_put_error(0x10,0xbf,0x78,"ec_asn1.c",0x3ea);
  return 0;
}

