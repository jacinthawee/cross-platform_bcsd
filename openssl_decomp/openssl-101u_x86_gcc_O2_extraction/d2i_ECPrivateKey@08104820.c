
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  size_t *psVar1;
  size_t len_00;
  byte *buf;
  undefined4 *val;
  int *piVar2;
  EC_GROUP *group;
  BIGNUM *pBVar3;
  EC_POINT *r;
  int iVar4;
  undefined4 *key_00;
  undefined4 *puVar5;
  int in_GS_OFFSET;
  int line;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *in;
  val = (undefined4 *)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_24,len,(ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x400);
    puVar5 = (undefined4 *)0x0;
    goto LAB_081049a6;
  }
  if ((key == (EC_KEY **)0x0) ||
     (key_00 = (undefined4 *)*key, (undefined4 *)*key == (undefined4 *)0x0)) {
    puVar5 = (undefined4 *)EC_KEY_new();
    key_00 = puVar5;
    if (puVar5 != (undefined4 *)0x0) goto LAB_08104876;
    ERR_put_error(0x10,0x92,0x41,"ec_asn1.c",0x406);
  }
  else {
LAB_08104876:
    piVar2 = (int *)val[2];
    if (piVar2 == (int *)0x0) {
      group = (EC_GROUP *)key_00[1];
    }
    else {
      if ((EC_GROUP *)key_00[1] == (EC_GROUP *)0x0) {
LAB_0810489f:
        iVar4 = *piVar2;
        if (iVar4 == 0) {
          iVar4 = OBJ_obj2nid((ASN1_OBJECT *)piVar2[1]);
          group = EC_GROUP_new_by_curve_name(iVar4);
          if (group == (EC_GROUP *)0x0) {
            line = 0x3b1;
            iVar4 = 0x77;
            goto LAB_08104ba1;
          }
          iVar4 = 1;
        }
        else {
          if (iVar4 != 1) {
            group = (EC_GROUP *)0x0;
            if (iVar4 != 2) {
              ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x3c0);
              group = (EC_GROUP *)0x0;
            }
            goto LAB_081048df;
          }
          group = (EC_GROUP *)ec_asn1_parameters2group();
          if (group == (EC_GROUP *)0x0) {
            line = 0x3b9;
            iVar4 = 0x10;
            goto LAB_08104ba1;
          }
          iVar4 = 0;
        }
        EC_GROUP_set_asn1_flag(group,iVar4);
      }
      else {
        EC_GROUP_clear_free((EC_GROUP *)key_00[1]);
        piVar2 = (int *)val[2];
        if (piVar2 != (int *)0x0) goto LAB_0810489f;
        line = 0x3a9;
        iVar4 = 0x7c;
LAB_08104ba1:
        ERR_put_error(0x10,0x9e,iVar4,"ec_asn1.c",line);
        group = (EC_GROUP *)0x0;
      }
LAB_081048df:
      key_00[1] = group;
    }
    if (group == (EC_GROUP *)0x0) {
      iVar4 = 0x413;
      goto LAB_08104aa8;
    }
    *key_00 = *val;
    piVar2 = (int *)val[1];
    if (piVar2 == (int *)0x0) {
      ERR_put_error(0x10,0x92,0x7d,"ec_asn1.c",0x422);
    }
    else {
      pBVar3 = BN_bin2bn((uchar *)piVar2[2],*piVar2,(BIGNUM *)key_00[3]);
      key_00[3] = pBVar3;
      if (pBVar3 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x92,3,"ec_asn1.c",0x41e);
      }
      else {
        if ((EC_POINT *)key_00[2] != (EC_POINT *)0x0) {
          EC_POINT_clear_free((EC_POINT *)key_00[2]);
        }
        r = EC_POINT_new((EC_GROUP *)key_00[1]);
        key_00[2] = r;
        if (r != (EC_POINT *)0x0) {
          psVar1 = (size_t *)val[3];
          if (psVar1 == (size_t *)0x0) {
            iVar4 = EC_POINT_mul((EC_GROUP *)key_00[1],r,(BIGNUM *)key_00[3],(EC_POINT *)0x0,
                                 (BIGNUM *)0x0,(BN_CTX *)0x0);
            if (iVar4 == 0) {
              iVar4 = 0x445;
              goto LAB_08104aa8;
            }
            key_00[4] = key_00[4] | 2;
          }
          else {
            len_00 = *psVar1;
            if ((int)len_00 < 1) {
              ERR_put_error(0x10,0x92,100,"ec_asn1.c",0x438);
              goto LAB_08104a56;
            }
            buf = (byte *)psVar1[2];
            key_00[5] = *buf & 0xfffffffe;
            iVar4 = EC_POINT_oct2point((EC_GROUP *)key_00[1],r,buf,len_00,(BN_CTX *)0x0);
            if (iVar4 == 0) {
              iVar4 = 0x43f;
              goto LAB_08104aa8;
            }
          }
          if (key != (EC_KEY **)0x0) {
            *key = (EC_KEY *)key_00;
          }
          *in = local_24;
          puVar5 = key_00;
          goto LAB_08104993;
        }
        iVar4 = 0x42a;
LAB_08104aa8:
        ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",iVar4);
      }
    }
LAB_08104a56:
    if ((key == (EC_KEY **)0x0) || (key_00 != (undefined4 *)*key)) {
      puVar5 = (undefined4 *)0x0;
      EC_KEY_free((EC_KEY *)key_00);
    }
    else {
      puVar5 = (undefined4 *)0x0;
    }
  }
LAB_08104993:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)EC_PRIVATEKEY_it);
LAB_081049a6:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (EC_KEY *)puVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

