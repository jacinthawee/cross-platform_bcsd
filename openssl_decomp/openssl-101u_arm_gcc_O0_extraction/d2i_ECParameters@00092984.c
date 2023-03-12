
EC_KEY * d2i_ECParameters(EC_KEY **key,uchar **in,long len)

{
  int *val;
  EC_GROUP *group;
  int iVar1;
  EC_KEY *key_00;
  uchar *local_1c;
  
  if ((in == (uchar **)0x0) || (local_1c = *in, local_1c == (uchar *)0x0)) {
    ERR_put_error(0x10,0x90,0x43,"ec_asn1.c",0x4d6);
    return (EC_KEY *)0x0;
  }
  if ((key == (EC_KEY **)0x0) || (key_00 = *key, key_00 == (EC_KEY *)0x0)) {
    key_00 = EC_KEY_new();
    if (key_00 == (EC_KEY *)0x0) {
      ERR_put_error(0x10,0x90,0x41,"ec_asn1.c",0x4dc);
      return (EC_KEY *)0x0;
    }
    local_1c = *in;
  }
  val = (int *)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_1c,len,
                             (ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092b1c);
  if (val == (int *)0x0) {
    ERR_put_error(0x10,0x91,0x75,"ec_asn1.c",0x3d0);
    ASN1_item_free((ASN1_VALUE *)0x0,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092b1c);
  }
  else {
    iVar1 = *val;
    if (iVar1 == 0) {
      iVar1 = OBJ_obj2nid((ASN1_OBJECT *)val[1]);
      group = EC_GROUP_new_by_curve_name(iVar1);
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,1);
LAB_00092a44:
        if (*(EC_GROUP **)(key_00 + 4) != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*(EC_GROUP **)(key_00 + 4));
        }
        *(EC_GROUP **)(key_00 + 4) = group;
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092b1c);
        *in = local_1c;
        if (key != (EC_KEY **)0x0) {
          *key = key_00;
          return key_00;
        }
        return key_00;
      }
      ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x3b1);
    }
    else if (iVar1 == 1) {
      group = (EC_GROUP *)ec_asn1_parameters2group(val[1]);
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,0);
        goto LAB_00092a44;
      }
      ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x3b9);
    }
    else if (iVar1 != 2) {
      ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x3c0);
    }
    ERR_put_error(0x10,0x91,0x7f,"ec_asn1.c",0x3d6);
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092b1c);
  }
  ERR_put_error(0x10,0x90,0x10,"ec_asn1.c",0x4e3);
  if ((key == (EC_KEY **)0x0) || (*key != key_00)) {
    EC_KEY_free(key_00);
  }
  return (EC_KEY *)0x0;
}

