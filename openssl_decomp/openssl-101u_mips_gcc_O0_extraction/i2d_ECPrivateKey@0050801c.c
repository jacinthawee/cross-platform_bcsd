
int i2d_ECPrivateKey(EC_KEY *key,uchar **out)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uchar *puVar5;
  int iVar6;
  size_t sVar7;
  uchar *buf;
  undefined4 uVar8;
  EC_GROUP *group;
  BIGNUM *a;
  undefined4 uVar9;
  uint len;
  uint uVar10;
  int *piVar11;
  code *pcVar12;
  
  if ((((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (*(int *)(key + 0xc) == 0)) ||
     (((*(uint *)(key + 0x10) & 2) == 0 && (*(int *)(key + 8) == 0)))) {
    uVar9 = 0x43;
    uVar8 = 0x466;
LAB_005082cc:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc0,uVar9,"ec_asn1.c",uVar8);
    return 0;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(EC_PRIVATEKEY_it);
  if (puVar3 == (undefined4 *)0x0) {
    uVar9 = 0x41;
    uVar8 = 0x46b;
    goto LAB_005082cc;
  }
  a = *(BIGNUM **)(key + 0xc);
  *puVar3 = *(undefined4 *)key;
  iVar4 = BN_num_bits(a);
  iVar6 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar6 = iVar4 + 0xe;
  }
  uVar10 = iVar6 >> 3;
  iVar4 = EC_GROUP_get_degree(*(EC_GROUP **)(key + 4));
  iVar6 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar6 = iVar4 + 0xe;
  }
  len = iVar6 >> 3;
  if (len < uVar10) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc0,100,"ec_asn1.c",0x478);
LAB_0050812c:
    (*(code *)PTR_ASN1_item_free_006a8658)(puVar3,EC_PRIVATEKEY_it);
    return 0;
  }
  puVar5 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(len,"ec_asn1.c",0x47c);
  if (puVar5 == (uchar *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc0,0x41,"ec_asn1.c",0x47e);
    goto LAB_0050812c;
  }
  iVar6 = BN_bn2bin(*(BIGNUM **)(key + 0xc),puVar5 + (len - uVar10));
  if (iVar6 == 0) {
    uVar9 = 3;
    uVar8 = 0x483;
    pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
  }
  else {
    if (uVar10 != len) {
      (*(code *)PTR_memset_006a99f4)(puVar5,0,len - uVar10);
    }
    iVar6 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(puVar3[1],puVar5,len);
    if (iVar6 == 0) {
      uVar9 = 0xd;
      uVar8 = 0x48c;
      pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
    }
    else {
      uVar10 = *(uint *)(key + 0x10);
      if ((uVar10 & 1) == 0) {
        piVar11 = (int *)puVar3[2];
        group = *(EC_GROUP **)(key + 4);
        if (piVar11 == (int *)0x0) {
          piVar11 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(ECPKPARAMETERS_it);
          if (piVar11 != (int *)0x0) goto LAB_00508464;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9c,0x41,"ec_asn1.c",0x28d);
        }
        else {
          if (*piVar11 == 0) {
            if (piVar11[1] != 0) {
              (*(code *)PTR_ASN1_OBJECT_free_006a7004)();
            }
          }
          else if ((*piVar11 == 1) && (piVar11[1] != 0)) {
            (*(code *)PTR_ASN1_item_free_006a8658)(piVar11[1],ECPARAMETERS_it);
          }
LAB_00508464:
          iVar6 = EC_GROUP_get_asn1_flag(group);
          if (iVar6 == 0) {
            *piVar11 = 1;
            iVar6 = ec_asn1_group2parameters_constprop_3(group);
            piVar11[1] = iVar6;
            if (iVar6 != 0) {
              uVar10 = *(uint *)(key + 0x10);
              puVar3[2] = piVar11;
              goto LAB_005081fc;
            }
          }
          else {
            iVar6 = EC_GROUP_get_curve_name(group);
            puVar2 = PTR_OBJ_nid2obj_006a7140;
            if (iVar6 != 0) {
              *piVar11 = 0;
              iVar6 = (*(code *)puVar2)(iVar6);
              piVar11[1] = iVar6;
              if (iVar6 != 0) {
                uVar10 = *(uint *)(key + 0x10);
                puVar3[2] = piVar11;
                goto LAB_005081fc;
              }
            }
          }
          (*(code *)PTR_ASN1_item_free_006a8658)(piVar11,ECPKPARAMETERS_it);
        }
        pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
        puVar3[2] = 0;
        uVar9 = 0x10;
        uVar8 = 0x494;
      }
      else {
LAB_005081fc:
        buf = puVar5;
        if ((uVar10 & 2) != 0) {
LAB_00508384:
          iVar6 = (*(code *)PTR_ASN1_item_i2d_006a8678)(puVar3,out,EC_PRIVATEKEY_it);
          if (iVar6 == 0) {
            bVar1 = false;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc0,0x10,"ec_asn1.c",0x4bc);
          }
          else {
            bVar1 = true;
          }
          goto LAB_00508310;
        }
        iVar6 = (*(code *)PTR_ASN1_STRING_type_new_006a8680)(3);
        puVar3[3] = iVar6;
        if (iVar6 == 0) {
          uVar9 = 0x41;
          uVar8 = 0x49c;
          pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
        }
        else {
          sVar7 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                     *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,
                                     (BN_CTX *)0x0);
          if ((len < sVar7) &&
             (buf = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(puVar5,sVar7,"ec_asn1.c",0x4a4),
             len = sVar7, buf == (uchar *)0x0)) {
            uVar9 = 0x41;
            uVar8 = 0x4a6;
            pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
          }
          else {
            sVar7 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                       *(point_conversion_form_t *)(key + 0x14),buf,len,
                                       (BN_CTX *)0x0);
            puVar2 = PTR_ASN1_STRING_set_006a7d1c;
            puVar5 = buf;
            if (sVar7 == 0) {
              uVar9 = 0x10;
              uVar8 = 0x4af;
              pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
            }
            else {
              iVar6 = puVar3[3];
              *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffffff0 | 8;
              iVar6 = (*(code *)puVar2)(iVar6,buf,len);
              if (iVar6 != 0) goto LAB_00508384;
              uVar9 = 0xd;
              uVar8 = 0x4b6;
              pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
            }
          }
        }
      }
    }
  }
  bVar1 = false;
  (*pcVar12)(0x10,0xc0,uVar9,"ec_asn1.c",uVar8);
  iVar6 = 0;
  buf = puVar5;
LAB_00508310:
  (*(code *)PTR_CRYPTO_free_006a6e88)(buf);
  (*(code *)PTR_ASN1_item_free_006a8658)(puVar3,EC_PRIVATEKEY_it);
  if (!bVar1) {
    return 0;
  }
  return iVar6;
}

