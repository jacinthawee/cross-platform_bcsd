
EC_GROUP * d2i_ECPKParameters(EC_GROUP **param_1,uchar **in,long len)

{
  int *val;
  int iVar1;
  EC_GROUP *group;
  
  val = (int *)ASN1_item_d2i((ASN1_VALUE **)0x0,in,len,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00093c40);
  if (val == (int *)0x0) {
    ERR_put_error(0x10,0x91,0x75,"ec_asn1.c",0x433);
    ASN1_item_free((ASN1_VALUE *)0x0,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00093c40);
    return (EC_GROUP *)0x0;
  }
  iVar1 = *val;
  if (iVar1 == 0) {
    iVar1 = OBJ_obj2nid((ASN1_OBJECT *)val[1]);
    group = EC_GROUP_new_by_curve_name(iVar1);
    if (group != (EC_GROUP *)0x0) {
      EC_GROUP_set_asn1_flag(group,1);
LAB_00093bc4:
      if (param_1 != (EC_GROUP **)0x0) {
        if (*param_1 != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*param_1);
        }
        *param_1 = group;
      }
      goto LAB_00093ba2;
    }
    ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x40d);
  }
  else if (iVar1 == 1) {
    group = (EC_GROUP *)ec_asn1_parameters2group(val[1]);
    if (group != (EC_GROUP *)0x0) {
      EC_GROUP_set_asn1_flag(group,0);
      goto LAB_00093bc4;
    }
    ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x418);
  }
  else if (iVar1 != 2) {
    ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x423);
  }
  group = (EC_GROUP *)0x0;
  ERR_put_error(0x10,0x91,0x7f,"ec_asn1.c",0x43a);
LAB_00093ba2:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00093c40);
  return group;
}

