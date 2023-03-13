
undefined4 * __regparm3 ec_asn1_group2parameters_constprop_3(EC_GROUP *param_1)

{
  ASN1_OBJECT **ppAVar1;
  ASN1_STRING **ppAVar2;
  bool bVar3;
  BIGNUM *a;
  undefined4 *val;
  EC_METHOD *pEVar4;
  int iVar5;
  ASN1_OBJECT *pAVar6;
  char *pcVar7;
  ASN1_OBJECT *pAVar8;
  int *piVar9;
  BIGNUM *pBVar10;
  BIGNUM *b;
  int iVar11;
  EC_POINT *p;
  point_conversion_form_t form;
  size_t len;
  uchar *to;
  size_t sVar12;
  ASN1_INTEGER *pAVar13;
  ASN1_STRING *str;
  ASN1_BIT_STRING *a_00;
  void *data;
  uchar *puVar14;
  int in_GS_OFFSET;
  int iVar15;
  uchar *local_40;
  uchar *local_3c;
  int local_38;
  int local_30;
  uchar local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = BN_new();
  if (a == (BIGNUM *)0x0) {
    val = (undefined4 *)0x0;
    ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",0x22a);
    goto LAB_081037a4;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)ECPARAMETERS_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",0x230);
    BN_free(a);
    goto LAB_081037a4;
  }
  *val = 1;
  ppAVar1 = (ASN1_OBJECT **)val[1];
  if ((param_1 == (EC_GROUP *)0x0) || (ppAVar1 == (ASN1_OBJECT **)0x0)) {
LAB_08103757:
    iVar5 = 0x23b;
LAB_0810375f:
    iVar15 = 0x10;
LAB_08103766:
    puVar14 = (uchar *)0x0;
    ERR_put_error(0x10,0x9b,iVar15,"ec_asn1.c",iVar5);
LAB_08103777:
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)ECPARAMETERS_it);
    BN_free(a);
    val = (undefined4 *)0x0;
    if (puVar14 == (uchar *)0x0) goto LAB_081037a4;
  }
  else {
    if (*ppAVar1 != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(*ppAVar1);
    }
    if (ppAVar1[1] != (ASN1_OBJECT *)0x0) {
      ASN1_TYPE_free((ASN1_TYPE *)ppAVar1[1]);
    }
    pEVar4 = EC_GROUP_method_of(param_1);
    iVar5 = EC_METHOD_get_field_type(pEVar4);
    pAVar6 = OBJ_nid2obj(iVar5);
    *ppAVar1 = pAVar6;
    if (pAVar6 == (ASN1_OBJECT *)0x0) {
      iVar5 = 0x148;
LAB_08103c00:
      ERR_put_error(0x10,0x9a,8,"ec_asn1.c",iVar5);
      goto LAB_08103757;
    }
    if (iVar5 == 0x196) {
      pBVar10 = BN_new();
      if (pBVar10 != (BIGNUM *)0x0) {
        iVar5 = EC_GROUP_get_curve_GFp(param_1,pBVar10,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
        if (iVar5 == 0) {
          ERR_put_error(0x10,0x9a,0x10,"ec_asn1.c",0x153);
        }
        else {
          pAVar6 = (ASN1_OBJECT *)BN_to_ASN1_INTEGER(pBVar10,(ASN1_INTEGER *)0x0);
          ppAVar1[1] = pAVar6;
          if (pAVar6 != (ASN1_OBJECT *)0x0) {
            BN_free(pBVar10);
            goto LAB_08103985;
          }
          ERR_put_error(0x10,0x9a,0xd,"ec_asn1.c",0x159);
        }
        BN_free(pBVar10);
        goto LAB_08103757;
      }
      iVar5 = 0x14e;
LAB_08103bd8:
      ERR_put_error(0x10,0x9a,0x41,"ec_asn1.c",iVar5);
      goto LAB_08103757;
    }
    pAVar6 = (ASN1_OBJECT *)ASN1_item_new((ASN1_ITEM *)X9_62_CHARACTERISTIC_TWO_it);
    ppAVar1[1] = pAVar6;
    if (pAVar6 == (ASN1_OBJECT *)0x0) {
      iVar5 = 0x16b;
      goto LAB_08103bd8;
    }
    pcVar7 = (char *)EC_GROUP_get_degree(param_1);
    pAVar6->sn = pcVar7;
    pEVar4 = EC_GROUP_method_of(param_1);
    iVar5 = EC_METHOD_get_field_type(pEVar4);
    if (((iVar5 != 0x197) || (*(int *)(param_1 + 0x5c) == 0)) || (*(int *)(param_1 + 0x60) == 0)) {
LAB_08103739:
      ERR_put_error(0x10,0x9a,0x10,"ec_asn1.c",0x174);
      goto LAB_08103757;
    }
    if (*(int *)(param_1 + 100) == 0) {
      pAVar8 = OBJ_nid2obj(0x2aa);
      pAVar6->ln = &pAVar8->sn;
      if (pAVar8 != (ASN1_OBJECT *)0x0) {
        pEVar4 = EC_GROUP_method_of(param_1);
        iVar5 = EC_METHOD_get_field_type(pEVar4);
        if (((iVar5 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) &&
           ((iVar5 = *(int *)(param_1 + 0x60), iVar5 != 0 && (*(int *)(param_1 + 100) == 0)))) {
          pAVar13 = ASN1_INTEGER_new();
          pAVar6->nid = (int)pAVar13;
          if (pAVar13 == (ASN1_INTEGER *)0x0) {
            iVar5 = 0x185;
            goto LAB_08103bd8;
          }
          iVar5 = ASN1_INTEGER_set(pAVar13,iVar5);
          if (iVar5 != 0) goto LAB_08103985;
          ERR_put_error(0x10,0x9a,0xd,"ec_asn1.c",0x189);
        }
        else {
          ERR_put_error(0x10,0xc2,0x42,"ec_asn1.c",0x61);
        }
        goto LAB_08103757;
      }
LAB_08103ca0:
      iVar5 = 0x179;
      goto LAB_08103c00;
    }
    if ((*(int *)(param_1 + 0x68) == 0) || (*(int *)(param_1 + 0x6c) != 0)) goto LAB_08103739;
    pAVar8 = OBJ_nid2obj(0x2ab);
    pAVar6->ln = &pAVar8->sn;
    if (pAVar8 == (ASN1_OBJECT *)0x0) goto LAB_08103ca0;
    pEVar4 = EC_GROUP_method_of(param_1);
    iVar5 = EC_METHOD_get_field_type(pEVar4);
    if (((((iVar5 != 0x197) || (*(int *)(param_1 + 0x5c) == 0)) ||
         (iVar5 = *(int *)(param_1 + 0x60), iVar5 == 0)) ||
        ((iVar15 = *(int *)(param_1 + 100), iVar15 == 0 ||
         (iVar11 = *(int *)(param_1 + 0x68), iVar11 == 0)))) || (*(int *)(param_1 + 0x6c) != 0)) {
      ERR_put_error(0x10,0xc1,0x42,"ec_asn1.c",0x77);
      goto LAB_08103757;
    }
    piVar9 = (int *)ASN1_item_new((ASN1_ITEM *)X9_62_PENTANOMIAL_it);
    pAVar6->nid = (int)piVar9;
    if (piVar9 == (int *)0x0) {
      iVar5 = 0x194;
      goto LAB_08103bd8;
    }
    piVar9[1] = iVar15;
    piVar9[2] = iVar5;
    *piVar9 = iVar11;
LAB_08103985:
    ppAVar2 = (ASN1_STRING **)val[2];
    local_21 = '\0';
    if (((ppAVar2 == (ASN1_STRING **)0x0) || (*ppAVar2 == (ASN1_STRING *)0x0)) ||
       (ppAVar2[1] == (ASN1_STRING *)0x0)) {
LAB_08103bc2:
      iVar5 = 0x241;
      goto LAB_0810375f;
    }
    pBVar10 = BN_new();
    if ((pBVar10 == (BIGNUM *)0x0) || (b = BN_new(), b == (BIGNUM *)0x0)) {
      ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x1bc);
      if (pBVar10 == (BIGNUM *)0x0) goto LAB_08103bc2;
      bVar3 = false;
      b = (BIGNUM *)0x0;
    }
    else {
      pEVar4 = EC_GROUP_method_of(param_1);
      iVar5 = EC_METHOD_get_field_type(pEVar4);
      if (iVar5 == 0x196) {
        iVar5 = EC_GROUP_get_curve_GFp(param_1,(BIGNUM *)0x0,pBVar10,b,(BN_CTX *)0x0);
        if (iVar5 != 0) goto LAB_08103a06;
        iVar5 = 0x1c5;
LAB_08103dcd:
        ERR_put_error(0x10,0x99,0x10,"ec_asn1.c",iVar5);
      }
      else {
        iVar5 = EC_GROUP_get_curve_GF2m(param_1,0,pBVar10,b,0);
        if (iVar5 == 0) {
          iVar5 = 0x1cd;
          goto LAB_08103dcd;
        }
LAB_08103a06:
        iVar15 = BN_num_bits(pBVar10);
        iVar5 = iVar15 + 0xe;
        if (-1 < iVar15 + 7) {
          iVar5 = iVar15 + 7;
        }
        iVar11 = BN_num_bits(b);
        iVar15 = iVar11 + 0xe;
        if (-1 < iVar11 + 7) {
          iVar15 = iVar11 + 7;
        }
        if (iVar5 >> 3 != 0) {
          puVar14 = (uchar *)CRYPTO_malloc(iVar5 >> 3,"ec_asn1.c",0x1da);
          if (puVar14 == (uchar *)0x0) {
            bVar3 = false;
            ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x1db);
            goto LAB_08103b26;
          }
          local_38 = BN_bn2bin(pBVar10,puVar14);
          local_3c = puVar14;
          if (local_38 != 0) goto LAB_08103a59;
          bVar3 = false;
          ERR_put_error(0x10,0x99,3,"ec_asn1.c",0x1df);
          local_40 = (uchar *)0x0;
LAB_08103b00:
          CRYPTO_free(local_3c);
LAB_08103b0f:
          if (local_40 == (uchar *)0x0) goto LAB_08103b26;
LAB_08103b17:
          CRYPTO_free(local_40);
          goto LAB_08103b26;
        }
        puVar14 = &local_21;
        local_38 = 1;
        local_3c = (uchar *)0x0;
LAB_08103a59:
        if (iVar15 >> 3 == 0) {
          to = &local_21;
          local_30 = 1;
          local_40 = (uchar *)0x0;
LAB_08103a75:
          iVar5 = ASN1_STRING_set(*ppAVar2,puVar14,local_38);
          if ((iVar5 == 0) || (iVar5 = ASN1_STRING_set(ppAVar2[1],to,local_30), iVar5 == 0)) {
            iVar15 = 0x1f8;
            iVar5 = 0xd;
LAB_08103d57:
            bVar3 = false;
            ERR_put_error(0x10,0x99,iVar5,"ec_asn1.c",iVar15);
          }
          else {
            data = *(void **)(param_1 + 0x3c);
            a_00 = ppAVar2[2];
            if (data == (void *)0x0) {
              if (a_00 != (ASN1_BIT_STRING *)0x0) {
                ASN1_BIT_STRING_free(a_00);
                ppAVar2[2] = (ASN1_STRING *)0x0;
              }
            }
            else {
              if (a_00 == (ASN1_BIT_STRING *)0x0) {
                a_00 = ASN1_BIT_STRING_new();
                ppAVar2[2] = a_00;
                if (a_00 == (ASN1_BIT_STRING *)0x0) {
                  iVar15 = 0x200;
                  iVar5 = 0x41;
                  goto LAB_08103d57;
                }
                data = *(void **)(param_1 + 0x3c);
              }
              a_00->flags = a_00->flags & 0xfffffff0U | 8;
              iVar5 = ASN1_BIT_STRING_set(a_00,data,*(int *)(param_1 + 0x40));
              if (iVar5 == 0) {
                iVar15 = 0x207;
                iVar5 = 0xd;
                goto LAB_08103d57;
              }
            }
            bVar3 = true;
          }
          if (local_3c != (uchar *)0x0) goto LAB_08103b00;
          goto LAB_08103b0f;
        }
        to = (uchar *)CRYPTO_malloc(iVar15 >> 3,"ec_asn1.c",0x1ea);
        if (to != (uchar *)0x0) {
          local_30 = BN_bn2bin(b,to);
          local_40 = to;
          if (local_30 != 0) goto LAB_08103a75;
          bVar3 = false;
          ERR_put_error(0x10,0x99,3,"ec_asn1.c",0x1ef);
          if (local_3c != (uchar *)0x0) goto LAB_08103b00;
          goto LAB_08103b17;
        }
        ERR_put_error(0x10,0x99,0x41,"ec_asn1.c",0x1eb);
        if (local_3c != (uchar *)0x0) {
          local_40 = (uchar *)0x0;
          bVar3 = false;
          goto LAB_08103b00;
        }
      }
      bVar3 = false;
    }
LAB_08103b26:
    BN_free(pBVar10);
    if (b != (BIGNUM *)0x0) {
      BN_free(b);
    }
    if (!bVar3) goto LAB_08103bc2;
    p = EC_GROUP_get0_generator(param_1);
    if (p == (EC_POINT *)0x0) {
      iVar5 = 0x247;
      iVar15 = 0x71;
      goto LAB_08103766;
    }
    form = EC_GROUP_get_point_conversion_form(param_1);
    len = EC_POINT_point2oct(param_1,p,form,(uchar *)0x0,0,(BN_CTX *)0x0);
    if (len == 0) {
      iVar5 = 0x24f;
      goto LAB_0810375f;
    }
    puVar14 = (uchar *)CRYPTO_malloc(len,"ec_asn1.c",0x252);
    if (puVar14 == (uchar *)0x0) {
      iVar5 = 0x253;
LAB_08103fb8:
      ERR_put_error(0x10,0x9b,0x41,"ec_asn1.c",iVar5);
      goto LAB_08103777;
    }
    sVar12 = EC_POINT_point2oct(param_1,p,form,puVar14,len,(BN_CTX *)0x0);
    if (sVar12 == 0) {
      iVar5 = 599;
LAB_08103eba:
      ERR_put_error(0x10,0x9b,0x10,"ec_asn1.c",iVar5);
      goto LAB_08103777;
    }
    str = (ASN1_STRING *)val[3];
    if (str == (ASN1_STRING *)0x0) {
      str = ASN1_OCTET_STRING_new();
      val[3] = str;
      if (str == (ASN1_OCTET_STRING *)0x0) {
        iVar5 = 0x25b;
        goto LAB_08103fb8;
      }
    }
    iVar5 = ASN1_OCTET_STRING_set(str,puVar14,len);
    if (iVar5 == 0) {
      iVar5 = 0x25f;
LAB_08103d26:
      ERR_put_error(0x10,0x9b,0xd,"ec_asn1.c",iVar5);
      goto LAB_08103777;
    }
    iVar5 = EC_GROUP_get_order(param_1,a,(BN_CTX *)0x0);
    if (iVar5 == 0) {
      iVar5 = 0x265;
      goto LAB_08103eba;
    }
    pAVar13 = BN_to_ASN1_INTEGER(a,(ASN1_INTEGER *)val[4]);
    val[4] = pAVar13;
    if (pAVar13 == (ASN1_INTEGER *)0x0) {
      iVar5 = 0x26a;
      goto LAB_08103d26;
    }
    iVar5 = EC_GROUP_get_cofactor(param_1,a,(BN_CTX *)0x0);
    if (iVar5 != 0) {
      pAVar13 = BN_to_ASN1_INTEGER(a,(ASN1_INTEGER *)val[5]);
      val[5] = pAVar13;
      if (pAVar13 == (ASN1_INTEGER *)0x0) {
        iVar5 = 0x272;
        goto LAB_08103d26;
      }
    }
    BN_free(a);
  }
  CRYPTO_free(puVar14);
LAB_081037a4:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return val;
}

