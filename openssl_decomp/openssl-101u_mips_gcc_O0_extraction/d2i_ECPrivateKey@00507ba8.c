
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  EC_GROUP *pEVar6;
  BIGNUM *pBVar7;
  EC_POINT *r;
  undefined4 *puVar8;
  int iVar9;
  uchar *puVar10;
  uchar *buf;
  int iVar11;
  size_t *psVar12;
  byte *buf_00;
  undefined1 *puVar13;
  undefined4 uVar14;
  size_t sVar15;
  undefined4 *key_00;
  EC_KEY *pEVar16;
  uint len_00;
  uint uVar17;
  code *pcVar18;
  uchar *local_28;
  undefined4 *local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_28 = *in;
  local_24 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  puVar3 = (undefined4 *)(*(code *)PTR_ASN1_item_d2i_006a8674)(0,&local_28,len,EC_PRIVATEKEY_it);
  if (puVar3 == (undefined4 *)0x0) {
    puVar13 = (undefined1 *)0x92;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x92,0x10,"ec_asn1.c",0x400);
    puVar8 = (undefined4 *)0x0;
  }
  else {
    if (((key == (EC_KEY **)0x0) ||
        (key_00 = (undefined4 *)*key, (undefined4 *)*key == (undefined4 *)0x0)) &&
       (puVar8 = (undefined4 *)EC_KEY_new(), key_00 = puVar8, puVar8 == (undefined4 *)0x0)) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x92,0x41,"ec_asn1.c",0x406);
    }
    else {
      piVar4 = (int *)puVar3[2];
      if (piVar4 == (int *)0x0) {
        pEVar6 = (EC_GROUP *)key_00[1];
        goto LAB_00507ca4;
      }
      if ((EC_GROUP *)key_00[1] == (EC_GROUP *)0x0) {
LAB_00507c58:
        iVar11 = *piVar4;
        if (iVar11 == 0) {
          iVar11 = (*(code *)PTR_OBJ_obj2nid_006a712c)(piVar4[1]);
          pEVar6 = EC_GROUP_new_by_curve_name(iVar11);
          if (pEVar6 != (EC_GROUP *)0x0) {
            EC_GROUP_set_asn1_flag(pEVar6,1);
            key_00[1] = pEVar6;
            goto LAB_00507ca4;
          }
          uVar14 = 0x77;
          uVar5 = 0x3b1;
          goto LAB_00507c88;
        }
        if (iVar11 == 1) {
          pEVar6 = (EC_GROUP *)ec_asn1_parameters2group(piVar4[1]);
          if (pEVar6 == (EC_GROUP *)0x0) {
            uVar14 = 0x10;
            uVar5 = 0x3b9;
            goto LAB_00507c88;
          }
          EC_GROUP_set_asn1_flag(pEVar6,0);
          key_00[1] = pEVar6;
        }
        else {
          if (iVar11 != 2) {
            uVar14 = 0x73;
            uVar5 = 0x3c0;
            goto LAB_00507c88;
          }
          pEVar6 = (EC_GROUP *)0x0;
          key_00[1] = 0;
        }
      }
      else {
        EC_GROUP_clear_free((EC_GROUP *)key_00[1]);
        piVar4 = (int *)puVar3[2];
        if (piVar4 != (int *)0x0) goto LAB_00507c58;
        uVar14 = 0x7c;
        uVar5 = 0x3a9;
LAB_00507c88:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9e,uVar14,"ec_asn1.c",uVar5);
        pEVar6 = (EC_GROUP *)0x0;
        key_00[1] = 0;
      }
LAB_00507ca4:
      if (pEVar6 == (EC_GROUP *)0x0) {
        uVar14 = 0x10;
        uVar5 = 0x413;
      }
      else {
        piVar4 = (int *)puVar3[1];
        *key_00 = *puVar3;
        if (piVar4 == (int *)0x0) {
          uVar14 = 0x7d;
          uVar5 = 0x422;
        }
        else {
          pBVar7 = BN_bin2bn((uchar *)piVar4[2],*piVar4,(BIGNUM *)key_00[3]);
          key_00[3] = pBVar7;
          if (pBVar7 == (BIGNUM *)0x0) {
            uVar14 = 3;
            uVar5 = 0x41e;
          }
          else {
            if ((EC_POINT *)key_00[2] != (EC_POINT *)0x0) {
              EC_POINT_clear_free((EC_POINT *)key_00[2]);
            }
            r = EC_POINT_new((EC_GROUP *)key_00[1]);
            key_00[2] = r;
            if (r == (EC_POINT *)0x0) {
              uVar14 = 0x10;
              uVar5 = 0x42a;
            }
            else {
              psVar12 = (size_t *)puVar3[3];
              if (psVar12 == (size_t *)0x0) {
                iVar11 = EC_POINT_mul((EC_GROUP *)key_00[1],r,(BIGNUM *)key_00[3],(EC_POINT *)0x0,
                                      (BIGNUM *)0x0,(BN_CTX *)0x0);
                if (iVar11 != 0) {
                  key_00[4] = key_00[4] | 2;
LAB_00507d50:
                  if (key != (EC_KEY **)0x0) {
                    *key = (EC_KEY *)key_00;
                  }
                  *in = local_28;
                  puVar8 = key_00;
                  goto LAB_00507d64;
                }
                uVar14 = 0x10;
                uVar5 = 0x445;
              }
              else {
                sVar15 = *psVar12;
                if ((int)sVar15 < 1) {
                  uVar14 = 100;
                  uVar5 = 0x438;
                }
                else {
                  buf_00 = (byte *)psVar12[2];
                  key_00[5] = *buf_00 & 0xfe;
                  iVar11 = EC_POINT_oct2point((EC_GROUP *)key_00[1],r,buf_00,sVar15,(BN_CTX *)0x0);
                  if (iVar11 != 0) goto LAB_00507d50;
                  uVar14 = 0x10;
                  uVar5 = 0x43f;
                }
              }
            }
          }
        }
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x92,uVar14,"ec_asn1.c",uVar5);
      if ((key == (EC_KEY **)0x0) || (key_00 != (undefined4 *)*key)) {
        puVar8 = (undefined4 *)0x0;
        EC_KEY_free((EC_KEY *)key_00);
      }
      else {
        puVar8 = (undefined4 *)0x0;
      }
    }
LAB_00507d64:
    puVar13 = EC_PRIVATEKEY_it;
    (*(code *)PTR_ASN1_item_free_006a8658)(puVar3,EC_PRIVATEKEY_it);
  }
  if (local_24 == *(undefined4 **)puVar2) {
    return (EC_KEY *)puVar8;
  }
  puVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((puVar3 == (undefined4 *)0x0) || (puVar3[1] == 0)) ||
     ((puVar3[3] == 0 || (((puVar3[4] & 2) == 0 && (puVar3[2] == 0)))))) {
    uVar14 = 0x43;
    uVar5 = 0x466;
LAB_005082cc:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc0,uVar14,"ec_asn1.c",uVar5);
    return (EC_KEY *)0x0;
  }
  puVar8 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(EC_PRIVATEKEY_it);
  if (puVar8 == (undefined4 *)0x0) {
    uVar14 = 0x41;
    uVar5 = 0x46b;
    goto LAB_005082cc;
  }
  pBVar7 = (BIGNUM *)puVar3[3];
  *puVar8 = *puVar3;
  iVar9 = BN_num_bits(pBVar7);
  iVar11 = iVar9 + 7;
  if (iVar9 + 7 < 0) {
    iVar11 = iVar9 + 0xe;
  }
  uVar17 = iVar11 >> 3;
  iVar9 = EC_GROUP_get_degree((EC_GROUP *)puVar3[1]);
  iVar11 = iVar9 + 7;
  if (iVar9 + 7 < 0) {
    iVar11 = iVar9 + 0xe;
  }
  len_00 = iVar11 >> 3;
  if (len_00 < uVar17) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc0,100,"ec_asn1.c",0x478);
LAB_0050812c:
    (*(code *)PTR_ASN1_item_free_006a8658)(puVar8,EC_PRIVATEKEY_it);
    return (EC_KEY *)0x0;
  }
  puVar10 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(len_00,"ec_asn1.c",0x47c);
  if (puVar10 == (uchar *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc0,0x41,"ec_asn1.c",0x47e);
    goto LAB_0050812c;
  }
  iVar11 = BN_bn2bin((BIGNUM *)puVar3[3],puVar10 + (len_00 - uVar17));
  if (iVar11 == 0) {
    uVar14 = 3;
    uVar5 = 0x483;
    pcVar18 = (code *)PTR_ERR_put_error_006a7f34;
  }
  else {
    if (uVar17 != len_00) {
      (*(code *)PTR_memset_006a99f4)(puVar10,0,len_00 - uVar17);
    }
    iVar11 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(puVar8[1],puVar10,len_00);
    if (iVar11 == 0) {
      uVar14 = 0xd;
      uVar5 = 0x48c;
      pcVar18 = (code *)PTR_ERR_put_error_006a7f34;
    }
    else {
      uVar17 = puVar3[4];
      if ((uVar17 & 1) == 0) {
        piVar4 = (int *)puVar8[2];
        pEVar6 = (EC_GROUP *)puVar3[1];
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(ECPKPARAMETERS_it);
          if (piVar4 != (int *)0x0) goto LAB_00508464;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9c,0x41,"ec_asn1.c",0x28d);
        }
        else {
          if (*piVar4 == 0) {
            if (piVar4[1] != 0) {
              (*(code *)PTR_ASN1_OBJECT_free_006a7004)();
            }
          }
          else if ((*piVar4 == 1) && (piVar4[1] != 0)) {
            (*(code *)PTR_ASN1_item_free_006a8658)(piVar4[1],ECPARAMETERS_it);
          }
LAB_00508464:
          iVar11 = EC_GROUP_get_asn1_flag(pEVar6);
          if (iVar11 == 0) {
            *piVar4 = 1;
            iVar11 = ec_asn1_group2parameters_constprop_3(pEVar6);
            piVar4[1] = iVar11;
            if (iVar11 != 0) {
              uVar17 = puVar3[4];
              puVar8[2] = piVar4;
              goto LAB_005081fc;
            }
          }
          else {
            iVar11 = EC_GROUP_get_curve_name(pEVar6);
            puVar2 = PTR_OBJ_nid2obj_006a7140;
            if (iVar11 != 0) {
              *piVar4 = 0;
              iVar11 = (*(code *)puVar2)(iVar11);
              piVar4[1] = iVar11;
              if (iVar11 != 0) {
                uVar17 = puVar3[4];
                puVar8[2] = piVar4;
                goto LAB_005081fc;
              }
            }
          }
          (*(code *)PTR_ASN1_item_free_006a8658)(piVar4,ECPKPARAMETERS_it);
        }
        pcVar18 = (code *)PTR_ERR_put_error_006a7f34;
        puVar8[2] = 0;
        uVar14 = 0x10;
        uVar5 = 0x494;
      }
      else {
LAB_005081fc:
        buf = puVar10;
        if ((uVar17 & 2) != 0) {
LAB_00508384:
          pEVar16 = (EC_KEY *)(*(code *)PTR_ASN1_item_i2d_006a8678)(puVar8,puVar13,EC_PRIVATEKEY_it)
          ;
          if (pEVar16 == (EC_KEY *)0x0) {
            bVar1 = false;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc0,0x10,"ec_asn1.c",0x4bc);
          }
          else {
            bVar1 = true;
          }
          goto LAB_00508310;
        }
        iVar11 = (*(code *)PTR_ASN1_STRING_type_new_006a8680)(3);
        puVar8[3] = iVar11;
        if (iVar11 == 0) {
          uVar14 = 0x41;
          uVar5 = 0x49c;
          pcVar18 = (code *)PTR_ERR_put_error_006a7f34;
        }
        else {
          sVar15 = EC_POINT_point2oct((EC_GROUP *)puVar3[1],(EC_POINT *)puVar3[2],puVar3[5],
                                      (uchar *)0x0,0,(BN_CTX *)0x0);
          if ((len_00 < sVar15) &&
             (buf = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                       (puVar10,sVar15,"ec_asn1.c",0x4a4), len_00 = sVar15,
             buf == (uchar *)0x0)) {
            uVar14 = 0x41;
            uVar5 = 0x4a6;
            pcVar18 = (code *)PTR_ERR_put_error_006a7f34;
          }
          else {
            sVar15 = EC_POINT_point2oct((EC_GROUP *)puVar3[1],(EC_POINT *)puVar3[2],puVar3[5],buf,
                                        len_00,(BN_CTX *)0x0);
            puVar2 = PTR_ASN1_STRING_set_006a7d1c;
            puVar10 = buf;
            if (sVar15 == 0) {
              uVar14 = 0x10;
              uVar5 = 0x4af;
              pcVar18 = (code *)PTR_ERR_put_error_006a7f34;
            }
            else {
              iVar11 = puVar8[3];
              *(uint *)(iVar11 + 0xc) = *(uint *)(iVar11 + 0xc) & 0xfffffff0 | 8;
              iVar11 = (*(code *)puVar2)(iVar11,buf,len_00);
              if (iVar11 != 0) goto LAB_00508384;
              uVar14 = 0xd;
              uVar5 = 0x4b6;
              pcVar18 = (code *)PTR_ERR_put_error_006a7f34;
            }
          }
        }
      }
    }
  }
  bVar1 = false;
  (*pcVar18)(0x10,0xc0,uVar14,"ec_asn1.c",uVar5);
  pEVar16 = (EC_KEY *)0x0;
  buf = puVar10;
LAB_00508310:
  (*(code *)PTR_CRYPTO_free_006a6e88)(buf);
  (*(code *)PTR_ASN1_item_free_006a8658)(puVar8,EC_PRIVATEKEY_it);
  if (!bVar1) {
    return (EC_KEY *)0x0;
  }
  return pEVar16;
}

