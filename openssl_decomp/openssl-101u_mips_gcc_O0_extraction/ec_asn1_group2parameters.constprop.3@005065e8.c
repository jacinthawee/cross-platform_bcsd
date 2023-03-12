
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
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  a = BN_new();
  if (a == (BIGNUM *)0x0) {
    puVar4 = (undefined4 *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0x41,"ec_asn1.c",0x22a);
    goto LAB_005067dc;
  }
  unaff_s5 = 0x690000;
  puVar4 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(ECPARAMETERS_it);
  if (puVar4 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0x41,"ec_asn1.c",0x230);
    BN_free(a);
    unaff_s3 = a;
    goto LAB_005067dc;
  }
  piVar17 = (int *)puVar4[1];
  *puVar4 = 1;
  if ((param_1 == (EC_GROUP *)0x0) || (piVar17 == (int *)0x0)) goto LAB_00506778;
  if (*piVar17 != 0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)();
  }
  if (piVar17[1] != 0) {
    (*(code *)PTR_ASN1_TYPE_free_006a7498)();
  }
  pEVar5 = EC_GROUP_method_of(param_1);
  iVar6 = EC_METHOD_get_field_type(pEVar5);
  iVar7 = (*(code *)PTR_OBJ_nid2obj_006a7140)(iVar6);
  *piVar17 = iVar7;
  if (iVar7 == 0) {
    uVar13 = 8;
    uVar9 = 0x148;
    goto LAB_00506764;
  }
  if (iVar6 != 0x196) {
    piVar8 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(X9_62_CHARACTERISTIC_TWO_it);
    piVar17[1] = (int)piVar8;
    if (piVar8 == (int *)0x0) {
      uVar13 = 0x41;
      uVar9 = 0x16b;
    }
    else {
      iVar6 = EC_GROUP_get_degree(param_1);
      *piVar8 = iVar6;
      pEVar5 = EC_GROUP_method_of(param_1);
      iVar6 = EC_METHOD_get_field_type(pEVar5);
      if (((iVar6 == 0x197) && (*(int *)(param_1 + 0x5c) != 0)) && (*(int *)(param_1 + 0x60) != 0))
      {
        if (*(int *)(param_1 + 100) == 0) {
          iVar6 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x2aa);
          piVar8[1] = iVar6;
          if (iVar6 == 0) {
LAB_00506d3c:
            uVar13 = 8;
            uVar9 = 0x179;
          }
          else {
            pEVar5 = EC_GROUP_method_of(param_1);
            iVar6 = EC_METHOD_get_field_type(pEVar5);
            if (((iVar6 != 0x197) || (*(int *)(param_1 + 0x5c) == 0)) ||
               ((iVar6 = *(int *)(param_1 + 0x60), iVar6 == 0 || (*(int *)(param_1 + 100) != 0)))) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc2,0x42,"ec_asn1.c",0x61);
              goto LAB_00506778;
            }
            iVar7 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
            piVar8[2] = iVar7;
            if (iVar7 == 0) {
              uVar13 = 0x41;
              uVar9 = 0x185;
            }
            else {
              iVar6 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar7,iVar6);
              if (iVar6 != 0) goto LAB_00506898;
              uVar13 = 0xd;
              uVar9 = 0x189;
            }
          }
          goto LAB_00506764;
        }
        if ((*(int *)(param_1 + 0x68) == 0) || (*(int *)(param_1 + 0x6c) != 0)) goto LAB_00506750;
        iVar6 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x2ab);
        piVar8[1] = iVar6;
        if (iVar6 == 0) goto LAB_00506d3c;
        pEVar5 = EC_GROUP_method_of(param_1);
        iVar6 = EC_METHOD_get_field_type(pEVar5);
        if (((((iVar6 != 0x197) || (*(int *)(param_1 + 0x5c) == 0)) ||
             (unaff_s7 = *(BIGNUM **)(param_1 + 0x60), unaff_s7 == (BIGNUM *)0x0)) ||
            ((iVar6 = *(int *)(param_1 + 100), iVar6 == 0 ||
             (iVar7 = *(int *)(param_1 + 0x68), iVar7 == 0)))) || (*(int *)(param_1 + 0x6c) != 0)) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc1,0x42,"ec_asn1.c",0x77);
          goto LAB_00506778;
        }
        piVar17 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(X9_62_PENTANOMIAL_it);
        piVar8[2] = (int)piVar17;
        if (piVar17 == (int *)0x0) {
          uVar13 = 0x41;
          uVar9 = 0x194;
          goto LAB_00506764;
        }
        *piVar17 = iVar7;
        piVar17[1] = iVar6;
        piVar17[2] = (int)unaff_s7;
        goto LAB_00506898;
      }
LAB_00506750:
      uVar13 = 0x10;
      uVar9 = 0x174;
    }
LAB_00506764:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9a,uVar13,"ec_asn1.c",uVar9);
LAB_00506778:
    unaff_s4 = 0x660000;
    pcVar14 = "ec_asn1.c";
    uVar13 = 0x10;
    uVar9 = 0x23b;
    goto LAB_0050678c;
  }
  p = BN_new();
  if (p == (BIGNUM *)0x0) {
    uVar13 = 0x41;
    uVar9 = 0x14e;
    goto LAB_00506764;
  }
  iVar6 = EC_GROUP_get_curve_GFp(param_1,p,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
  if (iVar6 == 0) {
    uVar13 = 0x10;
    uVar9 = 0x153;
LAB_0050686c:
    unaff_s7 = (BIGNUM *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9a,uVar13,"ec_asn1.c",uVar9);
  }
  else {
    iVar6 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(p,0);
    piVar17[1] = iVar6;
    if (iVar6 == 0) {
      uVar13 = 0xd;
      uVar9 = 0x159;
      goto LAB_0050686c;
    }
    unaff_s7 = (BIGNUM *)0x1;
  }
  BN_free(p);
  if (unaff_s7 == (BIGNUM *)0x0) goto LAB_00506778;
LAB_00506898:
  unaff_s4 = 0x660000;
  piVar17 = (int *)puVar4[2];
  local_2d = '\0';
  if (piVar17 == (int *)0x0) goto LAB_00506b40;
  if (*piVar17 == 0) goto LAB_00506b40;
  if (piVar17[1] == 0) goto LAB_00506b40;
  unaff_s7 = BN_new();
  if ((unaff_s7 == (BIGNUM *)0x0) || (unaff_s6 = BN_new(), unaff_s6 == (BIGNUM *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x99,0x41,"ec_asn1.c",0x1bc);
    if (unaff_s7 == (BIGNUM *)0x0) goto LAB_00506b40;
    bVar1 = false;
    unaff_s6 = (BIGNUM *)0x0;
    goto LAB_00506a78;
  }
  pEVar5 = EC_GROUP_method_of(param_1);
  iVar6 = EC_METHOD_get_field_type(pEVar5);
  if (iVar6 == 0x196) {
    iVar6 = EC_GROUP_get_curve_GFp(param_1,(BIGNUM *)0x0,unaff_s7,unaff_s6,(BN_CTX *)0x0);
    if (iVar6 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x99,0x10,"ec_asn1.c",0x1c5);
      goto LAB_00506ec8;
    }
  }
  else {
    iVar6 = EC_GROUP_get_curve_GF2m(param_1,0,unaff_s7,unaff_s6,0);
    if (iVar6 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x99,0x10,"ec_asn1.c",0x1cd);
      bVar1 = false;
      goto LAB_00506a78;
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
    puVar11 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar6 >> 3,"ec_asn1.c",0x1da);
    if (puVar11 == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x99,0x41,"ec_asn1.c",0x1db);
      bVar1 = false;
      goto LAB_00506a78;
    }
    puVar15 = (uchar *)BN_bn2bin(unaff_s7,puVar11);
    local_3c = puVar11;
    if (puVar15 == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x99,3,"ec_asn1.c",0x1df);
      bVar1 = false;
      local_44 = (uchar *)0x0;
      goto LAB_00506a48;
    }
  }
  if (local_44 == (uchar *)0x0) {
    local_38 = &local_2d;
    local_44 = (uchar *)0x0;
    iVar6 = 1;
  }
  else {
    local_44 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(local_44,"ec_asn1.c",0x1ea);
    if (local_44 == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x99,0x41,"ec_asn1.c",0x1eb);
      local_44 = puVar15;
      if (local_3c != (uchar *)0x0) {
        local_44 = (uchar *)0x0;
        bVar1 = false;
        goto LAB_00506a48;
      }
LAB_00506ec8:
      bVar1 = false;
      goto LAB_00506a78;
    }
    iVar6 = BN_bn2bin(unaff_s6,local_44);
    local_38 = local_44;
    if (iVar6 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x99,3,"ec_asn1.c",0x1ef);
      if (local_3c == (uchar *)0x0) {
        bVar1 = false;
        goto LAB_00506a64;
      }
      bVar1 = false;
      goto LAB_00506a48;
    }
  }
  iVar7 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(*piVar17,puVar11,puVar15);
  if ((iVar7 == 0) ||
     (iVar6 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(piVar17[1],local_38,iVar6), iVar6 == 0)) {
    pcVar14 = "ec_asn1.c";
    uVar13 = 0xd;
    uVar9 = 0x1f8;
    goto LAB_00506d68;
  }
  iVar6 = *(int *)(param_1 + 0x3c);
  if (iVar6 == 0) {
    if (piVar17[2] != 0) {
      (*(code *)PTR_ASN1_BIT_STRING_free_006a8670)();
      piVar17[2] = 0;
      bVar1 = true;
      goto LAB_00506a3c;
    }
  }
  else {
    iVar7 = piVar17[2];
    if (iVar7 == 0) {
      iVar7 = (*(code *)PTR_ASN1_BIT_STRING_new_006a8660)();
      piVar17[2] = iVar7;
      if (iVar7 == 0) goto LAB_00507360;
      iVar6 = *(int *)(param_1 + 0x3c);
    }
    puVar2 = PTR_ASN1_BIT_STRING_set_006a8664;
    uVar9 = *(undefined4 *)(param_1 + 0x40);
    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffffff0 | 8;
    iVar6 = (*(code *)puVar2)(iVar7,iVar6,uVar9);
    if (iVar6 == 0) {
      pcVar14 = "ec_asn1.c";
      uVar13 = 0xd;
      uVar9 = 0x207;
      goto LAB_00506d68;
    }
  }
  bVar1 = true;
LAB_00506a3c:
  do {
    if (local_3c != (uchar *)0x0) {
LAB_00506a48:
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_3c);
    }
    if (local_44 != (uchar *)0x0) {
LAB_00506a64:
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_44);
    }
LAB_00506a78:
    BN_free(unaff_s7);
    if (unaff_s6 != (BIGNUM *)0x0) {
      BN_free(unaff_s6);
    }
    if (bVar1) {
      unaff_s7 = (BIGNUM *)EC_GROUP_get0_generator(param_1);
      if (unaff_s7 == (BIGNUM *)0x0) {
        pcVar14 = (char *)(unaff_s4 + 0x6a5c);
        uVar13 = 0x71;
        uVar9 = 0x247;
        goto LAB_0050678c;
      }
      form = EC_GROUP_get_point_conversion_form(param_1);
      puVar11 = (uchar *)EC_POINT_point2oct(param_1,(EC_POINT *)unaff_s7,form,(uchar *)0x0,0,
                                            (BN_CTX *)0x0);
      if (puVar11 == (uchar *)0x0) {
        pcVar14 = (char *)(unaff_s4 + 0x6a5c);
        uVar13 = 0x10;
        uVar9 = 0x24f;
        goto LAB_0050678c;
      }
      unaff_s6 = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(puVar11,unaff_s4 + 0x6a5c,0x252);
      puVar16 = puVar4;
      local_44 = puVar11;
      if (unaff_s6 == (BIGNUM *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0x41,unaff_s4 + 0x6a5c,0x253);
        goto LAB_005067a0;
      }
      sVar12 = EC_POINT_point2oct(param_1,(EC_POINT *)unaff_s7,form,(uchar *)unaff_s6,
                                  (size_t)puVar11,(BN_CTX *)0x0);
      if (sVar12 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0x10,unaff_s4 + 0x6a5c,599);
        goto LAB_005067a0;
      }
      iVar6 = puVar4[3];
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a8668)();
        puVar4[3] = iVar6;
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0x41,unaff_s4 + 0x6a5c,0x25b);
          goto LAB_005067a0;
        }
      }
      iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)(iVar6,unaff_s6,puVar11);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0xd,unaff_s4 + 0x6a5c,0x25f);
        goto LAB_005067a0;
      }
      iVar6 = EC_GROUP_get_order(param_1,a,(BN_CTX *)0x0);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0x10,unaff_s4 + 0x6a5c,0x265);
        goto LAB_005067a0;
      }
      iVar6 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(a,puVar4[4]);
      puVar4[4] = iVar6;
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0xd,unaff_s4 + 0x6a5c,0x26a);
        goto LAB_005067a0;
      }
      iVar6 = EC_GROUP_get_cofactor(param_1,a,(BN_CTX *)0x0);
      if (iVar6 != 0) {
        iVar6 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(a,puVar4[5]);
        puVar4[5] = iVar6;
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,0xd,unaff_s4 + 0x6a5c,0x272);
          goto LAB_005067a0;
        }
      }
      BN_free(a);
LAB_005067cc:
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s6);
      unaff_s3 = a;
    }
    else {
LAB_00506b40:
      pcVar14 = (char *)(unaff_s4 + 0x6a5c);
      uVar13 = 0x10;
      uVar9 = 0x241;
LAB_0050678c:
      unaff_s6 = (BIGNUM *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9b,uVar13,pcVar14,uVar9);
      puVar16 = puVar4;
LAB_005067a0:
      puVar4 = (undefined4 *)0x0;
      (*(code *)PTR_ASN1_item_free_006a8658)(puVar16,unaff_s5 + 0x3634);
      BN_free(a);
      unaff_s3 = a;
      if (unaff_s6 != (BIGNUM *)0x0) goto LAB_005067cc;
    }
LAB_005067dc:
    if (local_2c == *(int *)puVar3) {
      return puVar4;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    a = unaff_s3;
LAB_00507360:
    pcVar14 = (char *)(unaff_s4 + 0x6a5c);
    uVar13 = 0x41;
    uVar9 = 0x200;
LAB_00506d68:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x99,uVar13,pcVar14,uVar9);
    bVar1 = false;
  } while( true );
}

