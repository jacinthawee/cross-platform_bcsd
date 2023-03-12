
EC_KEY * d2i_ECParameters(EC_KEY **key,uchar **in,long len)

{
  int *val;
  EC_KEY *pEVar1;
  EC_GROUP *group;
  int iVar2;
  int line;
  
  if ((in == (uchar **)0x0) || (*in == (uchar *)0x0)) {
    line = 0x548;
    iVar2 = 0x43;
    goto LAB_08106dda;
  }
  if (key == (EC_KEY **)0x0) {
    pEVar1 = EC_KEY_new();
    if (pEVar1 == (EC_KEY *)0x0) {
LAB_08106e9f:
      line = 0x550;
      iVar2 = 0x41;
      goto LAB_08106dda;
    }
  }
  else {
    pEVar1 = *key;
    if (pEVar1 == (EC_KEY *)0x0) {
      pEVar1 = EC_KEY_new();
      if (pEVar1 == (EC_KEY *)0x0) goto LAB_08106e9f;
      *key = pEVar1;
    }
  }
  val = (int *)ASN1_item_d2i((ASN1_VALUE **)0x0,in,len,(ASN1_ITEM *)ECPKPARAMETERS_it);
  if (val == (int *)0x0) {
    ERR_put_error(0x10,0x91,0x75,"ec_asn1.c",0x433);
    ASN1_item_free((ASN1_VALUE *)0x0,(ASN1_ITEM *)ECPKPARAMETERS_it);
  }
  else {
    iVar2 = *val;
    if (iVar2 == 0) {
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)val[1]);
      group = EC_GROUP_new_by_curve_name(iVar2);
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,1);
LAB_08106e1e:
        if (*(EC_GROUP **)(pEVar1 + 4) != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*(EC_GROUP **)(pEVar1 + 4));
        }
        *(EC_GROUP **)(pEVar1 + 4) = group;
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)ECPKPARAMETERS_it);
        return pEVar1;
      }
      ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x40d);
    }
    else if (iVar2 == 1) {
      group = (EC_GROUP *)ec_asn1_parameters2group();
      if (group != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag(group,0);
        goto LAB_08106e1e;
      }
      ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x418);
    }
    else if (iVar2 != 2) {
      ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x423);
    }
    ERR_put_error(0x10,0x91,0x7f,"ec_asn1.c",0x43a);
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)ECPKPARAMETERS_it);
  }
  line = 0x55b;
  iVar2 = 0x10;
LAB_08106dda:
  ERR_put_error(0x10,0x90,iVar2,"ec_asn1.c",line);
  return (EC_KEY *)0x0;
}

