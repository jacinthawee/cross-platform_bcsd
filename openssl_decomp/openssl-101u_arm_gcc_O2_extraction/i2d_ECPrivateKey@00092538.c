
int i2d_ECPrivateKey(EC_KEY *key,uchar **out)

{
  undefined4 *val;
  BIGNUM *a;
  int iVar1;
  ASN1_STRING *pAVar2;
  size_t num;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  uint uVar5;
  ASN1_STRING *pAVar6;
  uint len;
  ASN1_STRING *pAVar7;
  int *val_00;
  ASN1_STRING *buf;
  EC_GROUP *group;
  
  if ((((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (*(int *)(key + 0xc) == 0)) ||
     ((-1 < *(int *)(key + 0x10) << 0x1e && (*(int *)(key + 8) == 0)))) {
    ERR_put_error(0x10,0xc0,0x43,"ec_asn1.c",0x466);
    return 0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00092890);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x46b);
    return 0;
  }
  a = *(BIGNUM **)(key + 0xc);
  *val = *(undefined4 *)key;
  iVar1 = BN_num_bits(a);
  iVar4 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar4 = iVar1 + 7;
  }
  iVar1 = EC_GROUP_get_degree(*(EC_GROUP **)(key + 4));
  uVar5 = iVar4 >> 3;
  iVar4 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar4 = iVar1 + 7;
  }
  len = iVar4 >> 3;
  if (len < uVar5) {
    ERR_put_error(0x10,0xc0,100,"ec_asn1.c",0x478);
  }
  else {
    pAVar2 = (ASN1_STRING *)CRYPTO_malloc(len,"ec_asn1.c",0x47c);
    if (pAVar2 != (ASN1_STRING *)0x0) {
      pAVar6 = (ASN1_STRING *)
               BN_bn2bin(*(BIGNUM **)(key + 0xc),(uchar *)((int)pAVar2 + (len - uVar5)));
      if (pAVar6 == (ASN1_STRING *)0x0) {
        ERR_put_error(0x10,0xc0,3,"ec_asn1.c",0x483);
        pAVar7 = pAVar6;
      }
      else {
        if (len != uVar5) {
          memset(pAVar2,0,len - uVar5);
        }
        pAVar6 = (ASN1_STRING *)ASN1_STRING_set((ASN1_STRING *)val[1],pAVar2,len);
        if (pAVar6 == (ASN1_STRING *)0x0) {
          iVar4 = 0x48c;
LAB_00092760:
          ERR_put_error(0x10,0xc0,0xd,"ec_asn1.c",iVar4);
          pAVar7 = pAVar6;
        }
        else {
          uVar5 = *(uint *)(key + 0x10);
          if ((int)(uVar5 << 0x1f) < 0) {
LAB_00092626:
            buf = pAVar2;
            if ((uVar5 & 2) == 0) {
              pAVar6 = ASN1_STRING_type_new(3);
              val[3] = pAVar6;
              if (pAVar6 == (ASN1_STRING *)0x0) {
                iVar4 = 0x49c;
              }
              else {
                num = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                         *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,
                                         (BN_CTX *)0x0);
                if ((num <= len) ||
                   (pAVar6 = (ASN1_STRING *)CRYPTO_realloc(pAVar2,num,"ec_asn1.c",0x4a4),
                   buf = pAVar6, len = num, pAVar6 != (ASN1_STRING *)0x0)) {
                  pAVar6 = (ASN1_STRING *)
                           EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                              *(point_conversion_form_t *)(key + 0x14),(uchar *)buf,
                                              len,(BN_CTX *)0x0);
                  pAVar2 = buf;
                  if (pAVar6 == (ASN1_STRING *)0x0) {
                    ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x4af);
                    pAVar7 = pAVar6;
                    goto LAB_000926e4;
                  }
                  pAVar6 = (ASN1_STRING *)val[3];
                  pAVar6->flags = pAVar6->flags & 0xfffffff0U | 8;
                  pAVar6 = (ASN1_STRING *)ASN1_STRING_set(pAVar6,buf,len);
                  if (pAVar6 == (ASN1_STRING *)0x0) {
                    iVar4 = 0x4b6;
                    goto LAB_00092760;
                  }
                  goto LAB_00092706;
                }
                iVar4 = 0x4a6;
              }
              ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",iVar4);
              pAVar7 = pAVar6;
            }
            else {
LAB_00092706:
              pAVar7 = (ASN1_STRING *)
                       ASN1_item_i2d((ASN1_VALUE *)val,out,
                                     (ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00092890);
              pAVar6 = (ASN1_STRING *)0x1;
              pAVar2 = buf;
              if (pAVar7 == (ASN1_STRING *)0x0) {
                ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x4bc);
                pAVar6 = pAVar7;
              }
            }
          }
          else {
            val_00 = (int *)val[2];
            group = *(EC_GROUP **)(key + 4);
            if (val_00 == (int *)0x0) {
              val_00 = (int *)ASN1_item_new((ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092894);
              if (val_00 != (int *)0x0) goto LAB_000927aa;
              ERR_put_error(0x10,0x9c,0x41,"ec_asn1.c",0x28d);
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
LAB_000927aa:
              iVar4 = EC_GROUP_get_asn1_flag(group);
              if (iVar4 == 0) {
                *val_00 = 1;
                pAVar3 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_0(group);
                val_00[1] = (int)pAVar3;
joined_r0x00092822:
                if (pAVar3 != (ASN1_OBJECT *)0x0) {
                  val[2] = val_00;
                  uVar5 = *(uint *)(key + 0x10);
                  goto LAB_00092626;
                }
              }
              else {
                iVar4 = EC_GROUP_get_curve_name(group);
                if (iVar4 != 0) {
                  *val_00 = 0;
                  pAVar3 = OBJ_nid2obj(iVar4);
                  val_00[1] = (int)pAVar3;
                  goto joined_r0x00092822;
                }
              }
              ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)PTR_ECPKPARAMETERS_it_00092894);
            }
            pAVar6 = (ASN1_STRING *)0x0;
            val[2] = 0;
            ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x494);
            pAVar7 = (ASN1_STRING *)0x0;
          }
        }
      }
LAB_000926e4:
      CRYPTO_free(pAVar2);
      goto LAB_000925c0;
    }
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x47e);
  }
  pAVar6 = (ASN1_STRING *)0x0;
  pAVar7 = (ASN1_STRING *)0x0;
LAB_000925c0:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_EC_PRIVATEKEY_it_00092890);
  if (pAVar6 == (ASN1_STRING *)0x0) {
    return 0;
  }
  return (int)pAVar7;
}

