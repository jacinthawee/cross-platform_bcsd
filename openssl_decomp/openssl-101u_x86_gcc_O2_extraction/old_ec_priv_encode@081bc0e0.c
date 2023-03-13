
int old_ec_priv_encode(int param_1,uchar **param_2)

{
  EC_GROUP *group;
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *val;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  ASN1_STRING *pAVar6;
  size_t sVar7;
  uchar *buf;
  ASN1_OBJECT *pAVar8;
  int *val_00;
  uint uVar9;
  int iVar10;
  uint uStack_24;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  if ((((puVar1 == (undefined4 *)0x0) || (puVar1[1] == 0)) || (puVar1[3] == 0)) ||
     (((*(byte *)(puVar1 + 4) & 2) == 0 && (puVar1[2] == 0)))) {
    ERR_put_error(0x10,0xc0,0x43,"ec_asn1.c",0x466);
    return 0;
  }
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x46b);
    return 0;
  }
  *val = *puVar1;
  iVar3 = BN_num_bits((BIGNUM *)puVar1[3]);
  iVar5 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar5 = iVar3 + 7;
  }
  uVar9 = iVar5 >> 3;
  iVar3 = EC_GROUP_get_degree((EC_GROUP *)puVar1[1]);
  iVar5 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar5 = iVar3 + 7;
  }
  uStack_24 = iVar5 >> 3;
  if (uStack_24 < uVar9) {
    ERR_put_error(0x10,0xc0,100,"ec_asn1.c",0x478);
LAB_08104c95:
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)EC_PRIVATEKEY_it);
    return 0;
  }
  puVar4 = (uchar *)CRYPTO_malloc(uStack_24,"ec_asn1.c",0x47c);
  if (puVar4 == (uchar *)0x0) {
    ERR_put_error(0x10,0xc0,0x41,"ec_asn1.c",0x47e);
    goto LAB_08104c95;
  }
  iVar5 = BN_bn2bin((BIGNUM *)puVar1[3],puVar4 + (uStack_24 - uVar9));
  if (iVar5 == 0) {
    iVar3 = 0x483;
    iVar5 = 3;
  }
  else {
    if (uVar9 != uStack_24) {
      memset(puVar4,0,uStack_24 - uVar9);
    }
    iVar5 = ASN1_STRING_set((ASN1_STRING *)val[1],puVar4,uStack_24);
    if (iVar5 == 0) {
      iVar3 = 0x48c;
      iVar5 = 0xd;
    }
    else {
      uVar9 = puVar1[4];
      if ((uVar9 & 1) == 0) {
        val_00 = (int *)val[2];
        group = (EC_GROUP *)puVar1[1];
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
          iVar5 = EC_GROUP_get_asn1_flag(group);
          if (iVar5 == 0) {
            *val_00 = 1;
            pAVar8 = (ASN1_OBJECT *)ec_asn1_group2parameters_constprop_3();
            val_00[1] = (int)pAVar8;
joined_r0x0810500c:
            if (pAVar8 != (ASN1_OBJECT *)0x0) {
              val[2] = val_00;
              uVar9 = puVar1[4];
              goto LAB_08104d30;
            }
          }
          else {
            iVar5 = EC_GROUP_get_curve_name(group);
            if (iVar5 != 0) {
              *val_00 = 0;
              pAVar8 = OBJ_nid2obj(iVar5);
              val_00[1] = (int)pAVar8;
              goto joined_r0x0810500c;
            }
          }
          ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)ECPKPARAMETERS_it);
        }
        val[2] = 0;
        iVar3 = 0x494;
LAB_08104dc3:
        iVar5 = 0x10;
      }
      else {
LAB_08104d30:
        buf = puVar4;
        if ((uVar9 & 2) != 0) {
LAB_08104e70:
          bVar2 = true;
          iVar10 = ASN1_item_i2d((ASN1_VALUE *)val,param_2,(ASN1_ITEM *)EC_PRIVATEKEY_it);
          if (iVar10 == 0) {
            bVar2 = false;
            ERR_put_error(0x10,0xc0,0x10,"ec_asn1.c",0x4bc);
          }
          goto LAB_08104e1a;
        }
        pAVar6 = ASN1_STRING_type_new(3);
        val[3] = pAVar6;
        if (pAVar6 == (ASN1_STRING *)0x0) {
          iVar3 = 0x49c;
          iVar5 = 0x41;
        }
        else {
          sVar7 = EC_POINT_point2oct((EC_GROUP *)puVar1[1],(EC_POINT *)puVar1[2],puVar1[5],
                                     (uchar *)0x0,0,(BN_CTX *)0x0);
          if ((uStack_24 < sVar7) &&
             (buf = (uchar *)CRYPTO_realloc(puVar4,sVar7,"ec_asn1.c",0x4a4), uStack_24 = sVar7,
             buf == (uchar *)0x0)) {
            iVar3 = 0x4a6;
            iVar5 = 0x41;
          }
          else {
            sVar7 = EC_POINT_point2oct((EC_GROUP *)puVar1[1],(EC_POINT *)puVar1[2],puVar1[5],buf,
                                       uStack_24,(BN_CTX *)0x0);
            puVar4 = buf;
            if (sVar7 == 0) {
              iVar3 = 0x4af;
              goto LAB_08104dc3;
            }
            pAVar6 = (ASN1_STRING *)val[3];
            pAVar6->flags = pAVar6->flags & 0xfffffff0U | 8;
            iVar5 = ASN1_STRING_set(pAVar6,buf,uStack_24);
            if (iVar5 != 0) goto LAB_08104e70;
            iVar3 = 0x4b6;
            iVar5 = 0xd;
          }
        }
      }
    }
  }
  bVar2 = false;
  iVar10 = 0;
  ERR_put_error(0x10,0xc0,iVar5,"ec_asn1.c",iVar3);
  buf = puVar4;
LAB_08104e1a:
  CRYPTO_free(buf);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)EC_PRIVATEKEY_it);
  if (!bVar2) {
    return 0;
  }
  return iVar10;
}

