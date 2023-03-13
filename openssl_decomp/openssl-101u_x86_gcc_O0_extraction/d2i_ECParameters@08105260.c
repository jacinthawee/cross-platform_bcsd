
EC_KEY * d2i_ECParameters(EC_KEY **key,uchar **in,long len)

{
  uchar *puVar1;
  int *val;
  EC_KEY *key_00;
  EC_GROUP *group;
  int in_GS_OFFSET;
  int line;
  int iVar2;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((in == (uchar **)0x0) || (puVar1 = *in, puVar1 == (uchar *)0x0)) {
    line = 0x4d6;
    iVar2 = 0x43;
LAB_08105440:
    ERR_put_error(0x10,0x90,iVar2,"ec_asn1.c",line);
    key_00 = (EC_KEY *)0x0;
    goto LAB_081053da;
  }
  if ((key == (EC_KEY **)0x0) || (key_00 = *key, key_00 == (EC_KEY *)0x0)) {
    key_00 = EC_KEY_new();
    if (key_00 == (EC_KEY *)0x0) {
      line = 0x4dc;
      iVar2 = 0x41;
      goto LAB_08105440;
    }
    puVar1 = *in;
  }
  local_24 = puVar1;
  val = (int *)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_24,len,(ASN1_ITEM *)ECPKPARAMETERS_it);
  if (val == (int *)0x0) {
    ERR_put_error(0x10,0x91,0x75,"ec_asn1.c",0x3d0);
    ASN1_item_free((ASN1_VALUE *)0x0,(ASN1_ITEM *)ECPKPARAMETERS_it);
  }
  else {
    iVar2 = *val;
    if (iVar2 == 0) {
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)val[1]);
      group = EC_GROUP_new_by_curve_name(iVar2);
      if (group != (EC_GROUP *)0x0) {
        iVar2 = 1;
LAB_0810538b:
        EC_GROUP_set_asn1_flag(group,iVar2);
        if (*(EC_GROUP **)(key_00 + 4) != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*(EC_GROUP **)(key_00 + 4));
        }
        *(EC_GROUP **)(key_00 + 4) = group;
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)ECPKPARAMETERS_it);
        *in = local_24;
        if (key != (EC_KEY **)0x0) {
          *key = key_00;
        }
        goto LAB_081053da;
      }
      ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x3b1);
    }
    else if (iVar2 == 1) {
      group = (EC_GROUP *)ec_asn1_parameters2group();
      if (group != (EC_GROUP *)0x0) {
        iVar2 = 0;
        goto LAB_0810538b;
      }
      ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x3b9);
    }
    else if (iVar2 != 2) {
      ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x3c0);
    }
    ERR_put_error(0x10,0x91,0x7f,"ec_asn1.c",0x3d6);
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)ECPKPARAMETERS_it);
  }
  ERR_put_error(0x10,0x90,0x10,"ec_asn1.c",0x4e3);
  if ((key == (EC_KEY **)0x0) || (*key != key_00)) {
    EC_KEY_free(key_00);
    key_00 = (EC_KEY *)0x0;
  }
  else {
    key_00 = (EC_KEY *)0x0;
  }
LAB_081053da:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return key_00;
}

