
int i2d_ECPrivateKey(EC_KEY *key,uchar **out)

{
  EC_GROUP *group;
  bool bVar1;
  undefined4 *val;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  uint uVar5;
  ASN1_STRING *pAVar6;
  size_t sVar7;
  uchar *buf;
  ASN1_OBJECT *pAVar8;
  int *val_00;
  uint len;
  int iVar9;
  
  if (((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (*(int *)(key + 0xc) == 0)) {
    ERR_put_error(0x10,0xc0,0x43,"ec_asn1.c",0x4d4);
    return 0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x4db);
    return 0;
  }
  *val = *(undefined4 *)key;
  iVar2 = BN_num_bits(*(BIGNUM **)(key + 0xc));
  iVar4 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar4 = iVar2 + 7;
  }
  len = iVar4 >> 3;
  puVar3 = (uchar *)CRYPTO_malloc(len,"ec_asn1.c",0x4e2);
  if (puVar3 == (uchar *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x4e6);
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)EC_PRIVATEKEY_it);
    return 0;
  }
  iVar4 = BN_bn2bin(*(BIGNUM **)(key + 0xc),puVar3);
  if (iVar4 == 0) {
    iVar2 = 0x4ec;
    iVar4 = 3;
  }
  else {
    iVar4 = ASN1_STRING_set((ASN1_STRING *)val[1],puVar3,len);
    if (iVar4 == 0) {
      iVar2 = 0x4f2;
      iVar4 = 0xd;
    }
    else {
      uVar5 = *(uint *)(key + 0x10);
      if ((uVar5 & 1) == 0) {
        val_00 = (int *)val[2];
        group = *(EC_GROUP **)(key + 4);
        if (val_00 == (int *)0x0) {
          val_00 = (int *)ASN1_item_new((ASN1_ITEM *)ECPKPARAMETERS_it);
          if (val_00 != (int *)0x0) goto LAB_08106a2f;
          ERR_put_error(0x10,0x9c,0x41,"ec_asn1.c",0x2c0);
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
LAB_08106a2f:
          iVar4 = EC_GROUP_get_asn1_flag(group);
          if (iVar4 == 0) {
            *val_00 = 1;
            pAVar8 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_3();
            val_00[1] = (int)pAVar8;
joined_r0x08106aac:
            if (pAVar8 != (ASN1_OBJECT *)0x0) {
              val[2] = val_00;
              uVar5 = *(uint *)(key + 0x10);
              goto LAB_08106853;
            }
          }
          else {
            iVar4 = EC_GROUP_get_curve_name(group);
            if (iVar4 != 0) {
              *val_00 = 0;
              pAVar8 = OBJ_nid2obj(iVar4);
              val_00[1] = (int)pAVar8;
              goto joined_r0x08106aac;
            }
          }
          ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)ECPKPARAMETERS_it);
        }
        val[2] = 0;
        iVar2 = 0x4fb;
LAB_081068e1:
        iVar4 = 0x10;
      }
      else {
LAB_08106853:
        buf = puVar3;
        if ((uVar5 & 2) != 0) {
LAB_08106930:
          bVar1 = true;
          iVar9 = ASN1_item_i2d((ASN1_VALUE *)val,out,(ASN1_ITEM *)EC_PRIVATEKEY_it);
          if (iVar9 == 0) {
            bVar1 = false;
            ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x52c);
          }
          goto LAB_081067d4;
        }
        pAVar6 = ASN1_STRING_type_new(3);
        val[3] = pAVar6;
        if (pAVar6 == (ASN1_STRING *)0x0) {
          iVar2 = 0x506;
          iVar4 = 0x41;
        }
        else {
          sVar7 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                     *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,
                                     (BN_CTX *)0x0);
          if ((len < sVar7) &&
             (buf = (uchar *)CRYPTO_realloc(puVar3,sVar7,"ec_asn1.c",0x50f), len = sVar7,
             buf == (uchar *)0x0)) {
            iVar2 = 0x512;
            iVar4 = 0x41;
          }
          else {
            sVar7 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                       *(point_conversion_form_t *)(key + 0x14),buf,len,
                                       (BN_CTX *)0x0);
            puVar3 = buf;
            if (sVar7 == 0) {
              iVar2 = 0x51c;
              goto LAB_081068e1;
            }
            pAVar6 = (ASN1_STRING *)val[3];
            pAVar6->flags = pAVar6->flags & 0xfffffff0U | 8;
            iVar4 = ASN1_STRING_set(pAVar6,buf,len);
            if (iVar4 != 0) goto LAB_08106930;
            iVar2 = 0x525;
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
LAB_081067d4:
  CRYPTO_free(buf);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (!bVar1) {
    return 0;
  }
  return iVar9;
}

