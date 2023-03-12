
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  byte *buf;
  size_t len_00;
  int *piVar1;
  BIGNUM *pBVar2;
  EC_POINT *p;
  int iVar3;
  undefined4 *key_00;
  EC_GROUP *group;
  int in_GS_OFFSET;
  undefined4 *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (undefined4 *)0x0;
  local_14 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (local_14 == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x92,0x41,"ec_asn1.c",0x466);
    key_00 = (undefined4 *)0x0;
    goto LAB_081064d4;
  }
  local_14 = (undefined4 *)
             ASN1_item_d2i((ASN1_VALUE **)&local_14,in,len,(ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (local_14 == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",0x46c);
    ASN1_item_free((ASN1_VALUE *)local_14,(ASN1_ITEM *)EC_PRIVATEKEY_it);
    key_00 = (undefined4 *)0x0;
    goto LAB_081064d4;
  }
  if (key == (EC_KEY **)0x0) {
    key_00 = (undefined4 *)EC_KEY_new();
    if (key_00 != (undefined4 *)0x0) goto LAB_081063af;
LAB_081065eb:
    key_00 = (undefined4 *)0x0;
    ERR_put_error(0x10,0x92,0x41,"ec_asn1.c",0x476);
LAB_081064bb:
    if (local_14 == (undefined4 *)0x0) goto LAB_081064d4;
  }
  else {
    key_00 = (undefined4 *)*key;
    if (key_00 == (undefined4 *)0x0) {
      key_00 = (undefined4 *)EC_KEY_new();
      if (key_00 == (undefined4 *)0x0) goto LAB_081065eb;
      *key = (EC_KEY *)key_00;
    }
LAB_081063af:
    piVar1 = (int *)local_14[2];
    if (piVar1 == (int *)0x0) {
      group = (EC_GROUP *)key_00[1];
    }
    else {
      if ((EC_GROUP *)key_00[1] == (EC_GROUP *)0x0) {
LAB_081063dc:
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          iVar3 = OBJ_obj2nid((ASN1_OBJECT *)piVar1[1]);
          group = EC_GROUP_new_by_curve_name(iVar3);
          if (group == (EC_GROUP *)0x0) {
            ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x40d);
          }
          else {
            EC_GROUP_set_asn1_flag(group,1);
          }
        }
        else if (iVar3 == 1) {
          group = (EC_GROUP *)ec_asn1_parameters2group();
          if (group == (EC_GROUP *)0x0) {
            ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x418);
          }
          else {
            EC_GROUP_set_asn1_flag(group,0);
          }
        }
        else {
          group = (EC_GROUP *)0x0;
          if (iVar3 != 2) {
            ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x423);
          }
        }
      }
      else {
        EC_GROUP_clear_free((EC_GROUP *)key_00[1]);
        piVar1 = (int *)local_14[2];
        if (piVar1 != (int *)0x0) goto LAB_081063dc;
        group = (EC_GROUP *)0x0;
        ERR_put_error(0x10,0x9e,0x7c,"ec_asn1.c",0x403);
      }
      key_00[1] = group;
    }
    if (group == (EC_GROUP *)0x0) {
      iVar3 = 0x488;
LAB_08106558:
      ERR_put_error(0x10,0x92,0x10,"ec_asn1.c",iVar3);
LAB_0810656e:
      EC_KEY_free((EC_KEY *)key_00);
      key_00 = (undefined4 *)0x0;
      goto LAB_081064bb;
    }
    piVar1 = (int *)local_14[1];
    *key_00 = *local_14;
    if (piVar1 == (int *)0x0) {
      ERR_put_error(0x10,0x92,0x7d,"ec_asn1.c",0x49e);
      goto LAB_0810656e;
    }
    pBVar2 = BN_bin2bn((uchar *)piVar1[2],*piVar1,(BIGNUM *)key_00[3]);
    key_00[3] = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x92,3,"ec_asn1.c",0x497);
      goto LAB_0810656e;
    }
    if (local_14[3] != 0) {
      if ((EC_POINT *)key_00[2] != (EC_POINT *)0x0) {
        EC_POINT_clear_free((EC_POINT *)key_00[2]);
      }
      p = EC_POINT_new((EC_GROUP *)key_00[1]);
      key_00[2] = p;
      if (p == (EC_POINT *)0x0) {
        iVar3 = 0x4ac;
      }
      else {
        buf = (byte *)((size_t *)local_14[3])[2];
        len_00 = *(size_t *)local_14[3];
        key_00[5] = *buf & 0xfffffffe;
        iVar3 = EC_POINT_oct2point((EC_GROUP *)key_00[1],p,buf,len_00,(BN_CTX *)0x0);
        if (iVar3 != 0) goto LAB_081064bb;
        iVar3 = 0x4b6;
      }
      goto LAB_08106558;
    }
  }
  ASN1_item_free((ASN1_VALUE *)local_14,(ASN1_ITEM *)EC_PRIVATEKEY_it);
LAB_081064d4:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (EC_KEY *)key_00;
}

