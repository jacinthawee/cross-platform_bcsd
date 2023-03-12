
EC_KEY * d2i_ECParameters(EC_KEY **key,uchar **in,long len)

{
  int *val;
  EC_GROUP *group;
  int iVar1;
  EC_KEY *pEVar2;
  
  if ((in == (uchar **)0x0) || (*in == (uchar *)0x0)) {
    ERR_put_error(0x10,0x90,0x43,"ec_asn1.c",0x548);
    return (EC_KEY *)0x0;
  }
  if (key == (EC_KEY **)0x0) {
    pEVar2 = EC_KEY_new();
    if (pEVar2 == (EC_KEY *)0x0) {
LAB_000944c6:
      ERR_put_error(0x10,0x90,0x41,"ec_asn1.c",0x550);
      return (EC_KEY *)0x0;
    }
  }
  else {
    pEVar2 = *key;
    if (pEVar2 == (EC_KEY *)0x0) {
      pEVar2 = EC_KEY_new();
      if (pEVar2 == (EC_KEY *)0x0) goto LAB_000944c6;
      *key = pEVar2;
    }
  }
  val = (int *)ASN1_item_d2i((ASN1_VALUE **)0x0,in,len,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_000944f8);
  if (val == (int *)0x0) {
    ERR_put_error(0x10,0x91,0x75,"ec_asn1.c",0x433);
    ASN1_item_free((ASN1_VALUE *)0x0,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_000944f8);
  }
  else {
    iVar1 = *val;
    if (iVar1 == 0) {
      iVar1 = OBJ_obj2nid((ASN1_OBJECT *)val[1]);
      group = EC_GROUP_new_by_curve_name(iVar1);
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,1);
LAB_00094416:
        if (*(EC_GROUP **)(pEVar2 + 4) != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*(EC_GROUP **)(pEVar2 + 4));
        }
        *(EC_GROUP **)(pEVar2 + 4) = group;
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_000944f8);
        return pEVar2;
      }
      ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x40d);
    }
    else if (iVar1 == 1) {
      group = (EC_GROUP *)ec_asn1_parameters2group(val[1]);
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,0);
        goto LAB_00094416;
      }
      ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x418);
    }
    else if (iVar1 != 2) {
      ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x423);
    }
    ERR_put_error(0x10,0x91,0x7f,"ec_asn1.c",0x43a);
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_000944f8);
  }
  ERR_put_error(0x10,0x90,0x10,"ec_asn1.c",0x55b);
  return (EC_KEY *)0x0;
}

