
undefined4 * ec_asn1_group2parameters_constprop_3(EC_GROUP *param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  BIGNUM *a;
  undefined4 *puVar4;
  EC_METHOD *pEVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  BIGNUM *p;
  int iVar10;
  point_conversion_form_t form;
  uchar *puVar11;
  size_t sVar12;
  undefined4 uVar13;
  char *pcVar14;
  uchar *puVar15;
  undefined4 *puVar16;
  BIGNUM *unaff_s3;
  int unaff_s4;
  int *piVar17;
  int unaff_s5;
  BIGNUM *unaff_s6;
  BIGNUM *unaff_s7;
  uchar *local_44;
  uchar *local_3c;
  uchar *local_38;
  uchar local_2d;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  a = BN_new();
  if (a == (BIGNUM *)0x0) {
    puVar4 = (undefined4 *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0x41,"ec_asn1.c",0x249);
    goto LAB_00508b2c;
  }
  unaff_s5 = 0x690000;
  puVar4 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(ECPARAMETERS_it);
  if (puVar4 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0x41,"ec_asn1.c",0x252);
    BN_free(a);
    unaff_s3 = a;
    goto LAB_00508b2c;
  }
  piVar17 = (int *)puVar4[1];
  *puVar4 = 1;
  if ((param_1 == (EC_GROUP *)0x0) || (piVar17 == (int *)0x0)) goto LAB_00508ac8;
  if (*piVar17 != 0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)();
  }
  if (piVar17[1] != 0) {
    (*(code *)PTR_ASN1_TYPE_free_006a8598)();
  }
  pEVar5 = EC_GROUP_method_of(param_1);
  iVar6 = EC_METHOD_get_field_type(pEVar5);
  iVar7 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar6);
  *piVar17 = iVar7;
  if (iVar7 == 0) {
    uVar13 = 8;
    uVar9 = 0x13e;
    goto LAB_00508ab4;
  }
  if (iVar6 != 0x196) {
    piVar8 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(X9_62_CHARACTERISTIC_TWO_it);
    piVar17[1] = (int)piVar8;
    if (piVar8 == (int *)0x0) {
      uVar13 = 0x41;
      uVar9 = 0x167;
    }
    else {
      iVar6 = EC_GROUP_get_degree(param_1);
      *piVar8 = iVar6;
      pEVar5 = EC_GROUP_method_of(param_1);
      iVar6 = EC_METHOD_get_field_type(pEVar5);
      if (((iVar6 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) && (*(int *)(param_1 + 0x60) != 0))
      {
        if (*(int *)(param_1 + 100) == 0) {
          iVar6 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x2aa);
          piVar8[1] = iVar6;
          if (iVar6 == 0) {
LAB_0050908c:
            uVar13 = 8;
            uVar9 = 0x177;
          }
          else {
            pEVar5 = EC_GROUP_method_of(param_1);
            iVar6 = EC_METHOD_get_field_type(pEVar5);
            if (((iVar6 != 0x197) || (*(int *)(param_1 + 0x5c) == 0)) ||
               ((iVar6 = *(int *)(param_1 + 0x60), iVar6 == 0 || (*(int *)(param_1 + 100) != 0)))) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc2,0x42,"ec_asn1.c",0x60);
              goto LAB_00508ac8;
            }
            iVar7 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
            piVar8[2] = iVar7;
            if (iVar7 == 0) {
              uVar13 = 0x41;
              uVar9 = 0x185;
            }
            else {
              iVar6 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar7,iVar6);
              if (iVar6 != 0) goto LAB_00508be8;
              uVar13 = 0xd;
              uVar9 = 0x18b;
            }
          }
          goto LAB_00508ab4;
        }
        if ((*(int *)(param_1 + 0x68) == 0) || (*(int *)(param_1 + 0x6c) != 0)) goto LAB_00508aa0;
        iVar6 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x2ab);
        piVar8[1] = iVar6;
        if (iVar6 == 0) goto LAB_0050908c;
        pEVar5 = EC_GROUP_method_of(param_1);
        iVar6 = EC_METHOD_get_field_type(pEVar5);
        if (((((iVar6 != 0x197) || (*(int *)(param_1 + 0x5c) == 0)) ||
             (unaff_s7 = *(BIGNUM **)(param_1 + 0x60), unaff_s7 == (BIGNUM *)0x0)) ||
            ((iVar6 = *(int *)(param_1 + 100), iVar6 == 0 ||
             (iVar7 = *(int *)(param_1 + 0x68), iVar7 == 0)))) || (*(int *)(param_1 + 0x6c) != 0)) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc1,0x42,"ec_asn1.c",0x73);
          goto LAB_00508ac8;
        }
        piVar17 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(X9_62_PENTANOMIAL_it);
        piVar8[2] = (int)piVar17;
        if (piVar17 == (int *)0x0) {
          uVar13 = 0x41;
          uVar9 = 0x199;
          goto LAB_00508ab4;
        }
        *piVar17 = iVar7;
        piVar17[1] = iVar6;
        piVar17[2] = (int)unaff_s7;
        goto LAB_00508be8;
      }
LAB_00508aa0:
      uVar13 = 0x10;
      uVar9 = 0x171;
    }
LAB_00508ab4:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9a,uVar13,"ec_asn1.c",uVar9);
LAB_00508ac8:
    unaff_s4 = 0x660000;
    pcVar14 = "ec_asn1.c";
    uVar13 = 0x10;
    uVar9 = 0x25f;
    goto LAB_00508adc;
  }
  p = BN_new();
  if (p == (BIGNUM *)0x0) {
    uVar13 = 0x41;
    uVar9 = 0x146;
    goto LAB_00508ab4;
  }
  iVar6 = EC_GROUP_get_curve_GFp(param_1,p,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
  if (iVar6 == 0) {
    uVar13 = 0x10;
    uVar9 = 0x14c;
LAB_00508bbc:
    unaff_s7 = (BIGNUM *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9a,uVar13,"ec_asn1.c",uVar9);
  }
  else {
    iVar6 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(p,0);
    piVar17[1] = iVar6;
    if (iVar6 == 0) {
      uVar13 = 0xd;
      uVar9 = 0x153;
      goto LAB_00508bbc;
    }
    unaff_s7 = (BIGNUM *)0x1;
  }
  BN_free(p);
  if (unaff_s7 == (BIGNUM *)0x0) goto LAB_00508ac8;
LAB_00508be8:
  unaff_s4 = 0x660000;
  piVar17 = (int *)puVar4[2];
  local_2d = '\0';
  if (piVar17 == (int *)0x0) goto LAB_00508e90;
  if (*piVar17 == 0) goto LAB_00508e90;
  if (piVar17[1] == 0) goto LAB_00508e90;
  unaff_s7 = BN_new();
  if ((unaff_s7 == (BIGNUM *)0x0) || (unaff_s6 = BN_new(), unaff_s6 == (BIGNUM *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x99,0x41,"ec_asn1.c",0x1c4);
    if (unaff_s7 == (BIGNUM *)0x0) goto LAB_00508e90;
    bVar1 = false;
    unaff_s6 = (BIGNUM *)0x0;
    goto LAB_00508dc8;
  }
  pEVar5 = EC_GROUP_method_of(param_1);
  iVar6 = EC_METHOD_get_field_type(pEVar5);
  if (iVar6 == 0x196) {
    iVar6 = EC_GROUP_get_curve_GFp(param_1,(BIGNUM *)0x0,unaff_s7,unaff_s6,(BN_CTX *)0x0);
    if (iVar6 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x99,0x10,"ec_asn1.c",0x1cf);
      goto LAB_00509218;
    }
  }
  else {
    iVar6 = EC_GROUP_get_curve_GF2m(param_1,0,unaff_s7,unaff_s6,0);
    if (iVar6 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x99,0x10,"ec_asn1.c",0x1d8);
      bVar1 = false;
      goto LAB_00508dc8;
    }
  }
  iVar7 = BN_num_bits(unaff_s7);
  iVar6 = iVar7 + 7;
  if (iVar7 + 7 < 0) {
    iVar6 = iVar7 + 0xe;
  }
  iVar10 = BN_num_bits(unaff_s6);
  iVar7 = iVar10 + 7;
  if (iVar10 + 7 < 0) {
    iVar7 = iVar10 + 0xe;
  }
  local_44 = (uchar *)(iVar7 >> 3);
  if (iVar6 >> 3 == 0) {
    puVar11 = &local_2d;
    local_3c = (uchar *)0x0;
    puVar15 = (uchar *)0x1;
  }
  else {
    puVar11 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar6 >> 3,"ec_asn1.c",0x1e8);
    if (puVar11 == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x99,0x41,"ec_asn1.c",0x1eb);
      bVar1 = false;
      goto LAB_00508dc8;
    }
    puVar15 = (uchar *)BN_bn2bin(unaff_s7,puVar11);
    local_3c = puVar11;
    if (puVar15 == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x99,3,"ec_asn1.c",0x1f0);
      bVar1 = false;
      local_44 = (uchar *)0x0;
      goto LAB_00508d98;
    }
  }
  if (local_44 == (uchar *)0x0) {
    local_38 = &local_2d;
    local_44 = (uchar *)0x0;
    iVar6 = 1;
  }
  else {
    local_44 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(local_44,"ec_asn1.c",0x1fe);
    if (local_44 == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x99,0x41,"ec_asn1.c",0x201);
      local_44 = puVar15;
      if (local_3c != (uchar *)0x0) {
        local_44 = (uchar *)0x0;
        bVar1 = false;
        goto LAB_00508d98;
      }
LAB_00509218:
      bVar1 = false;
      goto LAB_00508dc8;
    }
    iVar6 = BN_bn2bin(unaff_s6,local_44);
    local_38 = local_44;
    if (iVar6 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x99,3,"ec_asn1.c",0x206);
      if (local_3c == (uchar *)0x0) {
        bVar1 = false;
        goto LAB_00508db4;
      }
      bVar1 = false;
      goto LAB_00508d98;
    }
  }
  iVar7 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(*piVar17,puVar11,puVar15);
  if ((iVar7 == 0) ||
     (iVar6 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(piVar17[1],local_38,iVar6), iVar6 == 0)) {
    pcVar14 = "ec_asn1.c";
    uVar13 = 0xd;
    uVar9 = 0x210;
    goto LAB_005090b8;
  }
  iVar6 = *(int *)(param_1 + 0x3c);
  if (iVar6 == 0) {
    if (piVar17[2] != 0) {
      (*(code *)PTR_ASN1_BIT_STRING_free_006a9794)();
      piVar17[2] = 0;
      bVar1 = true;
      goto LAB_00508d8c;
    }
  }
  else {
    iVar7 = piVar17[2];
    if (iVar7 == 0) {
      iVar7 = (*(code *)PTR_ASN1_BIT_STRING_new_006a9784)();
      piVar17[2] = iVar7;
      if (iVar7 == 0) goto LAB_005096b0;
      iVar6 = *(int *)(param_1 + 0x3c);
    }
    puVar2 = PTR_ASN1_BIT_STRING_set_006a9788;
    uVar9 = *(undefined4 *)(param_1 + 0x40);
    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffffff0 | 8;
    iVar6 = (*(code *)puVar2)(iVar7,iVar6,uVar9);
    if (iVar6 == 0) {
      pcVar14 = "ec_asn1.c";
      uVar13 = 0xd;
      uVar9 = 0x222;
      goto LAB_005090b8;
    }
  }
  bVar1 = true;
LAB_00508d8c:
  do {
    if (local_3c != (uchar *)0x0) {
LAB_00508d98:
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_3c);
    }
    if (local_44 != (uchar *)0x0) {
LAB_00508db4:
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_44);
    }
LAB_00508dc8:
    BN_free(unaff_s7);
    if (unaff_s6 != (BIGNUM *)0x0) {
      BN_free(unaff_s6);
    }
    if (bVar1) {
      unaff_s7 = (BIGNUM *)EC_GROUP_get0_generator(param_1);
      if (unaff_s7 == (BIGNUM *)0x0) {
        pcVar14 = (char *)(unaff_s4 + 0x73ac);
        uVar13 = 0x71;
        uVar9 = 0x26d;
        goto LAB_00508adc;
      }
      form = EC_GROUP_get_point_conversion_form(param_1);
      puVar11 = (uchar *)EC_POINT_point2oct(param_1,(EC_POINT *)unaff_s7,form,(uchar *)0x0,0,
                                            (BN_CTX *)0x0);
      if (puVar11 == (uchar *)0x0) {
        pcVar14 = (char *)(unaff_s4 + 0x73ac);
        uVar13 = 0x10;
        uVar9 = 0x276;
        goto LAB_00508adc;
      }
      unaff_s6 = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a8108)(puVar11,unaff_s4 + 0x73ac,0x279);
      puVar16 = puVar4;
      local_44 = puVar11;
      if (unaff_s6 == (BIGNUM *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0x41,unaff_s4 + 0x73ac,0x27b);
        goto LAB_00508af0;
      }
      sVar12 = EC_POINT_point2oct(param_1,(EC_POINT *)unaff_s7,form,(uchar *)unaff_s6,
                                  (size_t)puVar11,(BN_CTX *)0x0);
      if (sVar12 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0x10,unaff_s4 + 0x73ac,0x280);
        goto LAB_00508af0;
      }
      iVar6 = puVar4[3];
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
        puVar4[3] = iVar6;
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0x41,unaff_s4 + 0x73ac,0x285);
          goto LAB_00508af0;
        }
      }
      iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(iVar6,unaff_s6,puVar11);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0xd,unaff_s4 + 0x73ac,0x28a);
        goto LAB_00508af0;
      }
      iVar6 = EC_GROUP_get_order(param_1,a,(BN_CTX *)0x0);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0x10,unaff_s4 + 0x73ac,0x291);
        goto LAB_00508af0;
      }
      iVar6 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(a,puVar4[4]);
      puVar4[4] = iVar6;
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0xd,unaff_s4 + 0x73ac,0x297);
        goto LAB_00508af0;
      }
      iVar6 = EC_GROUP_get_cofactor(param_1,a,(BN_CTX *)0x0);
      if (iVar6 != 0) {
        iVar6 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(a,puVar4[5]);
        puVar4[5] = iVar6;
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,0xd,unaff_s4 + 0x73ac,0x2a1);
          goto LAB_00508af0;
        }
      }
      BN_free(a);
LAB_00508b1c:
      (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s6);
      unaff_s3 = a;
    }
    else {
LAB_00508e90:
      pcVar14 = (char *)(unaff_s4 + 0x73ac);
      uVar13 = 0x10;
      uVar9 = 0x266;
LAB_00508adc:
      unaff_s6 = (BIGNUM *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9b,uVar13,pcVar14,uVar9);
      puVar16 = puVar4;
LAB_00508af0:
      puVar4 = (undefined4 *)0x0;
      (*(code *)PTR_ASN1_item_free_006a977c)(puVar16,unaff_s5 + 0x4790);
      BN_free(a);
      unaff_s3 = a;
      if (unaff_s6 != (BIGNUM *)0x0) goto LAB_00508b1c;
    }
LAB_00508b2c:
    if (local_2c == *(int *)puVar3) {
      return puVar4;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    a = unaff_s3;
LAB_005096b0:
    pcVar14 = (char *)(unaff_s4 + 0x73ac);
    uVar13 = 0x41;
    uVar9 = 0x21a;
LAB_005090b8:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x99,uVar13,pcVar14,uVar9);
    bVar1 = false;
  } while( true );
}

