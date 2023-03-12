
int i2d_ECPrivateKey(EC_KEY *key,uchar **out)

{
  undefined4 *val;
  BIGNUM *a;
  int iVar1;
  ASN1_STRING *pAVar2;
  ASN1_STRING *pAVar3;
  size_t num;
  ASN1_STRING *pAVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  uint uVar7;
  ASN1_STRING *buf;
  uint len;
  int *val_00;
  EC_GROUP *group;
  
  if (((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (*(int *)(key + 0xc) == 0)) {
    ERR_put_error(0x10,0xc0,0x43,"ec_asn1.c",0x4d4);
    return 0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00094280);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x4db);
    return 0;
  }
  a = *(BIGNUM **)(key + 0xc);
  *val = *(undefined4 *)key;
  iVar1 = BN_num_bits(a);
  iVar6 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar6 = iVar1 + 7;
  }
  len = iVar6 >> 3;
  pAVar2 = (ASN1_STRING *)CRYPTO_malloc(len,"ec_asn1.c",0x4e2);
  if (pAVar2 == (ASN1_STRING *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x4e6);
    pAVar4 = pAVar2;
    goto LAB_00094010;
  }
  pAVar3 = (ASN1_STRING *)BN_bn2bin(*(BIGNUM **)(key + 0xc),(uchar *)pAVar2);
  if (pAVar3 == (ASN1_STRING *)0x0) {
    ERR_put_error(0x10,0xc0,3,"ec_asn1.c",0x4ec);
    pAVar4 = pAVar3;
  }
  else {
    pAVar3 = (ASN1_STRING *)ASN1_STRING_set((ASN1_STRING *)val[1],pAVar2,len);
    if (pAVar3 == (ASN1_STRING *)0x0) {
      iVar6 = 0x4f2;
LAB_00094110:
      ERR_put_error(0x10,0xc0,0xd,"ec_asn1.c",iVar6);
      pAVar4 = pAVar3;
    }
    else {
      uVar7 = *(uint *)(key + 0x10);
      if ((int)(uVar7 << 0x1f) < 0) {
LAB_00094058:
        buf = pAVar2;
        if ((uVar7 & 2) == 0) {
          pAVar3 = ASN1_STRING_type_new(3);
          val[3] = pAVar3;
          if (pAVar3 == (ASN1_STRING *)0x0) {
            iVar6 = 0x506;
          }
          else {
            num = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                     *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,
                                     (BN_CTX *)0x0);
            if ((num <= len) ||
               (pAVar3 = (ASN1_STRING *)CRYPTO_realloc(pAVar2,num,"ec_asn1.c",0x50f), buf = pAVar3,
               len = num, pAVar3 != (ASN1_STRING *)0x0)) {
              pAVar3 = (ASN1_STRING *)
                       EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                          *(point_conversion_form_t *)(key + 0x14),(uchar *)buf,len,
                                          (BN_CTX *)0x0);
              if (pAVar3 == (ASN1_STRING *)0x0) {
                ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x51c);
                pAVar2 = buf;
                pAVar4 = pAVar3;
                goto LAB_0009400a;
              }
              pAVar2 = (ASN1_STRING *)val[3];
              pAVar2->flags = pAVar2->flags & 0xfffffff0U | 8;
              pAVar3 = (ASN1_STRING *)ASN1_STRING_set(pAVar2,buf,len);
              if (pAVar3 == (ASN1_STRING *)0x0) {
                iVar6 = 0x525;
                pAVar2 = buf;
                goto LAB_00094110;
              }
              goto LAB_00094120;
            }
            iVar6 = 0x512;
          }
          ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",iVar6);
          pAVar4 = pAVar3;
        }
        else {
LAB_00094120:
          pAVar4 = (ASN1_STRING *)
                   ASN1_item_i2d((ASN1_VALUE *)val,out,(ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00094280);
          pAVar3 = (ASN1_STRING *)0x1;
          pAVar2 = buf;
          if (pAVar4 == (ASN1_STRING *)0x0) {
            ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x52c);
            pAVar3 = pAVar4;
          }
        }
      }
      else {
        val_00 = (int *)val[2];
        group = *(EC_GROUP **)(key + 4);
        if (val_00 == (int *)0x0) {
          val_00 = (int *)ASN1_item_new((ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00094284);
          if (val_00 != (int *)0x0) goto LAB_000941a8;
          ERR_put_error(0x10,0x9c,0x41,"ec_asn1.c",0x2c0);
        }
        else {
          if (*val_00 == 0) {
            if ((ASN1_OBJECT *)val_00[1] != (ASN1_OBJECT *)0x0) {
              ASN1_OBJECT_free((ASN1_OBJECT *)val_00[1]);
            }
          }
          else if ((*val_00 == 1) && ((ASN1_VALUE *)val_00[1] != (ASN1_VALUE *)0x0)) {
            ASN1_item_free((ASN1_VALUE *)val_00[1],(ASN1_ITEM *)&ECPARAMETERS_it);
          }
LAB_000941a8:
          iVar6 = EC_GROUP_get_asn1_flag(group);
          if (iVar6 == 0) {
            *val_00 = 1;
            pAVar5 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_0(group);
            val_00[1] = (int)pAVar5;
joined_r0x000941f4:
            if (pAVar5 != (ASN1_OBJECT *)0x0) {
              val[2] = val_00;
              uVar7 = *(uint *)(key + 0x10);
              goto LAB_00094058;
            }
          }
          else {
            iVar6 = EC_GROUP_get_curve_name(group);
            if (iVar6 != 0) {
              *val_00 = 0;
              pAVar5 = OBJ_nid2obj(iVar6);
              val_00[1] = (int)pAVar5;
              goto joined_r0x000941f4;
            }
          }
          ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00094284);
        }
        pAVar3 = (ASN1_STRING *)0x0;
        val[2] = 0;
        pAVar4 = (ASN1_STRING *)0x0;
        ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x4fb);
      }
    }
  }
LAB_0009400a:
  CRYPTO_free(pAVar2);
  pAVar2 = pAVar3;
LAB_00094010:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00094280);
  if (pAVar2 == (ASN1_STRING *)0x0) {
    return 0;
  }
  return (int)pAVar4;
}

