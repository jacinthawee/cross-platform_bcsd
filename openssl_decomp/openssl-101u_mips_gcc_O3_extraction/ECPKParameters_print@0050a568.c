
/* WARNING: Removing unreachable block (ram,0x0050adc8) */

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
  uint uVar10;
  BIO *a;
  int iVar11;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s4;
  BIGNUM *unaff_s5;
  BIGNUM *unaff_s7;
  code *pcVar12;
  BIGNUM *local_d8;
  size_t local_cc;
  undefined local_ac;
  undefined auStack_ab [127];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (x == (EC_GROUP *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d8 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    unaff_s3 = (BIGNUM *)0x0;
    a = (BIO *)0x0;
    c = (BN_CTX *)0x0;
    uVar9 = 0x43;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  c = BN_CTX_new();
  if (c == (BN_CTX *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d8 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    unaff_s3 = (BIGNUM *)0x0;
    a = (BIO *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  iVar2 = EC_GROUP_get_asn1_flag(x);
  if (iVar2 != 0) {
    iVar2 = BIO_indent(bp,off,0x80);
    if ((iVar2 != 0) && (iVar2 = EC_GROUP_get_curve_name(x), iVar2 != 0)) {
      uVar9 = (*(code *)PTR_OBJ_nid2sn_006a709c)(iVar2);
      iVar2 = BIO_printf(bp,"ASN1 OID: %s",uVar9);
      if ((0 < iVar2) && (iVar2 = BIO_printf(bp,"\n"), 0 < iVar2)) {
        iVar2 = 0;
        iVar11 = 1;
        goto LAB_0050a6f0;
      }
    }
    unaff_s7 = (BIGNUM *)0x0;
    local_d8 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    unaff_s3 = (BIGNUM *)0x0;
    a = (BIO *)0x0;
    uVar9 = 0x20;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  meth = EC_GROUP_method_of(x);
  iVar11 = EC_METHOD_get_field_type(meth);
  a = (BIO *)BN_new();
  if (a == (BIO *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d8 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    unaff_s3 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  unaff_s3 = BN_new();
  if (unaff_s3 == (BIGNUM *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d8 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    unaff_s4 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  unaff_s4 = BN_new();
  if (unaff_s4 == (BIGNUM *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d8 = (BIGNUM *)0x0;
    unaff_s5 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  unaff_s5 = BN_new();
  if (unaff_s5 == (BIGNUM *)0x0) {
    unaff_s7 = (BIGNUM *)0x0;
    local_d8 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  unaff_s7 = BN_new();
  if (unaff_s7 == (BIGNUM *)0x0) {
    local_d8 = (BIGNUM *)0x0;
    uVar9 = 0x41;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  pcVar12 = (code *)PTR_EC_GROUP_get_curve_GFp_006a71dc;
  if (iVar11 == 0x197) {
    pcVar12 = (code *)PTR_EC_GROUP_get_curve_GF2m_006a865c;
  }
  iVar2 = (*pcVar12)(x,a,unaff_s3,unaff_s4,c);
  if ((((iVar2 == 0) || (pEVar3 = EC_GROUP_get0_generator(x), pEVar3 == (EC_POINT *)0x0)) ||
      (iVar2 = EC_GROUP_get_order(x,unaff_s5,(BN_CTX *)0x0), iVar2 == 0)) ||
     (iVar2 = EC_GROUP_get_cofactor(x,unaff_s7,(BN_CTX *)0x0), iVar2 == 0)) {
    local_d8 = (BIGNUM *)0x0;
    uVar9 = 0x10;
    iVar2 = 0;
    goto LAB_0050a650;
  }
  form = EC_GROUP_get_point_conversion_form(x);
  local_d8 = EC_POINT_point2bn(x,pEVar3,form,(BIGNUM *)0x0,c);
  if (local_d8 == (BIGNUM *)0x0) goto LAB_0050ae38;
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
  uVar10 = iVar2 >> 3;
  if ((uint)(iVar2 >> 3) < (uint)(iVar4 >> 3)) {
    uVar10 = iVar4 >> 3;
  }
  iVar4 = BN_num_bits(unaff_s4);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  if (uVar10 <= (uint)(iVar2 >> 3)) {
    uVar10 = iVar2 >> 3;
  }
  iVar4 = BN_num_bits(local_d8);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  if (uVar10 <= (uint)(iVar2 >> 3)) {
    uVar10 = iVar2 >> 3;
  }
  iVar4 = BN_num_bits(unaff_s5);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  if (uVar10 <= (uint)(iVar2 >> 3)) {
    uVar10 = iVar2 >> 3;
  }
  iVar4 = BN_num_bits(unaff_s7);
  iVar2 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar2 = iVar4 + 0xe;
  }
  if (uVar10 <= (uint)(iVar2 >> 3)) {
    uVar10 = iVar2 >> 3;
  }
  puVar6 = EC_GROUP_get0_seed(x);
  if (puVar6 == (uchar *)0x0) {
    local_cc = 0;
  }
  else {
    local_cc = EC_GROUP_get_seed_len(x);
  }
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar10 + 10,"eck_prn.c",0xf9);
  if (iVar2 == 0) {
    uVar9 = 0x41;
    goto LAB_0050a650;
  }
  iVar4 = BIO_indent(bp,off,0x80);
  if (iVar4 != 0) {
    uVar9 = (*(code *)PTR_OBJ_nid2sn_006a709c)(iVar11);
    iVar4 = BIO_printf(bp,"Field Type: %s\n",uVar9);
    if (0 < iVar4) {
      if (iVar11 == 0x197) {
        iVar11 = EC_GROUP_get_basis_type(x);
        if ((iVar11 != 0) && (iVar4 = BIO_indent(bp,off,0x80), iVar4 != 0)) {
          uVar9 = (*(code *)PTR_OBJ_nid2sn_006a709c)(iVar11);
          iVar11 = BIO_printf(bp,"Basis Type: %s\n",uVar9);
          if (0 < iVar11) {
            iVar11 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"Polynomial:",a,iVar2,off);
            if (iVar11 == 0) {
              uVar9 = 0x20;
              goto LAB_0050a650;
            }
            goto LAB_0050abe0;
          }
        }
      }
      else {
        iVar11 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"Prime:",a,iVar2,off);
        if (iVar11 != 0) {
LAB_0050abe0:
          iVar11 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"A:   ",unaff_s3,iVar2,off);
          if (iVar11 != 0) {
            iVar11 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"B:   ",unaff_s4,iVar2,off);
            if (iVar11 != 0) {
              if (form == POINT_CONVERSION_COMPRESSED) {
                pcVar8 = "Generator (compressed):";
              }
              else if (form == POINT_CONVERSION_UNCOMPRESSED) {
                pcVar8 = "Generator (uncompressed):";
              }
              else {
                pcVar8 = "Generator (hybrid):";
              }
              iVar11 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,pcVar8,local_d8,iVar2,off);
              if ((iVar11 != 0) &&
                 (iVar11 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"Order: ",unaff_s5,iVar2,off),
                 iVar11 != 0)) {
                iVar11 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"Cofactor: ",unaff_s7,iVar2,off);
                if (iVar11 != 0) {
                  if (puVar6 == (uchar *)0x0) {
LAB_0050aee0:
                    iVar11 = 1;
                    goto LAB_0050a678;
                  }
                  if (off < 1) {
                    off = 0;
                  }
                  else {
                    if (0x80 < off) {
                      off = 0x80;
                    }
                    (*(code *)PTR___memset_chk_006a998c)(&local_ac,0x20,off,0x80);
                    iVar11 = BIO_write(bp,&local_ac,off);
                    if (iVar11 < 1) goto LAB_0050ab64;
                  }
                  iVar11 = BIO_printf(bp,"%s","Seed:");
                  if (0 < iVar11) {
                    uVar10 = 0;
                    do {
                      if (local_cc == uVar10) {
                        iVar11 = BIO_write(bp,"\n",1);
                        if (iVar11 < 1) goto LAB_0050ab64;
                        goto LAB_0050aee0;
                      }
                      if (uVar10 % 0xf == 0) {
                        local_ac = 10;
                        (*(code *)PTR___memset_chk_006a998c)(auStack_ab,0x20,off + 4,0x7f);
                        iVar11 = BIO_write(bp,&local_ac,off + 5);
                        if (iVar11 < 1) {
                          uVar9 = 0x20;
                          goto LAB_0050a650;
                        }
                      }
                      pbVar7 = puVar6 + uVar10;
                      uVar10 = uVar10 + 1;
                      if (local_cc == uVar10) {
                        pcVar8 = "";
                      }
                      else {
                        pcVar8 = ":";
                      }
                      iVar11 = BIO_printf(bp,"%02x%s",(uint)*pbVar7,pcVar8);
                    } while (0 < iVar11);
                    uVar9 = 0x20;
                    goto LAB_0050a650;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0050ab64:
  uVar9 = 0x20;
LAB_0050a650:
  while( true ) {
    iVar11 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x95,uVar9,"eck_prn.c",0x139);
    bp = a;
    if (a != (BIO *)0x0) {
LAB_0050a678:
      BN_free((BIGNUM *)a);
      bp = a;
    }
    if (unaff_s3 != (BIGNUM *)0x0) {
      BN_free(unaff_s3);
    }
    if (unaff_s4 != (BIGNUM *)0x0) {
      BN_free(unaff_s4);
    }
    if (local_d8 != (BIGNUM *)0x0) {
      BN_free(local_d8);
    }
    if (unaff_s5 != (BIGNUM *)0x0) {
      BN_free(unaff_s5);
    }
    if (unaff_s7 != (BIGNUM *)0x0) {
      BN_free(unaff_s7);
    }
LAB_0050a6f0:
    if (c != (BN_CTX *)0x0) {
      BN_CTX_free(c);
    }
    if (iVar2 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
    }
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    a = bp;
LAB_0050ae38:
    uVar9 = 0x10;
    iVar2 = 0;
  }
  return iVar11;
}

