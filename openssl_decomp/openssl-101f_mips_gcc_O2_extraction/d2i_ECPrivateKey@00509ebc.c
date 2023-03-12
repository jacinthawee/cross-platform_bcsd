
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 uVar4;
  EC_GROUP *pEVar5;
  BIGNUM *pBVar6;
  undefined1 *p;
  byte *buf;
  undefined4 *puVar7;
  int iVar8;
  uchar *puVar9;
  uint uVar10;
  uchar *buf_00;
  int iVar11;
  undefined4 uVar12;
  size_t sVar13;
  undefined4 *puVar14;
  EC_KEY *pEVar15;
  uint len_00;
  code *pcVar16;
  undefined4 *local_20;
  undefined4 *local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_20 = (undefined4 *)0x0;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  local_20 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(EC_PRIVATEKEY_it);
  if (local_20 == (undefined4 *)0x0) {
    p = (EC_POINT *)0x92;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x92,0x41,"ec_asn1.c",0x466);
    puVar14 = (undefined4 *)0x0;
  }
  else {
    local_20 = (undefined4 *)
               (*(code *)PTR_ASN1_item_d2i_006a9798)(&local_20,in,len,EC_PRIVATEKEY_it);
    if (local_20 == (undefined4 *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x92,0x10,"ec_asn1.c",0x46c);
      p = EC_PRIVATEKEY_it;
      (*(code *)PTR_ASN1_item_free_006a977c)(local_20,EC_PRIVATEKEY_it);
      puVar14 = (undefined4 *)0x0;
    }
    else {
      if (key == (EC_KEY **)0x0) {
        puVar14 = (undefined4 *)EC_KEY_new();
        if (puVar14 != (undefined4 *)0x0) goto LAB_00509f58;
LAB_0050a210:
        p = (EC_POINT *)0x92;
        puVar14 = (undefined4 *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x92,0x41,"ec_asn1.c",0x476);
LAB_0050a090:
        if (local_20 == (undefined4 *)0x0) goto LAB_0050a0a8;
      }
      else {
        puVar14 = (undefined4 *)*key;
        if (puVar14 == (undefined4 *)0x0) {
          puVar14 = (undefined4 *)EC_KEY_new();
          if (puVar14 == (undefined4 *)0x0) goto LAB_0050a210;
          *key = (EC_KEY *)puVar14;
        }
LAB_00509f58:
        piVar3 = (int *)local_20[2];
        if (piVar3 == (int *)0x0) {
          pEVar5 = (EC_GROUP *)puVar14[1];
          goto LAB_00509fd4;
        }
        if ((EC_GROUP *)puVar14[1] == (EC_GROUP *)0x0) {
LAB_00509f88:
          iVar11 = *piVar3;
          if (iVar11 == 0) {
            iVar11 = (*(code *)PTR_OBJ_obj2nid_006a822c)(piVar3[1]);
            pEVar5 = EC_GROUP_new_by_curve_name(iVar11);
            if (pEVar5 != (EC_GROUP *)0x0) {
              EC_GROUP_set_asn1_flag(pEVar5,1);
              puVar14[1] = pEVar5;
              goto LAB_00509fd4;
            }
            uVar12 = 0x77;
            uVar4 = 0x40d;
            goto LAB_00509fb8;
          }
          if (iVar11 == 1) {
            pEVar5 = (EC_GROUP *)ec_asn1_parameters2group(piVar3[1]);
            if (pEVar5 == (EC_GROUP *)0x0) {
              uVar12 = 0x10;
              uVar4 = 0x418;
              goto LAB_00509fb8;
            }
            EC_GROUP_set_asn1_flag(pEVar5,0);
            puVar14[1] = pEVar5;
          }
          else {
            if (iVar11 != 2) {
              uVar12 = 0x73;
              uVar4 = 0x423;
              goto LAB_00509fb8;
            }
            pEVar5 = (EC_GROUP *)0x0;
            puVar14[1] = 0;
          }
        }
        else {
          EC_GROUP_clear_free((EC_GROUP *)puVar14[1]);
          piVar3 = (int *)local_20[2];
          if (piVar3 != (int *)0x0) goto LAB_00509f88;
          uVar12 = 0x7c;
          uVar4 = 0x403;
LAB_00509fb8:
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9e,uVar12,"ec_asn1.c",uVar4);
          pEVar5 = (EC_GROUP *)0x0;
          puVar14[1] = 0;
        }
LAB_00509fd4:
        if (pEVar5 == (EC_GROUP *)0x0) {
          uVar12 = 0x10;
          uVar4 = 0x488;
LAB_0050a144:
          p = (EC_POINT *)0x92;
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x92,uVar12,"ec_asn1.c",uVar4);
          EC_KEY_free((EC_KEY *)puVar14);
          puVar14 = (undefined4 *)0x0;
          goto LAB_0050a090;
        }
        piVar3 = (int *)local_20[1];
        *puVar14 = *local_20;
        if (piVar3 == (int *)0x0) {
          uVar12 = 0x7d;
          uVar4 = 0x49e;
          goto LAB_0050a144;
        }
        pBVar6 = BN_bin2bn((uchar *)piVar3[2],*piVar3,(BIGNUM *)puVar14[3]);
        puVar14[3] = pBVar6;
        if (pBVar6 == (BIGNUM *)0x0) {
          uVar12 = 3;
          uVar4 = 0x497;
          goto LAB_0050a144;
        }
        if (local_20[3] != 0) {
          if ((EC_POINT *)puVar14[2] != (EC_POINT *)0x0) {
            EC_POINT_clear_free((EC_POINT *)puVar14[2]);
          }
          p = EC_POINT_new((EC_GROUP *)puVar14[1]);
          puVar14[2] = p;
          if ((EC_POINT *)p == (EC_POINT *)0x0) {
            uVar12 = 0x10;
            uVar4 = 0x4ac;
          }
          else {
            buf = (byte *)((size_t *)local_20[3])[2];
            sVar13 = *(size_t *)local_20[3];
            puVar14[5] = *buf & 0xfe;
            iVar11 = EC_POINT_oct2point((EC_GROUP *)puVar14[1],(EC_POINT *)p,buf,sVar13,
                                        (BN_CTX *)0x0);
            if (iVar11 != 0) goto LAB_0050a090;
            uVar12 = 0x10;
            uVar4 = 0x4b6;
          }
          goto LAB_0050a144;
        }
      }
      p = EC_PRIVATEKEY_it;
      (*(code *)PTR_ASN1_item_free_006a977c)(local_20,EC_PRIVATEKEY_it);
    }
  }
LAB_0050a0a8:
  if (local_1c == *(undefined4 **)puVar2) {
    return (EC_KEY *)puVar14;
  }
  puVar14 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((puVar14 == (undefined4 *)0x0) || (puVar14[1] == 0)) || (puVar14[3] == 0)) {
    uVar12 = 0x43;
    uVar4 = 0x4d4;
LAB_0050a4b0:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc0,uVar12,"ec_asn1.c",uVar4);
    return (EC_KEY *)0x0;
  }
  puVar7 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(EC_PRIVATEKEY_it);
  if (puVar7 == (undefined4 *)0x0) {
    uVar12 = 0x41;
    uVar4 = 0x4db;
    goto LAB_0050a4b0;
  }
  pBVar6 = (BIGNUM *)puVar14[3];
  *puVar7 = *puVar14;
  iVar8 = BN_num_bits(pBVar6);
  iVar11 = iVar8 + 7;
  if (iVar8 + 7 < 0) {
    iVar11 = iVar8 + 0xe;
  }
  len_00 = iVar11 >> 3;
  puVar9 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(len_00,"ec_asn1.c",0x4e2);
  if (puVar9 == (uchar *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc0,0x41,"ec_asn1.c",0x4e6);
    (*(code *)PTR_ASN1_item_free_006a977c)(puVar7,EC_PRIVATEKEY_it);
    return (EC_KEY *)0x0;
  }
  iVar11 = BN_bn2bin((BIGNUM *)puVar14[3],puVar9);
  if (iVar11 == 0) {
    uVar12 = 3;
    uVar4 = 0x4ec;
    pcVar16 = (code *)PTR_ERR_put_error_006a9030;
  }
  else {
    iVar11 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(puVar7[1],puVar9,len_00);
    if (iVar11 == 0) {
      uVar12 = 0xd;
      uVar4 = 0x4f2;
      pcVar16 = (code *)PTR_ERR_put_error_006a9030;
    }
    else {
      uVar10 = puVar14[4];
      if ((uVar10 & 1) == 0) {
        piVar3 = (int *)puVar7[2];
        pEVar5 = (EC_GROUP *)puVar14[1];
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(ECPKPARAMETERS_it);
          if (piVar3 != (int *)0x0) goto LAB_0050a6f4;
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9c,0x41,"ec_asn1.c",0x2c0);
        }
        else {
          if (*piVar3 == 0) {
            if (piVar3[1] != 0) {
              (*(code *)PTR_ASN1_OBJECT_free_006a8104)();
            }
          }
          else if ((*piVar3 == 1) && (piVar3[1] != 0)) {
            (*(code *)PTR_ASN1_item_free_006a977c)(piVar3[1],ECPARAMETERS_it);
          }
LAB_0050a6f4:
          iVar11 = EC_GROUP_get_asn1_flag(pEVar5);
          if (iVar11 == 0) {
            *piVar3 = 1;
            iVar11 = ec_asn1_group2parameters_constprop_3(pEVar5);
            piVar3[1] = iVar11;
            if (iVar11 != 0) {
              uVar10 = puVar14[4];
              puVar7[2] = piVar3;
              goto LAB_0050a520;
            }
          }
          else {
            iVar11 = EC_GROUP_get_curve_name(pEVar5);
            puVar2 = PTR_OBJ_nid2obj_006a8240;
            if (iVar11 != 0) {
              *piVar3 = 0;
              iVar11 = (*(code *)puVar2)(iVar11);
              piVar3[1] = iVar11;
              if (iVar11 != 0) {
                uVar10 = puVar14[4];
                puVar7[2] = piVar3;
                goto LAB_0050a520;
              }
            }
          }
          (*(code *)PTR_ASN1_item_free_006a977c)(piVar3,ECPKPARAMETERS_it);
        }
        pcVar16 = (code *)PTR_ERR_put_error_006a9030;
        puVar7[2] = 0;
        uVar12 = 0x10;
        uVar4 = 0x4fb;
      }
      else {
LAB_0050a520:
        buf_00 = puVar9;
        if ((uVar10 & 2) != 0) {
LAB_0050a644:
          pEVar15 = (EC_KEY *)(*(code *)PTR_ASN1_item_i2d_006a979c)(puVar7,p,EC_PRIVATEKEY_it);
          if (pEVar15 == (EC_KEY *)0x0) {
            bVar1 = false;
            (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc0,0x10,"ec_asn1.c",0x52c);
          }
          else {
            bVar1 = true;
          }
          goto LAB_0050a444;
        }
        iVar11 = (*(code *)PTR_ASN1_STRING_type_new_006a97a4)(3);
        puVar7[3] = iVar11;
        if (iVar11 == 0) {
          uVar12 = 0x41;
          uVar4 = 0x506;
          pcVar16 = (code *)PTR_ERR_put_error_006a9030;
        }
        else {
          sVar13 = EC_POINT_point2oct((EC_GROUP *)puVar14[1],(EC_POINT *)puVar14[2],puVar14[5],
                                      (uchar *)0x0,0,(BN_CTX *)0x0);
          if ((len_00 < sVar13) &&
             (buf_00 = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                          (puVar9,sVar13,"ec_asn1.c",0x50f), len_00 = sVar13,
             buf_00 == (uchar *)0x0)) {
            uVar12 = 0x41;
            uVar4 = 0x512;
            pcVar16 = (code *)PTR_ERR_put_error_006a9030;
          }
          else {
            sVar13 = EC_POINT_point2oct((EC_GROUP *)puVar14[1],(EC_POINT *)puVar14[2],puVar14[5],
                                        buf_00,len_00,(BN_CTX *)0x0);
            puVar2 = PTR_ASN1_STRING_set_006a8e0c;
            puVar9 = buf_00;
            if (sVar13 == 0) {
              uVar12 = 0x10;
              uVar4 = 0x51c;
              pcVar16 = (code *)PTR_ERR_put_error_006a9030;
            }
            else {
              iVar11 = puVar7[3];
              *(uint *)(iVar11 + 0xc) = *(uint *)(iVar11 + 0xc) & 0xfffffff0 | 8;
              iVar11 = (*(code *)puVar2)(iVar11,buf_00,len_00);
              if (iVar11 != 0) goto LAB_0050a644;
              uVar12 = 0xd;
              uVar4 = 0x525;
              pcVar16 = (code *)PTR_ERR_put_error_006a9030;
            }
          }
        }
      }
    }
  }
  bVar1 = false;
  (*pcVar16)(0x10,0xc0,uVar12,"ec_asn1.c",uVar4);
  pEVar15 = (EC_KEY *)0x0;
  buf_00 = puVar9;
LAB_0050a444:
  (*(code *)PTR_CRYPTO_free_006a7f88)(buf_00);
  (*(code *)PTR_ASN1_item_free_006a977c)(puVar7,EC_PRIVATEKEY_it);
  if (!bVar1) {
    return (EC_KEY *)0x0;
  }
  return pEVar15;
}

