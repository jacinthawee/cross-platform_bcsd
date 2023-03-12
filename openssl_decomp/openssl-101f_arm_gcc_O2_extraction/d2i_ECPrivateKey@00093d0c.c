
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  int *piVar1;
  BIGNUM *pBVar2;
  EC_POINT *p;
  byte *buf;
  int iVar3;
  size_t len_00;
  undefined4 *key_00;
  int *piVar4;
  undefined4 *local_20 [3];
  
  local_20[0] = (undefined4 *)0x0;
  local_20[0] = (undefined4 *)ASN1_item_new((ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00093f88);
  if (local_20[0] == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x92,0x41,"ec_asn1.c",0x466);
    return (EC_KEY *)0x0;
  }
  local_20[0] = (undefined4 *)
                ASN1_item_d2i((ASN1_VALUE **)local_20,in,len,
                              (ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00093f88);
  if (local_20[0] == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x46c);
    ASN1_item_free((ASN1_VALUE *)local_20[0],(ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00093f88);
    return (EC_KEY *)0x0;
  }
  if (key == (EC_KEY **)0x0) {
    key_00 = (undefined4 *)EC_KEY_new();
    if (key_00 == (undefined4 *)0x0) {
LAB_00093f6a:
      key_00 = (undefined4 *)0x0;
      ERR_put_error(0x10,0x92,0x41,"ec_asn1.c",0x476);
      goto LAB_00093dea;
    }
  }
  else {
    key_00 = (undefined4 *)*key;
    if (key_00 == (undefined4 *)0x0) {
      key_00 = (undefined4 *)EC_KEY_new();
      if (key_00 == (undefined4 *)0x0) goto LAB_00093f6a;
      *key = (EC_KEY *)key_00;
    }
  }
  piVar1 = (int *)key_00[1];
  if ((int *)local_20[0][2] != (int *)0x0) {
    piVar4 = (int *)local_20[0][2];
    if (piVar1 == (int *)0x0) {
LAB_00093d64:
      iVar3 = *piVar4;
      if (iVar3 == 0) {
        iVar3 = OBJ_obj2nid((ASN1_OBJECT *)piVar4[1]);
        piVar1 = (int *)EC_GROUP_new_by_curve_name(iVar3);
        if (piVar1 == (int *)0x0) {
          ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x40d);
        }
        else {
          EC_GROUP_set_asn1_flag((EC_GROUP *)piVar1,1);
        }
      }
      else if (iVar3 == 1) {
        piVar1 = (int *)ec_asn1_parameters2group(piVar4[1]);
        if (piVar1 == (int *)0x0) {
          ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x418);
        }
        else {
          EC_GROUP_set_asn1_flag((EC_GROUP *)piVar1,0);
        }
      }
      else if (iVar3 == 2) {
        piVar1 = (int *)0x0;
      }
      else {
        ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x423);
        piVar1 = (int *)0x0;
      }
    }
    else {
      EC_GROUP_clear_free((EC_GROUP *)piVar1);
      piVar1 = (int *)local_20[0][2];
      piVar4 = piVar1;
      if (piVar1 != (int *)0x0) goto LAB_00093d64;
      ERR_put_error(0x10,0x9e,0x7c,"ec_asn1.c",0x403);
    }
    key_00[1] = piVar1;
  }
  if (piVar1 == (int *)0x0) {
    ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x488);
  }
  else {
    piVar1 = (int *)local_20[0][1];
    *key_00 = *local_20[0];
    if (piVar1 == (int *)0x0) {
      ERR_put_error(0x10,0x92,0x7d,"ec_asn1.c",0x49e);
    }
    else {
      pBVar2 = BN_bin2bn((uchar *)piVar1[2],*piVar1,(BIGNUM *)key_00[3]);
      key_00[3] = pBVar2;
      if (pBVar2 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x92,3,"ec_asn1.c",0x497);
      }
      else {
        if (local_20[0][3] == 0) goto LAB_00093dea;
        if ((EC_POINT *)key_00[2] != (EC_POINT *)0x0) {
          EC_POINT_clear_free((EC_POINT *)key_00[2]);
        }
        p = EC_POINT_new((EC_GROUP *)key_00[1]);
        key_00[2] = p;
        if (p == (EC_POINT *)0x0) {
          ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x4ac);
        }
        else {
          buf = (byte *)((size_t *)local_20[0][3])[2];
          len_00 = *(size_t *)local_20[0][3];
          key_00[5] = *buf & 0xfffffffe;
          iVar3 = EC_POINT_oct2point((EC_GROUP *)key_00[1],p,buf,len_00,(BN_CTX *)0x0);
          if (iVar3 != 0) goto LAB_00093dea;
          ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x4b6);
        }
      }
    }
  }
  EC_KEY_free((EC_KEY *)key_00);
  key_00 = (undefined4 *)0x0;
LAB_00093dea:
  if (local_20[0] != (undefined4 *)0x0) {
    ASN1_item_free((ASN1_VALUE *)local_20[0],(ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00093f88);
    return (EC_KEY *)key_00;
  }
  return (EC_KEY *)key_00;
}

