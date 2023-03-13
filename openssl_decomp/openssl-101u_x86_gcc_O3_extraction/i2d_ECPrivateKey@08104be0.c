
int i2d_ECPrivateKey(EC_KEY *key,uchar **out)

{
  EC_GROUP *group;
  bool bVar1;
  undefined4 *val;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  ASN1_STRING *pAVar5;
  size_t sVar6;
  uchar *buf;
  ASN1_OBJECT *pAVar7;
  int *val_00;
  uint uVar8;
  int iVar9;
  uint local_24;
  
  if ((((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (*(int *)(key + 0xc) == 0)) ||
     ((((byte)key[0x10] & 2) == 0 && (*(int *)(key + 8) == 0)))) {
    ERR_put_error(0x10,0xc0,0x43,"ec_asn1.c",0x466);
    return 0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x46b);
    return 0;
  }
  *val = *(undefined4 *)key;
  iVar2 = BN_num_bits(*(BIGNUM **)(key + 0xc));
  iVar4 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar4 = iVar2 + 7;
  }
  uVar8 = iVar4 >> 3;
  iVar2 = EC_GROUP_get_degree(*(EC_GROUP **)(key + 4));
  iVar4 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar4 = iVar2 + 7;
  }
  local_24 = iVar4 >> 3;
  if (local_24 < uVar8) {
    ERR_put_error(0x10,0xc0,100,"ec_asn1.c",0x478);
LAB_08104c95:
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)EC_PRIVATEKEY_it);
    return 0;
  }
  puVar3 = (uchar *)CRYPTO_malloc(local_24,"ec_asn1.c",0x47c);
  if (puVar3 == (uchar *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x47e);
    goto LAB_08104c95;
  }
  iVar4 = BN_bn2bin(*(BIGNUM **)(key + 0xc),puVar3 + (local_24 - uVar8));
  if (iVar4 == 0) {
    iVar2 = 0x483;
    iVar4 = 3;
  }
  else {
    if (uVar8 != local_24) {
      memset(puVar3,0,local_24 - uVar8);
    }
    iVar4 = ASN1_STRING_set((ASN1_STRING *)val[1],puVar3,local_24);
    if (iVar4 == 0) {
      iVar2 = 0x48c;
      iVar4 = 0xd;
    }
    else {
      uVar8 = *(uint *)(key + 0x10);
      if ((uVar8 & 1) == 0) {
        val_00 = (int *)val[2];
        group = *(EC_GROUP **)(key + 4);
        if (val_00 == (int *)0x0) {
          val_00 = (int *)ASN1_item_new((ASN1_ITEM *)ECPKPARAMETERS_it);
          if (val_00 != (int *)0x0) goto LAB_08104f47;
          ERR_put_error(0x10,0x9c,0x41,"ec_asn1.c",0x28d);
        }
        else {
          if (*val_00 == 0) {
            if ((ASN1_OBJECT *)val_00[1] != (ASN1_OBJECT *)0x0) {
              ASN1_OBJECT_free((ASN1_OBJECT *)val_00[1]);
            }
          }
          else if ((*val_00 == 1) && ((ASN1_VALUE *)val_00[1] != (ASN1_VALUE *)0x0)) {
            ASN1_item_free((ASN1_VALUE *)val_00[1],(ASN1_ITEM *)ECPARAMETERS_it);
          }
LAB_08104f47:
          iVar4 = EC_GROUP_get_asn1_flag(group);
          if (iVar4 == 0) {
            *val_00 = 1;
            pAVar7 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_3();
            val_00[1] = (int)pAVar7;
joined_r0x0810500c:
            if (pAVar7 != (ASN1_OBJECT *)0x0) {
              val[2] = val_00;
              uVar8 = *(uint *)(key + 0x10);
              goto LAB_08104d30;
            }
          }
          else {
            iVar4 = EC_GROUP_get_curve_name(group);
            if (iVar4 != 0) {
              *val_00 = 0;
              pAVar7 = OBJ_nid2obj(iVar4);
              val_00[1] = (int)pAVar7;
              goto joined_r0x0810500c;
            }
          }
          ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)ECPKPARAMETERS_it);
        }
        val[2] = 0;
        iVar2 = 0x494;
LAB_08104dc3:
        iVar4 = 0x10;
      }
      else {
LAB_08104d30:
        buf = puVar3;
        if ((uVar8 & 2) != 0) {
LAB_08104e70:
          bVar1 = true;
          iVar9 = ASN1_item_i2d((ASN1_VALUE *)val,out,(ASN1_ITEM *)EC_PRIVATEKEY_it);
          if (iVar9 == 0) {
            bVar1 = false;
            ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x4bc);
          }
          goto LAB_08104e1a;
        }
        pAVar5 = ASN1_STRING_type_new(3);
        val[3] = pAVar5;
        if (pAVar5 == (ASN1_STRING *)0x0) {
          iVar2 = 0x49c;
          iVar4 = 0x41;
        }
        else {
          sVar6 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                     *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,
                                     (BN_CTX *)0x0);
          if ((local_24 < sVar6) &&
             (buf = (uchar *)CRYPTO_realloc(puVar3,sVar6,"ec_asn1.c",0x4a4), local_24 = sVar6,
             buf == (uchar *)0x0)) {
            iVar2 = 0x4a6;
            iVar4 = 0x41;
          }
          else {
            sVar6 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                       *(point_conversion_form_t *)(key + 0x14),buf,local_24,
                                       (BN_CTX *)0x0);
            puVar3 = buf;
            if (sVar6 == 0) {
              iVar2 = 0x4af;
              goto LAB_08104dc3;
            }
            pAVar5 = (ASN1_STRING *)val[3];
            pAVar5->flags = pAVar5->flags & 0xfffffff0U | 8;
            iVar4 = ASN1_STRING_set(pAVar5,buf,local_24);
            if (iVar4 != 0) goto LAB_08104e70;
            iVar2 = 0x4b6;
            iVar4 = 0xd;
          }
        }
      }
    }
  }
  bVar1 = false;
  iVar9 = 0;
  ERR_put_error(0x10,0xc0,iVar4,"ec_asn1.c",iVar2);
  buf = puVar3;
LAB_08104e1a:
  CRYPTO_free(buf);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (!bVar1) {
    return 0;
  }
  return iVar9;
}

