
ASN1_VALUE * ec_asn1_group2parameters_constprop_0(EC_GROUP *param_1)

{
  BIGNUM *order;
  ASN1_VALUE *val;
  EC_METHOD *pEVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  char *pcVar4;
  BIGNUM *a;
  BIGNUM *b;
  int iVar5;
  ASN1_VALUE *p;
  point_conversion_form_t form;
  ASN1_VALUE *len;
  ASN1_OBJECT *pAVar6;
  ASN1_VALUE *buf;
  size_t sVar7;
  ASN1_STRING *str;
  BIGNUM *to;
  ASN1_INTEGER *pAVar8;
  uchar *to_00;
  void *data;
  char **ppcVar9;
  ASN1_OBJECT **ppAVar10;
  ASN1_STRING **ppAVar11;
  BIGNUM *num;
  BIGNUM *str_00;
  uchar *local_38;
  BIGNUM *local_34;
  uchar local_30 [12];
  
  order = BN_new();
  if (order == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",0x249);
    return (ASN1_VALUE *)0x0;
  }
  val = ASN1_item_new((ASN1_ITEM *)&ECPARAMETERS_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",0x252);
    buf = val;
    goto LAB_00093418;
  }
  ppAVar10 = *(ASN1_OBJECT ***)(val + 4);
  *(undefined4 *)&val->field_0x0 = 1;
  if (ppAVar10 == (ASN1_OBJECT **)0x0 || param_1 == (EC_GROUP *)0x0) {
LAB_0009342e:
    p = (ASN1_VALUE *)0x0;
    ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",0x25f);
  }
  else {
    if (*ppAVar10 != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(*ppAVar10);
    }
    if (ppAVar10[1] != (ASN1_OBJECT *)0x0) {
      ASN1_TYPE_free((ASN1_TYPE *)ppAVar10[1]);
    }
    pEVar1 = EC_GROUP_method_of(param_1);
    iVar2 = EC_METHOD_get_field_type(pEVar1);
    pAVar3 = OBJ_nid2obj(iVar2);
    *ppAVar10 = pAVar3;
    if (pAVar3 == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0x10,0x9a,8,"ec_asn1.c",0x13e);
    }
    else if (iVar2 == 0x196) {
      pAVar6 = (ASN1_OBJECT *)BN_new();
      iVar2 = 0x146;
      pAVar3 = pAVar6;
      if (pAVar6 == (ASN1_OBJECT *)0x0) {
LAB_00093844:
        ERR_put_error(0x10,0x9a,0x41,"ec_asn1.c",iVar2);
      }
      else {
        pAVar3 = (ASN1_OBJECT *)
                 EC_GROUP_get_curve_GFp
                           (param_1,(BIGNUM *)pAVar6,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
        if (pAVar3 == (ASN1_OBJECT *)0x0) {
          ERR_put_error(0x10,0x9a,0x10,"ec_asn1.c",0x14c);
        }
        else {
          pAVar3 = (ASN1_OBJECT *)BN_to_ASN1_INTEGER((BIGNUM *)pAVar6,(ASN1_INTEGER *)0x0);
          ppAVar10[1] = pAVar3;
          if (pAVar3 == (ASN1_OBJECT *)0x0) {
            ERR_put_error(0x10,0x9a,0xd,"ec_asn1.c",0x153);
          }
          else {
            pAVar3 = (ASN1_OBJECT *)0x1;
          }
        }
        BN_free((BIGNUM *)pAVar6);
      }
    }
    else {
      pAVar3 = (ASN1_OBJECT *)ASN1_item_new((ASN1_ITEM *)PTR_X9_62_CHARACTERISTIC_TWO_it_00093560);
      ppAVar10[1] = pAVar3;
      if (pAVar3 == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0x10,0x9a,0x41,"ec_asn1.c",0x167);
      }
      else {
        pcVar4 = (char *)EC_GROUP_get_degree(param_1);
        pAVar3->sn = pcVar4;
        pEVar1 = EC_GROUP_method_of(param_1);
        iVar2 = EC_METHOD_get_field_type(pEVar1);
        if (((iVar2 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) && (*(int *)(param_1 + 0x60) != 0)
           ) {
          if (*(int *)(param_1 + 100) == 0) {
            pAVar6 = OBJ_nid2obj(0x2aa);
            pAVar3->ln = &pAVar6->sn;
            if (pAVar6 == (ASN1_OBJECT *)0x0) {
LAB_0009398a:
              ERR_put_error(0x10,0x9a,8,"ec_asn1.c",0x177);
              pAVar3 = (ASN1_OBJECT *)0x0;
            }
            else {
              pEVar1 = EC_GROUP_method_of(param_1);
              iVar2 = EC_METHOD_get_field_type(pEVar1);
              if (((iVar2 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) &&
                 ((iVar2 = *(int *)(param_1 + 0x60), iVar2 != 0 && (*(int *)(param_1 + 100) == 0))))
              {
                pAVar6 = (ASN1_OBJECT *)ASN1_INTEGER_new();
                pAVar3->nid = (int)pAVar6;
                if (pAVar6 == (ASN1_OBJECT *)0x0) {
                  iVar2 = 0x185;
                  pAVar3 = pAVar6;
                  goto LAB_00093844;
                }
                pAVar6 = (ASN1_OBJECT *)ASN1_INTEGER_set((ASN1_INTEGER *)pAVar6,iVar2);
                pAVar3 = (ASN1_OBJECT *)0x1;
                if (pAVar6 == (ASN1_OBJECT *)0x0) {
                  ERR_put_error(0x10,0x9a,0xd,"ec_asn1.c",0x18b);
                  pAVar3 = pAVar6;
                }
              }
              else {
                ERR_put_error(0x10,0xc2,0x42,"ec_asn1.c",0x60);
                pAVar3 = (ASN1_OBJECT *)0x0;
              }
            }
          }
          else {
            if ((*(int *)(param_1 + 0x68) == 0) || (*(int *)(param_1 + 0x6c) != 0))
            goto LAB_00093246;
            pAVar6 = OBJ_nid2obj(0x2ab);
            pAVar3->ln = &pAVar6->sn;
            if (pAVar6 == (ASN1_OBJECT *)0x0) goto LAB_0009398a;
            pEVar1 = EC_GROUP_method_of(param_1);
            iVar2 = EC_METHOD_get_field_type(pEVar1);
            if (((((iVar2 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) &&
                 (iVar2 = *(int *)(param_1 + 0x60), iVar2 != 0)) &&
                ((ppcVar9 = *(char ***)(param_1 + 100), ppcVar9 != (char **)0x0 &&
                 (pcVar4 = *(char **)(param_1 + 0x68), pcVar4 != (char *)0x0)))) &&
               (*(int *)(param_1 + 0x6c) == 0)) {
              pAVar6 = (ASN1_OBJECT *)ASN1_item_new((ASN1_ITEM *)PTR_X9_62_PENTANOMIAL_it_00093564);
              pAVar3->nid = (int)pAVar6;
              if (pAVar6 == (ASN1_OBJECT *)0x0) {
                ERR_put_error(0x10,0x9a,0x41,"ec_asn1.c",0x199);
                pAVar3 = pAVar6;
              }
              else {
                pAVar6->sn = pcVar4;
                pAVar6->ln = ppcVar9;
                pAVar6->nid = iVar2;
                pAVar3 = (ASN1_OBJECT *)0x1;
              }
            }
            else {
              ERR_put_error(0x10,0xc1,0x42,"ec_asn1.c",0x73);
              pAVar3 = (ASN1_OBJECT *)0x0;
            }
          }
        }
        else {
LAB_00093246:
          ERR_put_error(0x10,0x9a,0x10,"ec_asn1.c",0x171);
          pAVar3 = (ASN1_OBJECT *)0x0;
        }
      }
    }
    if (pAVar3 == (ASN1_OBJECT *)0x0) goto LAB_0009342e;
    ppAVar11 = *(ASN1_STRING ***)(val + 8);
    local_30[0] = '\0';
    if (((ppAVar11 == (ASN1_STRING **)0x0) || (*ppAVar11 == (ASN1_STRING *)0x0)) ||
       (ppAVar11[1] == (ASN1_STRING *)0x0)) {
LAB_000933ee:
      p = (ASN1_VALUE *)0x0;
      ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",0x266);
    }
    else {
      a = BN_new();
      if ((a == (BIGNUM *)0x0) || (b = BN_new(), b == (BIGNUM *)0x0)) {
        b = (BIGNUM *)0x0;
        ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x1c4);
LAB_00093554:
        if (a != (BIGNUM *)0x0) {
          str_00 = (BIGNUM *)0x0;
          goto LAB_00093384;
        }
      }
      else {
        pEVar1 = EC_GROUP_method_of(param_1);
        iVar2 = EC_METHOD_get_field_type(pEVar1);
        if (iVar2 == 0x196) {
          iVar2 = EC_GROUP_get_curve_GFp(param_1,(BIGNUM *)0x0,a,b,(BN_CTX *)0x0);
          if (iVar2 != 0) goto LAB_000932c6;
          ERR_put_error(0x10,0x99,0x10,"ec_asn1.c",0x1cf);
          goto LAB_00093554;
        }
        iVar2 = EC_GROUP_get_curve_GF2m();
        if (iVar2 == 0) {
          ERR_put_error(0x10,0x99,0x10,"ec_asn1.c",0x1d8);
          goto LAB_00093554;
        }
LAB_000932c6:
        iVar5 = BN_num_bits(a);
        iVar2 = iVar5 + 0xe;
        if (-1 < iVar5 + 7) {
          iVar2 = iVar5 + 7;
        }
        iVar5 = BN_num_bits(b);
        to_00 = (uchar *)(iVar2 >> 3);
        iVar2 = iVar5 + 0xe;
        if (-1 < iVar5 + 7) {
          iVar2 = iVar5 + 7;
        }
        num = (BIGNUM *)(iVar2 >> 3);
        if (to_00 == (uchar *)0x0) {
          str_00 = (BIGNUM *)0x1;
          local_38 = local_30;
LAB_000932fe:
          if (num == (BIGNUM *)0x0) {
            to = (BIGNUM *)local_30;
            local_34 = (BIGNUM *)0x1;
LAB_0009330e:
            iVar2 = ASN1_STRING_set(*ppAVar11,local_38,(int)str_00);
            if ((iVar2 == 0) || (iVar2 = ASN1_STRING_set(ppAVar11[1],to,(int)local_34), iVar2 == 0))
            {
              iVar2 = 0x210;
LAB_00093748:
              ERR_put_error(0x10,0x99,0xd,"ec_asn1.c",iVar2);
              str_00 = (BIGNUM *)0x0;
              to = num;
            }
            else {
              data = *(void **)(param_1 + 0x3c);
              if (data == (void *)0x0) {
                str_00 = (BIGNUM *)0x1;
                to = num;
                if (ppAVar11[2] != (ASN1_BIT_STRING *)0x0) {
                  ASN1_BIT_STRING_free(ppAVar11[2]);
                  ppAVar11[2] = (ASN1_STRING *)0x0;
                }
              }
              else {
                str_00 = (BIGNUM *)ppAVar11[2];
                if (str_00 == (BIGNUM *)0x0) {
                  str_00 = (BIGNUM *)ASN1_BIT_STRING_new();
                  ppAVar11[2] = (ASN1_STRING *)str_00;
                  if (str_00 == (BIGNUM *)0x0) {
                    ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x21a);
                    to = num;
                    goto LAB_0009336c;
                  }
                  data = *(void **)(param_1 + 0x3c);
                }
                iVar2 = *(int *)(param_1 + 0x40);
                str_00->neg = str_00->neg & 0xfffffff0U | 8;
                iVar5 = ASN1_BIT_STRING_set((ASN1_STRING *)str_00,data,iVar2);
                iVar2 = 0x222;
                if (iVar5 == 0) goto LAB_00093748;
                str_00 = (BIGNUM *)0x1;
                to = num;
              }
            }
          }
          else {
            to = (BIGNUM *)CRYPTO_malloc((int)num,"ec_asn1.c",0x1fe);
            if (to == (BIGNUM *)0x0) {
              ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x201);
              str_00 = to;
            }
            else {
              local_34 = (BIGNUM *)BN_bn2bin(b,(uchar *)to);
              num = to;
              if (local_34 != (BIGNUM *)0x0) goto LAB_0009330e;
              ERR_put_error(0x10,0x99,3,"ec_asn1.c",0x206);
              str_00 = local_34;
            }
          }
LAB_0009336c:
          if (to_00 != (uchar *)0x0) goto LAB_00093372;
        }
        else {
          to_00 = (uchar *)CRYPTO_malloc((int)to_00,"ec_asn1.c",0x1e8);
          if (to_00 == (uchar *)0x0) {
            ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x1eb);
            goto LAB_00093554;
          }
          str_00 = (BIGNUM *)BN_bn2bin(a,to_00);
          local_38 = to_00;
          if (str_00 != (BIGNUM *)0x0) goto LAB_000932fe;
          ERR_put_error(0x10,0x99,3,"ec_asn1.c",0x1f0);
          to = str_00;
LAB_00093372:
          CRYPTO_free(to_00);
        }
        if (to != (BIGNUM *)0x0) {
          CRYPTO_free(to);
        }
LAB_00093384:
        BN_free(a);
        a = str_00;
      }
      if (b != (BIGNUM *)0x0) {
        BN_free(b);
      }
      if (a == (BIGNUM *)0x0) goto LAB_000933ee;
      p = (ASN1_VALUE *)EC_GROUP_get0_generator(param_1);
      if (p == (ASN1_VALUE *)0x0) {
        ERR_put_error(0x10,0x9b,0x71,"ec_asn1.c",0x26d);
      }
      else {
        form = EC_GROUP_get_point_conversion_form(param_1);
        len = (ASN1_VALUE *)
              EC_POINT_point2oct(param_1,(EC_POINT *)p,form,(uchar *)0x0,0,(BN_CTX *)0x0);
        if (len == (ASN1_VALUE *)0x0) {
          ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",0x276);
          p = len;
        }
        else {
          buf = (ASN1_VALUE *)CRYPTO_malloc((int)len,"ec_asn1.c",0x279);
          iVar2 = 0x27b;
          if (buf == (ASN1_VALUE *)0x0) {
LAB_0009372e:
            ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",iVar2);
            p = buf;
          }
          else {
            sVar7 = EC_POINT_point2oct(param_1,(EC_POINT *)p,form,(uchar *)buf,(size_t)len,
                                       (BN_CTX *)0x0);
            if (sVar7 == 0) {
              ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",0x280);
              p = buf;
            }
            else {
              str = *(ASN1_STRING **)(val + 0xc);
              if (str == (ASN1_STRING *)0x0) {
                str = ASN1_OCTET_STRING_new();
                *(ASN1_STRING **)(val + 0xc) = str;
                if (str == (ASN1_OCTET_STRING *)0x0) {
                  iVar2 = 0x285;
                  goto LAB_0009372e;
                }
              }
              iVar2 = ASN1_OCTET_STRING_set(str,buf,(int)len);
              iVar5 = 0x28a;
              if (iVar2 != 0) {
                iVar2 = EC_GROUP_get_order(param_1,order,(BN_CTX *)0x0);
                if (iVar2 == 0) {
                  ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",0x291);
                  p = buf;
                  goto LAB_00093408;
                }
                pAVar8 = BN_to_ASN1_INTEGER(order,*(ASN1_INTEGER **)(val + 0x10));
                iVar5 = 0x297;
                *(ASN1_INTEGER **)(val + 0x10) = pAVar8;
                if (pAVar8 != (ASN1_INTEGER *)0x0) {
                  iVar2 = EC_GROUP_get_cofactor(param_1,order,(BN_CTX *)0x0);
                  if (iVar2 == 0) goto LAB_00093418;
                  pAVar8 = BN_to_ASN1_INTEGER(order,*(ASN1_INTEGER **)&val[0x14].field_0x0);
                  *(ASN1_INTEGER **)&val[0x14].field_0x0 = pAVar8;
                  if (pAVar8 != (ASN1_INTEGER *)0x0) goto LAB_00093418;
                  iVar5 = 0x2a1;
                }
              }
              ERR_put_error(0x10,0x9b,0xd,"ec_asn1.c",iVar5);
              p = buf;
            }
          }
        }
      }
    }
  }
LAB_00093408:
  ASN1_item_free(val,(ASN1_ITEM *)&ECPARAMETERS_it);
  val = (ASN1_VALUE *)0x0;
  buf = p;
LAB_00093418:
  BN_free(order);
  if (buf != (ASN1_VALUE *)0x0) {
    CRYPTO_free(buf);
  }
  return val;
}

