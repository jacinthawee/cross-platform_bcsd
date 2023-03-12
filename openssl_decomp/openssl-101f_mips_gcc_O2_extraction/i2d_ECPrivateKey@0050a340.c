
int i2d_ECPrivateKey(EC_KEY *key,uchar **out)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uchar *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  size_t sVar9;
  uchar *buf;
  EC_GROUP *group;
  BIGNUM *a;
  undefined4 uVar10;
  uint len;
  code *pcVar11;
  int *piVar12;
  
  if (((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) || (*(int *)(key + 0xc) == 0)) {
    uVar10 = 0x43;
    uVar7 = 0x4d4;
LAB_0050a4b0:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc0,uVar10,"ec_asn1.c",uVar7);
    return 0;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(EC_PRIVATEKEY_it);
  if (puVar3 == (undefined4 *)0x0) {
    uVar10 = 0x41;
    uVar7 = 0x4db;
    goto LAB_0050a4b0;
  }
  a = *(BIGNUM **)(key + 0xc);
  *puVar3 = *(undefined4 *)key;
  iVar4 = BN_num_bits(a);
  iVar6 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar6 = iVar4 + 0xe;
  }
  len = iVar6 >> 3;
  puVar5 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(len,"ec_asn1.c",0x4e2);
  if (puVar5 == (uchar *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc0,0x41,"ec_asn1.c",0x4e6);
    (*(code *)PTR_ASN1_item_free_006a977c)(puVar3,EC_PRIVATEKEY_it);
    return 0;
  }
  iVar6 = BN_bn2bin(*(BIGNUM **)(key + 0xc),puVar5);
  if (iVar6 == 0) {
    uVar10 = 3;
    uVar7 = 0x4ec;
    pcVar11 = (code *)PTR_ERR_put_error_006a9030;
  }
  else {
    iVar6 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(puVar3[1],puVar5,len);
    if (iVar6 == 0) {
      uVar10 = 0xd;
      uVar7 = 0x4f2;
      pcVar11 = (code *)PTR_ERR_put_error_006a9030;
    }
    else {
      uVar8 = *(uint *)(key + 0x10);
      if ((uVar8 & 1) == 0) {
        piVar12 = (int *)puVar3[2];
        group = *(EC_GROUP **)(key + 4);
        if (piVar12 == (int *)0x0) {
          piVar12 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(ECPKPARAMETERS_it);
          if (piVar12 != (int *)0x0) goto LAB_0050a6f4;
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9c,0x41,"ec_asn1.c",0x2c0);
        }
        else {
          if (*piVar12 == 0) {
            if (piVar12[1] != 0) {
              (*(code *)PTR_ASN1_OBJECT_free_006a8104)();
            }
          }
          else if ((*piVar12 == 1) && (piVar12[1] != 0)) {
            (*(code *)PTR_ASN1_item_free_006a977c)(piVar12[1],ECPARAMETERS_it);
          }
LAB_0050a6f4:
          iVar6 = EC_GROUP_get_asn1_flag(group);
          if (iVar6 == 0) {
            *piVar12 = 1;
            iVar6 = ec_asn1_group2parameters_constprop_3(group);
            piVar12[1] = iVar6;
            if (iVar6 != 0) {
              uVar8 = *(uint *)(key + 0x10);
              puVar3[2] = piVar12;
              goto LAB_0050a520;
            }
          }
          else {
            iVar6 = EC_GROUP_get_curve_name(group);
            puVar2 = PTR_OBJ_nid2obj_006a8240;
            if (iVar6 != 0) {
              *piVar12 = 0;
              iVar6 = (*(code *)puVar2)(iVar6);
              piVar12[1] = iVar6;
              if (iVar6 != 0) {
                uVar8 = *(uint *)(key + 0x10);
                puVar3[2] = piVar12;
                goto LAB_0050a520;
              }
            }
          }
          (*(code *)PTR_ASN1_item_free_006a977c)(piVar12,ECPKPARAMETERS_it);
        }
        pcVar11 = (code *)PTR_ERR_put_error_006a9030;
        puVar3[2] = 0;
        uVar10 = 0x10;
        uVar7 = 0x4fb;
      }
      else {
LAB_0050a520:
        buf = puVar5;
        if ((uVar8 & 2) != 0) {
LAB_0050a644:
          iVar6 = (*(code *)PTR_ASN1_item_i2d_006a979c)(puVar3,out,EC_PRIVATEKEY_it);
          if (iVar6 == 0) {
            bVar1 = false;
            (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc0,0x10,"ec_asn1.c",0x52c);
          }
          else {
            bVar1 = true;
          }
          goto LAB_0050a444;
        }
        iVar6 = (*(code *)PTR_ASN1_STRING_type_new_006a97a4)(3);
        puVar3[3] = iVar6;
        if (iVar6 == 0) {
          uVar10 = 0x41;
          uVar7 = 0x506;
          pcVar11 = (code *)PTR_ERR_put_error_006a9030;
        }
        else {
          sVar9 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                     *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,
                                     (BN_CTX *)0x0);
          if ((len < sVar9) &&
             (buf = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(puVar5,sVar9,"ec_asn1.c",0x50f),
             len = sVar9, buf == (uchar *)0x0)) {
            uVar10 = 0x41;
            uVar7 = 0x512;
            pcVar11 = (code *)PTR_ERR_put_error_006a9030;
          }
          else {
            sVar9 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                       *(point_conversion_form_t *)(key + 0x14),buf,len,
                                       (BN_CTX *)0x0);
            puVar2 = PTR_ASN1_STRING_set_006a8e0c;
            puVar5 = buf;
            if (sVar9 == 0) {
              uVar10 = 0x10;
              uVar7 = 0x51c;
              pcVar11 = (code *)PTR_ERR_put_error_006a9030;
            }
            else {
              iVar6 = puVar3[3];
              *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffffff0 | 8;
              iVar6 = (*(code *)puVar2)(iVar6,buf,len);
              if (iVar6 != 0) goto LAB_0050a644;
              uVar10 = 0xd;
              uVar7 = 0x525;
              pcVar11 = (code *)PTR_ERR_put_error_006a9030;
            }
          }
        }
      }
    }
  }
  bVar1 = false;
  (*pcVar11)(0x10,0xc0,uVar10,"ec_asn1.c",uVar7);
  iVar6 = 0;
  buf = puVar5;
LAB_0050a444:
  (*(code *)PTR_CRYPTO_free_006a7f88)(buf);
  (*(code *)PTR_ASN1_item_free_006a977c)(puVar3,EC_PRIVATEKEY_it);
  if (!bVar1) {
    return 0;
  }
  return iVar6;
}

