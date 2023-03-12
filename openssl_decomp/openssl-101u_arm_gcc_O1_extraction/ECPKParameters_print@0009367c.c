
int ECPKParameters_print(BIO *bp,EC_GROUP *x,int off)

{
  byte *pbVar1;
  BIGNUM *ctx;
  int iVar2;
  BIGNUM *cofactor;
  EC_METHOD *meth;
  char *pcVar3;
  point_conversion_form_t form;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  int extraout_r1;
  uint uVar7;
  uchar *puVar8;
  BIGNUM *a;
  BIGNUM *b;
  BIGNUM *order;
  int iVar9;
  BIGNUM *p;
  uint uVar10;
  BIGNUM *local_d8;
  BIGNUM *local_d4;
  char *local_cc;
  uchar *local_b8;
  undefined local_b0;
  undefined auStack_af [131];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (x == (EC_GROUP *)0x0) {
    iVar2 = 0x43;
    ctx = (BIGNUM *)x;
    a = (BIGNUM *)x;
    b = (BIGNUM *)x;
    order = (BIGNUM *)x;
    p = (BIGNUM *)x;
    local_d8 = (BIGNUM *)x;
    local_d4 = (BIGNUM *)x;
  }
  else {
    ctx = (BIGNUM *)BN_CTX_new();
    if (ctx == (BIGNUM *)0x0) {
      iVar2 = 0x41;
      x = (EC_GROUP *)ctx;
      a = ctx;
      b = ctx;
      order = ctx;
      p = ctx;
      local_d8 = ctx;
      local_d4 = ctx;
    }
    else {
      iVar2 = EC_GROUP_get_asn1_flag(x);
      if (iVar2 == 0) {
        meth = EC_GROUP_method_of(x);
        iVar2 = EC_METHOD_get_field_type(meth);
        p = BN_new();
        if (p == (BIGNUM *)0x0) {
          iVar2 = 0x41;
          x = (EC_GROUP *)p;
          a = p;
          b = p;
          order = p;
          local_d8 = p;
          local_d4 = p;
        }
        else {
          a = BN_new();
          if (a == (BIGNUM *)0x0) {
            iVar2 = 0x41;
            x = (EC_GROUP *)a;
            b = a;
            order = a;
            local_d8 = a;
            local_d4 = a;
          }
          else {
            b = BN_new();
            if (b == (BIGNUM *)0x0) {
              iVar2 = 0x41;
              x = (EC_GROUP *)b;
              order = b;
              local_d8 = b;
              local_d4 = b;
            }
            else {
              order = BN_new();
              if (order == (BIGNUM *)0x0) {
                iVar2 = 0x41;
                x = (EC_GROUP *)order;
                local_d8 = order;
                local_d4 = order;
              }
              else {
                cofactor = BN_new();
                if (cofactor == (BIGNUM *)0x0) {
                  iVar2 = 0x41;
                  x = (EC_GROUP *)cofactor;
                  local_d8 = cofactor;
                  local_d4 = cofactor;
                }
                else {
                  uVar7 = count_leading_zeroes(iVar2 + -0x197);
                  if (uVar7 >> 5 == 0) {
                    iVar9 = EC_GROUP_get_curve_GFp(x,p,a,b,(BN_CTX *)ctx);
                    if (iVar9 != 0) goto LAB_00093864;
                    iVar2 = 0x10;
                    local_d4 = (BIGNUM *)0x0;
                    local_d8 = (BIGNUM *)0x0;
                    x = (EC_GROUP *)cofactor;
                  }
                  else {
                    iVar9 = EC_GROUP_get_curve_GF2m();
                    if (iVar9 == 0) {
                      local_d4 = (BIGNUM *)0x0;
                      iVar2 = 0x10;
                      local_d8 = (BIGNUM *)0x0;
                      x = (EC_GROUP *)cofactor;
                    }
                    else {
LAB_00093864:
                      local_d8 = (BIGNUM *)EC_GROUP_get0_generator(x);
                      if (local_d8 == (BIGNUM *)0x0) {
                        iVar2 = 0x10;
                        x = (EC_GROUP *)cofactor;
                        local_d4 = local_d8;
                      }
                      else {
                        local_d4 = (BIGNUM *)EC_GROUP_get_order(x,order,(BN_CTX *)0x0);
                        if ((local_d4 == (BIGNUM *)0x0) ||
                           (local_d4 = (BIGNUM *)EC_GROUP_get_cofactor(x,cofactor,(BN_CTX *)0x0),
                           local_d4 == (BIGNUM *)0x0)) {
                          iVar2 = 0x10;
                          x = (EC_GROUP *)cofactor;
                          local_d8 = local_d4;
                        }
                        else {
                          form = EC_GROUP_get_point_conversion_form(x);
                          local_d4 = EC_POINT_point2bn(x,(EC_POINT *)local_d8,form,(BIGNUM *)0x0,
                                                       (BN_CTX *)ctx);
                          if (local_d4 == (BIGNUM *)0x0) {
                            iVar2 = 0x10;
                            x = (EC_GROUP *)cofactor;
                            local_d8 = local_d4;
                          }
                          else {
                            iVar4 = BN_num_bits(p);
                            iVar9 = iVar4 + 0xe;
                            if (-1 < iVar4 + 7) {
                              iVar9 = iVar4 + 7;
                            }
                            iVar5 = BN_num_bits(a);
                            iVar4 = iVar5 + 0xe;
                            if (-1 < iVar5 + 7) {
                              iVar4 = iVar5 + 7;
                            }
                            iVar5 = BN_num_bits(b);
                            uVar10 = iVar4 >> 3;
                            if ((uint)(iVar4 >> 3) < (uint)(iVar9 >> 3)) {
                              uVar10 = iVar9 >> 3;
                            }
                            iVar9 = iVar5 + 0xe;
                            if (-1 < iVar5 + 7) {
                              iVar9 = iVar5 + 7;
                            }
                            if (uVar10 < (uint)(iVar9 >> 3)) {
                              uVar10 = iVar9 >> 3;
                            }
                            iVar4 = BN_num_bits(local_d4);
                            iVar9 = iVar4 + 7;
                            if (iVar4 + 7 < 0) {
                              iVar9 = iVar4 + 0xe;
                            }
                            if (uVar10 < (uint)(iVar9 >> 3)) {
                              uVar10 = iVar9 >> 3;
                            }
                            iVar4 = BN_num_bits(order);
                            iVar9 = iVar4 + 7;
                            if (iVar4 + 7 < 0) {
                              iVar9 = iVar4 + 0xe;
                            }
                            if (uVar10 < (uint)(iVar9 >> 3)) {
                              uVar10 = iVar9 >> 3;
                            }
                            iVar4 = BN_num_bits(cofactor);
                            iVar9 = iVar4 + 7;
                            if (iVar4 + 7 < 0) {
                              iVar9 = iVar4 + 0xe;
                            }
                            if (uVar10 < (uint)(iVar9 >> 3)) {
                              uVar10 = iVar9 >> 3;
                            }
                            puVar6 = EC_GROUP_get0_seed(x);
                            local_b8 = puVar6;
                            if (puVar6 != (uchar *)0x0) {
                              local_b8 = (uchar *)EC_GROUP_get_seed_len(x);
                            }
                            local_d8 = (BIGNUM *)CRYPTO_malloc(uVar10 + 10,"eck_prn.c",0xf9);
                            if (local_d8 == (BIGNUM *)0x0) {
                              iVar2 = 0x41;
                              x = (EC_GROUP *)cofactor;
                            }
                            else {
                              iVar9 = BIO_indent(bp,off,0x80);
                              if (iVar9 != 0) {
                                pcVar3 = OBJ_nid2sn(iVar2);
                                iVar2 = BIO_printf(bp,"Field Type: %s\n",pcVar3);
                                if (0 < iVar2) {
                                  if (uVar7 >> 5 == 0) {
                                    pcVar3 = "Prime:";
LAB_00093a0a:
                                    iVar2 = ASN1_bn_print(bp,pcVar3,p,(uchar *)local_d8,off);
                                    if (((iVar2 != 0) &&
                                        (iVar2 = ASN1_bn_print(bp,"A:   ",a,(uchar *)local_d8,off),
                                        iVar2 != 0)) &&
                                       (iVar2 = ASN1_bn_print(bp,"B:   ",b,(uchar *)local_d8,off),
                                       iVar2 != 0)) {
                                      if (form == POINT_CONVERSION_COMPRESSED) {
                                        pcVar3 = "Generator (compressed):";
                                      }
                                      else if (form == POINT_CONVERSION_UNCOMPRESSED) {
                                        pcVar3 = "Generator (uncompressed):";
                                      }
                                      else {
                                        pcVar3 = "Generator (hybrid):";
                                      }
                                      iVar2 = ASN1_bn_print(bp,pcVar3,local_d4,(uchar *)local_d8,off
                                                           );
                                      if (((iVar2 != 0) &&
                                          (iVar2 = ASN1_bn_print(bp,"Order: ",order,
                                                                 (uchar *)local_d8,off), iVar2 != 0)
                                          ) && (iVar2 = ASN1_bn_print(bp,"Cofactor: ",cofactor,
                                                                      (uchar *)local_d8,off),
                                               iVar2 != 0)) {
                                        if (puVar6 == (uchar *)0x0) goto LAB_00093832;
                                        if (off < 1) {
                                          off = 0;
                                        }
                                        else {
                                          if (0x7f < off) {
                                            off = 0x80;
                                          }
                                          __memset_chk(&local_b0,0x20,off,0x80);
                                          iVar2 = BIO_write(bp,&local_b0,off);
                                          if (iVar2 < 1) goto LAB_000939c2;
                                        }
                                        iVar2 = BIO_printf(bp,"%s","Seed:");
                                        if (0 < iVar2) {
                                          puVar8 = (uchar *)0x0;
                                          local_cc = "";
                                          do {
                                            if (puVar8 == local_b8) {
                                              iVar2 = BIO_write(bp,"\n",1);
                                              if (0 < iVar2) goto LAB_00093832;
                                              break;
                                            }
                                            __aeabi_uidivmod(puVar8,0xf);
                                            if (extraout_r1 == 0) {
                                              local_b0 = 10;
                                              __memset_chk(auStack_af,0x20,off + 4,0x7f);
                                              iVar2 = BIO_write(bp,&local_b0,off + 5);
                                              if (iVar2 < 1) break;
                                            }
                                            pbVar1 = puVar6 + (int)puVar8;
                                            puVar8 = puVar8 + 1;
                                            pcVar3 = local_cc;
                                            if (local_b8 != puVar8) {
                                              pcVar3 = ":";
                                            }
                                            iVar2 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,pcVar3);
                                          } while (0 < iVar2);
                                        }
                                      }
                                    }
                                  }
                                  else {
                                    iVar2 = EC_GROUP_get_basis_type(x);
                                    if ((iVar2 != 0) &&
                                       (iVar9 = BIO_indent(bp,off,0x80), iVar9 != 0)) {
                                      pcVar3 = OBJ_nid2sn(iVar2);
                                      iVar2 = BIO_printf(bp,"Basis Type: %s\n",pcVar3);
                                      if (0 < iVar2) {
                                        pcVar3 = "Polynomial:";
                                        goto LAB_00093a0a;
                                      }
                                    }
                                  }
                                }
                              }
LAB_000939c2:
                              iVar2 = 0x20;
                              x = (EC_GROUP *)cofactor;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        cofactor = (BIGNUM *)BIO_indent(bp,off,0x80);
        if ((cofactor != (BIGNUM *)0x0) &&
           (cofactor = (BIGNUM *)EC_GROUP_get_curve_name(x), cofactor != (BIGNUM *)0x0)) {
          pcVar3 = OBJ_nid2sn((int)cofactor);
          iVar2 = BIO_printf(bp,"ASN1 OID: %s",pcVar3);
          if (iVar2 < 1) {
            cofactor = (BIGNUM *)0x0;
          }
          else {
            cofactor = (BIGNUM *)0x0;
            iVar2 = BIO_printf(bp,"\n");
            if (0 < iVar2) {
              order = (BIGNUM *)0x0;
              b = (BIGNUM *)0x0;
              a = (BIGNUM *)0x0;
              p = (BIGNUM *)0x0;
              local_d4 = (BIGNUM *)0x0;
              local_d8 = (BIGNUM *)0x0;
LAB_00093832:
              iVar9 = 1;
              goto LAB_000936f6;
            }
          }
        }
        iVar2 = 0x20;
        x = (EC_GROUP *)cofactor;
        a = cofactor;
        b = cofactor;
        order = cofactor;
        p = cofactor;
        local_d8 = cofactor;
        local_d4 = cofactor;
      }
    }
  }
  iVar9 = 0;
  ERR_put_error(0x10,0x95,iVar2,"eck_prn.c",0x139);
  cofactor = (BIGNUM *)x;
LAB_000936f6:
  if (p != (BIGNUM *)0x0) {
    BN_free(p);
  }
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (b != (BIGNUM *)0x0) {
    BN_free(b);
  }
  if (local_d4 != (BIGNUM *)0x0) {
    BN_free(local_d4);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (cofactor != (BIGNUM *)0x0) {
    BN_free(cofactor);
  }
  if (ctx != (BIGNUM *)0x0) {
    BN_CTX_free((BN_CTX *)ctx);
  }
  if (local_d8 != (BIGNUM *)0x0) {
    CRYPTO_free(local_d8);
  }
  if (local_2c == __stack_chk_guard) {
    return iVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

