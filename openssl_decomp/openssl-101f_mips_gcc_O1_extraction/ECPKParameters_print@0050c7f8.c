
/* WARNING: Removing unreachable block (ram,0x0050d04c) */

int ECPKParameters_print(BIO *bp,EC_GROUP *x,int off)

{
  undefined *puVar1;
  BN_CTX *c;
  int iVar2;
  EC_METHOD *meth;
  EC_POINT *pEVar3;
  point_conversion_form_t form;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  byte *pbVar7;
  char *pcVar8;
  undefined4 uVar9;
  BIO *a;
  int iVar10;
  uint uVar11;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s4;
  BIGNUM *unaff_s5;
  BIGNUM *unaff_s7;
  code *pcVar12;
  int local_res8;
  BIGNUM *local_d4;
  size_t local_c8;
  undefined local_ac;
  undefined auStack_ab [127];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (x == (EC_GROUP *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d4 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    unaff_s3 = (BIGNUM *)0x0;
    a = (BIO *)0x0;
    c = (BN_CTX *)0x0;
    uVar9 = 0x43;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  c = BN_CTX_new();
  if (c == (BN_CTX *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d4 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    unaff_s3 = (BIGNUM *)0x0;
    a = (BIO *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  iVar2 = EC_GROUP_get_asn1_flag(x);
  if (iVar2 != 0) {
    iVar2 = BIO_indent(bp,off,0x80);
    if ((iVar2 != 0) && (iVar2 = EC_GROUP_get_curve_name(x), iVar2 != 0)) {
      uVar9 = (*(code *)PTR_OBJ_nid2sn_006a819c)(iVar2);
      iVar2 = BIO_printf(bp,"ASN1 OID: %s",uVar9);
      if ((0 < iVar2) && (iVar2 = BIO_printf(bp,"\n"), 0 < iVar2)) {
        iVar2 = 0;
        iVar10 = 1;
        goto LAB_0050c980;
      }
    }
    unaff_s7 = (BIGNUM *)0x0;
    local_d4 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    unaff_s3 = (BIGNUM *)0x0;
    a = (BIO *)0x0;
    uVar9 = 0x20;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  meth = EC_GROUP_method_of(x);
  iVar10 = EC_METHOD_get_field_type(meth);
  a = (BIO *)BN_new();
  if (a == (BIO *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d4 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    unaff_s3 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  unaff_s3 = BN_new();
  if (unaff_s3 == (BIGNUM *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d4 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  unaff_s4 = BN_new();
  if (unaff_s4 == (BIGNUM *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d4 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  unaff_s5 = BN_new();
  if (unaff_s5 == (BIGNUM *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d4 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  unaff_s7 = BN_new();
  if (unaff_s7 == (BIGNUM *)0x0) {
    local_d4 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  pcVar12 = (code *)PTR_EC_GROUP_get_curve_GFp_006a82dc;
  if (iVar10 == 0x197) {
    pcVar12 = (code *)PTR_EC_GROUP_get_curve_GF2m_006a9780;
  }
  iVar2 = (*pcVar12)(x,a,unaff_s3,unaff_s4,c);
  if ((((iVar2 == 0) || (pEVar3 = EC_GROUP_get0_generator(x), pEVar3 == (EC_POINT *)0x0)) ||
      (iVar2 = EC_GROUP_get_order(x,unaff_s5,(BN_CTX *)0x0), iVar2 == 0)) ||
     (iVar2 = EC_GROUP_get_cofactor(x,unaff_s7,(BN_CTX *)0x0), iVar2 == 0)) {
    local_d4 = (BIGNUM *)0x0;
    uVar9 = 0x10;
    iVar2 = 0;
    goto LAB_0050c8e0;
  }
  form = EC_GROUP_get_point_conversion_form(x);
  local_d4 = EC_POINT_point2bn(x,pEVar3,form,(BIGNUM *)0x0,c);
  if (local_d4 == (BIGNUM *)0x0) goto LAB_0050d0e8;
  iVar4 = BN_num_bits((BIGNUM *)a);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  iVar5 = BN_num_bits(unaff_s3);
  iVar4 = iVar5 + 7;
  if (iVar5 + 7 < 0) {
    iVar4 = iVar5 + 0xe;
  }
  uVar11 = iVar2 >> 3;
  if ((uint)(iVar2 >> 3) < (uint)(iVar4 >> 3)) {
    uVar11 = iVar4 >> 3;
  }
  iVar4 = BN_num_bits(unaff_s4);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  if (uVar11 <= (uint)(iVar2 >> 3)) {
    uVar11 = iVar2 >> 3;
  }
  iVar4 = BN_num_bits(local_d4);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  if (uVar11 <= (uint)(iVar2 >> 3)) {
    uVar11 = iVar2 >> 3;
  }
  iVar4 = BN_num_bits(unaff_s5);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  if (uVar11 <= (uint)(iVar2 >> 3)) {
    uVar11 = iVar2 >> 3;
  }
  iVar4 = BN_num_bits(unaff_s7);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  if (uVar11 <= (uint)(iVar2 >> 3)) {
    uVar11 = iVar2 >> 3;
  }
  puVar6 = EC_GROUP_get0_seed(x);
  if (puVar6 == (uchar *)0x0) {
    local_c8 = 0;
  }
  else {
    local_c8 = EC_GROUP_get_seed_len(x);
  }
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar11 + 10,"eck_prn.c",0x10a);
  if (iVar2 == 0) {
    uVar9 = 0x41;
    goto LAB_0050c8e0;
  }
  iVar4 = BIO_indent(bp,off,0x80);
  if (iVar4 != 0) {
    uVar9 = (*(code *)PTR_OBJ_nid2sn_006a819c)(iVar10);
    iVar4 = BIO_printf(bp,"Field Type: %s\n",uVar9);
    if (0 < iVar4) {
      if (iVar10 == 0x197) {
        iVar10 = EC_GROUP_get_basis_type(x);
        if ((iVar10 != 0) && (iVar4 = BIO_indent(bp,off,0x80), iVar4 != 0)) {
          uVar9 = (*(code *)PTR_OBJ_nid2sn_006a819c)(iVar10);
          iVar10 = BIO_printf(bp,"Basis Type: %s\n",uVar9);
          if (0 < iVar10) {
            iVar10 = (*(code *)PTR_ASN1_bn_print_006a97dc)(bp,"Polynomial:",a,iVar2,off);
            if (iVar10 == 0) {
              uVar9 = 0x20;
              goto LAB_0050c8e0;
            }
            goto LAB_0050ce70;
          }
        }
      }
      else {
        iVar10 = (*(code *)PTR_ASN1_bn_print_006a97dc)(bp,"Prime:",a,iVar2,off);
        if (iVar10 != 0) {
LAB_0050ce70:
          iVar10 = (*(code *)PTR_ASN1_bn_print_006a97dc)(bp,"A:   ",unaff_s3,iVar2,off);
          if (iVar10 != 0) {
            iVar10 = (*(code *)PTR_ASN1_bn_print_006a97dc)(bp,"B:   ",unaff_s4,iVar2,off);
            if (iVar10 != 0) {
              if (form == POINT_CONVERSION_COMPRESSED) {
                pcVar8 = "Generator (compressed):";
              }
              else if (form == POINT_CONVERSION_UNCOMPRESSED) {
                pcVar8 = "Generator (uncompressed):";
              }
              else {
                pcVar8 = "Generator (hybrid):";
              }
              iVar10 = (*(code *)PTR_ASN1_bn_print_006a97dc)(bp,pcVar8,local_d4,iVar2,off);
              if ((iVar10 != 0) &&
                 (iVar10 = (*(code *)PTR_ASN1_bn_print_006a97dc)(bp,"Order: ",unaff_s5,iVar2,off),
                 iVar10 != 0)) {
                iVar10 = (*(code *)PTR_ASN1_bn_print_006a97dc)(bp,"Cofactor: ",unaff_s7,iVar2,off);
                if (iVar10 != 0) {
                  if (puVar6 == (uchar *)0x0) {
LAB_0050d0d4:
                    iVar10 = 1;
                    goto LAB_0050c908;
                  }
                  local_res8 = off;
                  if (off != 0) {
                    if (0x80 < off) {
                      off = 0x80;
                    }
                    (*(code *)PTR___memset_chk_006aaa98)(&local_ac,0x20,off,0x80);
                    iVar10 = BIO_write(bp,&local_ac,off);
                    local_res8 = off;
                    if (iVar10 < 1) goto LAB_0050cdf4;
                  }
                  iVar10 = BIO_printf(bp,"%s","Seed:");
                  if (0 < iVar10) {
                    uVar11 = 0;
                    do {
                      if (local_c8 == uVar11) {
                        iVar10 = BIO_write(bp,"\n",1);
                        if (0 < iVar10) goto LAB_0050d0d4;
                        break;
                      }
                      if (uVar11 % 0xf == 0) {
                        local_ac = 10;
                        (*(code *)PTR___memset_chk_006aaa98)(auStack_ab,0x20,local_res8 + 4,0x7f);
                        iVar10 = BIO_write(bp,&local_ac,local_res8 + 5);
                        if (iVar10 < 1) {
                          uVar9 = 0x20;
                          goto LAB_0050c8e0;
                        }
                      }
                      pbVar7 = puVar6 + uVar11;
                      uVar11 = uVar11 + 1;
                      if (local_c8 == uVar11) {
                        pcVar8 = "";
                      }
                      else {
                        pcVar8 = ":";
                      }
                      iVar10 = BIO_printf(bp,"%02x%s",(uint)*pbVar7,pcVar8);
                    } while (0 < iVar10);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0050cdf4:
  uVar9 = 0x20;
LAB_0050c8e0:
  while( true ) {
    iVar10 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x95,uVar9,"eck_prn.c",0x150);
    bp = a;
    if (a != (BIO *)0x0) {
LAB_0050c908:
      BN_free((BIGNUM *)a);
      bp = a;
    }
    if (unaff_s3 != (BIGNUM *)0x0) {
      BN_free(unaff_s3);
    }
    if (unaff_s4 != (BIGNUM *)0x0) {
      BN_free(unaff_s4);
    }
    if (local_d4 != (BIGNUM *)0x0) {
      BN_free(local_d4);
    }
    if (unaff_s5 != (BIGNUM *)0x0) {
      BN_free(unaff_s5);
    }
    if (unaff_s7 != (BIGNUM *)0x0) {
      BN_free(unaff_s7);
    }
LAB_0050c980:
    if (c != (BN_CTX *)0x0) {
      BN_CTX_free(c);
    }
    if (iVar2 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    }
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    a = bp;
LAB_0050d0e8:
    uVar9 = 0x10;
    iVar2 = 0;
  }
  return iVar10;
}

