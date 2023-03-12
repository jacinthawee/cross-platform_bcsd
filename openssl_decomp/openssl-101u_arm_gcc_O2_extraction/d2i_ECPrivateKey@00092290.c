
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  undefined4 *val;
  int *piVar1;
  BIGNUM *pBVar2;
  EC_POINT *r;
  byte *buf;
  int iVar3;
  size_t len_00;
  undefined4 *key_00;
  undefined4 *puVar4;
  int *piVar5;
  size_t *psVar6;
  uchar *local_1c;
  
  local_1c = *in;
  val = (undefined4 *)
        ASN1_item_d2i((ASN1_VALUE **)0x0,&local_1c,len,(ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00092534);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x400);
    return (EC_KEY *)0x0;
  }
  if (((key == (EC_KEY **)0x0) ||
      (key_00 = (undefined4 *)*key, (undefined4 *)*key == (undefined4 *)0x0)) &&
     (puVar4 = (undefined4 *)EC_KEY_new(), key_00 = puVar4, puVar4 == (undefined4 *)0x0)) {
    ERR_put_error(0x10,0x92,0x41,"ec_asn1.c",0x406);
    goto LAB_00092370;
  }
  piVar1 = (int *)key_00[1];
  if ((int *)val[2] != (int *)0x0) {
    piVar5 = (int *)val[2];
    if (piVar1 == (int *)0x0) {
LAB_000922d2:
      iVar3 = *piVar5;
      if (iVar3 == 0) {
        iVar3 = OBJ_obj2nid((ASN1_OBJECT *)piVar5[1]);
        piVar1 = (int *)EC_GROUP_new_by_curve_name(iVar3);
        if (piVar1 != (int *)0x0) {
          EC_GROUP_set_asn1_flag((EC_GROUP *)piVar1,1);
          key_00[1] = piVar1;
          goto LAB_00092302;
        }
        ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x3b1);
      }
      else if (iVar3 == 1) {
        piVar1 = (int *)ec_asn1_parameters2group(piVar5[1]);
        if (piVar1 == (int *)0x0) {
          ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x3b9);
        }
        else {
          EC_GROUP_set_asn1_flag((EC_GROUP *)piVar1,0);
        }
      }
      else if (iVar3 == 2) {
        piVar1 = (int *)0x0;
      }
      else {
        ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x3c0);
        piVar1 = (int *)0x0;
      }
    }
    else {
      EC_GROUP_clear_free((EC_GROUP *)piVar1);
      piVar1 = (int *)val[2];
      piVar5 = piVar1;
      if (piVar1 != (int *)0x0) goto LAB_000922d2;
      ERR_put_error(0x10,0x9e,0x7c,"ec_asn1.c",0x3a9);
    }
    key_00[1] = piVar1;
  }
LAB_00092302:
  if (piVar1 == (int *)0x0) {
    ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x413);
  }
  else {
    piVar1 = (int *)val[1];
    *key_00 = *val;
    if (piVar1 == (int *)0x0) {
      ERR_put_error(0x10,0x92,0x7d,"ec_asn1.c",0x422);
    }
    else {
      pBVar2 = BN_bin2bn((uchar *)piVar1[2],*piVar1,(BIGNUM *)key_00[3]);
      key_00[3] = pBVar2;
      if (pBVar2 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x92,3,"ec_asn1.c",0x41e);
      }
      else {
        if ((EC_POINT *)key_00[2] != (EC_POINT *)0x0) {
          EC_POINT_clear_free((EC_POINT *)key_00[2]);
        }
        r = EC_POINT_new((EC_GROUP *)key_00[1]);
        key_00[2] = r;
        if (r == (EC_POINT *)0x0) {
          ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x42a);
        }
        else {
          psVar6 = (size_t *)val[3];
          if (psVar6 == (size_t *)0x0) {
            iVar3 = EC_POINT_mul((EC_GROUP *)key_00[1],r,(BIGNUM *)key_00[3],(EC_POINT *)0x0,
                                 (BIGNUM *)0x0,(BN_CTX *)0x0);
            if (iVar3 != 0) {
              key_00[4] = key_00[4] | 2;
LAB_00092366:
              if (key != (EC_KEY **)0x0) {
                *key = (EC_KEY *)key_00;
              }
              *in = local_1c;
              puVar4 = key_00;
              goto LAB_00092370;
            }
            ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x445);
          }
          else {
            len_00 = *psVar6;
            buf = (byte *)psVar6[2];
            if ((int)len_00 < 1) {
              ERR_put_error(0x10,0x92,100,"ec_asn1.c",0x438);
            }
            else {
              key_00[5] = *buf & 0xfffffffe;
              iVar3 = EC_POINT_oct2point((EC_GROUP *)key_00[1],r,buf,len_00,(BN_CTX *)0x0);
              if (iVar3 != 0) goto LAB_00092366;
              ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x43f);
            }
          }
        }
      }
    }
  }
  if ((key == (EC_KEY **)0x0) || (key_00 != (undefined4 *)*key)) {
    puVar4 = (undefined4 *)0x0;
    EC_KEY_free((EC_KEY *)key_00);
  }
  else {
    puVar4 = (undefined4 *)0x0;
  }
LAB_00092370:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00092534);
  return (EC_KEY *)puVar4;
}

